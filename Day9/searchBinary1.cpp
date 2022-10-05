// First/Last Occurrence of an Element in array: https://bit.ly/3Ioexjh

// Language: cpp
#include <iostream>
#include <vector>
using namespace std;

int firstOcc(vector<int> &arr, int n, int key) // function to find the first occurrence of the element
{
    int s = 0; //
    int e = n - 1;
    int ans = -1;
    while (s <= e)
    {
        int mid = (s + (e - s) / 2);
        if (arr[mid] == key)
        {
            ans = mid; // if the element is found then store the index of the element in ans
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
    return ans;
}

int lastOcc(vector<int> &arr, int n, int key)
{
    int s = 0;
    int e = n - 1;
    int ans = -1;
    while (s <= e)
    {
        int mid = (s + (e - s) / 2);
        if (arr[mid] == key)
        {
            ans = mid;
            s = mid + 1;
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
    return ans;
}
pair<int, int> firstLastOcc(vector<int> &arr, int n, int key)
{
    int first = firstOcc(arr, n, key);
    int last = lastOcc(arr, n, key);
    return {first, last};
}

int main()

{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int key;
    cin >> key;
    pair<int, int> ans = firstLastOcc(arr, n, key);
    cout << ans.first << " " << ans.second << endl;
    return 0;
}