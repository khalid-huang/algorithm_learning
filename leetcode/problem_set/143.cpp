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

void reorderList(ListNode* head) {
  if(head == NULL || head->next == NULL) {
    return;
  }
  //找中点
  ListNode* walker = head;
  ListNode* runner = head;
  while(runner->next != NULL && runner->next->next != NULL) {
    walker = walker->next;
    runner = runner->next->next;
  }

  ListNode* middle = walker;
  // cout << middle->val << endl;
  //翻转 1->2->3->4->5->6 ==> 1->2->3->6->5->4
  ListNode *pre = middle;
  ListNode *pp = pre->next, *p;
  while(pp->next != NULL) {
    // cout << "#" << pp->next->val << endl;
    p = pp->next;
    pp->next = p->next;
    p->next = pre->next;
    pre->next = p;
    // print(head);
  }

  // print(head);

  //从中心开始，一对对翻转比如 1-2->3->6->5->4先变成1->6->2->3->5->4
  ListNode *p1 = head, *p2 = middle->next, *temp;
  while(p1 != middle) {
    middle->next = p2->next;
    p2->next = p1->next;
    p1->next = p2;
    p1 = p2->next;
    p2 = middle->next;
  }
}

int main() {
  ListNode* head = new ListNode(1);
  ListNode* l2 = new ListNode(2);
  ListNode* l3 = new ListNode(3);
  ListNode* l4 = new ListNode(4);
  ListNode* l5 = new ListNode(5);
  ListNode* l6 = new ListNode(6);
  head->next = l2;
  l2->next = l3;
  l3->next = l4;
  l4->next = l5;
  l5->next = l6;
  print(head);
  reorderList(head);
  print(head);
}
