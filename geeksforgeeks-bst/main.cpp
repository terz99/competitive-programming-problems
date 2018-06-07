#include <iostream>
using namespace std;

struct Node{

    int data;
    Node *left;
    Node *right;
};

int largestBSTUtil(Node *node, int& minn, int& maxx, int& maxSize, bool& isBst){

    if(node == NULL){
        isBst = true;
        return 0;
    }

    int rightSize, leftSize;
    bool leftFlag = false;
    bool rightFlag = false;

    int tmp_min = INT32_MAX;

    maxx = INT32_MIN;
    leftSize = largestBSTUtil(node->left, minn, maxx, maxSize, isBst);
    if(node->data > maxx && isBst)
        leftFlag = true;

    tmp_min = minn;
    minn = INT32_MAX;
    rightSize = largestBSTUtil(node->right, minn, maxx, maxSize, isBst);
    if(node->data < minn && isBst){
        rightFlag = true;
    }

    if(tmp_min < minn){
        minn = tmp_min;
    }
    if(node->data > maxx){
        maxx = node->data;
    }
    if(node->data < minn){
        minn = node->data;
    }

    if(leftFlag && rightFlag){

        maxSize = max(maxSize, rightSize + leftSize + 1);
        return rightSize + leftSize + 1;
    } else {
        isBst = false;
        return 0;
    }
}

int largestBST(Node *root){

    int minn = INT32_MAX;
    int maxx = INT32_MIN;
    int maxSize = 1;
    bool isBst = false;
    return largestBSTUtil(root, minn, maxx, maxSize, isBst);
}

int main(){



    return 0;
}
