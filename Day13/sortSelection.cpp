// Selection sort algorithm implementation file for the Sort class

#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int> &v)
{
    int i, j, min, temp;
    for (i = 0; i < v.size() - 1; i++)
    {
        min = i;
        for (j = i + 1; j < v.size(); j++)
            if (v[j] < v[min])
                min = j;
        temp = v[i];
        v[i] = v[min];
        v[min] = temp;
    }
}

int main()
{
    vector<int> v;
    int n, i, x;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (i = 0; i < n; i++)
    {
        cin >> x;
        v.push_back(x);
    }
    selectionSort(v);
    cout << "Sorted array: ";
    for (i = 0; i < n; i++)
        cout << v[i] << " ";
    cout << endl;
    return 0;
}
// End of program
// Algorithm: Selection Sort
// Time Complexity: O(n^2)
// Space Complexity: O(1)
// Stable: No
// In-Place: Yes
// Pseudocode:
// selectionSort(A, n)
//   for i = 1 to n - 1
//     min = i
//     for j = i + 1 to n
//       if A[j] < A[min]
//         min = j
//     swap A[i] and A[min]
//   end for
// end selectionSort

// Test Case:
// Enter the number of elements: 5
// Enter the elements: 5 4 3 2 1
// Sorted array: 1 2 3 4 5
