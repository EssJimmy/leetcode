#include <bits/stdc++.h>

using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode* random;

    ListNode (int _val) { 
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution{
public:
    ListNode* copyRandomList(ListNode* head) {
        if(!head) return nullptr;
        
        if(const auto it = mpp.find(head); it != mpp.cend())
            return it->second;

        ListNode* newNode = new ListNode(head->val);
        mpp[head] = newNode;
        newNode->next = copyRandomList(head->next);
        newNode->random = copyRandomList(head->random);
        return newNode; 
    }

private:
    unordered_map<ListNode*, ListNode*> mpp;
};