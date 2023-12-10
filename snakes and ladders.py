import random

places=[]
pick=[]
sh=[] #snake head
st=[] #snake tail
ls=[] #ladder start
le=[] #ladder end
p1=1
p2=1
roll=0

for i in range(98):
    pick.append(i+2)

rs=random.sample(pick, 40)

for i in range(10):
    a=int(rs[-1])
    b=int(rs[-2])
    rs.pop()
    rs.pop()
    if (a>b):
        sh.append(a)
        st.append(b)
    else:
        st.append(a)
        sh.append(b)

for i in range(10):
    a=int(rs[-1])
    b=int(rs[-2])
    rs.pop()
    rs.pop()
    if (a>b):
        le.append(a)
        ls.append(b)
    else:
        ls.append(a)
        le.append(b)

for i in range(100):
    places.append(i+1)

for i in range(10):
    print("snake", i+1, ":", sh[i], "-->", st[i])

print()

for i in range(10):
    print("ladder", i+1, ":", ls[i], "-->", le[i])

print()

#game
while ((p1!=100) and (p2!=100)):
    w=""
    x=""
    y=""
    z=""
    roll=roll+1
    n=random.randint(1, 12)
    p1=p1+n
    if (p1<=100):
        for i in range(10):
            if p1==sh[i]:
                p1=st[i]
                w="(snake)"
                x=str(sh[i])
                y=" -->"
                z=x+y
                break
            if p1==ls[i]:
                p1=le[i]
                w="(ladder)"
                x=str(ls[i])
                y=" -->"
                z=x+y
                break
        print("roll", roll, ":", "die:", n, "position of 1:", z, p1, w)
    else:
        p1=p1-n
        print("roll", roll, ":", "die:", n, "position of 1:", p1, "(>100)")

    if p1!=100:
        w=""
        x=""
        y=""
        z=""
        n=random.randint(1, 12)
        p2=p2+n
        if (p2<=100):
            for i in range(10):
                if p2==sh[i]:
                    p2=st[i]
                    w="(snake)"
                    x=str(sh[i])
                    y=" -->"
                    z=x+y
                    break
                if p2==ls[i]:
                    p2=le[i]
                    w="(ladder)"
                    x=str(ls[i])
                    y=" -->"
                    z=x+y
                    break
            print("roll", roll, ":", "die:", n, "position of 2:", z, p2, w)
        else:
            p2=p2-n
            print("roll", roll, ":", "die:", n, "position of 2:", p2, "(>100)")

print()
if p1==100:
    print("P1 WON")
else:
    print("P2 WON")
