//比较灵活的是栈的存储方式; 从后面往前放，就可以了
#include<iostream>
#include<vector>

using namespace std;

class NestedInteger {
    public:
        bool isTrue;
};

class NestedIterator {
    public:
        stack<NestedInteger> store;
        NestedIterator(vector<NestedInteger> &nestedList) {
        }
        int next() {
            if(hasNext()) {

            }
        }
}

int main() {
    NestedInteger n1;
    n1.isTrue = true;
    vector<NestedInteger> test;
    test.push_back(n1);
    test[0].isTrue = false;
    cout << n1.isTrue << endl;
}