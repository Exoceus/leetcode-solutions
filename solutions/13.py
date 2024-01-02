class Solution:
    def romanToInt(self, s: str) -> int:
        return self.value_table(s)

    # blind
    def conditionals(self, s):
        value = 0
        i = 0

        # pretty trivial
        while i < len(s):
            curr = s[i]
            if i < len(s) - 1:
                nex = s[i + 1]
                match = False
                if curr == "I":
                    if nex == "V":
                        value += 4
                        match = True
                    elif nex == "X":
                        value += 9
                        match = True
                elif curr == "X":
                    if nex == "L":
                        value += 40
                        match = True
                    elif nex == "C":
                        value += 90
                        match = True
                elif curr == "C":
                    if nex == "D":
                        value += 400
                        match = True
                    elif nex == "M":
                        value += 900
                        match = True

                if match:
                    i += 2
                    continue

            if curr == "I":
                value += 1
            elif curr == "V":
                value += 5
            elif curr == "X":
                value += 10
            elif curr == "L":
                value += 50
            elif curr == "C":
                value += 100
            elif curr == "D":
                value += 500
            elif curr == "M":
                value += 1000

            i += 1

        return value

    # blind
    def value_table(self, s):
        # is much more cleaner in terms of logic
        values = {
            "I": 1,
            "V": 5,
            "X": 10,
            "L": 50,
            "C": 100,
            "D": 500,
            "M": 1000,

        # these could be potentially automated such that 
        # for every quantity that is a factor of 10, 
        # we generate the combination of the corresponding "5" value and for the next factor of 10
            "IV": 4,
            "IX": 9,
            "XL": 40,
            "XC": 90,
            "CD": 400,
            "CM": 900,
        }

        value = 0
        i = 0

        while i < len(s):
            # if possible try 2 char lookup first, then fall back to single char key lookup
            if i < len(s) - 1 and s[i:i+2] in values:
                value += values[s[i:i+2]]
                i += 2
            else:
                value += values[s[i]]
                i += 1
        
        return value


