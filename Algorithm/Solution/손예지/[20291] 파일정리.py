import sys 

N = int(sys.stdin.readline().rstrip())
extension = dict()

for i in range(N) :
    file = list(sys.stdin.readline().rstrip().split('.'))
    extension[file[1]] = extension.get(file[1],0)+1

arr = []
for key in extension :
    arr.append((key, extension.get(key)))
arr.sort()
for idx in arr :
    print(idx[0], idx[1])
