#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

void print(TreeNode* root) {
  if(root == NULL) {
    return;
  }
  cout << root->val;
  print(root->left);
  print(root->right);
}

TreeNode* _sortedArrayToBST(std::vector<int>& nums, int start, int end) {
  if(end < start) {
    return NULL;
  }
  if(start == end) {
    return new TreeNode(nums[start]);
  }
  int mid = start + ((end - start + 1) >> 1);
  TreeNode* root = new TreeNode(nums[mid]);
  root->left = _sortedArrayToBST(nums, start,mid - 1);
  root->right = _sortedArrayToBST(nums, mid+1, end);
  return root;
}

TreeNode* sortedArrayToBST(std::vector<int>& nums) {
  return _sortedArrayToBST(nums, 0 , nums.size() - 1);
}

int main() {
  std::vector<int> nums;
  nums.push_back(1);
  nums.push_back(2);
  nums.push_back(3);
  nums.push_back(4);
  nums.push_back(5);
  // nums.push_back(6);

  print(sortedArrayToBST(nums));
}
