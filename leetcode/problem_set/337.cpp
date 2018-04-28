#include<iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x),left(NULL),right(NULL) {}
};

TreeNode* buildTree() {
    TreeNode* root = new TreeNode(3);
    TreeNode* l = new TreeNode(2);
    TreeNode* r = new TreeNode(3);
    TreeNode* lr = new TreeNode(3);
    TreeNode* rr = new TreeNode(1);
    root->left = l;
    root->right = r;
    l->right= lr;
    r->right = rr;
    return root;
}

int rot(TreeNode* root) {
    if(root == NULL) {
        return 0;
    }
    int val = 0;
    if(root->left != NULL) {
       val +=  rot(root->left->left) + rot(root->left->right);
    }
    if(root->right != NULL) {
        val += rot(root->right->left) + rot(root->right->right);
    }
    return max(root->val + val, rot(root->left) + rot(root->right));
} 

int main() {
    TreeNode* root = buildTree();
    cout << rot(root) << endl;
}
