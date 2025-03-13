struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
    ListNode* deleteDuplicates(ListNode* head){
        if(!head||!head->next) return head;
        ListNode* start=new ListNode(0);
        start->next=head;
        ListNode* nondupl=start;
        int a=nondupl->next->val;
        while(nondupl->next&&nondupl->next->next){
                if(nondupl->next->next->val==a){
                    while(nondupl->next&&nondupl->next->val==a){
                        ListNode* temp=nondupl->next;
                        nondupl->next=nondupl->next->next;
                        temp=nullptr;
                    }
                    if(nondupl->next)
                    a=nondupl->next->val;
                }
                else{
                    nondupl=nondupl->next;
                    a=nondupl->next->val;
                }
        }
        return start->next;
    }
};