#include <iostream>

using namespace std;

//都是一样的模式，关于路径的问题上，不能单纯使用NULL为结束，就进行来结束判断；要使用左子树为空就使用右子树，右子树为空就使用左子树，否则就两者合并处理；主要是因为根结点的子树没有叶子之称，它没有子树的话，就是不存在，也就是不存在一个1->NULL的路径（当然这是存在另一个子树的情况下）
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool _hasPathSum(TreeNode* root, int sum, int cur) {
  cout << sum << " " << cur << endl;
  if(root == NULL && sum == cur) {
    return true;
  }
  if(root == NULL && sum != cur) {
    return false;
  }
  if(root->left == NULL) {
    return _hasPathSum(root->right, sum, cur + root->val);
  }
  if(root->right == NULL) {
    return _hasPathSum(root->left, sum, cur + root->val);
  }
  return _hasPathSum(root->left, sum, cur + root->val) ||
    _hasPathSum(root->right, sum, cur + root->val);
}

bool hasPathSum(TreeNode* root, int sum) {
  if(root == NULL) {
    return false;
  }
  int cur = 0;
  return _hasPathSum(root, sum ,cur);
}

int main() {
  TreeNode* root = new TreeNode(-2);
  TreeNode* rootLeft = new TreeNode(-3);
  // TreeNode* rootright = new TreeNode(20);
  // // TreeNode* ll = new TreeNode(3);
  // // TreeNode* lr = new TreeNode(4);
  // TreeNode* rl = new TreeNode(15);
  // TreeNode* rr = new TreeNode(7);
  // TreeNode* rrr = new TreeNode(8);

  root->left = rootLeft;
  // root->right = rootright;
  // // rootLeft->left = ll;
  // // rootLeft->right = lr;
  // rootright->left = rl;
  // rootright->right = rr;
  // rr->right = rrr;

  int target;
  cin >> target;
  cout << hasPathSum(root, target) << endl;
}
