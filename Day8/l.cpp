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
        cout << "Enter row and column of element to be inserted\n";
        int row, col;
        cin >> row >> col;
        cout << "Enter element to be inserted\n";
        int ele;
        cin >> ele;
        int flag = 0;
        for (int i = 0; i < size; i++)
        {
            if (compactMatrix[0][i] == row && compactMatrix[1][i] == col)
            {
                compactMatrix[2][i] = ele;
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            compactMatrix[0][size] = row;
            compactMatrix[1][size] = col;
            compactMatrix[2][size] = ele;
            size++;
        }
        cout << "The new sparse matrix is\n";
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < size; j++)
            {
                cout << compactMatrix[i][j] << " ";
            }
            cout << endl;
        }
        break;
    }

    case 'b':
    {
        cout << "Enter row and column of element to be deleted\n";
        int row1, col1;
        cin >> row1 >> col1;
        int flag1 = 0;
        for (int i = 0; i < size; i++)
        {
            if (compactMatrix[0][i] == row1 && compactMatrix[1][i] == col1)
            {
                for (int j = i; j < size - 1; j++)
                {
                    compactMatrix[0][j] = compactMatrix[0][j + 1];
                    compactMatrix[1][j] = compactMatrix[1][j + 1];
                    compactMatrix[2][j] = compactMatrix[2][j + 1];
                }
                flag1 = 1;
                size--;
                break;
            }
        }
        if (flag1 == 0)
        {
            cout << "Element not found\n";
        }
        else
        {
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
    case 'c':
    {
        cout << "Enter row and column of element to be searched\n";
        int row2, col2;
        cin >> row2 >> col2;
        int flag2 = 0;
        for (int i = 0; i < size; i++)
        {
            if (compactMatrix[0][i] == row2 && compactMatrix[1][i] == col2)
            {
                cout << "Element found at " << i + 1 << " position\n";
                flag2 = 1;
                break;
            }
        }
        if (flag2 == 0)
        {
            cout << "Element not found\n";
        }
        break;
    }
    case 'd':
    {
        exit(0);
        break;
    }
    default:
        cout << "Invalid choice\n";
    }
}