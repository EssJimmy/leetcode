#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int _val) : val(_val), next(nullptr) {}
    ListNode(int _val, ListNode *_next) : val(_val), next(_next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummyHead = ListNode(0);
        ListNode *head = &dummyHead;
        int carry = 0;

        while(l1 || l2 || carry) {
            if(l1) {
                carry += l1->val;
                l1 = l1->next;
            }

            if(l2) {
                carry += l2->val;
                l2 = l2->next;
            }

            head->next = new ListNode(carry % 10);
            carry /= 10;
            head = head->next;
        }

        return dummyHead.next;
    }
};