// // operator overloading
// // strings
#include<iostream>
#include<string.h>
using namespace std;

class strings
{
    private:
    char str1[20], str2[20];
    public:

    // // void Addstring(char *string1, char *string2) // // without constructor
    strings (char *string1, char *string2)
    {
        strcpy(str1, string1);
        strcpy(str2, string2);
    }
    void operator +()
    {
        cout << " After concatenation " << strcat(str1, str2)<<endl;
    }
};

int main()
{
char string1[] = "Prep";
char string2[] = "Insta";
strings obj1(string1, string2);
// strings obj1; // // with the help of Addstring function.
// obj1.Addstring(string1, string2);
+obj1;
    return 0;
}
