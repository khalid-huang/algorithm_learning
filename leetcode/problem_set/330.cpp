// 整个题目基于的思想是树的入度与出度是一致的
//https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/discuss/78551/7-lines-Easy-Java-Solution

#include<iostream>
#include<vector>

using namespace std;

void print(vector<string> nodes) {
    for(int i = 0; i < nodes.size(); i++) {
        cout << nodes[i] << " ";
    }
    cout << endl;
}

vector<string> split(string preorder, char delim) {
    preorder = preorder + ",";
    int size = preorder.size();
    int cur = 0, start = 0;
    vector<string> nodes;
    for(int i = 0; i < size; i++) {
        if(delim == preorder[i]) {
            nodes.push_back(preorder.substr(start, i - start));
            start = i + 1;
        }
    }
    return nodes;
}

bool isValidSerialization(string preorder) {
    vector<string> nodes = split(preorder, ',');
    // print(nodes);
    int diff = 1; // diff = outdgree - indegree (初始值为1是因为在循环里面假设了根结点是有入度的，所以这里要先加回来)
    bool rsl = true;
    for(int i = 0; i < nodes.size(); i++) {
        if(--diff < 0) {
            rsl = false;
            break;
        }
        if(nodes[i] != "#") {
            diff += 2;
        } //
    }
    rsl = diff == 0;
    return rsl;
}

int main() {
    string preorder;
    cin >> preorder;
    cout << isValidSerialization(preorder) << endl;
}