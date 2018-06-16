#include <bits/stdc++.h>
using namespace std;

// Complete the has_cycle function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
bool has_cycle(SinglyLinkedListNode* head) {

    if(head == NULL || head->next == NULL){
        return false;
    }
    vector<SinglyLinkedListNode*> vis;
    SinglyLinkedListNode* curr = head;
    while(curr != NULL){
        if(find(vis.begin(), vis.end(), curr) == vis.end()){
            vis.push_back(curr);
            curr = curr->next;
        } else{
            return true;
        }
    }
    return false;
}