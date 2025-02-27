#include <bits/stdc++.h>

using namespace std;

struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
   };

class Solution{
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans;
        ListNode* newList;

        if(list1->val < list2->val) 
            newList = new ListNode(list1->val);
        else 
            newList = new ListNode(list2->val);
        
        ans = newList;

        while(list1 && list2) {
            if(list1->val < list2->val) {
                newList->next = new ListNode(list1->val);
                list1 = list1->next;
            }
            else {
                newList->next = new ListNode(list2->val);
                list2 = list2->next;
            }
            newList = newList->next;
        }

        while(list1) {
            newList->next = new ListNode(list1->val);
            list1 = list1->next;
        }

        while(list2) {
            newList->next = new ListNode(list2->val);
            list2 = list2->next;
        }
        
        return ans;
    }
};