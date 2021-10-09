a=input().split()
start=int(a[0])*60+int(a[1])
end=int(a[2])*60+int(a[3])
out=end-start
h=out/60
m=out%60
print(int(h),end=' ')
print(m)
