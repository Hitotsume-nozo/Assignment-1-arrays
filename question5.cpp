#include <iostream>
using namespace std;

int main() {
    int arr[10][10], r, c, rowSum, colSum;

    cout << "Enter number of rows and columns: ";
    cin >> r >> c;

    cout << "Enter matrix elements:\n";
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> arr[i][j];
        }
    }

    cout << "\nMatrix:\n";
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\nSum of each row:\n";
    for(int i = 0; i < r; i++) {
        rowSum = 0;
        for(int j = 0; j < c; j++) {
            rowSum += arr[i][j];
        }
        cout << "Row " << i+1 << " sum: " << rowSum << "\n";
    }

    cout << "\nSum of each column:\n";
    for(int j = 0; j < c; j++) {
        colSum = 0;
        for(int i = 0; i < r; i++) {
            colSum += arr[i][j];
        }
        cout << "Column " << j+1 << " sum: " << colSum << "\n";
    }

    return 0;
}