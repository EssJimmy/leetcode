#include <bits/stdc++.h>

using namespace std;

class Node{
public:
    int val;
    vector<Node*> neighbors;

    Node(){
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val){
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors){
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution{
public:
    Node* cloneGraph(Node* node){
        if(node == nullptr) return nullptr;

        if(const auto it = map.find(node); it != map.cend()) return it->second;

        Node* newNode = new Node(node->val);
        map[node] = newNode;

        for(Node* n : node->neighbors)
            newNode->neighbors.push_back(cloneGraph(n));

        return newNode;
    }

private:
    unordered_map<Node*, Node*> map;
};

