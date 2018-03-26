//模拟退火算法解决N皇后问题

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <vector>

using namespace std;

int N;
vector<int> queens;
int maxRound;
double temperature;
bool FAILED;
double annealingRate;

int abs(int val) {
    return val > 0 ? val : -val;
}


void print() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(j == queens[i]) {
                cout << "Q ";
            } else {
                cout << ". ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

void printO() {
    for(int i = 0;i < N; i++) {
        cout << queens[i] << " ";
    }
    cout << endl;
}

void init() {
    maxRound = 400;
    temperature = 50;
    annealingRate = 0.95;

    queens.clear();
    //在每一行上放一个从1到n的整数
    for(int i = 0; i <= N; i++) {
        queens.push_back((rand() % N) + 1);
    }
}

bool isConfilict(int row1, int row2) {
    if((abs(queens[row1] - queens[row2]) == abs(row1 - row2)) || queens[row1] == queens[row2] ) {
        return true;
    }
    return false;
}

int countConflict() {
    int count = 0;
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            if(isConfilict(i, j)) {
                ++count;
            }
        }
    }
    return count;
}

//只是说温度高的时候，即使是冲突数多的结果也可能被接收
void stepSimulateAnnealing() {

    int randomRow, randomCol, originConflict, currentConfilict, originCol;
    double deltaE, acceptProbability;
    while(true) {
        randomRow = rand() % N;
        randomCol = rand() % N;
        originConflict = countConflict();
        originCol = queens[randomRow];
        queens[randomRow] = randomCol;
        currentConfilict = countConflict();
        temperature = max(temperature * annealingRate, 0.02);
        if(currentConfilict < originConflict) {
            break;
        } else {
            deltaE = originConflict - currentConfilict;
            acceptProbability = min(exp(deltaE/temperature), 1.0);
            //接收 
            double tmpRandom = rand() % 1000 / (double)1000;
            if(tmpRandom < acceptProbability) {
                break;
            } else {
                //回退
                queens[randomRow] = originCol;
            }
        }
    }
}

void simulatedAnnealing() {
    int count = 0, originConflict;
    FAILED = false;
    while(true) {
        originConflict = countConflict();
        if(originConflict == 0) {
            FAILED = false;
            break;
        }

        stepSimulateAnnealing();
        // printO();
        if(FAILED == true) {
            break;
        }
        count += 1;
        // cout << count << endl;
        if(count >= maxRound) {
            FAILED = true;
            break;
        }
    }
}

void simulatedAnnealingSolveNQueens() {
    srand((unsigned)time(NULL));
    clock_t start, finish;
    start = clock();
    int num = 0;
    while(true) {
        init();//初始化
        // cout << "初始状态 " << endl;
        // printO();

        simulatedAnnealing();
        if(FAILED == true) {
            // cout << "重新初始化" << endl;
            continue;
        } else {
            cout << "找到解,如下" << endl;
            print();
            break;
        }
    }

    finish = clock();
    double t = (double)(finish - start) / CLOCKS_PER_SEC;
    cout << "消耗时间为 " << t  << "s" << endl; 
}

int main() {
    cout << "请输入皇后数"<< endl;
    cin >> N;
    // N = 15;
    simulatedAnnealingSolveNQueens();
}

