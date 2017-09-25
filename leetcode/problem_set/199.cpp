#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x): val(x), left(NULL), right(NULL) {}
};


//按行遍历的变体
std::vector<int> rightSideView(TreeNode* root) {
  std::vector<int> rsl;
  if(root == NULL) {
    return rsl;
  }
  int count;
  TreeNode* tempN;
  queue<TreeNode*> q;
  q.push(root);
  while(!q.empty()) {
    count = q.size();
    for(int i = 0; i < count; i++) {
      tempN = q.front();
      q.pop();
      if(i == count - 1) {
        rsl.push_back(tempN->val);
      }
      if(tempN->left) {
        q.push(tempN->left);
      }
      if(tempN->right) {
        q.push(tempN->right);
      }
    }
  }
  return rsl;
}

int main() {
}
