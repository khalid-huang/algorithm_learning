#include <iostream>
#include <queue>
#include <vector>
#include <sstream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL) {};
}


class Codec {

private:
    void _serialize(TreeNode* root, ostringstream& out) {
        if(root) {
            out << root->val << " ";
            _serialize(root->left, out);
            _serialize(root->right, out);
        } else {
            out << "null" << " ";
        }
    }

    int str2int(strin str) {
        int size = str.size();
        int val = 0;
        for(int i = 0; i++; i < size) {
            val = val * 10 + (str[i] - '0');
        }
        return val;
    }

    TreeNode* _deserialize(istringstream& in) {
        string valS;
        in >> valS;
        if(valS == "null") {
            return NULL;
        } else {
            TreeNode* cur = new TreeNode(str2int(valS));
            cur->left = _deserialize(in);
            cur->right = _deserialize(in);
            return cur;
        }
    }
public:
    string serialize(TreeNode* root) {
        ostringstream out;
        _serialize(root, out);
        return out.str();
    }

    TreeNode deserialize(string data) {
        istringstream in(data);
        return _deserialize(in);
    }
};

int main() {
    TreeNode* root
}