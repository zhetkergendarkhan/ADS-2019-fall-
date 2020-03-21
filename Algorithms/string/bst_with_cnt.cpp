#include<iostream>
#include<vector>

using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
	int cnt;
	Node(int data) {
		this->data = data;
		left = NULL;
		right = NULL;
		this->cnt = 1;
	} 
};

Node* getMin(Node* root) {
	while (root->left != NULL) {
		root = root->left;
	}
	return root;
}

Node* toFind(Node * root, int x) {
	if (root == NULL) {
		return NULL;
	} else if (root->data == x) {
		return root;
	} else if (root->data < x) {
		return toFind(root->right, x);
	} else {
		return toFind(root->left, x);
	}
}

Node * add(Node* root, int data) {
	Node * n = toFind (root, data);
	if (n != NULL){
		n->cnt++;
	}
	else {
	if (root == NULL) {
		// cout << "The root is created" << endl;
		return new Node(data);
	} else if (root->data > data) {
		if (root->left == NULL) {
			root->left = new Node(data);
		} else {
			root->left = add(root->left, data);
		}
	} else if (root->data < data) {
		if (root->right == NULL) {
			root->right = new Node(data);
		} else {
			root->right = add(root->right, data);
		}
	}
	return root;
}
}

Node* deleteNode(Node* root, int data) {
	Node * n = toFind(root, data);
	if (n != NULL and n->cnt > 1){
		n->cnt--;
	}
	else {
	if (root == NULL) {
		return NULL;
	} else if (root->data > data) {
		root->left = deleteNode(root->left, data);
		return root;
	} else if (root->data < data) {
		root->right = deleteNode(root->right, data);
		return root;
	} else {
		if (root->left == NULL && root->right == NULL) {
			delete root;
			return NULL;
		} else if (root->right == NULL) {
			Node* temp = root->left;
			delete root;
			return temp;
		} else if (root->left == NULL) {
			Node* temp = root->right;
			delete root;
			return temp;
		} else {
			Node* temp = getMin(root->right);
			root->data = temp->data;
			root->right = deleteNode(root->right, temp->data);
			return root;
		}
	}
}
}

int count(Node * root, int x){
	Node * temp = root;
	Node * n = toFind(temp, x);
	if (n != NULL){
		return n->cnt;
	}
	// cout <<"not found" << endl;
	return 0;
}
 
int main(){
	int n;
	cin >> n;
	string s;
	int temp;
	Node * root = NULL;
	
	for (int i = 0; i < n; ++i)
	{
		cin >> s;
		if (s == "insert"){
			cin >> temp;
			root = add(root, temp);
		}
		else if (s == "cnt"){
			cin >> temp;
			cout << count(root, temp) << endl;
		}
		else if (s == "delete"){
			cin >> temp;
			root = deleteNode(root, temp);
		}
	}
	


	return 0;
}

