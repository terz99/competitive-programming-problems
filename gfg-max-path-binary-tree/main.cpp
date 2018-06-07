#include <bits/stdc++.h>
using namespace std;

/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


struct Node{
	int data;
	Node *left, *right;
};

int maxPathSumUtil(Node* root, int& res){

    if(root == NULL){
        return 0;
    }

    int ls = maxPathSumUtil(root->left, res);
    int rs = maxPathSumUtil(root->right, res);

    res = max(res, ls + rs + root->data);

    if(root->left && root->right){
        return max(0, max(root->data, max(rs, ls) + root->data));
    } else {
        return max(0, max(root->data, ((root->left) ? ls : rs) + root->data));
    }
}

int maxPathSum(struct Node *root){

    if(root == NULL){
        return 0;
    }

    int res = INT_MIN;
    maxPathSumUtil(root, res);
    return res;
}

int main(){
    return 0;
}