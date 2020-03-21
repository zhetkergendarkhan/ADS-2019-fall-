#include<bits/stdc++.h>

using namespace std;

struct node{
    int val;
    node * left;
    node * right;
    node(int x){
        val = x;
        left = NULL;
        right = NULL;
    }
};

node * add(node * root, int x){
    if(root == NULL) return new node(x);
    if(root->val < x){
        if(root->right == NULL){
            root->right = new node(x);
            return root;
        }else{
            add(root->right, x);
        }
    }else if(root->val > x){
        if(root->left == NULL){
            root->left = new node(x);
            return root;
        }else{
            add(root->left, x);
        }
    }
    return root;
}

void print(node * root){
    if(root != NULL){
        print(root->left);
        cout << root->val << " ";
        print(root->right);
    }
}

int rightmost(node * root)
{
while (root->right != NULL)
root = root->right;
return root->val;
}

node * remove(node * root, int x){
    if (root == NULL)
        return NULL;
    if (root-> val == x){
        if (root->left == NULL && root->right == NULL){
            free(root);
            return NULL;
        }
        if (root->right == NULL && root->left != NULL){
            node * temp = root->left;
            free(root);
            return temp;
        }
        if (root->left == NULL && root->right != NULL){
            node * temp = root->right;
            free(root);
            return temp;
        }
        root->val = rightmost(root->left);
        root->left = remove(root->left, root->val);
        return root;
    }
    if ( x < root->val){
        root->left = remove(root->left, x);
        return root;
    }
    if ( x > root->val){
        root->right = remove(root->right, x);
        return root;
    }
    return root;
}

node * find(node * root, int x){
    if (NULL == root)
        return NULL;
    if (x == root->val)
        return root;
    if (x < root->val)
        return find(root->left, x);
    if (x > root->val)
        return find(root->right, x);
}


int main(){
    
    int n;
    cin >> n;
    node * root = NULL;
    int x;
    for(int i = 0; i < n; ++i){
        cin >> x;
        root = add(root, x);
    }
    /*
    print(root);
    cout << endl;
    int k;
    cin >> k;
    cout << find(root, k);
    */
    cout << find(root, 6)->val;
    
    return 0;
}
