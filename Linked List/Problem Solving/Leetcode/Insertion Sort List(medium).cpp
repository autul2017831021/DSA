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
    void insert_at_beginning(ListNode** head, int value){
        ListNode* newNode = createNode(value);
        newNode->next = *head;
        *head = newNode;
    }
    void push(ListNode** head,int value){
        if((*head) == NULL || value<(*head)->val){
            insert_at_beginning(head,value);
            return;
        }
        ListNode* curr = *head;
        ListNode* parentNode = *head;
        while(curr != NULL){
            if(value < curr->val){
                ListNode* newNode = createNode(value);
                parentNode->next = newNode;
                newNode->next = curr;
                return;
            }
            parentNode = curr;
            curr = curr->next;
        }
        ListNode* newNode = createNode(value);
        parentNode->next = newNode;
    }
    ListNode* insertionSortList(ListNode* head) {
        vector<int>v;
        while(head != NULL){
            v.push_back(head->val);
            head = head->next;
        }
        ListNode* ans = NULL;
        for(int i=0;i<v.size();i++){
            push(&ans,v[i]);
        }
        return ans;
    }
};