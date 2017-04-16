//数字转字符串
#include <sstream>
void print() {
  stringstream ss_rsl;
  string rsl;
  for(int i = 100; i >= 0; i--) {
    if(vals[i] == 1) {
      ss_rsl << i << " ";
    }
  }
  rsl = ss_rsl.str();
  cout << rsl.substr(0, rsl.length()-1) << endl;
}

//byte转换为char的代码
char c = (char) (b & 0xff) //这个主要是用于补码的问题；