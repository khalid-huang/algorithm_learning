#include <iostream>
#include <vector>

using namespace std;

int newIndex(int index, int n) {
    return (1 + 2*index) % (n | 1);
}

void wiggleSort(vector<int>&) {
    int median = findKthLargest(nums, (nums.size() + 1) / 2);
    int n = nums.size();

    int left = 0, i = 0, right = n - 1;

    while (i <= right) {

        if (nums[newIndex(i,n)] > median) {
            swap(nums, newIndex(left++,n), newIndex(i++,n));
        }
        else if (nums[newIndex(i,n)] < median) {
            swap(nums, newIndex(right--,n), newIndex(i,n));
        }
        else {
            i++;
        }
    }
}

void print(vector<int> nums) {
    int size = nums.size();
    for(int i = 0; i < size; i++) {
        cout << nums[i] < " ";
    }
    cout << endl;
}

int main() {
    int nums[] = {6,13, 5,4,5,2};
    vector<int> nums;
    nums.push_back(6);
    nums.push_back(13);
    nums.push_back(5);
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(2);
    wiggleSort(nums);
    print(nums);
}

