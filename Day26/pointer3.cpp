#include <bits/stdc++.h>
using namespace std;

void update(int **p2)
{
    // p = p + 1;
    // kuch change hoga?? - No
    // *p2 = *p2 + 1;
    // kuch change hoga?? - Yes
    **p2 = **p2 + 1;
    // kuch change hoga?? - Yes
}

int main()
{
    int i = 5;
    int *p = &i;
    int **p2 = &p;
    // cout << endl
    //      << endl
    //      << "Sab sahi chal raha hai" << endl;

    // cout << "printing p " << p << endl;
    // // cout << "address of p " << &p << endl;

    // cout << *p2 << endl;

    // cout << i << endl;
    // cout << *p << endl;
    // cout << **p2 << endl;

    // cout << &i << endl;
    // cout << p << endl;
    // cout << *p2 << endl;

    // cout << &p << endl;
    // cout << p2 << endl;
    cout << endl
         << endl;
    cout << "before " << i << endl;
    cout << "before " << p << endl;
    cout << "before " << p2 << endl;
    update(p2);
    cout << "after " << i << endl;
    cout << "after " << p << endl;
    cout << "after " << p2 << endl;

    return 0;
}