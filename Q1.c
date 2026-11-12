#include <stdio.h>
void showPacks()
{
    printf("Mobile Recharge Center \n");
    printf("1. Rs. 100 Pack\n");
    printf("2. Rs. 200 Pack\n");
    printf("3. Rs. 500 Pack\n");
    printf("4. Rs. 1000 Pack\n");
}
int getPack()
{
    int p;
    printf("Enter pack number (1-4): ");
    scanf("%d",&p);
    while(p<1||p>4)
    {
        printf("Invalid pack Enter again (1-4): ");
        scanf("%d",&p);
    }
    return p;
}
long long getNumber()
{
    long long m;
    printf("Enter mobile number (11 digits): ");
    scanf("%lld",&m);
    while(m<1000000000LL||m>99999999999LL)
    {
        printf("Invalid number Enter 11 digits again: ");
        scanf("%lld",&m);
    }
    return m;
}
double packAmount(int p)
{
    switch(p)
    {
        case 1:
            return 100;
        case 2:
            return 200;
        case 3:
            return 500;
        case 4:
            return 1000;
        default:
            return 0;
    }
}
double addTax(double a)
{
    return a+a*0.15;
}
double findBonus(double a)
{
    if(a>=500)
        return a*0.10;
    return 0;
}
void printSlip(long long m,double a,double t,double b)
{
    printf("Recharge Slip\n");
    printf("Mobile Number : %lld\n",m);
    printf("Pack Amount   : Rs. %.2f\n",a);
    printf("Tax (15%%)     : Rs. %.2f\n",t-a);
    printf("Amount Paid   : Rs. %.2f\n",t);
    printf("Bonus         : Rs. %.2f\n",b);
    printf("Total Balance : Rs. %.2f\n",a+b);
}
int main()
{
    double s=0;
    int i;
    for(i=1;i<=3;i++)
    {
        printf("\nRecharge %d of 3",i);
        showPacks();
        int p=getPack();
        long long m=getNumber();
        double a=packAmount(p);
        double t=addTax(a);
        double b=findBonus(a);
        printSlip(m,a,t,b);
        s=s+t;
    }
    printf("\nTotal money spent on 3 recharges: Rs. %.2f\n",s);
    return 0;
}
