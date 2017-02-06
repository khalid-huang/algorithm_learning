#include <iostream>
#include <vector>
using namespace std;

void swap(string& source, int first, int second)
{
	char tmp = source[first];
	source[first] = source[second];
	source[second] = tmp;
}

void permutation(string letters, int start, int end, string cur, vector<string>& result)
{
	//cout << start << " " << end << endl;
	if(start == end)
	{
		string tmp = cur + letters[start];
		//cout << tmp<< endl;
		result.push_back(tmp);
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
	string letters("abc");
	vector<string> result = get_permutation(letters);
	print_rsl(result);
}