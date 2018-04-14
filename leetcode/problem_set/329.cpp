#include<iostream>
#include<vector>

using namespace std;

int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int rows, cols;

void buildData(vector<vector<int> >& nums) {
    vector<int> r1, r2, r3;
    r1.push_back(9);
    r1.push_back(9);
    r1.push_back(4);

    r2.push_back(6);
    r2.push_back(6);
    r2.push_back(8);


    r3.push_back(2);
    r3.push_back(1);
    r3.push_back(1);
    nums.push_back(r1);
    nums.push_back(r2);
    nums.push_back(r3);
}


void buildMatrixModel(int rows, int cols, vector<vector<int> >& tmp) {
    for(int i = 0; i < rows; i++) {
        tmp.push_back(vector<int>(cols, 0));
    }
}

bool isLegal(int row, int col) {
    if(row < 0 || col < 0 || row >= rows || col >= cols) {
        return false;
    }
    return true;
}

//用于求解(row, col)位置的最大递增长度
int bsf(vector<vector<int> >& matrix, vector<vector<int> >& tmp, int& rsl, int row, int col) {
    //剪枝
    // cout << row << " " << col <<endl;
    if(tmp[row][col] != 0) {
        return tmp[row][col];
    }

    int newCol, newRow, tmpPath = 0;
    for(int i = 0; i < 4; i++) {
        newRow = row + directions[i][0];
        newCol = col + directions[i][1];
        //获取最大的长度的结点
        if(isLegal(newRow, newCol) && matrix[newRow][newCol] > matrix[row][col]) {
            tmpPath = max(tmpPath, bsf(matrix, tmp, rsl, newRow, newCol));
        }
    }
    tmp[row][col] = tmpPath + 1;
    rsl = max(tmp[row][col], rsl);
    return tmp[row][col];
}

int longestIncreasingPath(vector<vector<int> >& matrix) {
    rows = matrix.size();
    if(rows == 0) {
        return 0;
    }
    cols = matrix[0].size();
    int rsl = 0;
    vector<vector<int> > tmp;
    buildMatrixModel(rows, cols, tmp); //用于暂存每个节点的路径长度
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            bsf(matrix, tmp, rsl, i, j);
        }
    }
    return rsl;
}

int main() {
    vector<vector<int> > matrix;
    buildData(matrix);
    cout << longestIncreasingPath(matrix) << endl;
}