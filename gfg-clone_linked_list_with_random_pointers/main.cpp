/**
 * @author  Dushan Terzikj
 *
 * @since   1.0.0
 * @version 1.0.0
*/
#include <bits/stdc++.h>
using namespace std;

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

// the node structure is as follows
struct Node{
    int data;
    Node* next;
    Node* arb;
    Node(){
        next = arb = nullptr;
    }
    Node(const int& data){
        this->data = data;
    }
};
// Should return the head of the copied linked list the
//output will be 1 if successfully copied
Node * copyList(Node *head){

    if(!head){
        Node *ret = nullptr;
        return ret;
    }

    Node* curr = head;
    while(curr){
        Node* tmp = curr->next;
        curr->next = new Node();
        curr->next->data = curr->data;
        curr->next->next = tmp;
        curr = tmp;
    }

    curr = head;
    while(curr){
        if(curr->next && curr->arb){
            curr->next->arb = curr->arb->next;
        }
        curr = curr->next ? curr->next->next : curr->next;
    }

    Node *orig, *copy;
    orig = head;
    copy = head->next;
    Node* tmp = copy;
    while(orig && copy){
        orig->next = orig->next ? orig->next->next : orig->next;
        copy->next = copy->next ? copy->next->next : copy->next;
        orig = orig->next;
        copy = copy->next;
    }
    return tmp;
}

int main()
{
    Node* start = new Node(1);
    start->next = new Node(2);
    start->next->next = new Node(3);
    start->next->next->next = new Node(4);
    start->next->next->next->next = new Node(5);

    // 1's arb points to 3
    start->arb = start->next->next;

    // 2's arb points to 1
    start->next->arb = start;

    // 3's and 4's arb points to 5
    start->next->next->arb =
                    start->next->next->next->next;
    start->next->next->next->arb =
                    start->next->next->next->next;

    // 5's arb points to 2
    start->next->next->next->next->arb =
                                      start->next;

    Node* clone = copyList(start);
    Node* curr = start;
    while(curr){
        cout << "Data: " << curr->data << endl;
        cout << "Next: " << ((curr->next) ? curr->next->data : -1) << endl;
        cout << "Arb: " << ((curr->arb) ? curr->arb->data : -1) << endl;
        curr = curr->next;
    }
    cout << endl;
    curr = clone;
    while(curr){
        cout << "Data: " << curr->data << endl;
        cout << "Next: " << ((curr->next) ? curr->next->data : -1) << endl;
        cout << "Arb: " << ((curr->arb) ? curr->arb->data : -1) << endl;
        curr = curr->next;
    }
    cout << endl;

    return 0;
}
