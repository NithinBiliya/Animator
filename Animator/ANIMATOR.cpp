//		ANIMATOR


#include<string.h>
#include<fstream.h>
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#include<process.h>
#include<math.h>
#include"mouses.cpp"

struct animation
{ char obj[6];
  int x,y,c; }object;
struct coordinates
{ int x,y; }coor;

void video(char [30]);
void animationvideo(char [30]);
void pts(int,int);

void entername(char name[30])
{ settextstyle(2,0,4);
  setcolor(RED);
  setfillstyle(SOLID_FILL,BLACK);
  bar(200,150,450,250);
  char temp[3];
  temp[1]='\0';
  outtextxy(250,200,"Filename : ");
  for(int k=0;k<30;k++)
  { name[k]=getch();
    temp[0]=name[k];
    if(name[k]=='\r')
    { name[k]='\0';
      break; }
    outtextxy(350+(k*10),200,temp); }}


void clear(char name[30])
{ hidemouseptr();
 entername(name);
 cleardevice();
 setcolor(WHITE);
 outtextxy(8,5,"TOOLS");
 line(55,0,55,getmaxy());
 rectangle(5,40,48,60);
 outtextxy(10,45,"New");
 rectangle(5,65,48,85);
 outtextxy(10,70,"Pencil");
 rectangle(5,90,48,110);
 outtextxy(10,95,"Line");
 rectangle(5,115,48,135);
 outtextxy(10,120,"Eraser");
 rectangle(5,140,48,160);
 outtextxy(10,145,"Rect");
 rectangle(5,165,48,185);
 outtextxy(10,170,"Triang");
 rectangle(5,190,48,210);
 outtextxy(10,195,"Ellips");
 rectangle(5,215,48,235);
 outtextxy(10,220,"Fill");
 rectangle(5,240,48,260);
 outtextxy(10,245,"Save");
 rectangle(5,265,48,285);
 outtextxy(10,270,"Open");
 rectangle(5,290,48,310);
 outtextxy(10,295,"Exit");
 rectangle(35,315,50,330);
 outtextxy(40,317,"U");
 rectangle(35,335,50,350);
 outtextxy(40,337,"C");
 rectangle(35,355,50,370);
 outtextxy(40,357,"S");
 rectangle(35,375,50,390);
 outtextxy(40,377,"R");
 rectangle(35,395,50,410);
 outtextxy(40,397,"X");
 rectangle(35,415,50,430);
 outtextxy(40,417,"O");
 rectangle(35,440,50,455);
 outtextxy(40,442,"s");
 rectangle(35,460,50,475);
 outtextxy(40,462,"o");
 rectangle(60,getmaxy()-20,110,getmaxy()-2);
 outtextxy(64,getmaxy()-17,"Text:");
 outtextxy(getmaxx()/2,getmaxy()-20,name); }

void show(char name[30])
{ hidemouseptr();
 settextstyle(2,0,4);
 setcolor(WHITE);
 outtextxy(8,5,"TOOLS");
 line(55,0,55,getmaxy());
 rectangle(5,40,48,60);
 outtextxy(10,45,"New");
 rectangle(5,65,48,85);
 outtextxy(10,70,"Pencil");
 rectangle(5,90,48,110);
 outtextxy(10,95,"Line");
 rectangle(5,115,48,135);
 outtextxy(10,120,"Eraser");
 rectangle(5,140,48,160);
 outtextxy(10,145,"Rect");
 rectangle(5,165,48,185);
 outtextxy(10,170,"Triang");
 rectangle(5,190,48,210);
 outtextxy(10,195,"Ellips");
 rectangle(5,215,48,235);
 outtextxy(10,220,"Fill");
 rectangle(5,240,48,260);
 outtextxy(10,245,"Save");
 rectangle(5,265,48,285);
 outtextxy(10,270,"Open");
 rectangle(5,290,48,310);
 outtextxy(10,295,"Exit");
 rectangle(35,315,50,330);
 outtextxy(40,317,"U");
 rectangle(35,335,50,350);
 outtextxy(40,337,"C");
 rectangle(35,355,50,370);
 outtextxy(40,357,"S");
 rectangle(35,375,50,390);
 outtextxy(40,377,"R");
 rectangle(35,395,50,410);
 outtextxy(40,397,"X");
 rectangle(35,415,50,430);
 outtextxy(40,417,"O");
 rectangle(35,440,50,455);
 outtextxy(40,442,"s");
 rectangle(35,460,50,475);
 outtextxy(40,462,"o");
 rectangle(60,getmaxy()-20,110,getmaxy()-2);
 outtextxy(64,getmaxy()-17,"Text:");
 outtextxy(getmaxx()/2,getmaxy()-20,name);   }

void main()
{
 int gdriver = DETECT, gmode;
 initgraph(&gdriver, &gmode, "\\tc\\bgi");

 int Mstatus = initmouse();
 int button,x,y,x3,y3,flag=0,flag1=0;
 float x1,y1,x2,y2;
 char c='\0',name[30],ani[30],character;
 if(Mstatus == 0 )
  outtextxy(50,50, "Mouse Support Not Available");
 video("NKB1");
 video("NKB2");
 video("NKB3");
 video("NKB4");
 video("NKB5");
 video("NKB6");
 video("NKB7");
 cleardevice();
 animationvideo("ani1");
 animationvideo("ani2");
 animationvideo("ani3");
 cleardevice();

 int m,n;
 int i=0,l=15,temp;
 float p,q;
 char text[3],ch='\0';
 text[3]='\0';
 char password[30];
 settextstyle(2,0,4);
 outtextxy(250,200,"Password :  ");
 for(int k=0;k<30;k++)
 { password[k]=getch();
   if(password[k]=='\r')
   { password[k]='\0';
     break; }
   outtextxy(350+(k*10),200,"*"); }
 if(strcmp(password,"hariputtar"))
 { outtextxy(250,250,"\n\nWrong password !!");
   getch();
   exit(0); }
 clear(name);

 while(1)
{ showmouseptr();
  getmousepos(&button,&x,&y);
  pts(x,y);
  if(button==0)
   flag=0;
  if(button==1)
  {   setcolor(WHITE);
      for(int j=0;j<16;j++)
      { setfillstyle(SOLID_FILL,j);
	bar(5,315+(j*10),15,315+((j+1)*10)); }
      rectangle(5,315,15,475);
	if(x>=5 && x<=15 && y>=315 && y<=475)
	{ if(y>315&&y<325) i=0;
	  else if(y>325&&y<335) i=1;
	  else if(y>335&&y<345) i=2;
	  else if(y>345&&y<355) i=3;
	  else if(y>355&&y<365) i=4;
	  else if(y>365&&y<375) i=5;
	  else if(y>375&&y<385) i=6;
	  else if(y>385&&y<395) i=7;
	  else if(y>395&&y<405) i=8;
	  else if(y>405&&y<415) i=9;
	  else if(y>415&&y<425) i=10;
	  else if(y>425&&y<435) i=11;
	  else if(y>435&&y<445) i=12;
	  else if(y>445&&y<455) i=13;
	  else if(y>455&&y<465) i=14;
	  else if(y>465&&y<475) i=15;  }
      for(j=0;j<16;j++)
      { setfillstyle(SOLID_FILL,j);
	bar(20,315+(j*10),30,315+((j+1)*10)); }
      rectangle(20,315,30,475);
	if(x>=20 && x<=30 && y>=315 && y<=475)
	{ if(y>315&&y<325) l=0;
	  else if(y>325&&y<335) l=1;
	  else if(y>335&&y<345) l=2;
	  else if(y>345&&y<355) l=3;
	  else if(y>355&&y<365) l=4;
	  else if(y>365&&y<375) l=5;
	  else if(y>375&&y<385) l=6;
	  else if(y>385&&y<395) l=7;
	  else if(y>395&&y<405) l=8;
	  else if(y>405&&y<415) l=9;
	  else if(y>415&&y<425) l=10;
	  else if(y>425&&y<435) l=11;
	  else if(y>435&&y<445) l=12;
	  else if(y>445&&y<455) l=13;
	  else if(y>455&&y<465) l=14;
	  else if(y>465&&y<475) l=15;  }
    if(x>5 && x<48 && y>40 && y<60)
     c='W';
    else if(x>5 && x<48 && y>65 && y<85)
    { c='P';
      delay(200); }
    else if(x>5 && x<48 && y>90 && y<110)
    { c='L';
      delay(200); }
    else if(x>5 && x<48 && y>115 && y<135)
    { c='E';
      delay(200); }
    else if(x>5 && x<48 && y>140 && y<160)
    { c='R';
      delay(200); }
    else if(x>5 && x<48 && y>165 && y<185)
    { c='T';
      delay(200); }
    else if(x>5 && x<48 && y>190 && y<210)
     c='C';
    else if(x>5 && x<48 && y>215 && y<235)
     c='F';
    else if(x>5 && x<48 && y>240 && y<260)
     c='S';
    else if(x>35 && x<50 && y>440 && y<455)
     c='s';
    else if(x>35 && x<50 && y>460 && y<475)
     c='o';
    else if(x>5 && x<48 && y>265 && y<285)
     c='O';
    else if(x>5 && x<48 && y>290 && y<310)
     c='X';
    else if(x>60 && x<110 && y>getmaxy()-20 && y<getmaxy()-2)
     c='t';
    if(x>35 && x<50 && y>315&& y<330)          //  Undo
    { hidemouseptr();
      setcolor(RED);
      rectangle(35,315,50,330);
      delay(200);
      setcolor(BLACK);
      if(c=='L')
       line(x1,y1,x2,y2);
      else if(c=='T')
      { line(x1,y1,x3,y3);
	line(x1,y1,x2,y2);
	line(x2,y2,x3,y3);  }
      else if(c=='R')
       rectangle(x1,y1,x2,y2);
      else if(c=='C')
       ellipse(x1+p/2,y1+q/2,0,360,p/2,q/2);
      c='N';  }
    else if(x>35 && x<50 && y>335 && y<350)   // Creating an object
    { hidemouseptr();
      show(name);
      setcolor(RED);
      rectangle(35,335,50,350);
      delay(200);
      if(c=='R')
      { strcpy(object.obj,"rect");
	object.x=p;
	object.y=q;
	object.c=i; }
      else if(c=='C')
      { strcpy(object.obj,"cir");
	object.x=p;
	object.y=q;
	object.c=i; }
      else if(c=='P')
      { strcpy(object.obj,"line");
	object.x=0;
	object.y=0;
	object.c=l; }
      else if(c=='L')
      { strcpy(object.obj,"line");
	object.x=0;
	object.y=0;
	object.c=l; }
      fstream file;
      file.open(name,ios::binary|ios::app);
      if(!file)
      { outtextxy(250,150,"Unable to open");
	getch();
	exit(0); }
      file.write((char*)&object,sizeof(object));
      file.close();
      ch='A'; }
    else if(x>35 && x<50 && y>395 && y<410)  // Deleting the file
    { hidemouseptr();
      show(name);
      setcolor(RED);
      rectangle(35,395,50,410);
      delay(200);
      remove(name);
      outtextxy(250,250,"FILE DELETED");
      c='N'; }
    else if(x>35 && x<50 && y>355 && y<370)  // Saving the animation file
    { hidemouseptr();
      show(name);
      setcolor(RED);
      rectangle(35,355,50,370);
      delay(200);
      ch='\0';
      fstream file;
      file.open(name,ios::binary|ios::app);
      coor.x=-20; coor.y=-20;
      if(!file)
      { outtextxy(250,150,"Unable to open");
	getch();
	exit(0); }
      file.write((char*)&coor,sizeof(coor));
      file.close();
      c='U';  }
    else if(x>35 && x<50 && y>375 && y<390 && c=='U') // Running ani file
    { hidemouseptr();
      show(name);
      setcolor(RED);
      rectangle(35,375,50,390);
      delay(200);
      cleardevice();
      int count=0;
      fstream file;
      file.open(name,ios::binary|ios::in);
      if(!file)
      { outtextxy(250,150,"Unable to open");
	getch();
	exit(0); }
      setcolor(WHITE);
      file.read((char*)&object,sizeof(object));
      while(!file.eof())
      { file.read((char*)&coor,sizeof(coor));
	if(coor.x==-240 && coor.y==-240)
	{ file.read((char*)&coor,sizeof(coor));
	  m=coor.x;  n=coor.y; }
	if(coor.x==-20 && coor.y==-20)
	{ file.read((char*)&object,sizeof(object));
	  file.read((char*)&coor,sizeof(coor));
	  count=0;  }
	if(!strcmp(object.obj,"rect"))
	{ setcolor(WHITE);
	  setfillstyle(SOLID_FILL,object.c);
	  rectangle(coor.x,coor.y,coor.x+object.x,coor.y+object.y);
	  floodfill(coor.x+(object.x/2),coor.y+(object.y/2),WHITE);
	  delay(10);
	  setfillstyle(SOLID_FILL,BLACK);
	  floodfill(coor.x+(object.x/2),coor.y+(object.y/2),WHITE);
	  setcolor(BLACK);
	  rectangle(coor.x,coor.y,coor.x+object.x,coor.y+object.y);  }
	else if(!strcmp(object.obj,"cir"))
	{ setcolor(WHITE);
	  setfillstyle(SOLID_FILL,object.c);
	  ellipse(coor.x,coor.y,0,360,(object.x/2),(object.y/2));
	  floodfill(coor.x,coor.y,WHITE);
	  delay(10);
	  setfillstyle(SOLID_FILL,BLACK);
	  floodfill(coor.x,coor.y,WHITE);
	  setcolor(BLACK);
	  ellipse(coor.x,coor.y,0,360,(object.x/2),(object.y/2)); }
	else if(!strcmp(object.obj,"line"))
	{ setcolor(object.c);
	  if(count==0)
	  { line(coor.x,coor.y,coor.x,coor.y);
	    count++; }
	  else
	   line(m,n,coor.x,coor.y);
	  delay(10);
	  m=coor.x;  n=coor.y;  }}
      file.close();
      show(name);  }
    else if(x>35 && x<50 && y>415 && y<430)  // Open ani file
    { hidemouseptr();
      show(name);
      setcolor(RED);
      rectangle(35,415,50,430);
      entername(name);
      hidemouseptr();
      cleardevice();
      animationvideo(name);
      show(name);  }
    else if(c=='t')			     // entering text
    { hidemouseptr();
      show(name);
      setcolor(RED);
      rectangle(60,getmaxy()-20,110,getmaxy()-2);
      int tt,size;
      char temp[3];
      setfillstyle(SOLID_FILL,BLACK);
      bar(61,getmaxy()-19,109,getmaxy()-3);
      temp[1]='\0';
      for(int k=0;k<3;k++)
      { temp[k]=getch();
	if(temp[k]=='\r')
	{ temp[k]='\0';
	  break; }
	outtextxy(64,462,temp); }
      tt=atoi(temp);
      temp[1]='\0';
      for(k=0;k<3;k++)
      { temp[k]=getch();
	if(temp[k]=='\r')
	{ temp[k]='\0';
	  break; }
	outtextxy(92,462,temp); }
      size=atoi(temp);
      button=0;
      while(!button)
      { showmouseptr();
	getmousepos(&button,&x,&y);
	pts(x,y); }
      hidemouseptr();
      settextstyle(tt,0,size);
      setcolor(l);
      char text[50];
      for(k=0;k<50;k++)
      { text[k]=getch();
	if(text[k]=='\r')
	{ text[k]='\0';
	  break; }
	text[k+1]='\0';
	outtextxy(x,y,text); }
      setfillstyle(SOLID_FILL,BLACK);
      bar(61,getmaxy()-19,109,getmaxy()-3);
      show(name);
      settextstyle(1,0,1);
      c='\0'; }
    else if(c=='L' && ch=='A')  	       // Draw animation line
    { hidemouseptr();
      show(name);
      setcolor(RED);
      rectangle(5,90,48,110);
      int count=0;
      while(count<2 && !(x>=0&&x<=55&&y>=0&&y<=479))
      { showmouseptr();
	getmousepos(&button,&x,&y);
	pts(x,y);
	if(button==1 && count==1)
	{ hidemouseptr();
	  setcolor(l);
	  x2=x; y2=y;
	  line(x1,y1,x,y);
	  delay(200);
	  count++; }
	else if(button==1 && count==0)
	{ x1=x; y1=y;
	  delay(200);
	  count++;   }}
      if(ch=='A')
    { fstream file;
      file.open(name,ios::binary|ios::app);
      if(!file)
      { outtextxy(250,150,"Unable to open");
	getch();
	exit(0); }
      long double m;
      if(x2-x1==0)
       m=(y2-y1)/0.001;
      else
       m=(y2-y1)/(x2-x1);
      coor.x=x1;  coor.y=y1;
      file.write((char*)&coor,sizeof(coor));
      while(x1!=x2)
      { if(x1>x2)
	{ coor.x=--x1;
	  coor.y=y2-m*(x2-x1); }
	else
	{ coor.x=++x1;
	  coor.y=y2-m*(x2-x1); }
	file.write((char*)&coor,sizeof(coor)); }
      file.close();  }}
    else if(c=='L' && ch!='A')  	       // Draw simple line
    { hidemouseptr();
      show(name);
      setcolor(RED);
      rectangle(5,90,48,110);
      setcolor(WHITE);
      int count=0;
      while(count<2 && !(x>=0&&x<=55&&y>=0&&y<=479))
      { showmouseptr();
	getmousepos(&button,&x,&y);
	pts(x,y);
	if(button==1 && count==1)
	{ hidemouseptr();
	  delay(200);
	  setcolor(l);
	  x2=x; y2=y;
	  line(x1,y1,x2,y2);
	  count++; }
	else if(button==1 && count==0)
	{ x1=x; y1=y;
	  delay(200);
	  count++;   }}}
    else if(c=='T')                          // Draw triangle
    { hidemouseptr();
      show(name);
      setcolor(RED);
      rectangle(5,165,48,185);
      setcolor(WHITE);
      int count=0;
      while(count<3 && !(x>=0&&x<=55&&y>=0&&y<=479))
      { showmouseptr();
	getmousepos(&button,&x,&y);
	pts(x,y);
	if(button==1 && count==2)
	{ hidemouseptr();
	  setcolor(l);
	  x3=x;  y3=y;
	  line(x1,y1,x,y);
	  line(x1,y1,x2,y2);
	  line(x2,y2,x,y);
	  delay(200);
	  count++; }
	else if(button==1 && count==1)
	{ x2=x; y2=y;
	  delay(200);
	  count++; }
	else if(button==1 && count==0)
	{ x1=x; y1=y;
	  delay(200);
	  count++;   }}}
    else if(c=='F')                               // Fill objects
    { hidemouseptr();
      show(name);
      setcolor(RED);
      rectangle(5,215,48,235);
      setcolor(WHITE);
      for(int j=0;j<16;j++)
      { setfillstyle(SOLID_FILL,j);
	bar(5,315+(j*10),15,315+((j+1)*10)); }
      rectangle(5,315,15,475);
	if(x>=0 && x<=55 && y>=0 && y<=479);
	else
	{ setfillstyle(SOLID_FILL,i);
	  floodfill(x,y,WHITE); }}
    else if(c=='X')                             // Exit
    { setcolor(RED);
      rectangle(5,290,48,310);
      hidemouseptr();
      cleardevice();
      video("THANKU");
      closegraph();
      exit(0);  }                            // New file
    else if(c=='W')
    { setcolor(RED);
      rectangle(5,40,48,60);
      clear(name);
      c='\0'; }
    else if(c=='P' || ch=='A')               // Pencil
    { hidemouseptr();
      show(name);
      character='\0';
      if(kbhit())
       character=getche();
      setcolor(RED);
      rectangle(5,65,48,85);
      if(ch=='A')
    { fstream file;
      file.open(name,ios::binary|ios::app);
      coor.x=x; coor.y=y;
      if(character!='\0')
      { coor.x=-240; coor.y=-240; }
      if(!file)
      { outtextxy(250,150,"Unable to open");
	getch();
	exit(0); }
      file.write((char*)&coor,sizeof(coor));
      file.close();  }
      setcolor(WHITE);
      showmouseptr();
      if(button == 1 && flag==0)
      { x1=x; y1=y;
	flag=1; }
      if(button == 1 && flag==1)
      { hidemouseptr();
	setcolor(l);
	line(x1,y1,x,y);
//	putpixel(x,y,WHITE);
	x1=x;  y1=y;  }}
    else if(c=='E')                         // Eraser
    { hidemouseptr();
      show(name);
      setcolor(RED);
      rectangle(5,115,48,135);
      setcolor(WHITE);
      showmouseptr();
      setfillstyle(SOLID_FILL,BLACK);
      hidemouseptr();
      bar(x-5,y-5,x+5,y+5); }
    else if(c=='R')                      // Rectangle
    { hidemouseptr();
      show(name);
      setcolor(RED);
      rectangle(5,140,48,160);
      setcolor(WHITE);
      int count=0;
      while(count<2 && !(x>=0&&x<=55&&y>=0&&y<=479))
      { showmouseptr();
	getmousepos(&button,&x,&y);
	pts(x,y);
	if(button==1 && count==1)
	{ hidemouseptr();
	  delay(200);
	  setcolor(l);
	  x2=x; y2=y;
	  rectangle(x1,y1,x2,y2);
	  p=x1-x;
	  if(x1<x);
	  else x1=x;
	  if(p<=0)
	   p*=-1;
	  q=y1-y;
	  if(y1<y);
	  else y1=y;
	  if(q<=0)
	   q*=-1;
	  count=2; }
	else if(button==1 && count==0)
	{ delay(200);
	  x1=x; y1=y;
	  count++;   }}}
    else if(c=='C')                               // Ellipse
    { hidemouseptr();
      show(name);
      setcolor(RED);
      rectangle(5,190,48,210);
      setcolor(WHITE);
      int count=0;
      while(count<2 && !(x>=0&&x<=55&&y>=0&&y<=479))
      { showmouseptr();
	getmousepos(&button,&x,&y);
	pts(x,y);
	if(button==1 && count==1)
	{ hidemouseptr();
	  p=x1-x;
	  if(x1<x);
	  else x1=x;
	  if(p<=0)
	   p*=-1;
	  q=y1-y;
	  if(y1<y);
	  else y1=y;
	  if(q<=0)
	   q*=-1;
	  setcolor(l);
	  ellipse(x1+p/2,y1+q/2,0,360,p/2,q/2);
	  setfillstyle(SOLID_FILL,i);
	  floodfill(x1+p/2,y1+q/2,WHITE);
	  delay(200);
	  count=2; }
/*	if(button==1 && count==1)
	{ hidemouseptr();
	  float n=(y1-y)*(y1-y)+(x1-x)*(x1-x);
	  float dist;
	  if(n>=0)
	   dist=sqrt(n);
	  else
	   dist=sqrt(-1*n);
	  circle(x1,y1,dist);
	  delay(200);
	  count=2; }*/
	else if(button==1 && count==0)
	{ x1=x; y1=y;
	  delay(200);
	  count++;   }}}
    else if(c=='s')                     //   Saving part of picture
    { hidemouseptr();
      show(name);
      setcolor(RED);
      rectangle(35,440,50,455);
      setcolor(WHITE);
      int count=0;
      button=0;
      delay(200);
      while(count<2)// && !(x>=0&&x<=55&&y>=0&&y<=479))
      { showmouseptr();
	getmousepos(&button,&x,&y);
	pts(x,y);
	if(button==1 && count==1)
	{ hidemouseptr();
	  delay(200);
	  setcolor(l);
	  x2=x; y2=y;
	  rectangle(x1,y1,x2,y2);
/*	  p=x1-x;
	  if(x1<x);
	  else x1=x;
	  if(p<=0)
	   p*=-1;
	  q=y1-y;
	  if(y1<y);
	  else y1=y;
	  if(q<=0)
	   q*=-1;*/
	  count=2; }
	else if(button==1 && count==0)
	{ delay(200);
	  x1=x; y1=y;
	  count++;   }}
      fstream file;
      file.open("temporary",ios::binary|ios::out);
      if(!file)
      { outtextxy(250,150,"Unable to open");
	getch();
	exit(0); }
      unsigned color;
      p=x2-x1;  q=y2-y1;
      file.write((char*)&p,sizeof(p));
      file.write((char*)&q,sizeof(q));
      for(int i=x1+1;i<x1+p;i++)
       for(int j=y1+1;j<y1+q;j++)
       { color=getpixel(i,j);
	 file.write((char*)&color,sizeof(color)); }
     file.close();
     char name1[30];
     entername(name1);
     rename("temporary",name1);
     setfillstyle(SOLID_FILL,BLACK);
     bar(200,150,450,250);
     outtextxy(250,200,"Save Complete");
     getch();
     c='\0';
     show(name); }
    else if(c=='o')                       //  Opening part of picture
    { hidemouseptr();
      show(name);
      setcolor(RED);
      rectangle(35,460,50,475);
      char name1[30];
      entername(name1);
      setcolor(WHITE);
      button=0;
      delay(200);
      while(!button)
      { showmouseptr();
	getmousepos(&button,&x,&y);
	pts(x,y); }
      fstream file;
      file.open(name1,ios::binary|ios::in);
      if(!file)
      { outtextxy(250,150,"Unable to open");
	getch();
	exit(0); }
      unsigned color;
      file.read((char*)&p,sizeof(p));
      file.read((char*)&q,sizeof(q));
      file.read((char*)&color,sizeof(color));
      for(i=0;i<p;i++)
       for(j=0;j<q;j++)
       { putpixel(x+i,y+j,color);
	 file.read((char*)&color,sizeof(color)); }
     file.close();
     c='\0';
     show(name); }
    else if(c=='S')                         //   Saving a picture
    { hidemouseptr();
      show(name);
      setcolor(RED);
      setfillstyle(SOLID_FILL,BLACK);
      bar(0,0,55,getmaxy());
      bar(0,getmaxy()-20,getmaxx(),getmaxy()+2);
      setcolor(WHITE);
      hidemouseptr();
      setfillstyle(SOLID_FILL,BLACK);
      bar(0,getmaxy()-20,getmaxx(),getmaxy());
      fstream file;
      file.open(name,ios::binary|ios::out);
      if(!file)
      { outtextxy(250,150,"Unable to open");
	getch();
	exit(0); }
      unsigned color;
      for(int i=0;i<getmaxx();i++)
       for(int j=0;j<getmaxy();j++)
       { color=getpixel(i,j);
	 file.write((char*)&color,sizeof(color)); }
      file.close();
     setfillstyle(SOLID_FILL,BLACK);
     bar(200,150,450,250);
     outtextxy(250,200,"Save Complete");
     getch();
     clear(name); }
    else if(c=='O')                             //  Opening a picture
    { hidemouseptr();
      setcolor(RED);
      setfillstyle(SOLID_FILL,BLACK);
      bar(200,150,450,250);
      char temp[3];
      temp[1]='\0';
      outtextxy(250,200,"Filename : ");
      for(int k=0;k<30;k++)
      { name[k]=getch();
	temp[0]=name[k];
	if(name[k]=='\r')
	{ name[k]='\0';
	  break; }
	outtextxy(350+(k*10),200,temp); }
      setfillstyle(SOLID_FILL,BLACK);
      bar(0,getmaxy()-5,getmaxx(),getmaxy()+2);
      fstream file;
      file.open(name,ios::binary|ios::in);
      if(!file)
      { outtextxy(250,150,"Unable to open");
	getch();
	exit(0); }
      unsigned color;
      file.read((char*)&color,sizeof(color));
      for(int i=0;i<getmaxx();i++)
       for(int j=0;j<getmaxy();j++)
       { putpixel(i,j,color);
	 file.read((char*)&color,sizeof(color)); }
      putpixel(i,j,color);
      file.close();
//     cin>>name;
     getch();
     show(name);
     outtextxy(getmaxx()/2,getmaxy()-20,name); }}}}

void pts(int x,int y)
{   int temp;
    char text[5];
    text[3]='\0';
    setfillstyle(SOLID_FILL,BLACK);
    settextstyle(2,0,4);
    bar(getmaxx()-50,getmaxy()-15,getmaxx(),getmaxy());
    temp=x;
    text[2]=(char)(temp%10)+48;
    temp/=10;
    text[1]=(char)(temp%10)+48;
    temp/=10;
    text[0]=(char)(temp%10)+48;
    if(x<10)
    { text[0]=(char)(x%10)+48;
      text[1]='\0';  }
    outtextxy(getmaxx()-48,getmaxy()-10,text);
    temp=y;
    text[2]=(char)(temp%10)+48;
    temp/=10;
    text[1]=(char)(temp%10)+48;
    temp/=10;
    text[0]=(char)(temp%10)+48;
    if(y<10)
    { text[0]=(char)(y%10)+48;
      text[1]='\0';  }
    outtextxy(getmaxx()-28,getmaxy()-12,",");
    outtextxy(getmaxx()-23,getmaxy()-10,text);  }

void video(char name[30])                //  for NKB pro
{     fstream file;
      file.open(name,ios::binary|ios::in);
      if(!file)
      { outtextxy(250,150,"Unable to open");
	getch();
	exit(0); }
      unsigned color;
      file.read((char*)&color,sizeof(color));
      for(int i=0;i<getmaxx();i++)
       for(int j=0;j<getmaxy();j++)
       { putpixel(i,j,color);
	 file.read((char*)&color,sizeof(color)); }
      putpixel(i,j,color);
      file.close();  }

void animationvideo(char name[30])               // opening ani files
{     int count=0,m,n;
      fstream file;
      file.open(name,ios::binary|ios::in);
      if(!file)
      { outtextxy(250,150,"Unable to open");
	getch();
	exit(0); }
      setcolor(WHITE);
      file.read((char*)&object,sizeof(object));
      while(!file.eof())
      { file.read((char*)&coor,sizeof(coor));
	if(coor.x==-240 && coor.y==-240)
	{ file.read((char*)&coor,sizeof(coor));
	  m=coor.x;  n=coor.y; }
	if(coor.x==-20 && coor.y==-20)
	{ file.read((char*)&object,sizeof(object));
	  file.read((char*)&coor,sizeof(coor));
	  count=0;  }
	if(!strcmp(object.obj,"rect"))
	{ setcolor(WHITE);
	  setfillstyle(SOLID_FILL,object.c);
	  rectangle(coor.x,coor.y,coor.x+object.x,coor.y+object.y);
	  floodfill(coor.x+(object.x/2),coor.y+(object.y/2),WHITE);
	  delay(10);
	  setfillstyle(SOLID_FILL,BLACK);
	  floodfill(coor.x+(object.x/2),coor.y+(object.y/2),WHITE);
	  setcolor(BLACK);
	  rectangle(coor.x,coor.y,coor.x+object.x,coor.y+object.y);  }
	else if(!strcmp(object.obj,"cir"))
	{ setcolor(WHITE);
	  setfillstyle(SOLID_FILL,object.c);
	  ellipse(coor.x,coor.y,0,360,(object.x/2),(object.y/2));
	  floodfill(coor.x,coor.y,WHITE);
	  delay(10);
	  setfillstyle(SOLID_FILL,BLACK);
	  floodfill(coor.x,coor.y,WHITE);
	  setcolor(BLACK);
	  ellipse(coor.x,coor.y,0,360,(object.x/2),(object.y/2)); }
	else if(!strcmp(object.obj,"line"))
	{ setcolor(object.c);
	  if(count==0)
	  { line(coor.x,coor.y,coor.x,coor.y);
	    count++; }
	  else
	   line(m,n,coor.x,coor.y);
	  delay(10);
	  m=coor.x;  n=coor.y;  }}
      file.close();  }

void coordinates(int x,int y)
{   int temp;
    char text[5];
    text[3]='\0';
    setfillstyle(SOLID_FILL,BLACK);
    settextstyle(2,0,4);
    bar(getmaxx()-50,getmaxy()-15,getmaxx(),getmaxy());
    temp=x;
    text[2]=(char)(temp%10)+48;
    temp/=10;
    text[1]=(char)(temp%10)+48;
    temp/=10;
    text[0]=(char)(temp%10)+48;
    if(x<10)
    { text[0]=(char)(x%10)+48;
      text[1]='\0';  }
    outtextxy(getmaxx()-48,getmaxy()-10,text);
    temp=y;
    text[2]=(char)(temp%10)+48;
    temp/=10;
    text[1]=(char)(temp%10)+48;
    temp/=10;
    text[0]=(char)(temp%10)+48;
    if(y<10)
    { text[0]=(char)(y%10)+48;
      text[1]='\0';  }
    outtextxy(getmaxx()-28,getmaxy()-12,",");
    outtextxy(getmaxx()-23,getmaxy()-10,text);  }


