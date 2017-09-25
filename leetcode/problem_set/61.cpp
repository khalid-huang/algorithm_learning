#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x): val(x), next(NULL) {}
};

void print(ListNode* head) {
  ListNode* cur = head;
  while(cur != NULL) {
    cout << cur->val << " ";
    cur = cur->next;
  }
  cout << endl;
}

ListNode* rotateRight(ListNode* head, int k) {
  if(head == NULL) {
    return head;
  }

  ListNode *tempNode = head, *preNode, *newHead;
  int tempVal = 1;
  while(tempVal != k && tempNode->next != NULL) {
    preNode = tempNode;
    tempNode = tempNode->next;
    tempVal++;
  }

  if(tempNode->next != NULL) {
    newHead = tempNode->next;
    tempNode->next = NULL;
  } else {
    newHead = tempNode;
    preNode->next = NULL;
  }

  cout << newHead->val << endl;
  tempNode = newHead;
  while(tempNode->next != NULL) {
    tempNode = tempNode->next;
  }
  tempNode->next = head;
  return newHead;
}

int main() {
    ListNode *l1 = new ListNode(1);
    ListNode *l2 = new ListNode(2);
    ListNode *l3 = new ListNode(3);
    ListNode *l4 = new ListNode(4);
    ListNode *l5 = new ListNode(5);
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;

    int k;
    cin >> k;
    ListNode* newHead = rotateRight(l1, k);
    print(newHead);
}
