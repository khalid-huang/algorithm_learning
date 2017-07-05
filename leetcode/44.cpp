#include <iostream>
#include <string>

using namespace std;

//超时了
// bool isMatch1(string s, string p) {
//   // cout << s << " " << p << endl;
//   if(p.empty()) {
//     return s.empty();
//   }
//
//   if(p[0] == '*') {
//     if(p.size() > 2 && p[1] == '*') {
//         return isMatch(s, p.substr(1));
//     } else {
//       return isMatch(s, p.substr(1)) || (!s.empty() && isMatch(s.substr(1), p));
//     }
//   } else {
//     return !s.empty() && (s[0] == p[0] || '?' == p[0]) && isMatch(s.substr(1), p.substr(1));
//   }
// }


//实在是没有搞懂，多了一个ss_index到底有什么用; 其实ss_index应该是用来使s_index实现预看功能的，但还是觉得好难想这种方式，就是保证像*a和aaaa来使*看看可以吃多少，每吃一个应该要保证*后面的可以和*要吃的字母后面的字母一样;可以吃的话，就再把p_inedex拉回来，继续测
bool isMatch(string s, string p) {
  int s_index = 0, p_index = 0, star_index = -1, ss_index = 0;
  int s_size = s.size(), p_size = p.size();
  while(s_index < s_size) {
    if(p_index < p_size && (p[p_index] == '?' ||p[p_index] == s[s_index])) {
      // cout << p_index << " " << p_size << endl;
      ++s_index;
      ++p_index;
      cout << "1" << endl;
      continue;
    }
    //标记，但不前进，因为可能可以不前进
    if(p_index < p_size && p[p_index] == '*') {
      star_index = p_index++;
      // ss_index = s_index;
      cout << "2" << endl;
      continue;
    }
    if(star_index != -1 && star_index < p_size) {
      p_index = star_index + 1;
      // s_index = ++ss_index;
      ++s_index;
      cout << "3" << endl;
      continue;
    }
    return false;
  }
  while(p_index < p_size && p[p_index] == '*') {
    p_index++;
  }
  return p_index == p_size;
}

int main() {
  string s, p;
  cin >> s >> p;
  cout << isMatch(s, p) << endl;
}
