#include <iostream>
#include <vector>

using namespace std;

class NumMatrix{
private:
    vector<vector<int> > sumMatrix;

public:
    NumMatrix(vector<vector<int> > matrix) {
        this->sumMatrix = matrix;
        int rows = matrix.size();
        if(rows == 0) {
            return;
        }
        int cols = matrix[0].size();
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(i == 0 && j == 0) {
                    continue;
                } else if(i == 0) {
                    this->sumMatrix[i][j] += this->sumMatrix[i][j-1];
                } else if(j == 0) {
                    this->sumMatrix[i][j] += this->sumMatrix[i-1][j];
                } else {
                    this->sumMatrix[i][j] += this->sumMatrix[i-1][j] + this->sumMatrix[i][j-1] - this->sumMatrix[i-1][j-1];
                }

            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2 ) {
        int rsl = this->sumMatrix[row2][col2];
        if(row1 > 0) {
            rsl -= this->sumMatrix[row1-1][col2];
        }
        if(col1 > 0) {
            rsl -= this->sumMatrix[row2][col1-1];
        }
        if(row1 > 0 && col1 > 0) {
            rsl += this->sumMatrix[row1-1][col1-1];
        }
        return rsl;
    }
};

int main() {
    vector<vector<int> > matrix;
    vector<int> v1;
    v1.push_back(3);
    v1.push_back(0);
    v1.push_back(1);
    v1.push_back(4);
    v1.push_back(2);

    vector<int> v2;
    v2.push_back(5);
    v2.push_back(6);
    v2.push_back(3);
    v2.push_back(2);
    v2.push_back(1);

    vector<int> v3;
    v3.push_back(1);
    v3.push_back(2);
    v3.push_back(0);
    v3.push_back(1);
    v3.push_back(5);

    vector<int> v4;
    v4.push_back(4);
    v4.push_back(1);
    v4.push_back(0);
    v4.push_back(1);
    v4.push_back(7);

    vector<int> v5;
    v5.push_back(1);
    v5.push_back(0);
    v5.push_back(3);
    v5.push_back(0);
    v5.push_back(5);
    

    matrix.push_back(v1);
    matrix.push_back(v2);
    matrix.push_back(v3);
    matrix.push_back(v4);
    matrix.push_back(v5);
    NumMatrix obj(matrix);
    cout << obj.sumRegion(1,1,2,2) << endl;
}