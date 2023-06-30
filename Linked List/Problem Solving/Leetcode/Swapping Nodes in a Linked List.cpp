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
    vector<int> giveNodes(ListNode* head){
        vector<int>v;
        while(head != NULL){
            v.push_back(head->val);
            head = head->next;
        }
        return v;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        int s = getSize(head);
        int m = s-k+1;
        int i = 1;
        int first,second;
        vector<int> v;
        v = giveNodes(head);
        ListNode* curr = head;
        while(curr != NULL){
            if(i==k){
                curr->val = v[m-1];
            }
            if(i==m){
                curr->val = v[k-1];
            }
            i++;
            curr = curr->next;
        }
        return head;
    }
};