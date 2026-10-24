# A

"""n = int(input())
lst = [0]*10**6
res = 0 #result
for _ in range(n):
    op,c = input().split() #op - operation , c - num
    c = int(c)
    if op=='add':
        while lst[c]==1:
            lst[c] = 0
            c+=1
            res-=1

        lst[c] = 1
        res+=1
    else:
        while lst[c]==0:
            lst[c] = 1
            c+=1
            res+=1
        lst[c]=0
        res-=1
    print(res)"""



# C
# wrong answer
"""import sys
K, N, M, D = [int(x) for x in input().split()]

a = (K*M*N - M*N - K*N - K*M)
b = (K*N*M*D)

if a <0.0001 or b <0.0001:
    print(-1)
    sys.exit()

S = D
while S*a<b:
    S+=1
if S*a==b:
    print(S)
else:
    print(-1)"""


# old_code (unused actually)
"""if a <0.00000001:
    print(-1)
    sys.exit()

S1 = b / a
S2 = b // a

if S2<D and abs(S2-S1)>0.0000001:
    print(-1)
else:
    print(S2)
"""
























