#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
    int ht;
} node;

node *right_rotate(node *x);

node *left_rotate(node *x);

void print_bf(node *p);

node* new_node(const int& val){
    auto * n = new node();
    n->val = val;
    n->ht = 0;
    n->right = n->left = nullptr;
    return n;
}

int height(node* n){
    if(n == nullptr){
        return -1;
    }
    return n->ht;
}

int get_balance(node* n){
    if(n == nullptr){
        return 0;
    }
    return height(n->left) - height(n->right);
}



node * insert(node * root,int val) {

    if(root == nullptr){
        return new_node(val);
    }

    if(val < root->val){
        root->left = insert(root->left, val);
    } else if(val > root->val){
        root->right = insert(root->right, val);
    }

    root->ht = 1 + max(height(root->left), height(root->right));

    int balance = get_balance(root);

    // left left case
    if(balance > 1 && val < root->left->val){
        return right_rotate(root);
    }

    // right right case
    if(balance < -1 && val > root->right->val){
        return left_rotate(root);
    }

    // left right case
    if(balance > 1 && val > root->left->val){
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }

    // right left case
    if(balance < -1 && val < root->right->val){
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }

    return root;
}

node *left_rotate(node *x) {

    node* y = x->right;
    node* z = y->left;

    y->left = x;
    x->right = z;

    y->ht = 1 + max(height(y->left), height(y->right));
    x->ht = 1 + max(height(x->left), height(x->right));

    return y;
}

node *right_rotate(node *y) {

    node* x = y->left;
    node* z = x->right;

    x->right = y;
    y->left = z;
    
    y->ht = 1 + max(height(y->left), height(y->right));
    x->ht = 1 + max(height(x->left), height(x->right));

    return x;
}

void in_order(node* p){
    if(p == nullptr){
        return;
    }
    cout << p->val << "\n";
    if(p->left) {
        cout << "Going left\n";
        in_order(p->left);
        cout << "Going up\n";
    }
    if(p->right) {
        cout << "Going right\n";
        in_order(p->right);
        cout << "Going up\n";
    }
}

int main(){

    node* root;
    root = nullptr;

    int n;
    cin >> n;
    while(n--){
        int tmp;
        cin >> tmp;
        root = insert(root, tmp);
    }

    int tmp;
    cin >> tmp;
    root = insert(root, tmp);

    print_bf(root);
    cout << endl;
    in_order(root);

    return 0;
}

void print_bf(node *p) {
    if(p == nullptr){
        return;
    }
    if(p->left) print_bf(p->left);
    cout << get_balance(p) << " ";
    if(p->right) print_bf(p->right);
}