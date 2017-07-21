// http://blog.csdn.net/xiaoxiaoxuewen/article/details/7570621/
#include <iostream>

using namespace std;

//从i开始，调整一个size大小的堆
void adjustHeap(int* a, int i, int size) {
  int lchild = i * 2;
  int rchild = i * 2 + 1;
  int max = i;
  if(i <= size/2) { //只针对非叶子结点进行调整
    if(lchild <= size && a[lchild]>a[max]) {
      max = lchild;
    }
    if(rchild <= size && a[rchild] > a[max]) {
      max = rchild;
    }
    if(max != i) {
      swap(a[i], a[max]);
      adjustHeap(a, max, size);
    }
  }
}

void buildHeap(int *a, int size) {
  //从非叶子结点开始调整堆
  for(int i = size / 2;i >= 1; i--) {
    adjustHeap(a, i, size);
  }
}

void heapSort(int* a, int size) {
  buildHeap(a, size);
  for(int i = size; i >= 1; i--) {
    swap(a[1], a[i]);
    adjustHeap(a, 1, i-1);
  }
}

int main() {
  int a[] = {0,1,3,5,2,6};
  int size = 5;
  heapsort(a, size);
  for(int i = 0; i < size; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}
