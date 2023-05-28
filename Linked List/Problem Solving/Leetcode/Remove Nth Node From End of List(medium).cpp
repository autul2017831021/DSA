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
    int getSize(ListNode* l1){
        int x=0;
        ListNode* curr = l1;
        while(curr != NULL){
            x++;
            curr = curr->next;
        }
        return x;
    }
    void pop(ListNode** head,int index){
        ListNode* curr = *head;
        ListNode* prev = *head;
        if(index==1){
            (*head) = (*head)->next;
            delete curr;
            return;
        }
        int i = 1;
        while(curr != NULL && i<index){
            i++;
            prev = curr;
            curr = curr->next;
        }
        if(curr == NULL)return;
        prev->next = curr->next;
        delete curr;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int s = getSize(head);
        int x = s-n+1;
        pop(&head,x);
        return head;
    }
};