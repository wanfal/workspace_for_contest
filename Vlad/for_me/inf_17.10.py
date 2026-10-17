def solve(a:str,b=';',n=0):
    c=a.split(b)
    m=[]
    for i in c:
        if len(i)<=n:
            m+=[j for j in i]
        else:
            m+=[i]           

    w=m
    x=dict()
    for i in w:
        if i not in list(x.keys()):
            x[i]=1
        else:
            x[i]+=1
    return x


print(solve("abcadefa"))
