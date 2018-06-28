#include<cstdio>
#include<cstdlib>
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int height;
};
Node* balance_node(struct Node* node, int data);
struct Node* deleteNode(struct Node* root, int data);
int max(int a, int b);
int height(struct Node *N)
{
    if (N == nullptr)
        return 0;
    return N->height;
}
int max(int a, int b)
{
    return (a > b)? a : b;
}
struct Node* newNode(int data)
{
    auto * node = (struct Node*)
            malloc(sizeof(struct Node));
    node->data   = data;
    node->left   = nullptr;
    node->right  = nullptr;
    node->height = 1;
    return(node);
}
struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;
    return x;
}
struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;
    return y;
}
int getBalance(struct Node *N)
{
    if (N == nullptr)
        return 0;
    return height(N->left) - height(N->right);
}

struct Node* insert(struct Node* node, int data)
{
    if (node == nullptr)
        return(newNode(data));

    if (data < node->data)
        node->left  = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else
        return node;
    node->height = 1 + max(height(node->left),height(node->right));
    int balance = getBalance(node);
    if (balance > 1 && data < node->left->data)
        return rightRotate(node);
    if (balance < -1 && data > node->right->data)
        return leftRotate(node);
    if (balance > 1 && data > node->left->data)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && data < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

struct Node * minValueNode(struct Node* node)
{
    struct Node* current = node;
    while (current->left != nullptr)
        current = current->left;

    return current;
}
int heigh(struct Node* Node)
{
    /* base case tree is empty */
    if(Node == nullptr)
        return 0;

    /* If tree is not empty then height = 1 + max of left
       height and right heights */
    return 1 + max(heigh(Node->left), heigh(Node->right));
}
bool isBalanced(struct Node *root)
{
    int lh; /* for height of left subtree */
    int rh; /* for height of right subtree */

    /* If tree is empty then return true */
    if(root == nullptr)
        return true;

    /* Get the height of left and right sub trees */
    lh = heigh(root->left);
    rh = heigh(root->right);

    return abs(lh - rh) <= 1 &&
           isBalanced(root->left) &&
           isBalanced(root->right);

    /* If we reach here then tree is not height-balanced */
}
int _B_(Node *root)
{
    if(root==nullptr)
        return 0;
    int lH = _B_(root->left);
    if(lH==-1)return -1;
    int rH = _B_(root->right);
    if(rH==-1)
        return -1;
    if(abs(lH-rH)>1)
        return -1;
    return max(lH,rH)+1;
}
bool _B(Node *root)
{
    return _B_(root) != -1;
}
bool I_(Node* root)
{
    static struct Node *prev = nullptr;

    if (root)
    {
        if (!I_(root->left))
            return false;

        if (prev != nullptr && root->data <= prev->data)
            return false;

        prev = root;

        return I_(root->right);
    }

    return true;
}
vector<int> z;
void inOrder(struct Node *root)
{
    if(root != nullptr)
    {

        inOrder(root->left);
        z.push_back(root->data);
        inOrder(root->right);
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a;
        struct Node *root = nullptr;
        for(int i=0;i<n;i++){
            int k;
            cin>>k;
            a.push_back(k);
            root = insert(root, k);
        }
        int k;
        cin>>k;
        root = deleteNode(root, k);
        bool f=true;
        if(!isBalanced(root)){
            f=false;
        }

        z.clear();
        inOrder(root);
        set<int> s(a.begin(),a.end());
        vector<int>zz(s.begin(),s.end());
        if(z.size()!=zz.size()-1){
            f=false;
        }
        if(f)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
    return 0;
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*Complete the following function
Node is as follows:
struct Node
{
    int data;
    Node *left;
    Node *right;
    int height;
};
*/

Node* deleteNode(Node* root, int data)
{
    if(root == nullptr){
        return root;
    }

    if(data < root->data){
        root->left = deleteNode(root->left, data);
    } else if(data > root->data){
        root->right = deleteNode(root->right, data);
    } else {

        if(root->left == nullptr || root->right == nullptr){

            Node* tmp = root->left ? root->left : root->right;
            if(tmp == nullptr){
                tmp = root;
                root = nullptr;
            } else {
                *root = *tmp;
            }
            delete tmp;
        } else {
            Node* tmp = minValueNode(root->right);
            root->data = tmp->data;
            root->right = deleteNode(root->right, tmp->data);
        }
    }

    if(root == nullptr){
        return root;
    }

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);
    if(balance > 1 && getBalance(root->left) >= 0){
        // left left case
        return rightRotate(root);
    }

    if(balance > 1 && getBalance(root->left) < 0){
        // left right case
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if(balance < -1 && getBalance(root->right) <= 0){
        // right right case
        return leftRotate(root);
    }

    if(balance < -1 && getBalance(root->right) > 0){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}