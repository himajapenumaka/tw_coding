#include<stdio.h>
int a[20];

int partition (int l,int h)
{
	int i,j,pivot,x;
        pivot=a[l];
        i=l;
	j=h;
        while(i<j)
        {
              while(a[i]<=pivot)
              {
                    i++;

              }
              while(a[j]>pivot)
              {
                    j--;

              }
              if (i<j){
		x=a[i];
		a[i]=a[j];
		a[j]=x;
	      }         
         }
         x=a[l];
	 a[l]=a[j];
	 a[j]=x;
         return j;
}

void quicksort(int p,int q)
{
	int j;
	if (p<q)
        {
              j=partition(p,q);
              quicksort (p,j-1);
              quicksort (j+1,q);
        }
}

int main(){
	
	int i,n;
	printf("Size:");
	scanf("%d",&n);
	//int a[n];
	printf("Elements:");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	quicksort(0,n-1);
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
	return 0;

}