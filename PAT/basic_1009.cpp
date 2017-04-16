#include <iostream>
#include <vector>
#include <string>
using namespace std;

std::vector<string> container;

void print_word() {
  int size = container.size();
  for(int i = size - 1; i > 0; i--) {
    cout << container[i] << " ";
  }
  cout << container[0] << endl;
}

int main() {
  string sentence;
  while(cin.get() != '\n') {
    cin.unget();
    cin >> sentence;
    container.push_back(sentence);
  }
  print_word();
}
