#include <iostream>
#include <set>
#include <vector>

using namespace std;

void bfs(vector<set<int> >& adjList, int point, int depth, vector<bool>& visited, int& rsl) {
    visited[point] = true;

    int size =  adjList[point].size();
    int next_point;
    for(int i = 0; i < size; i++) {
        next_point = adjList[point][i];
        adjList[next_point].erase(point);
        bfs(adjList, adjList[point][i], depth + 1, visited);
        adjList[next_point].insert(point);
    }

    //判断是否结束
    int v_size = visited.size(), flag = 1;
    for(int i = 0; i < v_size; i++) {
        if(visited[i] == false) {
            flag = 0;
        }
    }

    if(flag == 1) {
        rsl = rsl < depth ? rsl : depth;
    }

    visited[point] = false;
}

vector<int> findMinHeightTrees(int n , vector<pair<int, int> >& edges) {
    //build adjacency list;
    vector<set<int> > adjList(n);
    int e_size = edges.size();
    int p1, p2;
    for(int i = 0 ; i < e_size; i++) {
        p1 = edges[i].first;
        p2 = edges[i].second;
        adjList[p1].insert(p2);
        adjList[p2].insert(p1);
    }

    vector<bool> visited(n, false);
    int a_size, depth = 0, rsl = n;
    for(int i = 0; i < n; i++) {
        a_size = adjList[i].size();
        visited[i] = true;
        for(int j = 0; j < a_size; j++) {
            next_point = adjList[j];
            adjList[j].erase(i); //to avoid from j to i;
            bfs(adjList, next_point, depth+1, visited, rsl);
            adjList[j].insert(i);
        }
        visited[i] = false;
    }

}

int main() {
    vector<set<int> > linkTable;

}