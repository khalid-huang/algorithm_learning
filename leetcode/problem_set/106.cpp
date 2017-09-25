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

TreeNode* _buildTree(std::vector<int>& inorder, int in_start, int in_end, std::vector<int>& postorder, int post_start, int post_end) {
  if(post_start == post_end && in_start == in_end) {
    return new TreeNode(postorder[post_end]);
  }
  if(post_start > post_end || in_start > in_end) {
    return NULL;
  }

  TreeNode* root = new TreeNode(postorder[post_end]);
  int index = find(inorder, in_start, in_end, postorder[post_end]);
  cout << in_start << " " << in_end << " " << postorder[post_end] << endl;
  cout << index << endl;
  int diff = index - in_start; //这个差距是起点到root的距离，比左树的长度大1
  root->left = _buildTree(inorder, in_start, index - 1, postorder, post_start, post_start + diff - 1);
  root->right = _buildTree(inorder, index+1, in_end, postorder, post_start+diff, post_end - 1);
  return root;
}

TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder) {
  int post_size = postorder.size(), in_size = inorder.size();
  return _buildTree(inorder, 0, in_size - 1, postorder, 0, post_size - 1);

}

int main() {
  std::vector<int> preoder;
  std::vector<int> inorder;
  std::vector<int> postorder;

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

  postorder.push_back(4);
  postorder.push_back(5);
  postorder.push_back(7);
  postorder.push_back(8);
  postorder.push_back(6);
  postorder.push_back(3);
  print(buildTree(inorder, postorder));
  cout << endl;
}
