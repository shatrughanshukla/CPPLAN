#include<iostream>

using namespace std;
int glo = 6;
void sum(){
    int a;
    cout << glo; // this is printing independently because this don't know about the local var
    }

int main(){
    //int glo=9;  redeclaration of glo error is in action with this line.
    int glo=769;
    sum();
    cout << glo; //this is printing independently because local has precedence over global.
    return 0;
}