//http://www.cnblogs.com/autosar/archive/2012/04/08/2437799.html
#include <iostream>
#include <vector>
using namespace std;

void swap(string& source, int first, int second)
{
	char tmp = source[first];
	source[first] = source[second];
	source[second] = tmp;
}

//全排列
void permutation(string letters, int start, int end, string cur, vector<string>& result)
{
	//cout << start << " " << end << endl;
	// 结束了
	if(start > end) 
	{
		//cout << tmp<< endl;
		result.push_back(cur);
		return;
	} else {
		for(int i = start; i <= end; i++)
		{
			swap(letters, i, start);
			string tmp = cur + letters[start];
			permutation(letters, start + 1, end, tmp, result);
			swap(letters, i, start);
		}
	}
}

vector<string> get_permutation(string letters)
{
	std::vector<string> result;
	int start =  0, end = letters.size() - 1;
	permutation(letters, start, end, "", result);
	return result;
}

//带有个数参数，比如从5个中先3个；算法的思想主要是将其分为两个集合，一个是已经选好的，从0到start, 另一个是选择集，从start到end；如果我们的计算已经到达了目标的话，就把目前的结果放入结果数组中；没有的话，我们要做的是将选择集里面的所有元素选择一次，将其与start进行交换（这次交换是进行纵向的扩展与对比，可以 自己画个示意图）
void permutation1(string letters, int count, int start, int end, string cur, vector<string>& result, int target_count)
{
	//cout << start << " " << end << endl;
	if(count == target_count)
	{
		//cout << tmp<< endl;
		result.push_back(cur);
		return;
	} else {
		for(int i = start; i <= end; i++)
		{
			swap(letters, i, start);
			string tmp = cur + letters[start];
			permutation1(letters, count + 1, start+1, end, tmp, result,target_count);
			swap(letters, i, start);
		}
	}
}

vector<string> get_permutation1(string letters)
{
	std::vector<string> result;
	int start =  0, end = letters.size() - 1;
	int target_count = 2;
	permutation1(letters,0, start, end, "", result, target_count);
	return result;
}

void print_rsl(vector<string> result)
{
	int size = result.size();
	for(int i = 0; i < size; i++)
	{
		cout << result[i] << endl;
	}
}

int main()
{
	string letters("0123456789");
	vector<string> result = get_permutation1(letters);
	print_rsl(result);
}