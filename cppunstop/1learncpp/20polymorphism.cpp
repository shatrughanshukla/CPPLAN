#include<iostream>
#include<string.h>
using namespace std;

class prep
{
    public:
    char mystring[20];

    prep operator +(prep str2)
    {
        prep tempobj;
        strcat(mystring, str2.mystring);
        strcpy(tempobj.mystring, mystring);

        return tempobj;
    }

    void display()
    {
        cout<<"The concatenated string is : "<<mystring <<endl;
    }
};

int main()
{
    prep str1, str2, result;
    char temp1[20] = "prep";
    char temp2[20] = "Insta";

    strcpy(str1.mystring, temp1);
    strcpy(str2.mystring, temp2);

    result = str1 + str2;

    result.display();
    return 0;
}