#include <iostream>
using namespace std;

void selectionSort(int input[], int n) {
    for(int i = 0; i < n-1; i++ ) {
        int min = input[i];
        int minIndex = i;
        for(int j = i+1; j < n; j++) {
            if(input[j] < min) {
                min = input[j];
                minIndex = j;
            }
        }
        int temp = input[i];
        input[i] = input[minIndex];
        input[minIndex] = temp;
    }
}

int main(){
    int n;
    cout << "Enter number of elements : ";
    cin >> n;
    int* arr = new int[n];
    cout << "Enter " << n << " elements : ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << "Array before sorting" << endl;
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    selectionSort(arr, n);
    cout << "Array after sorting" << endl;
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}