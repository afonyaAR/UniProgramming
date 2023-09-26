#include <iostream>
#include <ctime>
using namespace std;

/// <summary>
/// Creating an array with dynamic size and fill it with int numbers
/// </summary>
/// <param name="size">of array</param>
/// <returns>array of chosen numbers</returns>
int* MatrixContents(int size)
{
    int* numbers = new int[size];
    cout << "Write " << size << " symbols:" << endl;
    for (int i = 0; i < size; i++)
    {
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

/// <summary>
/// Creating matrix randomly filled with chosen numbers
/// </summary>
/// <param name="m">strokes</param>
/// <param name="n">columns</param>
/// <param name="size">of array for matrix contents</param>
/// <returns>matrix</returns>
int** RandomMatrix(int m, int n, int size)
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
            cout.width(3);
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }

    return matrix;
}

/// <summary>
/// Finds number of strokes which contain target in there
/// </summary>
/// <param name="matrix"></param>
/// <param name="m">strokes</param>
/// <param name="n">columns</param>
/// <param name="target"></param>
/// <returns>number of strokes which contain target</returns>
int NumOfTargetedStrokes(int** matrix, int m, int n, int target)
{
    int countZeroStrokes = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == target)
            {
                countZeroStrokes++;
                break;
            }
        }
    }

    return m - countZeroStrokes;
}

/// <summary>
/// Validation to check is it a positive int number
/// </summary>
/// <param name="name">of parameter</param>
/// <returns>unsigned int and zero</returns>
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
        return GetValue(name);
    }

    return x;
}

int main()
{
    //settin matrix settings
    int m, n, size, target;
    m = GetValue("m");
    n = GetValue("n");
    size = GetValue("size");
    target = GetValue("target");

    //creatin matrix
    int** matrix = RandomMatrix(m, n, size);

    //printing result
    cout << "Number of strokes without " << target << ": " << NumOfTargetedStrokes(matrix, m, n, target);
}