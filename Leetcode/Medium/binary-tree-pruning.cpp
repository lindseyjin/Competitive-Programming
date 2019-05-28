/**
 * Question: remove all subtrees that do not contain 1 from a binary tree 
 *
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        
        // recursion
        if(root->left != NULL)
            root->left = pruneTree(root->left);
        if (root->right != NULL) 
            root->right = pruneTree(root->right);
        
        // leaf nodes, recursion finished
        if (root->val == 0 && root->left == NULL && root->right == NULL) {
            root = NULL;
        } 
        return root;
    }
};