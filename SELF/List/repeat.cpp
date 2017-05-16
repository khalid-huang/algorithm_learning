ListNode* ReverseList(ListNode* head) {
  if(head == NULL) {
    return head;
  }
  ListNode* p = head;
  ListNode* q = p->next;
  while(q != NULL) {
    p->next = q->next;
    q->next = head;

    head = q;
    q = p->next;
  }
}
