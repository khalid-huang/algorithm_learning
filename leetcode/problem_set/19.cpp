#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x): val(x), next(NULL) {}
};

void print(ListNode* head) {
  ListNode *cur = head;
  while(cur != NULL) {
    cout << cur->val << "->";
    cur = cur->next;
  }
  cout << endl;
}

ListNode* removeNthFromEnd(ListNode* head, int n) {
  if(head == NULL) {
    return NULL;
  }

  ListNode *fast, *slow;
  fast = head, slow = head;
  for(int i = 0; i < n; i++) {
    fast = fast->next;
    if(fast == NULL) {
      return head->next;
    }
  }

  while(fast->next != NULL) {
    cout << "kk" << endl;
    fast = fast->next;
    slow = slow->next;
  }

  ListNode *temp = slow->next;
  slow->next = slow->next->next;
  // free(temp);
  if(temp == head) {
    head = temp->next;
  }
  return head;
}

int main() {
  ListNode *head;
  ListNode *l1 = new ListNode(1);
  ListNode *l2 = new ListNode(2);
  ListNode *l3 = new ListNode(3);
  ListNode *l4 = new ListNode(4);
  ListNode *l5 = new ListNode(5);

  head = l1;
  l1->next = l2;
  l2->next = l3;
  l3->next = l4;
  l4->next = l5;
  // int n;
  // cin >> n;
  head = removeNthFromEnd(head, 5);
  print(head);

}
