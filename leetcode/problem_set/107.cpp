#include <iostream>
#include <vector>
#include <queue>

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


//用广度优先搜索，插入的时候往头插入就可以了
std::vector<std::vector<int> > levelOrderBottom(TreeNode* root) {
  std::vector<std::vector<int> > rsl;
  if(root == NULL) {
    return rsl;
  }
  queue<TreeNode*> q;
  q.push(root);
  TreeNode* tempNode;
  while(!q.empty()) {
    int size = q.size();
    std::vector<int> oneLevel;
    for(int i = 0; i < size; i++) {
      tempNode = q.front();
      q.pop();
      oneLevel.push_back(tempNode->val);
      if(tempNode->left) {
        q.push(tempNode->left);
      }
      if(tempNode->right) {
        q.push(tempNode->right);
      }
    }
    rsl.insert(rsl.begin(), oneLevel);
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

  print(levelOrderBottom(root));
}
