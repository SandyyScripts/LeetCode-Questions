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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int k=0;
        ListNode* temp=head;
        while(temp){
            temp=temp->next;
            k++;
        }
        if(k==1 && n==1) return NULL;
        if(n==k) return head->next;
        temp=head;
        k = k - n;
        while(k>1){
            temp=temp->next;
            k--;
        }
        temp->next=temp->next->next;
        return head;
    }
};