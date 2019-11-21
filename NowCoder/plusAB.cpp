/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Plus {
public:
    ListNode* plusAB(ListNode* a, ListNode* b) {
        // write code here
        ListNode* pa=a;
        ListNode* pb=b;
        ListNode* head = new ListNode(-1);
        ListNode* p = head ;
        int c = 0, sum =0;
        while(pa!=nullptr || pb !=nullptr || c!=0){
            int ta=(pa==nullptr ? 0:pa->val);
            int tb=(pb==nullptr ? 0:pb->val);
            sum = ta+tb+c;
            c = sum/10;
            sum = sum%10;
            ListNode * node = new ListNode(sum);
            p->next = node;
            p = node;
            pa = (pa==nullptr ? nullptr:pa->next);
            pb = (pb==nullptr ? nullptr:pb->next);
        }
        return head->next;
    }
};
