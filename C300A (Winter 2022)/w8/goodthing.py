n = input()
n = int(n)
for i in range(n):
    print("if (n == " + str(i+1) + ") {")
    for j in range(i+1):
        print("    cout << " + str(j+1) + " << endl;")
    print("    return 0;")
    print("}")