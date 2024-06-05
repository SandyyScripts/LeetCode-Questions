class Solution:
    def commonChars(self, words: List[str]) -> List[str]:
        master_count = Counter(words[0])
        
        for word in words:
            count = Counter(word)
            for c in master_count.keys():
                master_count[c] = min(master_count[c],count[c])
            
        ans = []
        for x in master_count.keys():
            for y in range(master_count[x]):
                ans.append(x)
        
        return ans