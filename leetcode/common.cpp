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



//ascill码，char, char* string的相互转换

char int2char(int val) {
  return char(val); //也可以是char('A'+5)
}

string int2str(int val) {
  // char a = char(val);
  // return string(&a); //使用了string(char*)构造函数
  return var + "";
}



//初始化的方式
#include<cstring>

//对于使用new出来的空间，最好不要使用memeset，会有一些奇怪的事情发生
int matrix[numCourses][numCourses]; //邻接表
int indegree[numCourses];
//初始化
memset(matrix, 0, sizeof(matrix));
memset(indegree, 0, sizeof(indegree));
