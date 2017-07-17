#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
  int start;
  int end;
  // Inerval(): start(0), end(0) {}
  Interval(int s, int e): start(s), end(e) {}
};

void print(std::vector<Interval> Intervals) {
  int size = Intervals.size();
  for(int i = 0; i < size; i++) {
    cout << "[ " << Intervals[i].start << "," << Intervals[i].end << "]" << ",";
  }
  cout << endl;
}

bool cmp(Interval& i1, Interval& i2) {
  return i1.start < i2.start;
}

std::vector<Interval> merge(vector<Interval>& Intervals) {
  std::vector<Interval> rsl;
  int size = Intervals.size();
  if(size == 0) {
    return rsl;
  }

  sort(Intervals.begin(), Intervals.end(), cmp); //通过排序防止断层的出现; 同时可以实现一直一次性拼接
  rsl.push_back(Intervals[0]);
  //用的是vector.back,不是end
  for(int i = 1; i < size; i++) {
    if(Intervals[i].start < rsl.back().end && Intervals[i].end > rsl.back().end) {
      rsl.back().end = Intervals[i].end;
    } else if(Intervals[i].start > rsl.end()->end) {
      rsl.push_back(Intervals[i]);
    }
  }
  return rsl;
}

int main() {

}
