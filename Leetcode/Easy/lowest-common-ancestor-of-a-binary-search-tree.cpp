/*
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
2019-10-27
*/
/**
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* lca = root;
        
        while (lca->val != p->val && lca->val != q->val) {
            if (lca->val < p->val && lca->val < q->val) lca = lca->right;
            else if (lca->val > p->val && lca->val > q->val) lca = lca->left;
            else return lca;
        }
        
        return lca;
    }
};