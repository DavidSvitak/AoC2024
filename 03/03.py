import re
with open("03/03.txt", "r") as txt:
    s = txt.read()

pattern1 = r'mul\((-?\d+),(-?\d+)\)'
pattern2 = r'do\(\)|don\'t\(\)'
pattern3 = r"do\(\)|don\'t\(\)|mul\((-?\d+),(-?\d+)\)"
ll = re.findall(pattern2, s)

tetsing = re.findall(pattern2, s)
matches = re.findall(pattern3, s)

sum = 0
measuring = True
i = 0
for num1, num2 in matches:
    if num1 == "" and num2 == "":
        if tetsing[i] == "don't()":
            measuring = False
        elif tetsing[i] == "do()":
            measuring = True
        i = i + 1
    elif measuring:
        sum = sum + int(num1)*int(num2)
print(sum)
