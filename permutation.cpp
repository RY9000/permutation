

#include "iostream"
#include "string.h"

using namespace std;


int pcount = 0;
static int indent = 0;
string space = "";
static string Indent(int i) 
{
    space = "";
    for (int a = 0; a < i; a++)
        space = space + "\t";
    return space; 
}



void permutation(string str, string prefix) 
{
    pcount++;
    cout << Indent(indent) << "permutation(\"" << str << "\", \"" << prefix << "\")"<<endl;
    if (str.length() == 0) {
        cout << Indent(indent + 1) << "--> " << prefix << endl;
    }
    else {
        for (int i = 0; i < str.length(); i++) {
            string rem = str.substr(0, i) + str.substr(i + 1);
            ++indent;
            permutation(rem, prefix + str.at(i));
            --indent;
        }
    }
}

void permutation(string str) {
    cout << "permutation(\"" << str << "\")" << endl;
    ++indent;
    permutation(str, "");
}


int main()
{
    permutation("abcd");
    cout << pcount << endl;
    
    return 0;
}
