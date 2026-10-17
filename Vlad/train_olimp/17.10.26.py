# f=[]
# blec=0
# white=0
# for i in range(n):
#     c=[]
#     for j in range(m):
#         if i%2==0:
#             if j%2==0:
#                 c.append(0)
#                 blec+=1
#             else:
#                 c.append(1)
#                 white+=1
#         else:
#             if j%2==0:
#                 c.append(1)
#                 white+=1
#             else:
#                 c.append(0)
#                 blec+=1

#     f.append(c)

# if blec==white:
#     print('equal')
# elif blec>white:
#     if int(f[i1-1][j1-1])==y:
#         print("black")
#     else:   
#         print("white")
# else:
#     if int(f[i1-1][j1-1])==y:
#         print("white")
#     else:
#         print("black")
# def q(i,j):
#     if (j-1)%2==0:
#         if (i-1)%2==0:
#             return 0
#         else:
#             return 1
#     else:
#         if (i-1)%2==0:
#             return 1
#         else:
#             return 0

# def g(i,j,c):
#     if q(i,j)==c:
#         return 0
#     else: 
#         return 1
        
     
# def f(m,n,i1,j1,y):
#     if m%2==0 or n%2==0:
#         return 'equal'
#     if (m>n and m%n==0) or (m<n and n%m==0):
#         return 'equal'
#     if q(m,n)==1 and g(i1,j1,y)==1:
#         return "white" 
#     if q(m,n)==1 and g(i1,j1,y)==0:
#         return "black"
#     if q(m,n)==0 and g(i1,j1,y)==0:
#         return "black"
#     if q(m,n)==0 and g(i1,j1,y)==1:
#         return "white" 

# m,n,i1,j1,y=list(map(int,input().split()))
# print(f(m,n,i1,j1,y))

#====================  L

n=int(input())
k=[]
for i in range(n):
    t,w =list(map(int,input().split()))
    k.append([w,t,i])


# lst_styp=sorted(k)      # сортировка по ступенькам, чтобы шли люди по порядку по экскалатору

k.sort()
for i in range(len(k)):
    k[i]=[k[i][2],k[i][0]*k[i][1]] #высчитывается время до конца экска [индекс человек, время пути без учета препятсвий]



last_time=-1


for i in range(len(k)):
    if last_time==-1: # первый человек по ступенькам всегда закончит первым 
            last_time=k[i][1]  #его впем
    else:
        if k[i][1]<=last_time:
            k[i][1]=last_time

        else:
            last_time=k[i][1]


k.sort()
for i in k:
    print(i[1])

        

    
    







            


