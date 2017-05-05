#include <iostream>
#include <map>

using namespace std;

std::map<char, int> charNum;

void analyse(string sentence) {
  size_t size = sentence.size();
  for(int i = 0; i < size; i++) {
    if((sentence[i] >= 'a' && sentence[i] <= 'z') || (sentence[i] >= 'A' && sentence[i] <= 'Z')) {
      if(sentence[i] <= 'Z' && sentence[i] >= 'A') {
        sentence[i] = sentence[i] + 32;
      }
      if(charNum.find(sentence[i]) != charNum.end()) {
        charNum[sentence[i]]++;
      } else {
        charNum[sentence[i]] = 1;
      }
    }
  }
}

void getRsl(char& rsl_char, int& rsl_int) {
  for(std::map<char, int>::iterator it = charNum.begin(); it != charNum.end(); ++it) {
    if(rsl_int < it->second) {
      rsl_char = it->first;
      rsl_int = it->second;
    } else if(rsl_int == it->second && rsl_char > it->first) {
      rsl_char = it->first;
      rsl_int = it->second;
    }
  }
}

int main() {
  string sentence;
  getline(cin, sentence);

  analyse(sentence);

  char rsl_char;
  int rsl_int;
  getRsl(rsl_char, rsl_int);
  cout << rsl_char << " " << rsl_int << endl;
}
