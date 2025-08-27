#include <iostream>
#include <string>
using namespace std;

string encrypt(string text, int shift)
{
    string result = "";

    for (char c : text)
    {
        if (isalpha(c))
        {
            char base = isupper(c) ? 'A' : 'a';
            result += char((c - base + shift) % 26 + base);
        }
        else
        {
            result += c;
        }
    }
    return result;
}

string decrypt(string text, int shift)
{
    return encrypt(text, 26 - (shift % 26));
}

int main()
{
    string text;
    int shift;

    cout << "Enter message: ";
    getline(cin, text);

    cout << "Enter shift value: ";
    cin >> shift;

    string encrypted = encrypt(text, shift);
    cout << "\nEncrypted Message: " << encrypted << endl;

    string decrypted = decrypt(encrypted, shift);
    cout << "Decrypted Message: " << decrypted << endl;

    return 0;
}