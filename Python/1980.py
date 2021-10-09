ina=input().split()
i=1
out=0
while i<=int(ina[0]):
    b=i
    while b>0:
        lin=b%10
        c=b
        b=int(c/10)
        if lin==int(ina[1]):out+=1
    i+=1
print(out)
