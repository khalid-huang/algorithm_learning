#include<iostream>

using namespace std;

struct BinaryTreeNode {
    int value;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    BinaryTreeNode(int value) {
        this->value=value;
    }
};

//       3
//     5    2
//  1   4 |    6 
BinaryTreeNode* buildTree() {
    BinaryTreeNode* root = new BinaryTreeNode(3);
    BinaryTreeNode* l = new BinaryTreeNode(5);
    BinaryTreeNode* r = new BinaryTreeNode(2);
    BinaryTreeNode* ll = new BinaryTreeNode13);
    BinaryTreeNode* lr = new BinaryTreeNode(4);
    BinaryTreeNode* rr = new BinaryTreeNode(6);
    root->left = l;
    root->right= r;
    l->left = ll;
    l->right = lr;
    r->right = rr;
    return root;
}

int main() {
    BinaryTreeNode* root = buildTree();
}