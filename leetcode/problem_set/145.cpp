//树的遍历，非递归版

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

void print(std::vector<int> rsl) {
  int size = rsl.size();
  for(int i = 0;i < size; i++) {
    cout << rsl[i] << " ";
  }
  cout << endl;
}

// void _postorderTraversal(TreeNode* root, std::vector<int>& rsl) {
//   if(root == NULL) {
//     return;
//   }
//   _postorderTraversal(root->left, rsl);
//   _postorderTraversal(root->right, rsl);
//   rsl.push_back(root->val);
// }
//
// std::vector<int> postorderTraversal(TreeNode* root) {
//   std::vector<int> rsl;
//   _postorderTraversal(root, rsl);
//   return rsl;
// }

std::vector<int> inorderTravsersal(TreeNode* root) {
  std::vector<int> rsl;
  stack<TreeNode*> s;
  TreeNode* p;

  while(!s.empty() || p != NULL) {
    if(p != NULL) {
      s.push(p);
      p = p->left;
    } else {
      p = s.top();
      s.pop();
      rsl.push_back(p->val);
      p = p->right;
    }
  }
  return rsl;
}

//先序遍历的改版
std::vector<int> postorderTraversal(TreeNode* root) {
  std::vector<int> rsl;

  stack<TreeNode*> s;
  TreeNode *tempNode, *p = root;
  while(!s.empty() || p != NULL) {
    if(p != NULL) {
      s.push(p);
      rsl.insert(rsl.begin(), p->val);
      p = p->right;
    } else {
      p = s.top();
      s.pop();
      p = p->left;
    }
  }
  return rsl;
}


int main() {
  TreeNode *root = new TreeNode(1);
  TreeNode *left = new TreeNode(2);
  TreeNode *right = new TreeNode(3);
  root->right = right;
  root->left = left;

  print(postorderTraversal(root)); //2,3,1
}
