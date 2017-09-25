#include <iostream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

TreeNode* prev = NULL;

void print(TreeNode* root) {
  if(root == NULL) {
    return;
  }
  cout << root->val;
  print(root->left);
  print(root->right);
}

//如果你传递进去的是一个地址，那么你修改这个地址的东西会直接反映到对象；
//但如果你希望的是可以改变这个地址的值，而不是地址的对象，那么你要传的是地址的引用
//值传递（修改值不会修改外部引用源值），地址传递（修改地址指向的对象的内容会反映到外部引用源上的内容，但修改地址值不会反映到外部的地址），地址引用传递（可以修改地址的值，反到外部地址引用 上）；
void _flatten(TreeNode* root, TreeNode*& pre) {
  if(pre) {
    cout << pre->val << endl;
  }
  if(root == NULL) {
    return;
  }
  _flatten(root->right, pre);
  _flatten(root->left, pre);
  root->right = pre;
  root->left = NULL;
  pre = root;
}

//post order to get the num list
//一个一个往上接，直下而止
void flatten(TreeNode* root) {
  TreeNode* pre = NULL;
  _flatten(root, pre);
  // return root;
}

int main() {

  TreeNode* root = new TreeNode(1);
  TreeNode* rootLeft = new TreeNode(2);
  TreeNode* rootright = new TreeNode(5);
  TreeNode* ll = new TreeNode(3);
  TreeNode* lr = new TreeNode(4);
  // TreeNode* rl = new TreeNode(15);
  TreeNode* rr = new TreeNode(6);

  root->left = rootLeft;
  root->right = rootright;
  rootLeft->left = ll;
  rootLeft->right = lr;
  // rootright->left = rl;
  rootright->right = rr;
  print(root);
  cout << endl;
  flatten(root);
  print(root);
  cout << endl;
}
