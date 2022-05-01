#include <iostream>
#include <fstream>
using namespace std;

float eta = 0.25, f;
int x1[4] = {0,0,1,1}, x2[4] = {0,1,0,1},b=1;
int y,i,count=1;

ofstream out("C:\\Users\\sagor\\OneDrive\\Desktop\\Coding\\Compiler Lab\\write.txt");

float AND();
float NAND();
float OR();
float NOR();
float NOT();

int main()
{
    AND();
    OR();
    NAND();
    NOR();
    NOT();
    return 0;
}
float AND()
{
    out<<"*********AND Gate*************"<<endl<<endl;

    float w0 = 0.3, w1 = 0.5, w2 = -0.4;
    int t[4]= {0,0,0,1};

        for(i=0; i<4; i++)
        {
            out<<"Iteration No: "<<count<<endl;
            count++;
            out<<"w0 = "<<w0<<endl;
            out<<"w1 = "<<w1<<endl;
            out<<"w2 = "<<w2<<endl<<endl;

            f=w0*b + w1*x1[i] + w2*x2[i];
            if(f<=0)
            {
                y=0;
            }
            else
            {
                y=1;
            }
            if(y==t[i])
            {

                continue;
            }
            else
            {
                w0 = w0+(eta*(t[i]-y)* b);
                w1 = w1+(eta*(t[i]-y)* x1[i]);
                w2 = w2+(eta*(t[i]-y)* x2[i]);
                i = 0;
            }
        }
}

float NAND()
{
    out<<"***********NAND Gate*************"<<endl<<endl;

    float w0 = 0.3, w1 = 0.5, w2 = -0.4;
    int t[4]= {1,1,1,0};
    count = 1;
        for(i=0; i<4; i++)
        {
            out<<"Iteration No: "<<count<<endl;
            count++;
            out<<"w0 = "<<w0<<endl;
            out<<"w1 = "<<w1<<endl;
            out<<"w2 = "<<w2<<endl<<endl;

            f=w0*b + w1*x1[i] + w2*x2[i];
            if(f<=0)
            {
                y=0;
            }
            else
            {
                y=1;
            }
            if(y==t[i])
            {
                continue;
            }
            else
            {
                w0 = w0+(eta*(t[i]-y)* b);
                w1 = w1+(eta*(t[i]-y)* x1[i]);
                w2 = w2+(eta*(t[i]-y)* x2[i]);
                i = 0;
            }
        }

}
//function for finding actual weight of OR gate....
float OR()
{
    out<<"*************OR Gate****************"<<endl<<endl;

    float w0 = -0.3, w1 = 0.1, w2 = 0.3;
    int t[4]= {0,1,1,1};
    count = 1;
        for(i=0; i<4; i++)
        {
            out<<"Iteration No: "<<count<<endl;
            count++;
            out<<"w0 = "<<w0<<endl;
            out<<"w1 = "<<w1<<endl;
            out<<"w2 = "<<w2<<endl<<endl;

            f=w0*b + w1*x1[i] + w2*x2[i];
            if(f<=0)
            {
                y=0;
            }
            else
            {
                y=1;
            }
            if(y==t[i])
            {
                continue;
            }
            else
            {
                w0 = w0+(eta*(t[i]-y)* b);
                w1 = w1+(eta*(t[i]-y)* x1[i]);
                w2 = w2+(eta*(t[i]-y)* x2[i]);
                i = 0;
            }
        }
}
float NOR()
{
    out<<"*****************NOR Gate*****************"<<endl<<endl;

    float w0 = 0.4, w1 = -0.3, w2 = -0.2;
    int t[4]= {1,0,0,0};
    count = 1;
        for(i=0; i<4; i++)
        {
            out<<"Iteration No: "<<count<<endl;
            count++;
            out<<"w0 = "<<w0<<endl;
            out<<"w1 = "<<w1<<endl;
            out<<"w2 = "<<w2<<endl<<endl;

            f=w0*b + w1*x1[i] + w2*x2[i];
            if(f<=0)
            {
                y=0;
            }
            else
            {
                y=1;
            }
            if(y == t[i])
            {
                continue;
            }
            else
            {
                w0 = w0+(eta*(t[i]-y)* b);
                w1 = w1+(eta*(t[i]-y)* x1[i]);
                w2 = w2+(eta*(t[i]-y)* x2[i]);
                i = 0;
            }
        }
}
float NOT()
{
    out<<"*****************NOT Gate******************"<<endl<<endl;

    float w0 = 0.7, w1 = -0.5;
    int t[4]= {1,0},x[2] = {0,1},count=0;
    count = 1;
        for(int i=0; i<2; i++)
        {
            out<<"Iteration No: "<<count<<endl;
            count++;
            out<<"w0 = "<<w0<<endl;
            out<<"w1 = "<<w1<<endl<<endl;

            f= w0*b + w1*x[i];
            if(f > 0)
            {
                y = 1;
            }
            else
            {
                y = 0;
            }
            if(y == t[i])
            {
               continue;
            }
            else
            {
                w0 = w0+(eta*(t[i]-y)* b);
                w1 = w1+(eta*(t[i]-y)* x[i]);
                i = 0;
            }
        }

}


