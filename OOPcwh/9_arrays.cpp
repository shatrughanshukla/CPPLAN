#include<iostream>
using namespace std;

int main(){
    // // Array Example
    // cout << "These are marks"<<endl;
    int Marks[] = {23,34,21,45,23,34};  // we add [x] the no of elements we need, [] if x is not present inside this it's okay as compiler will figure out how many elements there are. 
    // cout<<Marks[0]<<endl;
    // cout<<Marks[1]<<endl;
    // Marks[2] = 45; // you can change the value of an array.
    // cout<<Marks[2]<<endl;
    // cout<<Marks[3]<<endl;
    // cout<<Marks[4]<<endl;
    cout << "These are math marks"<<endl;
    int mathmarks[4];
    mathmarks[0] = 98;
    mathmarks[1] = 87;
    mathmarks[2] = 79;
    mathmarks[3] = 89;

    cout<<mathmarks[0]<<endl;
    cout<<mathmarks[1]<<endl;
    cout<<mathmarks[2]<<endl;
    cout<<mathmarks[3]<<endl;

    // for (int i = 0; i < 4; i++)
    // {
    //     cout << "The value of marks "<<i<<" is "<<Marks[i]<<endl;
    // }
    int i = 0;
    // do
    // {
    //     cout << "The value of marks "<<i<<" is "<<Marks[i]<<endl;
    //     i = i +1;
    // } while (i<=4);
    while (i<=4){
         cout << "The value of marks "<<i<<" is "<<Marks[i]<<endl;
         i++;
    }

// // Pointers and arrays..
int* p = Marks;
cout<<*(p++)<<endl;
cout<<*(p)<<endl;
cout<<*(++p)<<endl;
// cout<< "The value of Marks [0] is" <<*(p)<<endl;
// cout<< "The value of Marks [1] is" <<*(p+1)<<endl;
// cout<< "The value of Marks [2] is" <<*(p+2)<<endl;
// cout<< "The value of Marks [3] is" <<*(p+3)<<endl;
    
    return 0;
}