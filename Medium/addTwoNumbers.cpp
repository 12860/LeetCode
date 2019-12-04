
class Solution{
    public:
    ListNode * addTwoNumbers(ListNode* l1, ListNode* l2){
        int len1 = 1;
        int len2 = 1;
        ListNode * t1 = l1;
        ListNode * t2 = l2;
        while(t1 ->next != nullptr){
            len1++;
            t1 = t1 ->next;
        }
        while(t2 ->next != nullptr){
            len2++;
            t2 = t2 ->next;
        }
        if(len1>len2){
            for(int i=1;i<=len1-len2;i++){
                t2 ->next = new ListNode(0);
                t2 = t2->next;
            }
        }
        else{
            for(int i=0;i<len2-len1;i++){
                t1 ->next = new ListNode(0);
                t1 = t1 ->next;
            }
        }//if else
        ListNode *head = new ListNode(-1);
        ListNode *w = head;
        int count = 0;
        int k = 0;
        t1 = l1;
        t2 = l2;
        while(t1 != nullptr &&t2 != nullptr){
            count = k + t1->val + t2->val;
            w->next = new ListNode(count%10);
            k = count>=10? 1:0;
            w = w->next;
            t1 = t1->next;
            t2 = t2->next;
        }
        if(k){
            w->next = new ListNode(1);
            w = w ->next;
        }
        return head->next;
    }
};
