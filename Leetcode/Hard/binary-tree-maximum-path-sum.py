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
    def maxPathSum(self, root: TreeNode) -> int:
        
        memo = {}
        
        def findMaxPath(curr, i):
            if curr is None:
                return 0
            else:
                left = memo[2*i+1] if 2*i+1 in memo else findMaxPath(curr.left, 2*i+1)
                right = memo[2*i+2] if 2*i+2 in memo else findMaxPath(curr.right, 2*i+2)
                memo[i] = max(curr.val, curr.val + left, curr.val + right)
                return memo[i]
                
            
        def maxSubtree(curr, maxPath, i):
            subtree = curr.val
            
            if curr.left is not None:
                # recurse down left node
                m = maxSubtree(curr.left, maxPath, 2*i+1)
                if m > maxPath:
                    maxPath = m
                # calculate greatest path with curr as root
                p = findMaxPath(curr.left, 2*i+1)
                if p > 0:
                    subtree += p
                    
            if curr.right is not None:
                m = maxSubtree(curr.right, maxPath, 2*i+2)
                if m > maxPath:
                    maxPath = m
                p = findMaxPath(curr.right,  2*i+2)
                if p > 0:
                    subtree += p
                  
            if subtree > maxPath:
                maxPath = subtree
                
            return maxPath
                            
        # find max subtree
        maxPath = maxSubtree(root, root.val, 0)
        
        return maxPath
        