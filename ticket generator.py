import random

v1, v2, v3, v4, v5, v6, v7, v8, v9, d1, d2, d3, d4 = 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
c1, c2, c3, c4, c5, c6, c7, c8, c9, c, r = [], [], [], [], [], [], [], [], [], [], []

v1 = random.randint(1, 9)
v2 = random.randint(10, 19)
v3 = random.randint(20, 29)
v4 = random.randint(30, 39)
v5 = random.randint(40, 49)
v6 = random.randint(50, 59)
v7 = random.randint(60, 69)
v8 = random.randint(70, 79)
v9 = random.randint(80, 90)

for i in range(3):
    while v1 in c1:
        v1 = random.randint(1, 9)
    c1.append(v1)
    while v2 in c2:
        v2 = random.randint(10, 19)
    c2.append(v2)
    while v3 in c3:
        v3 = random.randint(20, 29)
    c3.append(v3)
    while v4 in c4:
        v4 = random.randint(30, 39)
    c4.append(v4)
    while v5 in c5:
        v5 = random.randint(40, 49)
    c5.append(v5)
    while v6 in c6:
        v6 = random.randint(50, 59)
    c6.append(v6)
    while v7 in c7:
        v7 = random.randint(60, 69)
    c7.append(v7)
    while v8 in c8:
        v8 = random.randint(70, 79)
    c8.append(v8)
    while v9 in c9:
        v9 = random.randint(80, 90)
    c9.append(v9)

c1.sort()
c2.sort()
c3.sort()
c4.sort()
c5.sort()
c6.sort()
c7.sort()
c8.sort()
c9.sort()

for i in range(3):
    c.append(c1[i])
for i in range(3):
    c.append(c2[i])
for i in range(3):
    c.append(c3[i])
for i in range(3):
    c.append(c4[i])
for i in range(3):
    c.append(c5[i])
for i in range(3):
    c.append(c6[i])
for i in range(3):
    c.append(c7[i])
for i in range(3):
    c.append(c8[i])
for i in range(3):
    c.append(c9[i])

for i in range(3):
    d1 = random.randint(0, 8)
    d2 = random.randint(0, 8)
    d3 = random.randint(0, 8)
    d4 = random.randint(0, 8)
    while (c[3 * d1] == c[3 * d1 + 1]):
        d1 = random.randint(0, 8)
    while ((d1 == d2) or (c[3 * d2] == c[3 * d2 + 1])):
        d2 = random.randint(0, 8)
    while ((d1 == d3) or (d2 == d3) or (c[3 * d3] == c[3 * d3 + 1])):
        d3 = random.randint(0, 8)
    while ((d1 == d4) or (d2 == d4) or (d3 == d4) or (c[3 * d4] == c[3 * d4 + 1])):
        d4 = random.randint(0, 8)
    c[3 * d1 + i] = "  "
    c[3 * d2 + i] = "  "
    c[3 * d3 + i] = "  "
    c[3 * d4 + i] = "  "

for i in range(3):
    for j in range(9):
        r.append(c[3 * j + i])

for i in range(27):
    if r[i] != "  ":
        if r[i] < 10:
            r[i] = "0" + str(r[i])
        else:
            r[i] = str(r[i])

print(r[:9])
print(r[9:18])
print(r[18:])