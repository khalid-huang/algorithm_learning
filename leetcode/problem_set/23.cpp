//主要思想就是平行遍历，每次从头结点找到最小的那个点，连起来；然后把lists里面的被选择的最小的点的位置往后移动
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};

void print(ListNode *head) {
  ListNode* cur = head;
  while(cur != NULL) {
    cout << cur->val << " -> ";
    cur = cur->next;
  }
  cout << endl;
}

bool allNULL(std::vector<ListNode*>& lists) {
  int size = lists.size();
  for(int i = 0; i < size; i++) {
    cout << "k" << endl;
    if(lists[i] != NULL) {
      return false;
    }
  }
  return true;
}

ListNode* getMin(std::vector<ListNode*>& lists) {
  int size = lists.size();
  // int minV = lists[0]->val;
  int index;
  ListNode* minLN = NULL;
  for(int i = 0; i < size; i++) {
    if(lists[i] != NULL && (minLN == NULL || lists[i]->val < minLN->val)) {
      minLN = lists[i];
      index = i;
    }
  }
  lists[index] = minLN->next; // 更新头结点信息
  return minLN;
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
  ListNode* head = NULL;
  ListNode* cur = NULL;
  ListNode* pre = NULL;
  while(!allNULL(lists)) {
    cur = getMin(lists);
    if(head == NULL) {
      head = cur;
    } else {
      pre->next = cur;
    }
    pre = cur;
  }
  return head;
}

int main() {
  ListNode* h1, *h2, *h3;
  ListNode *h1N1 = new ListNode(1);
  ListNode *h1N2 = new ListNode(3);
  ListNode *h1N3 = new ListNode(4);
  ListNode *h1N4 = new ListNode(6);
  h1 = h1N1;
  h1N1->next = h1N2;
  h1N2->next = h1N3;
  h1N3->next = h1N4;


  ListNode *h2N1 = new ListNode(2);
  ListNode *h2N2 = new ListNode(4);
  ListNode *h2N3 = new ListNode(5);
  ListNode *h2N4 = new ListNode(10);
  h2 = h2N1;
  h2N1->next = h2N2;
  h2N2->next = h2N3;
  h2N3->next = h2N4;


  ListNode *h3N1 = new ListNode(1);
  ListNode *h3N2 = new ListNode(2);
  ListNode *h3N3 = new ListNode(3);
  ListNode *h3N4 = new ListNode(7);
  h3 = h3N1;
  h3N1->next = h3N2;
  h3N2->next = h3N3;
  h3N3->next = h3N4;

  std::vector<ListNode*> v;
  v.push_back(h1);
  v.push_back(h2);
  v.push_back(h3);
  print(mergeKLists(v));

}
