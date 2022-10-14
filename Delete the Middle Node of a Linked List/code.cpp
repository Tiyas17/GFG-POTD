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
    ListNode* deleteMiddle(ListNode* head) {
        long long int tn=0;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            tn++;
            temp=temp->next;
        }
        if(tn%2==0)
        {
            tn=tn/2 + 1;
        }
        else{
            tn=(tn+1)/2;
        }
        if(tn==1)
        return head->next;
        long long int i=1;
        temp=head;
        ListNode* prev=NULL;
        while(i!=tn && temp!=NULL)
        {
            i++;
            prev=temp;
            temp=temp->next;
        }
        prev->next=temp->next;
        return head;
    }
};
