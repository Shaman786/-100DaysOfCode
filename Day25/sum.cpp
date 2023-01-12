// You are given N elements, you can remove any two elements from the list, note their sum, and add the sum to the list. Repeat these steps while there is more than a single element in the list. The task is to minimize the sum of these chosen sums. use function in c++ to solve the problem which has two parameters one in N for the no. of elements and the other is for the elements of the vector

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int sum = 0;
    while (v.size() > 1)
    {
        sort(v.begin(), v.end());
        int a = v[0];
        int b = v[1];
        sum = sum + a + b;
        v.erase(v.begin());
        v.erase(v.begin());
        v.push_back(a + b);
    }
    cout << sum;
    return 0;
}
