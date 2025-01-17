#include<iostream>
#include<string>
using namespace std;
class binary
{
    void chk_bin(void);
    string s;
    public:
    // void chk_bin(void);
    void read(void);
    void ones_compliment(void);
    void display(void);

};

void binary :: read(void)
{
    cout << "Enter a binary no :" << endl;
    cin >> s;
}

void binary :: chk_bin(void)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i) != '0' && s.at(i) != '1')
        {
            cout << "Incorrect binary format" << endl;
        }   
    }   
}

void binary :: ones_compliment(void)
{
    chk_bin();
    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i) == '0')
        {
            s.at(i) = '1';
        }
        else{
        s.at(i) = '0';}
    }   
}

void binary :: display(void)
{
    cout << "Displaying your binary number : "<<endl;
    for (int i = 0; i < s.length(); i++)
    {
        cout << s.at(i);
    }
    cout << endl;
    
}

int main()
{
    binary b;
    b.read();
   // b.chk_bin();
    b.display();
    b.ones_compliment();
    b.display();

    return 0;
}