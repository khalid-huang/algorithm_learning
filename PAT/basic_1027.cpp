#include <iostream>
using namespace std;

int line, remain;
char symbol;

void getLine(int stars) {
  line = 1;
  int cur = 1, newStar;
  while(true) {
    newStar = ((line + 1) * 2 - 1) * 2;
    if(cur + newStar > stars) {
      break;
    } else {
      line = line + 1;
      cur = cur + newStar;
    }
  }
  remain = stars - cur;
}

void printLine(int num, int length) {
  int space = (length - num) / 2;
  int space_start = space;
  int space_end = space;
  while(space_start--) {
    cout << " ";
  }
  while(num--) {
    cout << symbol;
  }
  // while(space_end--) {
  //   cout << " ";
  // }
}

void printStars() {
  int cur = line;
  int length = line * 2 - 1;
  int starNum;
  while(cur) {
    starNum = cur * 2 - 1;
    printLine(starNum, length);
    cout << endl;
    --cur;
  }
  cur = 2;
  while(cur <= line) {
    starNum = cur * 2 - 1;
    printLine(starNum,length);
    cout << endl;
    ++cur;
  }
}

int main() {
    int stars;
    cin >> stars >> symbol;

    int lines;
    getLine(stars);
    printStars();
    cout << remain << endl;
}
