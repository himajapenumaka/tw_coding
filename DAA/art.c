#include <stdio.h>
int n,num=1,dfn[20],l[20],c[20][20];
void art(int u,int v)
{
   int i,w;
   dfn[u]=num;
   l[u]=num++;
   for(w=1;w<=n;w++)
   {
      if(c[u][w]!=0)
      {
         if(dfn[w]==0)
         {
            art(w,u);
            l[u] = (l[u]<l[w]) ? l[u] : l[w];
            if(u!=1 && l[w]>=dfn[u])
               printf("%d ",u);
         }
         if(w!=v){
		printf("#%d%d  %d%d#",w,dfn[w],u,l[u]);
		l[u] = (l[u]<dfn[w]) ? l[u] : dfn[w];
	}
   
      }   
          
   }
}
int main()
{
    int i,j;
    printf("enter no of vertices:");
    scanf("%d",&n);
    printf("enter adjacency matrix:");
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    scanf("%d",&c[i][j]);
    printf("articulation points are:");
    for(i=1;i<=n;i++)
    dfn[i]=0;
    art(1,0);
    //for(j=1;j<=n;j++)
    //printf("%d %d",dfn[j],l[j]);
    return 0;
}