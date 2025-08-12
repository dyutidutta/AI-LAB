#include <iostream>
#include <vector>
using namespace std;

void oddMagicSquare(int n, vector<vector<int>> &magic) {
    int i = 0, j = n / 2;
    for (int num = 1; num <= n * n; num++) {
        magic[i][j] = num;
        int newi = (i - 1 + n) % n;
        int newj = (j + 1) % n;
        if (magic[newi][newj] != 0) {
            i = (i + 1) % n;
        } else {
            i = newi;
            j = newj;
        }
    }
}

int main() {
    int n;
    cout << "Enter odd size of magic square (n >= 3): ";
    cin >> n;

    if (n < 3) {
        cout << "Magic square not possible for n < 3.\n";
        return 0;
    }
    if (n % 2 == 0) {
        cout << "Order is not odd.\n";
        return 0;
    }

    vector<vector<int>> magic(n, vector<int>(n, 0));
    oddMagicSquare(n, magic);

    cout << "\nMagic Square of size " << n << ":\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << magic[i][j] << "\t";
        }
        cout << "\n";
    }

    int magicConstant = n * (n * n + 1) / 2;
    cout << "\nMagic Constant = " << magicConstant << endl;

    return 0;
}

