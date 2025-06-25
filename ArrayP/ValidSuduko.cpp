#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<string>> board = { 
        {"5", "3", ".", ".", "7", ".", ".", ".", "."},
        {"6", ".", ".", "1", "9", "5", ".", ".", "."},
        {".", "9", "8", ".", ".", ".", ".", "6", "."},
        {"8", ".", ".", ".", "6", ".", ".", ".", "3"},
        {"4", ".", ".", "8", ".", "3", ".", ".", "1"},
        {"7", ".", ".", ".", "2", ".", ".", ".", "6"},
        {".", "6", ".", ".", ".", ".", "2", "8", "."},
        {".", ".", ".", "4", "1", "9", ".", ".", "5"},
        {".", ".", ".", ".", "8", ".", ".", "7", "9"} 
    };

    // Convert into integer matrix
    vector<vector<int>> mat(9, vector<int>(9));
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == ".") {
                mat[i][j] = 0;
            } else {
                mat[i][j] = stoi(board[i][j]); // Convert string to int
            }
        }
    }

    // Check for ROW duplicates
    for (int i = 0; i < 9; i++) {
        vector<bool> isInRow(10, false); // Track numbers 1-9
        for (int j = 0; j < 9; j++) {
            if (mat[i][j] != 0) {
                if (isInRow[mat[i][j]]) {
                    cout << "Invalid Sudoku: Duplicate in row " << i << endl;
                    return 0;
                } else {
                    isInRow[mat[i][j]] = true;
                }
            }
        }
    }

    // Check for COLUMN duplicates
    for (int i = 0; i < 9; i++) {
        vector<bool> isInCol(10, false);
        for (int j = 0; j < 9; j++) {
            if (mat[j][i] != 0) {
                if (isInCol[mat[j][i]]) {
                    cout << "Invalid Sudoku: Duplicate in column " << i << endl;
                    return 0;
                } else {
                    isInCol[mat[j][i]] = true;
                }
            }
        }
    }

    // Subgrid check (FIXED: Removed outer declaration)
    for (int i = 0; i < 9; i += 3) {
        for (int j = 0; j < 9; j += 3) {
            vector<bool> isInSubgrid(10, false); // Reset for each subgrid
            for (int k = i; k < i + 3; k++) {
                for (int l = j; l < j + 3; l++) {
                    if (mat[k][l] != 0) {
                        if (isInSubgrid[mat[k][l]]) {
                            cout << "Invalid Sudoku: Duplicate in subgrid starting at (" 
                                 << i << ", " << j << ")" << endl;
                            return 0;
                        } else {
                            isInSubgrid[mat[k][l]] = true;
                        }
                    }
                }
            }
        }
    }

    cout << "Valid Sudoku!" << endl;
    return 0;
}