#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 15
#define COLUMN 30
char array[ROW][COLUMN];
void red()
{
    printf("\033[1;31m");
}
void reset()
{
    printf("\033[0m");
}
void yellow()
{
    printf("\033[1;33m");
}
void green()
{
    printf("\033[1;32m");
}
void purple()
{
    printf("\033[1;35m");
}
void printMap(int x1c,int x1r,int x2c,int x2r)
{

    int i, j;
    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COLUMN; j++)
        {
            if (i == x1r && j == x1c)
                array[i][j] = '1';
            else if (i == x2r && j == x2c)
                array[i][j] = '2';
            else if (j == 0)
                array[i][j] = '|';    
            else if (i == 2 && j == 1)
                array[i][j] = '*';
            else if (i == 4 && j == 3)
                array[i][j] = '*';
            else if (j == 29)
                array[i][j] = '|';
            else if (i == 0)
                array[i][j] = '-';
            else if (i == 14)
                array[i][j] = '-';
            else if (i == 1 && j == 14)
                array[i][j] = 'X';
            else if (i == 7 && j == 28)
                array[i][j] = 'X';
            else if (i == 13 && j == 14)
                array[i][j] = 'X';
            else if (i == 3 && j == 10)
                array[i][j] = 'X';
            else if (i == 3 && j == 18)
                array[i][j] = 'X';
            else if (i == 5 && j == 26)
                array[i][j] = 'X';
            else if (i == 10 && j == 26)
                array[i][j] = 'X';
            else if (i == 11 && j == 10)
                array[i][j] = 'X';
            else if (i == 11 && j == 18)
                array[i][j] = 'X';
            else if (i == 4 && j > 4 && j < 25)
                array[i][j] = '-';
            else if (i == 12 && j > 4 && j < 25)
                array[i][j] = '-';
            else if (i == 10 && j > 4 && j < 25)
                array[i][j] = '-';
            else if (i == 2 && j > 2 && j < 27)
                array[i][j] = '-';
            else if (i == 12 && j > 2 && j < 27)
                array[i][j] = '-';
            else if (j == 4 && i > 3 && i < 11)
                array[i][j] = '|';
            else if (j == 25 && i > 3 && i < 11)
                array[i][j] = '|';
            else if (j == 2 && i > 1 && i < 13)
                array[i][j] = '|';
            else if (j == 27 && i > 1 && i < 13)
                array[i][j] = '|';
            else
                array[i][j] = ' ';
        }

    }
    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COLUMN; j++)
        {
            if(i==x1r && j==x1c)  //Prints uptade coordinates for Player 1
         {
            green();
            printf("%c",array[i][j]);
            reset();
         }
            else if(j==x2r && j==x2c)  //Prints uptade coordinates for Player 2
           {
            yellow();
            printf("%c",array[i][j]);
            reset();
          }
            else if (i == 1 && j == 14)
            {
                red();
                printf("%c", array[i][j]);
                reset();
            }
            else if (i == 7 && j == 28)
            {
                red();
                printf("%c", array[i][j]);
                reset();
            }
            else if (i == 13 && j == 14)
            {
                red();
                printf("%c", array[i][j]);
                reset();
            }
            else if (i == 3 && j == 10)
            {
                red();
                printf("%c", array[i][j]);
                reset();
            }
            else if (i == 3 && j == 18)
            {
                red();
                printf("%c", array[i][j]);
                reset();
            }
            else if (i == 5 && j == 26)
            {
                red();
                printf("%c", array[i][j]);
                reset();
            }
            else if (i == 10 && j == 26)
            {
                red();
                printf("%c", array[i][j]);
                reset();
            }
            else if (i == 11 && j == 10)
            {
                red();
                printf("%c", array[i][j]);
                reset();
            }
            else if (i == 11 && j == 18)
            {
                red();
                printf("%c", array[i][j]);
                reset();
            }
            else if (i == 2 && j == 1)
            {
                purple();
                printf("%c", array[i][j]);
                reset();
            }
            else if (i == 4 && j == 3)
            {
                purple();
                printf("%c", array[i][j]);
                reset();
            }
            else
                printf("%c", array[i][j]);
        }
        printf("\n");
    }
}
int dice()
{
    return 1 + rand() % 6;
}
int startGame()
{
    int x1,x2;
    printf("To start to game,players should dice who is going to start first according to it...\n");
    green();
    printf("Player 1... press ENTER to dice");
    reset();
    while( getchar() != '\n' );
    x1 = dice();
    green();
    printf("DICE: %d",x1);
    reset();
    yellow();
    printf("\nPlayer 2... press ENTER to dice");
    reset();
    while( getchar() != '\n' );
    x2 = dice();
    yellow();
    printf("DICE: %d\n",x2);
    reset();
    if(x1 > x2)
        return 1;
    else if(x2 > x1)
        return 2;
    else
        return 0;
}
int main()
{
    int start,flag;
    srand(time(NULL));
    int x1c=1,x1r=1,x2c=3,x2r=3; // starting coordinates 
    printMap(x1c,x1r,x2c,x2r);
    int nextstep;  //   dice value
    int control = 0; //  control: controls condition
    int rightx1=1,leftx1=0,downx1=0,upx1=0; // controls right,left,down,up for Player 1
    int rightx2=1,leftx2=0,downx2=0,upx2=0; // controls right,left,down,up for Player 2 
    int diceturn; 
    do
    {
        diceturn = startGame();
        if(diceturn == 0)
            printf("Same dice value... Please try again.\n");
        else if(diceturn == 1)
            printf("***Player 1 will start the game...***\n");
        else 
            printf("***Player 2 will start the game...***\n");
    } while (diceturn == 0);

    while( !(x1c == 1 && x1r == 2) && !(x2c == 3 && x2r == 4) ) // controls if the game end
    {

        if(x1c ==28 && x1r == 1) // Down Player 1
        {
            downx1=1;
            leftx1=0;
            rightx1=0;
            upx1=0;
        }
        else if( x1c == 28 && x1r == 13) // Left Player 1
        {
            downx1=0;
            leftx1=1;
            rightx1=0;
            upx1=0;
        }
        else if(x1c == 1 && x1r == 13) // Up Player 1
        {
            downx1=0;
            leftx1=0;
            rightx1=0;
            upx1=1;
        }
        
        if(x2c == 26 && x2r == 3) // Down Player 2
        {
            downx2 =1;
            leftx2 = 0;
            rightx2 = 0;
            upx2 = 0;
        }
        else if(x2c  == 26 && x2r == 11)// Left Player 2
        {
            downx2 =0;
            leftx2 = 1;
            rightx2 = 0;
            upx2 = 0;
        }
        else if(x2c == 3 && x2r == 11) // Up Player 2
        {
            downx2 =0;
            leftx2 = 0;
            rightx2 = 0;
            upx2 = 1;
        }

        if(diceturn == 1)
        {
            if(rightx1)
            {
                green();
                printf("Player 1... press ENTER to dice");
                reset();
                while( getchar() != '\n' );
                nextstep = dice();
                green();
                printf("DICE : %d\n",nextstep);
                reset();
                x1c += nextstep;
                if(x1c >28)
                {
                    x1c =28;
                }
                if( (x1c == 14) && (x1r == 1) ) x1c -=2;  // Controls penalty points
            }
            else if(downx1)
            {
                green();
                printf("Player 1... press ENTER to dice");
                reset();
                while( getchar() != '\n' );
                nextstep = dice();
                green();
                printf("DICE : %d\n",nextstep);
                reset();
                x1r += nextstep;
                if(x1r >13)
                {
                    x1r =13;
                }

                if( (x1c == 28) && (x1r == 7) ) x1r-=2; // Controls penalty points
            }
            else if(leftx1)
            {
                green();
                printf("Player 1... press ENTER to dice");
                reset();
                while( getchar() != '\n' );
                nextstep = dice();
                green();
                printf("DICE : %d\n",nextstep);
                reset();
                x1c -= nextstep;
                if(x1c <1)
                {
                    x1c =1;
                }

                if((x1c == 14 ) && (x1r == 13 )) x1c+= 2; 
            }
            else if(upx2)
            {
                green();
                printf("Player 1... press ENTER to dice");
                reset();
                while( getchar() != '\n' );
                nextstep = dice();
                green();
                printf("DICE : %d\n",nextstep);
                reset();
                x1r -= nextstep;
                if(x1r <2)
                {
                    x1r =2;
                }
            }
            diceturn +=1;
            control +=1;
        }
        else if(diceturn == 2)
        {
            if(rightx2)
            {
                yellow();
                printf("Player 2... press ENTER to dice");
                reset();
                while( getchar() != '\n' );
                nextstep = dice();
                yellow();
                printf("DICE : %d\n",nextstep);
                reset();
                x2c += nextstep;
                if(x2c >26)
                {
                    x2c =26;
                }
                if(((x2c == 10 ) && (x2r == 3 )) || ((x2c == 18 ) && (x2r == 3 ) )) x2c -=2;  // Controls penalty points
            }
            else if(downx2)
            {
                yellow();
                printf("Player 2... press ENTER to dice");
                reset();
                while( getchar() != '\n' );
                nextstep = dice();
                yellow();
                printf("DICE : %d\n",nextstep);
                reset();
                x2r += nextstep;
                if(x2r >11)
                {
                    x2r =11;
                }

                if(((x2c == 26 ) && (x2r == 5 )) || ((x2c == 26 ) && (x2r == 10 ) )) x2r -=2;  // Controls penalty points
            }
            else if(leftx2)
            {
                yellow();
                printf("Player 2... press ENTER to dice");
                reset();
                while( getchar() != '\n' );
                nextstep = dice();
                yellow();
                printf("DICE : %d\n",nextstep);
                reset();
                x2c -= nextstep;
                if(x2c < 3)
                {
                    x2c =3;
                }

                if(((x2c == 10 ) && (x2r == 11 )) || ((x2c == 18 ) && (x2r == 11 ) )) x2c -=2;  // Controls penalty points
            }
            else if(upx2)
            {
                yellow();
                printf("Player 2... press ENTER to dice");
                reset();
                while( getchar() != '\n' );
                nextstep = dice();
                yellow();
                printf("DICE : %d\n",nextstep);
                reset();
                x2r -= nextstep;
                if(x2r <4)
                {
                    x2r =4;
                }
            }
            control +=1;
            diceturn -=1;
        }
        if(x1c == 1 && x1r ==2) // İf Player 1 on the end point
        {
            green();
            printf("\n\nPlayer 1 WON!!!\n");
            reset();
        }
        if(x2c == 3 && x2r == 4) // İf Player 2 on the end point
        {
            yellow();
            printf("\n\nPlayer 2 WON !!!\n");
            reset();
        }

        if(control ==2 || (x1c == 1 && x1r ==2) || (x2c == 3 && x2r == 4)) // Prints map according to 2 dice and end points
        {
            printMap(x1c,x1r,x2c,x2r);
            control =0;
        }
    }
    return 0;
}
