#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

struct Node {
  int address;
  int value;
  int next;
};

int value[100005], nextAddress[100005];
int startAddress, N, K;
std::vector<Node> linkArray;
std::vector<Node> rslArray;

void getLinkArray() {
  int cur = startAddress, i = 0;
  while(cur != -1) {
    Node node = {cur, value[cur], nextAddress[cur]};
    linkArray.push_back(node);
    cur = nextAddress[cur];
    i++;
  }
}

void transform() {
  size_t size = linkArray.size();
  if(size != N) {
    cout << "数据有误" << endl;
    return;
  }
  int cur = 0, k, temp;
  while(cur < size) {
    if(cur + K <= size) {
      k = K;
      while(k) {
        temp = cur + k - 1; //坐标要减1
        Node node = {linkArray[temp].address, linkArray[temp].value};
        if(rslArray.size()) {
          rslArray[rslArray.size()-1].next = linkArray[temp].address;
        }
        rslArray.push_back(node);
        --k;
      }
      cur = cur + K;
    } else {
      Node node = {linkArray[cur].address, linkArray[cur].value};
      if(rslArray.size()) {
          rslArray[rslArray.size()-1].next = linkArray[cur].address;
      }
      rslArray.push_back(node);
      cur = cur + 1;
    }
  }
  rslArray[rslArray.size()-1].next = -1;
}

string fillZero(int val) {
  stringstream ss_val;
  string rsl;
  ss_val << val;
  rsl = ss_val.str();
  if(val == -1) {
    return rsl;
  } else {
    int fill_num = 5 - rsl.size();
    while(fill_num--) {
      rsl = "0" + rsl;
    }
    return rsl;
  }
}

void print() {
  size_t size = linkArray.size();
  // cout << "++++++" << endl;
  //
  for(int i = 0; i < size; i++) {
      cout << fillZero(rslArray[i].address) << " " << rslArray[i].value << " " <<  fillZero(rslArray[i].next) << endl;
  }
  //
  // cout << "------" << endl;

}

int main() {
  int address;
  cin >> startAddress >> N >> K;
  for(int i = 0; i < N; i++) {
    cin >> address;
    cin >> value[address] >> nextAddress[address];
  }

  getLinkArray();
  transform();
  print();
}
