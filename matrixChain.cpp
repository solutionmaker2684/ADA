#include <iostream>
#include <climits>
using namespace std;

int matrixChainMultiplication(int *arr, int n)
{
    int **output = new int *[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        output[i] = new int[n + 1];
    }

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            if (i >= j || i == j - 1)
            {
                output[i][j] = 0;
            }
        }
    }

    for (int len = 2; len < n + 1; len++)
    {
        for (int row = 0, col = len; row < n - len + 1; row++, col++)
        {
            output[row][col] = INT_MAX;
            for (int k = row + 1; k < col; k++)
            {
                output[row][col] = min(output[row][col], output[row][k] + output[k][col] + arr[row] * arr[k] * arr[col]);
            }
        }
    }
    return output[0][n];
}

int main()
{
    int n;
    cout << "Enter n : ";
    cin >> n;
    int *arr = new int[n + 1];
    cout << "Enter n + 1 elements : ";
    for (int i = 0; i <= n; i++)
    {
        cin >> arr[i];
    }

    cout << "Minimum number of multiplications = " << matrixChainMultiplication(arr, n);

    delete[] arr;
}