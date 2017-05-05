#include <iostream>
#include <sstream>
using namespace std;

int gcd(int a, int b) {
  int temp;
  while(b != 1) {
    temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

void analyze(string str, int& symbol, int& molecule, int& denominator) {
  if(str[0] == '-') {
    symbol = -1;
  }

  int cur = symbol == 1 ? 0 : 1;
  while(str[cur] != '/') {
    molecule = molecule * 10 + (str[cur] - '0');
    ++cur;
  }

  cur = cur + 1;
  size_t size = str.size();
  while(cur != size) {
    denominator = denominator * 10 + (str[cur] - '0');
    ++cur;
  }

  int temp = gcd(molecule, denominator);
  molecule = molecule / temp;
  denominator = denominator / temp;
}

string simplify(string str) {
  //简化，如果有负号的话，还要加上括号

  int symbol = 1;
  int denominator = 0;
  int molecule = 0;
  analyse(str, symbol, molecule, denominator);

  if(molecule == 0) {
    return "0";
  }

  stringstream ss;
  if(symbol == -1) {
    ss << "(-";
  }
  ss << molecule;
  if(denominator != 1) {
    ss << denominator;
  }
  if(symbol == -1) {
    ss << ")";
  }
  return ss.str();
}

string simplify1(string str) {
  int symbol = 1;
  int denominator = 0;
  int molecule = 0;
  analyse(str, symbol, molecule, denominator);

  int intergerPart = molecule / denominator;
  molecule = molecule % denominator;

  stringstream ss;
  if(symbol == -1) {
    ss << "(-";
  }
  if(intergerPart != 0) {
    ss << intergerPart << " ";
  }
  ss << molecule << "/" << denominator;
  if(symbol == -1) {
    ss << ")";
  }
  return ss.str();
}

string add(string v1, string v2) {
  
}

void arithmetic(string v1, v2) {
  //加法
  cout << v1 << " + " << v2  << " = " << simplify1(add(v1, v2)) << endl;
  cout << v1 << " - " << v2  << " = " << simplify1(subtract(v1, v2)) << endl;
  cout << v1 << " * " << v2  << " = " << simplify1(mul(v1, v2)) << endl;
  cout << v1 << " / " << v2  << " = " << simplify1(divide(v1, v2)) << endl;
}

int main() {
  string v1, v2;
  cin >> v1 >> v2;
  v1 = simplify(v1);
  v2 = simplify(v2)
  arithmetic(v1, v2);
}
