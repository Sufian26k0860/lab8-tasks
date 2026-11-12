#include <stdio.h>
void showRules()
{
    printf("City Taxi Service\n");
    printf("Base fare           : Rs. 150\n");
    printf("First 10 km         : Rs. 60 per km\n");
    printf("After 10 km         : Rs. 45 per km\n");
    printf("Waiting (after 5min): Rs. 10 per min\n");
    printf("Night (10pm - 6am)  : 25%% extra\n");
}
int getDistance()
{
    int d;
    printf("Enter distance in km (1-200): ");
    scanf("%lf",&d);
    while(d<=0||d>200)
    {
        printf("Invalid distance! Enter again: ");
        scanf("%lf",&d);
    }
    return d;
}
int getWaiting()
{
    int w;
    printf("Enter waiting time in minutes (0-120): ");
    scanf("%d",&w);
    while(w<0||w>120)
    {
        printf("Invalid time! Enter again: ");
        scanf("%d",&w);
    }
    return w;
}
int getHour()
{
    int h;
    printf("Enter hour of the trip (0-23): ");
    scanf("%d",&h);
    while(h<0||h>23)
    {
        printf("Invalid hour! Enter again: ");
        scanf("%d",&h);
    }
    return h;
}
double distanceCharge(double d)
{
    if(d<=10)
        return d*60;
    return 10*60+(d-10)*45;
}
double waitingCharge(int w)
{
    if(w<=5)
        return 0;
    return (w-5)*10;
}
double nightCharge(double f,int h)
{
    if(h>=22||h<6)
        return f+f*0.25;
    return f;
}
void printReceipt(double d,int w,double f)
{
   
    printf("Distance     : %.2f km\n",d);
    printf("Waiting Time : %d min\n",w);
    printf("Final Fare   : Rs. %.2f\n",f);
    
}
int main()
{
    double t=0,x=0;
    int i;
    for(i=1;i<=3;i++)
    {
        printf("\nTrip %d",i);
        showRules();
        double d=getDistance();
        int w=getWaiting();
        int h=getHour();
        double f=150+distanceCharge(d)+waitingCharge(w);
        f=nightCharge(f,h);
        printReceipt(d,w,f);
        t=t+f;
        if(f>x)
            x=f;
    }
    printf("\nTotal earnings of the day : Rs. %.2f\n",t);
    printf("Highest fare of the day   : Rs. %.2f\n",x);
    return 0;
}
