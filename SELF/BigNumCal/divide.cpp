//思路是用试减法；比如7234 / 23的话，先因为它们相差两位，所以呢23 * 100为基位，看看可以减去几个这样的基位，方法是从9到1去试，这样可以得到商和余数；
//需要实现高精度的减法,乘法；
#include <iostream>

using namespace std;

//v1 >= v2 返回 1; 相等返回0；小于返回-1
int cmp(string v1, string v2) {
  // cout << "cmp " << v1 << " " << v2 << endl;
  if(v1.compare(v2) == 0) {
    return 0;
  }

  size_t size1 = v1.size();
  size_t size2 = v2.size();
  if((size1 > size2) || (size1 == size2 && v1.compare(v2) > 0)) {
    return 1;
  }

  return -1;
}

int char2int(char c) {
  return c - '0';
}

char int2char(int v) {
  return v + '0';
}

string int2str(int v) {
  string str;
  str += (char)(v+ '0');
  return str;
}

string delPreZero(string str) {
  int index = 0;
  while(str[index] == '0') {
    index++;
  }
  return str.substr(index);
}

//多位与一位的乘法
string mul(string v1, string v2) {
  // cout << "mul:" << v1 << " " << v2 << endl;
  string rsl;
  size_t size = v1.size();

  int carry = 0;
  int temp;
  for(int i = size - 1; i >= 0; i--) {
    temp = char2int(v1[i]) * char2int(v2[0]) + carry;
    // cout << temp << endl;
    carry = temp / 10;
    rsl = int2char(temp % 10) + rsl;
  }
  if(carry != 0) {
    rsl = int2char(carry) + rsl;
  }
  return rsl;
}

//高精度减法，但是v1一定会大于v2，而且它们的位数是一样的
string substract(string v1, string v2) {
  size_t size = v1.size();
  string rsl;
  int temp;
  int carry = 0;
  for(int i = size - 1; i >= 0; i--) {
    temp = char2int(v1[i]) - char2int(v2[i]) - carry;
    if(temp < 0) {
      carry = 1;
      temp += 10;
    }
    rsl = int2char(temp) + rsl;
  }
  int index = 0;
  while(rsl[index] == '0') {
    index++;
  }
  rsl = delPreZero(rsl);
  // cout << index << endl;
  return rsl.size() == 0 ? "0" : rsl;
}

//得到每次运算的基数，比如1234和23,它的基数应该是230; 而5432和32它的基数应该是2300；
string getBase(string v1, string v2) {
  size_t size1 = v1.size();
  size_t size2 = v2.size();
  int diff = size1 - size2;
  while(diff--) {
    v2 += "0";
  }
  if(cmp(v2, v1) <= 0) {
    return v2;
  } else {
    return v2.substr(0,v2.size()-1);
  }
}

string divide(string v1, string v2) {
  if(cmp(v1, v2) < 0) {
    return "0";
  }
  if(cmp(v1, v2) == 0) {
    return "1";
  }

  size_t size1, size2;
  string rsl, base_temp, v2_temp, v1_temp;
  int rate, diff;
  int flag = 0;
  while(cmp(v1, v2) >= 0 ) {
    if(v1 == v2) {
      rsl = rsl + "1";
      break;
    }

    base_temp = getBase(v1, v2);

    cout << v1 << "-" << v2 << " bt:" << base_temp << endl;
    //试减
    rate = 9;
    v2_temp = mul(base_temp, int2str(rate));
    cout << "temp" << v2_temp << endl;
    while(cmp(v2_temp, v1) > 0) {
      --rate;
      v2_temp = mul(base_temp, int2str(rate));
      cout << v2 << "-" << v1 << "-" << rate << ": " << v2_temp << endl;
      flag++;
      // if(flag == 10) {
      //   break;
      // }
    }

    cout << v1 << "-" << v2_temp << endl;
    v1_temp = substract(v1, v2_temp);
    diff = v1.size() - v1_temp.size();
    cout << "size:" << v1.size() << " " << v1_temp.size() << endl;
    cout << diff << endl;
    //写入商
    rsl = rsl + int2char(rate);
    //补0
    while(diff != 1) {
      diff--;
      rsl = rsl + "0";
    }
    v1 = v1_temp;
    cout << ":" << v1 << endl;
    // if(flag == 10) {
    //   break;
    // }
  }
  rsl = delPreZero(rsl);
  return rsl;
}

int main() {
  string v1, v2;
  cin >> v1 >> v2;
  // cout << substract(v1, v2) << endl;
  // cout << getBase(v1, v2) << endl;
  cout << divide(v1, v2) << endl;
}
