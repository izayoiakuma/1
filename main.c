#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int gold=50,daycount=1;
int move,farmmove,storemove;
int seed=0,planted=0,watered=0,growstat=0;
int turnipcount=0;
char playername[50];

void delay()
{
    usleep(1000000);
}

void printdel(char* n)
{
    printf("%s", n);
    delay();
}

void newPlayer()
{
    printf("New farmer! Welcome to the Sixteenvally Version 0.0.1, please tell us your name:\n");
    scanf("%s", &playername);
    delay();
    printf("OHHH! %s!! You are the farmer who recently moved in!\n",playername);
    delay();
    printf("%s, your life in Sixteenvally begins, \n",playername);
    delay();
    printf("and your goal is to make 200 gold!\n");

}

void newday()
{   //printf("flag 1");
    if(gold<200);
    {
        printf("**********DAY %d**********\n",daycount);
            delay();
        daycount++;
        printf("you will \n1)go to the farm\n2)go to the store\n");
        scanf("%d",&move);
            delay();
        if(move==1)
            gofarm();
        else
            gostore();
        printf("your day is over.\n");
            delay();
    }
}

void gofarm()
{
    printf("you want to \n1)plant the seed\n2)water the field\n");
    scanf("%d",&farmmove);
    if(farmmove==2)
        water();
    if(farmmove==1)
        plant();
}

void plant()
{
        if(seed>0)
        {
            planted=seed;
            seed=0;
            printf("you planted %d turnip seed\n",planted);
                delay();
        }
        else
        {
            printf("you don't have any seed! go to the store!\n");
                delay();
        }

}
void water()
{
        if(planted>0)
        {
            growstat++;
            printf("your turnip(s) is %d days till harvest!\n",2-growstat);
                delay();
        }
        if(planted==0)
        {
            printf("you have nothing planted! plant something!\n");
                delay();
        }
        if(growstat==2)
        {
            turnipcount=planted;
            planted=0;
            growstat=0;
            printf("you harvested %d turnips! go sell them!\n",turnipcount);
                delay();
        }
}

void gostore()
{
    printf("you want to\n1)buy a turnip seed(grows in 2 days)(50g)\n2)sell crops\n");
        delay();
        scanf("%d",&storemove);
    if(storemove==1)
        buy();
    if(storemove==2)
        sell();
}
void buy()
{
    if(gold>=50)
    {   while(gold>=50)
        {seed++;
        gold=gold-50;
        }
        printf("you bought %d turnip seed\n",seed);
            delay();
        printf("your balance is %d\n",gold);
            delay();
    }
}

void sell()
{
    if(turnipcount>0)
    {
        gold=gold+turnipcount*100;
        turnipcount=0;
        printf("your balance is %d\n", gold);
            delay();
    }
    else{
            printf("you dont have any turnip!!\n");
                delay();
    }
}
int main()
{
    newPlayer();
    while(gold<200)
        newday();
    if(gold>=200)
    {
        printf("congrats %s!! you accomplish the goal in %d days!!",playername,daycount);
            delay();
    }


    return 0;
}
