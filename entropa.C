/* IMPORTANT USE: g++ entropa.C -lm -o entropa */

/* the original modified for SUSE gcc 3.3.1, not using gets 2005 */
/**************************************/
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
#include <iostream> 
  using namespace std;

FILE *fin, *fin1,*fout, *fwork, *fh, *fhd;
float HL=0;
/*************************************/
void del_logic(char lin[],int l)
 {
  fseek(fwork ,-(l+1) ,1);
  fputs(lin,fwork);
  fseek (fwork,(l+1),1);
 }
/*************************************/

void lltoaa (long &n, char s[])
  {
   int c, i, j ,sign;
    if ((sign=n)<0) n=-n;
   i=0;
   do {
       s[i++]=n % 10 + '0'; 
      }
   while ((n /= 10) > 0);
   if (sign<0) s[i++]='-';
      s[i] = '\0';
    for (i=0, j=(strlen(s))-1; i<j ; i++, j--)
      {
	c=s[i];
	s[i]=s[j];
	s[j]= c;
      }
   }
/*************************************/

void str_print(char str[],long cpt,long pi,long totlin)
  {
   char s[11];
   float p,cpt1,totlin1;
   int c, i, j ,sign;
   cpt1=cpt;
   totlin1=totlin;
   fputs(str,fout);
   lltoaa(cpt,&s[0]);
   fseek(fout ,-1 ,1);
   fputs(" = ",fout);
   fputs(s,fout);
   fputc('\t',fout);
   fputc('P',fout);
   lltoaa(pi,&s[0]);
   fputs(s,fout);
   fputc('\t',fout);
   fputc('=',fout);
   p=cpt1/totlin1;
   fprintf(fout,"%7.3f",p);
   fputs("\th[",fout);
   fputs(s,fout);
   fputs("]\t=",fout);
   HL=HL+(p*log(p));
   fprintf(fout,"%f",-(p*(log(p))));
   fputc('\n',fout);
  }



/***********************************************************/

int main ()

 {
    const int NUMDISPLAY = 50; 
    char sfilename[NUMDISPLAY], dfilename[NUMDISPLAY], test;
    int c1;

    char str1[40],str2[40], lin[40] ;

    int m,i, k,tot,n,j,c,l,f,lecteur;

    long cal1,cal2,totlin,cpt,pi;
    
    double eeee;
/***********************************************************/
    eeee = log(2.7182818);

    printf ("log is natural ie log(e)= %7.10f \n", eeee);

    printf ("Source File : ");
    

    cin.getline(sfilename, NUMDISPLAY);



  if ((fin1 = fopen ( sfilename, "r")) == NULL )

	{

	   printf("\nError In Opening Of Origin's File %s \n", sfilename);

	   exit (2);

	}



/************************************************************/

    printf ("Destination File : ");

    cin.getline(dfilename,  NUMDISPLAY);



 if (( fout = fopen ( dfilename, "w+b" )) == NULL )

	{

      printf ("\nError In Opening Of Destination File %s\n",dfilename);

           fclose(fin1);

	   exit (2);

	}

/************************************************************/

      

    do

     {

      printf ("READ TYPE ( 1=lump or 2=slide ) : ");
     

      scanf ("%d", &lecteur);

     }

    while ((lecteur<1) || (lecteur>2));

/*******************************************/

    do

     {

      printf ("START : ");

      scanf ("%d", &l);

      printf ("END   : ");

      scanf ("%d", &f);

     }

    while ((l<2) || (l>32) || (f<2) || (f>32) || f<l);

/****************************************************************/

  if ((fin = fopen ( "filtfile", "w+b")) == NULL )

	{

	   printf("\nError In Opening Of File filtfile \n");

	   exit (2);

	}



while ((c1=fgetc(fin1))!= EOF)

  {

if ((c1>='0' && c1<='9') || (c1>='A' && c1<='Z') || (c1>='a' && c1<='z'))

   {

   fputc(c1,fin);

   }

  }



fclose(fin1);

/**************************************************************/

 if ((fh = fopen ( "hresult.txt", "w")) == NULL )

	{

	   printf("\nError In Opening Of Result File  HRESULT.TXT\n" );
	   exit (2);

	}



 if ((fhd = fopen ( "hresult.dat", "w")) == NULL )

	{

	   printf("\nError In Opening Of Result File  HRESULT.DAT\n" );
	   exit (2);

	}





fputs("\n========================================================\n",fh);

fputs("                THE RESULT OF THE PROGRAME                  ",fh);

fputs("\n========================================================\n",fh);

fputs("         L              !!             H(l)               ",fh);

fputs("\n========================================================\n",fh);









printf("PLEASE WAIT .........................");



/********************************************************************/



f++;

while (l<f)

{

 j=0; totlin=0;

 if (( fwork = fopen ( "workfile.cpp", "w+b" )) == NULL )

	{

           printf ("Error In Opening Of Work File ( WORKFILE.CCP )");

	   exit (2);

	}



 m=0; tot=0;

 fseek(fin,0L,SEEK_SET);

 while ((c1=fgetc(fin))!= EOF)

  {

	 str1[j]=c1;

	 j++;

         tot++;



    if (j==l)

       {

	  str1[j]='\n'; j++;

	  str1[j]='\0'; j=0;

	  fputs(str1,fwork);

          totlin++;

	  if (lecteur==2) {m++; fseek(fin,m,0);}

       }

  }

/*********************************************************/

 n=0;

 while (n!=l) {lin[n]='*'; n++;}

 lin[n]='\n'; n++;

 lin[n]='\0';

/**********************************************/

 i=1; pi=0;

 while (i!=(totlin+1))

 {

   cpt=1;

   fseek(fwork,0L,SEEK_SET);

   k=0;

   while (k!=i) {fgets(str1,40,fwork); k++; }

   test='z';

   while (test!=EOF)

    {

      if ((fgets(str2,40,fwork))==NULL){test=EOF;}

      if (strcmp(str1,str2)==0 && strcmp(str1,lin)!=0 && test!=EOF )

	{

	  cpt++;

	  del_logic(lin,l);

	  fseek(fwork,-(l+1),1);

	}

    }



   if (strcmp(str1,str2)!=0 || test==EOF || i==1)

     {

       if(strcmp(str1,lin)!=0 )

	{

          pi++;

	  str_print(str1,cpt,pi,totlin);

      	}

     }



  i++;

 }



    fputs("\n=====================================================\n",fout);

    fprintf(fout,"total =\t%ld\t",totlin);

    fprintf(fout,"\t  H[%d] = %7.10f\t",l,-HL);

    fputs("\n=====================================================\n\n",fout);



    fprintf(fhd,"%d\t\t%7.10f\n",l,-HL);



    fprintf(fh,"\tL = %d\t\t!!\tH[%d] = %7.10f\n",l,l,-HL);

    fputs("\n========================================================\n",fh);



 l++;

 HL=0;


}

/********************************************************************/

 fclose(fin);

 fclose(fwork);

 fclose(fh);

 fclose(fhd);

 fclose(fout);

 remove("filtfile");

 remove("workfile.cpp");

 printf("\nEND OF PROGRAMME\n");

 printf("THE WORK FILE IS \" %s \"",dfilename);

 printf("\nTHE RESULT FILES ARE \" hresult.txt  AND  hresult.dat \"");

 printf("\nANY KEY FOR EXIT ...................\n");

 return 0;

}

