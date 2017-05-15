//解决最长递增子串的问题，分为两种， 一种是连续的串，一种是非连续的串

//c[i]表示第i个位置的最长递增子串的长度，则有c[i] = max({c[j], j<i&&a[i]>=a[j]}) + 1;
#include <iostream>

using namespace std;

void printIncreasingSubstrNotContinue(int *a, int size) {
  int c[size];
  int max, index, temp;
  for(int i = 0; i < size; i++) {
    c[i] = 0;
  }
  for(int i = 0; i < size; i++) {
    max = c[i];
    for(int j = i-1; j >= 0; j--) {
      if(a[i] >= a[j] && c[j] >= max) {
        max = c[j];
      }
    }
    c[i] = max + 1;
  }
  for(int i = 0; i < size; i++) {
    cout << c[i] << " ";
  }
  cout << endl;

  //逆序打印
  max = 0;
  index = 0;
  for(int i = 0; i < size; i++) {
    if(c[i] > max) {
      max = c[i];
      index = i;
    }
  }

  //好像temp是不必须的，先放着吧
  temp = c[index];
  while(index >= 0) {
    if(c[index] == max && c[index] <= temp) {
      cout << a[index] << " ";
      max = max - 1;
      temp = a[index]; //记录下上一次打印的数字,保证是单调的
    }
    index = index - 1;
  }
  cout << endl;
}

void printIncreasingSubstrContinue(int a[], int size) {
  int c[size];
  int max, index, temp;
  for(int i = 0; i < size; i++) {
    c[i] = 0;
  }
  for(int i = 0; i < size; i++) {
    max = c[i];
    temp = a[i]; //temp用于约束是连续的串
    for(int j = i - 1; j >= 0; j--) {
      if(temp < a[j]) {
        break;
      }
      if(a[i] >= a[j] && c[j] >= max) {
        max = c[j];
        temp = a[j];
      }
    }
    c[i] = max + 1;
  }

  for(int i = 0; i < size; i++) {
    cout << c[i] << " ";
  }
  cout << endl;
  //逆序打印
  max = 0;
  for(int i = 0; i < size; i++) {
    if(c[i] > max) {
      max = c[i];
      index = i;
    }
  }
  temp = a[index];
  while(index >= 0) {
    if(max == c[index] && c[index] <= temp) {
      cout << a[index] << " ";
      max = max - 1;
      temp = a[index];
    }
    index = index - 1;
  }
  cout << endl;
}

int main() {
  // int a[] = {1, 7, 8, 3, 4, 5, 6, 6, 4, 3, 7};
  int a[] = {6, 9, 10, 2, 11, 3, 5, 12, 7, 13};
  int size = 10;
  printIncreasingSubstrNotContinue(a, size);
  printIncreasingSubstrContinue(a, size);
}
