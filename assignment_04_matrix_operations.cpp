// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Function prototypes
void inputMatrix(int matrix[10][10], int rows, int cols);
void displayMatrix(int matrix[10][10], int rows, int cols);
void transposeMatrix(int matrix[10][10], int rows, int cols);
void addMatrices(int A[10][10], int B[10][10], int rows, int cols);
void multiplyMatrices(int A[10][10], int B[10][10], int rowsA, int colsA, int colsB);

int main()
{
    int choice;

    cout << "Matrix Operations" << endl;
    cout << "1. Transpose Matrix" << endl;
    cout << "2. Add Two Matrices" << endl;
    cout << "3. Multiply Two Matrices" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1)
    {
        int matrix[10][10];
        int rows, cols;

        cout << "Enter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;

        cout << "Enter matrix elements:" << endl;
        inputMatrix(matrix, rows, cols);

        cout << "\nOriginal Matrix:" << endl;
        displayMatrix(matrix, rows, cols);

        cout << "\nTransposed Matrix:" << endl;
        transposeMatrix(matrix, rows, cols);
    }
    else if (choice == 2)
    {
        int A[10][10], B[10][10];
        int rows, cols;

        cout << "Enter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;

        cout << "Enter elements of Matrix A:" << endl;
        inputMatrix(A, rows, cols);

        cout << "Enter elements of Matrix B:" << endl;
        inputMatrix(B, rows, cols);

        cout << "\nMatrix A:" << endl;
        displayMatrix(A, rows, cols);

        cout << "\nMatrix B:" << endl;
        displayMatrix(B, rows, cols);

        cout << "\nSum of Matrices:" << endl;
        addMatrices(A, B, rows, cols);
    }
    else if (choice == 3)
    {
        int A[10][10], B[10][10];
        int rowsA, colsA, rowsB, colsB;

        cout << "Enter rows for Matrix A: ";
        cin >> rowsA;
        cout << "Enter columns for Matrix A: ";
        cin >> colsA;

        cout << "Enter elements of Matrix A:" << endl;
        inputMatrix(A, rowsA, colsA);

        cout << "Enter rows for Matrix B: ";
        cin >> rowsB;
        cout << "Enter columns for Matrix B: ";
        cin >> colsB;

        if (colsA != rowsB)
        {
            cout << "Matrix multiplication is not possible." << endl;
            return 0;
        }

        cout << "Enter elements of Matrix B:" << endl;
        inputMatrix(B, rowsB, colsB);

        cout << "\nMatrix A:" << endl;
        displayMatrix(A, rowsA, colsA);

        cout << "\nMatrix B:" << endl;
        displayMatrix(B, rowsB, colsB);

        cout << "\nProduct of Matrices:" << endl;
        multiplyMatrices(A, B, rowsA, colsA, colsB);
    }
    else
    {
        cout << "Invalid choice." << endl;
    }

    return 0;
}

// Function to input a matrix
void inputMatrix(int matrix[10][10], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

// Function to display a matrix
void displayMatrix(int matrix[10][10], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

// Function to transpose a matrix
void transposeMatrix(int matrix[10][10], int rows, int cols)
{
    int transpose[10][10];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            transpose[j][i] = matrix[i][j];
        }
    }

    displayMatrix(transpose, cols, rows);
}

// Function to add two matrices
void addMatrices(int A[10][10], int B[10][10], int rows, int cols)
{
    int sum[10][10];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            sum[i][j] = A[i][j] + B[i][j];
        }
    }

    displayMatrix(sum, rows, cols);
}

// Function to multiply two matrices
void multiplyMatrices(int A[10][10], int B[10][10], int rowsA, int colsA, int colsB)
{
    int product[10][10];

    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            product[i][j] = 0;

            for (int k = 0; k < colsA; k++)
            {
                product[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    displayMatrix(product, rowsA, colsB);
}

