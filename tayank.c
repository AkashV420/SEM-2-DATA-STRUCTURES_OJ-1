#include<stdio.h>

int  merge(int arr[],int temp[], int l, int m, int r)

{   int inversionCount=0;
	int i,j,k;
    
        i=l;
	j=m;
	k=l;

	while(i<=m-1 && j<=r)
	{
		if(arr[i]<=arr[j])
		{
			temp[k++] = arr[i++];
		}
		else
		{
			temp[k++] = arr[j++];
			inversionCount = inversionCount + m + 1 + j -k;

		}
	}

	while(i<=m-1)
	{
		temp[k++] = arr[i++];
	}
	while (j<=r)
	{
		temp[k++] = arr[j++];
	}
        int o;
        o=l;
	while(o<=r)
	{ 
		arr[o] = temp[o];
		o++;
	}
 
	return inversionCount;
}

int mergesort(int arr[], int temp[], int l, int r)
{
	int m; 
	int inversionCount=0;
	if(r > l)
	{
		int  m = (r + l)/2;

		 mergesort(arr,temp,l,m);
		 mergesort(arr,temp,m+1,r);

		inversionCount += merge(arr,temp,l,m+1,r); 
	}
	return inversionCount;
}


int main()
{  int t;

	scanf("%d",&t);
     for(int i=0;i<t;i++)
	{   
		int ret,n;
		
		scanf("%d",&n);
		int arr[n];
		int temp[n];
		for(int j=0;j<n;j++)
			scanf("%d",&arr[j]);

         ret=mergesorting(arr,temp,0,n-1);

		if(ret%2==0) printf("1\n");
		else	pr
			intf("0\n");
	}
return 0; 
}
