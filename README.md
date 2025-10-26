# UCS301 Lab Assignment 1 - Arrays

This repository contains solutions to Lab Assignment 1 for UCS301 Data Structures course, focusing on Array operations and manipulations.

---

## Question 1: Menu-Driven Array Operations

**Explanation:**  
This program implements a menu-driven interface to perform basic array operations including CREATE, DISPLAY, INSERT, DELETE, LINEAR SEARCH, and EXIT. The program uses a switch-case structure to handle user choices and performs operations dynamically on an array.

**Code:**
```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[100], n = 0, choice, pos, value, key, found;

    while(true) {
        cout << "\n------MENU------\n";
        cout << "1. CREATE\n";
        cout << "2. DISPLAY\n";
        cout << "3. INSERT\n";
        cout << "4. DELETE\n";
        cout << "5. LINEAR SEARCH\n";
        cout << "6. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter number of elements: ";
                cin >> n;
                cout << "Enter " << n << " elements: ";
                for(int i = 0; i < n; i++) {
                    cin >> arr[i];
                }
                cout << "Array created successfully\n";
                break;

            case 2:
                if(n == 0) {
                    cout << "Array is empty\n";
                } else {
                    cout << "Array elements: ";
                    for(int i = 0; i < n; i++) {
                        cout << arr[i] << " ";
                    }
                    cout << "\n";
                }
                break;

            case 3:
                cout << "Enter position to insert (0 to " << n << "): ";
                cin >> pos;
                if(pos < 0 || pos > n) {
                    cout << "Invalid position\n";
                } else {
                    cout << "Enter value: ";
                    cin >> value;
                    for(int i = n; i > pos; i--) {
                        arr[i] = arr[i-1];
                    }
                    arr[pos] = value;
                    n++;
                    cout << "Element inserted successfully\n";
                }
                break;

            case 4:
                cout << "Enter position to delete (0 to " << n-1 << "): ";
                cin >> pos;
                if(pos < 0 || pos >= n) {
                    cout << "Invalid position\n";
                } else {
                    for(int i = pos; i < n-1; i++) {
                        arr[i] = arr[i+1];
                    }
                    n--;
                    cout << "Element deleted successfully\n";
                }
                break;

            case 5:
                cout << "Enter element to search: ";
                cin >> key;
                found = -1;
                for(int i = 0; i < n; i++) {
                    if(arr[i] == key) {
                        found = i;
                        break;
                    }
                }
                if(found != -1) {
                    cout << "Element found at position " << found << "\n";
                } else {
                    cout << "Element not found\n";
                }
                break;

            case 6:
                cout << "Exiting program\n";
                return 0;

            default:
                cout << "Invalid choice\n";
        }
    }
    return 0;
}
```

**Sample Output:**
```
------MENU------
1. CREATE
2. DISPLAY
3. INSERT
4. DELETE
5. LINEAR SEARCH
6. EXIT
Enter your choice: 1
Enter number of elements: 5
Enter 5 elements: 10 20 30 40 50
Array created successfully

------MENU------
1. CREATE
2. DISPLAY
3. INSERT
4. DELETE
5. LINEAR SEARCH
6. EXIT
Enter your choice: 2
Array elements: 10 20 30 40 50

------MENU------
1. CREATE
2. DISPLAY
3. INSERT
4. DELETE
5. LINEAR SEARCH
6. EXIT
Enter your choice: 5
Enter element to search: 30
Element found at position 2
```

---

## Question 2: Remove Duplicate Elements

**Explanation:**  
This program removes duplicate elements from an array by comparing each element with all subsequent elements. When a duplicate is found, it shifts all elements to the left to fill the gap and reduces the array size.

**Code:**
```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[100], n;

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

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[i] == arr[j]) {
                for(int k = j; k < n - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                n--;
                j--;
            }
        }
    }

    cout << "Array after removing duplicates: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    return 0;
}
```

**Sample Output:**
```
Enter number of elements: 8
Enter 8 elements: 5 2 3 2 5 7 3 9
Original array: 5 2 3 2 5 7 3 9 
Array after removing duplicates: 5 2 3 7 9 
```

---

## Question 3: Predict Program Output

**Explanation:**  
This program demonstrates array initialization behavior in C++. When an array is initialized with `{1}`, the first element is set to 1, and all remaining elements are automatically initialized to 0. The program prints all 5 elements.

**Code:**
```cpp
#include <iostream>
using namespace std;

int main() {
    int i;
    int arr[5] = {1};
    for (i = 0; i < 5; i++)
        cout << arr[i];
    return 0;
}
```

**Output:**
```
10000
```

**Explanation of Output:**  
The array `arr[5] = {1}` initializes the first element to 1 and all other elements to 0 by default. Therefore, the output is `10000`.

---

## Question 4: Array and Matrix Operations

**Explanation:**  
This program provides three operations: reversing an array, multiplying two matrices, and finding the transpose of a matrix. The user selects an operation from a menu, and the program executes the corresponding function.

**Code:**
```cpp
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
```

**Sample Output (Reverse Array):**
```
1. Reverse Array
2. Matrix Multiplication
3. Matrix Transpose
Enter your choice: 1
Enter number of elements: 5
Enter 5 elements: 1 2 3 4 5
Original array: 1 2 3 4 5 
Reversed array: 5 4 3 2 1 
```

**Sample Output (Matrix Multiplication):**
```
Enter your choice: 2
Enter rows and columns for first matrix: 2 3
Enter rows and columns for second matrix: 3 2
Enter elements of first matrix:
1 2 3
4 5 6
Enter elements of second matrix:
7 8
9 10
11 12
Result matrix:
58 64 
139 154 
```

**Sample Output (Matrix Transpose):**
```
Enter your choice: 3
Enter rows and columns: 2 3
Enter matrix elements:
1 2 3
4 5 6
Original matrix:
1 2 3 
4 5 6 
Transpose matrix:
1 4 
2 5 
3 6 
```

---

## Question 5: Sum of Rows and Columns

**Explanation:**  
This program calculates and displays the sum of each row and each column in a two-dimensional array. It iterates through the matrix to compute row-wise and column-wise sums separately.

**Code:**
```cpp
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
```

**Sample Output:**
```
Enter number of rows and columns: 3 3
Enter matrix elements:
1 2 3
4 5 6
7 8 9

Matrix:
1 2 3 
4 5 6 
7 8 9 

Sum of each row:
Row 1 sum: 6
Row 2 sum: 15
Row 3 sum: 24

Sum of each column:
Column 1 sum: 12
Column 2 sum: 15
Column 3 sum: 18
```

---

## Conclusion

This assignment demonstrates fundamental array operations and two-dimensional array manipulations in C++. The programs cover essential data structure concepts including:

- **Dynamic array operations** through menu-driven interface
- **Array manipulation** techniques like duplicate removal and reversal
- **Array initialization** behavior and default values
- **Matrix operations** including multiplication and transpose
- **Two-dimensional array traversal** for computing row and column sums

These implementations provide a solid foundation for understanding array-based data structures and their applications in solving real-world programming problems. The solutions emphasize simplicity, efficiency, and proper handling of edge cases.

---

## License

MIT License - Feel free to use and modify these solutions for educational purposes.
