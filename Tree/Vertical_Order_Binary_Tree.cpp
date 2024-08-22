/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void traverse(TreeNode* root, priority_queue<pair<int,pair<int,int>>,
    vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> &pq, int count,int lr){
        if(root==NULL) return;
        pq.push({lr,{count,root->val}});
        traverse(root->left,pq,count+1,lr-1);
        traverse(root->right,pq,count+1,lr+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        set<pair<int,pair<int,vector<int>>>> st;
        priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        int count=0,lr=0;
        traverse(root,pq,count,lr);
        vector<int> v;
        int x=INT_MIN;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            if(x==INT_MIN) x=it.first;
            if(x==it.first){
                v.push_back(it.second.second);
            }
            else{
                x=it.first;
                ans.push_back(v);
                v.clear();
                v.push_back(it.second.second);
            }
        }
        if(v.size())
        ans.push_back(v);
        return ans;
    }
};
```**