#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main ()
{
    int num, i=0, g;
    time_t t1;

    

    srand((unsigned) time (&t1));
    printf("\n");

    num=(rand()%10)+1;
for (int i = 4; i >= 1; i--)
{
    printf("Enter your guess: ");
    scanf("%d", &g);
if (num==g){printf("You guessed it right!!"); break;}

else if (num>g){printf("Your guess was smaller than the number!! \n %d guesses left.", i);}

else {printf("Your guess was bigger than the number!! \n %d guesses left.", i);}
}
    return 0;
    
}