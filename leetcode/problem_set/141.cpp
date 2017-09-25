#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x): val(x), next(NULL) {}
};

bool hasCycle(ListNode* head) {
  if(head == NULL) {
    return false;
  }
  ListNode* walker = head;
  ListNode* runner = head;
  while(walker->next != NULL && runner->next != NULL && runner->next->next != NULL) {
    walker = walker->next;
    runner = runner->next->next;
    if(walker == runner) {
      return true;
    }
  }
  return false;
}

int main() {
  ListNode* head = new ListNode(1);
  ListNode* l1 = new ListNode(2);
  ListNode* l2 = new ListNode(2);
  ListNode* l3 = new ListNode(2);
  ListNode* l4 = new ListNode(2);
  head->next = l1;
  l1->next = l2;
  l2->next = l3;
  l3->next = l4;
  l4->next = l2;

  cout << hasCycle(head) << endl;
}
