# A

"""n = int(input())
lst = [0]*10**6
res = 0 #result
ans = [] #output lst
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
    ans.append(str(res))
print('\n'.join(ans))"""


#


























