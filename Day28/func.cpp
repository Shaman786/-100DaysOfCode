#include <bits/stdc++.h>
using namespace std;

// Functions are set of code which performs sometask for us
// Functions are used to avoid code repetition
// Functions are used to make code modular
// Functions are used to make code readable
// Functions are used to make code reusable
// Functions are used to make code debuggable
// void -> which does not return anything
// return
// patemeterised
// non parameterised
// void printStriver(string name)
// {
//     cout << "Striver" << endl;
//     cout << name << endl;
// }

// int main()
// {
//     string name;
//     cin >> name;
//     printStriver(name);

//     string name2;
//     cin >> name2;
//     printStriver(name2);

//     return 0;
// }

// int add(int a, int b)
// {
//     return a + b;
// }

// int main()
// {
//     int a, b;
//     cin >> a >> b;
//     cout << add(a, b) << endl;
//     return 0;
// }

// pass by value
//  void doSomething(int num)
//  {
//      cout << num << endl;
//      num += 5;
//      cout << num << endl;
//      num += 5;
//      cout << num << endl;
//  }

// int main()
// {
//     int num = 10;
//     doSomething(num);
//     cout << num << endl;
//     return 0;
// }

// pass by reference
void doSomething(int arr[], int n)
{
    arr[0] += 100;
    cout << "Value inside function : " << arr[0] << endl;
}
int main()
{
    int n = 5;
    int arr[n];
    for (int i = 0; i < 5; i++)
    {

        cin >> arr[i];
    }
    // for (int i = 0; i < 5; i++)
    // {
    //     cout << arr[i];
    // }
    doSomething(arr, n);
    cout << "Value inside int main: " << arr[0] << endl;

    return 0;
}