#include<stdio.h>
int main()
{
	int i, changecount = 0,n,ptr = 0;
    char str[100050], stack[100050];
    scanf("%d",&n);
    //for(i=0;i<n;i++)
    	scanf("%s",str);
	if(n % 2 == 1)
	{
		printf("-1\n");
		return 0;
	}
  	for(i=0;i<n;i++)
  	{  	
    		if(str[i]== 'A' )
    		{
    			//printf("A ex\n");
    			stack[ptr] = 'A';
        		ptr++;
    		}
   	 		if(str[i]=='C')
   	 		{
   	 			//printf("C ex");
   	 			if(ptr == 0)
   	 			{
   	 			//	printf("0 ex\n");
   	 				changecount++;
   	 				stack[ptr] = 'A';
					ptr++;
   	 			}
   	 			else
   	 			{
   	 			//	printf("n0 ex\n");
   	 				ptr--;
   	 			}
   	 		}
   	 		//printf(" * %d # %dS\n", changecount, ptr);
  	}
  	printf("%d\n",changecount + (ptr/2));
  	return 0;	
}


