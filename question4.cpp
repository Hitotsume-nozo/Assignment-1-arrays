#include <iostream>
using namespace std;

void reverseArray() {
    int arr[100], n, temp;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Original array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    for(int i = 0; i < n/2; i++) {
        temp = arr[i];
        arr[i] = arr[n-1-i];
        arr[n-1-i] = temp;
    }

    cout << "Reversed array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void matrixMultiplication() {
    int a[10][10], b[10][10], c[10][10], r1, c1, r2, c2;

    cout << "Enter rows and columns for first matrix: ";
    cin >> r1 >> c1;

    cout << "Enter rows and columns for second matrix: ";
    cin >> r2 >> c2;

    if(c1 != r2) {
        cout << "Matrix multiplication not possible\n";
        return;
    }

    cout << "Enter elements of first matrix:\n";
    for(int i = 0; i < r1; i++) {
        for(int j = 0; j < c1; j++) {
            cin >> a[i][j];
        }
    }

    cout << "Enter elements of second matrix:\n";
    for(int i = 0; i < r2; i++) {
        for(int j = 0; j < c2; j++) {
            cin >> b[i][j];
        }
    }

    for(int i = 0; i < r1; i++) {
        for(int j = 0; j < c2; j++) {
            c[i][j] = 0;
            for(int k = 0; k < c1; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    cout << "Result matrix:\n";
    for(int i = 0; i < r1; i++) {
        for(int j = 0; j < c2; j++) {
            cout << c[i][j] << " ";
        }
        cout << "\n";
    }
}

void matrixTranspose() {
    int a[10][10], t[10][10], r, c;

    cout << "Enter rows and columns: ";
    cin >> r >> c;

    cout << "Enter matrix elements:\n";
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> a[i][j];
        }
    }

    cout << "Original matrix:\n";
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            t[j][i] = a[i][j];
        }
    }

    cout << "Transpose matrix:\n";
    for(int i = 0; i < c; i++) {
        for(int j = 0; j < r; j++) {
            cout << t[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    int choice;

    cout << "\n1. Reverse Array\n";
    cout << "2. Matrix Multiplication\n";
    cout << "3. Matrix Transpose\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch(choice) {
        case 1:
            reverseArray();
            break;
        case 2:
            matrixMultiplication();
            break;
        case 3:
            matrixTranspose();
            break;
        default:
            cout << "Invalid choice\n";
    }

    return 0;
}