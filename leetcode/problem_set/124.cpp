#include <iostream>

#define INT_MIN 0x80000000

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

// 返回从当前结点往下走的路径最大值（一条路）
int _maxPathSum(TreeNode* root, int& rsl) {
  if(root == NULL) {
    return 0;
  }
  int l = _maxPathSum(root->left, rsl);
  int r = _maxPathSum(root->right, rsl);
  l = l < 0 ? 0 : l;
  r = r < 0 ? 0 : r;
  //更新
  if(l+r+root->val > rsl) {
    rsl = l + r + root->val;
  }

  return root->val += max(l, r); //选择左树或是选择右树走
}

int maxPathSum(TreeNode* root) {
  int rsl = INT_MIN;
  _maxPathSum(root, rsl);
  return rsl;
}

int main() {
  TreeNode *head = new TreeNode(1);
  TreeNode *left = new TreeNode(2);
  TreeNode *right = new TreeNode(3);
  head->left = left;
  head->right = right;
  cout << maxPathSum(head) << endl;
}
