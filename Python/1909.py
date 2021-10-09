a=int(input())
b=input().split()
c=input().split()
d=input().split()
lina=a/int(b[0])
lin=int(lina)
if a%int(b[0])!=0:
    lin+=1
out=lin*int(b[1])
#next
lina=a/int(c[0])
lin=int(lina)
if a%int(c[0])!=0:
    lin+=1
out1=lin*int(c[1])
if out1<out:
    out=out1
#next
lina=a/int(d[0])
lin=int(lina)
if a%int(d[0])!=0:
    lin+=1
out1=lin*int(d[1])
if out1<out:
    out=out1
print(int(out))
