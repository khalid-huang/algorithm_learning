#include <iostream>
#include <vector>

using namespace std;

void print(std::vector<string> v) {
  int size = v.size();
  for(int i = 0; i < size; i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}

void split(string path, std::vector<string>& pathSplit, char splitChar) {
  int size = path.size();
  int pst = 0, count = 0;
  while(pst < size) {
    // cout << pst << " " << count << endl;
    //用来初始的
    if(path[pst] == '/') {
      ++pst;
      count = 0;
    } else {
      if(pst + count == size - 1 || path[pst+count+1] == '/') {
        cout << pst << " " << count << endl;
        pathSplit.push_back(path.substr(pst, count+1));
        pst = pst + count + 1;
        count = 0;
      } else {
        ++count;
      }
    }
  }
}

string simplifyPath(string path) {
  vector<string> pathSplit;
  split(path, pathSplit, '/');
  print(pathSplit);
  vector<string> rsl;

  int size = pathSplit.size();
  for(int i = 0; i < size; i++) {
    if(pathSplit[i] == ".") {
      continue;
    } else if(pathSplit[i] == "..") {
      if(rsl.size() > 0)
        rsl.erase(rsl.begin()+i);
    } else {
      rsl.push_back(pathSplit[i]);
    }
  }
  size = rsl.size();
  string strRsl;
  for(int i = 0; i < size; i++) {
    strRsl += "/";
    strRsl += rsl[i];
  }
  return strRsl == "" ? "/" : strRsl;
}

int main() {
  string str;
  cin >> str;
  cout <<simplifyPath(str) << endl;
}
