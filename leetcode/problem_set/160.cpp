#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x): val(x), next(NULL) {}
};

ListNode* getIntersectionNode(ListNode *headA, ListNode* headB) {
  if(headA == NULL || headB == NULL) {
    return NULL;
  }
  ListNode* p1 = headA, *p2 = headB;
  while(p1 != p2) {
    p1 = p1 == NULL ? headB : p1->next;
    p2 = p2 == NULL ? headA : p2->next;
  }
  return p1;
}

int main() {


}
