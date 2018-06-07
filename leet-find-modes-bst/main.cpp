#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(int x);
    void insert(int x);
    static void insert(TreeNode *p, int x){

        if(x < p->val){
            if(p->left == NULL){
                p->left = new TreeNode(x);
            } else {
                insert(p->left, x);
            }
        } else {
            if(p->right == NULL){
                p->right = new TreeNode(x);
            } else {
                insert(p->right, x);
            }
        }
    }

    static void print(TreeNode *p){

        if(p->left != NULL) print(p->left);
        cout << p->val << " ";
        if(p->right != NULL) print(p->right);
    }
};

TreeNode::TreeNode(int x) : val(x), left(NULL), right(NULL){}

class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        
        int maxx = 0;
        map<int, int> vis;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){

            TreeNode *curr = q.front();
            q.pop();
            vis[curr->val]++;
            maxx = max(maxx, vis[curr->val]);
            if(curr->left != NULL) q.push(curr->left);
            if(curr->right != NULL) q.push(curr->right);
        }

        vector<int> res;
        for(map<int, int>::iterator it = vis.begin(); it != vis.end(); it++){
            if(it->second == maxx){
                res.push_back(it->first);
            }
        }

        return res;
    }
};

int main(){

    int n;
    cin >> n;
    TreeNode *root = NULL;
    while(n--){

        int tmp;
        cin >> tmp;
        if(root == NULL){
            root = new TreeNode(tmp);
        } else {
            TreeNode::insert(root, tmp);
        }
    }
    
    TreeNode::print(root);
    cout << endl;
    vector<int> res;
    Solution sol;
    res = sol.findMode(root);
    for(int i = 0; i < (int)res.size(); i++){
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}