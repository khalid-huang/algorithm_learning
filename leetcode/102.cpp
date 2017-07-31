//广度优先搜索，主要是使用计数，通过本层的结点数来计算下层有几个结点，
//也可以使用先序遍历
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

std::vector<std::vector<int> > levelOrder(TreeNode* root) {
  std::vector<std::vector<int> > rsl;
  if(root == NULL) {
    return rsl;
  }
  queue<TreeNode*> q;
  TreeNode* tempNode;

  q.push(root);
  int curCount = 1, nextCount = 0;
  while(!q.empty()) {
    std::vector<int> tempList;
    while(curCount--) {
      tempNode = q.front();
      q.pop();
      tempList.push_back(tempNode->val);
      if(tempNode->left) {
        nextCount++;
        q.push(tempNode->left);
      }
      if(tempNode->right) {
        nextCount++;
        q.push(tempNode->right);
      }
    }
    rsl.push_back(tempList);
    curCount = nextCount;
    nextCount = 0;
  }
  return rsl;
}


//使用先序遍历的方式
void _levelOrder1(std::vector<std::vector<int> >& rsl, TreeNode* root, int depth) {
  if(root == NULL) {
    return;
  }
  if(rsl.size() == depth) {
    rsl.push_back(std::vector<int>());
  }

  rsl[depth].push_back(root->val);
  _levelOrder1(rsl, root->left, depth+1);
  _levelOrder1(rsl, root->right, depth+1);
}

std::vector<std::vector<int> > levelOrder1(TreeNode* root) {
  std::vector<std::vector<int> > rsl;
  int depth = 0;
  _levelOrder1(rsl, root, depth);
  return rsl;
}
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

  print(levelOrder1(root));
}
