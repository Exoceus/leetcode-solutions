class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        return self.naive(s)

    # blind
    def naive(self, s):
        # using a function like strip in python would have made this a lot cleaner
        # but I wanted to go for a more language agnostic solution
        prev_word = ""
        current_word = ""

        for letter in s:
            if letter != ' ':
                current_word += letter
            else:
                if current_word != "":
                    prev_word = current_word
                current_word = ""
        
        if current_word != "":
            prev_word = current_word
        
        return len(prev_word)
