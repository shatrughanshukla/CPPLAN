#include<iostream>
using namespace std;
class shopItem
{
    int id;
    float price;
    public:
    void setdata(int a , float b)
    {
        id = a;
        price = b;
    }

    void getdata()
    {
        cout << "The id of the item is : " << id << endl;
        cout << "The price of the item is : " << price << endl;
    }
};

int main()
{
    int size;
    cout << "Enter the size of the array of objects" << endl;
    cin >> size;
    shopItem* ptr = new shopItem[size];
    shopItem* ptrTemp = ptr;

    int i;
    int p;
    float q;
    for (i = 0; i < size; i++)
    {
        cout << "Enter id and price of the item" <<endl;
        cin >> p >> q;
        ptr-> setdata(p , q);
        ptr++;
    }

    for (i = 0; i < size; i++)
    {
        ptrTemp-> getdata();
        ptrTemp++;
    }

    /*
    Key Points of How It Works
ptrTemp as a Bookmark:

By creating ptrTemp as a copy of ptr before incrementing ptr in the first loop, you’ve effectively created a “bookmark” that always points to the start of the array.
This allows you to use ptrTemp in the second loop without needing to reset ptr.

    */

    return 0;

}