#include <iostream>
#include <vector>
using namespace std;

void compareAndSwap(int &a, int &b)
{
    if (a > b)
    {
        swap(a, b);
    }
}

void pairwiseSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n / 2; i++)
    {
        for (int j = 0; j < n - 1; j += 2)
        {
            compareAndSwap(arr[j], arr[j + 1]);
        }
        for (int j = 1; j < n - 1; j += 2)
        {
            compareAndSwap(arr[j], arr[j + 1]);
        }
    }
}

int main()
{
    int n;
    cout << "Enter number of elements : ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter " << n << " elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    pairwiseSort(arr);
    cout << "Array after sorting : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
