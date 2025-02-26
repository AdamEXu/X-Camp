def hanoi(n, start, end, else1, else2):
    if n == 1:
        print_matrix(start, end, n)
        return
    elif (n==2):
        print_matrix(start, end, n-1)
    hanoi(n-2, start, else2, end, else1)
    print_matrix(start, else2, n)
    print_matrix(start, end, n)
    print_matrix(else2, end, n)
    hanoi(n-2, else1, else2, start, end)

def print_matrix(startPole, endPole, diskNum, poleB, poleC):
    print(str(startPole) + " -> " + str(endPole))

in_ = input()
hanoi(int(in_), 1, 4, 3, 2)