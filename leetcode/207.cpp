//经验教训：1）对于可能大size的数组，要使用new，不使用栈直接生成，要放于堆里面；而且最好还是手动初始化，使用for来搞；记得new之后要delete
//这是最安全的
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

bool canFinish(int numCourses, std::vector<pair<int, int > >& prerequisites) {
  // // return false;
  //直接用栈保存的话，会爆空间的，要生成在堆 里面
  // int matrix[numCourses][numCourses]; //邻接表
  // int indegree[numCourses];
  int **matrix = new int*[numCourses];
  for(int i = 0; i < numCourses; i++) {
    matrix[i] = new int[numCourses];
  }
  int *indegree = new int[numCourses];

  //这里要注意的是用new初始化本身就是0了；最好还是不要使用memset
  for(int i = 0; i < numCourses; i++) {
    for(int j = 0; j < numCourses; j++) {
      matrix[i][j] = 0;
    }
  }
  for(int i = 0; i < numCourses; i++) {
    indegree[i] = 0;
  }

  cout << matrix[0][1] << endl;
  int size = prerequisites.size(), ready, next;
  for(int i = 0; i < size; i++) {
    ready = prerequisites[i].first;
    next= prerequisites[i].second;
    if(matrix[ready][next] == 0) {
      ++indegree[next]; //入度信息
      matrix[ready][next] = 1;
    }
  }

  //只入入度为0的;队列保存了此时可以上的课,也就是入度为0的
  queue<int> q;
  for(int i = 0; i < numCourses; i++) {
    if(indegree[i] == 0) {
      q.push(i);
    }
  }
  int count = 0, course;
  while(!q.empty()) {
    course = q.front();
    q.pop();
    ++count;
    for(int i = 0; i < numCourses; i++) {
      if(matrix[course][i]) {
        if(--indegree[i] == 0) {
          q.push(i);
        }
      }
    }
  }
  //释放内存
  for(int i = 0; i < numCourses; i++) {
    delete matrix[i];
  }
  delete matrix;
  delete indegree;

  return count == numCourses;
}

int main() {
    int numCourses = 1;
    std::vector<pair<int, int> > prerequisites;
    // prerequisites.push_back(make_pair(0,1));
    // prerequisites.push_back(make_pair(1,0));
    cout << canFinish(numCourses, prerequisites) << endl;
}
