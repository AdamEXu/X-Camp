n = int(input())
cowtimes = []
for i in range(n):
  temp = input().split()
  temp[0] = int(temp[0])
  temp[1] = int(temp[1])
  cowtimes.append(temp)

ls = []

for i in range(n):
  temp = cowtimes.copy()
  # print(temp)
  del temp[i]
  # print(temp)
  timeline = [-1 for i in range(1000)]
  for j in range(n-1):
    for k in range(temp[j][0], temp[j][1]):
      timeline[k] = 1
  # for j in range(len(timeline)):
  #   if timeline[j] != -1: print(timeline[j], end=" ")
  # print()
  ls.append(timeline.count(1))

print(max(ls))