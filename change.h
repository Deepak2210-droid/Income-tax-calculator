#include<stdio.h>
#include<string.h>
struct p

{
	char name[100];
	int id;
	char phno[13];
	char acno[13];
	long int inc;

	
};
int change(char a[],int b,int cn)
{

	FILE *f;
	struct p e[cn];
	long int ans;
	f=fopen("C:\\Users\\user\\Documents\\file\\PR0.txt","r+");	
	int c,i=0;
	printf("Enter new salary\n");
	scanf("%d",&c);
	while(i<cn)
	{
		fscanf(f,"%s %d %s %s %d",e[i].name,&e[i].id,e[i].phno,e[i].acno,&e[i].inc);
		if((strcmp(e[i].acno,a)==0||strcmp(e[i].phno,a)==0)&&e[i].id==b)
		{		
			e[i].inc=c;
			ans=e[i].inc;
		}
		
		i++;
	}
    i=0;
	fseek(f,0,SEEK_SET);	
	while(i<cn)
	{
	if(i==0)
	fprintf(f,"%s\n%d\n%s\n%s\n%d",e[i].name,e[i].id,e[i].phno,e[i].acno,e[i].inc);
	else
	fprintf(f,"\n%s\n%d\n%s\n%s\n%d",e[i].name,e[i].id,e[i].phno,e[i].acno,e[i].inc);
	i++;
	}
	system("CLS");
	printf("SALARY HAS BEEN UPDATED SUCCESSFULLY\n");
	
	fclose(f);
	return ans;
	
}

