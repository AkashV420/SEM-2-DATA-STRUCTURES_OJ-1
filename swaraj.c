#include<stdio.h>
void merge(int arr[], int l, int m, int r)
{
	int i,j,k,n1 = m-l+1, n2 = r-m, L[n1],R[n2];

  for(i=0;i<n1;i++)
  	 L[i] = arr[l+i];
  for(j=0;j<n2;j++)
  	 R[j] = arr[m+1+j];
  
  i=0;
  j=0;
  k = l;

  while(i<n1 && j<n2)
   {
   	 if(L[i]<=R[j])
   	  {
   	  	arr[k] = L[i];
   	  	i++;
   	  }
   	 else
   	  {
   	  	arr[k] = R[j];
   	  	j++;
   	  }
   	 k++; 
   }

  for(;j<n2; j++)
  	{
  		arr[k] = R[j];
  	
  		k++;
  	}
  for(;i<n1; i++)
  {
  	arr[k] = L[i];
  	
  	k++;
  }
}

void mergesort(int arr[], int l, int r)
{
	if(l<r)
	{
		int m = l+(r-l)/2;

		mergesort(arr, l, m);
		mergesort(arr, m+1, r);

		merge(arr, l, m, r);
	}
}

int main()
{
	int t,n,k;
	int arr[1000001];
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	 {
	 	scanf("%d %d",&n,&k);
	 	for(int j=0;j<n;j++)
	 	 {
	 	 	scanf("%d",&arr[j]);
	 	 }
	 	mergesort(arr, 0, n-1);

       for(int x=0;x<n;x++){
       printf("%d ",arr[x]);
       }
   
	 }
	 return 0;
}
