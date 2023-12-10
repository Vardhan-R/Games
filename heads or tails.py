import random
x=0;
y=0;
for i in range (10):
    r=random.randint(0, 1);
    if (r==1):
        x=x+1

    y=y+1
    print(i+1, x/y);
