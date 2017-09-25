#include <iostream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

int abs(int val) {
  return val > 0 ? val : -val;
}

int _isBalanced(TreeNode* root) {
  //为NULL直接返回0
  if(root == NULL) {
    return 0;
  }
  //从底向上，先判断左子树和右子树，是不是balanced
  int leftHeight = _isBalanced(root->left);
  if(leftHeight == -1) {
    return -1;
  }
  int rightHeight = _isBalanced(root->right);
  if(rightHeight == -1) {
    return -1;
  }

  //再判断自己
  if(abs(leftHeight - rightHeight) > 1) {
    return -1;
  }
  //如果是的话，直接返回高度信息
  return max(leftHeight, rightHeight) + 1;
}

bool isBalanced(TreeNode* root) {
  return _isBalanced(root) == -1 ? false : true;
}

int main() {
  TreeNode* root = new TreeNode(3);
  TreeNode* rootLeft = new TreeNode(9);
  TreeNode* rootright = new TreeNode(20);
  // TreeNode* ll = new TreeNode(3);
  // TreeNode* lr = new TreeNode(4);
  TreeNode* rl = new TreeNode(15);
  TreeNode* rr = new TreeNode(7);
  TreeNode* rrr = new TreeNode(8);

  root->left = rootLeft;
  root->right = rootright;
  // rootLeft->left = ll;
  // rootLeft->right = lr;
  rootright->left = rl;
  rootright->right = rr;
  rr->right = rrr;

  cout << isBalanced(root) << endl;
}
