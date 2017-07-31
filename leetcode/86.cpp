#include <iostream>

using namespace std;

struct ListNode {
  int  val;
  ListNode* next;
  ListNode (int x): val(x), next(NULL) {}
};

void print(ListNode* head) {
  ListNode* cur = head;
  while(cur != NULL) {
    cout << cur->val << " ";
    cur = cur->next;
  }
  cout << endl;
}

//直接分两半，再接起来
ListNode* partition(ListNode* head,int x) {
  ListNode *p1= new ListNode(0), *p2 = new ListNode(0);
  ListNode *cur = head;
  ListNode *h1 = p1, *h2 = p2;

  while(cur != NULL) {
    if(cur->val < x) {
      p1->next = cur;
      p1 = p1->next;
    } else {
      p2->next = cur;
      p2 = p2->next;
    }
    cur = cur->next;
  }
  p1->next = h2->next;
  p2->next = NULL;
  return h1->next;
}

int main() {
  ListNode *l1 = new ListNode(1);
  ListNode *l2 = new ListNode(4);
  ListNode *l3 = new ListNode(3);
  ListNode *l4 = new ListNode(2);
  ListNode *l5 = new ListNode(5);
  ListNode *l6 = new ListNode(2);
  l1->next = l2;
  l2->next = l3;
  l3->next = l4;
  l4->next = l5;
  l5->next = l6;

  ListNode* head=l1;
  print(partition(head, 3));
}
