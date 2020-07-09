#include<stdio.h>
#include<stdlib.h>
int calc(long int n)
{
	
	if(n<=250000)
	{
	printf("YOUR SALARY IS %ld\n\n",n);
	printf("NO TAX\n");
	}
	else if(n>250000 && n<=500000)
	{
	printf("YOUR SALARY IS %ld\n\n",n);
	printf("TAX TO BE PAID IS %.0lf\n",(double)(n*(5/100.0)));
	}
	else if(n>500000 && n<=1000000)
	{
	printf("YOUR SALARY IS %ld\n\n",n);
	printf("TAX TO BE PAID IS %.0lf\n",(double)(n*(20/100.0))+12500);
	}
	else if(n>1000000)
	{
	printf("YOUR SALARY IS %ld\n\n",n);
	printf("TAX TO BE PAID IS %.0lf\n",(double)(n*(30/100.0))+112500);
	}
	
}

