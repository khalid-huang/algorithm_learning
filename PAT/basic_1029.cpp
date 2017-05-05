#include <iostream>
#include <vector>

using namespace std;

string origin;
string fact;
std::vector<char> destory;

bool contain(std::vector<char> v, char c) {
  size_t size = v.size();
  for(int i = 0;i < size; i++) {
    if(v[i] == c) {
      return true;
    }
  }
  return false;
}

void get_destory() {
  size_t size = origin.size();
  char temp;
  for(int i = 0, j = 0; i < size; i++) {
    if(origin[i] == fact[j]) {
      ++j;
      continue;
    } else {
      if(origin[i] >= 'a' && origin[i] <= 'z') {
        temp = origin[i] - 32;
      } else {
        temp = origin[i];
      }
      if(!contain(destory,temp)) {
        destory.push_back(temp);
      }
    }
  }
}

void print() {
  size_t size = destory.size();
  for(int i = 0; i < size; i++) {
    cout << destory[i];
  }
  cout << endl;
}

int main() {
  cin >> origin >> fact;
  get_destory();
  print();
}
