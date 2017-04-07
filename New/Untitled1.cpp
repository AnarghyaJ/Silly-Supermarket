#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

typedef struct p
{
	char ID[10];
	char name[20];
	int quantity;
	double price;
	
}product;

int search (FILE *,char *);

int main()
{
FILE *fp1,*fp2;
int choice;
printf("=================Enter Username================\n\n");
char username[20],password[20];
gets(username);
char character,pro[10];
int temp;
printf("=================PASSWORD========================\n\n");
gets(password);

if(strcmp(password,"nothing")!=0)
{
	printf("\n\nINVALID PASSWORD\nPROGRAM EXITING\n\n");

	return 0;
}

printf("\n\nENTER THE CATEGORY\n");
printf("[1]ELECTRONICS\n[2]FURNITURE\n[3]GROCERY\n\n");
scanf("%d",&choice);

switch(choice)
{
	case 1:printf("\n==============================ELECTRONICS====================\n\n");
			fp1=fopen("electronics.txt","w+");
			if(fp1==NULL)
			{
				printf("\nFILE OPENING ERROR!\n");
				
				return 1;
				
			}
			
			printf("\nPRODUCT ID	NAME			QUANTITY				PRICE\n\n");
			character=fgetc(fp1);
			while(character!=EOF)
			{
				putc(character,stdout);
				character=fgetc(fp1);
				
			}
			printf("\n\nENTER THE PRODUCT,YOU WANT TO PURCHASE\n\n");
			gets(pro);
			
			printf("Product Selected:%s",pro);
			
			temp=search(fp1,pro);
			printf("LINE:%d",temp);
			break;
}

}






int search(FILE *fp,char *s)
{
	int temp=1;
	int j;
	int i=0;
	
	char c;
	while(c=fgetc(fp)!=EOF)
	{
		if(c=='\n')
			temp++;
			
		while(s[i]==c)
		{	j++;
			i++;
			c=fgetc(fp);
		}
			
		if(j==strlen(s))
			return temp;
	
	}	
	return -1;
	
}

}
