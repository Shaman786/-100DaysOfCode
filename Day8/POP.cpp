#include <bits/stdc++.h>
using namespace std;
int main()
{
    cout << "Enter order of matrix\n";
    int I, J;
    cin >> I >> J;
    int a[I][J];
    cout << "Enter elements of matrix\n";
    for (int i = 0; i < I; i++)
    {
        for (int j = 0; j < J; j++)
        {
            cin >> a[i][j];
        }
    }
    int size = 0;
    for (int i = 0; i < I; i++)
    {
        for (int j = 0; j < J; j++)
        {
            if (a[i][j] != 0)
            {
                size++;
            }
        }
    }
    int compactMatrix[3][size];
    // making of new matrix
    int k = 0;
    for (int i = 0; i < I; i++)
    {
        for (int j = 0; j < J; j++)
        {
            if (a[i][j] != 0)
            {
                compactMatrix[0][k] = i;
                compactMatrix[1][k] = j;
                compactMatrix[2][k] = a[i][j];
                k++;
            }
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << compactMatrix[i][j] << " ";
        }
        cout << endl;
    }
}
