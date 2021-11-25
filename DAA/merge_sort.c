#include<stdio.h>
int b[100];

void merge(int a[] ,int l,int mid,int h)
{
	int i=l;
	int j=mid+1;
	int k=l;
	while ((i<=mid)&& j<=h)
 	{
  		if (a[i]<a[j])
		{
      			b[k] = a[i];
      			i++;
     	 		k++;
		}
		else
		{
  			b[k]=a[j];
  			j++;
  			k++;
  		}
	}
         while(i<=mid)                          
         {                                         
                   b[k] = a[i];
                   i++;                                                                             
                   k++;
         }
         while (j<=h)
         {
                   b[k]=a[j];
                   j++;                                   
                   k++;
         }
         for(k=l;k<=h;k++) 
                 a[k]=b[k];
}

void mergesort(int a[],int l,int h)
{
	   int mid;
           if (l<h) // if it has more than one element
           {
                    mid = (l+h)/2;
                    mergesort (a,l,mid);
                    mergesort (a,mid+1,h);
                    merge (a,l,mid,h);
            }
}

int main(){
	
	int i,n;
	printf("Size:");
	scanf("%d",&n);
	int a[n];
	printf("Elements:");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	mergesort(a,0,n-1);
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
	return 0;
}