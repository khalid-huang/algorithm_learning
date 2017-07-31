#include <iostream>
using namespace std;

//思路 就是去比较应该要相等的要相等
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

bool _isSymmetrix(TreeNode* tn1, TreeNode* tn2) {
  if(tn1 == NULL && tn2 == NULL) {
    return true;
  }
  if(tn1 == NULL || tn2 == NULL) {
    return false;
  }

  return tn1->val == tn2->val && _isSymmetrix(tn1->left,tn2->right) && _isSymmetrix(tn1->right, tn2->left);

}

bool isSymmertric(TreeNode* root) {
  if(root == NULL) {
    return true;
  }
  return _isSymmetrix(root->left, root->right);
}

int main() {
  TreeNode* root = new TreeNode(1);
  TreeNode* rootLeft = new TreeNode(2);
  TreeNode* rootright = new TreeNode(2);
  TreeNode* ll = new TreeNode(3);
  TreeNode* lr = new TreeNode(4);
  TreeNode* rl = new TreeNode(3);
  TreeNode* rr = new TreeNode(3);

  root->left = rootLeft;
  root->right = rootright;
  rootLeft->left = ll;
  rootLeft->right = lr;
  rootright->left = rl;
  rootright->right = rr;
  cout << isSymmertric(root) << endl;
}
