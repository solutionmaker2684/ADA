#include <iostream>
using namespace std;

void merge ( int input[], int startIndex, int endIndex ){
    int midIndex = ( startIndex + endIndex ) / 2;
    int size = endIndex - startIndex + 1;
    
    int * helparray = new int [ size ];
    
    int i = startIndex, j = midIndex + 1, k = 0; 
    
    while ( i <= midIndex && j <= endIndex ){
        if ( input[i] < input[j] ){
            helparray[k] = input[i];
            i++;
            k++;
        }
        
        else if ( input[i] > input[j] ){
            helparray[k] = input[j];
            j++;
            k++;
        }  
        
        else if ( input[i] == input[j] ){
            helparray[k] = input[i];
            i++;
            k++;
            helparray[k] = input[j]; 
            j++;
            k++;
        }
    }
    
    while ( i <= midIndex && j > endIndex ){
        helparray[k] = input[i];
        i++;
        k++;
    }
    
    while ( i > midIndex && j <= endIndex ){
        helparray[k] = input[j];
        j++;
        k++;
    }
    
    for ( int m = 0, l = startIndex; l <= endIndex ; m++, l++ ){
        input[l] = helparray[m];
    }
    
    delete [] helparray;
}

void mergeSort( int input[], int startIndex, int endIndex ){
    if ( startIndex >= endIndex ){
        return;
    }

    int midIndex = ( startIndex + endIndex ) / 2;
    
    mergeSort ( input, startIndex, midIndex );
    mergeSort ( input, midIndex + 1, endIndex );
    
    merge ( input, startIndex, endIndex );
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
    mergeSort(arr, 0, n - 1);
    cout << "Array after sorting" << endl;
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}