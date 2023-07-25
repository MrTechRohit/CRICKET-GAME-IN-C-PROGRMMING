/*********** WELCOME ALL OF YOU ON ROHIT TECH STUDY CHANNEL **************/
/*------------- C++ PROGRAMMING TO CREATE CRICKET GAME ------------------*/


#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<time.h>
#include<alloc.h>
#include<dos.h>

const int UP_ARROW = 72;
const int DOWN_ARROW = 80;
const int LEFT_ARROW = 75;
const int RIGHT_ARROW = 77;
const int ESC = 27;
const int ENTER = 13;

class cricket
{
private:
int a[1],x2, y2, run5[11], m, run, wicket, run2, run4, ab,bowler, wicket1[5];
float target1 , o;
char batnames[11][50], bowlnames[5][50] , acc;

public:
clock_t start , end;
cricket()
{
run = wicket = run4 = run2 = m = ab = 0;
wicket1[0] = wicket1[1] = wicket1[2] = wicket1[3] = wicket1[4] = 0;
}

	int Menu ();
	void drawMenu (int);
	int select_team();
	void drawmenu1(int);
	void welcome_screen();
	void select_screen();
	void target(int);
	void ground();
	void stumps();
	void teams(int);
	void move_ball();
	void *ball;
	void inswing();
	void outswing();
	void legspin();
	void offspin();
	void medium();
	void score(int);
	void victory();
	void defeat();
	void batsman(int);
	void credits();
	void boundaries();
	void move_batsman(int);
	void help();
	void scoreboard();
	void pause();
};

void cricket::welcome_screen()
{
	setbkcolor(8);
	setcolor(YELLOW);
	settextstyle(7,0,3);
	outtextxy(100,100,"WELCOME TO CRICKET 2022");
	outtextxy(100,200,"PRESS ANY KEY TO CONTINUE...");
	getch();
	sound( 520 );
	delay( 100 );
	nosound();
	sound( 1000 );
	delay( 100 );
	nosound();
	cleardevice();
	select_screen();
}

void cricket::select_screen()
{
	cleardevice();
	int ch,i,key,rep,rep1;
	Again:
	rep = Menu();
	switch(rep)
	{
	case 4:
	closegraph();
	exit(0);
	return;
	case 2:
	help();
	goto Again;
	case 3:
	credits();
	goto Again;
	case 1:
	rep1=select_team();
	switch(rep1)
	case 1:case 2:case 3:case 4: case 5:case 6:case 7: case 8:
	target(rep1);
	teams(rep1);
	getch();
	}
}

int cricket::Menu()
{
int selected = 1,TotalOptions = 4;
char ch;
cleardevice();
setbkcolor ( 6 );
drawMenu ( selected );
do
{
ch = getch();
if ( ch == DOWN_ARROW )
selected = selected >= TotalOptions ? 1 : selected + 1;
else if ( ch == UP_ARROW )
selected = selected < 2 ? TotalOptions : selected - 1;
drawMenu ( selected );
}
while ( ch != ENTER );

return selected;
}

void cricket::drawMenu( int selected )
{
int x = 230, y = 100, width = 180, height = 40, i, TotalOptions = 4;
char menu_option[4][14]=
 {
  "     T20     ",
  "    HELP     ",
  "   CREDITS   ",
  "    EXIT     "
  };
  setcolor ( 4 );
  setfillstyle ( 1 , 11 );
  setlinestyle ( 0 , 0 , 0 );
  settextstyle ( 7 , 0 , 3 );

  for ( i = 1; i <= TotalOptions; i++ )
  {
  bar ( x , y , x + width , y + height );
  rectangle ( x , y , x + width , y + height );
  outtextxy ( x + 10 , y + 5 , menu_option[i - 1] );
  y = y + height + 30;
  }

  setfillstyle ( 1 , 4 );
  setcolor ( 11 );
  y = y - TotalOptions * (height + 30) + (selected - 1) * (height + 30);

  bar ( x , y , x + width , y + height );
  rectangle ( x , y , x + width , y + height );
  outtextxy ( x + 10 , y + 5 , menu_option[selected - 1] );
}

int cricket::select_team()
{
    char ch1;
    int select=1;
    sound( 520 );
    delay( 100 );
    nosound();
    sound( 1000 );
    delay( 100 );
    nosound();
    cleardevice();
    setbkcolor( 10 );
    drawmenu1(select);
    do{
		ch1 = getch();
		if(ch1==ESC)
		select_screen();
		if ( ch1 == DOWN_ARROW )
		{
			if( select < 4 )
			select += 1;
			else if( select == 4 )
			select -= 3;
			else if( select > 4 && select < 8 )
			select += 1;
			else
			select -= 3;
		}
		if ( ch1 == UP_ARROW )
		{
			if(select > 1 && select < 5)
			select -= 1;
			else if( select == 1 )
			select += 3;
			else if( select > 5 && select < 9 )
			select -= 1;
			else
			select += 3;
		}
		if ( ch1 == RIGHT_ARROW || ch1 == LEFT_ARROW )
		{
		if(select<5)
		select+=4;
		else
		select-=4;
		}
		drawmenu1(select);
    }
    while ( ch1!= ENTER );
    return select;
}

void cricket::drawmenu1(int select)
{
int x = 200, y = 100, width = 100, height = 40, total_options = 4;

char menu_opt[8][14]={"IND","WI","PAK","ENG","NZ","AUS","SL","SA"};
	settextstyle( 4 , 0 , 4 );
	setcolor( BROWN );
	outtextxy( 100 , 15 , "Select Your Team" );
	settextstyle( 3 , 0 , 2 );
	outtextxy( 100 , 60 , "Press ESC to go to Main Menu" );
	setcolor ( 4 );
	setfillstyle ( 1 , 11 );
	setlinestyle ( 0 , 0 , 0 );
	settextstyle ( 7 , 0 , 3 );

	for (int i = 1; i <= 4; i++ )
	{
	 bar ( x , y , x + width , y + height );
	 rectangle ( x , y , x + width , y + height );
	 outtextxy ( x + 25 , y + 5 , menu_opt[i - 1] );
	 bar ( x+160 , y , x + 160 + width , y + height );
	 rectangle ( x + 160 , y , x + 160 + width , y + height );
	 outtextxy ( x + 160 + 25 , y + 5 , menu_opt[i+ 3] );
	 y = y + height + 30;
	}

setfillstyle ( 1 , 4 );
setcolor ( 11 );
if(select>4)
{
y = y - total_options * ( height + 30 )+ ( select - 1 ) * ( height + 30 );
bar ( x+160 , y-280 , x +160+ width , y + height-280 );
rectangle ( x+160 , y-280 , x +160+ width , y + height - 280 );
outtextxy ( x +160+ 25 , y -280 + 5 , menu_opt[select - 1] );
}

else if(select<5)
{
y = y - total_options * ( height + 30 ) + ( select - 1 ) * ( height + 30 );
bar (x , y , x + width , y + height );
rectangle ( x , y , x + width , y + height );
outtextxy ( x + 25 , y + 5 , menu_opt[select - 1] );
}
}

void cricket::credits()
{
sound( 520 );
delay( 100 );
nosound();
sound( 1000 );
delay( 100 );
nosound();
cleardevice();
setbkcolor(0);
settextstyle( 7 , 0 , 7 );
setcolor( 12 );
outtextxy( 0 , 20 , "CREDITS:" );
settextstyle( 3 , 0 , 2 );
setcolor( 10 );
outtextxy( 15 , 120 , "This game is developed by ROHIT who" );
outtextxy( 15 , 140 , "is Owner of ROHIT TECH STUDY Youtube Channel" );
outtextxy(15, 200,"If you have any doubts or show any bug,comments me");
outtextxy( 15 , 220 , "in youtube video and message me on my social apps" );
outtextxy( 15 , 260 , "Suggestions are welcomed." );
getch();
}

void cricket::help()
{
sound( 520 );
delay( 100 );
nosound();
sound( 1000 );
delay( 100 );
nosound();
cleardevice();
setbkcolor( 0 );
settextstyle( 7 , 0 , 7 );
setcolor( 12 );
outtextxy( 0 , 20 , "HELP:" );
setcolor( 10 );
settextstyle( 0 , 0 , 1 );
outtextxy( 40 , 120 , "Cricket 2022 is a virtual reality cricket game");
outtextxy(40 , 140 , "Each innings consists of 20 overs." );
outtextxy(40 , 160 , "The name of the batsman,target,overs are displayed in the bottom.");
outtextxy(40 , 180 , "The name of the bowler is displayed in the right top corner.");
outtextxy(40 , 200 , "The instructions of the game is listed below:");
outtextxy(40 , 220 , "Press UP key to hit the ball in straights.");
outtextxy(40 , 240 , "Press LEFT key to hit the ball in legside.");
outtextxy(40 , 260 , "Press RIGHT key to hit the ball in offside.");
outtextxy(40 , 280 , "Press ESC to pause the game.");
settextstyle( 0 , 0 , 4 );
outtextxy(40 , 360 , "Enjoy playing!!!" );
getch();
}

void cricket::target(int select)
{
sound( 520 );
delay( 100 );
nosound();
sound( 1000 );
delay( 100 );
nosound();
cleardevice();
char opp[14],k[15],p[15],run_rate[10];
char menu_opt[8][14]={"IND","WI","PAK","ENG","NZ","AUS","SL","SA"};

	int min = 70, max = 140, r,n=8;
	float q;
	randomize();
	do{
	a[0]=random(n);
	strcpy(opp,menu_opt[a[0]]);
	}
	while(strcmp(opp,menu_opt[select-1])==0);
	srand(time(NULL));
	r = (rand() % (max + 1 - min)) + min;
	itoa( r , k , 10 );
	target1=r+1;
	itoa( target1 , p , 10 );
	q=target1/20;
	sprintf( run_rate , "%f" , q );
	setbkcolor( 14 );
	settextstyle( 10 , 0 , 3 );
	setcolor( 2 );
	outtextxy( 150 , 20 , menu_opt[select-1] );
	outtextxy(260 , 20 , "VS" );
	outtextxy( 370 , 20 , opp );
	outtextxy( 30 , 120 , opp );
	outtextxy( 110 , 120 , "scored" );
	outtextxy( 240 , 120 , k );
	outtextxy( 320 , 120 , "runs in 20 overs" );
	outtextxy( 150 , 190 , "Target:" );
	outtextxy( 280 , 190 , p );
	outtextxy( 110 , 260 , "Required Run Rate:" );
	outtextxy( 450 , 260 , run_rate );
	outtextxy( 130 , 340 , "Good Luck !!!" );
	getch();
}

void cricket::teams(int select)
{
sound( 520 );
delay( 100 );
nosound();
sound( 1000 );
delay( 100 );
nosound();
cleardevice();
char indbat[11][50]={"DHAWAN","ROHIT","KOHLI","RAHANE","RAINA","DHONI",
"JADEJA","ASHWIN","SHAMI","YADHAV","BHUVI"};

char wibat[11][50]={"GAYLE","SMITH","SAMUELS","SIMMONS","BRAVO","SAMMY",
"RUSSELL","RAMDIN","BENN","HOLDER","NARINE"};

char pakbat[11][50]={"SHEHZAD","HAFEEZ","AHEMAD","MISBAH","YOUNIS",
"AKMAL","AFRIDI","YASIR","RIAZ","SOHAIL","IRFAN"};
char engbat[11][50]={"COOK","BELL","ROOT","HALES","MORGAN","BUTTLER",
"BALLANCE","ALI","SWANN","WOAKES","JORDAN"};

char nzbat[11][50]={"McCULLUM","GUPTILL","WILLIAMSON","TAYLOR",
"ANDERSON","RONCHI","SANTNER","SODHI","BOULT","SOUTHEE","McCLENAGHAN"};

char ausbat[11][50]={"WARNER","FINCH","SMITH","CLARKE","MAXWELL",
"WATSON","HADDIN","FAULKNER","CUMMINS","JOHNSON","STARC"};

char slbat[11][50]={"THRIMANNE","CHANDIMAL","DILSHAN","SANGAKKARA","HERATH",
"JAYAWARDENE","MATHEWS","PERERA","SENANAYAKE","KULASEKARA","MALINGA"};

char sabat[11][50]={"de KOCK","AMLA","du PLESSIS","de VILLIERS","MILLER",
"DUMINY","TAHIR","PHILANDER","PARNELL","MORKEL","STEYN"};


char indbowl[5][50]={"YADHAV","SHAMI","ASHWIN","JADEJA","BHUVI"};
char wibowl[5][50]={"HOLDER","RUSSELL","NARINE","BENN","BRAVO"};
char pakbowl[5][50]={"IRFAN","RIAZ","YASIR","AFRIDI","SOHAIL"};
char engbowl[5][50]={"HALES","JORDAN","SWANN","ALI","WOAKES"};
char nzbowl[5][50]={"BOULT","SOUTHEE","SODHI","SANTNER","ANDERSON"};
char ausbowl[5][50]={"STARC","JOHNSON","CLARKE","MAXWELL","FAULKNER"};
char slbowl[5][50]={"MALINGA","KULASEKARA","SENANAYAKE","HERATH","PERARA"};
char sabowl[5][50]={"STEYN","MORKEL","TAHIR","DUMINY","PHILANDER"};
int b,l;
if( select==1 )
{
for( b=0; b<11; b++ )
{
strcpy( batnames[b] , indbat[b] );
}
}
else if( select==2 )
{
for( b=0; b<11; b++ )
{
strcpy( batnames[b] , wibat[b] );
}
}
else if( select==3 )
	{
	for( b=0; b<11; b++ )
	{
	strcpy( batnames[b] , pakbat[b] );
	}
	}
	else if( select==4 )
	{
	for( b=0; b<11; b++ )
	{
	strcpy( batnames[b] , engbat[b] );
	}
	}
	else if( select==5 )
	{
		for( b=0; b<11; b++ )
		{
		strcpy( batnames[b] , nzbat[b] );
		}
	}
	else if( select==6 )
	{
		for( b=0 ; b<11; b++)
		{
		strcpy( batnames[b] , ausbat[b] );
		}
	}
	else if( select==7 )
	{
		for( b=0; b<11; b++)
		{
		strcpy( batnames[b] , slbat[b] );
		}
	}
	else if( select==8 )
	{
		for( b=0; b<11; b++ )
		{
		strcpy( batnames[b] , sabat[b] );
		}
	}
	if( a[0]==0 )
	{
		for( l=0; l<5; ++l )
		{
		strcpy( bowlnames[l] , indbowl[l] );
		}
	}
	else if( a[0]==1 )
	{
		for( l=0; l<5; ++l )
		{
		strcpy( bowlnames[l] , wibowl[l] );
		}
	}
	else if( a[0]==2 )
	{
		for( l=0; l<5; ++l )
		{
		strcpy( bowlnames[l] , pakbowl[l] );
		}
	}
	else if( a[0]==3 )
	{
		for( l=0; l<5; ++l )
		{
		strcpy( bowlnames[l] , engbowl[l] );
		}
	}
	else if( a[0]==4 )
	{
		for( l=0; l<5; ++l )
		{
		strcpy( bowlnames[l] , nzbowl[l] );
		}
	}
	else if( a[0]==5 )
	{
		for( l=0; l<5; ++l )
		{
		strcpy( bowlnames[l] , ausbowl[l] );
		}
	}
	else if( a[0]==6 )
	{
		for( l=0; l<5; ++l )
		{
		strcpy( bowlnames[l] , slbowl[l] );
		}
	}
	else if( a[0]==7 )
	{
		for( l=0; l<5; ++l )
		{
		strcpy( bowlnames[l] , sabowl[l] );
		}
	}
	int y1=110,y2=110;
	settextstyle( 1 , 0 , 6 );
	setbkcolor( 0 );
	setcolor( 13 );
	outtextxy( 10 , 20 , "Your team consists of :" );
	setcolor( 10 );
	settextstyle( 1 , 0 , 3 );
	for( int k=0;k<6;k++ )
	{
		outtextxy( 10 , y1 , batnames[k] );
		y1+=45;
	}
	for( k=0; k<5; k++ )
	{
		outtextxy( 200 , y2 , batnames[k+6] );
		y2+=45;
	}
	setcolor( 14 );
	settextstyle( 1 , 0 , 4 );
	outtextxy( 200 , 350 , "Press any key to continue" );
	getch();
	score( select );
}

void cricket::score(int select)
{
sound(520);
delay(100);
nosound();
sound(1000);
delay(100);
nosound();
char bowltype[20];
char menu_opt[8][14]={"IND","WI","PAK","ENG","NZ","AUS","SL","SA"};
int k=0;
char run1[10],wicket1[10],run_rem1[10],overs1[10],k1[10],target2[10],run3[10];
int no_of_balls,overs,run_rem;
run = wicket = run4 = run2 = m = ab = overs = 0;
no_of_balls=120;
for(int i=1;i<=no_of_balls && wicket<10 && run<target1;i++)
	{
		Again:
		ground();
		batsman( select );
		stumps();
		setfillstyle( 1 , RED );
		bar( 0 , getmaxy() , getmaxx() , getmaxy()-20 );
		setcolor( WHITE );
		line( 120 , getmaxy()-20 , 120 , getmaxy() );
		run_rem=target1-run;
		settextstyle(1 , 0 , 2 );
		outtextxy( 10 , getmaxy()-23 , menu_opt[select-1] );
		itoa( run , run1 , 10 );
		itoa( wicket , wicket1 , 10 );
		itoa( run_rem , run_rem1 , 10 );
		itoa( target1 , target2 , 10 );
		itoa( overs , overs1 , 10 );
		itoa( run2 , run3 , 10 );
		itoa( k , k1 , 10 );
		outtextxy( 55 , getmaxy()-23 , run1 );
		outtextxy( 93 , getmaxy()-23 , "/" );
		outtextxy( 105 , getmaxy()-23 , wicket1 );
		outtextxy( 430 , getmaxy()-23 , "TARGET" );
		outtextxy( 520 , getmaxy()-23 , target2 );
		outtextxy( 130 , getmaxy()-23 , "OVERS" );
		outtextxy( 200 , getmaxy()-23 , overs1 );
		outtextxy( 215 , getmaxy()-23 , "." );
		outtextxy( 225 , getmaxy()-23 , k1 );
		outtextxy( 260 , getmaxy()-23 , batnames[m] );
		outtextxy( 385 , getmaxy()-23 , run3 );
		if( run4>=50 )
		{
			for(int i=0;i<150;i++)
			{
				setfillstyle( 1 , 15 );
				bar( 150 , 150 , 150+i+235 , 150+i );
				delay( 3 );
			}
			setcolor( 4 );
			settextstyle( 3 , 0 , 3 );
			outtextxy( 160 , 170 , "Excellant batting from" );
			outtextxy( 415 , 170 , batnames[m] );
			outtextxy( 200 , 220 , "Keep it up !!! ");
			run4 = 0;
			getch();
			goto Again;
		}
		setfillstyle( 1 , 1 );
		bar( getmaxx()-200 , 0 , getmaxx() , 25 );
		setcolor( YELLOW );
		if(overs<6)
		{
		if(overs%2==0)
		bowler=1;
		else
		bowler=2;
		}
		else if(overs<12)
		{
			if(overs%2==0)
				bowler=3;
			else
				bowler=4;
		}
		else
		{
			if(overs%2==0)
			{
				if(overs==12)
					bowler=1;
				else if(overs==14)
					bowler=2;
				else if(overs==16)
					bowler=3;
				else
					bowler=4;
			}
			else
				bowler=5;
		}
		if( bowler==1 )
			strcpy( bowltype , "Fast outswing" );
		else if( bowler==2 )
			strcpy(bowltype,"Fast inswing");
		else if(bowler==3)
			strcpy(bowltype,"Legspin");
		else if(bowler==4)
			strcpy(bowltype,"Offspin");
		else if(bowler==5)
			strcpy(bowltype,"Medium");
		settextstyle(3,0,1);
		outtextxy(getmaxx()-195,1,bowltype);
		outtextxy(getmaxx()-73,1,bowlnames[bowler-1]);
		setfillstyle(1,15);
		if(bowler==1)
		{
			outswing();
			move_batsman(select);
			boundaries();
		}
		else if(bowler==2)
		{
			inswing();
			move_batsman(select);
			boundaries();
		}
		else if(bowler==3)
		{
			legspin();
			move_batsman(select);
			boundaries();
		}
		else if(bowler==4)
		{
			offspin();
			move_batsman(select);
			boundaries();
		}
		else if(bowler==5)
		{
			medium();
			move_batsman(select);
			boundaries();

		}
		delay(1000);
		k++;
		if(i%6==0)
		{
			for(int i=0;i<125;i++)
			{
				setfillstyle(1,15);
				bar(200,100,200+i,100+i);
				delay(3);
				bar(200,225,200+i,225+i);
				delay(3);
				bar(325,100,325+i,100+i);
				delay(3);
				bar(325,225,325+i,225+i);
				delay(3);
			}
			setcolor(4);
			settextstyle(3,0,3);
			outtextxy(230,130,"END OF THE OVER");
			outtextxy(230,180,"LAST OVER:");
			outtextxy(230,205,bowlnames[bowler-1]);
			outtextxy(230,230,bowltype);
			outtextxy(230,280,"TO WIN");
			outtextxy(320,280,run_rem1);
			overs++;
			k=0;
			getch();
		}
	}
	if(run<target1)
	{
	scoreboard();
	defeat();
	}
	if(run>target1)
	{
	scoreboard();
	victory();
	}
}

void cricket::victory()
{
	cleardevice();
	int i=0;
	setbkcolor(WHITE);
	setcolor(GREEN);
	settextstyle(1,0,4);
	outtextxy(20,50,"YOU WIN!!!");
	delay(1000);
	outtextxy(20,100,"KEEP IT UP....");
	outtextxy(20,150,"AND GRAB THE TROPHY!!!");
	delay(750);
	setfillstyle(1,8);
	setfillstyle(1,YELLOW);
	setcolor(8);
	pieslice(250,240,0,360,25);
	setcolor(8);
	for(i=155;i<166;i++)
	arc(248,i,249,295,80);
	for(i=80;i<86;i++)
	arc(i,270,330,12,200);
	for(i=415;i<421;i++)
	arc(i,270,168,210,200);
	arc(250,240,245,295,25);
	for(i=240;i<261;i++)
	{
		line(i,264,246,370);
		line(i,264,253,370);
	}
	for(i=246;i<253;i++)
	line(i,264,i,370);
	setfillstyle(1,YELLOW);
	pieslice(249,400,0,180,30);
	setfillstyle(1,8);
	setcolor(8);
	pieslice(250,390,0,360,6);
	pieslice(230,387,0,360,6);
	pieslice(268,387,0,360,6);
	settextstyle(1,0,3);
	delay(500);
	setcolor(GREEN);
	outtextxy(100,420,"Press any key to continue");
}

void cricket::defeat()
{
	cleardevice();
	setbkcolor(WHITE);
	settextstyle(1,0,4);
	setcolor(RED);
	outtextxy(20,50,"YOU LOSE");
	delay(1000);
	outtextxy(20,150,"BETTER LUCK NEXT TIME...");
	settextstyle(1,0,3);
	delay(500);
	outtextxy(100,390,"Press any key to continue");
}

void cricket::ground()
{
	int poly[8]={255,65,373,65,470,442,154,442};
	cleardevice();
	setcolor(4);
	setbkcolor(2);    //.......ground.........//
	setcolor(2);
	setfillstyle(1,6);
	fillpoly(4,poly);  //.......pitch..........//
	setcolor(15);
	line(358,85,355,65); //...bowling side lines...//
	line(270,85,273,65);
	line(307,41,320,41);  //...bowling stumps bails...//
	line(307,40,320,40);
	line(401,365,416,442); //...side lines...//
	line(400,365,415,442);
	line(231,365,211,442);
	line(230,365,210,442);
	line(175,366,450,366);   //...crease...//
	line(175,365,450,365);
	line(250,85,378,85);    //...bowling crease...//
	line(319,65,319,40);    //...bowling stumps...//
	line(320,65,320,40);
	line(313,65,313,40);
	line(314,65,314,40);
	line(307,65,307,40);
	line(308,65,308,40);
	setfillstyle(1,11);
	bar(0,0,220,25);
	setcolor(5);
	settextstyle(2,0,5);
	outtextxy(5,3,"Press ESC to pause the game");
}

void cricket::stumps()
{
	setcolor(15);
	line(293,442,293,375);  //batting stumps
	line(295,442,295,375);
	line(313,442,313,375);
	line(315,442,315,375);
	line(333,442,333,375);
	line(335,442,335,375);
	line(294,375,334,375);   //batting stump bails
	line(294,376,334,376);
}

void cricket::move_ball()
{
	static int r = 20;
	static int StartX = 100;
	static int StartY = 50;
	int ulx, uly, lrx, lry, size;
	struct viewporttype vp;
	getviewsettings( &vp );
	setfillstyle(1,2);
	setcolor(2);
	pieslice(StartX,StartY,0,360,7);
	setcolor(9);
	arc(StartX+10,StartY+5,110,187,10);
	arc(StartX+7,StartY+5,100,180,12);

	/* Read ball image */
	ulx = StartX-(r+1);
	uly = StartY-14;
	lrx = StartX+(r+1);
	lry = StartY+(r/3)+3;
	size = imagesize(ulx, uly, lrx, lry);

	ball = malloc( size );
	getimage(ulx, uly, lrx, lry, ball);
	putimage(ulx, uly, ball, XOR_PUT);
}

void cricket::outswing()
{
	move_ball();
	int x1=320,g,g1,max=1,min=0,max1=360,min1=201;
	x2=320;
	srand(time(NULL));
	g = (rand() % (max + 1 - min)) + min;
	g1 = (rand() % (max1 + 1 - min1)) + min1;
	start = clock();
	for(y2=25;y2<g1;y2+=5)
	{
	    x1-=g;
	}
	setfillstyle(1,YELLOW);
	setcolor(BROWN);
	fillellipse(x1+20,g1,10,5);
	delay(400);
	setcolor(BROWN);
	setfillstyle(1,BROWN);
	fillellipse(x1+20,g1,10,5);
	for(y2=25;y2<g1;y2+=5)
	{
		x2-=g;
		putimage(x2, y2, ball, XOR_PUT);
		delay(17);
		putimage(x2, y2, ball, XOR_PUT);
	}
	for(y2=g1;y2<400;y2+=5)
	{
	x2+=2;
	putimage(x2, y2, ball, XOR_PUT);
	delay(17);
	putimage(x2, y2, ball, XOR_PUT);
	if(kbhit())
	{
	acc=getch();
	if(acc==UP_ARROW||acc==RIGHT_ARROW||acc==LEFT_ARROW)
	break;
	else if(acc==ESC)
	pause();
	}
	}
	end = clock();
	o=(end-start)/CLK_TCK;
	free(ball);
}

void cricket::legspin()
{
	move_ball();
	int x1=320,g,g1,max=1,min=0,max1=360,min1=201;
	x2=320;
	srand(time(NULL));
	g = (rand() % (max + 1 - min)) + min;
	g1 = (rand() % (max1 + 1 - min1)) + min1;
	start = clock();
	for(y2=25;y2<g1;y2+=5)
	{
	    if(y2%10==0)
	    x1-=g;
	}
	setfillstyle(1,YELLOW);
	setcolor(BROWN);
	fillellipse(x1+20,g1,10,5);
	delay(400);
	setcolor(BROWN);
	setfillstyle(1,BROWN);
	fillellipse(x1+20,g1,10,5);
	for(y2=25;y2<g1;y2+=5)
	{
		if(y2%10==0)
		x2-=g;
		putimage(x2, y2, ball, XOR_PUT);
		delay(17);
		putimage(x2, y2, ball, XOR_PUT);
	}
	for(y2=g1;y2<400;y2+=5)
	{
		x2+=2;
		putimage(x2, y2, ball, XOR_PUT);
		delay(23);
		putimage(x2, y2, ball, XOR_PUT);
		if(kbhit())
		{
		acc=getch();
		if(acc==UP_ARROW||acc==RIGHT_ARROW||acc==LEFT_ARROW)
		break;
		else if(acc==ESC)
		pause();
		}
	}
	end = clock();
	o=(end-start)/CLK_TCK;
	free(ball);
}

void cricket::medium()
{
	move_ball();
	int x1=320,g1,max1=360,min1=201;
	x2=320;
	srand(time(NULL));
	g1 = (rand() % (max1 + 1 - min1)) + min1;
	start = clock();
	for(y2=25;y2<g1;y2+=5)
	{
	    if(y2%10==0)
	    x1--;
	}
	setfillstyle(1,YELLOW);
	setcolor(BROWN);
	fillellipse(x1+20,g1,10,5);
	delay(400);
	setcolor(BROWN);
	setfillstyle(1,BROWN);
	fillellipse(x1+20,g1,10,5);
	for(y2=25;y2<g1;y2+=5)
	{
		if(y2%10==0)
		x2--;
		putimage(x2, y2, ball, XOR_PUT);
		delay(20);
		putimage(x2, y2, ball, XOR_PUT);
	}
	for(y2=g1;y2<400;y2+=5)
	{
		if(y2%10==0)
		x2++;
		putimage(x2, y2, ball, XOR_PUT);
		delay(20);
		putimage(x2, y2, ball, XOR_PUT);
		if(kbhit())
		{
		acc=getch();
		if(acc==UP_ARROW||acc==RIGHT_ARROW||acc==LEFT_ARROW)
		break;
		else if(acc==ESC)
		pause();
		}
	}
	end = clock();
	o=(end-start)/CLK_TCK;
	free(ball);
}

void cricket::inswing()
{
	move_ball();
	int x1=320,g1,max1=360,min1=201;
	x2=320;
	srand(time(NULL));
	g1 = (rand() % (max1 + 1 - min1)) + min1;
	start = clock();
	for(y2=25;y2<g1;y2+=5)
	{
	    if(y2%10==0)
	    x1++;
	}
	setfillstyle(1,YELLOW);
	setcolor(BROWN);
	fillellipse(x1+20,g1,10,5);
	delay(400);
	setcolor(BROWN);
	setfillstyle(1,BROWN);
	fillellipse(x1+20,g1,10,5);
	for(y2=25;y2<g1;y2+=5)
	{
		if(y2%10==0)
		x2++;
		putimage(x2, y2, ball, XOR_PUT);
		delay(17);
		putimage(x2, y2, ball, XOR_PUT);
	}
	for(y2=g1;y2<400;y2+=5)
	{
		x2-=2;
		putimage(x2, y2, ball, XOR_PUT);
		delay(17);
		putimage(x2, y2, ball, XOR_PUT);
		if(kbhit())
		{
		acc=getch();
		if(acc==UP_ARROW||acc==RIGHT_ARROW||acc==LEFT_ARROW)
		break;
		else if(acc==ESC)
		pause();
		}
	}
	end = clock();
	o=(end-start)/CLK_TCK;
	free(ball);
}

void cricket::offspin()
{
	move_ball();
	int x1=320,g1,max1=360,min1=201;
	x2=320;
	srand(time(NULL));
	g1 = (rand() % (max1 + 1 - min1)) + min1;
	start = clock();
	for(y2=25;y2<g1;y2+=5)
	{
	    if(y2%10==0)
	    x1++;
	}
	setfillstyle(1,YELLOW);
	setcolor(BROWN);
	fillellipse(x1+20,g1,10,5);
	delay(400);
	setcolor(BROWN);
	setfillstyle(1,BROWN);
	fillellipse(x1+20,g1,10,5);
	for(y2=25;y2<g1;y2+=5)
	{
		if(y2%10==0)
		x2++;
		putimage(x2, y2, ball, XOR_PUT);
		delay(17);
		putimage(x2, y2, ball, XOR_PUT);
	}
	for(y2=g1;y2<400;y2+=5)
	{
		x2-=2;
		putimage(x2, y2, ball, XOR_PUT);
		delay(23);
		putimage(x2, y2, ball, XOR_PUT);
		if(kbhit())
		{
		acc=getch();
		if(acc==UP_ARROW||acc==RIGHT_ARROW||acc==LEFT_ARROW)
		break;
		else if(acc==ESC)
		pause();
		}
	}
	end = clock();
	o=(end-start)/CLK_TCK;
	free (ball);
}

void cricket::boundaries()
{
	static int r = 20;
	static int StartX = 100;
	static int StartY = 50;
	int ulx, uly, lrx, lry, size;
	setcolor(1);
	settextstyle(3,0,9);
	if(o<1.4)
	{
		settextstyle(3,0,6);
		outtextxy(getmaxx()/2-80,getmaxy()/2-80,"CATCH");
		wicket++;
		m++;
		if(bowler==1)
			wicket1[0]+=1;
		else if(bowler==2)
			wicket1[1]+=1;
		else if(bowler==3)
			wicket1[2]+=1;
		else if(bowler==4)
			wicket1[3]+=1;
		else if(bowler==5)
			wicket1[4]+=1;
		run5[ab]=run2;
		ab++;
		run2=0;
		run4=0;
	}
	else if(o>=1.4 && o<1.48)
	{
		int g,max=7,min=1;
		srand(time(NULL));
		g = (rand() % (max + 1 - min)) + min;
		for(int i=0;i<27;i++)
		{
			putimage(x2, y2, ball, XOR_PUT);
			delay(18);
			putimage(x2, y2, ball, XOR_PUT);
			if(acc==LEFT_ARROW)
			{
				x2-=5;
				y2-=g;
			}
			if(acc==RIGHT_ARROW)
			{
				x2+=5;
				y2-=g;
			}
			if(acc==UP_ARROW)
			{
				x2+=0;
				y2-=3;
			}
		}
		outtextxy(getmaxx()/2-20,getmaxy()/2-80,"1");
		run++;
		run2++;
		run4++;
	}
	else if(o>=1.48 && o<1.53)
	{
		int g,max=7,min=1;
		srand(time(NULL));
		g = (rand() % (max + 1 - min)) + min;
		for(int i=0;i<27;i++)
		{
			putimage(x2, y2, ball, XOR_PUT);
			delay(18);
			putimage(x2, y2, ball, XOR_PUT);
			if(acc==LEFT_ARROW)
			{
				x2-=5;
				y2-=g;
			}
			if(acc==RIGHT_ARROW)
			{
				x2+=5;
				y2-=g;
			}
			if(acc==UP_ARROW)
			{
				x2+=0;
				y2-=6;
			}
		}
		setfillstyle(1,RED);
		setcolor(RED);
		pieslice(StartX,StartY,0,360,7);
		setcolor(15);
		arc(StartX+10,StartY+5,110,187,10);
		arc(StartX+7,StartY+5,100,180,12);

		/* Read ball image */
		ulx = StartX-(r+1);
		uly = StartY-14;
		lrx = StartX+(r+1);
		lry = StartY+(r/3)+3;
		size = imagesize(ulx, uly, lrx, lry);

		ball = malloc( size );
		getimage(ulx, uly, lrx, lry, ball);
		putimage(ulx, uly, ball, XOR_PUT);
		for(i=27;i<35;i++)
		{
			putimage(x2, y2, ball, XOR_PUT);
			delay(17);
			putimage(x2, y2, ball, XOR_PUT);
			if(acc==LEFT_ARROW)
			{
				x2-=5;
				y2-=g;
			}
			if(acc==RIGHT_ARROW)
			{
				x2+=5;
				y2-=g;
			}
			if(acc==UP_ARROW)
			{
				x2+=0;
				y2-=6;
			}
		}
		setcolor(1);
		outtextxy(getmaxx()/2-20,getmaxy()/2-80,"2");
		run+=2;
		run2+=2;
		run4+=2;
	}
	else if(o>=1.53 && o<1.59)
	{
		int g,max=7,min=1;
		srand(time(NULL));
		g = (rand() % (max + 1 - min)) + min;
		for(int i=0;i<24;i++)
		{
			putimage(x2, y2, ball, XOR_PUT);
			delay(18);
			putimage(x2, y2, ball, XOR_PUT);
			if(acc==LEFT_ARROW)
			{
				x2-=5;
				y2-=g;
			}
			if(acc==RIGHT_ARROW)
			{
				x2+=5;
				y2-=g;
			}
			if(acc==UP_ARROW)
			{
				x2+=0;
				y2-=8;
			}
		}
		setfillstyle(1,RED);
		setcolor(RED);
		pieslice(StartX,StartY,0,360,7);
		setcolor(15);
		arc(StartX+10,StartY+5,110,187,10);
		arc(StartX+7,StartY+5,100,180,12);

		/* Read ball image */
		ulx = StartX-(r+1);
		uly = StartY-14;
		lrx = StartX+(r+1);
		lry = StartY+(r/3)+3;
		size = imagesize(ulx, uly, lrx, lry);

		ball = malloc( size );
		getimage(ulx, uly, lrx, lry, ball);
		putimage(ulx, uly, ball, XOR_PUT);
		for(i=24;i<70;i++)
		{
			putimage(x2, y2, ball, XOR_PUT);
			delay(17);
			putimage(x2, y2, ball, XOR_PUT);
			if(acc==LEFT_ARROW)
			{
				x2-=5;
				y2-=g;
			}
			if(acc==RIGHT_ARROW)
			{
				x2+=5;
				y2-=g;
			}
			if(acc==UP_ARROW)
			{
				x2+=0;
				y2-=8;
			}
		}
		setcolor(1);
		outtextxy(getmaxx()/2-20,getmaxy()/2-80,"4");
		run+=4;
		run2+=4;
		run4+=4;
	}
	else if(o>=1.59 && o<1.6)
	{
		setcolor(14);
		for(int i=20;i>1;i--)
		{
			if(acc==RIGHT_ARROW)
			{
				arc(getmaxx(),y2+i,90,180,getmaxx()-x2-20);
				delay(10);
			}
			else if(acc==UP_ARROW)
			{
				line(x2+15,y2+5,getmaxx()/2+i,0);
				delay(10);
			}
			else if(acc==LEFT_ARROW)
			{
				arc(20,y2+i,0,120,0+x2);
				delay(10);
			}
		}
		setcolor(1);
		outtextxy(getmaxx()/2-20,getmaxy()/2-80,"6");
		run+=6;
		run2+=6;
		run4+=6;
	}
	if(o>=1.6)
	{
		if((x2>=260 && x2<=334) && (y2>=360 && y2<=442))
		{
			outtextxy(getmaxx()/2-80,getmaxy()/2-80,"OUT");
			setcolor(15);
			line(294,360,310,340);  //hitting the stumps
			line(360,360,334,350);
			line(360,360,334,350);
			line(361,360,335,350);
			setcolor(BROWN);
			line(313,442,313,375);
			line(315,442,315,375);
			line(294,375,334,375);
			line(294,376,334,376);
			wicket++;
			m++;
			if(bowler==1)
				wicket1[0]+=1;
			else if(bowler==2)
				wicket1[1]+=1;
			else if(bowler==3)
				wicket1[2]+=1;
			else if(bowler==4)
				wicket1[3]+=1;
			else if(bowler==5)
				wicket1[4]+=1;
			run5[ab]=run2;
			ab++;
			run2=0;
			run4=0;
		}
		else
		{
			settextstyle(3,0,5);
			outtextxy(getmaxx()/2-80,getmaxy()/2-80,"NO RUN");
		}
	}
}

void cricket::scoreboard()
{
	cleardevice();
	setbkcolor(0);
	settextstyle(7,0,3);
	setcolor(12);
	outtextxy(getmaxx()/2-100,20,"Batting Statistics");
	settextstyle(1,0,1);
	setcolor(10);
	int i=70;
	char run6[10],wicket2[10];
	for(int b=0;b<10;b++)
	{
		outtextxy(150,i,batnames[b]);
		itoa(run5[b],run6,10);
		outtextxy(450,i,run6);
		i+=40;
	}
	getch();
	cleardevice();
	settextstyle(7,0,3);
	setcolor(12);
	outtextxy(getmaxx()/2-100,20,"Bowling Statistics");
	i=90;
	settextstyle(1,0,2);
	setcolor(10);
	for(b=0;b<5;b++)
	{
		outtextxy(150,i,bowlnames[b]);
		itoa(wicket1[b],wicket2,10);
		outtextxy(450,i,wicket2);
		i+=40;
	}
	getch();
}

void cricket::batsman(int select)
{
	int foot[10]={290,400,305,400,303,395,293,390,288,390};
	int legs[8]={288,390,293,390,290,355,275,355};
	int hip[8]={275,355,290,355,302,320,285,320};
	int arm[8]={300,325,295,340,303,350,311,350};
	int grip[8]={306,358,312,359,310,350,304,350};
	int bat[8]={307,400,319,397,315,357,303,360};
	if(select==1)
	{
		setcolor(9);
		setfillstyle(1,9);
		fillpoly(4,legs);
		setcolor(9);
		setfillstyle(1,9);
		fillpoly(4,hip);
	}
	if(select==2)
	{
		setcolor(4);
		setfillstyle(1,4);
		fillpoly(4,legs);
		setcolor(4);
		setfillstyle(1,4);
		fillpoly(4,hip);
	}
	if(select==3)
	{
		setcolor(2);
		setfillstyle(1,2);
		fillpoly(4,legs);
		setcolor(2);
		setfillstyle(1,2);
		fillpoly(4,hip);
	}
	if(select==4)
	{
		setcolor(12);
		setfillstyle(1,12);
		fillpoly(4,legs);
		setcolor(12);
		setfillstyle(1,12);
		fillpoly(4,hip);
	}
	if(select==5)
	{
		setcolor(8);
		setfillstyle(1,8);
		fillpoly(4,legs);
		setcolor(8);
		setfillstyle(1,8);
		fillpoly(4,hip);
	}
	if(select==6)
	{
		setcolor(14);
		setfillstyle(1,14);
		fillpoly(4,legs);
		setcolor(14);
		setfillstyle(1,14);
		fillpoly(4,hip);
	}
	if(select==7)
	{
		setcolor(1);
		setfillstyle(1,1);
		fillpoly(4,legs);
		setcolor(1);
		setfillstyle(1,1);
		fillpoly(4,hip);
	}
	if(select==8)
	{
		setcolor(10);
		setfillstyle(1,10);
		fillpoly(4,legs);
		setcolor(10);
		setfillstyle(1,10);
		fillpoly(4,hip);
	}
	setcolor(7);
	setfillstyle(1,7);
	fillpoly(4,arm);
	setcolor(15);
	setfillstyle(1,15);
	fillpoly(5,foot);
	setfillstyle(1,8);
	setcolor(8);
	fillpoly(4,bat);
	setcolor(3);
	setfillstyle(1,3);
	fillpoly(4,grip);
	setcolor(1);
	setfillstyle(1,17);
	pieslice(293,307,0,180,10);		//helmet
	setfillstyle(1,7);
	setcolor(7);
	sector(293,307,180,360,8,17);
}

void cricket::move_batsman(int select)
{
	int foot[10]={290,400,305,400,303,395,293,390,288,390};
	int legs[8]={288,390,293,390,290,355,275,355};
	int hip[8]={275,355,290,355,302,320,285,320};
	int arm[8]={300,325,295,340,303,350,311,350};
	int grip[8]={306,358,312,359,310,350,304,350};
	int bat[8]={307,400,319,397,315,357,303,360};

	for(int i=0;i<9;i++)
	{
		if(select==1)
		{
			setcolor(9);
			setfillstyle(1,9);
			fillpoly(4,legs);
			setcolor(9);
			setfillstyle(1,9);
			fillpoly(4,hip);
		}
		if(select==2)
		{
			setcolor(4);
			setfillstyle(1,4);
			fillpoly(4,legs);
			setcolor(4);
			setfillstyle(1,4);
			fillpoly(4,hip);
		}
		if(select==3)
		{
			setcolor(2);
			setfillstyle(1,2);
			fillpoly(4,legs);
			setcolor(2);
			setfillstyle(1,2);
			fillpoly(4,hip);
		}
		if(select==4)
		{
			setcolor(12);
			setfillstyle(1,12);
			fillpoly(4,legs);
			setcolor(12);
			setfillstyle(1,12);
			fillpoly(4,hip);
		}
		if(select==5)
		{
			setcolor(8);
			setfillstyle(1,8);
			fillpoly(4,legs);
			setcolor(8);
			setfillstyle(1,8);
			fillpoly(4,hip);
		}
		if(select==6)
		{
			setcolor(14);
			setfillstyle(1,14);
			fillpoly(4,legs);
			setcolor(14);
			setfillstyle(1,14);
			fillpoly(4,hip);
		}
		if(select==7)
		{
			setcolor(1);
			setfillstyle(1,1);
			fillpoly(4,legs);
			setcolor(1);
			setfillstyle(1,1);
			fillpoly(4,hip);
		}
		if(select==8)
		{
			setcolor(10);
			setfillstyle(1,10);
			fillpoly(4,legs);
			setcolor(10);
			setfillstyle(1,10);
			fillpoly(4,hip);
		}
		setcolor(15);
		setfillstyle(1,15);

		fillpoly(5,foot);
		setcolor(1);
		setfillstyle(1,1);
		pieslice(293,307,0,180,10);
		setfillstyle(1,7);
		setcolor(7);
		sector(293,307,180,360,8,17);
		if(acc==RIGHT_ARROW)
		{
			bat[0]=bat[0]+i;
			bat[1]=bat[1]-i;
			bat[2]=bat[2]+i;
			bat[3]=bat[3]-i;
			bat[4]=bat[4]+i;
			bat[5]=bat[5]-i;
			bat[6]=bat[6]+i;
			bat[7]=bat[7]-i;
			arm[4]=arm[4]+i;
			arm[5]=arm[5]-i;
			arm[6]=arm[6]+i;
			arm[7]=arm[7]-i;
			grip[0]=grip[0]+i;
			grip[1]=grip[1]-i;
			grip[2]=grip[2]+i;
			grip[3]=grip[3]-i;
			grip[4]=grip[4]+i;
			grip[5]=grip[5]-i;
			grip[6]=grip[6]+i;
			grip[7]=grip[7]-i;

			fillpoly(4,arm);
			setfillstyle(1,8);
			setcolor(8);
			fillpoly(4,bat);
			setcolor(3);
			setfillstyle(1,3);
			fillpoly(4,grip);
			delay(30);
			if(i<7)
			{
				setfillstyle(1,BROWN);
				setcolor(BROWN);
				fillpoly(4,arm);
				fillpoly(4,bat);
				fillpoly(4,grip);
			}
			stumps();
		}
		else if(acc==LEFT_ARROW)
		{
			bat[0]=bat[0]-i;
			bat[1]=bat[1]-i;
			bat[2]=bat[2]-i;
			bat[3]=bat[3]-i;
			bat[4]=bat[4]-i;
			bat[5]=bat[5]-i;
			bat[6]=bat[6]-i;
			bat[7]=bat[7]-i;
			arm[4]=arm[4]-i;
			arm[5]=arm[5]-i;
			arm[6]=arm[6]-i;
			arm[7]=arm[7]-i;
			grip[0]=grip[0]-i;
			grip[1]=grip[1]-i;
			grip[2]=grip[2]-i;
			grip[3]=grip[3]-i;
			grip[4]=grip[4]-i;
			grip[5]=grip[5]-i;
			grip[6]=grip[6]-i;
			grip[7]=grip[7]-i;

			fillpoly(4,arm);
			setfillstyle(1,8);
			setcolor(8);
			fillpoly(4,bat);
			setcolor(3);
			setfillstyle(1,3);
			fillpoly(4,grip);
			delay(30);
			if(i<7)
			{
				setfillstyle(1,BROWN);
				setcolor(BROWN);
				fillpoly(4,arm);
				fillpoly(4,bat);
				fillpoly(4,grip);
			}
			stumps();
		}
		else if(acc==UP_ARROW)
		{
			bat[1]=bat[1]-i;
			bat[3]=bat[3]-i;
			bat[5]=bat[5]-i;
			bat[7]=bat[7]-i;
			arm[5]=arm[5]-i;
			arm[7]=arm[7]-i;
			grip[1]=grip[1]-i;
			grip[3]=grip[3]-i;
			grip[5]=grip[5]-i;
			grip[7]=grip[7]-i;

			fillpoly(4,arm);
			setfillstyle(1,8);
			setcolor(8);
			fillpoly(4,bat);
			setcolor(3);
			setfillstyle(1,3);
			fillpoly(4,grip);
			delay(30);
			if(i<7)
			{
				setfillstyle(1,BROWN);
				setcolor(BROWN);
				fillpoly(4,arm);
				fillpoly(4,bat);
				fillpoly(4,grip);
			}
			stumps();
		}
		arm[4]=303;
		arm[5]=350;
		arm[6]=311;
		arm[7]=350;
		bat[0]=307;
		bat[1]=405;
		bat[2]=319;
		bat[3]=403;
		bat[4]=315;
		bat[5]=357;
		bat[6]=303;
		bat[7]=360;
		grip[0]=306;
		grip[1]=358;
		grip[2]=312;
		grip[3]=359;
		grip[4]=310;
		grip[5]=350;
		grip[6]=304;
		grip[7]=350;
	}
}

void cricket::pause()
{
	char ch;
	int select;
	for(int i=0;i<125;i++)
	{
		setfillstyle(1,15);
		bar(150,150,150+i+135,150+i);
		delay(3);
	}
	setcolor(4);
	settextstyle(6,0,5);
	outtextxy(160,140,"GAME PAUSED");
	settextstyle(1,0,2);
	outtextxy(160,200,"Press E to Exit");
	outtextxy(160,230,"Any key to Continue");
	ch= getch();
	if(ch=='E'||ch=='e')
	select_screen();
}

void main()
{
	int gdriver=DETECT,gmode;
	initgraph(&gdriver,&gmode,"C://TC//BGI");
	cricket c;
	c.welcome_screen();
}

/***************** I HOPE YOU LIKE THIS C PROGRAMMING *****************/

/*----------- LIKE  ------------ SHARE  ---------- SUBSCRIBE -----------*/

