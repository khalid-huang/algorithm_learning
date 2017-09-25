//使用queue广度优先搜索，只是在插入数字的时候，要先把空间分配出来；不计算，直接每一层第一层处理

#include<iostream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

void print(std::vector<std::vector<int> > rsl) {
  int size_o = rsl.size(), size_i;
  for(int i = 0;i < size_o; i++) {
    size_i = rsl[i].size();
    for(int j = 0; j < size_i; j++) {
      cout << rsl[i][j] << " ";
    }
    cout << endl;
  }
}

void printT(TreeNode* root) {
  if(root == NULL) {
    return;
  }
  cout << root->val << " ";
  printT(root->left);
  printT(root->right);
}

std::vector<std::vector<int> > zigzagLevelOrder(TreeNode* root) {
  std::vector<std::vector<int> > rsl;
  if(root == NULL) {
    return rsl;
  }
  queue<TreeNode*> q;
  q.push(root);
  TreeNode* tempNode;
  bool left2right = true;
  int index;
  while(!q.empty()) {
    int size = q.size();
    std::vector<int> tempList(size);
    for(int i = 0; i < size; i++) {
      tempNode = q.front();
      q.pop();
      index = left2right == 1 ? i : size - i - 1;
      tempList[index] = tempNode->val;
      if(tempNode->left) {
        q.push(tempNode->left);
      }
      if(tempNode->right) {
        q.push(tempNode->right);
      }
    }
    rsl.push_back(tempList);
    left2right = !left2right;
  }
  return rsl;
}

int main() {
  TreeNode* root = new TreeNode(3);
  TreeNode* rootLeft = new TreeNode(9);
  TreeNode* rootright = new TreeNode(20);
  // TreeNode* ll = new TreeNode(3);
  // TreeNode* lr = new TreeNode(4);
  TreeNode* rl = new TreeNode(15);
  TreeNode* rr = new TreeNode(7);

  root->left = rootLeft;
  root->right = rootright;
  // rootLeft->left = ll;
  // rootLeft->right = lr;
  rootright->left = rl;
  rootright->right = rr;

  printT(root);
  // print(zigzagLevelOrder(root));
}
