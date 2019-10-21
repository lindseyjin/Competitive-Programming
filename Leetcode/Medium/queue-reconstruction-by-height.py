# https://leetcode.com/problems/queue-reconstruction-by-height/solution/
# 2019-10-20

class Solution(object):
    def reconstructQueue(self, people):
        """
        :type people: List[List[int]]
        :rtype: List[List[int]]
        """
        # Idea: start from greater heights and insert each person
        # Inserting smaller numbers will not disrupt the order, at every point the queue is correct
        
        # O(n^2) solution: looping once, inserting per item
        
        # sort by descending h and ascending k
        people.sort(key=lambda x: x[1])
        people.sort(key=lambda x: x[0], reverse=True)
        
        sorted_queue = []
        
        for person in people:
            sorted_queue.insert(person[1], person)
            
        return sorted_queue