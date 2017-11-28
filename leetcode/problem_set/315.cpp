#include <vector>
#include <iostream>

using namespace std;

void print(vector<int> nums) {
    int size = nums.size();
    for(int i = 0; i < size; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}

//反向就可以了
vector<int> countSmaller(vector<int>& nums) {
    int size = nums.size();
    vector<int> count(size, 0);
    int tmp;
    for(int i = size - 2; i > -1; i--) {
        tmp = 0;
        for(int j = i + 1; j < size; j++) {
            // if(nums[i] >= nums[j]) {
            //     count[i] = max(count[i], count[j] + 1);
            // }
            // print(count);
            if(nums[i] > nums[j]) {
                ++tmp;
            }
        }
        count[i] = tmp;
    }
    return count;
}

int main() {
    vector<int> nums;
    nums.push_back(7);
    nums.push_back(2);
    nums.push_back(6);
    nums.push_back(1);

    print(countSmaller(nums));
}