#include <iostream>
#include <iomanip>
#include <conio.h>
#include <math.h>
using namespace std;

void algebricSum(double b1[], double b2[], int n);
void boundedSum(double b1[], double b2[], int n);
void boundedDifference(double b1[], double b2[], int n);
double Max(double b1[], double b2[]);
double Min(double b1[], double b2[]);
void b1Unionb2(double b1[], double b2[]);
void b1Intersectionb2(double b1[], double b2[]);
double Complement(double b[]);
void b1Byb2(double b1[], double b2[]);
void ComplementPrint(double b[]);

const int n = 4;
double b1[n] = {1,0.5,0.3,0.4},b2[n] = {0.4,0.2,0.7,0.1};
float m;

int main()
{
    cout<<"B1 = {1/0.5 + 0.5/1.0 + 0.3/1.5 + 0.4/2.0}\n\n"<<"B2 = {0.4/0.5 + 0.2/1.0 + 0.7/1.5 + 0.1/2.0}\n\n\n";

    cout<<"Complement of B1: \n{";
    ComplementPrint(b1);
    cout<<"Complement of B2: \n{";
    ComplementPrint(b2);
    b1Unionb2(b1,b2);
    b1Intersectionb2(b1,b2);
    b1Byb2(b1,b2);
    algebricSum(b1,b2,n);
    boundedSum(b1,b2,n);
    boundedDifference(b1,b2,n);

    getch();
    return 0;
}

double Max(double b1, double b2)
{
      if(b1 > b2)
        {
            return b1;
        }
        return b2;
}

double Min(double b1, double b2)
{
        if(b1 > b2)
        {
            return b2;
        }
        return b1;
}

double Complement(double b)
{
    return (1-b);
}

void b1Unionb2(double b1[], double b2[])
{
    m = 0.5;
    cout<<"B1 U B2:\n{";
    for(int i=0; i<n; i++)
    {
        cout<<Max(b1[i],b2[i])<<"/"<<m;
        m += 0.5;
        if(i != n-1)
        {
            cout<<" + ";
        }
    }
    cout<<"}\n\n";
}

void b1Intersectionb2(double b1[], double b2[])
{
    m = 0.5;
    cout<<"B1 intersection B2:\n{";
    for(int i=0; i<n; i++)
    {
        cout<<Min(b1[i],b2[i])<<"/"<<m;
        m += 0.5;
        if(i != n-1)
        {
            cout<<" + ";
        }
    }
    cout<<"}\n\n";
}

void b1Byb2(double b1[], double b2[])
{
    m = 0.5;
    cout<<"B1 | B2:\n{";
    for(int i=0; i<n; i++)
    {
        cout<<Min(b2[i],Complement(b1[i]))<<"/"<<m;
        m += 0.5;
        if(i != n-1)
        {
            cout<<" + ";
        }
    }
    cout<<"}\n\n";
}

void algebricSum(double b1[], double b2[], int n)
{
    m = 0.5;
    cout<<"Algebric Sum: \n{";
    for(int i=0; i<n; i++)
    {
        cout<<(b1[i] + b2[i]) - (b1[i]*b2[i])<<"/"<<m;
        m+=0.5;
        if(i != n-1)
        {
            cout<<" + ";
        }
    }
    cout<<"}";
}
void boundedSum(double b1[], double b2[], int n)
{
    m = 0.5;
    cout<<"\n\nBounded Sum: \n{";
    for(int i=0; i<n; i++)
    {
        cout<<Min(1.0,(b1[i]+b2[i]))<<"/"<<m;
        m+=0.5;
        if(i != n-1)
        {
            cout<<" + ";
        }
    }
    cout<<"}";
}
void boundedDifference(double b1[], double b2[], int n)
{
    m = 0.5;
    cout<<"\n\nBounded Difference: \n{";
    for(int i=0; i<n; i++)
    {
        cout<<Max(0.0,(b1[i]+Complement(b2[i])))<<"/"<<m;
        m+=0.5;
        if(i != n-1)
        {
            cout<<" + ";
        }
    }
    cout<<"}";
}

void ComplementPrint(double b[])
{
    m = 0.5;
    for(int i=0; i<n; i++)
    {
        cout<<Complement(b[i])<<"/"<<m;
        m+=0.5;
        if(i != n-1)
        {
            cout<<" + ";
        }
    }
    cout<<"}\n\n";
}
