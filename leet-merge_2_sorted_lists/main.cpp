#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1 || !l2){
            return l1 ? l1 : (l2 ? l2 : nullptr);
        }

        ListNode* curr1 = l1;
        ListNode* curr2 = l2;
        ListNode* ret = nullptr;
        ListNode* currRet;
        while(curr1 && curr2){
            if(curr1->val < curr2->val){
                if(ret){
                    currRet->next = new ListNode(curr1->val);
                    curr1 = curr1->next;
                    currRet = currRet->next;
                } else {
                    ret = new ListNode(curr1->val);
                    curr1 = curr1->next;
                    currRet = ret;
                }
            } else {
                if(ret){
                    currRet->next = new ListNode(curr2->val);
                    curr2 = curr2->next;
                    currRet = currRet->next;
                } else {
                    ret = new ListNode(curr2->val);
                    curr2 = curr2->next;
                    currRet = ret;
                }
            }
        }
        while(curr1){
            currRet->next = new ListNode(curr1->val);
            curr1 = curr1->next;
            currRet = currRet->next;
        }
        while(curr2){
            currRet->next = new ListNode(curr2->val);
            curr2 = curr2->next;
            currRet = currRet->next;
        }
        return ret;
    }
};

int main(){
    return 0;
}