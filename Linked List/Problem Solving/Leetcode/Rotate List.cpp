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
    void traverse(ListNode* head, vector<int>&v){
        while(head != NULL){
            v.push_back(head->val);
            head = head->next;
        }
    }
    void reverse(vector<int>&v,int l,int r){
        while(r>l){
            swap(v[l],v[r]);
            l++;r--;
        }
    }
    void rotate(vector<int>&v,int k){
        reverse(v,0,v.size()-k-1);
        reverse(v,v.size()-k,v.size()-1);
        reverse(v,0,v.size()-1);
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL)return head;
        // Store the values of linked-list in a vector
        vector<int>v;
        traverse(head,v);
        // Rotate the vector 
        k = k % v.size();
        rotate(v,k);
        // Update the linked-list
        ListNode* curr = head;
        int i = 0;
        while(curr != NULL){
            curr->val = v[i];
            curr = curr->next;
            i++;
        }
        return head;
    }
};