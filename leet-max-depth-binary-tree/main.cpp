#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {

        if(root == NULL){
            return 0;
        }

        int res = 1;
        maxDepth(root, 1, res);

        return res;
    }

private:

    void maxDepth(TreeNode* root, int currLvl, int& res){

        if(root == NULL){
            return;
        }

        res = max(res, currLvl);
        maxDepth(root->left, currLvl+1, res);
        maxDepth(root->right, currLvl+1, res);
    }
};

int main(){
    return 0;
}