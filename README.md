# ENTROPA

**A stand-alone program in C++ for Block-Entropy Analysis and Symbolic Dynamcis
**See the references in the end of theis file for more information and citation etiquette.
**The program has been tested for the GNU g++ compiler: gcc (Ubuntu 5.4.0-6ubuntu1~16.04.10) 5.4.0 20160609
**Some output is produced for ease of use and for diagnostics withinthe code.

**Compile it by:
g++ entropa.C -o entropa

**Run it by typing 
./entropa

**It will respond by a reminder about what log it uses and a prompt to input the symbol-sequence file to be analyzed:

log is natural ie log(e)= 0.9999999895 
Source File : 

**Give the sourse file (for example download and use '1000.txt', without quotes!) 
 Source File : 1000.txt

**The progam responds with 
Destination File : 
**(Say '1000.dat' as the one provided along with the program)

Destination File : 1000.dat
**Hit Return
**The program responds with an option 
**1=lump means no overlaping reading window for the symbol-blocks/words 
**2=slide means overlaping by one symbol/letter, sliding, window for the symbol-blocks/words
**Beware! the statistics are different if the sequence has forbutten blocks (i.e. syntactical or gramatical constrains)
READ TYPE ( 1=lump or 2=slide ) :
**(Say we type "2" as more conventional type, no quotes!)
READ TYPE ( 1=lump or 2=slide ) : 2

**The program responds with 
START:
**Type the initial word lenght to count
**Beware must be > 2 !!! to be a block...
START: 2 
** The program responds
END   : 
**Type the length up to which you wantto count:
END   : 6
** Please wait because the calculation is exponentialy long depending on the entropy/complexity of the text.
** So, the program responds:
PLEASE WAIT .........................
** Have a cup of coffeee for END > 12 :-) or wait in mindfulness for a while ;-)
** When it finishes it responds with:

PLEASE WAIT .........................
END OF PROGRAMME
THE WORK FILE IS " 1000.dat "
THE RESULT FILES ARE " hresult.txt  AND  hresult.dat "
ANY KEY FOR EXIT ...................

**Check the files and compare with the ones I have uploade for testing.
**You can uncomment lines 420 and 421 if you do not want the intermediate steps recorded.

429 /**************uncomment if you do not want the intermediate steps recorded******/
420 // remove("filtfile");
421 // remove("workfile.cpp");
422 /*******************************************************************/

**Check out the freshly produced files "hresult.dat" and "hresult.txt"
**They are the block (discrete Shannon entropies, one for plotting the other for inspection)
**Have Fun and Play Fair. Give a reference to these in case you use it, especially in a publication or student project!!!

Basios, V., Forti, L. G. & Nicolis, G., [2008]. 
Symbolic dynamics generated by a combination of graphs, 
Int. J. Bifurcation and Chaos 18, 2265-2274.

Basios, V. & Mac Kernan, D., [2008]. 
Symbolic dynamics, coarse graining and the monitoring of complex systems, 
Int. J. of Bifurcation and Chaos, 21, 3465-3475.
  
Basios, V., de Garnier, R. & Oikonomou, T., [2018]. 
Symbolic Dynamics of Music from Europe and Japan, 
arXiv 2018 to be published.

**END OF READ.md FILE
**EOF



