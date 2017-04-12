// 就是一个广度优先搜索,使用队列就可以了.
#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

class Element
{
  public:
    int x;
    int y;
    String symbol;
    int step;

    Element(int x = 0, int y = 0, String symbol = '.', int step = 0)
    {
      this->x = x;
      this->y = y;
      this->symbol = symbol;
      this->step = step;
    }
}

Element maze[7][7];
std::queue<Element> q;
Element start;

Element dealInput(int rows, int cols)
{
  maze.clear();
  int x, y;
  String symbol;
  for(x = 0 ; x < rows; x++)
  {
    for(y = 0; y < cols; y++)
    {
      cin >> symbol;
      Element e = Element(x, y, symbol, 0);
      maze[x][y] = e;
      if(symbol == "S")
        start = e;
    }
  }
  return start;
}

void passMaze(int time)
{
  q.clear();
  q.push(start);
  bool rsl = false;
  Element cur;
  int cur_x;
  int cur_y;
  while(!q.empty())
  {
    cur = q.front();
    cur_x = cur.x;
    cur_y = cur.y;
    // 判断是否成功

    q.pop();

    for(i = 0; i < 4; i++) {
      d = directions[i];
      next_x = cur.x + d[0];
      next_y = cur.y + d[1];

      // check
      if(isLegal(next_x, next_y) && !visited[next_x][next_y])
      {
        maze[next_x][next_y].step = maze[cur_x][cur_y].step + 1;

      }
    }
  }
  return rsl;
}

int main() {
    int N, M, T;
    while((cin >> N >> M >> T) && !(N == 0 && M == 0 && T == 0))
    {
      start = dealInput(N, M);
      if(passMaze(T))
      {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
}
