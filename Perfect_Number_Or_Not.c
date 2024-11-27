#include<stdio.h>
int main()
{
	int num,sum=0,i;
	printf("Enter number:");
	scanf("%d",&num);
	for(i=1;i<num;i++)
	{
		if(num%i==0)
		{
		sum=sum+i;
	}
}
if(sum==num)
{
	printf("%d os a perfect number\n",num);
}
else
{
	printf("Not a perfect number");
}
}
