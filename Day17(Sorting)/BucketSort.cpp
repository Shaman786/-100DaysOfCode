//Implementation of BucketSort

#include <iostream>


void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}
void BucketSort(int arr[],int a){ //a is the size of the array
    int max=arr[0]; //max is the maximum element in the array
    for(int i=0;i<a;i++){ //finding the maximum element in the array
        if(arr[i]>max){//if the element is greater than the max
            max=arr[i];// then max is assigned to that element
        }
    }
    int bucket[max+1];//creating a bucket of size max+1
    for(int i=0;i<max+1;i++){//initializing the bucket with 0
        bucket[i]=0;//initializing the bucket with 0
    }
    for(int i=0;i<a;i++){//incrementing the bucket value by 1
        bucket[arr[i]]++;//incrementing the bucket value by 1
    }
    int j=0;//initializing the index of the array
    for(int i=0;i<max+1;i++){//traversing the bucket
        while(bucket[i]>0){//if the bucket value is greater than 0
            arr[j]=i;//then the array is assigned the value of the bucket
            j++;//incrementing the index of the array
            bucket[i]--;//decrementing the bucket value by 1
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

//