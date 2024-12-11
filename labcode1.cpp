//1.cpp
/*

		write c++ programe to Fill the polygon using scanfill algorithm . apply concept of inheritance.
		
*/
//#include<conio.h>
#include<iostream>
#include<graphics.h>
#include<stdlib.h>

using namespace std;

class point
{
	public:
	int x,y;
};
class poly : public point
{
	public:
	point p[20];
	int inter[20],x,y;
	int v,xmin,ymin,xmax,ymax;
	public:
	int c;
	void read();
	void calcs();
	void display();
	void ints(float);
	void sort(int);
};

//function for reading the data of the vertices using the array 
void poly::read()
{
	cout<<"\n Scan Fill Algorithm ";
	cout<<"\n Enter Number Of vertices Of polygon";
	cin>>v;
	if(v>2)
	{
		int i;
		for(i=0;i<v;i++) //to accept the verices one after another
		{
			cout<<"\n Enter Co-ordinate no. "<<i+1<<" : ";
			cout<<"\n\t x"<<(i+1)<<"=";
			cin>>p[i].x;
			cout<<"\n\t y"<<(i+1)<<"=";
			cin>>p[i].y;
		}
		p[i].x = p[0].x;
		p[i].y = p[0].y;
		xmin=xmax=p[0].x;
		ymin=ymax=p[0].y;
	}
	else
	cout<<"\n Enter Valid No. of Vertices..";
}
//function to Calculate
void poly::calcs()
{
	for(int i=0;i<v;i++)
	{
		if(xmin>p[i].x)
			xmin=p[i].x;
		if(xmax<p[i].x)
			xmax=p[i].x;
		if(ymin>p[i].y)
			ymin=p[i].y;
		if(ymax<p[i].y)
			ymax=p[i].y;
	}
}
//Function To Display The Menu
void poly::display()
{
	int ch1;// Taking the Chooice of Operation
	char ch='y';
	float s,s2;
	//using do while loop
	do
	{
		cout<<"\n\n MENU: ";
		cout<<"\n\n\t 1. Scan line Fill ";
		cout<<"\n\n\t 2. Exit ";
		cout<<"\n\n Enter Your Choice: ";
		cin>>ch1;
		switch(ch1)
		{
			case 1:
				s=ymin+0.01;
				delay(100);
				cleardevice();
				while(s<=ymax)
				{
					ints(s);
					sort(s);
					s++;
				}
				break;
			case 2:
				exit(0);
		}
		cout<<"Do you Want To continue?: ";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
}
//Input for PolyGon Scan Line 
void poly::ints(float z)
{
	int x1,x2,y1,y2,temp;
	c=0;
	for(int i=0;i<v;i++)
	{
		x1=p[i].x;
		y1=p[i].y;
		x2=p[i+1].x;
		y2=p[i+1].y;
		if(y2<y1)
		{
			temp=x1;
			x1=x2;
			x2=temp;
			temp=y1;
			y1=y2;
			y2=temp;
		}
		if(z<=y2 && z>=y1)
		{
			if((y1-y2)==0)
				x=x1;
			else
			{
				x=((x2-x1)*(z-y1)/(y2-y1));
				x=x+x1;
			}
			if(x<=xmax && x>= xmin)
			inter[c++]=x;
		}
	}
}
//Sorting The Scan Lines
void poly::sort(int z) // sorting
{
	int temp,j,i;

	for(i=0;i<v;i++)
	{
		line(p[i].x,p[i].y,p[i+1].x,p[i+1].y);
	}
	delay(100);
	for(i=0; i<c;i+=2)
	{
		delay(100);
		line(inter[i],z,inter[i+1],z);
	}
}


int main()
{
	int gd=DETECT,gm;
	int cl;
	initgraph(&gd,&gm,NULL);//opening Graph
	cleardevice();
	poly x;
	x.read();
	x.calcs();
	cleardevice();
	cout<<"\n\tEnter The Color You Want :(In Range 0 To 15 )->"; //selecting color
	cin>>cl;
	setcolor(cl);
	x.display();
	closegraph(); //closing graph
	getch();
	return 0;
}

//2.cpp
//Write C++ program to implement Cohen Southerland line clipping algorithm

#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<graphics.h>
//#include<dos.h>
using namespace std;
class Coordinate
{
	public:
	int x,y;
	char code[4];
};
class Lineclip
{
	public:
	Coordinate PT;
	void drawwindow();
	void drawline(Coordinate p1,Coordinate p2);
	Coordinate setcode(Coordinate p);
	int visibility(Coordinate p1,Coordinate p2);
	Coordinate resetendpt(Coordinate p1,Coordinate p2);
};
int main()
{
	Lineclip lc;
	int gd = DETECT,v,gm;
	Coordinate p1,p2,p3,p4,ptemp;
	cout<<"\n Enter x1 and y1\n";
	cin>>p1.x>>p1.y;
	cout<<"\n Enter x2 and y2\n";
	cin>>p2.x>>p2.y;
	initgraph(&gd,&gm,"");
	lc.drawwindow();
	delay(2000);
	lc.drawline (p1,p2);
	delay(2000);
	cleardevice();
	delay(2000);
	p1=lc.setcode(p1);
	p2=lc.setcode(p2);
	v=lc.visibility(p1,p2);
	delay(2000);
	switch(v)
	{
		case 0: lc.drawwindow();
		delay(2000);
		lc.drawline(p1,p2);
		break;
		case 1:lc.drawwindow();
		delay(2000);
		break;
		case 2:p3=lc.resetendpt(p1,p2);
		p4=lc.resetendpt(p2,p1);
		lc.drawwindow();
		delay(2000);
		lc.drawline(p3,p4);
		break;
	}
	delay(2000);
	closegraph();
}
void Lineclip::drawwindow()
{
	line(150,100,450,100);
	line(450,100,450,350);
	line(450,350,150,350);
	line(150,350,150,100);
}
void Lineclip::drawline(Coordinate p1,Coordinate p2)
{
	line(p1.x,p1.y,p2.x,p2.y);
}
Coordinate Lineclip::setcode(Coordinate p)
{
	Coordinate ptemp;
	if(p.y<100)
		ptemp.code[0]='1';
	else
		ptemp.code[0]='0';
	if(p.y>350)
		ptemp.code[1]='1';
	else
		ptemp.code[1]='0';
	if(p.x>450)
		ptemp.code[2]='1';
	else
		ptemp.code[2]='0';
	if(p.x<150)
		ptemp.code[3]='1';
	else
		ptemp.code[3]='0';
	ptemp.x=p.x;
	ptemp.y=p.y;
	return(ptemp);
};
int Lineclip:: visibility(Coordinate p1,Coordinate p2)
{
	int i,flag=0;
	for(i=0;i<4;i++)
	{
		if(p1.code[i]!='0' || (p2.code[i]=='1'))
			flag='0';
	}
	if(flag==0)
	return(0);
	for(i=0;i<4;i++)
	{
		if(p1.code[i]==p2.code[i] && (p2.code[i]=='1'))
		flag='0';
	}
	if(flag==0)
	return(1);
	return(2);
}
Coordinate Lineclip::resetendpt(Coordinate p1,Coordinate p2)
{
	Coordinate temp;
	int x,y,i;
	float m,k;
	if(p1.code[3]=='1')
		x=150;
	if(p1.code[2]=='1')
		x=450;
	if((p1.code[3]=='1') || (p1.code[2])=='1')
	{
		m=(float)(p2.y-p1.y)/(p2.x-p1.x);
		k=(p1.y+(m*(x-p1.x)));
		temp.y=k;
		temp.x=x;
		for(i=0;i<4;i++)
			temp.code[i]=p1.code[i];
		if(temp.y<=350 && temp.y>=100)
			return (temp);
	}
	if(p1.code[0]=='1')
		y=100;
	if(p1.code[1]=='1')
		y=350;
	if((p1.code[1]=='1') || (p1.code[1]=='1'))
	{
		m=(float)(p2.y-p1.y)/(p2.x-p1.x);
		k=(float)p1.x+(float)(y-p1.y)/m;
		temp.x=k;
		temp.y=y;
		for(i=0;i<4;i++)
		temp.code[i]=p1.code[i];
		return(temp);
	}
	else
	return(p1);
}

//3.cpp
//Write C++ program to draw the following pattern. Use DDA line and
//Bresenham‘s circledrawing algorithm. Apply the concept of encapsulation.

#include<iostream>
#include<graphics.h>
#include<stdlib.h>
using namespace std;

class dcircle
{
	private:
	int x0,y0;
	public:

	dcircle()
	{
		x0=0;
		y0=0;
	}
	void setoff(int xx,int yy)
	{
		x0=xx;
		y0=yy;
	}
	void drawc(int x1,int y1,int r)
	{
		float d;
		int x,y;
		x=0;
		y=r;
		d=3-2*r;
		do
		{
			putpixel(x1+x0+x,y0+y-y1,15);
			putpixel(x1+x0+y,y0+x-y1,15);
			putpixel(x1+x0+y,y0-x-y1,15);
			putpixel(x1+x0+x,y0-y-y1,15);
			putpixel(x1+x0-x,y0-y-y1,15);
			putpixel(x1+x0-y,y0-x-y1,15);
			putpixel(x1+x0-y,y0+x-y1,15);
			putpixel(x1+x0-x,y0+y-y1,15);
			if (d<=0)
			{
				d=d+4*x+6;
			}
			else
			{
				d=d+4*(x-y)+10;
				y=y-1;
			}
			x=x+1;
		}
		while(x<y);
	}
};

class pt
{
	protected:
	int xco, yco,color;
	public:
	pt()
	{
		xco=0,yco=0,color=15;
	}
	void setco(int x, int y)
	{
		xco=x;
		yco=y;
	}
	void setcolor(int c)
	{
		color=c;
	}
	void draw()
	{
		putpixel(xco,yco,color);
	}
};
class dline:public pt
{
	private: int x2, y2;
	public:
	dline():pt()
	{
		x2=0;
		y2=0;
	}
	void setline(int x, int y, int xx, int yy)
	{
		pt::setco(x,y);
		x2=xx;
		y2=yy;
	}
	void drawl( int colour)
	{
		float x,y,dx,dy,length;
		int i;
		pt::setcolor(colour);
		dx= abs(x2-xco);
		dy=abs(y2-yco);
		if(dx>=dy)
		{
			length= dx;
		}
		else
		{
			length= dy;
		}
		dx=(x2-xco)/length;
		dy=(y2-yco)/length;
		x=xco+0.5;
		y=yco+0.5;
		i=1;
		while(i<=length)
		{
			pt::setco(x,y);
			pt::draw();
			x=x+dx;
			y=y+dy;
			i=i+1;
		}
		pt::setco(x,y);
		pt::draw();
	}
};

int main()
{
	int gd=DETECT, gm;
	initgraph(&gd, &gm, NULL);
	int x,y,r, x1, x2, y1, y2, xmax, ymax, xmid, ymid, n, i;
	dcircle c;
	cout<<"\nenter coordinates of centre of circle : ";
	cout<<"\n enter the value of x : ";
	cin>>x;
	cout<<"\nenter the value of y : ";
	cin>>y;
	cout<<"\nenter the value of radius : ";
	cin>>r;
	xmax= getmaxx();
	ymax=getmaxy();
	xmid=xmax/2;
	ymid=ymax/2;
	setcolor(1);
	c.setoff(xmid,ymid);
	line(xmid, 0, xmid, ymax);
	line(0,ymid,xmax,ymid);	
	setcolor(15);
	c.drawc(x,y,r);
	pt p1;
	p1.setco(100,100);
	p1.setcolor(14);
	dline l;
	l.setline(x1+xmid, ymid-y1, x2+xmid, ymid-y2);
	cout<<"Enter Total Number of lines : ";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"Enter co-ordinates of point x1 : ";
		cin>>x1;
		cout<<"enter coordinates of point y1 : ";
		cin>>y1;
		cout<<"Enter co-ordinates of point x2 : ";
		cin>>x2;
		cout<<"enter coordinates of point y2 : ";
		cin>>y2;
		l.setline(x1+xmid, ymid-y1, x2+xmid, ymid-y2);
		l.drawl(15);
	}
	cout<<"\nEnter coordinates of centre of circle : ";
	cout<<"\n Enter the value of x : ";
	cin>>x;
	cout<<"\nEnter the value of y : ";
	cin>>y;
	cout<<"\nEnter the value of radius : ";
	cin>>r;
	setcolor(5);
	c.drawc(x,y,r);
	getch();
	delay(500);
	closegraph();
	return 0;
}

//4.cpp
//Write C++ program to draw 2-D object and perform following basic 
//transformations, Scaling, Translation c) Rotation. Apply the concept of
//operator overloading.
//OR
//Write C++ program to implement translation, rotation and scaling
//transformations onequilateral triangle and rhombus. Apply the concept of
//operator overloading.


#include<iostream> 
#include<graphics.h> 
#include<stdlib.h> 
#include<math.h> 
using namespace std; 
int pi[10]; 
double b[3][3]={1,0,0, 
0,1,0, 
0,0,1, 
}; 
int c[1][1]; 
float a[1][1]; 
void matmul(float[]); 
int main() 
{ 
	int op,i,x,y,tx,ty,sx,sy,angle=10,xmax,ymax,xmid,ymid; 
	int gd,gm=VGAMAX; 
	gd=DETECT; 
	float p1[10]={50,50, 
	100,50, 
	100,100, 
	50,100, 
	50,50, 
}; 
cout<<"\n select transformation:="; 
cout<<"\n 1.translation:="; 
cout<<"\n 2.rotation:="; 
cout<<"\n 3.scaling:="; 
cout<<"\n 4.rotation about arbitrary point:="; 
cout<<"\n 5.enter the option:="; 
cin>>op; 
switch(op) 
{ 
	case 1: 
	cout<<"\n enter the x translation:="; 
	cin>>tx; 
	cout<<"\n enter the y translation:="; 
	cin>>ty; 
	b[0][0]=1; 
	b[0][1]=0; 
	b[0][2]=0; 
	b[1][0]=0; 
	b[1][1]=1; 
	b[1][2]=0; 
	b[2][0]=tx; 
	b[2][1]=ty; 
	b[2][2]=1; 
	break; 
	case 2: 
	cout<<"\n enter the rotation angle :"; 
	cin>>angle; 
	b[0][0]=cos(angle*3.142/180); 
	b[0][1]=sin(angle*3.142/180); 
	b[0][2]=0; 
	b[1][0]=-sin(angle*3.142/180); 
	b[1][1]=cos(angle*3.142/180); 
	b[1][2]=0; 
	b[2][0]=0; 
	b[2][1]=0; 
	b[2][2]=1; 
	break; 
	case 3: 
	cout<<"\n enter the x scaling:"; 
	cin>>sx; 
	cout<<"\n enter y scaling:"; 
	cin>>sy; 
	b[0][0]=sx; 
	b[0][1]=0; 
	b[0][2]=0; 
	b[1][0]=0; 
	b[1][1]=sy; 
	b[1][2]=0; 
	b[2][0]=0; 
	b[2][1]=0; 
	b[2][2]=1; 
	break; 
	case 4: 
	cout<<"\n enter x coordinate of arbitatary point :"; 
	cin>>x; 
	cout<<"\n enter x coordinate of arbitatary point:"; 
	cin>>y; 
	cout<<"\n enter the rotation angle:="; 
	cin>>angle; 
	tx=x; 
	ty=y; 
	b[0][0]=cos(angle*3.142/180); 
	b[0][1]=sin(angle*3.142/180); 
	b[0][2]=0; 
	b[1][0]=-sin(angle*3.142/180);
	b[1][1]=cos(angle*3.142/180); 
	b[1][2]=0; 
	b[2][0]=-tx*cos(angle*3.142/180)+ty*sin(angle*3.142/180)+tx; 
	b[2][1]=-tx*sin(angle*3.142/180)-ty*cos(angle*3.142/180)+ty; 
	b[2][2]=1; 
} 
initgraph(&gd,&gm,NULL); //initialize graphics 
xmax=getmaxx(); //get the maximum y coordinate 
ymax=getmaxy(); //get the maximum x co-ordinate 
xmid=xmax/2; //get the center x coordinate 
ymid=ymax/2; //get the center y coordinate 
setcolor(1); 
line(xmid,0,xmid,ymax); //draw y coordinate 
line(0,ymid,xmax,ymid); //draw x coordinate 
setcolor(4);
for(i=0;i<8;i=i+2) 
{ 
	line(p1[i]+xmid,ymid-p1[i+1],xmid+p1[i+2],ymid-p1[i+3]); 
} 
matmul(p1); 
setcolor(15); 
for(i=0;i<8;i=i+2) 
{ 
	line(xmid+pi[i],ymid-pi[i+1],xmid+pi[i+2],ymid-pi[i+3]); 
} 
getch(); 
closegraph(); 
return 0; 
} 
void matmul(float p[10]) 
{ 
	int i; 
	for(i=0;i<9;i=i+2) 
	{ 
		a[0][0]=p[i]; 
		a[0][1]=p[i+1]; 
		c[0][0]=a[0][0]*b[0][0]+a[0][1]*b[1][0]+b[2][0]; 
		c[0][1]=a[0][0]*b[0][1]+a[0][1]*b[1][1]+b[2][1]; 
		pi[i]=c[0][0]; 
		pi[i+1]=c[0][1]; 
	} 
}

//5.cpp
//Write C++ program to generate snowflake using concept of fractals.
//OR
//Write C++ program to generate Hilbert curve using concept of fractals.

#include<iostream>
#include<graphics.h>
using namespace std;
void move(int ,int,int&,int&);
void hilbert(int ,int ,int,int ,int,int ,int &,int &);
void move(int j,int h,int &x,int &y)
{
	if(j==1){
		y-=h;
	}
	else if(j==2){
		x+=h;
	}
	else if(j==3){
		y+=h;
	}
	else if(j==4){
		x-=h;
	}
	lineto(x,y);
}

void hilbert (int r,int d,int l,int u,int i,int h,int &x,int &y )
{
	if(i>0){
		i--;
		hilbert(d,r,u,l,i,h,x,y);
		move(r,h,x,y);
		hilbert(r,d,l,u,i,h,x,y);
		move(d,h,x,y);
		hilbert(r,d,l,u,i,h,x,y);
		move(l,h,x,y);
		hilbert(u,l,d,r,i,h,x,y);
	}
}

int main(){
	int gd=DETECT,gm;
	char ch;
	initgraph(&gd,&gm,NULL);
	do{
		int n,x1,y1;
		int x0=150,y0=100,x,y,h=10,r=2,d=3,l=4,u=1;
		cout<<"\n Enter thr order of the curve:";
		cin>>n;
		x=x0;
		y=y0;
		moveto(x,y);
		hilbert(r,d,l,u,n,h,x,y);
		cout <<"\n Do you want to continue(y/n)";
		cin>>ch;
			
	}while(ch=='y');
	
	getch();
}

//6.cpp
//Write C++ program to draw 3-D cube and perform following transformations 
//on it using OpenGL i) Scaling ii) Translation iii) Rotation about an axis
//(X/Y/Z).
//OR
//Write OpenGL program to draw Sun Rise and Sunset.

#include<iostream> 
#include<stdlib.h> 
#ifdef APPLE 
#include<openGL/OpenGL.h> 
#include<GLUT/glut.h> 
#else 
#include<GL/glut.h> 
#endif 
using namespace std; 
float ballX = -0.8f; 
float ballY = -0.3f; 
float ballZ = -1.2f; 
float colR=5.0; 
float colG=3.5; 
float colB=2.0; 
float bgColR=0.43; 
float bgColG=0.12; 
float bgColB=0.08; 
static int flag=1; 
void drawBall(void) { 
	glColor3f(colR,colG,colB); //set ball colour 
	glTranslatef(ballX,ballY,ballZ); //moving it toward the screen a bit on creation 
	glutSolidSphere (0.05, 50, 30); //create ball. 
} 
void drawAv(void) { 
	glBegin(GL_POLYGON); 
	glColor3f(0.0,1.0,0.0); 
	glVertex3f(-0.9,-0.7,-1.0); 
	glVertex3f(-0.5,-0.1,-1.0); 
	glVertex3f(-0.2,-1.0,-1.0); 
	glVertex3f(0.5,0.0,-1.0); 
	glVertex3f(0.6,-0.2,-1.0); 
	glVertex3f(0.9,-0.7,-1.0);
	glEnd(); 
} 
void drawClouds(){
	//glBegin(GL_CIRCLE);
		
	//glEnd();
	
} 
void keyPress(int key, int x, int y) 
{ 
	if(key==GLUT_KEY_RIGHT) 
	ballX -= 0.05f; 
	if(key==GLUT_KEY_LEFT) 
	ballX += 0.05f; 
	glutPostRedisplay(); 
} 
void initRendering() { 
	glEnable(GL_DEPTH_TEST); 
	glEnable(GL_COLOR_MATERIAL); 
	glEnable(GL_LIGHTING); //Enable lighting 
	glEnable(GL_LIGHT0); //Enable light #0 
	glEnable(GL_LIGHT1); //Enable light #1 
	glEnable(GL_NORMALIZE); //Automatically normalize normals 
	//glShadeModel(GL_SMOOTH); //Enable smooth shading 
}
//Called when the window is resized 
void handleResize(int w, int h) { 
//Tell OpenGL how to convert from coordinates to pixel values 
	glViewport(0, 0, w, h); 
	glMatrixMode(GL_PROJECTION); //Switch to setting the camera perspective 
	//Set the camera perspective 
	glLoadIdentity(); //Reset the camera 
	gluPerspective(45.0, //The camera angle 
	(double)w / (double)h, //The width-to-height ratio 
	1.0, //The near z clipping coordinate 
	200.0); //The far z clipping coordinate 
} 
void drawScene() 
{ 
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); 
	glClearColor(bgColR,bgColG,bgColB,0.0); 
	glMatrixMode(GL_MODELVIEW); 
	glLoadIdentity(); 
	//Add ambient light 
	GLfloat ambientColor[] = {0.2f, 0.2f, 0.2f, 1.0f}; //Color (0.2, 0.2, 0.2)
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor); 
	//Add positioned light 
	GLfloat lightColor0[] = {0.5f, 0.5f, 0.5f, 1.0f}; //Color (0.5, 0.5, 0.5) 
	GLfloat lightPos0[] = {4.0f, 0.0f, 8.0f, 1.0f}; //Positioned at (4, 0, 8) 
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0); 
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos0); 
	//Add directed light 
	GLfloat lightColor1[] = {0.5f, 0.2f, 0.2f, 1.0f}; //Color (0.5, 0.2, 0.2) 
	//Coming from the direction (-1, 0.5, 0.5) 
	GLfloat lightPos1[] = {-1.0f, 0.5f, 0.5f, 0.0f}; 
	glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1); 
	glLightfv(GL_LIGHT1, GL_POSITION, lightPos1); 
	//drawing the SUN 
	glPushMatrix(); 
	drawBall(); 
	glPopMatrix(); 
	//drawing the Mount Avarest 
	glPushMatrix(); 
	drawAv(); 
	glPopMatrix(); 
	//drawing the Clouds
	glPushMatrix(); 
	drawClouds(); 
	glPopMatrix(); 
	glPushMatrix();
	drawClouds();
	glPopMatrix();
	glutSwapBuffers(); 
} 
//float _angle = 30.0f; 
void update(int value) { 
	if(ballX>0.9f) 
	{ 
	ballX = -0.8f; 
	ballY = -0.3f; 
	flag=1; 
	colR=5.0; 
	colG=3.50; 
	colB=2.0; 
	bgColB=0.0; 
	} 
	if(flag) 
	{ 
	ballX += 0.001f;
	glPushMatrix(); 
	drawClouds(); 
	glPopMatrix(); 
	glutSwapBuffers(); 
	}
	 
//float _angle = 30.0f; 
	//void update(int value){ 
		if(ballX>0.9f) 
		{ 
		ballX = -0.8f; 
		ballY = -0.3f; 
		flag=1; 
		colR=5.0; 
		colG=3.50; 
		colB=2.0; 
		bgColB=0.0; 
		} 
		if(flag) 
		{ 
		ballX += 0.001f;
		} 
		
	glutPostRedisplay(); //Tell GLUT that the display has changed 
	//Tell GLUT to call update again in 25 milliseconds 
	glutTimerFunc(25, update, 0);
}   	
int main(int argc,char** argv) 
{ 
	glutInit(&argc,argv); 
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH); 
	glutInitWindowSize(400,400); 
	glutCreateWindow("Sun"); 
	initRendering(); 
	glutDisplayFunc(drawScene); 
	glutFullScreen();
	glutSpecialFunc(keyPress); 
	glutReshapeFunc(handleResize); 
	glutTimerFunc(25, update, 0); 
	glutMainLoop(); 
	return 0; 
}

//7.cpp
//Write a C++ program to implement bouncing ball using sine wave form.
//Apply the conceptof polymorphism.
// OR
//Write C++ program to draw man walking in the rain with an umbrella. Apply
//the concept ofpolymorphism.

#include<iostream>
//#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
//#include<dos.h>
using namespace std;
class walkingman
{
	int rhx,rhy;
	public:
	void draw(int,int);
	void draw(int);
};
void walkingman::draw(int i)
{
	line(20,380,580,380);
	if(i%2)
	{
		line(25+i,380,35+i,340);
		line(45+i,380,35+i,340);
		line(35+i,310,25+i,330);
		delay(20);
	}
	else
	{
		line(35+i,340,35+i,310);
		line(35+i,310,40+i,330);
		delay(20);
	}
	line(35+i,340,35+i,310);
	circle(35+i,300,10);
	line(35+i,310,50+i,330);
	line(50+i,330,50+i,280);
	line(15+i,280,85+i,280);
	arc(50+i,280,180,360,35);
	arc(55+i,330,360,180,5);
}

void walkingman::draw(int x,int y)
{
	int j;
	rhx=x;
	rhy=y;
	for(j=0;j<100;j++)
	{
		outtextxy(rand()%rhx,rand()%(rhy-50),"|");
		setcolor(WHITE);
	}
}
int main()
{
	int gd=DETECT,gm;
	int rhx,rhy,j,i;
	walkingman obj;
	initgraph(&gd,&gm,"");
	for(i=0;i<500;i++)
	{
		obj.draw(i);
		rhx=getmaxx();
		rhy=getmaxy();
		obj.draw(rhx,rhy);
		delay(150);
		cleardevice();
	}
	getch();
}
