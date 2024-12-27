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


def is_safe_advanced(ll: list) -> bool:

    if ll[0] > 0:
        positive = True
    else:
        positive = False

    for i in range(len(ll) - 1):
        if ll[i] - ll[i + i] < 0 and positive:
            del ll[i + i]
            if not is_safe(ll):
                return False
        elif ll[i] - ll[i + i] > 0 and positive:
            
            pass
        elif abs(ll[i] - ll[i + i]) < 1 or abs(ll[i] - ll[i + i]) > 3:
            
            pass

    return True


if __name__ == "__main__":
    sum = 0
    with open("02/02.txt", "r") as txt:
        for line in txt:
            ll = np.array(line.split(" "), dtype=int)
            if is_safe(ll):
                sum += 1 
    print(sum)

