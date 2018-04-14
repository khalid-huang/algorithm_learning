//思路是加入一个伪结点，来方便进行遍历，同时维护两个指针，伪结点为0表示偶数，第一个结点为奇数；每次都向前前进两个单位

#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

void print(ListNode* head) {
    ListNode* node = head;
    while(node != NULL) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}

ListNode* buildList() {
    ListNode* head = new ListNode(1);
    ListNode* l2 = new ListNode(2);        
    ListNode* l3 = new ListNode(3);        
    ListNode* l4 = new ListNode(4);        
    ListNode* l5 = new ListNode(5);

    head->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;

    return head;
}

//加入虚结点后，画图模拟下就知道了
ListNode* oddEventList(ListNode* head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }

    ListNode* fakeHead = new ListNode(0);
    fakeHead->next = head;
    ListNode *curOdd, *curEven;
    curEven = fakeHead;
    curOdd = head;
    while(curOdd != NULL && curOdd->next != NULL) {
        curEven->next = curOdd->next;
        curOdd->next = curEven->next->next;
        
        curEven = curEven->next;
        //确保curOdd能够保持最后一个非零的奇数结点
        if(curOdd->next != NULL) {
            curOdd = curOdd->next;
        }
    }

    curEven->next = NULL;
    curOdd->next = fakeHead->next;
    return head;
}

int main() {
    ListNode* head = buildList();
    print(head);
    head = oddEventList(head);
    print(head);    
}