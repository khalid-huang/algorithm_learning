#include <iostream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

int _sumNumbers(TreeNode* root, int cur) {
  if(root == NULL) {
    return cur;
  }
  if(root->right == NULL) {
    return _sumNumbers(root->left, cur*10 + root->val);
  } else if(root->left == NULL) {
    return _sumNumbers(root->right, cur*10 + root->val);
  } else {
    return _sumNumbers(root->left, cur*10 + root->val) +
      _sumNumbers(root->right, cur * 10 + root->val);
  }
}

int sumNumbers(TreeNode* root) {
  return _sumNumbers(root, 0);
}

int main() {
  TreeNode* root = new TreeNode(1);
  TreeNode* left = new TreeNode(2);
  TreeNode* right = new TreeNode(3);


  root->left=  left;
  root->right = right;
  cout << sumNumbers(root) << endl;
  return 0;
}
