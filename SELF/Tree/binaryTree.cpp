//https://blog.csdn.net/luckyxiaoqiang/article/details/7518888#topic5
//树的做法
//  遍历（四种）
//  递归:在递归一种是利用遍历的思想，中序还是前序等；
//       还有一种是带值的，就是用递归来进行深度比较和求值 ，然后返回上层; 一般都是处理左树，处理右树，再进行整合
//       递归的形式中有些是可以用递归的过程来维护一个变量，这个变量一般是一个参数引用，用来维护一个跟当前结点相关的结点信息；与返回值一同用于进行整合操作
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

int indexOf(int* array, int start, int end, int value) {
    for(int i = start; i <= end; i++) {
        if(array[i] == value) {
            return i;
        }
    }
    return -1;
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
    // BinaryTreeNode* rr = new BinaryTreeNode(6*k);
    root->left = l;
    root->right= r;
    l->left = ll;
    l->right = lr;
    // r->right = rr;
    return root;
}


//buildtree2
//       3
//     5    9
//  1   4 |
//2   |   7
//          8  
BinaryTreeNode* buildTree2(int k) {
    BinaryTreeNode* root = new BinaryTreeNode(3*k);
    BinaryTreeNode* l = new BinaryTreeNode(5*k);
    BinaryTreeNode* r = new BinaryTreeNode(9*k);
    BinaryTreeNode* ll = new BinaryTreeNode(1*k);
    BinaryTreeNode* lr = new BinaryTreeNode(4*k);
    BinaryTreeNode* lll = new BinaryTreeNode(2*k);
    BinaryTreeNode* lrr = new BinaryTreeNode(7*k);
    BinaryTreeNode* lrrr = new BinaryTreeNode(8*k);
    root->left = l;
    root->right= r;
    l->left = ll;
    l->right = lr;
    ll->left = lll;
    lr->right = lrr;
    lrr->right = lrrr;
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

/*
    获取两个指定值的最低公共祖先结点
    思路：还是递归，分别判断左树和右树；其实是一个后序遍历
*/

//函数表示获取以root为根结点的v1和v2的最低公共祖先结点(没有重复数字的情况)
BinaryTreeNode* getLastCommonParent(BinaryTreeNode* root, int v1, int v2) {
    //终止条件
    if(root == NULL) return NULL;
    if(root->value == v1 || root->value == v2) return root;
    //获取当前结点左树和右树对于结果的判断
    BinaryTreeNode* leftResult = getLastCommonParent(root->left, v1, v2);
    BinaryTreeNode* rightResult = getLastCommonParent(root->right, v1, v2);

    if(leftResult) cout << "left " << leftResult->value << endl;
    if(rightResult) cout << "right " << rightResult->value << endl;

    //后序处理就下面三种情况；如果左树和右树各包含一个值的话，就表示最低公共子结点就是它父亲了
    if(leftResult != NULL && rightResult != NULL) {
        return root;
    }
    //如果左树不为空，但是右树的结果为空，表示两个值都在左树找到了，就返回左树的结果就可以了
    if(leftResult != NULL) {
        return leftResult;
    }
    if(rightResult != NULL) {
        return rightResult;
    }
    return NULL;
}

/*
    得到树中的最大距离，这里距离的定义是任意两个结点的步骤数
    思路：用递归的思想，本质还是后序遍历 ；每个递归返回以当前结点为树的最大距离，同时每个递归函数用一个参数引用来维护一个性质，表示当前结点到其叶子结点的最大距离
        如果树为空返回0，否则最大距离要不是左子树的最大距离，要不是右树的最大距离，要不是左子树到根结点的最大距离加上右子树到根结点的最大距离
*/
int _getMaxDistance(BinaryTreeNode* root , int& maxHeight) {
    if(root == NULL) {
        maxHeight = -1; //空结点是-1，这样叶子结点就是0了
        return 0;
    }
    int leftTreeMaxHeight, rightTreeMaxHeight, leftTreeMaxDistance, rightTreeMaxDistance;
    leftTreeMaxDistance = _getMaxDistance(root->left, leftTreeMaxHeight);
    rightTreeMaxDistance = _getMaxDistance(root->right, rightTreeMaxHeight);

    maxHeight = max(leftTreeMaxHeight, rightTreeMaxHeight) + 1;
    int maxVal = max(leftTreeMaxDistance, rightTreeMaxDistance);
    maxVal = max(maxVal, leftTreeMaxHeight + rightTreeMaxHeight + 2);//到根的距离为左子树的距离加上右子树的距离，加2，因为左右两边到根还有2步
    return maxVal;
}


int getMaxDistance(BinaryTreeNode* root) {
    int height;
    return _getMaxDistance(root, height);
}

/*
    根据前序和中序构造出完整的二叉树
    思想：利用递归就可以了，利用前序得到根结点，然后在中序中找到对应的根结点的位置，该位置前面的数就是根结点的左子树的全部元素，该位置后面的数就是根结点的右子树的全部元素
*/
//使用双闭区间;函数表示以preOrder数组的[preStart,preEnd]的元素作为前序
BinaryTreeNode* _buildBinaryTree(int* preOrder, int preStart, int preEnd, int* inOrder, int inStart, int inEnd) {
    //唯有一个元素的情况下
    if(preStart > preEnd || inStart > inEnd) {
        return NULL;
    }

    if(preStart == preEnd && inStart == inEnd) {
        return new BinaryTreeNode(preOrder[preStart]);
    }
    int rootVal = preOrder[preStart];
    BinaryTreeNode* root = new BinaryTreeNode(rootVal);
    int rootIndexOfInOrder = indexOf(inOrder, inStart, inEnd, rootVal);
    cout << "index" << rootIndexOfInOrder << endl;
    if(rootIndexOfInOrder == -1) {
        cout << "Invalid input";
        return NULL;
    }

    int diff = rootIndexOfInOrder - inStart;
    //构造左树和右树
    BinaryTreeNode* leftTree = _buildBinaryTree(preOrder, preStart + 1, preStart + diff, inOrder, inStart, rootIndexOfInOrder - 1);
    BinaryTreeNode* rightTree = _buildBinaryTree(preOrder, preStart + diff + 1, preEnd, inOrder, rootIndexOfInOrder + 1, inEnd);

    root->left = leftTree;
    root->right = rightTree;

    return root;
}

// preOrder前序遍历数据，inOrder后序遍历数据。number就是结点的个数
BinaryTreeNode* buildBinaryTree(int* preOrder, int* inOrder, int number) {
    return _buildBinaryTree(preOrder, 0, number-1, inOrder, 0, number-1);
}

/*
    判断是不是完全二叉树
    思路：本质是一个水平遍历，得到每一层的节点后，在进行推入的时候进行判断：如果左树为空（或是左树不为空和右树为空），那么之后的所有节点都应该都为空；否则
*/
bool isCompleteBinaryTree(BinaryTreeNode* root) {
    if(root == NULL) {
        return true;
    }
    queue<BinaryTreeNode*> qbt;
    qbt.push(root);
    BinaryTreeNode* tmp;
    bool result = true; //用于记录最终结果
    bool isMuchBeNull = false; //用于标记之后的结果是不是一定要为空    
    while(!qbt.empty()) {
        tmp = qbt.front();
        qbt.pop();
        if(isMuchBeNull) {
            if(tmp->left != NULL || tmp->right != NULL) {
                result = false;
                break;
            }
        } else {
            if(tmp->left != NULL && tmp->right != NULL) {
                qbt.push(tmp->left);
                qbt.push(tmp->right);
            } else if(tmp->left != NULL && tmp->right == NULL) {
                //只有左结点有，右结点为空
                qbt.push(tmp->left);
                isMuchBeNull = true;
            } else if(tmp->left == NULL && tmp->right != NULL) {
                result = false;
                break;
            } else {
                //左右结点都为空
                isMuchBeNull = true;
            }
        }
    }
    return result;
}


//buildtree1
//       3
//     5    2
//  1   4 |    6 

//bst
//       10
//     5    12
//  1   8 |    16 

//buildtree2
//       3
//     5    9
//  1   4 |
//2   |   7
//          8 
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
    // levelTraverse(root);
    // root = getMirror(root);
    // levelTraverse(root);

    // BinaryTreeNode* rsl = getLastCommonParent(root,2, 4);
    // if(rsl != NULL) {
    //     cout << rsl->value << endl;
    // } else {
    //     cout << "null" << endl;
    // }
    // cout << getMaxDistance(root) << endl;

    // int preOrder[] = {3, 5, 1, 4, 2, 6};
    // int inOrder[] = {1, 5, 4,3, 2, 6};
    // BinaryTreeNode* root1 = buildBinaryTree(preOrder, inOrder, 6);
    // if(root1 == NULL) {
    //     cout << "NULL" << endl;
    // }
    // preOrderTraverse(root1);
    // cout << endl;
    // inOrderTraverse(root1);
    cout << isCompleteBinaryTree(root) << endl;
}