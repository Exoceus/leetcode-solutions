
# I was asked this question in an interview a few months ago and I just completetly blanked on how to do this without splitting words into an array.

class Solution:
    def reverseWords(self, s: str) -> str:
        return self.inplace_ish(s)

    # blind
    def word_array(self, s):
        stripped_input = ""
        current_word = ""

        for letter in s:
            if letter == " ":
                if current_word != "":
                    current_word = ""
                    stripped_input += letter
            else:
                stripped_input += letter
                current_word += letter
        
        if stripped_input[-1] == " ":
            stripped_input = stripped_input[:-1]

        words = stripped_input.split(' ')

        final = ""

        for i in range(len(words)):
            if i != 0:
                final += " "
            final += words[len(words) - 1 - i]
    
        return final

    # blind
    def inplace_ish(self, s):
        reversed = ""

        # instead of using reverse function, doing it manually to make 
        # the solution language agnostic
        for i in range(1, len(s) + 1):
            reversed += s[len(s) - i]

        i = 0
        current_word = ""
        final = ""
        carryover_space = False

        for i in range(len(reversed)):
            if reversed[i] == " ":
                if current_word == "":
                   continue
                else:
                    if carryover_space:
                        final += " "
                    for j in range(1, len(current_word) + 1):
                        final += current_word[len(current_word) - j]
                    carryover_space = True

                current_word = ""
            else:
                current_word += reversed[i]


        if current_word != "":
            if carryover_space:
                final += " "
            for j in range(1, len(current_word) + 1):
                final += current_word[len(current_word) - j]
        

        return final
