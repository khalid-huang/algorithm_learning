#include<iostream>
#include<vector>

#define INT_MAX　0x7fffffff


using namespace std;


//超时
bool iscreasingTriple(vector<int>& nums) {
    int size = nums.size(), tmp;
    vector<int> flag = vector<int>(size,0);
    bool rsl = false;
    for(int i = 0; i < size; i++) {
        tmp = 0;
        for(int j = 0; j < i; j++) {
            if(nums[i] > nums[j]) {
                tmp = max(tmp, flag[j]);
            }
        }
        flag[i] = tmp + 1;
        if(flag[i] >= 3) {
            rsl = true;
            break;
        }
    }
    return rsl;
}

//很好的解法，因为只要判断是否存在就可以了，所以呢，就去查找最可能的一组就可以了
//下面的算法可以用于判断存在性，但不可以用于查找

bool iscreasingTriple(vector<int>& nums) {
    int c1 = INT_MAX, c2 = INT_MAX;
    int size = nums.size();
    for(int i = 0; i < size; i++) {
        if(nums[i] <= c1) {
            c1 = nums[i]; //获取最小整数
        } else if( x <= c2) {
            c2 = x;
        } else {
            return true;
        }
    }
    return false;
}


int main() {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(5);
    nums.push_back(2);
    nums.push_back(4);

    cout << iscreasingTriple(nums) << endl;

}