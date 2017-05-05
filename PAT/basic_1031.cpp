#include <iostream>
#include <vector>

using namespace std;
int weights[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
char M[] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};

bool isValid(string str) {
  size_t size = str.size();
  int temp = 0;
  char c;
  for(int i = 0; i < size; i++) {
    temp += (str[i] - '0') * weights[i];
  }
  temp = temp % 11;
  if(M[temp] == str[size-1]) {
    return true;
  } else {
    return false;
  }
}

int main() {
  int N;
  cin >> N;

  string str;
  std::vector<string> fake;
  while(N--) {
    cin >> str;
    if(!isValid(str)) {
      fake.push_back(str);
    }
  }
  size_t size = fake.size();
  if(size == 0) {
    cout << "All passed" << endl;
  } else {
    // cout << size << endl;
    for(int i = 0; i < size; i++) {
      cout << fake[i] << endl;
    }
  }
}
