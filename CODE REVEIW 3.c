#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct node
{
 char accountname[80];
 int accountnumber;
 char login[30];
 char password[30];
 float balance;
 struct node *next;
};
typedef struct node n;
n *first=NULL,*p=NULL;
void create();
void deposit();
void withdraw();
void display();
void exit();
void deleteacc();
int main()
{
    printf("*****************************************************************************\n");
    printf("*****************************************************************************\n");
    printf("*****************************************************************************\n");
    printf("*  * * *     NEW HORIZON COLLEGE OF ENGINEERING-2018-19              * * *  *\n");
    printf("* * * * *                BANK DETAILS SOFTWARE                      * * * * *\n");
    printf("*  * * *                             -mini project by Shreyas C      * * *  *\n");
    printf("*****************************************************************************\n");
    printf("*****************************************************************************\n");
    printf("*****************************************************************************\n");
    int ch;
    while(1)
    {
      printf("\nDATABASE\n 1.CREATE ACCOUNT\n 2.DEPOSIT MONEY\n 3.WITHDRAWAL\n 4.DISPLAY ACCOUNT DETAILS\n 5.DELETE ACCOUNT\n 6.EXIT\n");
      scanf("%d",&ch);
      if(ch==1)
      {
        create();
      }
        if(ch==2)
        {
          deposit();
        }
        if(ch==3)
        {
          withdraw();
        }
        if(ch==4)
        {
           display();
        }
        if(ch == 5)
        {
            deleteacc();
        }
       if(ch==6)
        {
          exit(0);
        }

    }
    return 0;
}
void create()
{
    n *temp=first;
    p=(n*)malloc(sizeof(n));
    printf("Enter The Account Name :");
    scanf("%s",(p->accountname));
    printf("Enter The Account Number :");
    scanf("%d",&(p->accountnumber));
     while(temp!=NULL)
     {
         if(p->accountnumber==temp->accountnumber)
         {
             printf("Account number already in database \n");
             printf("Please enter a different account number:");
             scanf("%d",&(p->accountnumber));
             break;
         }
         temp = temp->next;
     }
    printf("Enter New Login ID:");
    scanf("%s",&(p->login));
    printf("Enter New Password:");
    scanf("%s",&(p->password));
    p->balance=0;
    p->next=first;
    first=p;
}
void display()
{
  int flag=0;
  n *temp=first;
  char loginchk[30];
  char passwordchk[30];
  printf("Login:");
  scanf("%s",loginchk);
  printf("Password:");
  scanf("%s",passwordchk);
  if(first!=NULL)
  {
    while(temp!=NULL)
    {
     if(strcmp(loginchk,temp->login)==0 && strcmp(passwordchk,temp->password)==0)
     {
      printf("The Account Name is : %s\n",temp->accountname);
      printf("The Account Number is : %d\n",temp->accountnumber);
      printf("The Balance Is : %f\n",temp->balance);
      flag++;
      break;
     }
     temp=temp->next;
    }
    if(flag==0)
    {
        printf("Invalid Login or Password.");
    }
  }
   else{
     printf("DATABASE DOES NOT EXIST");
   }
}
void deposit()
{
  struct node *temp=first;
  int flag=0,acctnum;
  float amt;
  printf("Enter The Account Number :");
  scanf("%d",&acctnum);
  printf("Enter The Amount To Be Deposited :");
  scanf("%f",&amt);
  while(temp!=NULL)
  {
    if(temp->accountnumber==acctnum)
    {
     temp->balance=temp->balance+amt;
     printf("AMOUNT DEPOSITED SUCESSFULLY");
     flag++;
     break;
    }
    temp=temp->next;
  }
  if(flag==0)
    {
        printf("ACCOUNT INVALID");
    }
}
void withdraw()
{
  struct node *temp=first;
  int flag=0,acctnum;
  float amt;
  printf("Enter The Account Number");
  scanf("%d",&acctnum);
  printf("Enter The Amount To Be Withdrawn");
  scanf("%f",&amt);
  while(temp!=NULL)
  {
    if(temp->accountnumber==acctnum)
    {
      if(temp->balance>=amt)
       {
        temp->balance=temp->balance-amt;
        printf("MONEY WITHDRAWN SUCESSFULLY");
        flag++;
        break;
       }
       else
       {
           printf("INSUFFICIENT FUNDS");
           break;
       }
    }
    temp=temp->next;
  }
  if(flag==0)
    {
        printf("ACCOUNT NUMBER INVALID");
    }
}
void deleteacc()
{
    n *prev=NULL,*temp = first;
    int acctnum;
    printf("Enter The Account Number Of Account To Be Deleted :");
    scanf("%d",&acctnum);

    if(first==NULL)
    {
        printf("No data base\n");
    }
    else if (first->next == NULL)
    {
      if(temp->accountnumber==acctnum)
      {

          free(temp);
          first=NULL;
        printf("Deleted Successfully");

      }
    }
    else{
    while(temp->accountnumber!=acctnum)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next= temp->next;

    free(temp);
    printf("Deleted Successfully");
}
}




