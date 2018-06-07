#include <bits/stdc++.h>
using namespace std;


struct TreeNode{

    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(){
        left = right = NULL;
    }
    TreeNode(int x){
        val = x;
        left = right = NULL;
    }

    void static print(TreeNode* root){

        if(root == NULL) return;

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){

            TreeNode* curr;
            curr = q.front();
            q.pop();

            cout << curr->val << endl;
            if(curr->left != NULL) q.push(curr->left);
            if(curr->right != NULL) q.push(curr->right);
        }
    }
};

class Solution {

    int idxPost;

    TreeNode* buildTreeUtil(vector<int>& inorder, 
    vector<int>& postorder, int inStartIdx, int inEndIdx){

        if(inStartIdx > inEndIdx){
            return NULL;
        }

        int mid;
        for(int i = inStartIdx; i <= inEndIdx; i++){
            if(inorder[i] == postorder[idxPost]){
                mid = i;
                break;
            }
        }

        TreeNode* root;
        root = new TreeNode(postorder[idxPost]);
        idxPost--;
        root->right = buildTreeUtil(inorder, postorder, mid+1, 
        inEndIdx);

        root->left = buildTreeUtil(inorder, postorder, inStartIdx, 
        mid-1);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, 
    vector<int>& postorder) {

        idxPost = postorder.size()-1;
        if(idxPost < 0){
            return new TreeNode();
        }

        return buildTreeUtil(inorder, postorder, 0, 
        inorder.size()-1);
    }
};


int main(){

    int n;
    cin >> n;  
    vector<int> in(n);
    vector<int> post(n);

    for(int i = 0; i < n; i++){
        cin >> in[i];
    }
    for(int i = 0; i < n; i++){
        cin >> post[i];
    }

    Solution sol;
    TreeNode* root;
    root = sol.buildTree(in, post);

    TreeNode::print(root);

    return 0;
}