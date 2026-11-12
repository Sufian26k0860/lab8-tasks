#include <stdio.h>
#include <ctype.h>
void showRoutes()
{
    printf("\nDaewoo Bus Booking\n");
    printf("1. Karachi to Hyderabad - Rs. 800\n");
    printf("2. Karachi to Sukkur    - Rs. 2200\n");
    printf("3. Karachi to Multan    - Rs. 3500\n");
}
int getRoute()
{
    int r;
    printf("Enter route number (1-3): ");
    scanf("%d",&r);
    while(r<1||r>3)
    {
        printf("Invalid route! Enter again (1-3): ");
        scanf("%d",&r);
    }
    return r;
}
int getSeats()
{
    int s;
    printf("Enter number of seats (1-6): ");
    scanf("%d",&s);
    while(s<1||s>6)
    {
        printf("Invalid seats! Enter again (1-6): ");
        scanf("%d",&s);
    }
    return s;
}
char getType()
{
    char c;
    printf("Enter seat type (E for Economy, B for Business): ");
    scanf(" %c",&c);
    c=toupper(c);
    while(c!='E'&&c!='B')
    {
        printf("Invalid type Enter E or B: ");
        scanf(" %c",&c);
        c=toupper(c);
    }
    return c;
}
double seatFare(int r)
{
    if(r==1)
        return 800;
    else if(r==2)
        return 2200;
    else
        return 3500;
}
double totalFare(double f,int s)
{
    return f*s;
}
double addSeatCharge(double t,char c)
{
    if(c=='B')
        return t+t*0.30;
    return t;
}
const char* routeName(int r)
{
    if(r==1)
        return "Karachi to Hyderabad";
    else if(r==2)
        return "Karachi to Sukkur";
    else
        return "Karachi to Multan";
}
void printTicket(int r,int s,char c,double f)
{
    printf("Ticket\n");
    printf("Route      : %s\n",routeName(r));
    printf("Seats      : %d\n",s);
    printf("Seat Type  : %s\n",c=='B'?"Business":"Economy");
    printf("Final Fare : Rs. %.2f\n",f);
    
}
int main()
{
    double e=0;
    int i;
    for(i=1;i<=2;i++)
    {
        printf("\nPassenger %d",i);
        showRoutes();
        int r=getRoute();
        int s=getSeats();
        char c=getType();
        double f=seatFare(r);
        double t=totalFare(f,s);
        t=addSeatCharge(t,c);
        printTicket(r,s,c,t);
        e=e+t;
    }
    printf("\nTotal earnings of the bus company: Rs. %.2f\n",e);
    return 0;
}
