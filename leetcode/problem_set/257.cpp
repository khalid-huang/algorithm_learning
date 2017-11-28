#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

void print(vector<string> rsl) {
    int size = rsl.size();
    cout << size << endl;
    for(int i = 0; i < size; i++) {
        cout << rsl[i] << " ";
    }
    cout << endl;
}

string int2str(int val) {
    stringstream ss;
    ss << val;
    return ss.str();
}

void BTP(TreeNode* root, vector<string>& rsl, string cur) {
    if(root->left == NULL && root->right == NULL) {
        rsl.push_back(cur + int2str(root->val));
        return;
    }
    string tmp = cur + int2str(root->val) + "->";
    if(root->left != NULL) {
        BTP(root->left, rsl, tmp);
    }
    if(root->right != NULL) {
        BTP(root->right, rsl, tmp);
    }
}

vector<string> BinaryTreePaths(TreeNode* root) {
    vector<string> rsl;
    if(root == NULL) {
        return rsl;
    }
    BTP(root, rsl, "");
    return rsl;
}

int main() {
    TreeNode *root = new TreeNode(1);
    TreeNode *rl = new TreeNode(2);
    TreeNode *rr = new TreeNode(3);
    TreeNode *lr = new TreeNode(5);
    
    root->left = rl;
    root->right = rr;
    rl->right = lr;

    print(BinaryTreePaths(root));
}