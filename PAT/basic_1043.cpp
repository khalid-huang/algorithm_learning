#include <iostream>

using namespace std;
char char_set[6] = {'P', 'A', 'T', 'e', 's', 't'};
int char_num[6];

int indexOf(char char_set[], char c) {
  for(int i = 0; i < 6; i++) {
    if(c == char_set[i]) {
      return i;
    }
  }
  return -1;
}

void analyse(string str) {
  size_t size = str.size();
  int index;
  for(int i = 0; i < size; i++) {
    index = indexOf(char_set, str[i]);
    if(index != -1) {
      char_num[index]++;
    }
  }
}

void printOne(int& flag) {
  flag = 0;
  for(int i = 0; i < 6; i++) {
    if(char_num[i] != 0) {
      flag = 1;
      cout << char_set[i];
      --char_num[i];
    }
  }
}

void printRsl() {
  int flag = 1;
  while(flag) {
    printOne(flag);
  }
  cout << endl;
}

int main() {
  string str;
  cin >> str;
  analyse(str);
  printRsl();
}
