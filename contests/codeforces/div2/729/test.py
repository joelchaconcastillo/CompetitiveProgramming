mod=998244353
n=(int)(input())
a=[0 for i in range(n+1)]
for i in range(1,n+1):
	m=input().split()
	if m[0]=="+":
		a[i]=(int)(m[1])
	
ans=0
for t in range(1,n+1):
	if a[t]==0:
		continue
	f=[[0 for i in range(n+2)] for j in range(n+2)]
	f[0][0]=1
	for i in range(1,n+1):
		for j in range(0,i+1): 
			if a[i]==0:
				if ((i<=t) or (j>0)):
					f[i][max(j-1,0)]=(f[i][max(j-1,0)]+f[i-1][j])%mod
			else :
				if ((a[i]<a[t]) or ((a[i]==a[t]) and (i<t))):
					f[i][j+1]=(f[i][j+1]+f[i-1][j])%mod
				else :
					f[i][j]=(f[i][j]+f[i-1][j])%mod
			
			if (i!=t) :
				f[i][j]=(f[i][j]+f[i-1][j])%mod
				
	print(f)
	for i in range(0,n+1):
		ans=(ans+f[n][i]*a[t])%mod
	
 
print(ans)
