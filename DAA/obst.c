#include<stdio.h>
int find(int c[5][5],int r[5][5],int i,int j){
	int min=999,m,l;
	for(m=r[i][j-1]; m<=r[i+1][j]; m++)
		if((c[i][m-1]+c[m][j])<min){
			min=c[i][m-1]+c[m][j];
			l=m;
		}
	return l;
}
int main(){
	int n,i,j,k,m;
	printf("Enter no. of identifiers:");
	scanf("%d",&n);
	int c[n+1][n+1],p[n+1],q[n+1],w[n+1][n+1],r[n+1][n+1];
	printf("Enter p:");
	for(i=1;i<=n;i++)
		scanf("%d",&p[i]);
	printf("Enter q:");
	for(i=0;i<=n;i++)
		scanf("%d",&q[i]);
	for(i=0;i<n;i++){
		w[i][i]=q[i];
		r[i][i]=0;
		c[i][i]=0;
		w[i][i+1]=q[i]+q[i+1]+p[i+1];
		r[i][i+1]=i+1;
		c[i][i+1]=q[i]+q[i+1]+p[i+1];
	}
	w[n][n]=q[n];
	r[n][n]=0;
	c[n][n]=0;
	for(m=2;m<=n;m++){
		for(i=0;i<=n-m;i++){
			j=i+m;
			w[i][j]=w[i][j-1]+p[j]+q[j];
			k=find(c,r,i,j);
			c[i][j]=w[i][j]+c[i][k-1]+c[k][j];
			r[i][j]=k;
		}
	}
	printf("%d",c[0][n]);
}