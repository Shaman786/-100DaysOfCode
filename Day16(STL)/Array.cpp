#include<array>
#include<iostream>

using namespace std;
int main(){
    
    array<int,4> a = {1,2,3,4};
     int size = a.size();
     for (int i = 0; i < size; i++)
     {
         cout<<a[i]<<endl;
     }
     cout<<"Element at 2nd index: "<<a.at(2)<<endl;

     cout<<"last element: "<<a.back()<<endl;
        cout<<"first element: "<<a.front()<<endl;
        cout<<"empty or not: "<<a.empty()<<endl;
        cout<<"max size: "<<a.max_size()<<endl;
        cout<<"size: "<<a.size()<<endl;
        cout<<"swap: "<<endl;
        
        
     

}