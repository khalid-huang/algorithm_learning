//关键在于查找中间结点的算法

#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x): val(x), next(NULL) {}
};

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
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

//左闭右开
TreeNode* _sortedArrayToBST(ListNode* head, ListNode* tail) {
  if(head == tail) {
    return NULL;
  }
  if(head->next == tail) {
    return new TreeNode(head->val);
  }
  //查找中间结点,左闭右开
  ListNode* mid = head, *temp = head;
  while(temp != tail && temp->next != tail){
    mid = mid->next;
    temp = temp->next->next;
  }
  TreeNode* root = new TreeNode(mid->val);
  root->left = _sortedArrayToBST(head, mid);
  root->right= _sortedArrayToBST(mid->next, tail);
  return root;
}

TreeNode* sortedListToBST(ListNode* head) {
  return _sortedArrayToBST(head, NULL);
}

int main() {
  ListNode* head = new ListNode(1);
  ListNode* n1 = new ListNode(2);
  ListNode* n2 = new ListNode(3);
  ListNode* n3 = new ListNode(4);
  ListNode* n4 = new ListNode(5);
  // ListNode* n5 = new ListNode(2);
  head->next = n1;
  n1->next = n2;
  n2->next= n3;
  n3->next = n4;
  // n4->next = n5;
  print(sortedListToBST(head));
}
