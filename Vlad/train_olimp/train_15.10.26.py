# from itertools import *

# a=len(s)//2
# k=sum(s)
# ssum=[]
# for i in permutations(s,n):
#     m=list(i)
#     ssum.append(abs(2*sum(m[:a])-k))
# print(min(ssum))
    
# n = int(input())
# s=list(map(int,input().split()))

# s=sorted(s)
# a,b=[],[]
# if n%2==0:
#     for i in s:
#         if len(a)<=len(b):
#             a+=[i]
#         else:
#             b+=[i]
# print(a,b)


# ===== B
n,w=map(int,input().split())
s=[]

for i in range(n):
    s+=[list(map(int,input().split()))]

# result=[]
# for i in range(n):



