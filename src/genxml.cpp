#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char **argv){
    ofstream xmlfile;
    xmlfile.open("./data/data.xml");
    xmlfile << "<data>" << endl;
    xmlfile << "\t<coord which=\"X\">";
    xmlfile << argv[1];
    xmlfile << "</coord>" << endl;
    xmlfile << "\t<coord which=\"Y\">";
    xmlfile << argv[2];
    xmlfile << "</coord>" << endl;
    xmlfile << "\t<direction>";
    xmlfile << argv[3];
    xmlfile << "</direction>" << endl;
    xmlfile << "</data>" << endl;
    xmlfile.close();
    return 1;
}