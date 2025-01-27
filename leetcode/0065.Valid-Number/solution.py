class Solution:
    # @param {string} s
    # @return {boolean}
    def isNumber(self, s: str) -> bool:
        INVALID=0; SPACE=1; SIGN=2; DIGIT=3; DOT=4; EXPONENT=5;
        #0invalid,1space,2sign,3digit,4dot,5exponent,6num_inputs
        transitionTable=[[-1,  0,  3,  1,  2, -1],    #0 no input or just spaces 
                         [-1,  8, -1,  1,  4,  5],    #1 input is digits 
                         [-1, -1, -1,  4, -1, -1],    #2 no digits in front just Dot 
                         [-1, -1, -1,  1,  2, -1],    #3 sign 
                         [-1,  8, -1,  4, -1,  5],    #4 digits and dot in front 
                         [-1, -1,  6,  7, -1, -1],    #5 input 'e' or 'E' 
                         [-1, -1, -1,  7, -1, -1],    #6 after 'e' input sign 
                         [-1,  8, -1,  7, -1, -1],    #7 after 'e' input digits 
                         [-1,  8, -1, -1, -1, -1]]    #8 after valid input input space
        state = 0
        for c in s:
            inputtype = INVALID
            if c == ' ':
                inputtype = SPACE
            elif c == '-' or c == '+': 
                inputtype = SIGN
            elif c.isdigit(): 
                inputtype = DIGIT
            elif c == '.': 
                inputtype = DOT
            elif c.upper() == 'E': 
                inputtype = EXPONENT
            state = transitionTable[state][inputtype]
            if state == -1: 
                return False
    
        return state == 1 or state == 4 or state == 7 or state == 8