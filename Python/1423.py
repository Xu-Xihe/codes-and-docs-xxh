ina=float(input())
bu=1
long=2
while 1:
    ina-=long
    if ina<=0:
        print(bu)
        exit()
    long*=0.98
    bu+=1
