//思想是利用逐层删除叶子的操作，删除到最后剩下的就是根了
//https://leetcode.com/problems/minimum-height-trees/discuss/76104/C++-Solution.-O(n)-Time-O(n)-Space


#include <iostream>
#include <set>
#include <vector>

using namespace std;

struct Node {
    set<int> neighbors;
    bool isLeaf() {
        return neighbors.size() == 1;
    }
};

vector<int> findMinHeightTrees(int n, vector<pair<int, int> >& edges) {
    vector<int> buffer1;
    vector<int> buffer2;
    if(edges.size() == 1) {
        buffer1.push_back(0);
        return buffer1;
    }
    if(edges.size() == 2) {
        buffer1.push_back(0);
        buffer1.push_back(1);
        return buffer1;
    }

    //构建nodes数组
    vector<Node> nodes = vector<Node>(n);
    int edgesNum = edges.size();
    for(int i = 0; i < edgesNum; i++) {
        nodes[edges[i].first].neighbors.insert(edges[i].second);
        nodes[edges[i].second].neighbors.insert(edges[i].first);
    }

    vector<int>* leaves1 = &buffer1;
    vector<int>* leaves2 = &buffer2;
    //每层删除所有叶子结点和其边；也就是删除所有节点中包含叶子结点的部分（neighbor）
    for(int i = 0; i < n; i++) {
        if(nodes[i].isLeaf()) {
            leaves1->push_back(i);
        }
    }
    while(1) {
        for(int i : *leaves1) {
            for(int j : nodes[i].neighbors) {
                node[j].neighbors.erase(i);
                //判断删除这个叶子之后是不是叶子结点
                if(nodes[j].isLeaf()) {
                    leaves2->push_back(j);
                }
            }
        }
        if(leaves2->empty()) {
            return *leaves1; //这个就是结果了
        }
        leaves1->clear();//清空上层的叶子
        swap(leaves1, leaves2);
    }
}

int main() 
    // vector<set<int> > linkTable;

}