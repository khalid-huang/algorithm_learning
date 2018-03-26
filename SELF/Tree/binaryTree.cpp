#include<iostream>
#include<queue>

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
    BinaryTreeNode* ll = new BinaryTreeNode(1);
    BinaryTreeNode* lr = new BinaryTreeNode(4);
    BinaryTreeNode* rr = new BinaryTreeNode(6);
    root->left = l;
    root->right= r;
    l->left = ll;
    l->right = lr;
    r->right = rr;
    return root;
}

/*
    实现计算树内的结点个数；
    思路两个，分别是纵向的和横向的；纵向的就是递归，横向的就是队列；也就是深度优先搜索和广度优先搜索了；
*/
//用递归。深度优先搜索
int countNodeNumber(BinaryTreeNode* root) {
    if(root == NULL) {
        return 0;
    }
    return 1 + countNodeNumber(root->left) + countNodeNumber(root->right);
}
//用队列，广度优先搜索
int countNodeNumberWithQueue(BinaryTreeNode* root) {
    queue<BinaryTreeNode*> qbn;
    if(root == NULL) {
        return 0;
    }
    qbn.push(root);
    BinaryTreeNode* tmp;
    int rsl = 0;
    //可以如下按层来
    // while(!qbn.empty()) {
    //     int curSize = qbn.size(); //记录上一层进入队列的结点数；也就是一整层的结点数
    //     while(curSize--) {
    //         tmp = qbn.front();
    //         qbn.pop();
    //         ++rsl;
    //         if(tmp->left != NULL) {
    //             qbn.push(tmp->left);
    //         }
    //         if(tmp->right != NULL) {
    //             qbn.push(tmp->right);
    //         }
    //     }
    // }
    //也可以直接运算，因为不用保存层的信息
    while(!qbn.empty()) {
        tmp = qbn.front();
        qbn.pop();
        ++rsl;
        if(tmp->left != NULL) {
            qbn.push(tmp->left);
        }
        if(tmp->right != NULL) {
            qbn.push(tmp->right);
        }
    }
    return rsl;
}

/*
    实现计算树的深度
    思路同样两种，要么用深度优先就是用递归；要么就是用广度优先，就是用队列，循环
*/
//用递归
int getTreeDepth(BinaryTreeNode* root) {
    if(root == NULL) {
        return 0;
    }
    return 1 + max(getTreeDepth(root->left), getTreeDepth(root->right));
}

//用队列，思想是每次得到一层的全部节点数，层数就加1；最后可以遍历多少层就是树的深度了；
int getTreeDepthWithQueue(BinaryTreeNode* root) {
    if(root == NULL) {
        return 0;
    }
    queue<BinaryTreeNode*> qbt;
    qbt.push(root);
    int depth = 0;
    BinaryTreeNode* tmp;
    while(!qbt.empty()) {
        int curSize = qbt.size();
        ++depth;
        while(curSize--) {
            tmp = qbt.front();
            qbt.pop();
            if(tmp->left != NULL) qbt.push(tmp->left);
            if(tmp->right != NULL) qbt.push(tmp->right);
        }
    }
    return depth;
}

/*
    三种遍历方式：前序+中序+后序
*/
//动作函数
void visit(BinaryTreeNode* node) {
    cout << node->value << " ";
}
//preOrderTraverse
void preOrderTraverse(BinaryTreeNode* root) {
    if(root == NULL) return;

    visit(root);
    preOrderTraverse(root->left);
    preOrderTraverse(root->right);
}

//inOrderTraverse
void  inOrderTraverse(BinaryTreeNode* root) {
    if(root == NULL) return;

    inOrderTraverse(root->left);
    visit(root);
    inOrderTraverse(root->right);
}

//postOrderTraverse
void postOrderTraverse(BinaryTreeNode* root) {
    if(root == NULL) return;
    postOrderTraverse(root->left);
    postOrderTraverse(root->right);
    visit(root);
}


int main() {
    BinaryTreeNode* root = buildTree();

    // int count = countNodeNumberWithQueue(root);
    // cout << "nums: " << count << endl;

    // int depth = getTreeDepthWithQueue(root);
    // cout << "depth: " << depth << endl;
    inOrderTraverse(root);

}