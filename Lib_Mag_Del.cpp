#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
struct user
{
char id[9];
int pass;
char block;
int room;
} stu[100];
struct user *ptr=stu;



struct book1
{
char name[50];
int year;
int qty;
}book[100];



struct checkout
{
char b_name[50];
char id[8];
char block;
int  r_no;
int shipped;
int delievered;
struct checkout *next;
}*front, *rear, *temp,*pr,*temp1;

char s[8],bk;
int empid[100];
int n,m,p,r;



void initializing()
{
front=NULL;
rear=NULL;
p=0;
n=0;
m=0;
}



int empmenu()
{
int c,d,e,f;
do
{
cout<<"\nEnter \n1.Adding books \n2.Student checkout \n3.Update status \n4.exit\n";
cin>>c;
switch(c)
{
case 1:
{
cout<<"\nEnter the name, year of publication and quantity:\n";
cin>>book[p].name;
cin>>book[p].year;
cin>>book[p].qty;
p++;
break;
}
case 2:
{
temp=temp1;
if(front!=NULL)
{
do
{
cout<<"\n";
puts(temp->b_name);
puts(temp->id);
cout<<temp->block<<":"<<temp->r_no;
if(temp->shipped==1)
{
cout<<"\nShipped\n";
}
else
{
cout<<"\nNot Shipped\n";
}
if(temp->delievered==1)
{
cout<<"\nDelievered\n";
}
else
{
cout<<"\nNot Delievered\n";
}

temp=temp->next;
}while(temp!=NULL);
}
else cout<<"\nNo Checkout\n";
break;
}
case 3:
{
temp=temp1;
if(front!=NULL)
{

cout<<"\nDo you want to update the book status enter 1:\n";
cin>>d;
if(d==1)
{
temp=front;
cout<<"\nEnter \n1.Update shipped \n2.Update Delievered\n";
cin>>e;
if(e==1)
{
cout<<"\nHow many of the books are shipped?\n";
cin>>f;
for(int i=0;i<f;i++)
{
temp->shipped=1;
temp=temp->next;
}
}
else
{
cout<<"\nHow many of the books are delievered?\n";
cin>>f;
for(int i=0;i<f;i++)
{
temp->delievered=1;
temp=temp->next;
front=front->next;
}
}
}
}
else cout<<"\nNo Checkout\n";
break;
}
case 4:
{
break;
}
default:
{
cout<<"\nWrong Choice\n";
break;
}	
}
}while(c!=4);
return 0;
}




void studentmenu()
{
int a,c=0,flag=0,x=0,g=0;
char b[50];
do
{
cout<<"\nEnter: \n1.list of all the book \n2.Search \n3.Checkout \n4.Status \n5.exit\n";
cin>>a;
switch(a)
{

case 1:
{

for(int i=0;i<=p;i++)
{

if(book[i].qty>0 && p>0)
{
	g=1;
cout<<"\n"<<book[i].name<<":"<<book[i].year;
}
}
if(g==0)
{
cout<<"\nNo Books Available\n";
}

break;
}
case 2:
{
cout<<"\nEnter the name of the book:\n";
cin>>(b);
for(int i=0;i<p;i++)
{
if((strcmp(b,book[i].name)==0) && (book[i].qty>0))
{
cout<<"\nAvailable\n";
flag=1;
}
}
if(flag==0)
{
cout<<"\nBook not available\n";
}	
break;	
}
case 3:
{
cout<<"\nEnter the book to be checked out:\n";
cin>>b;
for(int i=0;i<p;i++)
{
if((strcmp(b,book[i].name)==0) && (book[i].qty>0))
{
cout<<"\nAvailable\n";
flag=1;
}
}
if(flag==0)
{
cout<<"\nBook not available\n";
}
else
{
pr=new struct checkout;
cout<<"\nEnter 1.To check out\n";
cin>>c;
if(c==1)
{
strcpy(pr->id,s);
strcpy(pr->b_name,b);
pr->block=bk;
pr->r_no=r;
pr->delievered=0;
pr->shipped=0;
pr->next=NULL;
if(rear==NULL)
{
front=pr;
rear=front;
temp1=front;
}
else
{
rear->next=pr;
rear=pr;
}
}
}
break;
}
case 4:
{
temp=temp1;
if(front!=NULL)
{
do
{
if(strcmp(temp->id,s)==0)
{
x=1;
cout<<"\n";
puts(temp->b_name);
puts(temp->id);
if(temp->shipped==1)
{
cout<<"\nShipped\n";
}
else
{
cout<<"\nNot Shipped\n";
}
if(temp->delievered==1)
cout<<"\nDelievered";
else
cout<<"\nNot Delievered\n";
temp=temp->next;
}
}while(temp!=NULL);
if(x==0)
{
cout<<"\nNo Book Available\n";
}
}
else 
{
cout<<"\nNo Available Book\n";
}
break;
}
case 5:
{
break;
}
default:
{
cout<<"\nWrong Choice\n";
break;
}
} 
}while(a!=5);
}




void student()
{
int a, b;
char c[10];
cout<<"\n"<<"Enter: \n1.Sign UP \n2.Sign In\n";
cin>>a;
if(a==1)
{
ptr++;
n++;
cout<<"\nEnter the student ID:\n";
cin>>ptr->id;
cout<<"\nEnter the pass: 4 numerical character:\n";
cin>>ptr->pass;
cout<<"\nEnter the block:\n";
cin>>ptr->block;
cout<<"\nEnter the room number:\n";
cin>>ptr->room;
student();
}
else
{
cout<<"\nEnter the student user id:\n";
cin>>c;
cout<<"\nEnter the password:\n";
cin>>b;
for(int i=0;i<n;i++)
{
if(strcmp(c,ptr->id)==0)
{
if(b==ptr->pass)
{
strcpy(s,ptr->id);
bk=ptr->block;
r=ptr->room;
studentmenu();
}
}
else
{
ptr++;
}
}
}
}




void emp()
{ 
int a,b;
cout<<"\nEnter \n1.Enter new user \n2.Sign in\n";
cin>>a;
if(a==1)
{
m++;
cout<<"\nEnter the employee ID\n";
cin>>empid[m];
}
else
{
cout<<"\nEnter the employee id\n";
cin>>b;
for(int i=0;i<=m;i++)
{
if(empid[i]==b)
{
empmenu();
}
}
}
}





int main()
{
int a;
initializing();
do
{
cout<<"\nEnter \n1.For Student Login \n2.For Faculity login \n3.Exit\n";
cin>>a;
switch(a)
{
case 1:
{
student();
break;
}	
case 2:
{
emp();
break;
}
case 3:
{
break;
}
default:
{
cout<<"\nWrong Choice\n";
break;
}
}
}while(a!=3);
return 0;
}
