#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num = 5;
    int *ptr = &num;
    // bad practice to use cout<<*ptr<<endl;

    cout << num << endl;

    // address of operator - &
    // cout << "address of num is: " << &num << "\n";
    // cout << "value is :" << *ptr << endl;
    cout << "address is :" << ptr << "\n"; // address of num
    cout << "value is :" << *ptr << "\n";  // dereferencing operator - * (value at address)
    cout << "size of integer is " << sizeof(num) << endl;
    cout << "size of pointer is " << sizeof(ptr) << endl;
    return 0;
}