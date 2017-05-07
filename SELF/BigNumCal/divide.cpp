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

//高精度减法，但是v1一定会大于v2
string substract(string v1, string v2) {
  size_t size1 = v1.size();
  size_t size2 = v2.size();
  string rsl;
  int temp;
  int carry = 0;
  //逐位减
  for(int i = 1; i <= size2; i++) {
    temp = char2int(v1[size1 - i]) - char2int(v2[size2 - i]) - carry;
    if(temp < 0) {
      carry = 1;
      temp += 10;
    } else {
      carry = 0;
    }
    rsl = int2char(temp) + rsl;
  }

  //剩下的多余位数
  for(int i = size2 + 1; i <= size1; i++) {
    temp = char2int(v1[size1 - i]) - carry;
    if(temp < 0) {
      carry = 1;
      temp += 10;
    } else {
      carry = 0;
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
  string rsl, base_temp, v2_temp, v1_temp, remain = "0";
  int rate, diff, len;
  int flag = 0, flag1 = 0, zeroNum = 0, remain_num = 0;
  while(v1 != "0") {
    cout << "v1-v2: " << v1 << " " << v2 << endl;
    //相等情况，直接给1,结束
    if(cmp(v1, v2) == 0) {
      rsl = rsl + "1";
      break;
    }
    //最后一步的补0；已经没有办法再做减法，就直接补0,补0这里要结合remain_num来，它表示在竖式除法里，前面的除法剩下的数字位数；计算的方式是减法的结束减去base_temp里面增加的0的个数；
    if(cmp(v1, v2) < 0) {
      len = remain_num+1;
      size1 = v1.size();
      for(int i = remain_num + 1; i <= size1; i++) {
        rsl += "0";
      }
      remain = v1;
      v1 = "0";
      break;
    }

    //获取减法的基数
    base_temp = getBase(v1, v2);
    zeroNum = base_temp.size() - v2.size();

    cout << v1 << "-" << v2 << " bt:" << base_temp << endl;
    //试减
    rate = 9;
    v2_temp = mul(base_temp, int2str(rate));
    while(cmp(v2_temp, v1) > 0 ) {
      --rate;
      v2_temp = mul(base_temp, int2str(rate));
    }
    cout << v2 << "-" << v1 << "-" << rate << ": " << v2_temp << endl;
    //过程中商补0; 需要先判断是不是第一位开始;同时因为一开始已经进行v1与v2的判断，可以判断出这里一定是可以成功减法的；
    cout << "base_temp " << base_temp << endl;
    if(rsl.size() != 0) {
      cout << "remainNum " << remain_num << endl;
      len = remain_num+1;
      while(len < v1.size() + 1 && cmp(v1.substr(0, len), v2) < 0) {
        cout << "zero: " << v1.substr(0, len) << "-" << v2 << endl;
        rsl = rsl + "0";
        len++;
      }
    }

    v1_temp = substract(v1, v2_temp);
    cout << "subrsl: " << v1 << "-" << v2_temp << "=" << v1_temp << endl;
    remain_num   = v1_temp.size() - zeroNum;
    diff = v1.size() - v1_temp.size();
    // cout << "size:" << v1.size() << " " << v1_temp.size() << endl;
    cout << diff << endl;
    //写入商
    rsl = rsl + int2char(rate);
    v1 = v1_temp;
    cout << "rate:" << rate << endl;

  }
  rsl = delPreZero(rsl);
  //综合结果
  return rsl + "......" + remain;
  // return rsl;
}

int main() {
  string v1, v2;
  cin >> v1 >> v2;
  // cout << substract(v1, v2) << endl;
  // cout << "sub" << endl;
  // cout << getBase(v1, v2) << endl;
  cout << divide(v1, v2) << endl;
}
