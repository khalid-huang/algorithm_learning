#include <iostream>
#include <vector>
#include <map>

using namespace std;

class MagicDictionary {
private:
  map<int, std::vector<string> > mymap;

public:
  MagicDictionary() {
  }

  void buildDict(std::vector<string>& dict) {
    int size = dict.size(), len;
    for(int i = 0; i < size; i++) {
      len = dict[i].size();
      if(mymap.find(len) != mymap.end()) {
        mymap[len].push_back(dict[i]);
      } else {
        mymap[len] = std::vector<string>(0);
        mymap[len].push_back(dict[i]);
      }
    }
  }

  bool search(string word) {
    int size1 = word.size();
    if(mymap.find(size1) == mymap.end()) {
      return false;
    }
    std::vector<string> tempV = mymap[size1];
    int size2 = tempV.size(), count = 0;
    for(int i = 0; i < size2; i++) {
      count = 0;
      for(int j = 0; j < size1; j++) {
        if(word[j] != tempV[i][j]) {
          ++count;
        }
        if(count > 1) {
          break;
        }
      }
      if(count == 1) {
        break;
      }
    }
    if(count == 1) {
      return true;
    } else {
      return false;
    }
  }

};

int main() {
  MagicDictionary md;
  std::vector<string> v;
  v.push_back("hello");
  v.push_back("leetcode");
  md.buildDict(v);
  cout << "kk" << endl;
  cout << md.search("hello") << endl;
  cout << md.search("hhllo") << endl;
}
