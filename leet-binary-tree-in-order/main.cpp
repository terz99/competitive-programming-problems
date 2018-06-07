#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode();
    TreeNode(int x);
    static void insert(TreeNode *p, int x){

        if(x < p->val){

            if(p->left == NULL){
                p->left = new TreeNode(x);
            } else {
                insert(p->left, x);
            }
        } else {

            if(p->right == NULL){
                p->right = new TreeNode(x);
            } else {
                insert(p->right, x);
            }
        }
    }
};

TreeNode::TreeNode(){}

TreeNode::TreeNode(int x){
    val = x;
    left = right = NULL;
}

class Solution {
public:

    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> res;

        if(root == NULL){
            return res;
        }

        if(root->left != NULL){
            vector<int> tmp = inorderTraversal(root->left);
            res.insert(res.end(), tmp.begin(), tmp.end());
        }
        res.push_back(root->val);
        if(root->right != NULL){
            vector<int> tmp = inorderTraversal(root->right);
            res.insert(res.end(), tmp.begin(), tmp.end());
        }
        return res;
    }
};

int main(){

    int n;
    cin >> n;
    TreeNode *root;
    root = NULL;
    while(n--){

        int tmp;
        cin >> tmp;
        if(root == NULL){
            root = new TreeNode(tmp);
        } else {
            TreeNode::insert(root, tmp);
        }
    }

    Solution sol;
    vector<int> res;
    res = sol.inorderTraversal(root);

    for(int i = 0; i < (int)res.size(); i++){
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}