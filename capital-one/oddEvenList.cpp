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
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return nullptr;

        moveVal(head->next);
        return head;
    }

    void moveVal(ListNode* node){
        if(!node || !node->next) return;

        moveVal(node->next);
        int temp = node->next->val;
        node->next->val = node->val;
        node->val = temp;
    }
};