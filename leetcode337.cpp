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
    int dfs(TreeNode* node, unordered_map<TreeNode*,int>& node_map){
        if(node == NULL)
            return 0;
        
        if(node_map.count(node))
            return node_map[node];
        
        int val_with_root = node->val;
        if(node->left){
            val_with_root += dfs(node->left->left,node_map);
            val_with_root += dfs(node->left->right,node_map);
        }
        if(node->right){
            val_with_root += dfs(node->right->left,node_map);
            val_with_root += dfs(node->right->right,node_map);
        }
        
        int val_without_root = 0;
        val_without_root += dfs(node->left,node_map);
        val_without_root += dfs(node->right,node_map);
        
        int ans = max(val_with_root,val_without_root);
        
        node_map[node] = ans;
        
        return ans;
    }
    int rob(TreeNode* root) {
        unordered_map<TreeNode*,int> node_map;
       
        return dfs(root,node_map);
        //return max(root->val, l+r);
    }
};
