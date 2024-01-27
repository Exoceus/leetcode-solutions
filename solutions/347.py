class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        return self.using_dict(nums, k)
    
    # blind
    def using_dict(self, nums, k):
        freq = {}
        for num in nums:
            if num in freq:
                freq[num] += 1
            else:
                freq[num] = 1
        
        freq_arr = []

        for tup in freq.items():
            freq_arr.append(tup)

        # inbuilt sort is optimized
        freq_arr.sort(key=lambda item: item[1], reverse=True)
        out = []
        
        for i in range(k):
            out.append(freq_arr[i][0])

        return out
