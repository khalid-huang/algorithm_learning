#include <iostream>
using namespace std;

//八皇后问题的解法是使用回溯来减少递归次数
void queen_solve(int num, int cur, int& rsl, int* C)
{
	cout << cur << "  " << num << endl;
	if(cur == num)
	{
		rsl++;
	} else {
		for(int i = 0; i < num; i++)
		{
			C[cur] = i;//在第cur行的第j
			int ok = 1;
			for(int j = 0; j < cur; j++)
			{
				if(C[cur] == C[j] || cur - C[cur] == j - C[j] || cur + C[cur] == j + C[j])
				{
					ok = 0;
					break;
				}
			}
			if(ok == 1)
				queen_solve(num, cur+1, rsl, C);
		}
	}
}

int get_queen_solve(int num)
{
	int rsl = 0;
	int C[num];
	queen_solve(num , 0, rsl, C);
	return rsl;
}

int main()
{
	int tot = get_queen_solve(8);
	cout << tot << endl;
}