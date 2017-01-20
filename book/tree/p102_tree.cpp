#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct Node
{
	Node():has_value(false) {}
	bool has_value;
	string value;
	struct Node *left, *right;
};

void addnode(Node *head, string tmp)
{
	size_t split_index = tmp.find(',');
	size_t len1 = split_index - 1, len2 = tmp.size() - 2 - split_index;
	string value = tmp.substr(1, len1);
	string position = tmp.substr(split_index+1, len2);
	int n = position.size();
	Node* cur = head;
	for(int i = 0; i < n; i++)
	{
		if(position[i] == 'L')
		{
			if(cur->left == NULL) {cur->left = new Node();}
			cur = cur->left;
		} else {
			if(cur->right == NULL) {cur->right = new Node();}
			cur = cur->right;
		}
	}
	cur->value = value;
	cur->has_value = true;
} 

void reset(Node *node)
{
	if(node ==  NULL)
		return;
	reset(node->left);
	reset(node->right);
	node->has_value = false; 
}

//deep first search: pre_order_traversal
void pre_order_traversal(Node *node)
{
	if(node == NULL) return;
	if(node->has_value == true)
	{
		cout << node->value << " ";
		pre_order_traversal(node->left);
		pre_order_traversal(node->right);
	}
}

//breadth first search: layer traversal
void layer_traversal(Node *node)
{
	if(node == NULL || node->has_value == false) return;
	queue<Node*> q;
	q.push(node);
	Node *cur = NULL;
	while(!q.empty())
	{
		cur = q.front();
		q.pop();
		if(cur->left) q.push(cur->left);
		if(cur->right) q.push(cur->right);
		cout << cur->value << " ";
	}
}

void all_free(Node *node)
{
	if(node == NULL) return;
	all_free(node->left);
	all_free(node->right);
	delete node;
}

int main()
{
	string tmp("");
	Node* head = new Node();
	while(cin>>tmp)
	{
		if(tmp.compare("()") == 0)
		{
			layer_traversal(head);
			cout << endl;
			reset(head);
		} else {
			addnode(head, tmp);
		}
	}
	all_free(head);
}