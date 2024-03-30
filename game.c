#include<stdio.h>

int main()
{
    printf("Welcome! \n Fisrt to make a number divisible by 3, within their respective 10 turns, wins!! \n Please enter the number of players participating!\n");
    int start= 0, p=0;scanf("%d", &p);
    for (int j=0; ; )
    {
     if (p<=1)
    {
        printf("Get some friends, or enemies even...bruh... >:(\n Retry now tho...with more players that is...\n");
        scanf("%d", &p);
    }
    else{break;}
    }
    
    printf("Alright! Game set for %d players!! \n Please enter the starting number!!\n", p);
    scanf("%d", &start);

    for (int turn=1; turn<=10; turn++)
    {
        printf("Turn %d starts!!\n", turn);
        for (int i=1; i<=p; i++)
        {
            
            for (int i = 0; ; )
            { int check=start;
                printf("Will player %d add or subtract 1 from the starting value?\n", i);
            char c;scanf("%c", &c);
             switch (c)
             {
             case '+': start++;
                break;

             case '-': start--;
                break;

             default:printf("Blud, I told either add or subtract bruh..No need of showing your proficiency in maths here...\n Retry RN!!!\n");
                break;
             }
             if (start!=check)
             {
                break;
             }
             
            }

             if (start%3==0)
             {
                printf("Player %d won!!!\n", i);
                break;
             }
              
        }
        if (start%3==0)
        {
            break;
        }
    }
     
    if (start%3!=0)
    {
        printf("None achieved the objective. It is a draw!! ;-;\n");
    }
    

    printf("Thanks for playing!!");
    
    return 0;
}
