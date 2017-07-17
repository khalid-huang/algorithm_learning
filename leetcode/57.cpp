#include <iostream>
#include <vector>

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

vector<Interval> insert(std::vector<Interval>& intervals, Interval newInterval) {
  int size = intervals.size();
  std::vector<Interval> rsl;
  int i, flag = 0;
  for(i = 0; i < size; i++) {
    if(intervals[i].end < newInterval.start) {
      rsl.push_back(intervals[i]);
    } else if(intervals[i].start > newInterval.end) {
      flag = 1;
      rsl.push_back(newInterval);
      break;
    } else {
        newInterval.start = min(newInterval.start, intervals[i].start);
        newInterval.end  = max(newInterval.end, intervals[i].end);
    }
  }
  if(flag == 0) {
    rsl.push_back(newInterval);
  }
  for(; i < size; i++) {
    rsl.push_back(intervals[i]);
  }
  return rsl;
}

int main() {
  Interval i1(1,3);
  Interval i2(5, 9);
  std::vector<Interval> intervals;
  intervals.push_back(i1);
  intervals.push_back(i2);

  Interval i3(2, 5);
  print(insert(intervals, i3));
}
