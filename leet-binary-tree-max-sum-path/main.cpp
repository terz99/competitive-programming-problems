#include <bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {

        if(root == NULL){
            return 0;
        }

        int res = INT_MIN;
        maxPathSumUtil(root, res);
        return res;
    }

private:

    int maxPathSumUtil(TreeNode* root, int& maxx){

        if(root == NULL){
            return 0;
        }

        int ls = maxPathSumUtil(root->left, maxx);
        int rs = maxPathSumUtil(root->right, maxx);

        maxx = max(maxx, ls + rs + root->val);

        if(root->left && root->right){
            return max(0, max(root->val, max(rs, ls) + root->val));
        } else {
            return max(0, max(((root->left) ? ls : rs) + root->val, root->val));
        }
    }
};

int main(){


    return 0;
}