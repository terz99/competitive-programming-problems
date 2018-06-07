#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int carry){

        if(l1 == NULL && l2 == NULL){

            if(carry){
                return new ListNode(carry);
            }

            return NULL;

        } else if(l1 == NULL){
            
            ListNode* l = new ListNode((l2->val + carry)%10);
            carry = (l2->val + carry)/10;
            l->next = addTwoNumbers(l1, l2->next, carry);
            return l;

        } else if(l2 == NULL){

            ListNode* l = new ListNode((l1->val + carry)%10);
            carry = (l1->val + carry)/10;
            l->next = addTwoNumbers(l1->next, l2, carry);
            return l;

        } else {

            ListNode* l = new ListNode((l1->val + l2->val + carry)%10);
            carry = (l1->val + l2->val + carry)/10;
            l->next = addTwoNumbers(l1->next, l2->next, carry);
            return l;
        }
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = addTwoNumbers(l1, l2, 0);
        return res;        
    }
};

int main(){

    

    return 0;
}