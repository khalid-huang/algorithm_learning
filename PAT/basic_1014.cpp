#include <iostream>
#include <string>
using namespace std;

string week[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

void parse_week(char c) {
  int index = c - 'A';
  cout << week[index];
}

void parse_hour(char c) {
  if(c >= '0' && c <= '9') {
    cout << (c - '0');
  } else if(c >= 'A' && c <= 'N') {
    int hour = 10 + c - 'A';
    cout << hour;
  } else if(c >= 'a' && c <= 'n') {
    int hour = 10 + c - 'a';
    cout << hour;
  }
}

void parse_minute(int index) {
  if(index >= 0 && index <= 9) {
    cout << "0" << index;
  } else {
    cout << index;
  }
}

void parse(char week, char hour, int index) {
  parse_week(week);
  cout << " ";
  parse_hour(hour);
  cout << ":";
  parse_minute(index);
  cout << endl;
}

int main() {
  string s1, s2, s3, s4;
  char week = ' ', hour = ' ';
  int index = 0;
  cin >> s1 >> s2 >> s3 >> s4;
  size_t s1_size = s1.size();
  size_t s2_size = s2.size();
  size_t s3_size = s3.size();
  size_t s4_size = s4.size();
  size_t min_size_1 = s1_size < s2_size ? s1_size : s2_size;
  size_t min_size_2 = s3_size < s4_size ? s3_size : s4_size;

  for(int i = 0; i < min_size_1; i++) {
    if(week == ' ') {
      if(s1[i] == s2[i] && s1[i] >= 'A' && s1[i] <= 'G') {
        week = s1[i];
      }
    } else if(hour == ' ') {
      if(s1[i] == s2[i] && ((s1[i] >= 'A' && s1[i] <= 'N') || (s1[i] >= 'a' && s1[i] <= 'n'))) {
        hour = s1[i];
      }
    } else {
      break;
    }
  }
  for(int i = 0; i < min_size_2; i++) {
    // cout << s3[i] << " " << s4[i] << endl;
    if(s3[i] == s4[i] && ((s3[i] >= 'A' && s3[i] <= 'Z') || (s3[i] >= 'a' && s3[i] <= 'z'))) {
      index = i;
      break;
    }
  }
  // cout << codes[0] << " " <<  codes[1] << " " << index << endl;
  parse(week, hour, index);

}
