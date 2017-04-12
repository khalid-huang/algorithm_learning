#include <iostream>
using namespace std;

int main() {
  int max_grade = -1, min_grade = 101;
  string max_grade_name, max_grade_number;
  string min_grade_name, min_grade_number;

  int t, grade;
  string name, number;
  cin >> t;

  while(t--) {
    cin >> name >> number >> grade;
    if(grade > max_grade) {
      max_grade = grade;
      max_grade_name = name;
      max_grade_number = number;
    }
    if(grade < min_grade) {
      min_grade = grade;
      min_grade_name = name;
      min_grade_number = number;
    }
    // cout << max_grade << " " << min_grade << endl;
  }
  cout << max_grade_name << " " << max_grade_number << endl;
  cout << min_grade_name << " " << min_grade_number << endl;
}
