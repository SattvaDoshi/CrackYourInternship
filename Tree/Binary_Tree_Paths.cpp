class Solution {
public:
    void helper(TreeNode* root,string s,vector<string>&ans){
        if(root==NULL) return;
        // Convert the current node's value to a string and store it in 'a'
        string a=to_string(root->val);
        // If it's a leaf node, add the current path to the answer list
        if(root->left==NULL && root->right==NULL){
            s +=a;
            ans.push_back(s);
            return;
        }
        // Recursively call the helper function for left and right subtrees
        helper(root->left,s+a+"->",ans);
        helper(root->right,s+a+"->",ans);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        helper(root,"",ans);
        return ans;
    }
};