import numpy as np

def is_safe(ll: list) -> bool:
    l = [ll[i] - ll[i + 1] for i in range(len(ll) - 1)]
    if l[0] > 0:
        positive = True
    else:
        positive = False

    for i in l:
        if i < 0 and positive:
            return False
        elif i > 0 and not positive:
            return False
        elif abs(i) < 1 or abs(i) > 3:
            return False
    return True


def is_safe_advanced(ll: list) -> list[bool, int]:

    if ll[0] - ll[1] > 0:
        decreasing = True
    elif ll[0] == ll[1]:
        lll = np.delete(ll, [0])
        if is_safe(lll):
            #print(ll, True)
            return (True, ll[0])
        else:
            #print(ll, False)
            return (False, None)
    else:
        decreasing = False
    pokus = 0
    num = None
    for i in range(len(ll) - 1):
        if ll[i] - ll[i + 1] < 0 and decreasing:
            lll = np.delete(ll, [i + 1])
            num = ll[i+1]
            #print(f"Removing the number {ll[i + 1]} on index {i + 1}, it was decreasing but now bigger number was detected")
            if pokus == 0 and not is_safe(lll):
                return (False, None)
            pokus = 1
        elif ll[i] - ll[i + 1] > 0 and not decreasing:
            lll = np.delete(ll, [i + 1])
            num = ll[i+1]
            #print(f"Removing the number {ll[i + 1]} on index {i + 1}, it was increasing but now lower number was detected")
            if pokus == 0 and not is_safe(lll):
                return (False, None)
            pokus = 1
        elif abs(ll[i] - ll[i + 1]) < 1 or abs(ll[i] - ll[i + 1]) > 3:
            lll = np.delete(ll, [i + 1])
            num = ll[i]
            #print(f"Removing the number {ll[i + 1]} on index {i + 1}, one of the numbers are the same or the difference is bigger than 3.")
            if pokus == 0 and not is_safe(lll):
                return (False, None)
            pokus = 1
    
    return (True, num)


if __name__ == "__main__":
    sum = 0
    with open("02/02.txt", "r") as txt:
        for line in txt:
            ll = np.array(line.split(" "), dtype=int)
            bo, num = is_safe_advanced(ll)
            print(ll, bo, num)
            if bo:
                sum += 1
    print(sum)
