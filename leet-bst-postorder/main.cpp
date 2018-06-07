#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    static void insert(TreeNode *root, int x){

        if(x < root->val){

            if(root->left == NULL){
                root->left = new TreeNode(x);
            } else {
                insert(root->left, x);
            }
        } else {

            if(root->right == NULL){
                root->right = new TreeNode(x);
            } else {
                insert(root->right, x);
            }
        }
    }
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {

        vector<int> res;
        if(root == NULL){
            return res;
        }

        if(root->left != NULL){
            vector<int> tmp = postorderTraversal(root->left);
            res.insert(res.end(), tmp.begin(), tmp.end());
        }
        if(root->right != NULL){
            vector<int> tmp = postorderTraversal(root->right);
            res.insert(res.end(), tmp.begin(), tmp.end());
        }
        res.push_back(root->val);
        return res;
    }
};

int main() {

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
    vector<int> v = sol.postorderTraversal(root);
    for(int i = 0; i < (int)v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}