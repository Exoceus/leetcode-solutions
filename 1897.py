class Solution:
    def makeEqual(self, words: List[str]) -> bool:
        return self.letter_freq_divisibility(words)

    # blind
    def letter_freq_divisibility(self, words):
        occurrences = [0] * 26 # could easily use dict for better readability

        for word in words:
            for letter in word:
                occurrences[ord(letter) - 97] += 1
        
        for occurrence in occurrences:
            if occurrence % len(words) != 0:
                return False

        return True
