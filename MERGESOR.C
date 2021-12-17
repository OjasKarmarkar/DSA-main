#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int *mergesort(int *p,int *p1,int n,int m)
{
	int *p2,i=0,j=0,k=0;
	p2=(int *) malloc((m+n)*sizeof(int));
	while(i<=n-1 && j<=m-1)
	{
		if(p[i]<p1[j])
		p2[k++]=p[i++];
		else p2[k++]=p1[j++];

	}
	while(i<=n-1)
	{
		p2[k++]=p[i++];
	}
	while(j<=m-1)
	{
		p2[k++]=p1[j++];
	}
	return p2;
}
void sort(int *p,int n)
{
	int i,j,temp;
	for(i=0;i<=n-2;i++)
	{
		for(j=0;j<=n-i-2;j++)
		{
			if(p[j]>p[j+1])
			{
				temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
			}
		}
	}
}
int main()
{
	int n,*a,i,*b,m,*c;
	printf("Enter the number of elements for 1st array:");
	scanf("%d",&n);
	a=(int *)malloc(n*sizeof(int));
	for(i=0;i<=n-1;i++)
	{
		printf("Enter a value:");
		scanf("%d",&a[i]);
	}
	sort(a,n);
	printf("Enter the number of elements for 2nd array:");
	scanf("%d",&m);
	b=(int *)malloc(m*sizeof(int));
	for(i=0;i<=m-1;i++)
	{
		printf("Enter a value:");
		scanf("%d",&b[i]);
	}
	sort(b,m);
	c=mergesort(a,b,n,m);
	printf("Merged Sorted array\n");
	for(i=0;i<=m+n-1;i++)
	{
		printf("%d\n",c[i]);
	}
	return 0;
}
