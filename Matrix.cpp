#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> mat;

vector<int> spiralMatrix(mat &matrix)
{
    vector<int> ans;
    int rowBegin = 0;
    int rowEnd = matrix.size() - 1;
    int colBegin = 0;
    int colEnd = matrix[0].size() - 1;

    while (rowBegin <= rowEnd && colBegin <= colEnd)
    {
        for (int index = colBegin; index <= colEnd; index++)
        {
            ans.push_back(matrix[rowBegin][index]);
        }
        rowBegin++;

        for (int index = rowBegin; index <= rowEnd; index++)
        {
            ans.push_back(matrix[index][colEnd]);
        }
        colEnd--;

        if (rowBegin <= rowEnd)
        {
            for (int index = colEnd; index >= colBegin; index--)
            {
                ans.push_back(matrix[rowEnd][index]);
            }
        }
        rowEnd--;

        if (colBegin <= colEnd)
        {
            for (int index = rowEnd; index >= rowBegin; index--)
            {
                ans.push_back(matrix[index][colBegin]);
            }
        }
        colBegin++;
    }
    return ans;
}

int sumOfNthDiagonal(mat &matrix, int key)
{
    int ans = 0;
    int row = matrix.size();
    int col = matrix[0].size();
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (j-i == key)
            {
                ans += matrix[i][j];
            }
        }
    }
    return ans;
}




int main()
{
    mat matrix = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };
    int nthLine=3;
    int ans = sumOfNthDiagonal(matrix, nthLine-1);
    cout << "Sum of nth Diagonal is: " << ans << endl;
    return 0;
}
