#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {

    int res;
    int maxDepth;
    void findBottomLeftValueUtil(TreeNode* root, int depth, bool isLeft){

        // check if is a child
        if(root->left == NULL && root->right == NULL){
            if(depth > maxDepth){
                res = root->val;
                maxDepth = depth;
            }
            return;
        }

        if(root->left != NULL){
            findBottomLeftValueUtil(root->left, depth+1, true);
        }
        if(root->right != NULL){
            findBottomLeftValueUtil(root->right, depth+1, false);
        }
    }

public:
    int findBottomLeftValue(TreeNode* root) {
        maxDepth = 0;
        findBottomLeftValueUtil(root, 0, true);
        return res;
    }
};

int main(){

    

    return 0;
}