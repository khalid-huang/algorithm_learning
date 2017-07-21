// 找出数组里面的第k个最小的值，可以使用快速排序和堆排
//利用快速排序可以参考http://blog.csdn.net/abc7845129630/article/details/51087299
//利用堆排序可以的思想就是建立一个k个元素的最大堆，维护这个堆，然后在交换数据那一步（对应到原本的算法就是把最大数放到堆的最后，然后把堆的大小减1那一步）从剩下的size - k个数据里面，遍历一次，每个数都与堆顶比较，如果比堆顶还要小的话，就交换（比最大的数小，就可以把最大的数换出去了，这就是思想，参考http://www.cnblogs.com/walker-lee/p/5814505.html）
#include <iostream>

using namespace std;

int quickSort(int *a, int down, int up, int k) {
  int tmp = a[down];
  int i = down, j = up;
  while(i < j) {
    while(i < j && tmp <= a[j]) { //等于也要在这边
      j--;
    }
    if(i < j) {
      a[i++] = a[j];
    }

    while(i < j && tmp > a[i]) {
      i++;
    }
    if(i < j) {
      a[j--] = a[i];
    }
  }
  a[i] = tmp;
  if(i+1 == k) {
    return tmp;
  } else if(i+1 > k) {
    return quickSort(a, down, i-1, k);
  } else {
    return quickSort(a, i+1, up, k);
  }
}

//保证数据有效，k在范围内
int getKmin(int *a, int size, int k) {
  return quickSort(a, 0, size - 1, k);
}



int main() {
  int a[] = {1,5,2,6,0,8,6};
  int length = 7;
  int k ;
  cin >> k;
  int kMin = getKmin(a, length, k);
  cout << kMin << endl;
}
