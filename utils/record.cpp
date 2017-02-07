#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//stirng
void swap(string& source, int first, int second)
{
	char tmp = source[first];
	source[first]  =source[second];
	source[second] = tmp;
}

void toArr(string& source, vector<char>& target)
{
	int size = source.size();
	for(int i = 0; i < size; i++)
	{
		target.push_back(source[i]);
	}
}

void print_vec(vector<char> v)
{
	for(int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}
}

//vector
//sort
//
bool cmp(const int first, const int second)
{
	return first < second;
}
void test() {
	std::vector<int> v_int;
	v_int.push_back(1);
	v_int.push_back(4);
	v_int.push_back(2);
	sort(v_int.begin(), v_int.end(), cmp);
}


int main()
{
	string test("qwe");
	cout <<test << endl;
	swap(test, 0, 1);
	cout << test << endl;
	std::vector<char> target;
	toArr(test, target);
	print_vec(target);
}