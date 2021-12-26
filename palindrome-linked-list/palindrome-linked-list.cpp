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
    ListNode* reverse(ListNode* dummy){
        if(dummy==NULL){
            return dummy;
        }
        ListNode* prev=NULL;
        ListNode* nextptr=NULL;
        while(dummy->next){
            nextptr=dummy->next;
            dummy->next=prev;
            prev=dummy;
            dummy=nextptr;    
        }
        dummy->next=prev;
        return dummy;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        // slow will reach to mid
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        // reversing all nodes after the mid node(second half)
        slow->next = reverse(slow->next);
        
        // again starting
        ListNode* start = head;
        slow = slow->next;
        while(slow){
            if(slow->val!=start->val){
                return false;
            }
            slow=slow->next;
            start=start->next;
        }
        return true;
    }
};