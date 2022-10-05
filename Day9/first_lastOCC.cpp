#include <bits/stdc++.h>
using namespace std;

int firstOcc(int arr[], int n, int key)
{
    int s = 0;

    int e = n - 1;
    int mid = s + (n - s) / 2;
    int ans = -1;

    while (s <= e)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            e = mid - 1;
        }
        else if (arr[mid] < key)
        {
            s = mid + 1;
        }
        else if (key > arr[mid])
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int lastOcc(int arr[], int n, int key)
{
    int s = 0;

    int e = n - 1;
    int mid = s + (n - s) / 2;
    int ans = -1;

    while (s <= e)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            s = mid + 1;
        }
        else if (arr[mid] < key)
        {
            s = mid + 1;
        }
        else if (key < arr[mid])
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}
int main()
{
    int arr[] = {1, 2, 3, 3, 3, 3, 3, 3, 3, 4, 5, 6, 7, 8};
    cout << "First Occurrence of 3 is at Index: " << firstOcc(arr, 13, 3) << "\n";
    cout << "Last Occurrence of 3 is at Index: " << lastOcc(arr, 13, 3) << "\n";

    return 0;
}