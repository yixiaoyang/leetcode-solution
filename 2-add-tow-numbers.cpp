#include "includes.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// memory leak
class AddTwoNumbersSolution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        int sum = 0;
        ListNode* pos1 = l1;
        ListNode* pos2 = l2;

        ListNode* res = NULL;
        ListNode* resLast = res;
        ListNode* newNode = NULL;

        int pos1Val;
        int pos2Val;
        for(pos1 = l1, pos2 = l2;
            pos1 != NULL || pos2 != NULL;){
                pos1Val = pos1 ? pos1->val: 0;
                pos2Val = pos2 ? pos2->val: 0;
                sum = pos1Val+pos2Val+carry;
                carry = sum/10;

                newNode = new ListNode(sum%10);
                if(!res){
                    res = newNode;
                    resLast = res;
                }else{
                    resLast->next = newNode;
                    resLast = newNode;
                }

                if(pos1)
                    pos1 = pos1->next;
                if(pos2)
                    pos2 = pos2->next;
        }


        if(carry != 0){
            resLast->next = new ListNode(carry);
            resLast->next->next = NULL;
        }

        return res;
    }
};

int main2()
{
    AddTwoNumbersSolution solu;

    ListNode list1[2]={
        ListNode(2),
        ListNode(4)
    };
    ListNode list2[3]={
        ListNode(9),
        ListNode(6),
        ListNode(4)
    };
    list1[0].next = &list1[1];
    list2[0].next = &list2[1];
    list2[1].next = &list2[2];

    ListNode* l1 = list1;
    ListNode* l2 = list2;

    ListNode *res = solu.addTwoNumbers(l1,l2);
    ListNode *resPos = res;
    ListNode *resDel = NULL;

    while(resPos){
        resDel = resPos;
        cout << resPos->val << " ";

        resPos = resPos->next;
        delete resDel;
    }

    return 0;
}
