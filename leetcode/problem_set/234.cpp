#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x): val(x), next(NULL) {}
};

void printList(ListNode* head) {
  ListNode *cur = head;
  while(cur != NULL) {
    cout << cur->val << " ";
    cur = cur->next;
  }
  return;
}

ListNode* reverseList(ListNode* head) {
  ListNode* next = head, *pre = NULL, *cur = NULL;
  while(next != NULL) {
    cur = next;
    next = next->next;
    cur->next = pre;
    pre = cur;
  }
  return cur;
}

bool isPalindrome(ListNode* head) {
  ListNode *slow = head, *fast = head, *cur;
  while(fast->next != NULL && fast->next->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
  }
  slow = slow->next;
  slow = reverseList(slow);
  cur = head;
  bool rsl = true;
  while(slow != NULL) {
    if(slow->val != cur->val) {
      rsl = false;
      break;
    }
    slow = slow->next;
    cur = cur->next;
  }
  return rsl;
}

int main() {
  ListNode* head = new ListNode(1);
  ListNode *l2 = new ListNode(2);
  ListNode *l3 = new ListNode(3);
  ListNode *l4 = new ListNode(2);
  // ListNode *l5 = new ListNode(1);

  head->next = l2;
  l2->next=  l3;
  l3->next = l4;
  // l4->next = l5;

  // printList(reverseList(l2));

  cout << isPalindrome(head) << endl;
}
