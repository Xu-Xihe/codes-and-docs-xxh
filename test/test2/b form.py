b=1
n=1
an=0
while b<=15:
    n=1
    an=0
    while 1:
        an+=1/n
        if an>b:
            print(b,"--->",n)
            break
        n+=1
    b+=1