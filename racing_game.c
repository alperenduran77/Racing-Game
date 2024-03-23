#include <stdio.h>
void green()
{
    printf("\033[0;32m");
}
void white()
{
    printf("\033[0;37m");
}
void yellow()
{
    printf("\033[0;33m");
}
void cyan()
{
    printf("\033[0;36m");
}
void red()
{
 printf("\033[0;31m");
}
void reset()
{
printf("\033[0m");
}
void cordinat_plane(int a,int b,int c)
{
int x,y;
for(y=15;y <= -15;y--)
{
  for(x=-55 ;x < 55;x++)  
{
    if(x == (a*y*y) + b*y + c )
                   {
                  printf("#");
                    }
    else if (x == 0)                    
                  {
                  printf("|"); 
                  }
    else             
              {
                  printf(y == 0 ? "-" : " ");
                }   
   }
       printf("\n");
}

}

int main()
{
int choice;
do
{

printf("\nSelect an operation\n");
printf("1 -> Enter the coefficients\n");
printf("2 -> Draw the graph.\n");
printf("3 -> Printf the graph into a .txt file.\n");
printf("4 -> Exit.\n");
printf("Choice: ");
scanf("%d",&choice);
printf("\n");
if(choice == 1)
{
    int a,b,c;
    printf("Please enter the coefficient for the following equation: x=a(y*y) + b*y+ c\n");
    printf("a: ");
    scanf("%d",&a);
    printf("b: ");
    scanf("%d",&b);
    printf("c: ");
    scanf("%d",&c);
    FILE *fp;
    fp=fopen("coefficients.txt","w+");
    fprintf(fp,"%d\n%d\n%d\n",a,b,c);
    fclose(fp);
    printf("\n");
    printf("coefficients.txt file has been created.\n\n");
}
if(choice == 2)
{
int x,y,a,b,c;
FILE *fp = fopen("coefficients.txt","r+");
if(fp == NULL)
{
printf("File could not found\n");
return 0;
}
fscanf(fp,"%d %d %d ",&a,&b,&c);
fclose(fp);
printf("Coefficients has been read from coefficient.txt file.\n");
printf("Printing the graph of x = %d * y *y + %d * y + %d.\n ",a,b,c);
for(y = 16; y >= -15; y--)
{
    for(x = -55;x < 55; x++)
    {
                 if((x == (a*y*y) + b*y + c ) && y == 5 && x>0)   // A space was left at y=5 to prevent the graph from slipping.
                   {
                   red();
                   printf(" #");
                   reset();
                    }
                else if((x == (a*y*y) + b*y + c ) && y == 10 && x>0)  // A space was left at y=10 to prevent the graph from slipping.
                    {
                     red();
                     printf(" #");
                     reset();
                     }
                else if((x == (a*y*y) + b*y + c ) && y == 15 && x>0)   //  A space was left at y=15 to prevent the graph from slipping.
                 {
                   red();
                  printf(" #");
                    reset();
                    }
                   else if((x == (a*y*y) + b*y + c ) && y == 16 && x>0)   //  A space was left at y=15 to prevent the graph from slipping.
                 {
                   red();
                  printf("  #");
                    reset();
                    }
                else if((x == (a*y*y) + b*y + c ) && y == -10 && x<0)   // A space was left at y=-10 to prevent the graph from slipping.
                   {
                       red();
                      printf(" \b#");
                      reset();
                       }
                else if((x == (a*y*y) + b*y + c ) && y == -15 && x<0)    // // A space was left at y=-15 to prevent the graph from slipping.
                  {
                  red();
                 printf(" \b#");
                  reset();
                   }
                  else if((x == (a*y*y) + b*y + c ) && y == -5 && x<0)  // A space was left at y=-5 to prevent the graph from slipping.
                   {
                       red();
                      printf(" \b#");
                      reset();
                       }
                else if(x == (a*y*y) + b*y + c )
                   {
                  red();
                  printf("#");
                  reset();
                    }
                                    else if(y == 16 && x == 0)
                   {
               cyan();
               printf("^");
               reset();
                   }
                else if(x == -1 && y == -1)      // y-axis numbers are printed based on the character value of the numbers
                    {
                    cyan();
                     printf("0");
                    reset();
                    }
                else if (x == -1 && y == 5 )    
                 {
                    cyan();
                    printf("%d|",y);
                     reset();
                       }
                else if (x == -2 && y == 10)     
                    {
                    cyan();
                    printf("%d|",y);
                     reset();
                       }
                else if (x == -2 && y == 15)     
                    {
                    cyan();
                    printf("%d|",y);
                     reset();
                       }
                else if (x == -2 && y == -5)      
                   {
                    cyan();
                    printf("%d|",y);
                     reset();
                       }
                else if (x == -3 && y == -10)      
                    {
                    cyan();
                    printf("%d|",y);
                     reset();
                       }
                else if (x == -3 && y == -15)        // y-axis numbers are printed based on the character value of the numbers
                    {
                    cyan();
                    printf("%d|",y);
                     reset();
                       }
                else if (x == 1 && y == 5 )           // unnecessary characters are deleted so that previously printed characters do not conflict
                    printf("\b");
                else if (x == 2 && y == 10)
                    printf("\b\b");
                else if (x == 2 && y == 15)
                    printf("\b\b");
                 else if (x == 2 && y == 16)
                    printf("\b\b");
                else if (x == 2 && y == -5)
                    printf("\b\b");
                else if (x == 3 && y == -10)
                    printf("\b\b\b");
                else if (x == 3 && y == -15)
                    printf("\b\b\b");                 // unnecessary characters are deleted so that previously printed characters do not conflict
                else if (x == 0)                     // y axis printed
                  {
                   cyan();
                  printf("|");
                     reset();
                    }
                else                              // x axis printed
                {
                  yellow();
                   printf(y == 0 ? "-" : " ");
                    reset();
                }
         }
    printf("\n");
}
}
if(choice == 3)
{
int a,b,c;
FILE *fp = fopen("coefficients.txt","r+");
fscanf(fp,"%d %d %d ",&a,&b,&c);
fclose(fp);
printf("Coefficients has been read from coefficient file.\n");
printf("The graph of x = %d * y * + %d * y + %d\n",a,b,c);
FILE *fp1 = fopen("graph.txt","w+");
fprintf(fp1,"cordinat_plane(a,b,c)");
}
if(choice != 1 && choice != 2 && choice != 3 && choice != 4)
{
    printf("Please enter a valid number[0-4]\n");
}
}while(choice != 4);

    return 0;
}
