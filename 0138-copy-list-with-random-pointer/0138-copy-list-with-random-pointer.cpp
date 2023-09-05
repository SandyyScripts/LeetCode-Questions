/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        Node* curr=head;
        unordered_map<Node*,Node*> mp;
        mp[NULL]=NULL;
        while(curr){
            Node* copy=new Node(curr->val);
            mp[curr] = copy;
            curr=curr->next;
        }
        curr=head;
        while(curr){
            Node* copy=mp[curr];
            copy->next=mp[curr->next];
            copy->random=mp[curr->random];
            curr=curr->next;
        }
        return mp[head];
    }
};