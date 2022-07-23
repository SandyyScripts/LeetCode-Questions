/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* temphead=NULL;
        ListNode* newhead=NULL;
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* dummy =new ListNode(0);
        
        while(curr){
            if(curr->val<x){
                dummy->next=curr;
                if(!newhead) newhead=curr;
                dummy=dummy->next;
                if(prev) prev->next=curr->next;
                curr=curr->next;
                dummy->next=NULL;
            }
            else{
                if(!temphead) temphead=curr;
                prev=curr;
                curr=curr->next;
            }
        }
        dummy->next=temphead;
        if(newhead) return newhead;
        return temphead;
    }
};