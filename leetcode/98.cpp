#include <iostream>

// #define INT_MAX 0x7fffffff
// #define INT_MIN 0x80000000

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x): val(x), left(NULL), right(NULL) {}
};
//单点比较; 要注意下要使用Long的最大值，最小值，因为范围的关系
bool _isValidBST(TreeNode* root, long min , long max) {
  if(root == NULL) {
    return true;
  }
  if(root->val >= max || root->val <= min) {
    return false;
  }
  return _isValidBST(root->left, min, root->val) &&
    _isValidBST(root->right, root->val, max);
}


bool isValidBST(TreeNode* root) {
  long INT_MAX = 2147483648;
  long INT_MIN = -2147483649;
  return _isValidBST(root, INT_MIN, INT_MAX);
}

int main() {
  TreeNode* root = new TreeNode(2);
  TreeNode* left = new TreeNode(1);
  TreeNode* right = new TreeNode(3);

  root->left = left;
  root->right = right;

  cout << isValidBST(root) << endl;
}
