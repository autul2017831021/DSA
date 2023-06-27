# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def frequentTreeSum(self, root=None)->int:
        if not root:
            return 0

        left =  self.frequentTreeSum(root.left)
        right = self.frequentTreeSum(root.right)
        
        treeSum = root.val + left + right
        self.freq_dict[treeSum] += 1
        self.max_freq = max(self.max_freq,self.freq_dict[treeSum])
        return treeSum
        
    def findFrequentTreeSum(self, root: Optional[TreeNode]) -> List[int]:
        self.freq_dict = collections.defaultdict(int)
        self.max_freq = 0
        self.ans = []
        self.frequentTreeSum(root)
        for key,value in self.freq_dict.items():
            if value == self.max_freq:
                self.ans.append(key)
        return self.ans

