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
    ListNode* createNode(int value){
        ListNode* newNode = new ListNode;
        newNode->val = value;
        newNode->next = NULL;
        return newNode;
    }
    int getSize(ListNode* l1){
        int x=0;
        ListNode* curr = l1;
        while(curr != NULL){
            x++;
            curr = curr->next;
        }
        return x;
    }
    void push(ListNode** head,int value){
        ListNode* newNode = createNode(value);
        if(*head == NULL){
            *head = newNode;
            return;
        }
        ListNode* curr = *head;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = newNode;
    }
    int pop(ListNode** head){
        ListNode* deleteThisNode = *head;
        int value = (*head)->val;
        (*head) = (*head)->next;
        delete deleteThisNode;
        return value;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int s1 = getSize(l1);
        int s2 = getSize(l2);
        int lagbe = abs(s1-s2);
        if(s1>s2){
            for(int i=0;i<lagbe;i++){
                push(&l2,0);
            }
        }
        else if(s2>s1){
            for(int i=0;i<lagbe;i++){
                push(&l1,0);
            }
        }
        ListNode* ans = NULL;
        int carry = 0;
        lagbe = max(s1,s2);
        for(int i=0;i<lagbe;i++){
            int a = pop(&l1);
            int b = pop(&l2);
            int s = (a+b+carry)%10;
            carry = (a+b+carry)/10;
            push(&ans,s);
        }
        if(carry>0){
            push(&ans,carry);
        }
        return ans;
    }
};