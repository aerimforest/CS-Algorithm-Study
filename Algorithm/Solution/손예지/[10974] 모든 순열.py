from itertools import combinations, permutations
n = int(input())
m = []
for i in range(n):
    m.append(i+1)
p = permutations(m, n)
for res in p:
    print(*res)
