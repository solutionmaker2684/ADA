#include <iostream>
using namespace std;

void heapSort(int* arr, int n) {
    for ( int i = 1; i < n; i++ ){
        int childIndex = i;
        while ( childIndex > 0 ){
            int parentIndex = ( childIndex - 1 ) / 2;
            if ( arr[childIndex] > arr[parentIndex] ){
                int temp = arr[childIndex];
                arr[childIndex] = arr[parentIndex];
                arr[parentIndex] = temp;
            }
            else{
                break;
            }         
            childIndex = parentIndex;
        }
    }
    
    int size = n;
    while ( size > 1 ){
        int temp = arr[0];
        arr[0] = arr[size - 1];
        arr[size - 1] = temp;
        size--;   
        int parentIndex = 0;
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndex = 2 * parentIndex + 2;
        while ( leftChildIndex < size ){
            int minIndex = parentIndex;
            if ( arr[leftChildIndex] > arr[minIndex] ){
                minIndex = leftChildIndex;
            } 
            if ( rightChildIndex < size && arr[rightChildIndex] > arr[minIndex] ){
                minIndex = rightChildIndex;
            }
            if ( parentIndex == minIndex ){
                break;
            }
            int temp = arr[minIndex];
            arr[minIndex] = arr[parentIndex];
            arr[parentIndex] = temp;
            parentIndex = minIndex;
            leftChildIndex = 2 * parentIndex + 1;
            rightChildIndex = 2 * parentIndex + 2;
        }
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
    heapSort(arr, n);
    cout << "Array after sorting" << endl;
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
