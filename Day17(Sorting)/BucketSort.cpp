// Implementation of BucketSort

#include <iostream>

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}
void BucketSort(int arr[], int a)
{                     // a is the size of the array
    int max = arr[0]; // max is the maximum element in the array
    for (int i = 0; i < a; i++)
    { // finding the maximum element in the array
        if (arr[i] > max)
        {                 // if the element is greater than the max
            max = arr[i]; // then max is assigned to that element
        }
    }
    int bucket[max + 1]; // creating a bucket of size max+1
    for (int i = 0; i < max + 1; i++)
    {                  // initializing the bucket with 0
        bucket[i] = 0; // initializing the bucket with 0
    }
    for (int i = 0; i < a; i++)
    {                     // incrementing the bucket value by 1
        bucket[arr[i]]++; // incrementing the bucket value by 1
    }
    int j = 0; // initializing the index of the array
    for (int i = 0; i < max + 1; i++)
    { // traversing the bucket
        while (bucket[i] > 0)
        {                // if the bucket value is greater than 0
            arr[j] = i;  // then the array is assigned the value of the bucket
            j++;         // incrementing the index of the array
            bucket[i]--; // decrementing the bucket value by 1
        }
    }
}

int main()
{
    int n;
    std::cout << "Enter the size of the array: ";
    std::cin >> n;
    int arr[n];
    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
    BucketSort(arr, n);
    std::cout << "Sorted array is " << std::endl;
    printArray(arr, n);
}

// Pseudocode
// BucketSort( array, a)
// 1. max <- array[0]
// 2. for i <- 0 to a
// 3.     if array[i] > max
// 4.         max <- array[i]
// 5.     end if
// 6. end for
// 7. bucket <- new array of size max+1
// 8. for i <- 0 to max+1
// 9.     bucket[i] <- 0
// 10. end for
// 11. for i <- 0 to a
// 12.     bucket[array[i]] <- bucket[array[i]] + 1
// 13. end for
// 14. j <- 0
// 15. for i <- 0 to max+1
// 16.     while bucket[i] > 0
// 17.         array[j] <- i
// 18.         j <- j + 1
// 19.         bucket[i] <- bucket[i] - 1
// 20.     end while
// 21. end for
// 22. return array
// 23. end BucketSort

// explanation
// BucketSort( array, a)
// maximum element in the array is found
// for loop is used to find the maximum element in the array
// if the element is greater than the max
// then max is assigned to that element
// a bucket of size max+1 is created
// for loop is used to initialize the bucket with 0
// for loop is used to increment the bucket value by 1
// index of the array is initialized
// for loop is used to traverse the bucket
// while loop is used to check if the bucket value is greater than 0
// then the array is assigned the value of the bucket
// index of the array is incremented
// bucket value is decremented by 1
// return array
