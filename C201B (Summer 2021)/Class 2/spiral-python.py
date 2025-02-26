x,y=0,0
current = 1
n=int(input())
matrix=[[-1 for i in range(n)] for i in range(n)]
while True:
  for i in range(x,n-x):
    matrix[i][y] = current
    current+=1
    for i in range(n):
      for j in range(n):
        print(matrix[i][j], end=" ")
      print()
    print()
  x=n-x-1
  for i in range(y+1,n-y):
    matrix[x][i] = current
    current+=1
    for i in range(n):
      for j in range(n):
        print(matrix[i][j], end=" ")
      print()
    print()
  y=n-y-1
  for i in range(n-x,n):
    matrix[n-i-1][y] = current
    current+=1
    for i in range(n):
      for j in range(n):
        print(matrix[i][j], end=" ")
      print()
    print()
  x=n-x-1
  for i in range(n-y,n-1):
    matrix[x][n-i-1] = current
    current+=1
    for i in range(n):
      for j in range(n):
        print(matrix[i][j], end=" ")
      print()
    print()
    exitbool = False
  y=n-y
  for i in matrix:
    for j in i:
      if j == -1:
        exitbool = True
  if exitbool == False:
    break