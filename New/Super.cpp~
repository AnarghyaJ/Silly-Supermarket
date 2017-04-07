#include<stdio.h>
#include<string.h>
#include<stdlib.h>
FILE *fp1,*fp2;
void display(FILE *);
typedef struct p
{
	char ID[10];
	char name[20];
	int quantity;
	float price;
	
}product;

int search (FILE *,char *);
void admin(FILE *);
int main()
{

int choice;
char res;
system("cls");

printf("\n\n=================ADMIN RIGHTS===================\n\n");
printf("press[Y] to continue to.... \n\n");
scanf("%c",&res);
if(res=='Y')
{
	admin(fp1);
}

printf("=================Enter Username================\n\n");
char username[20],password[20];
scanf("%s",username);
char character,pro[10];
int temp;
printf("=================PASSWORD========================\n\n");
scanf(" %s",password);

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
			
			printf("\nPRODUCT.ID	NAME			QUANTITY			PRICE\n\n");
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


void admin(FILE *fp)
{
	product *p1;
	p1=(struct p*)malloc(sizeof(struct p));
	
	int ch;
	printf("\n\n[1]TO ADD A PRODUCT TO INVENTORY\n[2]TO REMOVE AN ITEM FROM INVENTORY\n\n");
	scanf("%d",&ch);
	
	if(ch==1)
	{
		printf("Enter the Product ID:\n");
		scanf("%s",p1->ID);
		printf("Enter the Product name:\n");
		scanf("%s",p1->name);
		printf("Enter the number of quantity:\n");
		scanf("%d",p1->quantity);
		printf("Enter the price of the item:\n");
		scanf("%lf",p1->price);
		fp=fopen("electronics.txt","w+");
		fprintf(fp,"%-10s%-20s%d%lf",p1->ID,p1->name,p1->quantity,p1->price);
		display(fp);
		
	
	}
	
	
}
	
	void display(FILE *fp)
	{
		char c;
		while(c=fgetc(fp)!=EOF)
		{
			putc(c,fp);
		
		}
	
	}









