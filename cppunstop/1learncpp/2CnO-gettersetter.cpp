#include<iostream>
using namespace std;
class recatangle{ // // we're doing encapsulation here as well all the related functions we're capsuling under the same class rectangle.

    private:
    int length, breadth; // // we made length and breadth private so that now it can't be manipulated directly from outside, suppose it to be the password of your id so we have to abstract it so that no one from outside can manipulate it.
    // //public:
    // //int length, breadth;

    // // we'll make our functions public.

    public:
    // // Getters and setters act as a controlled interface for accessing private variables, allowing you to validate or modify data before it’s stored or retrieved.
    // // these are public methods that allow you to access the private variables. 

    // setters
    void setLength(int len){ // // 256 bit encrytption or encryption has happened then we're sending length value.
        // decryption
        length = len; // // here we're naming our length as len.
        /*

        Argument: When you call the function, the value inside the parentheses (e.g., setlength(10);) is called an argument. In this case, the argument is 10, and it is passed into the function.

        Parameter: The variable len in void setlength(int len) is a parameter that receives the value of the argument. When you call setlength(10);, the number 10 gets assigned to len.

        Here’s the sequence:
        You call the function setlength(10);.
        The value 10 is passed as an argument to the setlength function.
        The parameter len inside the function takes on the value of 10.
        Inside the function, length = len; assigns 10 to the class’s private member length.

        */
    }

    void setBreadth(int bre){
        breadth = bre; // // here we're naming our breadth as bre.
    }

    // // getters
    int getLength(){  // // if we create some functions like if else etc under functions , here we're also encapsuling same type of statements together inside a function.
        return length;
    }

    int getBreadth(){
        return breadth;
    }

    int area(){  // // this function is the part of class rectangle i.e. we're not creating it like int area(int length, int breadth);
        return length*breadth;
    }

};

int main(){
recatangle rect0;
rect0.setLength(10);
//rect0.length = 10; // // here we're setting length n breadth directly under main fn which we shuldn't use beacuase if it was username and password than do we want hacker to set values here? no rigth that's why we use setters and getters.
// // the diff between above two is (10) here we're dealing it in encrypted form.
rect0.setBreadth(20);
//rect0.breadth = 20; // length and breadth can't be accessed directly.

// // here we're doing abstrsction also as we've have created an interface in which directly u can't access length and breadth variables.
//but we've created getters and setters but they're performing data encryption so u're no directly able to change the values.

// cout << "The lenght of the rectangle is : "<<rect0.length<< endl;
// cout << "The breadth of the rectangle is : "<<rect0.breadth<< endl;

// //cout << "The area of rectangle rect0 is " << rect0.length*rect0.breadth << endl;
// // we're using these variable inside main functions which is very wrong.
cout << "The lenght of the rectangle is : "<<rect0.getLength()<< endl;
cout << "The breadth of the rectangle is : "<<rect0.getBreadth()<< endl;
cout << "The area of rectangle rect0 is " << rect0.area() << endl;
    return 0;
}