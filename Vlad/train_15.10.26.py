from itertools import *

n = int(input())
s=list(map(int,input().split()))

a=len(s)//2
k=sum(s)
ssum=[]
for i in permutations(s,n):
    m=list(i)
    ssum.append(abs(2*sum(m[:a])-k))
print(min(ssum))
    