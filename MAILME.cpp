
	#include<fstream.h>        //For Files, Input and Output
	#include<conio.h>          //For Clear Screen
	#include<stdio.h>          //For Input and Output of Strings
	#include<string.h>         //For Manipulting Strings
	#include<process.h>        //For exit Function
	#include<graphics.h>       //For Graphics
	#include<ctype.h>	   //For isalpha, toalpha, toupper Functions
	#include<dos.h>            //For delay Function
	#include<time.h>	   //For Current System Time
	#include<stdlib.h>
	class mail
	{
	 private:

	 char username[20];
	 char password[20];
	 char name[20];
	 int  age;
	 char id[30];
	 char gender;

	 public:

	 void nwlogin();
	 int check(char user[20]);
	 void login();
	 void nwprofile();
	 void prof(mail temp);
	 void menu(mail temp);
	 void nwmail(mail temp);
	 void inbox(mail temp);
	 }t,s,temp1,temp;

	 struct msg
	 {
	    char rcnm[10];
	    char rcmsg[30];

	  }ms,mr;

	 int fl=0;

	 void loading()
	 {
	   int gd=EGA,gm=EGAHI;
	   initgraph(&gd,&gm,"..//bgi ");
	   cleardevice();
	   setbkcolor(0);
	   setcolor(15);
	   settextstyle(9,0,5);
	   outtextxy(100,200,"Loading");
	   int o=0;
	   for(int n=0;n<10;n++)
	    {
	      outtextxy(380+o,200,".");
	      o+=20;
	      delay(300);
	     }
	   closegraph();

	  }



	 void mail::prof(mail temp)
	  {
	    int gd=EGA,gm=EGAHI;
	    initgraph(&gd,&gm,"..//bgi ");
	    cleardevice();
	    setbkcolor(BLUE);

	    ifstream ff;
	    ff.open("details",ios::binary);
	    while(!ff.eof())
	     {
		 ff.read((char*)&s,sizeof(s));
		 if(strcmp(temp.username,s.username)==0)
		 {

		  cout<<'\n'<<"\t\t";
		  cout<<"\t\t Profile";
		  cout<<'\n'<<"\n\n\t\tName        : ";
		  puts(temp.name);
		  cout<<'\n'<<"\n\n\t\tMaiLmE  ID  : ";
		  puts(temp.username);
		  cout<<'\n'<<"\n\t\tGender      : ";
		  cout<<temp.gender;
		  cout<<'\n'<<"\n\n\t\tAge         : ";
		  cout<<temp.age;
		  cout<<'\n'<<"\n\n\t\tEmail ID    : ";
		  puts(temp.id);
		  getch();
		  closegraph();

		  menu(temp);
		  break;
		 }

	      }
	     ff.close();


	    }


	void mail::inbox(mail temp)
	{
	  clrscr();

	  int n=0,i=0,count=1;
	  cout<<'\n'<<"\n\t\t\t.....INBOX.....\n";
	  ifstream fm;

	  fm.open(temp.username,ios::binary);
	  if(fm)
	  {

	       while(fm.read((char*)&mr,sizeof(mr)))
	       {
		 cout<<'\n';
		 cout<<'\n'<<count<<".";
		 cout<<"\tFrom:    ";
		 puts(mr.rcnm);
		 cout<<'\n'<<"\tMessage:";
		 for(i=0;mr.rcmsg[i]!='\0';i++)
		 {
		      if(i==n)
		       {
			  cout<<"\n\t\t";
			  n=i+10;
			}

		      else if(mr.rcmsg[i]==1)
		      break;

		      cout<<mr.rcmsg[i];
		    }
		 count++;
		}

	    }
	   else
	   cout<<'\n'<<"  \n\t No MESSAGES   ";

	  fm.close();

	  getch();
	  menu(temp);
	}


	void mail::nwmail(mail temp)
	{
	  ifstream fu;
	  ofstream fr;
	  char ch;
	 a:

	  int flag =0;
	  clrscr();
	  cout<<'\n'<<"\n\t\t.....New Mail......\n";
	  cout<<'\n'<<"\n\tTo: ";
	  cin>>temp1.username; //receiver ID

	  fu.open("details",ios::binary);
	    while(!fu.eof())
	     {
		 fu.read((char*)&s,sizeof(s));
		 if(strcmp(temp1.username,s.username)==0)
		  {
		     // user exists
		      flag=1;
		      break;
			 }
		   }
	     fu.close();

	  if(flag==0)
	  {
	    cout<<"\n\n\t Sorry, User does not exist";
	    cout<<"\n\t Try again..?(y/n) :  ";
	    cin>>ch;
	    if(ch=='y')
	    goto a;
	    else
	    menu(temp);

	  }
	  else if(flag==1)
	  {

	    int i=0;
	    char ch;
	    cout<<"\n\tMESSAGE: ";
	    cout<<"\n\t... Press 1 and Enter to send...\n\t";
	    fr.open(temp1.username,ios::app);//reciever file
	    strcpy(ms.rcnm,temp.name);//sender name

	    ms.rcmsg[30]=NULL;
	    do
	    {
	      cin>>ms.rcmsg[i];
	      ch=ms.rcmsg[i];

	       if (ch==1||ch=='1')
	       {
		 ms.rcmsg[i]='\0';
		 break;
		}

	      i++;

	     }while(ch!=1);

	     fr.write((char*)&ms,sizeof(ms));

	     delay(100);


	     fr.close();
	     cout<<"\n\n\t\t MAIL SENT \n\n";
	     getch();
	     menu(temp);

	      }

	 }

	void logout()
	{
	  int gd=EGA,gm=EGAHI;
	  initgraph(&gd,&gm,"..//bgi ");
	  cleardevice();
	  setbkcolor(BLUE);
	  cout<<'\n'<<"\n\n\t\t....You Have Successfully LoggeD OuT....";
	  cout<<'\n'<<"\n\n\n\n\t\t....ThAnK You For UsinG...  ";

	  setcolor(WHITE);
	  settextstyle(7,HORIZ_DIR,6);
	  outtextxy (180,190,"MaiL mE");

	  delay(1000);
	  fl=1;

	}

	void mail::menu(mail temp)
	{
	 char ch;
	 int choice;

	 z:
	  clrscr();

	  cout<<'\n'<<"\n\n\t..Welcome..";
	  puts(temp.name);

	  cout<<'\n'<<"\t\t\t......Menu......";
	  cout<<'\n'<<"\n\t\t1======>...View ur Profile...";
	  cout<<'\n'<<"\n\t\t2======>....Check ur Mail....";
	  cout<<'\n'<<"\n\t\t3======>......Send mail......";
	  cout<<'\n'<<"\n\t\t4======>........Logout.......";
	  cout<<'\n'<<"\n\t\tEnter ur Choice: ";

	  cin>>ch;

	  switch(ch)
		{	case '1':choice=1;break;
			case '2':choice=2;break;
			case '3':choice=3;break;
			case '4':choice=4;break;

		}

	   switch(choice)
	      {
		 case 1:
			{
			  prof(temp);
			  break;
				}
		 case 2:
			{
			  inbox(temp);
			  break;
				}
		 case 3:
			{
			  nwmail(temp);
			  break;
				}
		 case 4:
			{
			  logout();
			  break;
				}
		 default:
			 {
			 delay(100);
			 cout<<'\n'<<"\n\t\t...... Wrong choice....";
			 ch=0;

			 getch();
			 goto z;

			  }

		  }

	   }



	 int mail::check(char user[20])
	 {
	   mail s;
	   int flag=0;
	   ifstream fin;
	   fin.open("details",ios::binary);
	   while(!fin.eof())
	   {
	       fin.read((char*)&s,sizeof(s));
	       if(strcmp(s.username,user)==0)
	       {
		flag=1;
		break;
	       }

	    }
	   fin.close();
	   if(flag==1)
	    {
	     cout<<"\n\n\n\n\n\t\t";
	     cout<<".....Username unavailable....Try another...";
	     delay(1000);
	     return 1;
	    }
	   else
	    {   cout<<"\n\n\n\n\t\t\t";
		cout<<".....Username available..."<<'\n';
		getch();
		return 2;
	      }
	  }

	 void mail::nwlogin()
	 {  int a;
	  b: clrscr();

	    cout<<"\n\n\n\n\n\t\t\t";
	    cout<<"Enter The Username: ";

	    gets(username);

	    a=check(username);

	    if(a==1)
	    goto b;

	    else if(a==2)
	    cout<<"\n\n\n\n\n\t\t\t";
	    cout<<"Enter The Password: ";
	    gets(password);

	    delay (100);
	    clrscr();
	    cout<<"\n\n\n\n\n\t\t";
	    cout<<"You have successfully created your ID ";
	    cout<<"\n\n\t\t\t      on  \n ";

	    cout<<"\n\t\t\t   MAiL Me  \n ";

	    delay(1000);
	    }

	 void mail::nwprofile()
	  {
	   cout<<'\n'<<"\n\n\t\t\tName        : ";
	   gets(name);
	   cout<<'\n'<<"\n\n\t\t\tGender(M/F) : ";
	   cin>>gender;
	   cout<<'\n'<<"\n\n\t\t\tAge         : ";
	   cin>>age;
	   cout<<'\n'<<"\n\n\t\t\tEmail ID    : ";
	   gets(id);

	    }

	 void nw()
	  {
	    ofstream f;
	    int i;
	    f.open("details",ios::binary|ios::ate);

	    t.nwlogin();
	    clrscr();
	    cout<<'\n'<<"\n\t\t\t....Make ur profile.....";
	    getch();
	    t.nwprofile();

	    f.write((char*)&t,sizeof(t));
	    f.close();
	    loading();
	    t.menu(t);

	  }

	  void mail::login()
	  {
	   char ch;
	   a:
	    clrscr();
	    int flag=0;
	    ifstream fi;
	    cout<<"\n\n\n\n\n\t\t\t";
	    cout<<"Enter The Username: ";
	    gets(username);
	    cout<<"\n\n\n\n\n\t\t\t";
	    cout<<"Enter The Password: ";
	    gets(password);

	    fi.open("details",ios::binary);
	    if(fi)
	    {
	     while(!fi.eof())
	      {
		 fi.read((char*)&temp,sizeof(temp));
		 if(strcmp(username,temp.username)==0)
		  {
		     if(strcmp(password,temp.password)==0)
			{
			  flag =1;

			  break;
			 }
		      }
		  }
	      }


	      if(flag==0)
	       {
		 clrscr();
		 cout<<"\n\n\n\n\t\t\t";
		 cout<<"Wrong username or password \n";
		 getch();
		 cout<<"\n\t\t\t";
		 cout<<"??....Try again....??(y/n) ";
		 cout<<"\n\t\t\t";
		 cout<<"Choice:";
		 cin>>ch;
		 if(ch=='y'||ch=='Y')
		 goto a;
		 else
		 ::fl=1;
	       }

	       else if(flag==1)
	       {

		 clrscr();
		 delay(100);
		 cout<<"\n\t\t";
		 cout<<"..You have successfully Logged in.. \n";
		 delay(1000);
		 cout<<'\n'<<"\n\n\t\t..Proceeding to Menu.. \n";
		 delay(1000);
		 loading();
		 menu(temp);


		}
	     fi.close();

	    }

	 void head()
	  {

	      int gdriver = DETECT, gmode,i;
	      initgraph(&gdriver, &gmode, "..\\bgi");


	      setcolor(WHITE);
	      settextstyle(7, HORIZ_DIR, 8);
	      setusercharsize(2, 1, 2, 1);

	      outtextxy(150,150," MaiL mE ");
	      for(i=0;i<=11;i++)
	      {
	       setbkcolor(i);
	       delay(200);
	      }
	     setbkcolor(0);
	     for(int p=0;p<2000;p++)
	     {
	      putpixel(random(640),random(480),random(15)+1);
	      delay(1);
		}

	     delay(1500);

	}//End of head()


	void tail()
	{
	closegraph();
	clrscr();
	int h=0;

	int gdriver = DETECT, gmode;
	initgraph(&gdriver, &gmode, "..\\bgi");

	delay(1000);
	setcolor(WHITE);
	rectangle(0,0,getmaxx(),getmaxy());
	settextstyle(5, HORIZ_DIR,6);
	outtextxy(165,50," Powered by ");

	settextstyle(7, HORIZ_DIR, 4);
	outtextxy(172,150,"   B.Sudershan");
	outtextxy(275,200,"XII F");
	outtextxy(100,300,"SBOA SCHOOL & Jr. COLLEGE ");
	outtextxy(200,350,"2011 - 2012");


	delay(500);

	for(int b=0;b<15;b++)
	{
	   setbkcolor(b);
	   delay(50);
	}
	setbkcolor(RED);
	for(int p=0;p<2000;p++)
	{
	putpixel(random(640),random(480),random(15)+1);
	delay(1);
	}

	a:
	setcolor(WHITE);
	settextstyle(5, HORIZ_DIR, 6);
	outtextxy(165,50," Powered by ");

	settextstyle(7, HORIZ_DIR, 4);
	outtextxy(172,150,"   B.Sudershan");
	outtextxy(275,200,"XII F");
	outtextxy(100,300,"SBOA SCHOOL & Jr. COLLEGE ");
	outtextxy(200,350,"2011 - 2012");

	while(h<3)
	{
		delay(500);
		setcolor(LIGHTBLUE);
		settextstyle(5,HORIZ_DIR,6);

	outtextxy(165,50," Powered by ");
	settextstyle(7, HORIZ_DIR, 4);
	outtextxy(172,150,"   B.Sudershan");
	outtextxy(275,200,"XII F");
	outtextxy(100,300,"SBOA SCHOOL & Jr. COLLEGE ");
	outtextxy(200,350,"2011 - 2012");


		h++;
		delay(500);
		goto a;

	}
	closegraph();
	getch();

	} //tail



	  void main()
	  {
	   char choice;

	   head();

	   x:

		cleardevice();
		setbkcolor(BLUE);
		setcolor(WHITE);
		settextstyle(5,HORIZ_DIR,7);
		outtextxy (180,0,"MaiL mE");


		gotoxy (26,10);cout<<"N   ==============>> SiGn uP";
		gotoxy (26,14);cout<<"U   ==============>> SiGn In";
		gotoxy (26,18);cout<<"E   ==============>> ExIt   ";
		cout<<"\n\n\n\t\t\t";
		cout<<"Enter your choice :";


		cin>>choice;

		closegraph();

		if(choice=='n'||choice=='N')
		nw();
		else if(choice=='u'||choice=='U')
		t.login();
		else if(choice=='e'||choice=='E')
		{
		  tail();

		  exit(0);
		  }
		else
		{
		  cout<<"\n\t\t\t\t";
		  cout<<"Wrong choice ";
		  delay(1000);
		  goto x;
		 }


		if(fl==1)
		{
		 fl=0;
		 goto x;
		 }


	   }







