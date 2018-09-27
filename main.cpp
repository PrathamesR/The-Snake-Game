#include<graphics.h>
#include<stdio.h>
#include<time.h>

int main()
{
    DWORD wid=GetSystemMetrics(SM_CXSCREEN);
    DWORD heig=GetSystemMetrics(SM_CYSCREEN);
    initwindow(wid,heig,"",-4,-3);
    int dir,i,j,page=0,n=0,m=0,x1=200,x2=250,y1=150,y2=200,t=0,t1x,t1y,t2x,t2y,score=0,xb,yb,sx[100],sy[100],k,r=0;
    int flag=1,speed=0;
    char a,s[20];

    while(speed==0)
    {
        setactivepage(page);
        setvisualpage(1-page);
        setcolor(GREEN);
        settextstyle(6,HORIZ_DIR,2);
        outtextxy(510,230,"THE");
        settextstyle(6,HORIZ_DIR,10);
        outtextxy(500,250,"SNAKE");
        settextstyle(6,HORIZ_DIR,2);
        outtextxy(1020,375,"GAME");
        if(GetAsyncKeyState(VK_UP)) r--;
        if(GetAsyncKeyState(VK_DOWN)) r++;
        if(GetAsyncKeyState(VK_ESCAPE)) exit(1);

    if(r==1)
    {       setcolor(YELLOW);
            outtextxy(800,500,"EASY");
            setcolor(BLUE);
            outtextxy(800,600,"MEDIUM");
            outtextxy(800,700,"HARD");
            outtextxy(800,800,"INSANE");
    }
    else if(r==2)
    {       setcolor(BLUE);
            outtextxy(800,500,"EASY");
            setcolor(YELLOW);
            outtextxy(800,600,"MEDIUM");
            setcolor(BLUE);
            outtextxy(800,700,"HARD");
            outtextxy(800,800,"INSANE");
    }
    else if(r==3)
    {
            setcolor(BLUE);
            outtextxy(800,500,"EASY");
            outtextxy(800,600,"MEDIUM");
            setcolor(YELLOW);
            outtextxy(800,700,"HARD");
            setcolor(BLUE);
            outtextxy(800,800,"INSANE");
    }
    else if(r==4)
    {
            setcolor(BLUE);
            outtextxy(800,500,"EASY");
            outtextxy(800,600,"MEDIUM");
            outtextxy(800,700,"HARD");
            setcolor(YELLOW);
            outtextxy(800,800,"INSANE");
    }
    else
    {       setcolor(BLUE);
            outtextxy(800,500,"EASY");
            outtextxy(800,600,"MEDIUM");
            outtextxy(800,700,"HARD");
            outtextxy(800,800,"INSANE");
    }

    if(GetAsyncKeyState(VK_RETURN))
    {
        if(r==1)
        {
            speed=800;
        }
        else if(r==2)
        {
            speed=400;
        }
        else if(r==3)
        {
            speed=200;
        }
        else if(r==4)
        {
            speed=70;
        }
    }

        page=1-page;
        delay(100);
    }


    srand(time(NULL));
    xb=(rand()%28)*50+125;
    yb=(rand()%16)*50+75;

    while(flag)
    {
        setactivepage(page);
        setvisualpage(1-page);
        cleardevice();
        setcolor(YELLOW);
        rectangle(100,50,wid-100,heig-50);
        settextstyle(6,HORIZ_DIR,1);
        if(GetAsyncKeyState(VK_LEFT))
        if(n!=50)
        {
            n=-50,m=0;
        }
        if(GetAsyncKeyState(VK_RIGHT))
        if(n!=-50)
        {
            n=50,m=0;
        }
        if(GetAsyncKeyState(VK_UP))
        if(m!=50)
        {
            m=-50,n=0;
        }
        if(GetAsyncKeyState(VK_DOWN))
        if(m!=-50)
        {
            m=50,n=0;
        }
        if(GetAsyncKeyState(VK_ESCAPE)) exit(1);

        t1x=x1+25;
        t1y=y1+25;

        x1=x1+n;
        y1=y1+m;
        x2=x2+n;
        y2=y2+m;

            setfillstyle(SOLID_FILL,GREEN);
            bar(x1,y1,x2,y2);
            setcolor(GREEN);
            rectangle(x1,y1,x2,y2);

         for(i=1;i<=t;i++)
        {
            t2x=sx[i];
            t2y=sy[i];
            sx[i]=t1x;
            sy[i]=t1y;
            t1x=t2x;
            t1y=t2y;
        }

        for(i=1;i<=t;i++)
        {
            setfillstyle(INTERLEAVE_FILL,GREEN);
            bar(sx[i]-25,sy[i]-25,sx[i]+25,sy[i]+25);
            setcolor(BROWN);
            rectangle(sx[i]-25,sy[i]-25,sx[i]+25,sy[i]+25);

        }

        for(i=1;i<=t;i++)
        {
            if(x1+25==sx[i] && y1+25==sy[i])
            {
                flag=0;
            }
        }
        for(i=1;i<t;i++)
        {
            if((xb==sx[i] && yb==sy[i]))
            {
                srand(time(NULL));
                xb=(rand()%28)*50+125;
                yb=(rand()%16)*50+75;
            }
        }
        if(x1+25==xb && y1+25==yb)
        {
            srand(time(NULL));
            xb=(rand()%28)*50+125;
            yb=(rand()%16)*50+75;
            score++;
            printf("\a");
            t++;
        }

        for(i=0;i<15;i++)
        {
            setcolor(RED);
            circle(xb,yb,i);
        }


        setcolor(WHITE);
        sprintf(s,"SCORE : %d",score);
        outtextxy(1300,45,s);

        if(x1==50 || x2==1550 || y1==0 || y2==900)
        {
            flag=0;
        }


        page=1-page;
        delay(speed);
    }
    while(1)
    {
        setactivepage(page);
        setvisualpage(1-page);
        cleardevice();
        settextstyle(6,HORIZ_DIR,8);
        setcolor(GREEN);
        outtextxy(450,300,"GAME OVER");
        sprintf(s,"Score : %d",score);
        setcolor(YELLOW);
        settextstyle(6,HORIZ_DIR,4);
        outtextxy(700,450,s);
        setcolor(DARKGRAY);
        settextstyle(0,HORIZ_DIR,2);
        outtextxy(625,650,"Press Enter to Play again");
        outtextxy(660,700,"Press Escape to Exit");
        if(GetAsyncKeyState(VK_ESCAPE)) exit(1);
        if(GetAsyncKeyState(VK_RETURN)) main();
        page=1-page;
    }
    closegraph();
}
