#include <iostream>

int getMax(int array[], int n)
{
    int max = array[0];
    for (int i = 1; i < n; i++)
    {
        if (array[i] > max)
            max = array[i];
    }
    return max;
}

void countingSort(int array[], int size, int place)
{
    int output[size + 1];
    int max = (array[0] / place) % 10;
    for (int i = 1; i < size; i++)
    {
        if (((array[i] / place) % 10) > max)
            max = array[i];
    }
    int count[max + 1];
    for (int i = 0; i < max; ++i)
        count[i] = 0;
    for (int i = 0; i < size; i++)
        count[(array[i] / place) % 10]++;
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (int i = size - 1; i >= 0; i--)
    {
        output[count[(array[i] / place) % 10] - 1] = array[i];
        count[(array[i] / place) % 10]--;
    }
    for (int i = 0; i < size; i++)
        array[i] = output[i];
}

void radixsort(int array[], int size)
{
    int max = getMax(array, size);
    for (int place = 1; max / place > 0; place *= 10)
        countingSort(array, size, place);
}

void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;
}

int main()
{
    int n;
    std::cout << "Enter the size of the array: ";
    std::cin >> n;
    int array[n];
    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        std::cin >> array[i];
    }
    radixsort(array, n);
    std::cout << "Sorted array is " << std::endl;
    printArray(array, n);
}

// Pseudocode
//  1. radixSort(array, a)
//  2. max <- getMax(array, a)
//  3. for place <- 1 to max
//  4.     countingSort(array, a, place)

// explanation
// 1. radixSort(array, a) is a function that takes an array and its size as arguments.
// 2. max <- getMax(array, a) is a function that returns the maximum element in the array.
// 3. for place <- 1 to max is a loop that runs from 1 to the maximum element in the array.
// 4. countingSort(array, a, place) is a function that takes the array, its size and the place as arguments.