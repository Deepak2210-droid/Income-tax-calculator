#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include "change.h"
#include "cal.h"
#include "signup.h"
void del(int);
struct per
{
	char name[100];
	int id;
	char phno[13];
	char acno[13];
	long int inc;	
};
int in()
{	int count,cnt,wr=0,password,ch,i=0,n,n1,j;
	char w[]="INCOME TAX CALCULATOR";
	struct per p1;
	FILE *ct;
	FILE *z;	
	long int k;
	char no[13];
	ct=fopen("C:\\Users\\user\\Documents\\file\\cnt.txt","r+");
	z=fopen("C:\\Users\\user\\Documents\\file\\PR0.txt","r");
	fscanf(ct,"%d",&count);	
	retry:
	while(i<strlen(w))
	{	
	printf("%c",w[i]);del(1);
	i++;
	}i=0;
	printf("\n");
	printf("                                                                                                    1.SIGNIN\n\n                                                                                                    2.SIGNUP\n\n");
	scanf("%d",&n);
	system("CLS");
	if(n==2)
	{
		count=create();
		del(20);
		system("CLS");
		goto retry;
		
	}
	else if(n==1)
	{
    	acc:
		printf("ENTER THE ACCOUNT NUMBER/MOBILE NUMBER:\n");
		scanf("%s",no);
		if(strlen(no)!=12&&strlen(no)!=10)
			{
				printf("INVALID ACCOUNT NUMBER/PHONE NUMBER\n\n");
				goto acc;
			}
				
		else
			{
		
				for(j=0;j<strlen(no);j++)
					{
						if(((int)no[j])>=48 && ((int)no[j])<=57)
						{
							wr++;
						}
					}
				if(wr!=strlen(no))
    				{
    					printf("INVALID ACCOUNT NUMBER/PHONE NUMBER\n\n");
    					wr=0;
						goto acc;
					}
			}

		printf("Enter the 4 digit password\n");	
		scanf("%d",&password);
		system("CLS");
		cnt=authent(no,password,count);
		if(cnt==1)
			{
				printf("Do you have any changes in your salary?\n1.YES\n2.NO\n");
				scanf("%d",&ch);
				system("CLS");
				if(ch==1)
					{
						k=change(no,password,count);
						del(15);
						system("CLS");
						calc(k);
						printf("\n1.SIGN OUT\n");
						scanf("%d",&n1);
						if(n==n1)
						goto end;
					}
				else if(ch==2)
					{
						fseek(z,0,SEEK_SET);
					
						while(i<count)
							{
									
								fscanf(z,"%*s%d%*s%*s%ld",&p1.id,&p1.inc);
								if(p1.id==password)
									{	
										system("CLS");
										calc(p1.inc);
											break;
									}	
		
									i++;
	
	
							}
						printf("\n1.SIGN OUT");
						printf("\n");
						scanf("%d",&n1);
						if(n1==1)
							goto end;
					}
			}
	else
	{
	printf("INVALID USER CREDENTIALS\n\n");
	del(20);
	printf("ENTER CORRECT DETAILS");
	del(20);
	system("CLS");
	goto acc;
	}
}
else
{
	printf("INVALID SELECTION\n");
	del(10);
	printf("PLS CHOOSE EITHER 1 OR 2");
	del(10);
	system("CLS");
	goto retry;
}
end:
	printf("SUCCESSFULLY SIGNED OUT\n");
}
void del(int x)
{
	int m=50*x;
	clock_t start=clock();
	while(clock()<start+m);
}
