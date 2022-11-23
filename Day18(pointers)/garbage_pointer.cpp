#include <iostream>
using namespace std;
int main()
{
    // pointer to int is created, and pointing to some garbage address (not pointing to any variable)
    // int *p;
    // cout << *p << endl;
    /* int i = 5;
     int *q = &i;
     cout << q << endl;
     cout << *q << endl;

     int *p = 0;
     p = &i;
     cout << p << endl;
     cout << *p << endl;
 */
    int num = 5;
    int a = num;
    a++;
    cout << num << endl;
    int *p = &num;
    cout << "before" << num << endl;
    (*p)++;
    cout << "after" << num << endl;

    // copying a pointer
    int *q = p;
    cout << p << "  -  " << q << endl;
    cout << *p << "  -  " << *q << endl;
    // important concept
    int i = 3;
    int *t = &i;
    cout << t << endl;
    // cout << (*t)++ << endl; // ()at *t for quality code and precedence
    *t = *t + 1; // value at t is incremented
    cout << *t << endl;
    t = t + 1; // address at t is incremented, t is pointing to next address
    cout << *t << endl;
    cout << t << endl;
    return 0;

} // namespace std;
  // segmentation fault (core dumped) - program is trying to access some memory location which is not allocated to the program