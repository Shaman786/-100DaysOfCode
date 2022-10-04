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

    cout << "The matrix is\n";
    for (int i = 0; i < I; i++)
    {
        for (int j = 0; j < J; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\n";
    cout << "The sparse matrix is\n";
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

    cout << "Enter choice\n";
    cout << "a. Insertion\n";
    cout << "b. Deletion\n";
    cout << "c. Search\n";
    cout << "d. Exit\n";

    char ch;
    cin >> ch;
    switch (ch)
    {
    case 'a':
    {
        cout << "Enter the element to be inserted\n";
        int ele;
        cin >> ele;
        cout << "Enter the position\n";
        int pos;
        cin >> pos;
        if (pos > size)
        {
            cout << "Invalid position\n";
            break;
        }
        else
        {
            for (int i = size; i > pos; i--)
            {
                compactMatrix[0][i] = compactMatrix[0][i - 1];
                compactMatrix[1][i] = compactMatrix[1][i - 1];
                compactMatrix[2][i] = compactMatrix[2][i - 1];
            }
            compactMatrix[0][pos] = I;
            compactMatrix[1][pos] = J;
            compactMatrix[2][pos] = ele;
            size++;
            cout << "The new sparse matrix is\n";
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    cout << compactMatrix[i][j] << " ";
                }
                cout << endl;
            }
        }
        break;
    }
    case 'b':
    {
        cout << "Enter the position of element to be deleted\n";
        int pos;
        cin >> pos;
        if (pos > size)
        {
            cout << "Invalid position\n";
            break;
        }
        else
        {
            for (int i = pos; i < size; i++)
            {
                compactMatrix[0][i] = compactMatrix[0][i + 1];
                compactMatrix[1][i] = compactMatrix[1][i + 1];
                compactMatrix[2][i] = compactMatrix[2][i + 1];
            }
            size--;
            cout << "The new sparse matrix is\n";
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    cout << compactMatrix[i][j] << " ";
                }
                cout << endl;
            }
        }
        break;
    }
    }
}