#include<stdio.h>

void jsn(int d[],int n,int p[])
{
	int i,k,j[n],x,q,r,s=0;

	int jobs[n];
	for(i=1;i<=n;i++)
	jobs[i]=i;	

	for(i=1;i<=n;i++) 
        {
            for(k=i+1;k<=n;k++)
            {
                if(p[i]<p[k]) 
                {
                    x =  p[i];
                    p[i] = p[k];
                    p[k] = x;
		    x = d[i];
		    d[i]=d[k];
		    d[k]=x;
		    x =  jobs[i];
                    jobs[i] = jobs[k];
                    jobs[k] = x;
                }
            }
        }
	
	for(i=1;i<=n;i++)
		j[i]=0;

	p[0]=d[0]=j[0] =0;
	j[1]=1;
	k=1; 
	for(i=2;i<=n;i++) 
	{
		r=k;
		while (d[j[r]]>=d[i] && d[j[r]]!=r)
		r--;
		if(d[j[r]] <= d[i] && d[i]> r)
		{
			for(q=k;q>=r+1;q--)
				j[q+1]=j[q];
			j[r+1]=i;
			k=k+1;
		}
	}
	printf("Total no. of jobs: %d\nSequence is: ",k);
	for(i=1;i<=k;i++){
		s+=p[j[i]];
		printf("%d ",jobs[j[i]]);
	}
	printf("\nTotal profit: %d",s);
}

int main(){
	
	int i,n;
	printf("No. of jobs:");
	scanf("%d",&n);
	int p[n],d[n];
	printf("Enter profits:");
	for(i=1;i<=n;i++)
		scanf("%d",&p[i]);
	printf("Enter dead lines:");
	for(i=1;i<=n;i++)
		scanf("%d",&d[i]);
	jsn(d,n,p);
	return 0;

}