#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

vector<int> queens;
int n;

void print(vector<int> queens) {
    int size = queens.size();
    for(int i = 1; i < size; i++) {
        cout << queens[i] << " ";
    }
    cout << endl;
}

int abs(int n) {
    return n < 0 ? -n : n;
}


void initQueens() {
    queens.clear();
    queens.push_back(0); //queen[0]不用
    //在每一行上放一个从1到n的整数
    for(int i = 1; i <= n; i++) {
        // queens.push_back(getRandom(1, n));
        queens.push_back((rand() % n) + 1);
    }
}

bool isConfilict(int row1, int row2) {
    if((abs(queens[row1] - queens[row2]) == abs(row1 - row2)) || queens[row1] == queens[row2] ) {
        return true;
    }
    return false;
}

int countOfConflict() {
    int count = 0;
    for(int i = 1; i < n; i++) {
        for(int j = i + 1; j <= n; j++) {
            if(isConfilict(i, j)) {
                ++count;
            }
        }
    }
    return count;
}

void swap(int row1, int row2) {
    int tmp = queens[row1];
    queens[row1] = queens[row2];
    queens[row2] = tmp;
}    

int countTrue(vector<bool>& flag) {
    int count = 0;
    for(int i = 1; i <= n; i++) {
        if(flag[i] == true) {
            ++count;
        }
    }
    return count;
}

int selectNthTrueIndex(vector<bool>& flag, int count) {
    for(int i = 1; i <= n; i++) {
        if(flag[i] == true) {
            --count;
            if(0 == count) {
                return i;
            }
        }
    }
}

bool changeTwoQueen() {
    int originalCount = countOfConflict();
    //随机产生一对组合，不要是同一行就可以了
    int row1, row2, tmp;
    vector<bool> flag1(n+1, true); //表示第一个组合数使用了哪些了，true表示可以使用
    vector<bool> flag2(n+1, true);
    //两层for循环，因为不知道哪些可以，最不好的情况的是要尝试所有的组合数，所以要记录这个组合数的
    for(int i = 1; i <= n; i++) {
        //生成组合数的第一位
        //策略是先判断有多少个组合数可以使用，然后随机生成一个数，这个数的最大是可使用组合数的最大值，然后以这个的值来计数
        int countTrue1 = countTrue(flag1);
        if(countTrue1 == 0) {
            break;
        }

        tmp = (rand() % countTrue1) + 1;
        // tmp = ge tRandom(1, countTrue1);
        
        int row1 = selectNthTrueIndex(flag1, tmp);
        flag1[row1] = false;
        //组合数第二位应该是从没有使用的第一位组合数中选择，包含两种情况，一种是当前轮两者不可以相等，另一种情况是之前选择过的第一个组合数不用再用了，因为已经测试过所有的以这个为第一个的组合数都不可以
        for(int j = 1; j <= n; j++) {
            flag2[j] = flag1[j];
        }
        //生成第二个组合数，最多也就是n次
        for(int i = 1; i <= n; i++) {
            int countTrue2 = countTrue(flag2);
            if(countTrue2 == 0) {
                break;
            }

            tmp = (rand() % countTrue2) + 1;
            // tmp = getRandom(1, countTrue2);
            int row2 = selectNthTrueIndex(flag2, tmp);
            flag2[row2] = false;
            //交换; 局部搜索
            swap(row1, row2);
            if(originalCount > countOfConflict()) {
                return true;
            } else {
                swap(row1, row2);
            }
        }
    
    }
    return false;
}

void queenSolution() {

    bool flag = false;
    srand((unsigned)time(NULL)); //随机数种子必须放在这里，不能重复初始化，复杂会一直得到一样的随机数
    // cout << "迭代过程:" << endl;
    while(1) {
        // cout << "重新初始化:" << endl;
        initQueens();
        // print(queens);
        // cout << "冲突数变化：" << endl;
        while(1) {
            // cout << countOfConflict() << endl;
            if(0 == countOfConflict()) {
                flag = true;
                break; 
            }
            if(!changeTwoQueen()) {
                break;
            }
        }
        if(flag == true) {
            // print(queens);
            break;
        }
        // cout << endl;
    }
}

int main() {
    // cin >> n;
    n = 8;
    queenSolution();
    cout << "结果" << endl;
    print(queens);
}