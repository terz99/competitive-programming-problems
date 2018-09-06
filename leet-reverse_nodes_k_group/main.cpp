#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 1) return head;
        ListNode *fhead = new ListNode(0);
        ListNode *prev = fhead;
        prev->next = head;

        while(prev->next != nullptr && prev->next->next != nullptr){
            ListNode *begin = prev->next;
            ListNode *end = prev->next;
            ListNode *after = prev->next->next;

            bool flag = true;
            ListNode *check = after;
            for(int i = 1; i < k; i++){
                if(!check){
                    flag = false;
                    break;
                }
                check = check->next;
            }

            if(flag){

                for(int i = 1; i < k; i++){
                    if(after){
                        end->next = after->next;
                        after->next = begin;
                        prev->next = after;
                        begin = after;
                        after = end->next;
                    }
                }
            }
            prev = end;
        }
        return fhead->next;
    }
};

static const auto _ = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

int main(){

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    int n = 2;
    Solution sol;
    ListNode* res = sol.reverseKGroup(head, n);
    ListNode* curr = res;
    while(curr){
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;

    return 0;
}