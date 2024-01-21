#include <iostream>
#include <ctime>
using namespace std;

int* MatrixContents(unsigned int size)
{
    int* numbers = new int[size];
    cout << "Write " << size << " symbols:\n";
    for (int i = 0; i < size; i++)
    {
        cin >> numbers[i];
    }

    return numbers;
}

int** RandomMatrix(unsigned int m, unsigned int n, unsigned int size)
{
    int** matrix = new int* [m];
    int* numbers = MatrixContents(size);
    srand(time(NULL));

    for (int i = 0; i < m; i++)
    {
        matrix[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = numbers[rand() % size];
            cout.width(6);
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }

    return matrix;
}

int NumOfFullStrokes(int** matrix, unsigned int m, unsigned int n)
{
    int countZeroStrokes = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                countZeroStrokes++;
                break;
            }
        }
    }

    return m - countZeroStrokes;
}

int main()
{
    //set matrix settings
    const unsigned int m = 6;
    const unsigned int n = 3;
    const unsigned int size = 3;
    int** matrix = RandomMatrix(m, n, size);

    //printing result
    cout << "Number of full strokes: " << NumOfFullStrokes(matrix, m, n);
}