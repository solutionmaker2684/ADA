#include<bits/stdc++.h>
using namespace std;

int board[11][11];

bool isPossible( int n, int row, int column ){
    for ( int i = row - 1; i >= 0; i-- ){
        if ( board[i][column] == 1 ){
            return false;
        }
    }

    for ( int i = row - 1, j = column - 1; i >= 0 && j >= 0; i--, j-- ){
        if ( board[i][j] == 1 ){
            return false;
        }
    }

    for ( int i = row - 1, j = column + 1; i >= 0, j < n; i--, j++ ){
        if ( board[i][j] == 1 ){
            return false;
        }
    }

    return true;
}

void NQueenHelper( int n, int row ){
    if ( n == row ){
        for ( int i = 0; i < n; i++ ){
            for ( int j = 0; j < n; j++ ){
                cout << board[i][j] << " ";
            }
        }

        cout << endl;
    }

    for ( int j = 0; j < n; j++ ){
        if ( isPossible( n, row, j ) ){
            board[row][j] = 1;
            NQueenHelper( n, row + 1 );
            board[row][j] = 0;
        }
    }

    return;
}

void placeNQueens( int n, int row ) {
    for ( int i = 0; i < 11; i++ ){
        for ( int j = 0; j < 11; j++ ){
            board[i][j] = 0;
        }
    }

    NQueenHelper( n, row );
}

int main(){
    int n;
    cout << "Enter chessboard size : ";
    cin >> n;
    placeNQueens( n, 0 );
    return 0;
}