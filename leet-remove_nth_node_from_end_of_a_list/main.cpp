#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {

    int getLength(ListNode* head){
        ListNode *curr = head;
        int len = 0;
        while(curr){
            curr = curr->next;
            len++;
        }
        return len;
    }

public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = getLength(head);
        if(len == 1){
            delete head;
            return nullptr;
        }
        int currIdx = 0;
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while(currIdx < len-n){
            currIdx++;
            prev = curr;
            curr = curr->next;
        }
        if(curr->next){
            if(prev){
                prev->next = curr->next;
            } else {
                head = curr->next;
            }
            delete curr;
        } else {
            if(prev){
                prev->next = nullptr;
            } else {
                delete curr;
                return nullptr;
            }
            delete curr;
        }
        return head;
    }
};

static const auto _ = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

int main(){
    return 0;
}