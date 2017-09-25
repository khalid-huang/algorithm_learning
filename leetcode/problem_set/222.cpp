#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

//超时，要用高度来计算
int countNodes_1(TreeNode* root) {
  if(root == NULL) {
    return 0;
  }
  queue<TreeNode*> q;
  q.push(root);
  TreeNode* temp;
  int count = 0;
  while(!q.empty()) {
    temp = q.front();
    q.pop();
    ++count;
    if(temp->left) {
      q.push(temp->left);
    }
    if(temp->right) {
      q.push(temp->right);
    }
  }
  return count;
}

int countNodes(TreeNode* root) {
  if(root == NULL) {
    return 0;
  }
  TreeNode* left = root, *right = root;
  int hl = 0, hr = 0; //左右树的高度
  while(left) {
    ++hl;
    left = left->left;
  }
  while(right) {
    ++hr;
    right = right->right;
  }
  // cout << hl << endl;
  if(hr == hl) {
    return pow(2, hl) - 1;
  } else {
    return 1 + countNodes(root->left) + countNodes(root->right);
  }
}

int main() {
  TreeNode* root = new TreeNode(1);
  TreeNode* left = new TreeNode(1);
  TreeNode* right = new TreeNode(1);
  TreeNode* ll = new TreeNode(1);
  root->left = left;
  root->right = right;
  left->left = ll;

  cout << countNodes(root) << endl;
}
