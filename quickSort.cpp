#include <iostream>
using namespace std;

int partition ( int input[], int startIndex, int endIndex ){
    int pivot = input[startIndex];
    int count_smaller_elements = 0;
    for ( int i = startIndex + 1; i <= endIndex; i++ ){
        if ( input[i] <= pivot )
            count_smaller_elements++;
    } 
    int pivotIndex = startIndex + count_smaller_elements;
    input[startIndex] = input[pivotIndex];
    input[pivotIndex] = pivot;
    int j = startIndex, k = endIndex;
    while ( j < startIndex + count_smaller_elements && k > startIndex + count_smaller_elements ){
        if ( input[j] <= pivot )
            j++;
        else if ( input[k] > pivot )
            k--;
        else {
            int temp = input[j];
            input[j] = input[k];
            input[k] = temp;
        }
    }
    return pivotIndex;
}

void quickSort(int input[], int startIndex, int endIndex){
	if ( startIndex >= endIndex )
        return;
    int i = partition ( input, startIndex, endIndex );
    quickSort ( input, startIndex, i - 1 );
    quickSort ( input, i + 1, endIndex );
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
    quickSort(arr, 0, n - 1);
    cout << "Array after sorting" << endl;
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}