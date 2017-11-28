// 有相同数字和数字的大小，可以抽象是一个图，带有环的
#include <iostream>
#include <vector>

using namespace std;

// 抽象成环的作法
int findDuplicateUseGraph(vector<int>& nums) {
    if(nums.size() > 1) {
        // cout << nums.size() << endl;
        // int slow = 0;
        // int fast = 0;
        //其实一开始应该是使用slow = flow = 0的，因为这样才可以防止发生重复点在开头的情况，因为这种情况下，我们需要让
        //完成第一次while之后的，fast=开头的，如果一开始就是相等了就不好弄的。当然也可以弄一个if循环
        //使用slow=fast=0一开始又无法进入循环，所以就索性自动过一次，让slow = nums[0], fast = nums[nums[0]]
        //其实这样是包含了开头元素为0的做法
        int slow = nums[0];
        int fast = nums[nums[0]];
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        cout << fast << endl;
        fast = 0;
        // int pre;
        while(slow != fast) {
            // pre = slow;
            slow = nums[slow];
            fast = nums[fast];
            // cout << slow << " " << fast << endl;
        }
        // cout << pre << endl;
        // return pre;
        return fast;
    }
    return -1;
}

void _findDuplicateUseQuickSort(vector<int>& nums, int start, int end, int& dupVal) {
    if(start > end || dupVal != -1) {
        return;
    }
    int keyVal = nums[start];
    int _start = start, _end = end;
    while(_start < _end) {
        while(_start < _end && nums[_end] >= keyVal) {
            if(nums[_end] == keyVal) {
                dupVal = keyVal;
                return;
            }
            --_end;
        }
        nums[_start] = nums[_end];

        while(_start < _end && nums[_start] < keyVal) {
            ++_start;
        }
        nums[_end] = nums[_start];
    }
    nums[_start] = keyVal;
    _findDuplicateUseQuickSort(nums, start, _start - 1, dupVal);
    _findDuplicateUseQuickSort(nums, _start + 1, end, dupVal);

}

//使用快排的变种来解决
int findDuplicateUseQuickSort(vector<int>& nums) {
    int dupVal = -1;
    _findDuplicateUseQuickSort(nums,0,nums.size() - 1, dupVal);
    return dupVal;
}

int main() {
    vector<int> nums;
    nums.push_back(4);
    nums.push_back(1);
    nums.push_back(5);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);

    // cout << findDuplicateUseGraph(nums) << endl;
    cout << findDuplicateUseQuickSort(nums) << endl;
}
