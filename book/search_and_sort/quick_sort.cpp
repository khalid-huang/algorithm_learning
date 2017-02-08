#include <iostream>
using namespace std;

void print_arr(int* arr, int size)
{
	for(int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void quick_sort(int* arr, int start, int end) {
	if(end - start <= 1) 
		return;
	int obj = arr[start];
	int p = start, q = end-1;
	while(p < q) {
		while(q > p) {
			if(arr[q] < obj) {
				arr[p] = arr[q];
				break;
			}
			q--;
		}
		while(p < q) {
			if(arr[p] > obj) {
				arr[q] = arr[p];
				break;
			}
			p++;
		}
	}
	arr[q] = obj;
	cout << p << endl;
	//第q个是已经确定了的，所以不用参与排序
	quick_sort(arr, start, p); 
	quick_sort(arr, p+1, end);
}

void get_quick_sort(int* arr, int size) {
	quick_sort(arr, 0, size);
}

void k_min_value(int *arr, int start, int end, int k, int& ans) {
	if(end - start <= 1) {
		if(start == k)
			ans = arr[start]; 
		return;
	}
	int obj = arr[start];
	int p = start, q = end-1;
	while(p < q) {
		while(q > p) {
			if(arr[q] < obj) {
				arr[p] = arr[q];
				break;
			}
			q--;
		}
		while(p < q) {
			if(arr[p] > obj) {
				arr[q] = arr[p];
				break;
			}
			p++;
		}
	}
	arr[q] = obj;
	if(q == k) {
		ans = obj;
		return;
	}  else if(q > k) {
		k_min_value(arr, start, p, k, ans);
	} else {
		k_min_value(arr, p+1, end, k, ans);
	}
}

int  get_k_min_value(int *arr, int size, int k)
{
	int ans = 0;
	//k是第几个，而数组是从0开始索引的
	k_min_value(arr, 0, size, k-1, ans);
	return ans;
}

int main()
{
	int arr[] = {1,2,10, 9, 5};
	int size = sizeof(arr) / sizeof(arr[0]);

	//get_quick_sort(arr,size);
	int k  = 4;
	int ans = get_k_min_value(arr, size, k);
	cout << ans << endl;
	print_arr(arr, size);
}