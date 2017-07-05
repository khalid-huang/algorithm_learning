//思路跟24是一样的，就是要缓存下需要交换位置的点，然后进行统一交换，防止信息丢失
#include<iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x): val(x), next(NULL) {}
};

void print(ListNode *head) {
  ListNode* cur = head;
  while(cur != NULL) {
    cout << cur->val << " -> ";
    cur = cur->next;
  }
  cout << endl;
}

ListNode* reverseKGroup(ListNode* head, int k) {
  if(head == NULL) {
    return head;
  }
  ListNode* reverseGroup[k+1];
  ListNode* dumpy = new ListNode(0);
  dumpy->next = head;
  ListNode* temp = dumpy;
  int cur;
  while(true) {
    cur = 0;
    reverseGroup[cur] = temp;
    ++cur;
    while(temp->next != NULL && cur <= k) {
      reverseGroup[cur] = temp->next;
      ++cur;
      temp = temp->next;
      if(temp == NULL) {
        break;
      }
    }
    cout << cur << "-" << k << endl;
    if(cur < k+1) {
      break;
    }

    reverseGroup[1]->next = reverseGroup[k]->next;
    reverseGroup[0]->next = reverseGroup[k];
    for(int i = k; i > 1; i--) {
      reverseGroup[i]->next = reverseGroup[i-1];
    }
    temp = reverseGroup[1];
  }
  return dumpy->next;
}

int main() {
  ListNode* h1 = NULL;
  ListNode *h1N1 = new ListNode(1);
  // ListNode *h1N2 = new ListNode(3);
  // ListNode *h1N3 = new ListNode(4);
  // ListNode *h1N4 = new ListNode(6);
  // ListNode *h1N5 = new ListNode(7);
  // ListNode *h1N6 = new ListNode(10);
  // ListNode *h1N7 = new ListNode(13);
  h1 = h1N1;
  // h1N1->next = h1N2;
  // h1N2->next = h1N3;
  // h1N3->next = h1N4;
  // h1N4->next= h1N5;
  // h1N5->next = h1N6;
  // h1N6->next = h1N7;

  int k;
  cin >> k;
  print(reverseKGroup(h1, k));

}
