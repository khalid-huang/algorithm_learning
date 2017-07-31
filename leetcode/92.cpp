#include <iostream>
using namespace std;


//思路是每次换一组；
// 1 2 3 4 5
// -> 1 3 2 4 5 (换2, 3)
// -> 1 4 3 2 5 (换4 ,3)
ListNode* reverseBeween(ListNode* head, int m, int n) {
  if(m == n || head == NULL) {
    return head;
  }
  int num = n - m;
  ListNode *fakeNode = new ListNode(0);
  fakeNode->next = head;
  ListNode *cur = fakeNode;
  while(m--) {
    cur = cur->next;
  }
  ListNode *pre = cur, *p, *ppre = pre->next;
  while(num--) {
    p = ppre->next;
    ppre->next = p->next;
    p->next = pre->next;
    pre->next = p;
  }
  return fakeNode->next;
}

int main() {

}
