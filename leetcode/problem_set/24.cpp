//参考 https://leetcode.com/problems/swap-nodes-in-pairs/#/solutions
//主要是想到使用三个为一组进行变换，而不是两个
#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x): val(x), next(NULL){}
};


void print(ListNode *head) {
  ListNode* cur = head;
  while(cur != NULL) {
    cout << cur->val << " -> ";
    cur = cur->next;
  }
  cout << endl;
}

ListNode* swapPairs(ListNode* head) {
  ListNode* dummy = new ListNode(0);
  dummy->next = head;
  ListNode* current = dummy;
  ListNode* first, *second;
  while(current->next != NULL && current->next->next != NULL) {
    first = current->next;
    second = current->next->next;
    first->next = second->next;
    current->next = second;
    second->next = first;
    current = first;
  }
  return dummy->next;
}

int main() {
  ListNode* h1 = NULL;
  ListNode *h1N1 = new ListNode(1);
  ListNode *h1N2 = new ListNode(3);
  ListNode *h1N3 = new ListNode(4);
  ListNode *h1N4 = new ListNode(6);
  ListNode *h1N5 = new ListNode(7);
  ListNode *h1N6 = new ListNode(10);
  h1 = h1N1;
  h1N1->next = h1N2;
  h1N2->next = h1N3;
  h1N3->next = h1N4;
  h1N4->next= h1N5;
  h1N5->next = h1N6;
  print(swapPairs(h1));
}
