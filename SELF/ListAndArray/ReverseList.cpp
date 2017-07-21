#include <iostream>
using namespace std;

struct ListNode {
  int value;
  ListNode* next;
  ListNode() {
    value = 0;
    next = NULL;
  }
};

int N;

void printList(ListNode* head) {
  ListNode *p = head;
  while(p != NULL) {
    cout << p->value << " ";
    p = p->next;
  }
  cout << endl;
}

//三个指针，其中p是用于缓存下q->next，防止链表丢失的;
//q是用于前进的，而head一直保持新的链表的头
ListNode* ReverseList(ListNode* head) {
  //开始时head和p在同一处，q在head->next
  //完成一轮后，状态是q指向了head; q指向了原本的q->next;需要做的有将head移动到q的位置，q移动到p->next的位置；
  //p一直只是一个缓存q->next的指针
  if(head == NULL)
    return head;
  ListNode *p = head;
  ListNode *q = head->next;
  while(q != NULL) {
    //调整指针走向
    p->next = q->next;
    q->next = head;
    //向前移动
    head = q;
    q = p->next;
  }
  return head;
}

//递归的方式；思路是反转当前head的链表，相当于反转head之后的链表，再把head与head->next的指向反转
//递归除了终止条件走的是直接结果，其他的走的都是过程（这个过程的实现依赖于传入的参数，也就是函数栈的应用了，直接修改了走向，而原本的信息保存在了函数栈里面，思考一个个指针在函数栈里面的情况），而不是直接结果；
ListNode* ReverseList2(ListNode* head) {
  //链表为空或是只有一个元素时返回head
  if(head == NULL || head->next == NULL) {
    return head;
  } else {
    ListNode *newhead = ReverseList2(head->next); //先反转后面的链表，
    head->next->next = head;//再将当前节点设置为其后面节点的后续节点
    head->next = NULL;
    return newhead;
  }
}

int main() {
  cin >> N;
  int value;
  ListNode* tail = NULL;
  ListNode* head = NULL;
  ListNode* p = NULL;
  for(int i = 0; i < N; i++) {
    cin >> value;
    p = new ListNode;
    p->value = value;
    if(head == NULL) {
      head = p;
      tail = p;
    } else {
      tail->next = p;
      tail = p;
    }
  }
  printList(head);
  head = ReverseList2(head);
  printList(head);
}
