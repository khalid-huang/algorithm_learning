#include <iostream>

using namespace std;

void print_arr(int* arr, int size)
{
	for(int i = 0; i < size; i++) {
		cout << arr[i] << "  ";
	}
	cout << endl;
}

void merge_sort(int* arr, int start, int end, int* tmp)
{
	if(end - start <= 1) return;
	int m = (start + end) / 2;
	merge_sort(arr, start, m, tmp);
	merge_sort(arr, m, end, tmp);
	int p = start, q = m, k = start;
	//merge
	cout << "l:";
	for(int i = start; i < m; i++)
		cout << arr[i] << " ";
	cout << endl << "r: ";
	for(int i = m; i < end; i++)
		cout << arr[i] << " ";
	cout << endl;

	cout << "result:" << endl;
	while (p < m || q < end) {
		if(q >= end || (p < m && arr[p] < arr[q]))
			tmp[k++] = arr[p++];
		else
			tmp[k++] = arr[q++];
		cout << tmp[k-1] << " ";
	}
	cout << endl;
	cout << "#" << endl;
	for(int i = start; i < end; i++) {
		cout << tmp[i] << "  ";
		arr[i] = tmp[i];
	}
	cout << endl;
}

void get_merge_sort(int* arr, int size)
{
	int tmp[size];
	merge_sort(arr, 0, size, tmp);
}

int main()
{
	int arr[] = {1,2,5,2,5,7,1,2,5,10};
	//int arr[] = {3,4};
	int size = sizeof(arr) / sizeof(arr[0]);
	get_merge_sort(arr, size);
	print_arr(arr, size);
}