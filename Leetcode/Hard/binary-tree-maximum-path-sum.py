/*
https://leetcode.com/problems/binary-tree-maximum-path-sum
2019-09-01
*/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findMaxPath(self, curr):
        if not curr: return 0

        left = max(0, self.findMaxPath(curr.left))
        right = max(0, self.findMaxPath(curr.right))

        self.maxPath = max(self.maxPath, curr.val + left + right)
        return curr.val + max(left, right)
    
    def maxPathSum(self, root: TreeNode) -> int:
            
        # find max subtree
        self.maxPath = root.val
        self.findMaxPath(root)
        return self.maxPath
        
        