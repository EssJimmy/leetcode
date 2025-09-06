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
    ListNode* oddEvenList(ListNode* head){
        if(!head) return nullptr;
        if(!head->next || !head->next->next) return head;
        int a = 0;

        ListNode* past = head;
        ListNode* current = head->next;
        ListNode* next = current->next;

        while(next->next){
            for(int i = 0; i < a; i++) {
                next = next->next;
            }
            past->next = next;
            current->next = next->next;
            next->next = current;
            
            past = next;
            next = current->next;
            a++;
        }
            
        return head;
    }
};