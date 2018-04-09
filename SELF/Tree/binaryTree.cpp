//https://blog.csdn.net/luckyxiaoqiang/article/details/7518888#topic5
//树的做法
//  遍历（四种）
//  递归:在递归一种是利用遍历的思想，中序还是前序等；
//       还有一种是带值的，就是用递归来进行深度比较和求值 ，然后返回上层; 一般都是处理左树，处理右树，再进行整合
#include<iostream>
#include<queue>

using namespace std;

struct BinaryTreeNode {
    int value;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    BinaryTreeNode(int value) {
        this->value=value;
        left = NULL;
        right = NULL;

    }
};

int abs(int val) {
    return val < 0 ? -val : val;
}

int max(int a, int b) {
    return a > b ? a : b;
}

//       3
//     5    2
//  1   4 |    6 
//k表示位数，用于构造不同的树
BinaryTreeNode* buildTree1(int k) {
    BinaryTreeNode* root = new BinaryTreeNode(3*k);
    BinaryTreeNode* l = new BinaryTreeNode(5*k);
    BinaryTreeNode* r = new BinaryTreeNode(2*k);
    BinaryTreeNode* ll = new BinaryTreeNode(1*k);
    BinaryTreeNode* lr = new BinaryTreeNode(4*k);
    BinaryTreeNode* rr = new BinaryTreeNode(6*k);
    root->left = l;
    root->right= r;
    l->left = ll;
    l->right = lr;
    r->right = rr;
    return root;
}

//       3
//     5    2
//  1   4 |
//2
//k表示位数，用于构造不同的树
BinaryTreeNode* buildTree2(int k) {
    BinaryTreeNode* root = new BinaryTreeNode(3*k);
    BinaryTreeNode* l = new BinaryTreeNode(5*k);
    BinaryTreeNode* r = new BinaryTreeNode(2*k);
    BinaryTreeNode* ll = new BinaryTreeNode(1*k);
    BinaryTreeNode* lr = new BinaryTreeNode(4*k);
    BinaryTreeNode* lll = new BinaryTreeNode(2*k);
    root->left = l;
    root->right= r;
    l->left = ll;
    l->right = lr;
    ll->left = lll;
    return root;
}

//       10
//     5    12
//  1   8 |    16 
BinaryTreeNode* buildBinarySearchTree() {
    BinaryTreeNode* root = new BinaryTreeNode(10);
    BinaryTreeNode* l = new BinaryTreeNode(5);
    BinaryTreeNode* r = new BinaryTreeNode(12);
    BinaryTreeNode* ll = new BinaryTreeNode(1);
    BinaryTreeNode* lr = new BinaryTreeNode(8);
    BinaryTreeNode* rr = new BinaryTreeNode(16);
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


/*
    分层遍历二叉树；
    思路是使用队列，每次都把当层的全部结点获取并打印
*/
void levelTraverse(BinaryTreeNode* root) {
    if(root == NULL) return;
    queue<BinaryTreeNode*> qbt;
    qbt.push(root);
    int curSize;
    BinaryTreeNode* tmp;
    while(!qbt.empty()) {
        curSize = qbt.size(); //获取一整层的结点
        for(int i = 0; i < curSize; i++) {
            tmp = qbt.front();
            qbt.pop();
            if(tmp->left) qbt.push(tmp->left);
            if(tmp->right) qbt.push(tmp->right);
            cout << tmp->value << " ";
        }
        cout << endl;
    }
}

//未测试

/*
    二叉查找树转化为有序的双向链表
    思路：自己画下图就知道这是一个中序遍历结构
    
    root: 要转化的二叉查找树的根结点
    firstNode: 转化成功后的双向链表的头结点
    lastNode: 转化成功后的双向链表的尾结点
*/
void binarySearchTree2OrderedDoubledList(BinaryTreeNode* root, BinaryTreeNode*& firstNode, BinaryTreeNode*& lastNode) {
    //递归结束
    if(root == NULL) {
        firstNode = NULL;
        lastNode = NULL;
        return;
    }
    //下面的结点分别是左树和右树的转化后的头尾结点
    BinaryTreeNode* firstNodeOfLeftTree, *lastNodeOfLeftTree, *firstNodeOfRightTree, *lastNodeOfRightTree;

    //inOrder travel
    if(root->left == NULL) {
        firstNode = root; //如果左子树为空，树root的第一个头结点就是root
    } else {
        binarySearchTree2OrderedDoubledList(root->left, firstNodeOfLeftTree, lastNodeOfLeftTree);
        //获取到左树的第一个结点和最后一个结点
        firstNode = firstNodeOfLeftTree; //root树的每一个结点应该是左子树第一个结点
        lastNodeOfLeftTree->right = root;
        root->left = lastNodeOfLeftTree;
    }

    if(root->right == NULL) {
        lastNode = root;
    } else {
        binarySearchTree2OrderedDoubledList(root->right, firstNodeOfRightTree, lastNodeOfRightTree);
        lastNode = lastNodeOfRightTree;
        root->right = firstNodeOfRightTree;
        firstNodeOfRightTree->left = root;
    }
}

void printOrderDoubleList(BinaryTreeNode* firstNode) {
    while(firstNode != NULL) {
        cout << firstNode->value << " ";
        firstNode = firstNode->right;
    }
    return;
}

/*
    求二叉树第K层的节点个数
    就是一个水平遍历
*/
int countNumberofKthLevel(BinaryTreeNode* root, int k) {
    if(root == NULL) {
        return 0;
    }
    int count = -1, level = 0, num;
    BinaryTreeNode* tmp;
    queue<BinaryTreeNode*> qbt;
    qbt.push(root);
    while(!qbt.empty()) {
        ++level;
        num = qbt.size();
        if(level == k) {
            count = num;
            return count;
        }
        for(int i = 0; i < num; i++) {
            tmp = qbt.front();
            qbt.pop();
            if(tmp->left) qbt.push(tmp->left);
            if(tmp->right) qbt.push(tmp->right);
        }
    }
    return count;
}

/*
    count the number of leave
    思路是使用递归就可以了
*/

int countLeaveNode(BinaryTreeNode* root) {
    if(root == NULL) return 0;

    if(root->left == NULL && root->right == NULL) {
        return 1;
    } //成为叶子结点的条件

    return countLeaveNode(root->left) + countLeaveNode(root->right); //计算左子树和右子树的叶子结点
}

/*
    判断两棵二叉树的结构是否相同
    思路是使用递归就可以了，结构相同的条件是左子树和右子树的结构相同
*/

bool isSameStructure(BinaryTreeNode* root1, BinaryTreeNode* root2) {
    //终止条件
    //都为空
    if(root1 == NULL && root2 == NULL) {
        return true;
    }
    //有一个为空
    if(root1 == NULL || root2 == NULL) {
        return false;
    }
    //都不为空
    return isSameStructure(root1->left, root2->left) & isSameStructure(root1->right, root2->right);
}

/*
    判断是不是平衡二叉树
    思想是利用递归；如果是空树直接返回true;如果不是空树就看看左子树和右子树是不是AVL，同时还要满足高度的条件
*/

bool _isAVL(BinaryTreeNode* root, int& height) {
    if(root == NULL) {
        height = 0;
        return true;
    }
    //判断左子树和右子树是不是AVL还有高度信息
    bool isLeftTreeAVL, isRightTreeAVL;
    int heightOfLeftTree, heightOfRightTree;

    isLeftTreeAVL = _isAVL(root->left, heightOfLeftTree);
    isRightTreeAVL = _isAVL(root->right, heightOfRightTree);
    height = max(heightOfLeftTree, heightOfRightTree) + 1;
    if(isLeftTreeAVL && isRightTreeAVL && abs(heightOfLeftTree-heightOfRightTree) <= 1) {
        return true;
    } else {
        return false;
    }
}

bool isAVL(BinaryTreeNode* root) {
    int height;
    return _isAVL(root, height);
}

/*
    求二叉树的镜像
    本质就是递归，先处理左树和右树，再处理根，得到根的镜像（交换左树和右树），其实就是一个后序遍历
*/
BinaryTreeNode* getMirror(BinaryTreeNode* root) {
    //终止条件
    if(root == NULL) {
        return NULL;
    }
    //后序遍历
    BinaryTreeNode* leftNode = getMirror(root->left);
    BinaryTreeNode* rightNode = getMirror(root->right);
    //处理
    root->left = rightNode;
    root->right = leftNode;
    return root;
}

//       3
//     5    2
//  1   4 |    6 

//       10
//     5    12
//  1   8 |    16 

int main() {
    BinaryTreeNode* root = buildTree1(1);
    // BinaryTreeNode* root1 = buildTree1(3);
    // BinaryTreeNode* root2 = buildTree2(2);
    // int depth = getTreeDepthWithQueue(root);
    // cout << "depth: " << depth << endl;
    // int count = countNodeNumberWithQueue(root);
    // cout << "nums: " << count << endl;

    // int depth = getTreeDepthWithQueue(root);
    // cout << "depth: " << depth << endl;
    // inOrderTraverse(root);
    // levelTraverse(root);

    // BinaryTreeNode* root = buildBinarySearchTree();
    // BinaryTreeNode* firstNode, *lastNode;
    // binarySearchTree2OrderedDoubledList(root, firstNode, lastNode);
    // cout << firstNode << endl;
    // printOrderDoubleList(firstNode);

    // cout << countNumberofKthLevel(root,3) << endl;
    // cout << countNumberofKthLevel(root,4) << endl;

    // cout << countLeaveNode(root) << endl;

    // cout << isSameStructure(root, root1) << endl;
    // cout << isSameStructure(root1, root2) << endl;
    // cout << isAVL(root1) << endl;
    // cout << isAVL(root2) << endl;
    levelTraverse(root);
    root = getMirror(root);
    levelTraverse(root);
}