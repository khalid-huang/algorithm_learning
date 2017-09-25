#include <iostream>

using namespace std;

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
  int c_left = max(A, E), c_right = max(min(C, G), c_left) ;//c_top加上c_bottom只是为了防止错误输入
  int c_bottom = max(B, F), c_top = max(min(D, H), c_bottom);
  return (C-A) * (D-B) + (G-E)*(H-F) - (right - left) * (top-bottom);
}

int main() {
  int A = -2;
  int B = -2;
  int C = 2;
  int D = 2;
  int E = -2;
  int F = -2;
  int G = 2;
  int H = 2;
  cout << computeArea(A, B, C, D, E, F, G, H) << endl;
}
