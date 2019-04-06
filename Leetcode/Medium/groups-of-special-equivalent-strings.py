class Solution:
    def numSpecialEquivGroups(self, A):
        """
        :type A: List[str]
        :rtype: int
        """
        
        # make as many lists of matching odds/even letters as groups ?
        
        groups = []
        
        for word in A:
            even = []
            odd = []
            for i in range(0, len(word)):
                if i%2 == 0:
                    even.append(word[i])
                else:
                    odd.append(word[i])
                    
            even.sort();
            odd.sort();
            
            if ([even, odd] not in groups):
                groups.append([even, odd])
        
        return len(groups)