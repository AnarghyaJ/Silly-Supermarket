
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void add(char *);
void remov (char *);
void display(char *);
void addToNode(FILE *,int );
void checkout(void);
void freenode( void);
void signup(void);
void update(char *,int);
typedef struct p
{
        char ID[10];
        char name[20];
        int quantity;
        float price;
        struct p *next;

}product;
product *head=NULL,*previous=NULL;
int search (char *,char *);
void admin(void );
void user( );
product* getnode(void);
void connection(void);
int validation(char *,char *);

int main()
{

int choice;
char res;
system("clear");
char username[20],password[20];
printf("\n\n=================ADMIN RIGHTS===================\n\n----------------------------------------------------------\n\n");
printf("...............PRESS[Y] TO CONTINUE ....,,,,,,,,,,, \n\n");
scanf("%c",&res);
if(res=='Y'|res=='y')
{
	do{
		printf("\nEnter the Password\n");
		scanf("%s",password);
		if(strcmp(password,"admin")!=0)
			printf("\n\nInvalid password,Re-Enter:\n");
		}while(strcmp(password,"admin")!=0);
		admin();
		
}
else
{
	system("clear");
	printf("\n============WOULD YOU LIKE TO CONTINUE AS USER............?\n");
	printf("\nPRESS[1] to proceed as customer\nPRESS[2] to exit the program\n");
	scanf("%d",&choice);
	if(choice==2)
		exit(0);
		
	if(choice==1)
{

system("clear");
do
{	
printf("=================Enter Username================\n\n");
scanf("%s",username);



printf("\n=================PASSWORD========================\n\n");
scanf("%s",password);

if(validation(username,password)!=1)
	printf("\n\nINVALID USERNAME OR PASSWORD,PLEASE RETRY\n");
	

}while(validation(username,password)!=1);
user();

}
}
}

int validation(char *usr,char *passwd)
{
	
	int lineNum,temp=1;
	FILE *fp;
	char c,t[2];
	char buffer1[20],buffer2[20];
	lineNum=search("userDB.txt",usr);
	
	
	if(lineNum==-1)
		return -1;
		
	fp=fopen("userDB.txt","r");
		if(fp==NULL)
		{	printf("\n file opening failed\n");}
	
	
	while(c !=EOF)
	{
		c=getc(fp);
		if(c=='\n')
			temp++;
			
		if(lineNum==temp)
		{
		while(c!='\n')
			c=getc(fp);
			
		fscanf(fp,"%s%c%s",buffer1,&t[0],buffer2);
		
		if(strcmp(passwd,buffer2)==0)
			return 1;
		
		
		}
	
	}
	rewind(fp);
	fclose(fp);
	return -1;
	

}








void user( )
{

	int choice;
	
	FILE *fp;
	char character,pro[20];
    int temp,i=1;
    int quantity;
	printf("\n\nENTER THE CATEGORY\n");
	printf("\t[1]ELECTRONICS\n\t[2]FURNITURE\n\t[3]GROCERY\n\t[4]AUTOMOBILES\n\t[5]LIFESTYLE\n\t[6]HOME\n\t[7]EXIT\n");
	scanf("%d",&choice);

switch(choice)
{
        case 1:
						system("clear");
						printf("\n==============================ELECTRONICS====================\n\n");
                        fp=fopen("electronics.txt","r+");
                        if(fp==NULL)
                        {
                                printf("\nFILE OPENING ERROR!\n");
								return ;

                        }

                       
                        display("electronics.txt");
                        
                        printf("\n\nENTER THE PRODUCT,YOU WANT TO PURCHASE\n\n");
                        scanf("%s",pro);

                        printf("\n\t\tProduct Selected:%s",pro);

                        temp=search("electronics.txt",pro);
                        if(temp==-1){
						
                        	printf("\n\n\tSomething Wrong!! Product you entered not found\n");
                        	main();}
                        else
                        {	printf("\n\tEnter the quantity\n");
                        	scanf("%d",&quantity);
						}
						character=getc(fp);
					while(character !=EOF)
                        {
                        	if(i==temp-1)
                        	{
                        		while(character!='\n')
                        		{
                        			character=getc(fp);
                        			
								}
								i++;
								addToNode(fp,quantity);
								update("electronics.txt",temp);
								connection();
								break;
						
							}
							else
							{
								if(character=='\n')
									i++;
									
							}
							character=getc(fp);
                        		
						}
						fclose(fp);
						break;
                    
                       
						fclose(fp);
						break;
						
						
			case 2:
								system("clear");
						printf("\n==============================FURNITURE====================\n\n");
                        fp=fopen("furniture.txt","r+");
                        if(fp==NULL)
                        {
                                printf("\nFILE OPENING ERROR!\n");
								return;

                        }

                        display("furniture.txt");
                        printf("\n\nENTER THE PRODUCT,YOU WANT TO PURCHASE\n\n");
                        scanf("%s",pro);

                        printf("\n\t\tProduct Selected:%s\n",pro);
						
                        temp=search("furniture.txt",pro);
                        if(temp==-1){
						
                        	printf("\n\n\tSomething Wrong!! Product you entered not found\n");
                        	main();}
                        else
                        {	printf("\n\tEnter the quantity\n");
                        	scanf("%d",&quantity);
						}
                        character=getc(fp);
                        while(character !=EOF)
                        {
                        	if(i==temp-1)
                        	{
                        		while(character!='\n')
                        		{
                        			character=getc(fp);
                        			
								}
								i++;
								addToNode(fp,quantity);
								update("furniture.txt",temp);
								connection();
								
						
							}
							else
							{
								if(character=='\n')
									i++;
									
							}
							character=getc(fp);
                        		
						}
						fclose(fp);
						break;
						
						
						
			case 3:
						system("clear");
						printf("\n==============================GROCERY====================\n\n");
                        fp=fopen("grocery.txt","r+");
                        if(fp==NULL)
                        {
                                printf("\nFILE OPENING ERROR!\n");
								exit(0);

                        }

                        
                        display("grocery.txt");
                        printf("\n\nENTER THE PRODUCT,YOU WANT TO PURCHASE\n\n");
                        scanf("%s",pro);

                        printf("\n\t\tProduct Selected:%s\n",pro);
						
                        temp=search("grocery.txt",pro);
                        if(temp==-1){
						
                        	printf("\n\n\tSomething Wrong!! Product you entered not found\n");
 							main();}                       
                        else
                        {	printf("\n\tEnter the quantity\n");
                        	scanf("%d",&quantity);
						}
                        character=getc(fp);
                        while(character !=EOF)
                        {
                        	if(i==temp-1)
                        	{
                        		while(character!='\n')
                        		{
                        			character=getc(fp);
                        			
								}
								i++;
								addToNode(fp,quantity);
								update("grocery.txt",temp);
								connection();
								
						
							}
							else
							{
								if(character=='\n')
									i++;
									
							}
							character=getc(fp);
                        		
						}
						fclose(fp);
						break;
						
		case 4:
		
					system("clear");
						printf("\n==============================AUTOMOBILE=========================\n\n");
                        fp=fopen("automobiles.txt","r+");
                        if(fp==NULL)
                        {
                                printf("\nFILE OPENING ERROR!\n");
								return;

                        }

                        
                        display("automobiles.txt");
                        printf("\n\nENTER THE PRODUCT,YOU WANT TO PURCHASE\n\n");
                        scanf("%s",pro);

                        printf("\n=======================================\n\t\tProduct Selected:\n%s",pro);
						
                        temp=search("automobiles.txt",pro);
                        if(temp==-1){
						
                        	printf("\n\n\tSomething Wrong!! Product you entered not found\n");
                        	main();}
                    	else
                        {	printf("\n\tEnter the quantity\n");
                        	scanf("%d",&quantity);
						}
                        character=getc(fp);
                        while(character !=EOF)
                        {
                        	if(i==temp-1)
                        	{
                        		while(character!='\n')
                        		{
                        			character=getc(fp);
                        			
								}
								i++;
								addToNode(fp,quantity);
								update("automobiles.txt",temp);
								connection();
								break;
						
							}
							else
							{
								if(character=='\n')
									i++;
									
							}
							character=getc(fp);
                        		
						}
						fclose(fp);
						break;
						
						
			case 5:
						
						system("clear");
						printf("\n==============================LIFESTYLE===========================\n\n");
                        fp=fopen("lifestyle.txt","r+");
                        if(fp==NULL)
                        {
                                printf("\nFILE OPENING ERROR!\n");
								return ;

                        }

                        
                        display("lifestyle.txt");
                        printf("\n\nENTER THE PRODUCT,YOU WANT TO PURCHASE\n\n");
                        scanf("%s",pro);

                        printf("\n\t\tProduct Selected:%s\n",pro);
						
                        temp=search("lifestyle.txt",pro);
                        if(temp==-1){
						
                        	printf("\n\n\tSomething Wrong!! Product you entered not found\n");
                        	main();}
                        
                        else
                        {	printf("\n\tEnter the quantity\n");
                        	scanf("%d",&quantity);
						}
                        rewind(fp);
                        
                        character=getc(fp);
                        while(character !=EOF)
                        {
                        	if(i==temp-1)
                        	{
                        		while(character!='\n')
                        		{
                        			character=getc(fp);
                        			
								}
								i++;
								addToNode(fp,quantity);
								update("lifestyle.txt",temp);
								connection();
								break;
						
							}
							else
							{
								if(character=='\n')
									i++;
									
							}
							character=getc(fp);
                        		
						}fclose(fp);
						break;
						
						
	case 6:	main();break;
	
	
	case 7:freenode();exit(0);
	
	
						

}


}

void connection(void)
{

								int forward;
								system("clear");
								printf("\n\t[1]IF YOU WANT TO CONTINUE SHOPPING\n\t[2]TO GO TO MAIN MENU\n\t[3]PROCEED TO CHECKOUT\n\n");
								scanf("%d",&forward);
								switch(forward)
								{
									case 1:user();break;
									
									case 2:main();break;
									
									case 3:checkout();break;
									
									default:printf("\n Invalid input,RE-ENTER\n");connection();
								
								
								
								}
								
							return;	
								
								
								
								
}



void addToNode(FILE *fp,int quantity)
{
	product *temp=head;
	char t[10];
	if(head==NULL)
	{
		head=getnode();
		if(head==NULL)
			printf("\nNode not created\n");
		head->next=NULL;
		fscanf(fp,"%s%c%s%c%d%c%f%c",head->ID,&t[1],head->name,&t[2],&(head->quantity),&t[3],&(head->price),&t[4]);
		head->quantity=quantity;
	}
	else
	{
	while(temp!=NULL)
	{
		previous=temp;
		temp=temp->next;
		
	}
	previous->next=getnode();
	(previous->next)->next=NULL;
		fscanf(fp,"%s%c%s%c%d%c%f%c",previous->next->ID,&t[5],previous->next->name,&t[6],&(previous->next->quantity),&t[7],&(previous->next->price),&t[8]);
		previous->next->quantity=quantity;
	}
	
	return;

}

int search(char *filename,char *s)
{
		FILE *fp;
        int lineNumber=1;
        fp=fopen(filename,"r");
        if(fp==NULL)
        	printf("\n FILE NOT OPEN FOR SEARCH\n");
        rewind(fp);
        int stringIndex;
		char c;
		

		do
		{
			c=getc(fp);
			stringIndex=0;
				
			if(c=='\n')
				lineNumber++;
			while(c == s[stringIndex])
			{
				c=getc(fp);
				stringIndex++;
			}
			if(stringIndex==strlen(s))
				return lineNumber;
			
		}while(c!=EOF);
		
		
		fclose(fp);
		return -1;
}


void admin(void)
{
        
        int ch,department;
	printf("\n\n\n\n");
        printf("\n\n\t[1]TO ADD A PRODUCT TO INVENTORY\n\t[2]TO REMOVE AN ITEM FROM INVENTORY\n\t[3]DISPLAY INVENTORY\n\t[4]SIGN-UP OF A NEW CUSTOMER\n\t[5]MAIN MENU\n\t[6]EXIT");
        scanf("%d",&ch);
		
        switch(ch)
        {
        	case 1:
        		printf("\n\nEnter the department in which to add the product\n");
        		printf("\n\t[1]ELECTRONICS\n\t[2]FURNITURE\n\t[3]GROCERY\n\t[4]AUTOMOBILES\n\t[5]LIFESTYLE\n\t[6]MAIN MENU\n\t[7]If you want to Exit...");
        		scanf("%d",&department);
        		switch(department)
        		{
					case 1:
							add("electronics.txt");
							admin();break;
							
					case 2:add("furniture.txt");admin();break;
					
					case 3:add("grocery.txt");admin();break;
					
					case 4:add("automobiles.txt");admin();break;
					
					case 5:add("lifetstyle.txt");admin();break;
					
					case 6:main();break;
					
					case 7:printf("\n\nEnding program...BYE\n");exit(0);
					
					default:printf("\n\nInvalid Entry\nProgram Exiting........\n");
							exit(0);
				}break;
				
			case 2:
					
					system("clear");
					
					printf("\nENTER THE DEPARTMENT FROM WHICH product is to be deleted\n");
					printf("\n\t[1]ELECTRONICS\n\t[2]FURNITURE\n\t[3]GROCERY\n\t[4]AUTOMOBILES\n\t[5]LIFESTYLE\n\t[6]MAIN MENU\n\t[7]If you want to Exit...\n");
					scanf("%d",&department);
					switch(department)
        		{
					case 1:
							remov("electronics.txt");admin();break;
							
					case 2:remov("furniture.txt");admin();break;
					
					case 3:remov("grocery.txt");admin();break;
					
					case 4:remov("automobiles.txt");admin();break;
					
					case 5:remov("lifetstyle.txt");admin();break;
					
					case 6:main();break;
					
					case 7:printf("\n\nEnding program...BYE\n");exit(0);
					
					default:printf("\n\nInvalid Entry\nProgram Exiting........\n");
							exit(0);
				}break;
					
					
				
				
				
				
		case 3:	
				system("clear");
				printf("\nENTER THE DEPARTMENT IN,WHICH YOU ARE INTERESTED\n");
				printf("\n\t[1]ELECTRONICS\n\t[2]FURNITURE\n\t[3]GROCERY\n\t[4]AUTOMOBILES\n\t[5]LIFESTYLE\n\t[6]MAIN MENU\n\t[7]If you want to Exit...\n");
				scanf("%d",&department);
					switch(department)
        		{
					case 1:
							display("electronics.txt");admin();break;
							
					case 2:display("furniture.txt");admin();break;
					
					case 3:display("grocery.txt");admin();break;
					
					case 4:display("automobiles.txt");admin();break;
					
					case 5:display("lifetstyle.txt");admin();break;
					
					case 6:main();break;
					
					case 7:printf("\n\nEnding program...BYE\n");exit(0);
					
					default:printf("\n\nInvalid Entry\nProgram Exiting........\n");
							exit(0);
				}break;
        
		
		case 4:		system("clear");
					printf("\n\n**********************        SIGN - UP        ***************************\n");
					signup();admin();break;
		
				
		
		
		
		case 5:main();break;      

		case 6:exit(0);
		
		default:printf("\n\n\t\tInvalid input:Re-Enter\n");
				admin();break;
				
        }


}



 void display(char *filename)
        {
        	FILE *fp;
        	fp=fopen(filename,"r+");
        	system("clear");
        	printf("\n\n---------------------------------------------------------------------------\n");
		printf("P.ID      PROD.NAME      QTY       PRICE\n\n");
		printf("\n---------------------------------------------------------------------------\n");
	
                char c;
                do
                {
                	c=getc(fp);
                	printf("%c",c);
				}while(c != EOF);
				
				fclose(fp);

        }



void add(char *department)
{
	product p1;
	FILE *fp;
		

	do{
		system("clear");
	

		
	  			printf("Enter the Product ID:\n");
                scanf("%s",p1.ID);
                
                printf("Enter the Product name:\n");
                scanf("\n%s",p1.name);
                
                printf("Enter the number of quantity:\n");
                scanf("\n%d",&p1.quantity);
                
                printf("Enter the price of the item:\n");
                scanf("\n%f",&p1.price);
		
		if(p1.quantity <0 || p1.price<0)
			printf("\n\n\tILLEGAL ENTRY FOR ARITHMETIC VALUES:RE-ENTER\n");


           }while(p1.quantity<0 || p1. price < 0);
     
                fp=fopen(department,"a+");
                
                fprintf(fp,"%s\t%s\t%d\t%f\n",p1.ID,p1.name,p1.quantity,p1.price);
                
                fclose(fp);
                admin();
                
	
	


}
void remov(char *department)

{
	FILE *fp1,*fp2;
	fp1=fopen(department,"r");
	char ch;
	char product[20];
	int line_no,temp=1;
	system("clear");
	printf("\n\n======================FILE CONTENTS FOR REMOVAL===========================\n\n");
	display(department);
	
	printf("\n ENTER THE PRODUCT DETAILS\n");
	scanf("%s",product);
	
	line_no=search(department,product);
	
	if(line_no==-1)
		printf("\n\nSomething Wrong!\n");
	
		
	else
	{
		fp2=fopen("replica.txt","w");
		
    while(ch != EOF)
    {
	
    	ch=getc(fp1);
    	if(temp==line_no-1)
    	{
    	do
    	{
    		ch=getc(fp1);
    		putc(ch,fp2);	
		}while(ch != '\n');
		temp++;
		do
		{
		ch=getc(fp1);
		}while(ch != '\n');
		}
    	putc(ch,fp2);
    	if(ch=='\n')
    		temp++;
    	
	}
	printf("\n\n\n");
	
	fclose(fp1);
    fclose(fp2);
    remove(department);
    /*rename the file replica.c to original name*/
   if( rename("replica.txt",department) ==-1)
   		printf("\n\nRENAME FAILED\n");
    
    printf("\n==========FILE CONTENTS AFTER DELETION==================\n");
    display(department);
    }
	
}


product * getnode(void)
{
	product *temp;
	temp=(product *)malloc(sizeof(product));
	if(temp==NULL)
		{
			printf("\nUh....MALLOC failed on you!!!!!\n\n");exit(0);
		}
	return temp;
	

}

void checkout(void)
{

FILE *check;
product *temp=head;
check=fopen("checkout.txt","w");

char c,t[ ]="checkout.txt";

float total=0;

while(temp!=NULL)
{
	fprintf(check,"%s\t%s\t%d\t%f\n",temp->ID,temp->name,temp->quantity,temp->price);
	total=total+(temp->price)*temp->quantity;
	temp=temp->next;
}
system("clear");
fclose(check);
printf("\n=======================TOTAL BILLING===========================\n");
printf("\nP.ID	  Name	    Quantity	   Price \n");
display(t);


printf("\n ======================TOTAL======================\n\t\tAmount Payable=%f\n---------------------------------------------------\n",total);





}

void freenode( )
{
	product *temp;
	while(head !=NULL)
	{
		temp=head;
		head=head->next;
		free(temp);
	}
	return;

}

void signup(void)
{
	char usr[10],passwd[10],tmp[10];
	FILE *fp;
	fp=fopen("userDB.txt","a+");
	printf("\nENTER THE USERNAME:");
	scanf("%s",usr);
	printf("\nENTER THE PASSWORD:");
	scanf("%s",passwd);
	do
	{
		printf("\n\nCONFIRM THE PASSWORD:");
		scanf("%s",tmp);
		if(strcmp(tmp,passwd))
			{
				printf("\nWRONG RE-ENTER!! \n\n");	
			}
		
	}while(strcmp(tmp,passwd)!=0);
	
				fprintf(fp,"%s\t%s\n",usr,passwd);
				fclose(fp);
				printf("\n\n\n\t\tREGISTRATION DONE !\n");
				system("clear");
				admin();


}


void update(char *filename,int lineno)
{
	FILE *fp1,*fp2;
	product p;
	char c,d,ch[10];
	int t=1; 
	printf("LINENO:%d",lineno);
	fp1=fopen(filename,"r");
	fp2=fopen(filename,"r+");
	d=getc(fp2);
	c=getc(fp1);
	while(c!= EOF)
	{
		if(t==lineno -1)
		{
			do{
				c=getc(fp1);
				d=getc(fp2);
				
			}while(c!='\n' | d!='\n');
			
			fscanf(fp1,"%s%c%s%c%d%c%f%c",p.ID,&ch[1],p.name,&ch[2],&(p.quantity),&ch[3],&(p.price),&ch[4]);
			p.quantity=(p.quantity)--;
			fprintf(fp2,"%s\t%s\t%d\t%f\n",p.ID,p.name,p.quantity,p.price);
		}
		
		if(c == '\n')
				t++;
				
		c=getc(fp1);
		d=getc(fp2);
	
	}
	fclose(fp1);
	}
	

