class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL){
            return l2;
        }
        if(l2==NULL){
            return l1;
        }
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        ListNode* dummy=new ListNode(0);
        ListNode* curr=dummy;
        int carry=0;

        while(temp1!=NULL || temp2!=NULL || carry!=0){
            int p,q;
            if(temp1){
                p=temp1->val;
            }
            else{
                p=0;
            }
            if(temp2){
                q=temp2->val;
            }
            else{
                q=0;
            }
           int x=p+q+carry;
            carry=x/10;

            x=x%10;
           curr->next=new ListNode(x);
           if(temp1){          
           temp1=temp1->next;
           }
           if(temp2){
           temp2=temp2->next;}
           curr=curr->next; 
        }

        return dummy->next;
    }
};
