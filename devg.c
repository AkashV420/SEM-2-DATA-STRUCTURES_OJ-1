#include<stdio.h>
void swap(long long int *a,long long int *b)
{
	long long int temp = *a;
	   *a = *b;
	   *b = temp;
}
long long int partition(long long int arr[],long long int low,long long int high);
void quicksort(long long int arr[],long long int low, long long int high)
{
	if(low < high)
     {
     	int pi = partition(arr,low,high);
     	quicksort(arr,low,pi-1);
     	quicksort(arr,pi+1,high);
     }
 }
long long int partition(long long int arr[], long long int low, long long int high)
{
	long long int pivot = arr[high];
	long long int i = low - 1;

	for(long long int j=low;j<=high-1;j++){
		if(arr[j]<=pivot)
		{
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[i+1],&arr[high]);
	return (i+1);
}


int main()
{
	long long int t,m,n,l1[100001],r1[100001],l2[100001],r2[100001];
	long long int i,j,k;
	//long long int x,y,z;
	scanf("%lld",&t);
	for(i=0;i<t;i++)
	 {
	 	scanf("%lld",&m);
	 	 for(j=0;j<m;j++)
	 	 	scanf("%lld %lld",&l1[j],&r1[j]);
	 	 scanf("%lld",&n);
	 	 for(k=0;k<n;k++)
	 	 	scanf("%lld %lld",&l2[k],&r2[k]);
	 	 
	 	 quicksort(l1,0,m-1); 	
	 	
	 	 long long int a1 = l1[m-1];

	 	 quicksort(r1,0,m-1);
	 	 //for(int i=0;i<m;i++){
	 		//printf("%lld %lld\n",l1[i],r1[i]);
	 //	}
	 	 long long int a2 = r1[0];

	 	 quicksort(l2,0,n-1);
	 	 
	 	 long long int b1 = l2[n-1];

	 	  quicksort(r2,0,n-1);
          //for(int i=0;i<n;i++){
	 		//printf("%lld %lld\n",l2[i],r2[i]);
	 	//}
	 	long long int b2 = r2[0];
          
          long long int answer = (a1-b2);
          long long int ans = (b1-a2);
          if(answer<0 && ans <0 )
          printf("0\n");
          else if(ans>answer)
          	printf("%lld\n",ans);
          else printf("%lld\n",answer);

	 }
	 return 0;
 }
