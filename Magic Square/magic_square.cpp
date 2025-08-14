#include <iostream>
#include <vector>
using namespace std;

void oddMagicSquare(int n, vector<vector<int>> &magic)
{
    int i = 0, j = n / 2;
    for (int num = 1; num <= n * n; num++)
    {
        magic[i][j] = num;
        int newi = (i - 1 + n) % n;
        int newj = (j + 1) % n;
        if (magic[newi][newj] != 0)
        {
            i = (i + 1) % n;
        }
        else
        {
            i = newi;
            j = newj;
        }
    }
}

void doublyEvenMagicSquare(int n, vector<vector<int>> &square)
{
    int num = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            square[i][j] = ((i % 4 == j % 4) || ((i % 4 + j % 4) == 3))
                               ? n * n + 1 - num++
                               : num++;
        }
    }
}

void singlyEvenMagicSquare(int n, vector<vector<int>> &square)
{
    int half = n / 2;
    int subSize = half * half;
    vector<vector<int>> sub(half, vector<int>(half, 0));

    int i = 0, j = half / 2;
    for (int num = 1; num <= subSize; num++)
    {
        sub[i][j] = num;
        int ni = (i - 1 + half) % half;
        int nj = (j + 1) % half;
        if (sub[ni][nj] != 0)
            i = (i + 1) % half;
        else
        {
            i = ni;
            j = nj;
        }
    }

    for (int r = 0; r < half; r++)
    {
        for (int c = 0; c < half; c++)
        {
            int val = sub[r][c];
            square[r][c] = val;
            square[r + half][c + half] = val + subSize;
            square[r][c + half] = val + 2 * subSize;
            square[r + half][c] = val + 3 * subSize;
        }
    }

    
    int k = (half - 1) / 2;
    for (int r = 0; r < half; r++)
        for (int c = 0; c < k; c++)
            swap(square[r][c], square[r + half][c]);

    for (int r = 0; r < half; r++)
        for (int c = n - k + 1; c < n; c++)
            swap(square[r][c], square[r + half][c]);
}


void printMagicSquare(const vector<vector<int>> &square)
{
    int n = square.size();
    for (auto &row : square)
    {
        for (int val : row)
            cout << val << "\t";
        cout << "\n";
    }
    int magicConstant = n * (n * n + 1) / 2;
    cout << "\nMagic Constant = " << magicConstant << "\n";
}

int main()
{
    int n;
    cout << "Enter size of Magic Square (n >= 3): ";
    cin >> n;

    if (n < 3)
    {
        cout << "Magic square not possible for n < 3.\n";
        return 0;
    }

    vector<vector<int>> square(n, vector<int>(n, 0));

    if (n % 2 == 1)
    {
        oddMagicSquare(n, square);
    }
    else if (n % 4 == 0)
    {
        doublyEvenMagicSquare(n, square);
    }
    else
    {
        singlyEvenMagicSquare(n, square);
    }

    cout << "\nMagic Square of size " << n << ":\n";
    printMagicSquare(square);

    return 0;
}
