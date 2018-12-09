
#define TOWORD(_) # _
#define PRINT(_) ;printf(_)
#define PRINTS(_) PRINT(TOWORD(_))
#define COORD(_) "<coord which=\"" TOWORD(_) "\">"
#define COORD_ "</coord>"
#define COORD2(_,__) COORD(_) "%s" COORD_ "\n",__

    #include <stdio.h>
    #include <stdlib.h>

int main(int argc, char **argv){

    PRINTS(<data>\n)
    PRINT(COORD2(X, argv[1]))
    PRINT(COORD2(Y, argv[2]))
    PRINTS(<direction>) PRINT(argv[3]) PRINTS(</direction>)
    PRINTS(</data>)

    // xmlfile << "<data>" << endl;
    // xmlfile << "\t<coord which=\"X\">";
    // xmlfile << argv[1];
    // xmlfile << "</coord>" << endl;
    // xmlfile << "\t<coord which=\"Y\">";
    // xmlfile << argv[2];
    // xmlfile << "</coord>" << endl;
    // xmlfile << "\t<direction>";
    // xmlfile << argv[3]
    ;
    // xmlfile << "</direction>" << endl;
    // xmlfile << "</data>" << endl;
    // xmlfile.close();
    return 1;
}