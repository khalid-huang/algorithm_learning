void binarySearch(std::vector<int>& nums, int first, int last, int& rsl) {
// cout << first << "-" << last << endl;
if(first == last) {
rsl = nums[first];
return;
}
int mid = first + (last - first) / 2;
// cout << "#" << nums[mid] << "-" << nums[last] << endl;
if(nums[mid] < nums[last]) { //从mid到last有序
binarySearch(nums, first, mid, rsl);
} else if(nums[mid] > nums[last]) {
binarySearch(nums, mid+1, last, rsl);
} else {
binarySearch(nums, first, --last, rsl);
}

}

int findMin(vector<int>& nums) {
int first = 0, last = nums.size() - 1;
int rsl;
binarySearch(nums, 0, last, rsl);
return rsl;
}
