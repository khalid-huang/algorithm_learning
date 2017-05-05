#include <iostream>
#include <set>
#include <map>

using namespace std;
std::map<char, int> pearlNum;
std::set<char> pearl;

int flag = 1; //1表示满足，-1表示不满足

void printMap() {
  for(std::map<char, int>::iterator it = pearlNum.begin(); it != pearlNum.end(); ++it) {
    cout << it->first << ": " << it->second << endl;
  }
}

void getAllPearl(string pearls1, string pearls2) {
  size_t size = pearls1.size();
  for(int i = 0 ; i < size; i++) {
    pearl.insert(pearls1[i]);
  }
  size = pearls2.size();
  for(int i = 0 ; i < size; i++) {
    pearl.insert(pearls2[i]);
  }
}

void analyse(string pearls) {

  size_t size = pearls.size();
  for(int i = 0; i < size; i++) {
    if(pearlNum.find(pearls[i]) != pearlNum.end()) {
      pearlNum[pearls[i]] = pearlNum[pearls[i]] + 1;
    } else {
      pearlNum[pearls[i]] = 1;
    }
  }
  // cout << "----analyse----" << endl;
  // printMap();
}

void cal(string pearls1, string pearls2, int& remain, int& lack) {
  size_t size = pearls2.size();
  for(int i = 0; i < size; i++) {
    if(pearlNum.find(pearls2[i]) != pearlNum.end()) {
      pearlNum[pearls2[i]] = pearlNum[pearls2[i]] - 1;
      if(pearlNum[pearls2[i]] < 0) {
        flag = -1;
      }
    } else {
      pearlNum[pearls2[i]] = -1;
      flag = -1;
    }
  }
  // cout << "----cal end----" << endl;
  // printMap();
  if(flag == -1) {
    std::set<char>::iterator it;
    for(it = pearl.begin(); it != pearl.end(); it++) {
      if(pearlNum[*it] < 0) {
        lack += (-pearlNum[*it]);
      }
    }
  } else {
    std::set<char>::iterator it;
    for(it = pearl.begin(); it != pearl.end(); it++) {
      remain += pearlNum[*it];
    }
  }
}

int main() {
  string pearls1, pearls2;
  int remain = 0, lack = 0;
  cin >> pearls1 >> pearls2;
  getAllPearl(pearls1, pearls2);

  analyse(pearls1);

  cal(pearls1, pearls2, remain, lack);
  if(flag == 1) {
    cout << "Yes " << remain << endl;
  } else {
    cout << "No " << lack << endl;
  }
}
