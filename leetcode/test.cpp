#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> nums) {
    int size = nums.size();
    for(int i = 0; i < size; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}

int newIndex(int index, int n) {
    return (1 + 2*index) % (n | 1);
}

void swap(vector<int>& nums, int i, int j) {
    if(nums[j] == nums[i]) return;
    nums[i] = nums[i] ^ nums[j];
    nums[j] = nums[i] ^ nums[j];
    nums[i] = nums[i] ^ nums[j];
}

int _quickSort(std::vector<int>& nums, int down, int up, int target) {
    
      int _down = down, _up = up;
      int val = nums[down];
      while(down < up) {
        while(down < up && val <= nums[up]) {
          --up;
        }
        nums[down] = nums[up];
    
        while(down < up && val > nums[down]) {
          ++down;
        }
        nums[up] = nums[down];
      }
    
      nums[down] = val;
    
      if(down == target) {
        return val;
      } else if(target > down) {
        return _quickSort(nums, down + 1, _up, target);
      } else {
        return _quickSort(nums, _down, down - 1, target);
      }
    }
    
    int findKthLargest(std::vector<int>& nums, int k) {
      int down = 0, up = nums.size(), target = nums.size() - k;
      return _quickSort(nums, down, up - 1, target);
    }
    

void wiggleSort(vector<int>& nums) {
    vector<int> nums_copy(nums.begin(), nums.end());
    int median = findKthLargest(nums_copy, (nums.size() + 1) / 2);
    cout << "median " << median << endl;
    int n = nums.size();

    int left = 0, i = 0, right = n - 1;
    print(nums);
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
        print(nums);
    }
}



int main() {
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

