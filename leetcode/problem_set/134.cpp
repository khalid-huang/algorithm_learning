#include <iostream>
#include <vector>

using namespace std;

int canCOmpleeCircuit(std::vector<int>& gas, std::vector<int>& cost) {
  int start = gas.size() - 1, end = 0;
  int remain = gas[start] - cost[start];
  while(start > end) {
    if(remain >= 0) {
      remain += gas[end] - cost[end];
      ++end;
    } else {
      --start;
      remain += gas[start] - cost[start];
    }
  }
  return remain >= 0 ? start : -1; 
}

int main() {
  std::vector<int> gas;
  gas.push_back(1);
  gas.push_back(4);
  gas.push_back(5);
  std::vector<int> cost;
  cost.push_back(2);
  cost.push_back(2);
  cost.push_back(5);

  cout << canCOmpleeCircuit(gas, cost) << endl;
}
