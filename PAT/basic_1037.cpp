#include <iostream>
#include <sstream>

using namespace std;

long str2int(string str) {
  long val = 0;
  size_t size = str.size();
  for(int i = 0; i < size; i++) {
    val = val * 10 + (str[i] - '0');
  }
  return val;
}

void analyse(string str, long& Gallen, long& Sickle, long& Krut) {
  size_t size = str.size();
  string temp[3];
  for(int i = 0, j = 0; i < size; i++) {
    if(str[i] != '.') {
      temp[j] += str[i];
    } else {
      ++j;
    }
  }
  Gallen = str2int(temp[0]);
  Sickle = str2int(temp[1]);
  Krut = str2int(temp[2]);
}

int transform(string str) {
  long Gallen, Sickle, Krut;
  analyse(str, Gallen, Sickle, Krut);
  Krut = Gallen * 17 * 29 + Sickle * 29 + Krut;
  return Krut;
}

string transform_back(long Krut) {
  int symbol = Krut < 0 ? -1 : 1;
  Krut = Krut < 0 ? -Krut : Krut;

  long Sickle = Krut / 29;
  Krut = Krut % 29;

  long Gallen = Sickle / 17;
  Sickle = Sickle % 17;

  stringstream ss;
  if(symbol == -1) {
    ss << "-";
  }
  ss << Gallen << "." << Sickle << "." << Krut;
  return ss.str();
}

int main() {
  string P, A;
  cin >> P >> A;

  long KP = transform(P);
  long KA = transform(A);

  long diff = KA - KP;

  string rsl = transform_back(diff);

  cout << rsl << endl;
}
