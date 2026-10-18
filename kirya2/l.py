n=int(input())
k=[]
for i in range(n):
    t,w =list(map(int,input().split()))
    k.append([w,t,i])


# lst_styp=sorted(k)      # сортировка по ступенькам, чтобы шли люди по порядку по экскалатору

k.sort()
for i in range(len(k)):
    k[i]=[k[i][2],k[i][0]*k[i][1]] #высчитывается время до конца экска [индекс человек, время пути без учета препятсвий]


#
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
