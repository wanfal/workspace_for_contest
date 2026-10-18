n = int(input())
table = [list(map(int,input().split())) for _ in range(n)]

table = [i+[i[0]+i[1]] for i in table]
table.sort(key=lambda x: (-x[2],-x[0]))

s1 = sum(table[i][0] for i in range(0,n,2))
s2 = sum(table[i][1] for i in range(1,n,2))
print(s1-s2)
