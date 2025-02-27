#include <bits/stdc++.h>

using namespace std;

class ListNode{
public:
    int val;
    vector<ListNode*> neighbors;

    ListNode(){
        val = 0;
        neighbors = vector<ListNode*>();
    }

    ListNode(int _val){
        val = _val;
        neighbors = vector<ListNode*>();
    }

    ListNode(int _val, vector<ListNode*> _neighbors){
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution{
public:
    ListNode* cloneGraph(ListNode* node){
        if(node == nullptr) return nullptr;

        if(const auto it = map.find(node); it != map.cend()) return it->second;

        ListNode* newNode = new ListNode(node->val);
        map[node] = newNode;

        for(ListNode* n : node->neighbors)
            newNode->neighbors.push_back(cloneGraph(n));

        return newNode;
    }

private:
    unordered_map<ListNode*, ListNode*> map;
};

