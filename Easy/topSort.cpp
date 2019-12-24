/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */

class Solution {
public:
    /*
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*>& graph) {
        // write your code here
        unordered_map<DirectedGraphNode *,int > mp;
        queue<DirectedGraphNode *> qq;
        vector<DirectedGraphNode*> ans;
        
        for(auto node:graph){
            for(auto nei:node->neighbors){
                mp[nei]+=1;
            }
        }
        
        for(auto node:graph){
            if(mp[node]==0){
                qq.push(node);
                ans.push_back(node);
            }
        }
        while(!qq.empty()){
            DirectedGraphNode * now = qq.front();
            qq.pop();
            for(auto next:now->neighbors){
                mp[next]-=1;
                if(mp[next]==0){
                    qq.push(next);
                    ans.push_back(next);
                }
            }
        }//while
        return ans;
    }
};
