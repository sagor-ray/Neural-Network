#include <iostream>
using namespace std;

int i,target[4]= {0,0,0,1},x1[4] = {0,0,1,1},x2[4]= {0,1,0,1},x[3],positionX1,positionX2,t;
float w[3] = {-0.199643,0.5,-0.199643},delw[4],a[4],eta=0.25,wnew[3],f,y;

void print()
{
    for(i=0; i<3; i++)
    {
        cout<<wnew[i]<<endl;
        w[i] = wnew[i];
    }
    cout<<"Error Value: "<<t-y<<endl<<endl<<"...............*************.............."<<endl<<endl;
}

int main()
{
    x[0] = -1;
    while(1)
    {
        for(i=0; i<4; i++)
        {
            f = w[0]*x[0] + w[1]*x1[i] + w[2]*x2[i];
            a[i] = f;
        }

        t=1;
        y=a[3];
        x[1] = x1[3];
        x[2] = x2[3];

        for(i=0; i<3; i++)
        {
            delw[i] = eta*(t-y)*x[i];
            wnew[i] = w[i] + delw[i];
        }
        print();
        if((t-y)>= 0 && (t-y)<= 0.001)
        {
            break;
        }


    }
    return 0;
}



