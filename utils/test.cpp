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

int main()
{
	int t;
	double ans, x, y;
	vector<Point> points;
	Point p1, p2, p3,p4;

	p1.x = 0.0, p1.y = 0.0;
	p2.x = 2.0, p2.y = 0.0;
	p3.x = -1.0, p3.y = 1.0;
	p4.x = -1.0, p4.y = -1.0;

	points.push_back(p4);
	points.push_back(p2);
	points.push_back(p1);
	points.push_back(p3);
	sort(points.begin(), points.end(), cmp);
	print_points(points);
}
