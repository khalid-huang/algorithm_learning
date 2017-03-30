#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

struct Room{
  double J;
  double F;
  double rate;
  Room(double j, double f, double r) {
    J = j;
    F = f;
    rate = r;
  }
  Room() {}
};

void getInputs(std::vector<Room>& warehouses, int n, double& given) {
  warehouses.clear();
  double J, F;
  double rate;
  while(n--) {
    cin >> J >> F;
    if(F != 0) {
      rate =  J / F;
      warehouses.push_back(Room(J, F, rate));
    } else {
      given += J;
    }
  }
}

void sortWarehouse(std::vector<Room>& warehouses) {
  int wSize = warehouses.size();
  int i, j;
  Room temp;
  for(i = 1; i < wSize; i++) {
    for(j = 0; j < wSize - i; j++) {
      if(warehouses[j].rate < warehouses[j+1].rate) {
        temp = warehouses[j];
        warehouses[j] = warehouses[j+1];
        warehouses[j+1] = temp;
      }
    }
  }
}

void printWarehouse(std::vector<Room> warehouses) {
  int wSize = warehouses.size();
  for (int i = 0; i < wSize; i++) {
    cout << warehouses[i].J << "  " << warehouses[i].F << "  " << warehouses[i].rate << endl;
  }
}

double getMaxBeans(std::vector<Room>& warehouses, double m) {
  sortWarehouse(warehouses);

  int wSize = warehouses.size();
  // for test
  // printWarehouse(warehouses);

  double rsl = 0;
  for(int i = 0; i < wSize; i++) {
    if(m > warehouses[i].F) {
      rsl += warehouses[i].J;
      m -= warehouses[i].F;
    } else {
      // cout << warehouses[i].rate;
      rsl += m * warehouses[i].J / warehouses[i].F;
      m = 0;
      break;
    }
  }
  return rsl;
}

int main() {
  int n;
  double m;
  double rsl;
  std::vector<Room> warehouses;
  while(cin >> m >> n) {
    if(m == -1 && n == -1) {
      break;
    } else {
      double given = 0;
      getInputs(warehouses, n, given);
      rsl = getMaxBeans(warehouses, m);
      rsl += given;
      cout << fixed << setprecision(3) << rsl << endl;
    }
  }
}
