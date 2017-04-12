#include <iostream>
#include <string>
using namespace std;

int flag1 = 0; //表示当前找的字符，0表示P，1表示A, 2表示T, 3表示完成
int flag2 = 0; //表示是否有违法字符 ; 0表示无，1表示有
int flag3 = 1; //表示每三种情况下是否成立; 0表示成立，1表示不成立

bool legal_char(char c) {
  if(c == 'P' || c == 'A' || c == 'T') {
    return true;
  } else {
    return false;
  }
}

void searchPAT(string str) {
  flag1 = 0;
  flag2 = 0;
  flag3 = 1;
  int a_size = 0;
  int b_size = 0;
  int c_size = 0;

  int size = str.size();
  for(int i = 0; i < size; i++) {

    if(!legal_char(str[i])) {
      flag2 = 1;
      break;
    }

    if(str[i] == 'A') {
      // cout << "flag1: " << flag1 << endl;
      if(flag1 == 1) {
        flag1 = 2;
      } else if(flag1 == 0) {
        a_size++;
      } else if(flag1 == 2) {
        b_size++;
      } else if(flag1 == 3) {
        c_size++;
      }
      continue;
    }

    if(str[i] == 'P' && flag1 == 0) {
      flag1 = 1;
      continue;
    }

    // if(str[i] == 'T') {
    //   cout << "R" << flag1 << endl;
    // }
    if(str[i] == 'T' && flag1 == 2) {
      flag1 = 3;
      continue;
    }
  }

  // cout << "size: " << a_size << " " << b_size << " " << c_size << endl;
  //关于第三个的判断实现太奇怪了，不大懂题目的意思

}

bool check(string str) {
  searchPAT(str);
  // cout << flag1 << " " << flag2 << " " << flag3 << endl;
  if(flag2 == 0 && flag1 >= 2 && flag3 == 0) {
    return true;
  } else {
    return false;
  }
}

int main() {
  int t;
  string str;
  cin >> t;
  while(t--) {
    cin >> str;
    if(check(str)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
