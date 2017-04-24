#include <iostream>
#include <string>
using namespace std;

string startDay = "1814/09/06";
string endDay = "2014/09/06";

bool isValid(string birthday) {
  if(birthday >= startDay && birthday <= endDay) {
    return true;
  }
  return false;
}

bool isOlder(string birthday, string other_birthday) {
  if(birthday < other_birthday) {
    return true;
  }
  return false;
}

bool isYounger(string birthday, string other_birthday) {
  if(birthday > other_birthday) {
    return true;
  }
  return false;
}

int main() {
  int N;
  cin >> N;

  string name, birthday;
  int validNum = 0;
  string oldestName, oldestBirthday, youngestName, youngestBirthday;

  while(N--) {
    cin >> name >> birthday;
    if(!isValid(birthday)) {
      continue;
    }

    ++validNum;
    if(oldestName.size() == 0 || isOlder(birthday, oldestBirthday)) {
      oldestName = name;
      oldestBirthday = birthday;
    }
    if(youngestName.size() == 0 || isYounger(birthday, youngestBirthday)) {
      youngestName = name;
      youngestBirthday = birthday;
    }
  }
  if(validNum != 0) {
    cout << validNum << " " << oldestName << " " << youngestName << endl;
  } else {
    cout << validNum << endl;
  }
}
