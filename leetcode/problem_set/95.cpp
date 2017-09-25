#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

void _print(TreeNode* t) {
  if(t != NULL) {
    cout << t->val << " ";
    _print(t->left);
    _print(t->right);
  } else {
    cout << "null ";
  }
}

void print(vector<TreeNode*> rsl) {
  int size = rsl.size();
  cout << size << endl;
  for(int i = 0; i < size; i++) {
    _print(rsl[i]);
  }
  cout << endl;
}

std::vector<TreeNode*> _generateTrees(int low, int up) {
  std::vector<TreeNode*> rootTree;
  if(low > up) {
    rootTree.push_back(NULL);
    return rootTree;
  }

  for(int i = low; i <= up; i++) {
    std::vector<TreeNode*> left = _generateTrees(low, i-1);
    std::vector<TreeNode*> right = _generateTrees(i+1, up);

    int size_left = left.size();
    int size_right = right.size();
    for(int j = 0; j < size_left; j++) {
      for(int k = 0; k < size_right; k++) {
        TreeNode *root = new TreeNode(i);
        root->left = left[j];
        root->right = right[k];
        // _print(root);
        rootTree.push_back(root);
      }
    }
  }
  return rootTree;
}

std::vector<TreeNode*> generateTrees(int n) {
  return _generateTrees(1, n);
}

int main() {
  int n;
  cin >> n;
  print(generateTrees(n));
}
