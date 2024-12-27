import numpy as np

left = []
right = {}
with open("01/01.txt", "r") as txt:
    for line in txt:
        ll, rr = line.split("   ")
        left.append(int(ll))
        if int(rr) in right.keys():
            right[int(rr)] += 1
        else:
            right[int(rr)] = 1

sum = 0
for ll in left:
    if ll in right.keys():
        sum = sum + ll * right[ll]
        print(ll, right[ll], sum)

print(sum)
    
    
    












