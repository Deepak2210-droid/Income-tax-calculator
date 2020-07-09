#include<stdio.h>
#include<string.h>
struct k

{
	char name[100];
	int id;
	char phno[13];
	char acno[13];
	long int inc;

	
}d;
int authent(char a[],int b,int c)
{
	int cnt=0,i=0;
	FILE *p;
	p=fopen("C:\\Users\\user\\Documents\\file\\PR0.txt","r+");
	while(i<c)
	{
		fscanf(p,"%s%d%s%s%*d",d.name,&d.id,d.phno,d.acno);
		if((strcmp(d.phno,a)==0 || strcmp(d.acno,a)==0)&&(d.id==b))
		{
			cnt=1;
			printf("                                                WELCOME  %s\n",d.name);
			return cnt;
			break;
		}
		i++;
	}
}
int authent2(char a[],char b[],int c)
{
	int cnt=0,i=0;
	FILE *p;
	p=fopen("C:\\Users\\user\\Documents\\file\\PR0.txt","r+");
	while(i<c)
	{
		fscanf(p,"%*s%*d%s%s%*d",d.phno,d.acno);
		if((strcmp(d.acno,a)==0 || strcmp(d.phno,b)==0))
		{
			cnt=1;
			return cnt;
			break;
			
		}
		i++;
	}
}
