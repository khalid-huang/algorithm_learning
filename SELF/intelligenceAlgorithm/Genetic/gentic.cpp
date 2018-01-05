#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>

using namespace std;

int numOfGroup; //种群数目
int numOfQueen; //皇后数目
vector<int> optimalSolution; //最优解
vector<vector<int> > population; //种群
vector<double> adaptive; //种群的适应值
vector<double> adaptValue; //适应值累加值，用于模拟每个种群轮盘赌的区间
bool isSuccess; //是否迭代结束 

int abs(int value) {
    return value > 0? value : -value;
}

void print() {
    for(int i = 0; i < numOfQueen; i++) {
        for(int j = 0; j < numOfQueen; j++) {
            if(j == optimalSolution[i]) {
                cout << "Q ";
            } else {
                cout << ". ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

void printAdaptive() {
    for(int i = 0; i < adaptive.size(); i++) {
        cout << adaptive[i] << " ";
    }
    cout << endl;
}                                                

void printPopulation() {
    cout << "population" << endl;
    for(int i = 0; i < population.size(); i++) {
        for(int j = 0; j < population[0].size(); j++) {
            cout << population[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

//用冲突数的倒数来做适应值
double calcuAdative(vector<int>& queen) {
    int conflict = 0;
    for(int i = 0; i < numOfQueen; i++) {
        for(int j = i + 1; j < numOfQueen; j++) {
            if(abs(queen[j] - queen[i]) == abs(j - i) || queen[j] == queen[i]) {
                ++conflict;
            }
        }
    }
    //找到最优解
    if(conflict == 0) {
        isSuccess = true;
        optimalSolution = queen;
        return 1.1;
    } else {
        return 1.0 / conflict;
    }
}

//初始化函数
void init() {
    // numOfGroup = 120;
    numOfGroup = 4;
    adaptive.clear();
    adaptive.resize(numOfGroup, 0);
    adaptValue.clear();
    adaptValue.resize(numOfGroup, 0);
    
    optimalSolution = vector<int>(numOfQueen, 0);

    isSuccess = false;
    //population;
    population.clear();
    vector<int> tmp(numOfQueen, 0);
    for(int i = 0; i < numOfGroup; i++) {
        for(int j = 0; j < numOfQueen; j++) {
            tmp[j] = rand() % numOfQueen; //产生从0到numOfQueen的随机数
        }
        population.push_back(tmp);
        adaptive[i] = calcuAdative(tmp); //计算适应值
    }

}

//自然选择
void choose() {
    vector<vector<int> > newPopulation; //新的种群空间
    //计算总的适应值之和，以及每个个体所占轮盘的区间
    adaptValue[0] = adaptive[0];
    for(int i = 1; i < adaptValue.size(); i++) {
        adaptValue[i] = adaptValue[i-1] + adaptive[i];
    }
    double totalAdaptive = adaptValue[adaptValue.size()-1];
    //选择新的种群
    for(int i = 0; i < numOfGroup; i++) {
        //按比例缩放的轮盘赌，因为适应值太小
        int magnifyTotalAdative = totalAdaptive * 100000;
        int random = (rand() * rand()) % magnifyTotalAdative;
        double select = (double) random / 100000;

        vector<double>::iterator index_adaptValue;
        index_adaptValue = lower_bound(adaptValue.begin(), adaptValue.end(), select); //返回第一个比select大的坐标
        int index_population = index_adaptValue - adaptValue.begin();
        newPopulation.push_back(population[index_population]);
    }
    population.clear();
    population = newPopulation;
}

//交配；也就是交换皇后位置
//随机选择两个状态，随机产生一个交叉点，然后对这个交叉点的左（右）进行交叉
void genticCrossover() {
    int first = 0, row1, tmpVal;
    int groupSize = population.size();
    for(int i = 0; i < groupSize; i++) {
        //随机产生两次
        if(rand() % 2) { 
            //用first来产生两个选择
            ++first;
            if(first % 2 == 0) {
                int crossPoint = rand() % (numOfQueen - 1);
                int queenSize = population[i].size();
                for(int j = crossPoint; j < queenSize; j++) {
                    //交换
                    tmpVal = population[row1][j];
                    population[row1][j] = population[i][j];
                    population[i][j] = tmpVal;
                }
            } else {
                row1 = i;
            }
        }
    }
}

//变异; 如果产生了5的倍数
void genticMutate() {
    int mutateSpot = 0;
    int groupSize = population.size();
    for(int i = 0; i < groupSize; i++) {
        if(rand() % 5 == 0) {
            mutateSpot = rand() % numOfQueen;
            population[i][mutateSpot] = rand() % numOfQueen;
        }
    }
}

void updateAdative() {
    int groupSize = population.size();
    for(int i = 0; i < groupSize; i++) {
        adaptive[i] = calcuAdative(population[i]);
    }
}

//进行遗传算法的迭代
void genticCalculation() {
    clock_t start, finish;
    srand((unsigned)time(NULL));

    init();
    start = clock();
    while(!isSuccess) {
        //自然选择
        choose();

        //交配
        genticCrossover();

         //变异
        genticMutate();

        //更新适应值
        updateAdative();
    }
    
    print(); //根据结果进行结果打印    

    finish = clock();
    double t = (double)(finish - start) / CLOCKS_PER_SEC;
    cout << "遗传算法求解时间" << t << "s" << endl;
}

int main() {
    cout << "输入皇后数目" << endl;
    cin >> numOfQueen;
    genticCalculation(); //进行遗传算法迭代
}