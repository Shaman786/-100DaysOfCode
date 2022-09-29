#include <iostream>
using namespace std;

int main()
{
    // int a;
    // cin >> a; // cin- is input statement it doesn't store space , tab and enter for that we use cin.get()

    // cout<<"value of n is :"<<n<<endl;
    //  int a =5 ;
    //  int b= 14;
    //  if(a>b)
    //      cout<<"Answer is A";
    //      if(b>a)
    //      cout<<"Answer is B";
    //
    // int a,b;
    // a= cin.get();//cin.get(char& var):
    // It reads an input character and stores it in a variable.
    //  cout<< "Value of a is :"<< a << endl;
    /*int a, b;
    cout << "Enter the value of A " << endl;
    cin >> a;
    cout << "Enter the value of B" << endl;
    cin >> b;

    if (a > b)
    {
        cout << "A is greater" << endl;
    }
    if (b > a)
    {
        cout << "B is greater" << endl;
    }*/
    int a;
    cout << " Enter the value of a " << endl;
    cin >> a;

    // if(a>0){
    //     cout<<"A is greater"<<endl;
    // }else{
    //     if(a<0){
    //         cout<<"A is negative";

    //     }else{
    //         cout<<"A is 0";
    //     }
    // }
    if (a > 0)
    {
        cout << "A is positive" << endl;
    }

    else if (a<0)
    {
        cout << "A is negative" << endl;
    }
    else
    {
        cout << "A is 0" << endl;
    }
}