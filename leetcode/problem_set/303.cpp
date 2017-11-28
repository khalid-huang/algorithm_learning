#include <iostream>
#include <vector>

using namespace std;

class NumArray {
private:
    vector<int> nums;
    vector<int> sums;
public:
    void print(vector<int>& nums) {
        int size = nums.size();
        for(int i = 0; i < size; i++) {
            cout << nums[i] << " ";
        }
        cout << endl;
    }


    NumArray(vector<int> nums) {
        this->nums = nums;
        int size = nums.size();
        if(size == 0) {
            return;
        }

        this->sums = vector<int>(size, 0);
        this->sums[0] = nums[0];
        for(int i = 1; i < size; i++) {
            this->sums[i] = sums[i-1] + nums[i];
        }
    }

    int sumRange(int i, int j) {
        // print(this->sums);
        return this->sums[j] - this->sums[i] + this->nums[i];
    }
};

int main() {
    vector<int> nums;
    nums.push_back(-2);
    nums.push_back(0);
    nums.push_back(3);
    nums.push_back(-5);
    nums.push_back(2);
    nums.push_back(-1);

    NumArray obj(nums);
    cout << obj.sumRange(2,5) << endl;
}