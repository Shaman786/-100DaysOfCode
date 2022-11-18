//Implementation of MergeSort
#include <iostream>

using namespace std;

void Merge(int arr[],int p,int q,int r){
    int n1=q-p+1;
    int n2=r-q;
   int L[n1],M[n2];
   for(int i = 0;i<n1;i++){
       L[i]=arr[p+i];
   }
   for(int j = 0;j<n2;j++){
       M[j]=arr[q+j+1];
   }
   int i=0,j=0,k=p;
    while(i<n1 && j<n2){
         if(L[i]<=M[j]){
              arr[k]=L[i];
              i++;
         }
         else{
              arr[k]=M[j];
              j++;
         }
         k++;
    }
    while(i<n1){
         arr[k]=L[i];
         i++;
         k++;
    }
    while(j<n2){
         arr[k]=M[j];
         j++;
         k++;
    }
}

void MergeSort(int arr[],int p,int r){
    if(p<r){
         int q=(p+r)/2;
         MergeSort(arr,p,q);
         MergeSort(arr,q+1,r);
         Merge(arr,p,q,r);
    }
}
void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        cout<<A[i]<<" ";
    cout<<endl;
}

int main(){
    cout<<"Enter the size of the array: ";
    int n;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Given array is: ";
    printArray(arr,n);
    MergeSort(arr,0,n-1);
    cout<<"Sorted array is: ";
    printArray(arr,n);
    return 0;
}

// Psuedo Code:
// MergeSort(arr[], l,  r)
// If r > l
// q = (l+r)/2
// MergeSort(arr, l, q)
// MergeSort(arr, q+1, r)
// Merge(arr, l, q, r)

// explaination:
// MergeSort is a Divide and Conquer algorithm. It divides input array in two halves, calls itself for the two halves and then merges the two sorted halves. The merge() function is used for merging two halves. The merge(arr, l, m, r) is key process that assumes that arr[l..m] and arr[m+1..r] are sorted and merges the two sorted sub-arrays into one.

//wrong o/p
//Enter the size of the array: 5
//Enter the elements of the array: 5 4 3 2 1
//Given array is: 5 4 3 2 1
//Sorted array is: 1 2 3 4 5
