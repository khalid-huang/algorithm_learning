#include <iostream>
#include <vector>

using namespace std;

//pre的第一个数字确定根结点，使用in确定左子树和右子树

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

void print(TreeNode* root) {
  if(root == NULL) {
    return;
  }
  cout << root->val;
  print(root->left);
  print(root->right);
}

int find(std::vector<int>& vec, int start, int end, int target) {
  // cout << start << " " << end << " " << target << endl;
  for(int i = start; i <= end; i++) {
    if(target == vec[i]) {
      return  i;
    }
  }
  return -1;
}

TreeNode* _buildTree(std::vector<int>& preorder, int pre_start, int pre_end, std::vector<int>& inorder, int in_start, int in_end) {
  cout << pre_start << " " << pre_end << "#" << in_start << " " << in_end << endl;
  //只剩下一个结点就直接返回
  if(pre_start == pre_end && in_start == in_end) {
    return new TreeNode(preorder[pre_start]);
  }

  //这种是用于处理没有符合规律的左子树或是右子树时，返回NULL的。
  if(pre_end < pre_start || in_end < in_start) {
    return NULL;
  }

  TreeNode* root = new TreeNode(preorder[pre_start]);
  int index = find(inorder, in_start, in_end, preorder[pre_start]);
  cout << "index: " << index << endl;
  int diff = index - in_start;
  root->left = _buildTree(preorder, pre_start+1, pre_start+diff, inorder, in_start, index - 1);
  root->right = _buildTree(preorder, pre_start+diff+1, pre_end, inorder, index+1, in_end);

  return root;
}

TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
  int pre_size = preorder.size(), in_size = inorder.size();
  return _buildTree(preorder, 0, pre_size - 1, inorder, 0, in_size - 1);

}

int main() {
  std::vector<int> preoder;
  std::vector<int> inorder;

  preoder.push_back(3);
  preoder.push_back(5);
  preoder.push_back(4);
  preoder.push_back(6);
  preoder.push_back(7);
  preoder.push_back(8);

  inorder.push_back(4);
  inorder.push_back(5);
  inorder.push_back(3);
  inorder.push_back(7);
  inorder.push_back(6);
  inorder.push_back(8);

  print(buildTree(preoder, inorder));
  cout << endl;
}
