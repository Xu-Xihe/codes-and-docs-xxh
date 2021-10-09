i=0
ina=[0]*12
while i<12:
    ina[i]=input()
    i+=1
i=0
hand=0
mum=0
while i<12:
    hand+=300
    hand-=int(ina[i])
    if hand<0:
        print('-',end='')
        print(i+1)
        exit()
    mum+=int(hand/100)
    hand%=100
    i+=1
print(hand+mum*120)
