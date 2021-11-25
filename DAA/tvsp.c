#include<stdio.h>
int d[20],t[20],n,w[20];

int max(int m, int n){
	if(m>n)
	return m;
	else
	return n;
}

void tvs(int i, int delta){

	if(t[i]!=0){
		if(2*i > n) d[i]=0;
		else{
			tvs(2*i,delta);
			d[i]=max(d[i],d[2*i]+w[2*i]);
			if(2*i+1 <= n){
				tvs(2*i+1,delta);
				d[i]=max(d[i],d[2*i+1]+w[2*i+1]);
			} 

		}
		if((t[i]!=1) && (d[i]+w[i] > delta)){
			printf("%d ",t[i]);
			d[i]=0;
		}
	}	
}


int main(){
	
	int i,delta;
	printf("Enter no. of nodes:");
	scanf("%d",&n);
	printf("Enter tree in form of array:");
	for(i=1;i<=n;i++)
		scanf("%d",&t[i]);
	printf("Enter weights:");
	for(i=1;i<=n;i++)
		scanf("%d",&w[i]);
	printf("Tolerance level:");
	scanf("%d",&delta);
	tvs(1,delta);
	return 0;

}