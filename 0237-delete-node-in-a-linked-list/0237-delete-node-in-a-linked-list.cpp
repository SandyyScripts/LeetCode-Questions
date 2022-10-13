/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        int num=node->next->val;
        ListNode* temp=node->next->next;
        node->next=temp;
        node->val=num;
    }
};