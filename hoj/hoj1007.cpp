//是一个最邻近对问题，可以参考http://www.cnblogs.com/shanyr/p/5206899.html；和http://www.cnblogs.com/AdaByron/archive/2011/10/07/2200966.html；
//下面的代码在本地运行没有问题，但是Oj是超时的
#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>  
#include <vector>

using namespace std;

struct Point
{

	double x;
	double y;
};

std::vector<Point> tmp;

void print_points(std::vector<Point> points)
{
	for(std::vector<Point>::iterator it = points.begin(); it != points.end(); ++it) {
		cout << "x: " << (*it).x << "  y: " << (*it).y << endl;
	}
}

bool cmp(const Point& first, const Point& second)
{
	if(first.x != second.x)
		return first.x < second.x;
	else
		return first.y < second.y;
}

bool cmp_y(const Point& first, const Point& second)
{
	return first.y < second.y;
}

double get_dis(Point& first, Point& second)
{
	double dis_x = first.x - second.x;
	double dis_y = first.y - second.y;
	return sqrt(dis_x*dis_x + dis_y*dis_y);
}

double get_min_dis(std::vector<Point>& points, int start, int end)
{
	if(start == end)
		return 0;
	double ans = get_dis(points[start], points[start+1]);
	if(end - start > 1) {
		for(int i = start; i < end; i++) {
			for(int j = i + 1; j <= end; j++) {
				double tmp = get_dis(points[i], points[j]);
				ans = ans > tmp ? tmp : ans; 
			}
		}
	}
	return ans;
}


double nearest_pair(std::vector<Point>& points, int l, int r)
{
	if(r-l+1<=3)
	{
		double min_dis = get_min_dis(points, l, r);
		return min_dis;
	}
	int m = (l+r) >> 1;
	double l_min_dis = nearest_pair(points, l, m);
	double r_min_dis = nearest_pair(points, m+1, r);
	double min_dis = l_min_dis > r_min_dis ? r_min_dis : l_min_dis;
	//cout << l << " " << m << " " << r << endl;
	//cout << "l: " << l_min_dis << " r: " << r_min_dis << endl;
	//cout << "#1 " << min_dis << endl;

	//获取中间可能是最小值的所有点
	//std::vector<Point> tmp;
	tmp.clear();
	Point m_point = points[m];
	tmp.push_back(m_point);
	//cout << "min_dis: " << min_dis << endl;
	//cout << "m.x:" << m_point.x << " m.y: " << m_point.y << endl;
	for(int i = m - 1; i >= l && m_point.x - points[i].x <= min_dis; i--)
		tmp.push_back(points[i]);
	for(int i = m + 1; i <= r && points[i].x - m_point.x <= min_dis; i++)
		tmp.push_back(points[i]);
	int size = tmp.size();
	//cout << "#2" << endl;
	//print_points(tmp);
	//sort(tmp.begin(), tmp.end(), cmp_y);
	
	for(int i = 0; i < size; i++) {
		for(int j = i+1; j < size;j++) {
			double tmp_dis = get_dis(tmp[i], tmp[j]);
			min_dis = tmp_dis < min_dis ? tmp_dis : min_dis;
		}
	}
	//cout << "min_dis " << min_dis << endl; 
/*	cout << "##cur##" << endl;
	for(int i = l; i <= r; i++) {
		cout << "x:" << points[i].x << " y: " << points[i].y << endl;
	}
	cout << "ans: " << min_dis << endl;
	cout << "##cur_end##" << endl;*/
	return min_dis;
}

int main()
{
	int t;
	double ans, x, y;
	vector<Point> points;

/*	Point p1, p2, p3, p4, p5, p6, p7;
	p1.x = 0.0, p1.y = 0.0;
	p2.x = 2.0, p2.y = 0.0;
	p3.x = -1.0, p3.y = 1.0;
	p4.x = -1.0, p4.y = -1.0;
	p5.x = 4.0, p5.y = 0.0;
	p6.x = 6.0, p6.y = 0.0;
	p7.x = 7.0, p7.y = 0.0;

	points.push_back(p1);
	points.push_back(p2);
	points.push_back(p3);
	points.push_back(p4);
	points.push_back(p5);
	points.push_back(p6);
	points.push_back(p7);

	sort(points.begin(), points.end(), cmp);
	print_points(points);
	cout << fixed << setprecision(2) << nearest_pair(points, 0, 6) / 2 << endl;*/
	while(true)
	{
		cin >> t;
		if(t == 0)
		{
			break;
		}
		for(int i = 0; i < t; i++)
		{
			cin >> x >> y;
			Point tmp;
			tmp.x = x, tmp.y = y;
			points.push_back(tmp);
		}
		sort(points.begin(), points.end(), cmp);
		ans = nearest_pair(points,0,t-1);
		cout << fixed << setprecision(2) << ans / 2 << endl;
		points.clear();
	}
}