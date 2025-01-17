#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main()
{
    // // declarinng an object of the type instream
    ifstream in;
    string st1;
    // // opening the file into in.
    in.open("fileIOsample3.txt");
    // giving output the string lines by storing in st until the file reaches the end of it
    while (in.eof() == 0)
    {
        getline(in , st1);
        cout << st1 << endl;
    }
     return 0;

}