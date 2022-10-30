#include <bits/stdc++.h>
using namespace std;

int Binary_search(){
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int key;
    cout << "Enter the element to be searched: ";
    cin >> key;
    int low = 0;
    int high = n-1;
    int mid;
    while(low <= high){
        mid = (low + high)/2;
        if(arr[mid] == key){
            return mid;
        }
        else if(arr[mid] > key){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return -1;
}

int main(){
    int result = Binary_search();
    if(result == -1){
        cout << "Element not found";
    }
    else{
        cout << "Element found at index " << result<<"\n";
    }
    return 0;

}