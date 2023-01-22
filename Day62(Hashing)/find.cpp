#include <bits/stdc++.h>
using namespace std;

int find(int num, int arr[])
{
    int count = 0;
    for (int i = 0; i < 10; i++)
    {
        if (arr[i] == num)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    cout << "Enter size of array: ";
    int n;
    cin >> n;
    int arr[n];
    cout << "Enter elements of array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter number to find: ";
    int num;
    cin >> num;
    cout << "Number of times " << num << " is present in array is: " << find(num, arr) << endl;

    return 0;
}