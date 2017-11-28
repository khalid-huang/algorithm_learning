#include <iostream>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

//利用递归回溯，如果找到了p或是q就返回，如果没有，判断它的子树是否有，如果两个子树上各有一个，就返回该点，否则，只可能是子树中的一个了。
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  if(!root || root == p || root == q) {
    return root;
  }
  TreeNode *left = lowestCommonAncestor(root->left, p, q);
  TreeNode *right = lowestCommonAncestor(root->right, p, q);
  return !left ? right : !right ? left : root;
}
int main() {
  return 0;
}
