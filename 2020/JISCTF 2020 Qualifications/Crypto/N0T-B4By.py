
from z3 import *

data = [33385136436860330228033637194122,
        33385136436860330228033637194121,
        33385136436860330228033637194131,
        33385136436860330228033637194115,
        33385136436860330228033637194132,
        33385136436860330228033637194118,
        33385136436860330228033637194171,
        33385136436860330228033637194130,
        33385136436860330228033637194228,
        33385136436860330228033637194126,
        33385136436860330228033637194116,
        33385136436860330228033637194224,
        33385136436860330228033637194125,
        33385136436860330228033637194143,
        33385136436860330228033637194126,
        33385136436860330228033637194133,
        33385136436860330228033637194125,
        33385136436860330228033637194114,
        33385136436860330228033637194227,
        33385136436860330228033637194130,
        33385136436860330228033637194131,
        33385136436860330228033637194143,
        33385136436860330228033637194228,
        33385136436860330228033637194131,
        33385136436860330228033637194143,
        33385136436860330228033637194123,
        33385136436860330228033637194227,
        33385136436860330228033637194137,
        33385136436860330228033637194143,
        33385136436860330228033637194209,
        33385136436860330228033637194209,
        33385136436860330228033637194209,
        33385136436860330228033637194173,
        33385136436860330228033637194186]

s = Solver()

a = [BitVec('a{}'.format(i), 128) for i in range(34)]
key = BitVec('key', 128)

s.add((ord('J') ^ key) ^ key*2 == data[0])

s.check()
m = s.model()

key = m[key]

print('KEY: ', key)

s.reset()


for i in range(34):
    s.add((a[i] ^ key) ^ key*2 == data[i])

s.check()
m = s.model()

print('FLAG: ', ''.join(chr(m[a[i]].as_long()) for i in range(34)).strip())

# KEY:  12428628501003826891951326754624
# FLAG:  JISCTF{R4ND0M_NUMB3RS_4S_K3Y_!!!}
