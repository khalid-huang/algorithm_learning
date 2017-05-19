//解决最长递增子串的问题，分为两种， 一种是连续的串，一种是非连续的串

//c[i]表示第i个位置的最长递增子串的长度，则有c[i] = max({c[j], j<i&&a[i]>=a[j]}) + 1;
#include <iostream>

using namespace std;

//自己实现的动态规划法，与http://blog.csdn.net/sgbfblog/article/details/7798737 里面的解法二是一样的思路
//O(N^2)
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
//自己实现的
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

//参考 http://blog.csdn.net/sgbfblog/article/details/7798737
//O(NlgN),但是只可以得到长度，不能得到对应的序列内容
//返回在数组a中第一个比w要大的位置
int binarySearch(int *a, int size, int w) {
  int left = 0, right = size, middle; //左闭右开的区间
  while(left < right) {
    middle = left + (right - left) / 2;
    if(a[middle] > w) {
      right = middle;
    } else if(a[middle] < w) {
      left = middle + 1;
    } else {
      return middle; //找到了就直接返回
    }
  }
  //如果里面没有这个元素的话，我们就返回left的位置，这个就是数组里面第一个比w大的元素的位置
  return left;
}

void get_LIS(int *a, int size) {
  int B[size];
  int cur = 1, pos;
  B[cur] = a[0];
  for(int i = 1; i < size; i++) {
    if(a[i] > B[cur]) {
      B[++cur] = a[i];
    } else {
      pos = binarySearch(B, cur, a[i]);
      B[pos] = a[i];
    }
  }

  for(int i = 1; i < cur + 1; i++) {
    cout << "B[" << i << "] = " << B[i] << endl;
  }
  cout << "最长递增子序列长度为" << cur+1 << endl;
}

int main() {
  // int a[] = {1, 7, 8, 3, 4, 5, 6, 6, 4, 3, 7};
  // int a[] = {6, 9, 10, 2, 11, 3, 5, 12, 7, 13};
  int a[] = {2, 1, 6, 3, 5, 4, 8, 7, 9};
  int size = 9;
  // printIncreasingSubstrNotContinue(a, size);
  // printIncreasingSubstrContinue(a, size);
  get_LIS(a, size);
}
