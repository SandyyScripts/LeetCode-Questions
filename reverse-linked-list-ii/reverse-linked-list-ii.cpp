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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL){
            return head;
        }
        ListNode* prev=NULL;
        ListNode* current=head;
        while(left>1){
            prev=current;
            current=current->next;
            left--;
            right--;
        }
        ListNode* start=prev;
        ListNode* tail=current;
        ListNode* nextptr=NULL;
        while(right>0){
            nextptr=current->next;
            current->next=prev;
            prev=current;
            current=nextptr;
            right--;
        }
        if(start!=NULL){
            start->next=prev;
        }
        else{
            head=prev;
        }
        tail->next=current;
        return head;
    }
};