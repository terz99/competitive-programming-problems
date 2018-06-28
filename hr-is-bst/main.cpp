#include <bits/stdc++.h>
using namespace std;

typedef unsigned int ui;

struct Node {
	int data;
	Node* left;
	Node* right;
    Node(){
        data = 0;
        left = right = NULL;
    }
    Node(const int& n_data){
        data = n_data;
        left = right = NULL;
    }
};

void get_pre_order(Node *p, vector<int>& pre_order){
    if(p->left) get_pre_order(p->left, pre_order);
    pre_order.push_back(p->data);
    if(p->right) get_pre_order(p->right, pre_order);
}

bool checkBST(Node* root) {
    if(!root) return true;
    vector<int> pre_order;
    get_pre_order(root, pre_order);
    for(ui i = 0; i < pre_order.size() - 1; i++){
        if(pre_order[i] >= pre_order[i+1]){
            return false;
        }
    }
    return true;
}

int main(){



	return 0;
}
