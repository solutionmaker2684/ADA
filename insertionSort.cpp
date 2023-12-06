#include <iostream>
using namespace std;

void insertionSort(int input[], int size){
    for ( int i = 1; i < size; i++ ){
        int j, current = input[i];
        for ( j = i - 1; j >= 0; j-- ){
            if ( current < input[j] ){
                input[j+1] = input[j];
            }
            else{
                break;
            }
        }
        input[j+1] = current;
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
    insertionSort(arr, n);
    cout << "Array after sorting" << endl;
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
