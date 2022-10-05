// binary search

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n]; // array to take user input
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int key;
    cin >> key;
    int s = 0; // s > is start of the value
    int e = n - 1;

    while (s <= e)
    {
        int mid = (s + (e - s) / 2); // use the formula (s+(e-s)/2) to avoid overflow
        if (a[mid] == key)
        {
            cout << "found at " << mid << endl;
            break;
        }
        else if (a[mid] > key)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    if (s > e)
    {
        cout << "not found" << endl;
    }
    return 0;
}