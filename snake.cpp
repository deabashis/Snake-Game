#include<graphics.h>
#include<stdio.h>
void start();
void try_new(char* who, int l1, int l2)
{
    char point_text[100];
    char who_2[100];
    cleardevice();
    setfillstyle(1,1);
    bar(0,0,640,10);
    bar(0,0,10,480);
    bar(0,480,640,470);
    bar(630,10,640,480);
    while(1)
    {
        setcolor(1);
        outtextxy(160, 100, "Deabashis Sarker Tamal");
        outtextxy(200, 120, "ID: 201-35-606");
        sprintf(who_2, "%s Die", who);
        outtextxy(250, 190, who_2);
        setcolor(15);
        sprintf(point_text, "Point A: %d", l1-5);
        outtextxy(220, 215, point_text);
        setcolor(6);
        sprintf(point_text, "Point B: %d", l2-5);
        outtextxy(220, 235, point_text);
        outtextxy(150, 400, "Press ENTER to start");
        if(GetAsyncKeyState(13))
        {
            cleardevice();
            start();
            break;
        }
        delay(2000);
    }
}
void first()
{
    setfillstyle(1,1);
    bar(0,0,640,10);
    bar(0,0,10,480);
    bar(0,480,640,470);
    bar(630,10,640,480);
    while(1)
    {
        setcolor(1);
        settextstyle(8,0,3);
        outtextxy(160, 100, "Deabashis Sarker Tamal");
        outtextxy(200, 120, "ID: 201-35-606");
        outtextxy(150, 400, "Press ENTER to start");
        if(GetAsyncKeyState(13))
        {
            cleardevice();
            start();
            break;
        }
        delay(2000);
    }
}
void start()
{
	int i,X1[100],Y1[100],X2[100],Y2[100],rx,ry,l1,l2,d1=0,d2=2,s=8;
    char point_text[100];
    settextstyle(0,0,1);
    setcolor(1);
    outtextxy(10, 500, "Snake Game");
    outtextxy(10, 515, "Deabashis Sarker Tamal");
    outtextxy(10, 530, "ID: 201-35-606");
	setfillstyle(1,1);
    bar(0,0,640,10);
    bar(0,0,10,480);
    bar(0,480,640,470);
    bar(630,10,640,480);
	X1[0]=s*(640/(2*s)); Y1[0]=s*(480/(2*s));
	X2[0]=s*(640/(2*s)); Y2[0]=s*(480/(2*s));
    l1=5;
    l2=5;
	setfillstyle(1,15);
    for(i=1;i<l1;i++)
    {
        X1[i]=X1[0]-(i*s);
        Y1[i]=Y1[0];
        bar(X1[i]-s/2,Y1[i]-s/2,X1[i]+s/2,Y1[i]+s/2);
    }
	setfillstyle(1,6);
    for(i=1;i<l2;i++)
    {
        X2[i]=X2[0]-(i*s);
        Y2[i]=Y2[0];
        bar(X2[i]-s/2,Y2[i]-s/2,X2[i]+s/2,Y2[i]+s/2);
    }
    rx=s; ry=s;
    setfillstyle(1,2);
    while(getpixel(rx,ry)!=0)
	{
		rx=s*(1+rand()%(640/s-1));
		ry=s*(1+rand()%(480/s-1));
	}
	bar(rx-s/2,ry-s/2,rx+s/2,ry+s/2);
    delay(2000);
	while(1)
	{
    	setfillstyle(1,0);
		bar(X1[l1-1]-s/2,Y1[l1-1]-s/2,X1[l1-1]+s/2,Y1[l1-1]+s/2);
		bar(X2[l2-1]-s/2,Y2[l2-1]-s/2,X2[l2-1]+s/2,Y2[l2-1]+s/2);

		for(i=l1-1;i>0;i--)
    	{
    		X1[i]=X1[i-1];
    		Y1[i]=Y1[i-1];
		}
		for(i=l2-1;i>0;i--)
    	{
    		X2[i]=X2[i-1];
    		Y2[i]=Y2[i-1];
		}
    	if(d1==0)
			X1[0]=X1[0]-s;
		if(d1==1)
			Y1[0]=Y1[0]-s;
    	else if(d1==2)
			X1[0]=X1[0]+s;
		else if(d1==3)
			Y1[0]=Y1[0]+s;

    	if(d2==0)
			X2[0]=X2[0]-s;
		if(d2==1)
			Y2[0]=Y2[0]-s;
    	else if(d2==2)
			X2[0]=X2[0]+s;
		else if(d2==3)
			Y2[0]=Y2[0]+s;

		if(getpixel(X1[0],Y1[0])==1)
        {
			try_new("A", l1, l2);
			break;
        }
		if(getpixel(X2[0],Y2[0])==1)
        {
			try_new("B", l1, l2);
			break;
        }
		if((GetAsyncKeyState(VK_RIGHT))&&(d1!=0))
			d1=2;
		else if((GetAsyncKeyState(VK_UP))&&(d1!=3))
			d1=1;
		else if((GetAsyncKeyState(VK_LEFT))&&(d1!=2))
			d1=0;
		else if((GetAsyncKeyState(VK_DOWN))&&(d1!=1))
			d1=3;

		if((GetAsyncKeyState(68))&&(d2!=0))
			d2=2;
		else if((GetAsyncKeyState(87))&&(d2!=3))
			d2=1;
		else if((GetAsyncKeyState(65))&&(d2!=2))
			d2=0;
		else if((GetAsyncKeyState(83))&&(d2!=1))
			d2=3;

		if(getpixel(X1[0],Y1[0])==2)
		{
			rx=s; ry=s;
			setfillstyle(1,2);
			while(getpixel(rx,ry)!=0)
			{
				rx=s*(1+rand()%(640/s-1));
				ry=s*(1+rand()%(480/s-1));
			}
			bar(rx-s/2,ry-s/2,rx+s/2,ry+s/2);
			l1=l1+1;
		}
		if(getpixel(X2[0],Y2[0])==2)
		{
			rx=s; ry=s;
			setfillstyle(1,2);
			while(getpixel(rx,ry)!=0)
			{
				rx=s*(1+rand()%(640/s-1));
				ry=s*(1+rand()%(480/s-1));
			}
			bar(rx-s/2,ry-s/2,rx+s/2,ry+s/2);
			l2=l2+1;
		}
        setfillstyle(1,15);
		for(i=0;i<l1;i++)
       		bar(X1[i]-s/2,Y1[i]-s/2,X1[i]+s/2,Y1[i]+s/2);
        setfillstyle(1,6);
		for(i=0;i<l2;i++)
       		bar(X2[i]-s/2,Y2[i]-s/2,X2[i]+s/2,Y2[i]+s/2);
		delay(100);
        settextstyle(8,0,3);
        setcolor(15);
        sprintf(point_text, "Point A: %d", l1-5);
        outtextxy(350, 485, point_text);
        setcolor(6);
        sprintf(point_text, "Point B: %d", l2-5);
        outtextxy(350, 505, point_text);
    }
}
int main()
{
    initwindow(650, 600, "char*");
    first();

    return 0;
}
