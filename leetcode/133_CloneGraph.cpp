#include <iostream>
#include <vector>
#include <bitset>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL) return NULL;
        
        unordered_set<int> visited;
        
        vector<UndirectedGraphNode*> S;
        
        nodeMap[node->label] = new UndirectedGraphNode(node->label);
        
        S.push_back(node);
        
        while (!S.empty()) {
            UndirectedGraphNode* n = S.back();
            S.pop_back();
            
            if (visited.count(n->label) > 0) {
                continue;
            }
            
            visited.insert(n->label);
            
            UndirectedGraphNode* copied = getNode(n->label);
            
            for (UndirectedGraphNode* nb:n->neighbors) {
                copied->neighbors.push_back(getNode(nb->label));
                if (visited.count(nb->label) == 0)
                    S.push_back(nb);
            }
        }
        return getNode(node->label);
    }
private:
    UndirectedGraphNode* getNode(int label) {
        UndirectedGraphNode* node = NULL;
        if (nodeMap.count(label) > 0) node = nodeMap[label];
        else node = nodeMap[label] = new UndirectedGraphNode(label);
        return node;
    }
    
    unordered_map<int, UndirectedGraphNode*> nodeMap;
};

void Test0()
{
    Solution sln;
    
}

int main()
{
    Test0();
    
    return 0;
}
