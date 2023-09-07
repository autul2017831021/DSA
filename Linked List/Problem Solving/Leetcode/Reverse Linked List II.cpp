class Solution{
public:
    vector<int> getNodes(ListNode* head, int left, int right){
        vector<int>v;
        while(head != nullptr){
            v.push_back(head->val);
            head = head->next;
        }
        while(right>=left){
            swap(v[left],v[right]);
            left++;
            right--;
        }
        return v;
    }
    ListNode* makeReversedList(vector<int>v){
        ListNode* head = new ListNode(v[0]);
        ListNode* prev = head;
        for(int i=1;i<v.size();i++){
            ListNode* temp = new ListNode(v[i]);
            prev->next = temp;
            prev = temp;
        }
        return head;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right){
        if(head == NULL || left == right)return head;
        ListNode* reversed = nullptr;
        vector<int>v;
        v = getNodes(head,left-1,right-1);
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
        return makeReversedList(v);
    }
};
        
        