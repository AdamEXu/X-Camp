def ways(n, m):
    stairs = [1]
    for _ in range(n):
        stairs.append(sum(stairs))
        if len(stairs) > m:
            stairs.pop(0)
        return stairs[-1]

def way(n, knownWays = {}):
    if n <= 1:
        return 1
    if n not in knownWays:
        knownWays[n]

n = input("n: ")            
m = input("m: ")
print(ways(int(n), int(m)))