#include <iostream>

using namespace std;

int binarySearchLoop(int array[], int value, int size) {
  int start = 0, end = size, middle;
  while(start <= end) {
    middle = start + (end - start) / 2;
    if(value < array[middle]) {
      end = middle -1;
    } else if(value > array[middle]) {
      start = middle + 1;
    } else {
      break;
    }
  }
  if(start > end) {
    cout << "没有找到对应的数字" << endl;
    middle = -1;
  }
  return middle;
}

int binarySearchRecursion(int array[], int value, int start, int end) {
  if(start > end) {
    cout << "没有找到对应的数字" << endl;
    return -1;
  }
  int middle = start + (end - start) / 2;
  if(array[middle] < value) {
    return binarySearchRecursion(array, value, middle+1, end);
  } else if(array[middle] > value) {
    return binarySearchRecursion(array, value, start, middle-1);
  } else {
    return middle;
  }
}

int main() {
    int array[100] = {1,3,5,7,8,10,13,16};
    int value = 16;
    cout << binarySearchLoop(array, value, 7) << endl;
    cout << binarySearchRecursion(array, value, 0, 7) << endl;
}
