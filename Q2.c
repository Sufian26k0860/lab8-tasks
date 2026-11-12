#include <stdio.h>
void showRates()
{
    printf("City Care Hospital\n");
    printf("1. General Ward  - Rs. 1500/day\n");
    printf("2. Semi-Private  - Rs. 3500/day\n");
    printf("3. Private       - Rs. 6000/day\n");
}
int getRoom()
{
    int r;
    printf("Enter room type (1-3): ");
    scanf("%d",&r);
    while(r<1||r>3)
    {
        printf("Invalid room type! Enter again (1-3): ");
        scanf("%d",&r);
    }
    return r;
}
int getDays()
{
    int d;
    printf("Enter number of days stayed (1-30): ");
    scanf("%d",&d);
    while(d<1||d>30)
    {
        printf("Invalid days Enter again (1-30): ");
        scanf("%d",&d);
    }
    return d;
}
double roomCharges(int r,int d)
{
    if(r==1)
        return 1500.0*d;
    else if(r==2)
        return 3500.0*d;
    else
        return 6000.0*d;
}
double medicineCharge(double m)
{
    return m+m*0.05;
}
double applyDiscount(double t,int d)
{
    if(d>=7)
        return t-t*0.08;
    return t;
}
const char* roomName(int r)
{
    if(r==1)
        return "General Ward";
    else if(r==2)
        return "Semi-Private";
    else
        return "Private";
}
void printBill(int r,int d,double c,double m,double f)
{
    printf("Final Billn");
    printf("Room Type         : %s\n",roomName(r));
    printf("Days Stayed       : %d\n",d);
    printf("Room Charges      : Rs. %.2f\n",c);
    printf("Medicine Charges  : Rs. %.2f\n",m);
    printf("Final Amount      : Rs. %.2f\n",f);
    
}
int main()
{
    double b;
    char s;
    showRates();
    int r=getRoom();
    int d=getDays();
    double c=roomCharges(r,d);
    printf("Enter medicine bill: Rs. ");
    scanf("%lf",&b);
    while(b<0)
    {
        printf("Bill cannot be negative Enter again: Rs. ");
        scanf("%lf",&b);
    }
    double m=medicineCharge(b);
    double f=applyDiscount(c+m,d);
    printf("Is the patient a senior citizen? (y/n): ");
    scanf(" %c",&s);
    while(s!='y'&&s!='Y'&&s!='n'&&s!='N')
    {
        printf("Please enter y or n: ");
        scanf(" %c",&s);
    }
    if(s=='y'||s=='Y')
    {
        f=f-1000;
        if(f<0)
            f=0;
    }
    printBill(r,d,c,m,f);
    return 0;
}
