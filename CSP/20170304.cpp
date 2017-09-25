#include <iostream>
#include <vector>

using namespace std;

struct EdgeNode {
  int index;
  int data;
  EdgeNode* next;
  EdgeNode(int index, int data):index(index), data(data), next(NULL) {}
};

struct VertexNode {
  // int index;
  EdgeNode* firstNode;
  VertexNode(): firstNode(NULL) {}
};

void createGraph(int edgesNums, std::vector<VertexNode*>& AjdList) {
  int start, end, val;
  for(int i = 0; i < edgesNums; i++) {
    cin >> start >> end >> val;
    EdgeNode* en = new EdgeNode(end, val);
    if(AjdList[start] == NULL) {
      AjdList[start] = new VertexNode();
      AjdList[start]->firstNode = en;
    } else {
      EdgeNode* en1 = AjdList[start]->firstNode;
      while(en1->next != NULL) {
        en1 = en1->next;
      }
      en1->next = en;
    }
  }
}

void dfs(std::vector<VertexNode*>& AjdList,int start, int end, int cur, int& result) {
  if(start == end) {
    if(result == -1) {
      result = cur;
    } else {
      result = cur < result ? cur : result;
    }
    return;
  }
  if(AjdList[start] == NULL) {
    return;
  }
  EdgeNode* en = AjdList[start]->firstNode;
  int temp;
  while(en != NULL) {
    temp = cur > en->data ? cur : en->data;
    dfs(AjdList, en->index, end, temp, result);
    en = en->next;
  }
}

int solve(std::vector<VertexNode* >& AjdList, int nodesNums, int edgesNums) {
  int result = -1, start = 1, end = nodesNums, cur = 0;
  dfs(AjdList, start, end, cur, result);
  return result;
}

int main() {
  int nodesNums, edgesNums;
  cin >>nodesNums >> edgesNums;
  std::vector<VertexNode*> AjdList(nodesNums + 1, NULL);
  createGraph(edgesNums, AjdList);
  // cout << "kaka" << endl;
  cout << solve(AjdList, nodesNums, edgesNums) << endl;
  return 0;
}
