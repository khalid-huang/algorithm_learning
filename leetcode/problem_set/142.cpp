#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x): val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode* head) {
  if(head == NULL) {
    return NULL;
  }

  ListNode *walker = head, *runner = head;
  bool isCycle = false;
  while(walker->next != NULL && runner->next != NULL && runner->next->next != NULL) {
    walker = walker->next;
    runner = runner->next->next;

    if(walker == runner) {
      isCycle = true;
      break;
    }
  }
  if(isCycle == false) {
    return NULL;
  }
  ListNode* first = head;
  while(first != walker) {
    first = first->next;
    walker = walker->next;
  }
  return walker;
}
int main() {
  ListNode* head = new ListNode(1);
  ListNode* l1 = new ListNode(2);
  ListNode* l2 = new ListNode(3);
  ListNode* l3 = new ListNode(4);
  ListNode* l4 = new ListNode(5);
  head->next = l1;
  l1->next = l2;
  l2->next = l3;
  l3->next = l4;
  l4->next = l2;

  ListNode* rsl = detectCycle(head);
  if(rsl == NULL) {
    cout << "NULL" << endl;
  } else {
    cout << rsl->val << endl;
  }
}
