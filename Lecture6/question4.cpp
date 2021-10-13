#include <iostream>
using namespace std;

const int m = 3, n = 2, r = 5;

int entry_for_row_and_column(int row, int column, int arr1[][n], int arr2[][r])
{
    int total = 0;
    for (int count = 0; count < n; count++)
    {
        total += arr1[row][count] * arr2[count][column];
    }
    return total;
}

void matrix_mult(int arr1[][n], int arr2[][r], int answer[][r], int m)
{
    for (int row = 0; row < m; row++)
        for (int column = 0; column < r; column++)
        {
            answer[row][column] = entry_for_row_and_column(row, column, arr1, arr2);
        }
}

/* DEFINITION OF FUNCTION display_N_column_matrix */
void display_N_column_matrix(int a[][n], int m)
{
    for (int row = 0; row < m; row++)
    {
        cout << "           ";
        for (int column = 0; column < n; column++)
        {
            cout.width(5);
            cout << a[row][column] << " ";
        }
        cout << "\n";
    }
}

/* DEFINITION OF FUNCTION display_R_column_matrix */
void display_R_column_matrix(int a[][r], int m)
{
    for (int row = 0; row < m; row++)
    {
        cout << "           ";
        for (int column = 0; column < r; column++)
        {
            cout.width(5);
            cout << a[row][column] << " ";
        }
        cout << "\n";
    }
}

int main()
{

    int arr1[m][n];
    int arr2[n][r];
    int answer[m][r];

    cout << "INPUT FIRST (" << m << "x" << n << ") MATRIX:" << endl;
    for (size_t i = 0; i < m; i++)
    {
        cout << "Type in " << n << " values for row " << i + 1 << " separated by spaces: ";
        for (size_t j = 0; j < n; j++)
        {
            cin >> arr1[i][j];
        }

        cout << arr1 << endl;
    }

    cout << "INPUT SECOND (" << n << "x" << r << ") MATRIX:" << endl;
    for (size_t i = 0; i < n; i++)
    {
        cout << "Type in " << r << " values for row " << i + 1 << " separated by spaces: ";
        for (size_t j = 0; j < r; j++)
        {
            cin >> arr2[i][j];
        }

        cout << arr2 << endl;
    }

    matrix_mult(arr1, arr2, answer, m);
    cout << "\n";
    display_N_column_matrix(arr1, m);
    cout << "TIMES\n";
    display_R_column_matrix(arr2, n);
    cout << "EQUALS\n";
    display_R_column_matrix(answer, m);
    return 0;
}
