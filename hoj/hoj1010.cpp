// 因为题目是要求在指定步数到达，所以用的是深度优先探索，而不是广度优先搜索
#include <iostream>
#include <string>
using namespace std;

char maze[7][7];
int visited[7][7];
int rsl = 0;
int N, M, T, start_x, start_y, end_x, end_y;

//四个方向
int directions[4][2] = {{0, 1}, {0,-1}, {1, 0}, {-1, 0}};


//判断新的位置是否满足运动的要求
bool isLegal(int x, int y)
{
  if(x >=0 && x < N && y >= 0 && y < M && maze[x][y] != 'X')
  {
    return true;
  } else {
    return false;
  }
}

//绝对值函数
int abs(int a)
{
  return a > 0 ? a : -a;
}

//深度优先搜索
void dfs(int x, int y, int t)
{
  // 不可以在这里进行判断是否成功，因为这样会超时 ！！！！
  // // cout << "(" <<  x  <<  ", " <<  y <<  ")" << endl;
  // if(maze[x][y] == 'D')
  //   cout << "D " << t << endl;
  // if(maze[x][y] == 'D' && t == T)
  // {
  //   rsl = 1;
  //   return;
  // }
  // if(t >= T) return;

  //奇偶剪枝：剩下的步数的奇偶性与abs(dx-x)+abs(dy-y)的奇偶性一定是一样的
  if((T - t)%2 != (abs(end_x - x) + abs(end_y - y))%2) return;

  //进行四个方向的探索
  int next_x, next_y;
  for(int i = 0; i < 4; i++)
  {
    next_x = x + directions[i][0];
    next_y = y + directions[i][1];
    //进行判断
    if(maze[next_x][next_y] == 'D' && t == T - 1)
    {
      rsl = 1;
      return;
    }

    //判断是否符合条件
    if(isLegal(next_x, next_y) && !visited[next_x][next_y])
    {
      visited[next_x][next_y] = 1; //标记为已经遍历
      // maze[next_x][next_y] = 'X';
      dfs(next_x, next_y, t + 1);
      visited[next_x][next_y] = 0; //回溯
      // maze[next_x][next_y] = '.';
      if(rsl == 1) return;
    }
  }
}

int main()
{
  int i, j;
  char symbol;
  while((cin >> N >> M >> T) && !(N == 0 && M == 0 && T == 0))
  {
    rsl = 0;
    for(i = 0; i < N; i++)
    {
      for(j = 0; j < M; j++)
      {
        cin >> symbol;
        if (symbol == 'S')
        {
          start_x = i;
          start_y = j;
        }
        if (symbol == 'D')
        {
          end_x = i;
          end_y = j;
        }
        maze[i][j] = symbol;
        visited[i][i] = 0;
      }
    }

    visited[start_x][start_y] = 1;
    dfs(start_x, start_y, 0);
    if(rsl == 0)
    {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }
}
