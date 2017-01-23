//
#include <iostream>
using namespace std;

struct matrix
{
	int m[2][2];
};

void print_matrix(matrix temp)
{
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 2; j++) {
			cout << temp.m[i][j] << "  ";
		}
		cout << endl;
	}
}

matrix matrix_mul(matrix left, matrix right, int mod)
{
	matrix rsl;
	int left_rows = 2, left_cols = 2;
	int right_rows = 2, right_cols = 2;
	for(int i = 0; i < left_rows; i++) {
		for(int j = 0; j < right_cols; j++) {
			int temp = 0;
			for(int k = 0; k < left_cols; k++) {
				temp += (left.m[i][k] * right.m[k][j]);
			}
			rsl.m[i][j] = temp % mod;
		}
	}
	return rsl;
}

matrix fast_matrix_power(matrix base, int power, int mod)
{
	matrix ans;
	ans.m[0][0] = ans.m[1][1] = 1;
	ans.m[0][1] = ans.m[1][0] = 0;
	//cout << "base" << endl;
	//print_matrix(base);
	while(power > 0)
	{
		if(power & 1)
			ans = matrix_mul(ans, base, mod);
		base = matrix_mul(base, base, mod);
		power = power >> 1;
	}
	return ans;
}

int get_result(int A, int B, int n)
{
	int mod = 7;
	matrix base;
	base.m[0][0] = A, base.m[0][1] = 1;
	base.m[1][0] = B, base.m[1][1] = 0;
	matrix temp = fast_matrix_power(base, n-1, mod);
	matrix init, rsl;
	init.m[0][0] = init.m[0][1] = 1;
	init.m[1][0] = init.m[1][1] = 0;
	rsl = matrix_mul(init, temp,mod);
	//print_matrix(temp);
	//cout << "rsl" <<endl;
	//print_matrix(rsl);
	return rsl.m[0][1];
}

int main()
{
	int A, B, n, rsl;
	while(true)
	{
		cin >> A >> B >> n;
		if (A==0 && B == 0 && n == 0)
		{
			break;
		}
		rsl = get_result(A, B, n);
		cout << rsl << endl;
	}	
}