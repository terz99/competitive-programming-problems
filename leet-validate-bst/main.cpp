#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode();
    TreeNode(int x);
    static void insert(TreeNode *p, int i, int a[], int n){

        int left = 2*i + 1;
        int right = left + 1;
        // cout << i << " " << left << " " << right << endl;
        if(left < n){
            p->left = new TreeNode(a[left]);
            insert(p->left, left, a, n);
        }
        if(right < n){
            p->right = new TreeNode(a[right]);
            insert(p->right, right, a, n);
        }
    }
    static void print(TreeNode *p){
        
        if(p->left != NULL) print(p->left);
        cout << p->val << " ";
        if(p->right != NULL) print(p->right);
    }    
};

TreeNode::TreeNode(){}

TreeNode::TreeNode(int x) : val(x), left(NULL), right(NULL) {}


class Solution {
public:

    void inOrderTraversal(TreeNode *root, vector<int> &v){

        if(root->left != NULL) inOrderTraversal(root->left, v);
        v.push_back(root->val);
        if(root->right != NULL) inOrderTraversal(root->right, v);
    }

    bool isValidBST(TreeNode* root) {
        
        if(root == NULL){
            return true;
        }
        vector<int> v;
        inOrderTraversal(root, v);
        for(int i = 0; i < v.size()-1; i++){
            if(!(v[i+1] > v[i])){
                return false;
            }
        }
        return true;
    }
};

int main(){

    int n;
    cin >> n;
    int a[n+5];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    TreeNode *root;
    root = new TreeNode(a[0]);
    TreeNode::insert(root, 0, a, n);
    TreeNode::print(root);
    cout << endl;

    Solution sol;
    if(sol.isValidBST(root)){
        cout << "Valid\n";
    } else {
        cout << "Not Valid\n";
    }

    return 0;
}