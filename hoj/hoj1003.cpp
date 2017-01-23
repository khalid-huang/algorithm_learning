//将其转化为矩阵运算，然后利用快速矩阵幂取模算法来算计
#include <iostream>
using namespace std;

int main()
{
	int t, T,num, tmp;
	int max_up, max_sum, max_down, cur_up, cur_sum, cur_down, pre_sum;
	cin >> T;
	for (t = 1; t <= T; t++)
	{
		// deal the input
		cin >> num;
		max_sum = cur_sum = -1001;
		max_down = -1;
		max_up = -1;
		pre_sum = 0;

		cur_down = 0;
		cur_up = 0;
		for(int i = 0; i < num; i++)
		{
			cin >> tmp;
			if(tmp < 0 && cur_sum > max_sum)
			{
				max_sum = cur_sum;
				max_down = cur_down;
				max_up = cur_up;
			}			
			if(pre_sum >= 0)
			{
				cur_sum = pre_sum + tmp;
				cur_up = i;
			} else {
				cur_sum = tmp;
				cur_down = i;
				cur_up = i;
			}
			pre_sum = cur_sum;
		}
		if(cur_sum > max_sum)
		{
			max_sum = cur_sum;
			max_down = cur_down;
			max_up = cur_up;
		}
		cout << "Case "<< t << ":" << endl;
		cout << max_sum << " " << max_down+1 << " " << max_up+1 << endl;
		if (t != T)
		{
			cout << endl;
		}
	}
}