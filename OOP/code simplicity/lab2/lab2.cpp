#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

int* MatrixContents(int size)
{
    int* numbers = new int[size];
    cout << "Write " << size << " symbols:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "symbol " << i + 1 << " = ";
        try
        {
            cin >> numbers[i];
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw exception("Use only int numbers");
            }
        }
        catch (const exception& ex)
        {
            cerr << "Error: " << ex.what() << endl;
            return MatrixContents(size);
        }
    }

    return numbers;
}

int** RandomMatrix(int n, int m, int size)
{
    int** matrix = new int* [n];
    int* numbers = MatrixContents(size);
    srand(time(NULL));

    for (int i = 0; i < n; i++)
    {

        matrix[i] = new int[m];
        for (int j = 0; j < m; j++)
        {
            matrix[i][j] = numbers[rand() % size];
            cout.width(3);
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }

    return matrix;
}

int** RandomMatrix(int n, int m, int size, int* numbers)
{
    int** matrix = new int* [n];
    cout << size;
    srand(time(NULL));

    for (int i = 0; i < n; i++)
    {
        matrix[i] = new int[m];
        for (int j = 0; j < m; j++)
        {
            matrix[i][j] = numbers[rand() % size];
            cout.width(3);
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }

    return matrix;
}

int NumOfTargetedStrokes(int** matrix, int n, int m, int target)
{
    int countZeroStrokes = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == target)
            {
                countZeroStrokes++;
                break;
            }
        }
    }

    return n - countZeroStrokes;
}

int GetValue(string name)
{
    int x;
    cout << name << " = ";
    try
    {
        cin >> x;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            throw exception("Use only numbers");
        }
        else if (x < 0)
        {
            cin.clear();
            throw exception("Use only positive numbers");
        }
    }
    catch (const exception& ex)
    {
        cerr << "Error: " << ex.what() << endl;
        GetValue(name);
    }

    return x;
}

int main()
{
    //settin matrix settings
    int m, n, size, target;
    n = GetValue("n");
    m = GetValue("m");
    size = GetValue("size");
    target = GetValue("target");
    
    //creatin matrix
    int** matrix = RandomMatrix(n, m, size);

    //printing result
    cout << "Number of strokes without " << target << ": " << NumOfTargetedStrokes(matrix, n, m, target);
}