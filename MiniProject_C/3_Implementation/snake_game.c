#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <process.h>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

int snake_length, bend_no, curr_len, health;
char input;
void recordScore();
void load();
void delay(long double);
void moveSnake();
void generateFood();
int getScore();
void createWorld();
void gotoxy(int x, int y);
void GotoXY(int x,int y);
void Bend();
void Boarder();
void goDown();
void goLeft();
void goUp();
void goRight();
void border();
int scoreDisplay();

struct position
{
    int x;
    int y;
    int direction;
};

typedef struct position position;

position head, bend[500], food, body[30]; //ACTIVITY//

int main()
{

    createWorld();

    system("cls"); //SYSTEM//

    load(); //LOAD//

    snake_length=5; //LENGTH OF SNAKE//

    head.x=25; //STEP TOWARDS 25//

    head.y=20; //STEP TOWARDS 20//

    head.direction=RIGHT; //DIRECTION TO THE RIGHT//

    Boarder();

    generateFood(); //to find score//

    health=3; //to find stability//

    bend[0]=head;

    moveSnake();   //direction of snake//

    return 0;

}

void moveSnake() //direction of snake//
{
    int a,i;

    do
    {

        generateFood(); // generate of food //
        fflush(stdin);

        curr_len=0; //CURRENT LENGTH//

        for(i=0; i<30; i++)

        {

            body[i].x=0; //NAVIGATION//

            body[i].y=0; //NAVIGATION//

            if(i==snake_length) // length of snake //

                break;

        }

        delay(snake_length); //LENGTH OF SNAKE//

        Boarder();

        if(head.direction==RIGHT) //move towards right//

            goRight();

        else if(head.direction==LEFT) //move towards left//

            goLeft();

        else if(head.direction==DOWN) //move towards down//

            goDown();

        else if(head.direction==UP) //move towards up//

            goUp();

        border();

    }
    while(!kbhit());

    a=getch();

    if(a==27) //TOWARDS 27//

    {

        system("cls"); //SYSTEM//

        exit(0);

    }
    input=getch();

    if((input==RIGHT&&head.direction!=LEFT&&head.direction!=RIGHT)||(input==LEFT&&head.direction!=RIGHT&&head.direction!=LEFT)||(input==UP&&head.direction!=DOWN&&head.direction!=UP)||(input==DOWN&&head.direction!=UP&&head.direction!=DOWN)) //DIRECTION OF SNAKE//

    {

        bend_no++;

        bend[bend_no]=head; //DIRECTION//

        head.direction=input; //headed towards direction//

        if(input==UP) //to the up//

            head.y--;

        if(input==DOWN) //to the down//

            head.y++;

        if(input==RIGHT) //to the right//

            head.x++;

        if(input==LEFT) //to the left//

            head.x--;

        moveSnake(); //ACTIVITY OF SNAKE//

    }

    else if(input==27)

    {

        system("cls");

        exit(0);

    }

    else

    {

        printf("\a"); //PRINT//

        moveSnake(); //activity of snake//

    }
}

void gotoxy(int x, int y)
{

    COORD coord;

    coord.X = x;

    coord.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}
void GotoXY(int x, int y)
{
    HANDLE a;
    COORD b;
    fflush(stdout);
    b.X = x;
    b.Y = y;
    a = GetStdHandle(STD_OUTPUT_HANDLE); //DECLARATION//
    SetConsoleCursorPosition(a,b);
}
void load()
{
    int row,col,r,c,q;
    gotoxy(36,14);
    printf("loading..."); //PRINT//
    gotoxy(30,15); //NAVIGATION//
    for(r=1; r<=20; r++)
    {
        for(q=0; q<=100000000; q++); //display slow//
        printf("%c",177);
    }
    getch();
}
void goDown()
{
    int i;
    for(i=0; i<=(head.y-bend[bend_no].y)&&curr_len<snake_length; i++) //LENGTH OF SNAKE//
    {
        GotoXY(head.x,head.y-i);
        {
            if(curr_len==0)
                printf("v"); //PRINT//
            else
                printf("*"); //PRINT//
        }
        body[curr_len].x=head.x; //NAVIGATION//
        body[curr_len].y=head.y-i; //NAVIGATION//
        curr_len++;
    }
    Bend();
    if(!kbhit())
        head.y++; //NAVIGATION//
}
void delay(long double k)
{
    getScore(); //DISPLAY SCORE//
    long double i;
    for(i=0; i<=(10000000); i++);
}
void border()
{
    int i,check=0;
    for(i=4; i<snake_length; i++) //length value
    {
        if(body[0].x==body[i].x&&body[0].y==body[i].y) //NAVIGATION//
        {
            check++;    //calculate
        }
        if(i==snake_length||check!=0) //DIRECTION//
            break;
    }
    if(head.x<=10||head.x>=70||head.y<=10||head.y>=30||check!=0) //CHECKING//
    {
        health--; //HEALTH//
        if(health>=0) //HEALTH//
        {
            head.x=25; //MOVE TOWARDS 25//
            head.y=20; //MOVE TOWARDS 20//
            bend_no=0; //MOVE TOWARDS 0//
            head.direction=RIGHT; //headed towards right//
            moveSnake(); //ACTIVITY OF SNAKE//
        }
        else
        {
            system("cls"); //SYSTEM//
            printf("ALL LIVES COMPLETED\nBETTER LUCK NEXT TIME!!!\nPRESS ANY KEY TO QUIT THE GAME\n"); //INSTRUCTION GIVEN FOR THE GAME//
            recordScore(); //SCORE//
            exit(0);
        }
    }
}
void generateFood() //FOOD//
{
    if(head.x==food.x&&head.y==food.y)
    {
        snake_length++; //LENGTH OF SNAKE//
        time_t a;
        a=time(0); //TIME//
        srand(a);
        food.x=rand()%70; //FOOD//
        if(food.x<=10) //FOOD//
            food.x+=11; //FOOD//
        food.y=rand()%30; //FOOD//
        if(food.y<=10)

            food.y+=11; //FOOD//
    }
    else if(food.x==0)//create point//
    {
        food.x=rand()%70; //FOOD//
        if(food.x<=10)
            food.x+=11; //FOOD//
        food.y=rand()%30;
        if(food.y<=10)
            food.y+=11; //FOOD//
    }
}
void goLeft()
{
    int i;
    for(i=0; i<=(bend[bend_no].x-head.x)&&curr_len<snake_length; i++) //calculate length//
    {
        GotoXY((head.x+i),head.y);
        {
            if(curr_len==0)
                printf("<"); //PRINT//
            else
                printf("*"); //PRINT//
        }
        body[curr_len].x=head.x+i; //CURRENT LENGTH//
        body[curr_len].y=head.y; //CURRENT LENGTH//
        curr_len++;
    }
    Bend();
    if(!kbhit())
        head.x--; //NAVIGATION//

}
void goRight()
{
    int i;
    for(i=0; i<=(head.x-bend[bend_no].x)&&curr_len<snake_length; i++) //calculate of snake//
    {

        body[curr_len].x=head.x-i; //CURRENT LENGTH//
        body[curr_len].y=head.y; //CURRENT LENGTH//
        GotoXY(body[curr_len].x,body[curr_len].y); //CURRENT LENGTH//
        {
            if(curr_len==0)
                printf(">"); //PRINT//
            else
                printf("*"); //PRINT//
        }

        curr_len++;
    }
    Bend();
    if(!kbhit())
        head.x++;
}
void Bend()
{
    int i,j,diff;
    for(i=bend_no; i>=0&&curr_len<snake_length; i--) //LENGTH OF SNAKE//
    {
        if(bend[i].x==bend[i-1].x) //DIRECTION//
        {
            diff=bend[i].y-bend[i-1].y;
            if(diff<0)
                for(j=1; j<=(-diff); j++)
                {
                    body[curr_len].x=bend[i].x;
                    body[curr_len].y=bend[i].y+j; //DECLARATION//
                    GotoXY(body[curr_len].x,body[curr_len].y);
                    printf("*"); //print//
                    curr_len++;
                    if(curr_len==snake_length) //LENGTH//
                        break;
                }
            else if(diff>0)
                for(j=1; j<=diff; j++)
                {

                    body[curr_len].x=bend[i].x; //DECLARATION//
                    body[curr_len].y=bend[i].y-j; //DECLARATION//
                    GotoXY(body[curr_len].x,body[curr_len].y); //length of snake//
                    printf("*"); //PRINT//
                    curr_len++; //CURRENT LENGTH//
                    if(curr_len==snake_length) //snake length//
                        break;
                }
        }
        else if(bend[i].y==bend[i-1].y)
        {
            diff=bend[i].x-bend[i-1].x;
            if(diff<0)
                for(j=1; j<=(-diff)&&curr_len<snake_length; j++)
                {

                    body[curr_len].x=bend[i].x+j; //DECLARATION//
                    body[curr_len].y=bend[i].y; //DECLARATION//
                    GotoXY(body[curr_len].x,body[curr_len].y); //snake length//
                    printf("*"); //PRINT//
                    curr_len++;
                    if(curr_len==snake_length) //SNAKE LENGTH//
                        break;
                }
            else if(diff>0)
                for(j=1; j<=diff&&curr_len<snake_length; j++) //length of snake//
                {

                    body[curr_len].x=bend[i].x-j; //DECLARATION//
                    body[curr_len].y=bend[i].y; //DECLARATION//
                    GotoXY(body[curr_len].x,body[curr_len].y); //calculate current length of snake//
                    printf("*");
                    curr_len++;
                    if(curr_len==snake_length) //CALCULATE OF SNAKE LENGTH//
                        break;
                }
        }
    }
}
void Boarder()
{
    system("cls");
    int i;
    GotoXY(food.x,food.y);   //highlight score//
    printf("F");
    for(i=10; i<71; i++)
    {
        GotoXY(i,10);
        printf("!"); //PRINT//
        GotoXY(i,30);
        printf("!"); //PRINT//
    }
    for(i=10; i<31; i++)
    {
        GotoXY(10,i);
        printf("!"); //PRINT//
        GotoXY(70,i);
        printf("!"); //PRINT//
    }
}
void createWorld()
{

    printf("\tWELCOME TO THE MINI SNAKE GAME.(PRESS ANY KEY TO CONTINUE)\n"); //record the key//
    getch();
    system("cls");
    printf("\tGAME INSTRUCTION:\n");
    printf("\n-> USE ARROW KEYS TO MOVE THE SNAKE.\n\n-> YOU WILL BE PROVIDED FOODS AT THE SEVERAL COORDINATES OF THE SCREEN WHICH YOU HAVE TO EAT. EVERYTIME YOU EAT A FOOD THE SNAKE_LENGTH OF THE SNAKE WILL BE INCREASED BY 1 ELEMENT AND THUS THE SCORE.\n\n-> HERE YOU ARE GIVEN WITH 3 LIVES. YOUR HEALTH WILL BE DECREASED AS YOUR SNAKE HIT THE WALL.\n\n-> YOU ARE ABLE TO FREEZE THE GAME AT ANY TIME OF THE GAME BY ENTERING ANY KEY YOU LIKE. TO RESUME THE FREEZED GAME ENTER ANY OTHER KEY YOU LIKE ONCE AGAIN\n\n-> IF YOU WANT TO QUIT THE GAME PLEASE ENTER esc. \n");
    printf("\n\nPRESS ANY TO PLAY GAME...");
    if(getch()==27)
        exit(0);
}

void recordScore()
{
    char plname[20],nplname[20],cha,c;
    int i,j,px;
    FILE *info;
    info=fopen("record.txt","a+"); //RECORD//
    getch();
    system("cls");
    printf("ENTER YOUR NAME\n"); //ENTER NAME//
    scanf("%[^\n]",plname);
    //************************
    for(j=0; plname[j]!='\0'; j++) //to change letter//
    {
        nplname[0]=toupper(plname[0]);
        if(plname[j-1]==' ')
        {
            nplname[j]=toupper(plname[j]); //name the player//
            nplname[j-1]=plname[j-1];
        }
        else nplname[j]=plname[j];
    }
    nplname[j]='\0';

    fprintf(info,"PLAYER NAME :%s\n",nplname); //name the player//

    time_t mytime;
    mytime = time(NULL); //TIME//
    fprintf(info,"PLAYED DATE:%s",ctime(&mytime)); //highlight the date//

    fprintf(info,"SCORE:%d\n",px=scoreDisplay()); //highlight the score//
    for(i=0; i<=50; i++)
        fprintf(info,"%c",'_'); //PRINT//
    fprintf(info,"\n"); //PRINT//
    fclose(info);
    printf("WANT TO SEE THE PAST RECORDS PLEASE ENTER 'y'\n"); //Highlight the record//
    cha=getch();
    system("cls");
    if(cha=='y')
    {
        info=fopen("record.txt","r"); N//RECORD//
        do
        {
            putchar(c=getc(info));
        }
        while(c!=EOF);
    }
    fclose(info);
}
int getScore()
{
    int score;
    GotoXY(20,8); //DIRECTION//
    score=snake_length-5; //LENGTH OF SNAKE//
    printf("SCORE : %d",(snake_length-5)); //highlight the length//
    score=snake_length-5; //LENGTH//
    GotoXY(50,8); //DIRECTION//
    printf("Life : %d",health); //HEALTH//
    return score;
}
int scoreDisplay()
{
    int score=getScore();
    system("cls"); //SYSTEM//
    return score;
}
void goUp()
{
    int i;
    for(i=0; i<=(bend[bend_no].y-head.y)&&curr_len<snake_length; i++) //highlight the length//
    {
        GotoXY(head.x,head.y+i); //HEADING//
        {
            if(curr_len==0)
                printf("^"); //PRINT//
            else
                printf("*"); //PRINT//
        }
        body[curr_len].x=head.x;    //CALCULATE//
        body[curr_len].y=head.y+i; //CALCULATE//
        curr_len++;
    }
    Bend();
    if(!kbhit())
        head.y--;
}
