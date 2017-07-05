#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x): val(x), next(NULL) {}
};

void print(ListNode* l) {
  while(l->next != NULL) {
    cout << l->val << "->";
    l = l->next;
  }
  cout << l->val << endl;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
  int carry = 0, v1, v2, sum;
  ListNode *cur = NULL, *head = NULL, *tail = NULL;
  while(l1 != NULL || l2 != NULL) {
    v1 = l1 == NULL ? 0 : l1->val;
    v2 = l2 == NULL ? 0 : l2->val;
    sum = v1 + v2 + carry;
    carry = sum / 10;
    sum = sum % 10;
    cur = new ListNode(sum);
    if(head == NULL) {
      head = cur;
      tail = cur;
    } else {
      tail->next = cur;
      tail = cur;
    }
    l1 = l1 != NULL ? l1->next : l1;
    l2 = l2 != NULL ? l2->next : l2;
  }
  if(carry != 0) {
    cur = new ListNode(carry);
    tail->next = cur;
    tail = cur;
  }
  return head;
}

int main() {
  ListNode l1v1(5);
  // ListNode l1v2(4);
  // ListNode l1v3(3);
  // l1v1.next = &l1v2;
  // l1v2.next = &l1v3;

  ListNode l2v1(5);
  // ListNode l2v2(6);
  // ListNode l2v3(4);
  // l2v1.next = &l2v2;
  // l2v2.next = &l2v3;
  print(&l1v1);

  print(addTwoNumbers(&l1v1, &l2v1));
}
