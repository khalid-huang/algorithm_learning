#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x): val(x), next(NULL) {}
};

void print(ListNode* head) {
  ListNode* cur = head;
  while(cur) {
    cout << cur->val << " ";
    cur = cur->next;
  }
  cout << endl;
}
//有序的由helper来引导，无序的由head一开始的位置引导
//对于每一个数字，都需要从头去找它的合适位置
ListNode* insertionSortList(ListNode* head) {
  if(head == NULL) {
    return head;
  }

  ListNode* helper = new ListNode(0);
  ListNode *cur = head, *pre = helper, *next = NULL;
  while(cur != NULL) {
    next = cur->next; //缓存
    //找位置
    while(pre->next != NULL && pre->next->val < cur->val) {
      pre = pre->next;
    }
    cur->next = pre->next;
    pre->next = cur;
    pre = helper;
    cur = next;
  }
  return helper->next;
}



int main() {
  ListNode* head = new ListNode(21);
  ListNode* l1 = new ListNode(19);
  ListNode* l2 = new ListNode(10);
  ListNode* l3 = new ListNode(27);
  ListNode* l4 = new ListNode(8);
  ListNode* l5 = new ListNode(18);

  head->next = l1;
  l1->next = l2;
  l2->next = l3;
  l3->next = l4;
  l4->next = l5;

  print(insertionSortList(head));
}
