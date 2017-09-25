#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void print(std::vector<int> rsl) {
  int size = rsl.size();
  for(int i = 0;i < size; i++) {
    cout << rsl[i] << " ";
  }
  cout << endl;
}

//入度为0
std::vector<int> findOrder(int numCourses, std::vector<pair<int, int> >& prerequisites) {
  //初始化链接表和入度信息表
  int **matrix = new int*[numCourses];
  for(int i = 0; i < numCourses; i++) {
    matrix[i] = new int[numCourses];
  }
  int *indegree = new int[numCourses];
  for(int i = 0; i < numCourses; i++) {
    for(int j = 0; j < numCourses; j++) {
      matrix[i][j] = 0;
    }
  }

  for(int i = 0; i < numCourses; i++) {
    indegree[i] = 0;
  }


  int size = prerequisites.size(), ready, next;
  for(int i = 0; i  < size; i++) {
    next = prerequisites[i].first;
    ready = prerequisites[i].second;
    if(matrix[next][ready] == 0) {
      ++indegree[next]; //入度信息加1
      matrix[next][ready] = 1;
    }
  }

  queue<int> q;
  for(int i = 0;i < numCourses; i++) {
    if(indegree[i] == 0) {
      q.push(i);
    }
  }
  std::vector<int> rsl;
  int count = 0, course;
  while(!q.empty()) {
    course = q.front();
    ++count;
    rsl.push_back(course);
    q.pop();
    for(int i = 0; i < numCourses; i++) {
      if(matrix[i][course]) {
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

  return count == numCourses ? rsl : std::vector<int>();
}

int main() {
  int numCourses = 4;
  std::vector<pair<int, int> > prerequisites;
  // prerequisites.push_back(make_pair(0,1));
  prerequisites.push_back(make_pair(1,0));
  prerequisites.push_back(make_pair(2,0));
  prerequisites.push_back(make_pair(3,1));
  prerequisites.push_back(make_pair(3,2));
  print(findOrder(numCourses, prerequisites));
}
