#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a, b;
    cout << "Enter a number\n";
    cin >> n;

    a = 0, b = 1;
    cout << a << " " << b << " ";

    for (int i = 1; i <= n; i++)
    {
        int nextNum = a + b;
        cout << nextNum << " ";
        a = b;
        b = nextNum;
    }
    cout << "\n";
}