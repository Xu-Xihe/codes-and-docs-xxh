ina=input().split()
ji=int(ina[0])-1
i=0
out=0
while i<int(ina[1]):
    if ji<5:
        out+=250
    ji+=1
    ji%=7
    i+=1
print(out)
