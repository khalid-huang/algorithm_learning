#include <iostream>

using namespace std;

struct ListNode {
  int  val;
  ListNode* next;
  ListNode (int x): val(x), next(NULL) {}
};

void print(ListNode* head) {
  ListNode* cur = head;
  while(cur != NULL) {
    cout << cur->val << " ";
    cur = cur->next;
  }
  cout << endl;
}

//利用结点之间的关系，如果存在重复的情况，那么cur一定有移动过，利用 这个关系重建关系
ListNode* deleteDuplicates(ListNode* head) {
  ListNode* fakeHead = new ListNode(0);
  fakeHead->next = head;
  ListNode* preNode = fakeHead, *curNode = head;
  while(curNode != NULL) {
    while(curNode->next != NULL && curNode->next->val == curNode->val) {
      cur = cur->next;
    }
    //如果cur没有移动过的话，就表示没有重复的情况,就直接移动pre ;否则就直接使用next跳过这个重复结点
    if(pre->next == cur) {
        pre = pre->next;
    } else {
      pre->next = cur->next;
    }
    cur = cur->next;
  }
  return fakeHead->next;
}

//直接，但是代码不好看
ListNode* deleteDuplicates1(ListNode* head) {
  if(head == NULL) {
    return head;
  }
  ListNode *newHead, *newCur, *cur = head;
  newHead = newCur = new ListNode(0);
  int flag = 0, curVal = cur->val;
  while(cur != NULL) {
    if(cur->next == NULL) {
      if(flag == 0) {
        newCur->next = cur;
        newCur = cur;
      }
      cur = cur->next;
      newCur->next = NULL; //切断后续的节点
      break;
    }

    cout << cur->next->val << " " << curVal << endl;
    if(cur->next->val == curVal) {
      flag = 1;
      cur = cur->next;
    } else {
      if(flag == 1) {
        cur = cur->next;
        curVal = cur->val;
        flag = 0;
      } else {
        newCur->next = cur;
        newCur = cur;
        cur = cur->next;
        curVal =cur->val;
        flag = 0;
      }
    }
  }
  return newHead->next;
}

int main() {
  // ListNode *l1 = new ListNode(1);
  ListNode *l2 = new ListNode(1);
  ListNode *l3 = new ListNode(2);
  ListNode *l4 = new ListNode(2);
  // ListNode *l5 = new ListNode(3);
  // l1->next = l2;
  l2->next = l3;
  l3->next = l4;
  // l4->next = l5;

  ListNode* head=l2;
  print(deleteDuplicates(head));
}
