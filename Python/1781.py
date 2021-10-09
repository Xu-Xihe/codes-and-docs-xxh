chang=int(input())
ina=(0,)
lin=0
while lin<chang:
    ina[lin]=int(input())
    lin+=1
inb=sorted(ina)
lin=0
while lin<chang:
    if ina[lin]==inb[chang-1]:
        print(lin)
        break
    lin+=1
print(inb[chang-1])
