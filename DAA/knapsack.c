#include<stdio.h>

void knapsack(int m,int n,float p[],float w[])
{
	int i;
	float s=0.0;
	float x[n];
	for(i=0;i<n;i++) 
		x[i]= 0.0;
	float U=m;
	for(i=0;i<n;i++)
	{
		if (w[i]>U)
			break;
		x[i]=1.0;
		U= U-w[i];
	}
	if (i<n)
	  x[i]=(U/w[i]);
	for(i=0;i<n;i++)
		if(x[i]!=0)
			s+=(x[i]*p[i]);
	printf("%f",s);
}


int main(){
	int n,i,m,k,x;
	printf("No. of objects:");
	scanf("%d",&n);
	float p[n],w[n];
	printf("Enter profits:");
	for(i=0;i<n;i++)
		scanf("%f",&p[i]);
	printf("Enter weights:");
	for(i=0;i<n;i++)
		scanf("%f",&w[i]);
	printf("Bag Capacity:");
	scanf("%d",&m);
	float r[n];
	for(i=0;i<n;i++){
		r[i]=p[i]/w[i];
	}
	
	for (i = 0; i < n-1; i++) 
        {
            for (k = 0; k < n-i-1; k++)
            {
                if (r[k] < r[k+1]) 
                {
                    x =  p[k];
                    p[k] = p[k+1];
                    p[k+1] = x;
		    x = w[k];
		    w[k]=w[k+1];
		    w[k+1]=x;
		    x=r[k];
		    r[k]=r[k+1];
		    r[k+1]=x;
                }
            }
        }
	knapsack(m,n,p,w);
	return 0;
}