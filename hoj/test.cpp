#include <iostream>
#include <math.h>
using namespace std;
int ln, col, time;
int sx, sy, ex, ey, ok, avilable;
int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
char map[10][10];

int inmap(int x, int y){
    return x >= 0 && x <ln && y >= 0 && y <col;
}
void dfs(int x, int y, int tm)
{
    if(x == ex && y == ey && tm == time){
        ok = 1;
    }
    if(ok) return;
    if(tm > time) return;
    if((time - tm)%2!=(abs(ex-x)+abs(ey-y))%2)return;//奇偶剪枝
    for(int i = 0; i < 4; i++)
    {
        int tx = x + dir[i][0];
        int ty = y + dir[i][1];
        if(inmap(tx, ty) && map[tx][ty] != 'X'){
            map[tx][ty] = 'X';
            dfs(tx, ty, tm + 1);
            map[tx][ty] = '.';
        }
    }
}
int main()
{
    while(scanf("%d%d%d", &ln, &col, &time) != EOF && ln)
    {
        avilable = 0;//记录可行点个数
        for (int i = 0; i < ln; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cin >> map[i][j];
                if (map[i][j] == 'S')
                {
                    sx = i;
                    sy = j;
                    map[sx][sy] = 'X';
                    avilable++;
                }
                if (map[i][j] == '.')
                    avilable++;
                if (map[i][j] == 'D')
                {
                    ex = i;
                    ey = j;
                    avilable++;
                }
            }
        }
        // if(avilable < time){
        //     cout <<"NO" <<endl;
        //     continue;
        // }
        ok = 0;
        dfs(sx, sy, 0);
        if(ok)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
