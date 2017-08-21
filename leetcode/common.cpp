//经典
79,33,88
139
Reorder List(143); 分解的思想

void print(std::vector<std::vector<int> > rsl) {
  int size_o = rsl.size(), size_i;
  for(int i = 0;i < size_o; i++) {
    size_i = rsl[i].size();
    for(int j = 0; j < size_i; j++) {
      cout << rsl[i][j] << " ";
    }
    cout << endl;
  }
}

void print(std::vector<int> rsl) {
  int size = rsl.size();
  for(int i = 0;i < size; i++) {
    cout << rsl[i] << " ";
  }
  cout << endl;
}

void print(ListNode* head) {
  ListNode* cur = head;
  while(cur != NULL) {
    cout << cur->val << " ";
  }
  cout << endl;
}

//补充二分的
