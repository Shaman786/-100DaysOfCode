// Home Work
#include <iostream>
using namespace std;

int main()
{
    char ch;
    ch = cin.get();
    int n = ch; // converted char value to int so it returns the ASCII value
    if (ch >= 'a' && ch <= 'z')
        cout << "This is lower case";
    else if (ch >= 'A' && ch <= 'Z')
        cout << "This is upper case" << endl;
    else if (n >= 48 && n <= 57) // range of 0 to 9 in ASCII value used
        cout << "This is numeric" << endl;
}