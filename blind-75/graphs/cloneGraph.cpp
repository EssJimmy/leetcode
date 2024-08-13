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

Node* cloneGraph(Node* node) {
    if (node == nullptr)
      return nullptr;

    queue<Node*> q{{node}};
    unordered_map<Node*, Node*> map{{node, new Node(node->val)}};

    while (!q.empty()) {
      Node* u = q.front();
      q.pop();
      for (Node* v : u->neighbors) {
        if (map.find(v) != map.end()) { //map.contains(v) is better here but compiler gets nitpicky
          map[v] = new Node(v->val);
          q.push(v);
        }
        map[u]->neighbors.push_back(map[v]);
      }
    }

    return map[node];
}