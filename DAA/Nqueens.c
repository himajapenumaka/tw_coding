#include<stdio.h>
#include<stdlib.h>
int x[100];
int place(int k,int i){
	int j;
	for(j=1;j<=k-1;j++)
		if((x[j]==i) || (abs(x[j]-i))==(abs(j-k)) )
		return 0;
	return 1;
}
void Nqueens(int k,int n){
	int i,j;	
	for(i=1;i<=n;i++){
		if(place(k,i)){
			x[k]=i;
			if(k==n){
				printf("\n");
				for(j=1;j<=n;j++)
					printf("%d ",x[j]);
			}		
			else
				Nqueens(k+1,n);
		}
	}
}
int main(){
	int n;
	printf("Enter no. of queens:");
	scanf("%d",&n);
	Nqueens(1,n);
}