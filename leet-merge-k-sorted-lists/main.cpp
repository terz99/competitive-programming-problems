#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<int> q;
        for(int i = 0; i < lists.size(); i++){

            while(lists[i] != NULL){
                q.push(-lists[i]->val);
                lists[i] = lists[i]->next;
            }
        }

        ListNode *res;
        res = new ListNode(-q.top()); q.pop();
        ListNode *result;
        result = res;
        result = result->next;
        while(!q.empty()){
            result = new ListNode(-q.top());
            q.pop();
            result = result->next;
        }
        return res;
    }
};

int main(){



    return 0;
}

