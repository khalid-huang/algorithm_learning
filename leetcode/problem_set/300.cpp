#include <iostream>
#include <vector>

using namespace std;

void print(vector<int>& nums) {
    int size = nums.size();
    for(int i = 0; i < size; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}

int lengthOfLIS(vector<int>& nums)  {
    int size = nums.size();
    vector<int> count(size, 1);
    int maxCount = 0;
    for(int i = 1; i < size; i++) {
        int maxVal = -1;
        for(int j = i-1; j >= 0; j--) {
            if(nums[i] > nums[j] && maxVal < count[j]) {
                maxVal = count[j];
            }
        }
        if(maxVal != -1) {
            count[i] = maxVal + 1;
            maxCount = max(maxCount, count[i]);
        }
    }
    // print(count);
    return maxCount;
}

int main() {
    vector<int> nums;
    nums.push_back(10);
    nums.push_back(9);
    nums.push_back(2);
    nums.push_back(5);
    nums.push_back(3);
    nums.push_back(7);
    nums.push_back(101);
    nums.push_back(18);
    cout << lengthOfLIS(nums) << endl;
}