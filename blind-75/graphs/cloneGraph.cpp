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

ListNode* cloneGraph(ListNode* node) {
    if (node == nullptr)
      return nullptr;

    queue<ListNode*> q{{node}};
    unordered_map<ListNode*, ListNode*> map{{node, new ListNode(node->val)}};

    while (!q.empty()) {
      ListNode* u = q.front();
      q.pop();
      for (ListNode* v : u->neighbors) {
        if (map.find(v) != map.end()) { //map.contains(v) is better here but compiler gets nitpicky
          map[v] = new ListNode(v->val);
          q.push(v);
        }
        map[u]->neighbors.push_back(map[v]);
      }
    }

    return map[node];
}
