#include <iostream>
#include <map>

using namespace std;

//思想主要是使用Map去缓存已经创建的结点，防止多次创建
struct RandomListNode {
  int label;
  RandomListNode *next, *random;
  RandomListNode(int x): label(x), next(NULL), random(NULL) {}
};

void print(RandomListNode* head) {
  RandomListNode *cur = head;
  while(cur != NULL) {
    cout << cur->label << " ";
    if(cur->next != NULL) {
      cout << "next: " << cur->next->label << " ";
    } else {
      cout << "next: NULL" << " ";
    }
    if(cur->random != NULL) {
      cout << "random: " << cur->random->label << " ";
    } else {
      cout << "random: NULL" << " ";
    }
    cout << endl;
    cur = cur->next;
  }
}

RandomListNode *copyRandomList(RandomListNode* head) {
  if(head == NULL) {
    return head;
  }

  map<RandomListNode*, RandomListNode*> tempMap;
  RandomListNode* cur = head, *pre = NULL;
  RandomListNode* newHead = new RandomListNode(cur->label);
  tempMap[head] = newHead;
  RandomListNode *tempNode, *tempNode1;
  while(cur != NULL) {
    if(tempMap.find(cur) != tempMap.end()) {
      tempNode = tempMap[cur];
    } else {
      tempNode = new RandomListNode(cur->label);
      tempMap[cur] = tempNode;
    }

    if(pre != NULL) {
      pre->next = tempNode;
    }
    pre = tempNode;
    if(cur->random != NULL) {
      if(tempMap.find(cur->random) != tempMap.end()) {
        tempNode->random = tempMap[cur->random];
      } else {
        tempNode1 = new RandomListNode(cur->random->label);
        tempNode->random = tempNode1;
        tempMap[cur->random] = tempNode1;
      }
    }
    cur = cur->next;
    // cout << endl << endl;
    // print(newHead);
  }
  return newHead;
}



int main() {
  RandomListNode *head = new RandomListNode(1);
  RandomListNode *r2 = new RandomListNode(2);
  RandomListNode *r3 = new RandomListNode(3);
  RandomListNode *r4 = new RandomListNode(4);

  head->next = r2;
  r2->next = r3;
  r3->next = r4;

  head->random = r2;
  r2->random = NULL;
  r3->random = r4;
  r4->random = r3;

  print(head);
  cout << "copy result:" << endl;
  print(copyRandomList(head));
  return 0;
}
