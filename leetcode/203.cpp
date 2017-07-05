#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x): val(x), next(NULL) {}
};

void print(ListNode *head) {
  ListNode* cur = head;
  while(cur != NULL) {
    cout << cur->val << " -> ";
    cur = cur->next;
  }
  cout << endl;
}

ListNode* removeElements(ListNode* head, int val) {
  ListNode* dumpy = new ListNode(0);
  dumpy->next = head;
  ListNode* cur = dumpy;
  while(cur != NULL) {
    if(cur->next != NULL && cur->next->val == val) {
      cur->next = cur->next->next;
    } else {
      cur = cur->next;
    }
  }
  return dumpy->next;
}

int main() {
  ListNode* h1 = NULL;
  ListNode *h1N1 = new ListNode(1);
  ListNode *h1N2 = new ListNode(3);
  ListNode *h1N3 = new ListNode(4);
  ListNode *h1N4 = new ListNode(6);
  ListNode *h1N5 = new ListNode(7);
  ListNode *h1N6 = new ListNode(4);
  ListNode *h1N7 = new ListNode(13);
  h1 = h1N1;
  h1N1->next = h1N2;
  h1N2->next = h1N3;
  h1N3->next = h1N4;
  h1N4->next= h1N5;
  h1N5->next = h1N6;
  h1N6->next = h1N7;

  int val;
  cin >> val;
  print(removeElements(h1, val));
}
