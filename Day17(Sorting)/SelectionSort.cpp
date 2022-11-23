//
// selectionSort(array, size)
// repeat(size - 1) times
// set the first unsorted element as the minimum
// for each of the unsorted elements
// if element < currentMinimum
// set element as new minimum
// swap minimum with first unsorted position
// end selectionSort

#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int array[], int size)
{
    for (int step = 0; step < size - 1; step++)
    {
        int min_idx = step;
        for (int i = step + 1; i < size; i++)
        {
            if (array[i] < array[min_idx])
                min_idx = i;
        }
        swap(&array[min_idx], &array[step]);
    }
}

void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main()
{
    cout << "Enter the size of the array: ";
    int size;
    cin >> size;
    int array[size];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }
    selectionSort(array, size);
    cout << "Sorted array in Acsending Order: " << endl;
    printArray(array, size);
}

// pseudo code
// selection sort(array, size)
// for i = 0 to size - 1
// min = i
// for j = i + 1 to size
// if array[j] < array[min]
// min = j
// swap array[min] and array[i]
// end selection sort

// 3 correct outputs:
// Enter the size of the array: 5
// Enter the elements of the array: 5 4 3 2 1
// Sorted array in Acsending Order:
// 1 2 3 4 5
// Enter the size of the array: 5
// Enter the elements of the array: 1 2 3 4 5
// Sorted array in Acsending Order:
// 1 2 3 4 5
// Enter the size of the array: 5
// Enter the elements of the array: 1 1 1 1 1
// Sorted array in Acsending Order:
// 1 1 1 1 1
