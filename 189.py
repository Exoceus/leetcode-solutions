class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        self.cuckoo(nums, k)
    
    # blind
    def naive(self, nums, k):
        # linear runtime (trivial, one loop from 0 to k, an other from k to len(nums))
        # O(n) space complexity (as sub_arr can be equal to the length of nums)
        
        k = k % len(nums)
        k_inv = len(nums) - k

        # preserve first len(nums) - k elements
        sub_arr = nums[:k_inv]

        # the first k elements can be "rotated" in place
        for i in range(k):
            nums[i] = nums[i + k_inv]
        
        # append the preserved list to end of rotated list
        for i in range(k_inv):
            nums[i + k] = sub_arr[i]
    
    # blind
    def cuckoo(self, nums, k):
        # The idea is that you pick the first element and then place it in its rotated spot
        # Then, take the element that was just kicked out and find its rotated spot and so on
        # if you arrive at the same index from where you started this process you move to the next index and repeat
        # this is kind of like cuckoo hashing
        
        # uses O(1) space complexity since everything is done in place at every step
        # and it can be probably be proved that it is linear runtime (although it would require annoying math and expectation calculations)
        total_rotated = 0
        start = None

        while total_rotated != len(nums):
            if start == None:
                start = 0
            else:
                start += 1

            temp = nums[start]
            current_i = None

            while current_i == None or current_i != start:
                if current_i == None:
                    current_i = start

                new_i = (current_i + k) % len(nums)
                new_temp = nums[new_i]

                nums[new_i] = temp
                current_i = new_i
                temp = new_temp
                total_rotated += 1

