#include <bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {

    TreeNode* firstElement;
    TreeNode* secondElement;
    TreeNode* prevElement;

    void traverse(TreeNode* root){

        if(root == NULL){
            return;
        }

        traverse(root->left);

        if(firstElement == NULL && prevElement->val >= root->val){
            firstElement = prevElement;
        }
        if(firstElement != NULL && prevElement->val >= root->val){
            secondElement = root;
        }
        prevElement = root;

        traverse(root->right);
    }

public:
    void recoverTree(TreeNode* root) {

        firstElement = secondElement = NULL;
        prevElement = new TreeNode(INT_MIN);

        traverse(root);

        int tmp = firstElement->val;
        firstElement->val = secondElement->val;
        secondElement->val = tmp;
    }
};

int main(){

    return 0;
}