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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL)return head;
        ListNode* curr = head;
        ListNode* temp = head;
        ListNode* first = NULL;
        ListNode* second = NULL;
        ListNode* prev = head;
        bool f=1;
        while(curr != NULL && curr->next != NULL){
            first = curr;
            second = curr->next;
            temp = second;
            first->next = temp->next;
            second->next = first;
            if(f){
                head = second;
                f=0;
                prev = head->next;
                curr = first->next;
                continue;
            }
            prev->next = second;
            prev = second->next;
            curr = first->next;
        }
        return head;
    }
};