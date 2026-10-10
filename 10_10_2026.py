# A
"""
class soldat:
    def __init__(self,rost,parent=None):
        self.rost = rost


        if parent:
            if parent.rost>rost:
                self.id = parent.id-1
                parent.change_id()
            else:
                self.id = parent.id+1
        else:
            self.id = 0
        self.little = None
        self.big = None
        self.parent = parent

    def add_soldat(self,rost):
        if rost>self.rost:
            if self.big:
                self.big.add_soldat(rost)
            else:
                self.big = soldat(rost,self)
        else:
            if self.little:
                self.little.add_soldat(rost)
            else:
                self.little = soldat(rost,self)

    def change_id(self):
        pass

    def remove_soldat(self,idx):
        pass

n = int(input())
ipt = [input() for _ in range(n)]


for a,i in enumerate(ipt):
    com, rost = map(int, i.split())
    if com==1:
        if a == 0:
            stroi = soldat(rost)
        else:
            stroi.add_soldat(rost)
    else:
        stroi.remove_soldate(rost)




lst = []
for i in ipt:
    com, rost = map(int,i.split())
    if com==1:
        for j in range(len(lst)):
            if lst[j]<rost:
                lst.insert(j,rost)
                print(j)
                break
        else:
            print(len(lst))
            lst.append(rost)
    else:
        lst.pop(rost)

"""
# C
"""n = int(input())

s = 650
trains = []
for i in range(n):
    str = input()
    train_name = str[str.find('"'):str.rfind('"')+1]
    train_time = [tuple(map(int,i.split(':'))) for i in str.split()[-2:]]

    train_time = [i[0]*60+i[1] for i in train_time]
    if train_time[1]>train_time[0]:
        train_time = (train_time[1]-train_time[0])
    elif train_time[1]<train_time[0]:
        train_time = (train_time[1]-train_time[0])+24*60
    else:
        train_time = 24*60

    v = s/train_time * 60

    trains.append([v,train_name])

fastest = max(trains)

print(f'The fastest train is {fastest[1]}.')
print(f'Its speed is {round(fastest[0])} km/h, approximately.')"""

# F

"""n= int(input())
E = list('27182818284590452353602875')

if n==25:
    res = E
else:
    res = E[:n+2]
    if res[-1] in '56789':
        i = -2
        while res[i]=='9':
            res[i] = '0'
            i-=1
        else:
            res[i] = str(int(res[i])+1)
        res = res[:n+1]
    else:
        res = res[:n+1]
if len(res)>1:
    res.insert(1,'.')
res = ''.join(res)
print(res)"""

# I
"""
class City:
    def __init__(self,name,type):
        self.type = type
        self.connections = []
        self.name = name

    def __repr__(self) -> str:
        return f'{self.name}:{self.type}: {self.connections}'


    @staticmethod
    def is_possible(c:City,visited_cities:list):
        if c.type==2: return True
        visited_cities.append(c.name)
        for con in c.connections:
            if con[0] in visited_cities:
                continue
            else:
                if City.is_possible(cities_dict[con[0]],visited_cities): return True

        return False

    @staticmethod
    def find_path_to_2(c1:City,visited_cities:list,path:list):
        path = path+[c1.name]
        visited_cities.append(c1.name)
        paths
        if c1.type==2: return path
        for con in c1.connections:
            if con[0] in visited_cities:
                continue
            else:




n,m = map(int,input().split())

cities_list = list(map(int,input().split()))
segments = [list(map(int,input().split())) for _ in range(m)]
cities_dict = {i+1:City(i+1,cities_list[i]) for i,c in enumerate(cities_list)}

for segment in segments:
    cities_dict[segment[0]].connections.append([segment[1],segment[2]])
    cities_dict[segment[1]].connections.append([segment[0],segment[2]])

for c in cities_dict.values():
    print(c)

for c in cities_dict.values():
    if c.type==1:
        print(c.name,City.is_possible(c,[]))
"""



# K
import sys
x,k = map(int,input().split())
d = int(input())
st = list(sorted(map(int,input().split())))

if x%k==0:
    print(x)
    sys.exit(0)


ost = set()
ost.add(x%k)
for i in range(k):
    nost = set()
    for o in ost:
        for n in st:
            no = (o*10+n)%k
            if no==0:
                lx = len(str(x))
                stx = str(x)
                res = k
                ln_res = lx+i+1
                while True:
                    #if str(res)[:lx]==stx and res%10==n and all(int(a) in st for a in str(res//10)[lx:]):
                    if res % 10 == n and str(res)[:lx] == stx and ((res//10) % k)==o:
                        if all(int(a) in st for a in str(res//10)[lx:]):
                            print(res)
                            sys.exit(0)
                    res += k

            nost.add(no)
    ln = len(ost)
    ost |= nost
    if len(ost)==ln:
        print(-1)
        sys.exit(0)
else:
    print(-1)











