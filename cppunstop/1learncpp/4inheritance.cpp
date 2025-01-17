/*
The benefit of inheritance is :
- Reuse
- lesser time
- reliability
- easier to maintain
- complexity decreament
- reduced cost
*/ 

/*
visibility      inside the class        inChild class       outside(main)
public                T                      T                   T       
protected             T                      T                   F       
Private               T                      F                   F       
*/
#include<iostream>
using namespace std;

class parent{ // parentClass - superClass - BaseClass
    public:
    int var1;

    private:
    int var2;

    protected:
    int var3;
// // all these three things are accessible inside the class.

    public:
    void setVar2(int val){
    var2 = val; // Accessing the private member var2 of parent class
    }
    int getVar2(){
        return var2;
    }

};
class child: public parent{
    public:
    void setVar3(int val){ // // this can also happen in parent class and this shows that var3 is protected and it is accissible in both parent and child.
    var3 = val; // Accessing the protected member var3 of parent class
    }
    // // int valee = var1+var3; // 
    /*
    In your code, when you place int valee = var1 + var3; outside the function calc(),
    you are creating the variable valee at a point in the program where var1 and var3 may not have been initialized yet.
    This happens because the default constructor of child doesn't initialize the values of var1 and var3.
    So, when you add them outside the function, you get uninitialized memory values, leading to garbage results.
    */
void calc(){
    int valee = var1+var3;
    cout << "var1 + var3 + var2 is : "<<var1+var3+getVar2()<<endl; // // var3 hereshows that protected is accissible in child.
    cout <<"valee is :"<< valee<<endl;
}
};
int main(){
    child c;
    c.var1 = 310;  // Accessing public member var1
    c.setVar2(34); // Setting private member var2 via parent’s setter method
    c.setVar3(56); // Setting protected member var3 via child’s setter method
    c.calc();      // Calculating and printing the sum
}