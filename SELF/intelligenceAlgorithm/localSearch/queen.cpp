#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

vector<int> queens;
int n;
int RANDOM_ROWS = 5; //表示在进行产生随机因素时，使用几个随机的结果进行筛选

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

bool contains(vector<int>& pair, vector<vector<int> >& pairs) {
    int size = pairs.size();
    for(int i = 0; i < size; i++) {
        if(pair[0] == pairs[i][0] && pair[1] == pairs[i][1]) {
            return true;
        }
    }
    return false;
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

//用于产生一对可交换的两行组合，进行交换，需要满足交换后的冲突数减少，同时不能是在pairs中的
//pair的结构是，前两个数字是交换的行，第三个数字是使用这个组合的的冲突数
vector<int> generateTwoRowsEnableChange(vector<vector<int> >& pairs) {
    vector<int> pair;

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

            pair.push_back(row1);
            pair.push_back(row2);
            //判断是否已经存在
            if(contains(pair, pairs)) {
                pair.clear();
                continue;
            }
            //交换; 局部搜索，判断冲突数
            swap(row1, row2);
            //如果冲突数比之前大的话，直接还原
            int newCount = countOfConflict();
            swap(row1, row2);
            if(originalCount <= newCount) {
                pair.clear();
            } else {
                pair.push_back(newCount);
                break;
            }
        }
        if(pair.size() != 0) {
            break;
        }
    }
    return pair;
}

//产生n对可交换的两行组合
//这里可能没有办法产生n对组合，要判断下
void generateTwoRowsEnableChangePairs(vector<vector<int> >& pairs) {
    vector<int> pair;
    for(int i = 0; i < RANDOM_ROWS; i++) {
        pair = generateTwoRowsEnableChange(pairs);
        if(pair.size() == 0) {
            break;
        } else {
            if(pair[2] == 0) { //冲突数为0的情况 
                pairs.clear();
                pairs.push_back(pair);
            } else {
                pairs.push_back(pair);
            }
        }
    }
}

int selectRandomFromPairs(vector<vector<int> >& pairs) {
    int total = 0;
    int size = pairs.size();
    for(int i = 0; i < size; i++) {
        total += pairs[i][2];
    }
    //产生一个从[1,total]的数字
    int result = -1;
    // cout << "look" << total << endl;
    int random = (rand() % total) + 1;
    for(int i = 0; i < size; i++) {
        random -= pairs[i][2];
        if(random <= 0) {
            result = i;
            break;
        }
    }
    return result;
}

bool changeTwoQueen_o() {
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

bool changeTwoQueen() {
    vector<vector<int> > pairs;
    vector<int> pair = generateTwoRowsEnableChange(pairs);
    // cout << pair.size() << endl;
    // cout << "pairs:" << pair[0] << " " << pair[1] << " " << pair[2] << endl;
    if(pair.size() == 0) {
        return false;
    } else {
        swap(pair[0], pair[1]);
        return true;
    }
}

//随机的策略是，在选择下一步的时候，同时获取多个可能邻居，计算各自的概率值，随机从这些邻居中选择一个，生成一个随机数，看看这个随机数落在哪个邻居的范围内，比如p1是20,p2是30,则[1,20]是p1，[21,50]是p2，随机数的范围是[1,50]
//如果那些邻居里面产生了一个冲突数为0的结果，直接使用这个，并结束
bool changeTwoQueenWithRandom() {
    vector<vector<int> > pairs;
    generateTwoRowsEnableChangePairs(pairs);
    if(pairs.size() == 0) {
        return false;
    }
    int random;
    //冲突数为0
    if(pairs.size() == 1 && pairs[0][2] == 0) {
        random = 0;
    } else {
        random = selectRandomFromPairs(pairs);
    }
    cout << "random " << pairs.size() << " " << random << endl;
    swap(pairs[random][0], pairs[random][1]);
    return true;
}


//局部搜索算法
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
            //冲突数为0,成功找到
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

//加入随机因素的局部搜索算法

void queenSolutionAddRandomFactor() {
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
            //冲突数为0,成功找到
            if(0 == countOfConflict()) {
                flag = true;
                break; 
            }

            if(!changeTwoQueenWithRandom()) {
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
    // queenSolution();

    queenSolutionAddRandomFactor();
    cout << "结果" << endl;
    print(queens);

}