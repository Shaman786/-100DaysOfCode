#include <iostream>
using namespace std;

int firstOcc(int arr[], int n, int key)
{
    int s = 0;
    int mid = s + (n - s) / 2;
    int e = n - 1;
    int ans = -1;

    while (s <= e)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            e = mid - 1;
        }
        else if (arr[mid] > key)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
}
int main()
{
    int arr[] = {1, 2, 3, 3, 3, 3, 3, 3, 3, 4, 5, 6, 7, 8};
    cout << firstOcc(arr, 14, 3);

    return 0;
}