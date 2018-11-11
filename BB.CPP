#include<iostream.h>
#include<string.h>
#include<fstream.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdio.h>
/* GLOBALY DECLARED VARIABLES */

long gh[5],e[5],hj,er,zx,fg,tc,r;
char choice;//bazar_o;
long p1,p2,p3,p4,p5;
int a1,a2,ch,a3,a4,a5,a6,a7,a10;
long dis,total,dno=0;

/* CLASS CONTAINING IMP. FUNCTIONS & VARIABLES */
class customer
{
public:
int id;
char name[20];
int phone;
int recptn;
int payback;

customer()
{
	id=0;
	name[0]='\0';
	recptn = phone= payback = 0;
}
void getdata()
{
	cout<<"Enter ID:: ";
	cin>>id;
	cout<<"Enter Name ";
	gets(name);
	cout<<"Enter Mobile::";
	cin>>phone;
}
void updatepayback(int n)
{
	payback +=n;
}

void updaterec(int n)
{
	recptn = n;

}
void display()
{
	cout<<"Name::"<<name<<"\nid::"<<id<<"\nPayBack pointS::"<<payback;
	cout<<"LAst Shopping Recpt::"<<recptn;
}
};
void custmenu()
{
	clrscr();
	cout<<"\n1. Add Customer";
	cout<<"\n2. Modify Customer Payback points";
	cout<<"\n3. Delete customer ";
	cout<<"\n4. Display";
}
void custdisplay()
{
	ifstream file;
	customer c;
	file.open("cust.dat",ios::in|ios::binary);
	while(file.read((char*)&c,sizeof(c))){
		c.display();
	}
	file.close();
}
void custadd(int p, int r)
{
	ofstream file;
	customer c;
	file.open("cust.dat",ios::out|ios::app|ios::binary);
	c.getdata();
	c.updatepayback(p);
	c.updaterec(r);
	file.write((char*)&c,sizeof(c));
	file.close();
}
void custmodify(int id,int p, int r)
{
	fstream file;
	customer c;
	int pos;
	file.open("cust.dat",ios::out|ios::in|ios::binary);
	while(file.read((char*)&c,sizeof(c))){
		pos = file.tellg();
		if(c.id==id)
		{
			c.updatepayback(p);
			c.updaterec(r);
			cout<<"\nUpdated Payback Points ";
			cout<<c.payback;

			break;
		}
	}
	file.seekg(pos-sizeof(c),ios::beg);
	file.write((char*)&c,sizeof(c));

	file.close();
}

void custdel(int id)
{
	ifstream file1("cust.dat",ios::in|ios::binary);
	ofstream file2("cust.dat",ios::out|ios::binary);
	customer c;
	while(!file1.eof())
	{
	      file1.read((char*)&c,sizeof(c));
	      if(c.id!=	id)
		file2.write((char*)&c,sizeof(c));

	}
	file1.close();
	file2.close();
	remove("cust.dat");
	rename("temp.dat","cust.dat");



}
class bazar
{
public:
long q,c1,u;
long o1;
char x;
/* FUNCTION CONTAINING INF. ABOUT THE OPERATIONS OF PROGRAM */
void enterance()
{
cout<<"Welcome to BIG BAZAAR\n"<<endl;

cout<<"You can select your choice from the following options\n"<<endl;

cout<<"For placing an order press 1"<<endl;
cout<<"For watching previous record press 2"<<endl;
cout<<"For discount offer press 3"<<endl;
cout<<"For exchange offer press 4"<<endl;
cout<<"To know about the available products & their prices press 5"<<endl;
cout<<"To Customer Details press 10"<<endl;
cout<<"To exit press 6"<<endl;
cin>>u;
}
/* FUNCTION CONTAINING INF. ABOUT THE STATIONARY PRODUCTS */
void stationary()
{
a1=1;

//cout<<"YOU HAVE CHOSEN STATIONARY";



cout<<"Now you have following choices\n";
cout<<"CODE ITEM                          PRICE\n";
cout<<"1.King size register               RS.050\n";
cout<<"2.Glitter gllory pens              RS.100\n";
cout<<"3.Encyclopedia                     RS.500\n";
cout<<"4.Chart or sheets                  RS.035\n";
cout<<"5.geometry box(full)               RS.075\n";

p1=50;p2=100;p3=500;p4=35;p5=75;
}
/* FUNCTION CONTAINING INF.ABOUT FAST FOOD ITEMS */
void fastfood()
{
a2=2;

cout<<"YOU HAVE CHOSEN FAST FOOD";
cout<<"Now you have following choices\n";
cout<<"CODE ITEM                          PRICE\n";
cout<<"1.Burger/Pattis                    RS.100\n";
cout<<"2.Cold Drink with Chips            RS.150\n";
cout<<"3.Chowmein                         RS.075\n";
cout<<"4.Pizza                            RS.150\n";
cout<<"5.Cold Coffee with Ice Cream       RS.075\n";
p1=100;p2=150,p3=75,p4=150;p5=75;
}
/* FUNCTION CONTAINING INF.ABOUT THE ELECTRONIC PRODUCTS */
void electronics()
{
a3=3;


cout<<"YOU HAVE CHOSEN ELECTRONICS";
cout<<"Now you have following choices\n";
cout<<"CODE ITEM                          PRICE\n";
cout<<"1.LCD Colour Television            RS.45000\n";
cout<<"2.Refrigerator                     RS.57000\n";
cout<<"3.Washing Machine                  RS.35000\n";
cout<<"4.Computer System                  RS.61000\n";
cout<<"5.Microwave oven                   RS.15000\n";

p1=45000;p2=57000;p3=35000;p4=61000;p5=15000;

}
/* FUNCTION CONTAINING INF.ABOUT THE FURNITURE PRODUCTS */

void furniture()
{
a4=4;


cout<<"YOU HAVE CHOSEN FURNITURE";

cout<<"Now you have following choices\n";
cout<<"CODE ITEM                          PRICE\n";
cout<<"1.Sofa Set                         RS.40000\n";
cout<<"2.King size Bed                    RS.20000\n";
cout<<"3.Wooden Almirah                   RS.15000\n";
cout<<"4.Dining Table                     RS.17000\n";
cout<<"5.Six Chair set                    RS.10000\n";
p1=40000;p2=20000;p3=15000;p4=17000;p5=10000;

}
void customer()
{
	a10=10;
		clrscr();
	cout<<"\n1. Add new customer";
	cout<<"\n2. Modify customer paybackpoints";
	cout<<"\n3. delete customer records";

}
}o; //CLASS CLOSED   - Object declared as GOBAL
/* FUNCTION TO DISPLAY MAIN MENU */
void menu()
{

cout<<"BIG BAZAAR SHOPPING MALL";

cout<<"Here is the categorie menu\n\n";

cout<<"CODE CATEGORIE\n\n";

cout<<"  1.  Stationary\n\n";

cout<<"  2.  Fast food\n\n";

cout<<"  3.  Electronics\n\n";

cout<<"  4.  Furniture\n\n";

cout<<"  5.  Garments\n\n";


cout<<"Please enter the code of the categorie you want";
cin>>ch;
}
/*FUNCTION CONTAINING INF.ABOUT AVAILABLE GARMENTS */
void garments()
{
a5=5;
//bazar_o;


do
{
cout<<"\nWhat type of garments you want(M/F):";
cin>>o.x;
}while(tolower(o.x)!='m' && tolower(o.x)!='f');
if((o.x=='m')||(o.x=='M'))
{

cout<<"MALE GARMENTS"<<endl;
}
else
{

cout<<"FEMALE GARMENTS"<<endl;
}

switch(o.x)
{
case 'M':
case 'm':
cout<<"Now you have following choices\n\n";
cout<<"CODE ITEM                       PRICE\n";
cout<<"1. T-shirt                      RS.1000\n";
cout<<"2. Jeans/Trouser                RS.1500\n";
cout<<"3. Kurta Pajama                 RS.2500\n";
cout<<"4. Safari Suit                  RS.5000\n";
cout<<"5. 3-Piece Suit                 RS.3500\n";

p1=1000;p2=1500;p3=2500;p4=5000;p5=3500;

break;
case 'F':
case 'f':
cout<<"Now you have following choices\n\n";
cout<<"CODE ITEM                       PRICE\n";
cout<<"1. Ladies Jeans                 RS.2000\n";
cout<<"2. Sariee                       RS.5000\n";
cout<<"3. Night Suit                   RS.1500\n";
cout<<"4. Ladies Top                   RS.1000\n";
cout<<"5. Salwar Suit                  RS.1500\n";
p1=2000;p2=5000;p3=1500;p4=1000;p5=1500;
break;
default:cout<<"SORRY!!!INVALID SELECTION"<<endl;
}
}
/* FUNCTION CONTAINING INF.ABOUT THE EXCHANGE OFFERS */
void exchange()
{
a6=6;


cout<<"YOU HAVE CHOSEN EXCHANGE OFFERS";


cout<<"Now you have following choices\n";
cout<<"CODE ITEM        EXCHANGE ITEM         Extra Price\n";
cout<<"1.Wristwatch     Sonata Wristwatch     RS.500\n";
cout<<"2.Scooter        Yamaha Bike           RS.20000\n";
cout<<"3.Black&White TV LCD Colour TV         RS.3000\n";
cout<<"4.Old Mobile     Touch Screen Mobile   RS.2500\n";
cout<<"5.Old Jewellery  Gold Plated Jewellery RS.750\n";

p1=500;p2=20000;p3=3000;p4=2500;p5=750;

}
/* FUNCTION CONTAINING INF.ABOUT YHE DISCOUNT OFFERS */

void discount()
{
a7=7;

cout<<"YOU HAVE CHOSEN DISCOUNT OFFERS";


cout<<"Now you have following choices\n";
cout<<"CODE ITEM                             PRICE\n";
cout<<"1.With 5Kg Basmati Rice Get 1Ltr Oil  RS.400\n";
cout<<"2.With 1 Real Magic Jam Get 1 Free    RS.100\n";
cout<<"3.With 4Kg Surf Excel Get 1 Bucket    RS.450\n";
cout<<"4.With Any 5Kg Pulses 1kg Flour Free  RS.350\n";
cout<<"5.With 5Kg Fruit/Veg. Get 1 Homefoil  RS.550\n";

p1=400;p2=100;p3=450;p4=350;p5=550;

}
/* FUNCTION FOR CALCULATION OF PRICES */
void calc()
{
//bazar_o;


cout<<"How many items you want to purchase\n";
cin>>e[ch-1];

for(int i=1;i<=e[ch-1];i++)
{
cout<<"Please enter the code of the item["<<i<<"]you want to purchase\n";
cin>>o.c1;

if((o.c1<1)&&(o.c1>5))
{
cout<<"WRONG SELECTION!!!!!!!!!!"<<endl;
}

cout<<"What quantity of this item["<<i<<"]you want to purchase\n";
cin>>o.q;

switch(o.c1)
{
case 1:gh[ch-1]+=p1*o.q;
break;
case 2:gh[ch-1]+=p2*o.q;
break;
case 3:gh[ch-1]+=p3*o.q;
break;
case 4:gh[ch-1]+=p4*o.q;
break;
case 5:gh[ch-1]+=p5*o.q;
break;
default:cout<<"SORRY!!!INVALID SELECTION"<<endl;
}
}
cout<<"Price for this categorie"<<endl;
cout<<"RS."<<gh[ch-1]<<"/-only"<<endl;
}
/* MAIN FUNCTION */

void main()
{
void menu();
clrscr();

char str1[]="COMPUTER SCIENCE PROJECT";

for(int xy=0;str1[xy]!='\0';xy++)
{
cout<<str1[xy];

}

cout<<"ON";

char str2[]="SHOPPING AT BIG BAZAAR";

for(xy=0;str2[xy]!='\0';xy++)
{
cout<<str2[xy];

}
char str3[]="PREPARED BY :- Mudit and Mridul" ;

for(xy=0;str3[xy]!='\0';xy++)
{
cout<<str3[xy];

}
getch();
//bazar_o;
char str[21],st[21];
int g1;
int m,u1;

clrscr();
void enterance();

void stationary();
void fastfood();
void electronics();
void furniture();
void garments();

clrscr();

cout<<"\n\n\n\tWELCOME TO\n\n\n";


cout<<"\n\n\n\t\t\tBIG\n\n\n";


cout<<"\n\n\n\t\tBAZAAR";



getch();
do
{
clrscr();
o.enterance();
customer c;
if(o.u==10)
{
	char ch2;
	int option,id,p,r,a;
	do{
	clrscr();
	custmenu();

	cout<<"\n Please Enter Your Choice:: ";
	cin>>option;
	switch(option)
	{
		case 1:

		cout<<"\n\nEnter purchase amount: ";
		cin>>a;
		cout<<"Enter recpt num: ";
		cin>>r;
		p=a/100;
		custadd(p,r);
		break;

		case 2:
		cout<<"Enter ID of customer:: ";
		cin>>id;
		cout<<"Enter amount of purchase ";
		cin>>a;
		p=a/100;
		r=0;
		//c.updatepayback(p);
		custmodify(id,p,r);
		break;

		case 3:

		cout<<"enter ID of customer:: ";
		cin>>id;
		custdel(id);
		break;
		case 4:
		custdisplay();
		break;
		default:
		cout<<"Invalid option"<<endl;
	}
	cout<<"Do you want to continue";
	cin>>ch2;
	}while(ch2=='y'||ch2=='Y');

}

if(o.u==1)
{
do
{
clrscr();
/* TO DISPLAY MAIN MENU */
menu();
clrscr();
/* TO DISPLAY PRODUCTS FOR SELECTED CATEGORIES */

switch(ch)
{
case 1:o.stationary();
       calc();
       break;
case 2:o.fastfood();
       calc();
       break;
case 3:o.electronics();
       calc();
       break;
case 4:o.furniture();
       calc();
       break;
case 5:garments();
       calc();
       break;
default:cout<<"SORRY!!!INVALID SELECTION"<<endl;
}

cout<<"Want another categorie(y/n)"<<endl;
cin>>choice;

}while(choice=='y'||choice=='Y');
/* CALCULATION OF TOTAL PRICE & DISCOUNT */
o.o1=gh[0]+gh[1]+gh[2]+gh[3]+gh[4];
total=o.o1;
cout<<"Total expenditure of your shopping is RS."<<total<<endl;
if(o.o1<=10000)
{
dis=0.05*o.o1;
cout<<"You will get a discount of 5% i.e"<<dis<<endl;
}
if(o.o1>10000&&o.o1<=50000)
{
dis=0.1*o.o1;
cout<<"You will get a discount of 10% i.e"<<dis<<endl;
}
if(o.o1>50000&&o.o1<=100000)
{
dis=0.15*o.o1;
cout<<"You will get a discount of 15% i.e"<<dis<<endl;
}
if(o.o1>100000)
{
dis=0.2*o.o1;
cout<<"You will get a discount 20% i.e"<<dis<<endl;
}
o.o1=o.o1-dis;

cout<<"Now you have to pay"<<endl;
cout<<"RS."<<o.o1<<"/-only"<<endl;

getch();
clrscr();
do
{
cout<<"Mode of payment"<<endl;

cout<<"1.Cash\n";
cout<<"2.Check\n";
cout<<"3.Credit card\n";
cout<<"4.Online payment\n";

cin>>m;
}while(m<1||m>4);

if(m==2||m==4)
{
cout<<"Please enter your account no."<<endl;
cin>>u1;

if(m==4)
{
cout<<"Payed...."<<endl;
cout<<"***THANK YOU***"<<endl;
}
}
getch();
clrscr();

ofstream file("newfile.txt",ios::app);//OPENING TEXT FILE IN APP MODE

/* TO SHOW THE RECEIPT */

cout<<"\t**************************************************************\n";

cout<<"\t-----------------------------RECEIPT--------------------------\n";

cout<<"                  \t\t  BIG  BAZAAR               "<<endl;
cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";

cout<<"CODE  CATEGORIE                                PRICE\n\n";
if(a1==1)
cout<<"  1.  Stationary                        RS."<<gh[0]<<"\n\n";
if(a2==2)
cout<<"  2.  Fast food                         RS."<<gh[1]<<"\n\n";
if(a3==3)
cout<<"  3.  Electronics                       RS."<<gh[2]<<"\n\n";
if(a4==4)
cout<<"  4.  Furniture                         RS."<<gh[3]<<"\n\n";
if(a5==5)
cout<<"  5.  Garments                          RS."<<gh[4]<<"\n\n";
cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";

cout<<"  TOTAL  PRICE -                        RS."<<total<<"/-only\n\n";
cout<<"  DISCOUNT -                            RS."<<dis<<"/-only\n\n";
cout<<"  TO  PAY -                             RS."<<o.o1<<"/-only\n\n";
cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
cout<<"Mode of Payment -"<<endl;
if(m==1)
cout<<"Cash\n";
if(m==2)
cout<<"Check\n";
if     (m==3)
cout<<"Credit card\n";
if(m==4)
cout<<"Online payment\n";

randomize();
dno=random(10000);

cout<<"Delievery No.-"<<dno<<endl;
file<<"Delievery No._"<<dno;
file<<"Price Amount-"<<o.o1;

file.close();// CLOSING THE OPENED FILE

getch();

}

/* TO SHOW PREVIOUS RECORD */

else if(o.u==2)
{
clrscr();
char buff;
ifstream fin("newfile.txt",ios::in);
while(!fin.eof())
{
fin.get(buff);
cout<<buff;
}
fin.close();
}

/* TO SHOW EXCHANGE OFFERS */

else if(o.u==3)
{
clrscr();
exchange();

cout<<"How many items you want to purchase\n";
cin>>hj;

for(int i=0;i<=hj;i++)
{
cout<<"Please enter the code of the item{"<<i<<"] you want to purchase\n";
cin>>er;

if((er<1)&&(er>5))
{
cout<<"WRONG SELECTION!!!!!!!!!!"<<endl;
}

cout<<"What quantity of this item["<<i<<"] you want to purchase\n";
cin>>fg;
switch(er)
{
case 1:zx+=p1*fg;
       break;
case 2:zx+=p2*fg;
       break;
case 3:zx+=p3*fg;
       break;
case 4:zx+=p4*fg;
       break;
case 5:zx+=p5*fg;
       break;
default:cout<<"SORRY!!!INVALID SELECTION"<<endl;
}
}
cout<<"You have to pay"<<endl;
cout<<"RS."<<zx<<"/-only"<<endl;
}

/* TO SHOW DISCOUNT OFFERS */

else if(o.u==4)
{
clrscr();
discount();

cout<<"How many items you want to purchase\n";
cin>>hj;

for(int i=0;i<=hj;i++)
{

cout<<"Please enter the code of the item["<<i<<"] you want to purchase|n";
cin>>er;

if((er<1)&&(er>5))
{
cout<<"WRONG SELECTION!!!!!!!!!!!!"<<endl;
}

cout<<"What quantity of this item["<<i<<"] you want to purchase\n";
cin>>fg;
switch(er)
{
case 1:tc+=p1*fg;
       break;
case 2:tc+=p2*fg;
       break;
case 3:tc+=p3*fg;
       break;
case 4:tc+=p4*fg;
       break;
case 5:tc+=p5*fg;
       break;
default:cout<<"SORRY!!!INVALID SELECTION"<<endl;
}
}
cout<<"You have to pay"<<endl;
cout<<"RS."<<tc<<"/-only"<<endl;
}

/* TOSHOW AVAILABLE PRODUCTS */

else if(o.u==5)
{
do{
clrscr();

/* TO DISPLAY MAIN MENU */
menu();
clrscr();

/* TO DISPLAY PRODUCTS FOR SELECTED CATEGORIES */

switch(ch)
{
case 1:o.stationary();
       break;
case 2:o.fastfood();
       break;
case 3:o.electronics();
       break;
case 4:o.furniture();
       break;
case 5:garments();
       break;
default:cout<<"SORRY!!!INVALID SELECTION"<<endl;
}
cout<<"Want another categorie(y/n)"<<endl;
cin>>choice;
}while(choice=='y'||choice=='Y');

}
/* TO EXIT */
else if(o.u==6)
{
clrscr();

cout<<"*T*H*A*N*K*******Y*O*U*\n\n\n";

cout<<"*V*I*S*I*T*******A*G*A*I*N*"<<endl;
getch();
exit(0);
}
if(o.u==1)
{
char ch3, ch4;
int id;
cout<<endl<<endl;
do{
cout<<"\n Want to add new customer(A) or Update Old record (O)";
cin>>ch3;
if(ch3=='a'||ch3=='A')
{
	custadd(tc,dno);
}
else if(ch3=='o'||ch3=='O')
{
	cout<<"\n Enter Customer ID";
	cin>>id;
}
else
	cout<<"\n\n  Invalid Option";
cout<<"\n\nDo you want to add again ";
cin>>ch4;
}while(ch4=='y'||ch=='Y');
}
cout<<"Press 1  to continue..."<<endl;
cin>>r;

}while(r==1);
clrscr();

cout<<"*T*H*A*N*K*******Y*O*U*\n\n\n";

cout<<"*V*I*S*I*T*******A*G*A*I*N*"<<endl;
getch();
}// PROGRAM COMPLETED
