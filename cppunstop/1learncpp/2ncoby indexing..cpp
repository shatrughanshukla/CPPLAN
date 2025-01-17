// // Out-of-Class Definition with Member Function Declarations
#include<iostream>
using namespace std;

class rectangle {
    
private:
    int length, breadth;

public:
void setLength(int len);
void setBreadth(int bre);
int area();

    int getLength() {
        return length;
    }

    int getBreadth() {
        return breadth;
    }

};

void rectangle :: setBreadth(int bre) {
        breadth = bre;
    }

void rectangle :: setLength(int len) {
        length = len;
    }

int rectangle :: area() {
        return length * breadth;
    }

int main() {
    rectangle rect0;
    rect0.setLength(10);
    rect0.setBreadth(20);

    cout << "The length of the rectangle is: " << rect0.getLength() << endl;
    cout << "The breadth of the rectangle is: " << rect0.getBreadth() << endl;
    cout << "The area of rectangle rect0 is: " << rect0.area() << endl;

    return 0;
}
