#include <iostream>
#include <string>
using namespace std;

int main()
{
	string t("fac");
	cout << t[2] << endl;
	char tmp = t[2];
	t[2] = t[1];
	t[1] = tmp;
	cout <<t << endl;
}
