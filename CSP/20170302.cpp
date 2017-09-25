#include <iostream>
#include <vector>


using namespace std;

void print(std::vector<int>& students) {
  int size = students.size();
  for(int i = 0; i < size - 1; i++) {
    cout << students[i] << " ";
  }
  cout << students[size -1] << endl;
}

int main() {
  int n;
  cin >> n;
  std::vector<int> students(n);
  for(int i = 1; i <= n; i++) {
    students[i-1] = i;;
  }

  int m, p, q, s_pos, t_pos;
  cin >> m;
  while(m--) {
    cin >> p >> q;
    for(int i = 0; i < n; i++) {
      if(students[i] == p) {
        s_pos = i;
        break;
      }
    }
    // cout << "kaka" << endl;
    t_pos = s_pos + q;
    if(q > 0) {
      for(int i = s_pos ; i < t_pos; i++) {
        students[i] = students[i+1];
      }
    } else {
      for(int i = s_pos; i > t_pos; i--) {
        students[i] = students[i-1];
      }
    }
    // cout << "kaka" << endl;
    students[t_pos] = p;
    // print(students);
  }
  print(students);
  return 0;
}
