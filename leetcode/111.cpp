#include <iostream>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

//不能按下面的做法，因为如果是1,2,null, 4的话，答案是3而不是1; 不能用NULL来判断修改rsl
// void _depth(TreeNode* root, int& rsl, int depth) {
//   if(root == NULL) {
//     if(rsl == -1) {
//       rsl = depth;
//     } else {
//       rsl = rsl > depth ? depth : rsl;
//     }
//     return;
//   }
//   _depth(root->left, rsl, depth+1);
//   _depth(root->right, rsl, depth+1);
// }
//
// int minDepth(TreeNode* root) {
//   if(root == NULL) {
//     return 0;
//   }
//   int rsl = -1, depth = 0;
//   _depth(root, rsl, depth);
//   return rsl;
// }

//好好分析应该是在当前结点，如果左树为空，我们就算右树高度；如果右树为空我们就算左树，如果都不为空，我们就返回较小值
int minDepth(TreeNode* root) {
  if(root == NULL) {
    return 0;
  }
  if(root->left == NULL) {
    return 1 + minDepth(root->right);
  }
  if(root->right == NULL) {
    return 1 + minDepth(root->left);
  }
  return 1 + min(minDepth(root->left), minDepth(root->right));
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

  cout << minDepth(root) << endl;
}
