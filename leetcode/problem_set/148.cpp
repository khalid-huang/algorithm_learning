#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x): val(x), next(NULL) {}
};

void print(ListNode* head) {
  ListNode* cur = head;
  while(cur) {
    cout << cur->val << " ";
    cur = cur->next;
  }
  cout << endl;
}

ListNode* merge(ListNode* left, ListNode* right) {
  ListNode *helper = new ListNode(0), *pre = helper;
  while(left != NULL && right != NULL) {
    if(left->val < right->val) {
      pre->next = left;
      left = left->next;
    } else {
      pre->next = right;
      right = right->next;
    }
    pre = pre->next;
  }

  //处理剩下的
  if(left != NULL) {
    pre->next = left;
  }
  if(right != NULL) {
    pre->next = right;
  }
  return helper->next;
}

ListNode* sortList(ListNode *head) {
  if(head == NULL || head->next == NULL) {
    return head;
  }

  //找中间结点; 将列表一分为二
  ListNode *slow = head, *fast = head, *pre;
  while(fast != NULL && fast->next != NULL) {
    pre = slow;
    slow = slow->next;
    fast = fast->next->next;
  }
  pre->next = NULL; //切断
  cout << slow->val << endl;
  ListNode* l = sortList(head);
  ListNode* r = sortList(slow);

  return merge(l, r);
}

int main() {
  ListNode* head = new ListNode(21);
  ListNode* l1 = new ListNode(19);
  ListNode* l2 = new ListNode(10);
  ListNode* l3 = new ListNode(27);
  ListNode* l4 = new ListNode(8);
  ListNode* l5 = new ListNode(18);

  head->next = l1;
  l1->next = l2;
  l2->next = l3;
  l3->next = l4;
  l4->next = l5;

  print(sortList(head));
}
