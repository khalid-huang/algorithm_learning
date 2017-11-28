#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//O(nlogn)的
void wiggleSort(vector<int>& nums) {

    vector<int> tmp(nums.begin(), nums.end());

    int size = nums.size();
    int k = (size + 1) / 2; j = size;
    for(int i = 0; i <  size; i++) {
        nums[i] = i & 1 ? tmp[--j] : tmp[--k];
    }
}

int main() {

}