import numpy as np


left = []
right = []
with open("01/01.txt", "r") as txt:
    for line in txt:
        ll, rr = line.split("   ")
        left.append(int(ll))
        right.append(int(rr))

left.sort()
right.sort()

left = np.array(left)
right = np.array(right)

dif = abs(left - right)
print(sum(dif))



