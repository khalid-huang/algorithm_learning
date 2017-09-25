#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
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



void _pathSum(TreeNode* root, int sum, int cur, std::vector<std::vector<int> >& rsl, std::vector<int>& tempVec) {
  if(root == NULL && cur == sum) {
    rsl.push_back(tempVec);
    return;
  }
  if(root == NULL && cur != sum) {
    return;
  }
  if(root->left == NULL) {
    tempVec.push_back(root->val);
    _pathSum(root->right, sum, cur + root->val, rsl, tempVec);
    tempVec.pop_back();
    return;
  }
  if(root->right == NULL) {
    tempVec.push_back(root->val);
    _pathSum(root->left, sum, cur + root->val, rsl, tempVec);
    tempVec.pop_back();
    return;
  }
  tempVec.push_back(root->val);
  _pathSum(root->right, sum, cur + root->val, rsl, tempVec);
  tempVec.pop_back();

  tempVec.push_back(root->val);
  _pathSum(root->left, sum, cur + root->val, rsl, tempVec);
  tempVec.pop_back();
}

std::vector<std::vector<int> > pathSum(TreeNode *root, int sum) {
  std::vector<std::vector<int> > rsl;
  if(root == NULL) {
    return rsl;
  }
  std::vector<int> tempVec;
  int cur = 0;
  _pathSum(root, sum, cur, rsl, tempVec);
  return rsl;
}

int main() {
  TreeNode* root = new TreeNode(5);
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

  int target;
  cin >> target;
  print(pathSum(root, target));
}
