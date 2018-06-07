#include <bits/stdc++.h>
using namespace std;

/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


 struct Node{
     int data;
     Node* left, *right;
}; 

int diameterUtil(Node* node, int& res){

    if(node == NULL){
        return 0;
    }

    int ls = diameterUtil(node->left, res);
    int rs = diameterUtil(node->right, res);

    res = max(res, ls + rs + 1);

    if(node->left && node->right){
        return max(ls, rs) + 1;
    } else {
        return ((node->left) ? ls : rs) + 1;
    }
}

/* Computes the diameter of binary tree with given root.  */
int diameter(Node* node){

    int res = 0;
    diameterUtil(node, res);
    return res;
}

int main(){
    return 0;
}