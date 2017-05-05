#include <iostream>
#include <map>

using namespace std;

struct Info {
  string ticketNum;
  int examSeatNum;
};

std::map<int, Info> student;

int main() {
  int N;
  cin >> N;

  string ticketNum;
  int examSeatNum, testSeatNum;
  while(N--) {
    cin >> ticketNum >> testSeatNum >> examSeatNum;
    Info student_info = {ticketNum, examSeatNum};
    student[testSeatNum] = student_info;
  }

  cin >> N;
  while(N--) {
    cin >> testSeatNum;
    cout << student[testSeatNum].ticketNum << " " << student[testSeatNum].examSeatNum << endl;
  }
}
