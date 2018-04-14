//参考：http://blog.csdn.net/xiaoxiaoxuewen/article/details/7570621/
//可以快速得到前k个最大的或是最小 的
#include <iostream>
using namespace std;

void print_arr(int* arr, int size)
{
	for(int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

//保持从start开始的部分保持堆的性质
void heap_adjust(int* arr, int start, int size) {
	int lchild = 2 * start + 1;
	int rchild = 2 * start + 2;
	int max_index = start;
	if(start < size / 2)  {// 非叶子结点
		if(lchild < size && arr[lchild] > arr[max_index])
			max_index = lchild;
		if(rchild < size && arr[rchild] > arr[max_index])
			max_index = rchild;
		if(max_index != start) {
			swap(arr[max_index], arr[start]);
			heap_adjust(arr,max_index,size);
		}
	}
}

//从下而上遍历所有的非叶子结点就可以了
void build_heap(int* arr, int size) {
	for(int i = size / 2 - 1; i >= 0; i--) {
		heap_adjust(arr, i, size);
	}
}

//先建立堆，然后一个个的交换出最大值
void heap_sort(int* arr, int size)
{
	build_heap(arr, size);
	for(int i = size-1; i >= 0; i--) {
		swap(arr[i], arr[0]);
		heap_adjust(arr, 0, i); //
	}
}

void get_heap_sort(int* arr, int size)
{
	heap_sort(arr, size);
}

void heap_sort_vary(int* arr, int size, int k, int* ans) {
	build_heap(arr, size);
	int nums = 0;
	for(int i = size-1; i >= 0; i--) {
		if(nums != k) {
			ans[nums++] = arr[0];
			swap(arr[i], arr[0]);
			heap_adjust(arr, 0, i-1);
		} else {
			break;
		}
	}	
}

void get_k_max_nums(int *arr, int size, int k, int* ans)
{
	heap_sort_vary(arr, size, k, ans);
}

int main()
{
	int arr[] = {1,5,2,5,6,3};
	int size =  sizeof(arr) / sizeof(arr[0]);
	get_heap_sort(arr, size);
	print_arr(arr, size);
	//返回最4个最大的；
	// int k = 4;
	// int ans[k];
	// get_k_max_nums(arr, size, k ,ans);
	// print_arr(ans, k);
}