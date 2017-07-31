#include <iostream>
#include <queue>
using namespace std;

struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x): val(x), left(NULL), right(NULL), next(NULL) {}
};

void print(TreeLinkNode* root) {
  if(root == NULL) {
    return;
  }
  cout << root->val;
  print(root->left);
  print(root->right);
}

//其实就是一个水平方向的遍历，使用队列来实现广度优先搜索
void connect(TreeLinkNode* root) {
  if(root == NULL) {
    return;
  }
  queue<TreeLinkNode*> q;
  q.push(root);
  int size;
  TreeLinkNode* tempNode;
  while(!q.empty()) {
    size = q.size();
    for(int i = 0; i < size; i++) {
      tempNode = q.front();
      q.pop();
      tempNode->next = (i == size - 1) ? NULL : q.front();
      if(tempNode->left) {
        q.push(tempNode->left);
      }
      if(tempNode->right) {
        q.push(tempNode->right);
      }
    }
  }
  return;
}


int main() {
  TreeLinkNode* root = new TreeLinkNode(1);
  TreeLinkNode* rootLeft = new TreeLinkNode(2);
  // TreeLinkNode* rootright = new TreeLinkNode(5);
  // TreeLinkNode* ll = new TreeLinkNode(3);
  // TreeLinkNode* lr = new TreeLinkNode(4);
  // // TreeLinkNode* rl = new TreeLinkNode(15);
  // TreeLinkNode* rr = new TreeLinkNode(6);

  root->left = rootLeft;


  connect(root);
  // print(root)
}
