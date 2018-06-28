
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int height;
};
int heigh(struct Node *Node)
{
    /* base case tree is empty */
    if(Node == nullptr)
        return 0;

    /* If tree is not empty then height = 1 + max of left
       heigh and right heights */
    return 1 + max(heigh(Node->left), heigh(Node->right));
}
bool isBalanced(struct Node *root)
{
    int lh; /* for heigh of left subtree */
    int rh; /* for heigh of right subtree */

    /* If tree is empty then return true */
    if(root == nullptr)
        return true;

    /* Get the heigh of left and right sub trees */
    lh = heigh(root->left);
    rh = heigh(root->right);

    return abs(lh - rh) <= 1 &&
           isBalanced(root->left) &&
           isBalanced(root->right);

    /* If we reach here then tree is not heigh-balanced */
}

/* UTILITY FUNCTIONS TO TEST isBalanced() FUNCTION */

/* returns maximum of two integers */


/*  The function Compute the "heigh" of a tree. Height is the
    number of Nodes along the longest path from the root Node
    down to the farthest leaf Node.*/
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
Node* insertToAVL(Node* Node, int data);
vector<int> z;
void inorder(Node *root)
{
//	z.clear();
    if(root==nullptr)
        return;
    {
        inorder(root->left);
        z.push_back(root->data);
        inorder(root->right);
    }
}
/* Drier program to test above function*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        Node *root = nullptr;
        bool f= true;
        vector<int> a;
        while(q--)
        {
            int k;
            cin>>k;
            a.push_back(k);
            root = insertToAVL(root,k);
            if(!isBalanced(root)){
                f=false;
                break;
            }
        }

        z.clear();

        inorder(root);

        set<int> s(a.begin(),a.end());
        vector<int>zz(s.begin(),s.end());
        if(z.size()!=zz.size())
            f=false;
        else{
            for(int i=0;i<z.size();i++)
            {
                if(z[i]!=zz[i])
                    f=false;
            }
        }
        if(f)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
    return 0;
}


Node* new_node(const int& data){

    Node* node = new Node();
    node->data = data;
    node->height = 1;
    node->left = node->right = nullptr;
    return node;
}

int get_balance(Node* node){
    if(node == nullptr){
        return 0;
    }
    return heigh(node->left) - heigh(node->right);
}

Node* rotate_left(Node* y){

    Node* x = y->right;
    Node* z = x->left;

    x->left = y;
    y->right = z;

    x->height = 1 + max(heigh(x->left), heigh(x->right));
    y->height = 1 + max(heigh(y->left), heigh(y->right));

    return x;
}

Node* rotate_right(Node* y){

    Node* x = y->left;
    Node* z = x->right;

    x->right = y;
    y->left = z;

    x->height = 1 + max(heigh(x->left), heigh(x->right));
    y->height = 1 + max(heigh(y->left), heigh(y->right));

    return x;
}

Node* insertToAVL( Node* node, int data)
{
    if(node == nullptr){
        node = new_node(data);
        return node;
    }

    if(data < node->data){
        node->left = insertToAVL(node->left, data);
    } else if(data > node->data){
        node->right = insertToAVL(node->right, data);
    } else {
        return node;
    }

    node->height = 1 + max(heigh(node->left), heigh(node->right));

    int balance = get_balance(node);

    if(balance > 1){

        if(data < node->left->data){
            // left left case
            return rotate_right(node);
        } else {
            // left right case
            node->left = rotate_left(node->left);
            return rotate_right(node);
        }
    } else if(balance < -1){

        if(data > node->right->data){
            // right right case
            return rotate_left(node);
        } else {
            // right left case
            node->right = rotate_right(node->right);
            return rotate_left(node);
        }
    }
    return node;
}