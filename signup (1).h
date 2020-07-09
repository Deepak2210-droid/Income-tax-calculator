#include<stdio.h>
#include<string.h>
#include "authent.h"
static int i=0;
struct pe

{
	char name[100];
	int id;
	char phno[12];
	char acno[13];
	long int inc;

	
}pp;
int create()
{
	FILE *f;
	FILE *cn;
    int k=0,wr=0,cnt,check;
    f=fopen("C:\\Users\\user\\Documents\\file\\PR0.txt","a");
    cn=fopen("C:\\Users\\user\\Documents\\file\\cnt.txt","r+");
    fscanf(cn,"%d",&cnt);
	n:
	printf("Enter name\n");
	scanf("%s",pp.name);
	for(k=0;k<strlen(pp.name);k++)
	{
		if((pp.name[k]>='a' && pp.name[k]<='z')||(pp.name[k]>='A'&&pp.name[k]<='Z'))
		{
		wr++;
		}
	}
	if(wr!=strlen(pp.name))
	{
		printf("INVALID CHARACTER\n");
		wr=0;
		goto n;
	}
	wr=0;  
    phn:
    wr=0;
	printf("Enter Phone number\n");
	scanf(" %s",&pp.phno);
	if(strlen(pp.phno)!=10)
    	{
    		printf("INVALID MOBILE NUMBER\n");
			goto phn;
		}
	for(k=0;k<strlen(pp.phno);k++)
		{
			if(((int)pp.phno[k])>=48&&((int)pp.phno[k])<=57)
			wr++;
		}
	if(wr!=10)
    	{
    		printf("INVALID MOBILE NUMBER\n");
    		wr=0;
			goto phn;
	    }
    wr=0;
    acc:
   	printf("Enter Account number\n");
	scanf("%s",&pp.acno);
   	if(strlen(pp.acno)!=12)
		{
			printf("INVALID ACCOUNT NUMBER\n");
			goto acc;
		}	
	for(k=0;k<strlen(pp.acno);k++)
		{
			if(((int)pp.acno[k])>=48&&((int)pp.acno[k])<=57)
			{
			wr++;
			}
			
		}
	if(wr!=strlen(pp.acno))
    	{
    		printf("INVALID ACCOUNT NUMBER\n");
    		wr=0;
			goto acc;
    	}
    check=authent2(pp.acno,pp.phno,cnt);
    if(check==1)
    {	printf("ACCOUNT\\MOBILE NUMBER ALREADY EXISTS TRY WITH NEW ACCOUNT\\MOBILE NUMBER\n");
		wr=0;
    	goto phn;
	}
    printf("Enter PIN\n");
	scanf("%d",&pp.id);	  
	inc:
	printf("Enter Income\n");
	scanf("%ld",&pp.inc);
    if(pp.inc<0)
		{
    		printf("Invalid income");
    		goto inc;
   		}
	fprintf(f,"\n%s\n%d\n%s\n%s\n%d",pp.name,pp.id,pp.phno,pp.acno,pp.inc);
	system("CLS");	
	printf("YOUR ACCOUNT HAS BEEN CREATED SUCCESSFULLY\n");
	fseek(cn,0,SEEK_SET);
	cnt+=1;
	fprintf(cn,"%d",cnt);
	fclose(cn);
	fclose(f);
	return (cnt);
	
}
