#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
    int freq;
    char data;
    node * left;
    node * right;
    
}node;

typedef unsigned int ui;

bool node_has_no_children(node* n){
    return n->left == NULL && n->right == NULL;
}

void decode_huff(node * root, string s) {
    
    ui s_i = 0;
    while(s_i < s.length()){
        node* curr = root;
        bool flag = false;
        while(true){
            if(s[s_i] == '0'){
                curr = curr->left;
                if(node_has_no_children(curr)){
                    cout << curr->data;
                    flag = true;
                }
            } else {
                curr = curr->right;
                if(node_has_no_children(curr)){
                    cout << curr->data;
                    flag = true;
                }
            }
            s_i++;
            if(flag) break;
        }
    }
    cout << endl;
}