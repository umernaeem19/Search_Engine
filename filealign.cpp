#include<iostream>
#include <fstream>
#include<string>
#include <string.h>
using namespace std;

int main()
{
    ofstream outer;
    ifstream inner;
    string line;
    inner.open("titles_ordered.txt");
    outer.open("serials.txt");
    string data;
    for(int x=1;x<=1000000;x++)
    {
        getline(inner,line);
        outer << line << endl;
    }
    inner.clear();
    inner.clear();
    outer.clear();
    outer.close();
    // int var = 20;
    // string filename;
    // filename = to_string(var);
    // filename+=".txt";
    // cout << filename << endl;
    return 0;
}
    