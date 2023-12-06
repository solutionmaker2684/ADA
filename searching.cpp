#include <iostream>
using namespace std;

int linearSearch(int* arr, int n, int targetElement){
    for(int i = 0; i < n; i++){
        if(arr[i] == targetElement){
            return i;
        }
    }
    return -1;
}

int binarySearch(int* arr, int n, int targetElement){
    int startIndex = 0;
    int endIndex = n - 1;
    while(startIndex <= endIndex){
        int midIndex = (startIndex + endIndex)/2;
        if(arr[midIndex] == targetElement){
            return midIndex;
        }else if(arr[midIndex] > targetElement){
            endIndex = midIndex - 1;
        }else{
            startIndex = midIndex + 1;
        }
    }
    return -1;
}

int binarySearchRecursive(int* arr, int startIndex, int endIndex, int targetElement){
    if(startIndex > endIndex){
        return -1;
    }

    int midIndex = (startIndex + endIndex)/2;
    if(arr[midIndex] == targetElement){
        return midIndex;
    }else if(arr[midIndex] > targetElement){
        return binarySearchRecursive(arr, startIndex, midIndex - 1, targetElement);
    }else{
        return binarySearchRecursive(arr, midIndex + 1, endIndex, targetElement);
    }
}

int main(){
    int choice;
    cout << "1. Linear Search" << endl;
    cout << "2. Binary Search" << endl;
    cout << "3. Binary Search (Recursively)" << endl;
    cout << "Enter your choice : ";
    cin >> choice;

    int n;
    cout << "Enter number of elements : ";
    cin >> n;

    int* arr = new int[n];
    cout << "Enter " << n << " elements : ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int targetElement;
    cout << "Enter element you want to search : ";
    cin >> targetElement;

    int result;
    if(choice == 1){
        result = linearSearch(arr, n, targetElement);
    }else if(choice == 2){
        result = binarySearch(arr, n, targetElement);
    }else if(choice == 3){
        result = binarySearchRecursive(arr, 0, n - 1, targetElement);
    }

    if(result == -1){
        cout << "Element not found" << endl;
    }else{
        cout << "Element found at " << result << endl;
    }

    return 0;
}