n = int(input())
ls = []
for i in range(n):
    ls.append(int(input()))
ls.sort(reverse=True)
reverse = False
for i in range(0, n, 1):
    if not reverse:
        print(ls[i//2])
        reverse = True
    else:
        print(ls[n-i//2-1])
        reverse = False