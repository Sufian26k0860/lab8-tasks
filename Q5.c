#include <stdio.h>
int main()
{
    double costPrice,sellPrice,quantity;
    double *a=&costPrice,*b=&sellPrice,*c=&quantity;
    double t,s,g,e;
    double *p=&t,*q=&s,*r=&g,*f=&e;
    printf("Sara's Stationery Shop\n");
    printf("Enter cost price: ");
    scanf("%lf",a);
    while(*a<=0)
    {
        printf("Cost price must be more than 0. Enter again: ");
        scanf("%lf",a);
    }
    printf("Enter selling price: ");
    scanf("%lf",b);
    while(*b<0)
    {
        printf("Selling price cannot be negative. Enter again: ");
        scanf("%lf",b);
    }
    printf("Enter quantity sold: ");
    scanf("%lf",c);
    while(*c<=0)
    {
        printf("Quantity must be more than 0. Enter again: ");
        scanf("%lf",c);
    }
    *p=*a**c;
    *q=*b**c;
    *r=*q-*p;
    printf("\nTotal Cost  : Rs. %.2f\n",*p);
    printf("Total Sales : Rs. %.2f\n",*q);
    if(*r>0)
        printf("Result      : Profit of Rs. %.2f\n",*r);
    else if(*r<0)
        printf("Result      : Loss of Rs. %.2f\n",-*r);
    else
        printf("Result      : No profit no loss\n");
    *f=(*r/ *p)*100;
    if(*f>=0)
        printf("Profit %%    : %.2f%%\n",*f);
    else
        printf("Loss %%      : %.2f%%\n",-*f);
    double *m=(*a>=*b)?a:b;
    if(*a==*b)
        printf("\nCost price and selling price are equal, pointer points to costPrice with value %.2f\n",*m);
    else if(m==a)
        printf("\nLarger value pointer points to costPrice with value %.2f\n",*m);
    else
        printf("\nLarger value pointer points to sellPrice with value %.2f\n",*m);
    printf("\n%-15s%-15s%s\n","Name","Value","Address");
    printf("--------------------------------------------\n");
    printf("%-15s%-15.2f%p\n","costPrice",costPrice,(void*)&costPrice);
    printf("%-15s%-15.2f%p\n","sellPrice",sellPrice,(void*)&sellPrice);
    printf("%-15s%-15.2f%p\n","quantity",quantity,(void*)&quantity);
    printf("%-15s%-15.2f%p\n","totalCost",t,(void*)&t);
    printf("%-15s%-15.2f%p\n","totalSales",s,(void*)&s);
    printf("%-15s%-15.2f%p\n","profitLoss",g,(void*)&g);
    printf("%-15s%-15.2f%p\n","percentage",e,(void*)&e);
    printf("--------------------------------------------\n");
    printf("%-15s%-17s%s\n","Pointer","Points To","Own Address");
    printf("--------------------------------------------\n");
    printf("%-15s%-17p%p\n","a",(void*)a,(void*)&a);
    printf("%-15s%-17p%p\n","b",(void*)b,(void*)&b);
    printf("%-15s%-17p%p\n","c",(void*)c,(void*)&c);
    printf("%-15s%-17p%p\n","p",(void*)p,(void*)&p);
    printf("%-15s%-17p%p\n","q",(void*)q,(void*)&q);
    printf("%-15s%-17p%p\n","r",(void*)r,(void*)&r);
    printf("%-15s%-17p%p\n","f",(void*)f,(void*)&f);
    printf("%-15s%-17p%p\n","m",(void*)m,(void*)&m);
    return 0;
}
