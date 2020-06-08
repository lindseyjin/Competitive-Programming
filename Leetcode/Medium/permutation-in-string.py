# https://leetcode.com/problems/permutation-in-string/
# 2020-06-07

class Solution(object):
        
    def checkInclusion(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        
        if len(s1) > len(s2): return False
        if s1 == s2: return True
        
        def createMap(s, b, e):
            m = {}
            for i in range(b, e):
                c = s[i]
                m[c] = m[c] + 1 if c in m else 1
            return m
    
        # create hashmap to count letters in s1
        letters = createMap(s1, 0, len(s1))
        window = createMap(s2, 0, len(s1))
        if letters == window: return True 
        
        i = len(s1)
        while i < len(s2):            
            n = s2[i]
            if n not in letters:
                if i+1+len(s1) >= len(s2): return False
                window = createMap(s2, i+1, i+1+len(s1))
                i += len(s1)
            else:
                if n in window:
                    window[n] += 1
                else:
                    window[n] = 1

                r = s2[i - len(s1)]
                window[r] -= 1
                if window[r] == 0: del window[r]
                    
            if letters == window: return True
            i += 1
            
        return False