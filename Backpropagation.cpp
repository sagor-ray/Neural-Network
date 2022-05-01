#include <iostream>
#include <math.h>
#define e 2.71828182
using namespace std;

int main()
{
    long double w1=0.15,w2=0.2,w3=0.25,w4=0.3,w5=0.4,w6=0.45,w7=0.5,w8=0.55,b1=0.35,b2=0.6;
    long double i1=0.05,i2=0.1,targeto1=0.01,targeto2=0.99,eta=0.5;
    int b=1,n=1;
    long double neth1,neth2,outh1,outh2,neto1,neto2,outo1,outo2,eo1,eo2,etotal=1;
    long double w1New,w2New,w3New,w4New,w5New,w6New,w7New,w8New;

    while(etotal>0.00011)
    {
    cout<<"Iteration Number: "<<n<<endl;
    n++;

    neth1 = w1*i1+w2*i2+b1*b;
    neth2 = w3*i1+w4*i2+b1*b;

    outh1 = 1/(1+pow(e,-neth1));
    outh2 = 1/(1+pow(e,-neth2));

    neto1 =  w5*outh1+w6*outh2+b2*b;
    neto2 =  w7*outh1+w8*outh2+b2*b;

    outo1 = 1/(1+pow(e,-neto1));
    outo2 = 1/(1+pow(e,-neto2));

    eo1 = 0.5*(targeto1-outo1)*(targeto1-outo1);
    eo2 = 0.5*(targeto2-outo2)*(targeto2-outo2);

    etotal = eo1 + eo2;

    //Starting Backward pass

    long double deriNeto1ByW6,deriNeto1ByW7,deriNeto1ByW8,deriOuto2ByNeto2,deriEtByOuto2;
    long double deriEtByOuto1,deriOuto1ByNeto1,deriNeto1ByW5,deriEtByW5,deriEtByW6,deriEtByW7,deriEtByW8;

    deriEtByOuto1 = -(targeto1-outo1);
    deriOuto1ByNeto1 = (outo1*(1-outo1));
    deriNeto1ByW5 = outh1;

    deriEtByOuto2 = -(targeto2-outo2);
    deriOuto2ByNeto2 = (outo2*(1-outo2));
    deriNeto1ByW6 = outh2;

    deriNeto1ByW7 = outh1;
    deriNeto1ByW8 = outh2;

    deriEtByW5 = deriEtByOuto1 * deriOuto1ByNeto1 * deriNeto1ByW5;
    w5New = w5- eta*deriEtByW5;

    deriEtByW6 = deriEtByOuto1 * deriOuto1ByNeto1 * deriNeto1ByW6;
    w6New = w6- eta*deriEtByW6;

    deriEtByW7 = deriEtByOuto2 * deriOuto2ByNeto2 * deriNeto1ByW7;
    w7New = w7- eta*deriEtByW7;

    deriEtByW8 = deriEtByOuto2 * deriOuto2ByNeto2 * deriNeto1ByW8;
    w8New = w8- eta*deriEtByW8;
    //for hidden layer

    long double deriEtByW1,deriEtByW2,deriEtByW3,deriEtByW4,deriEtByOuth1,deriEo1ByOuth1,deriEo2ByOuth1;
    long double deriEo1ByNeto1,deriNeto1ByOuth1,deriEo1ByOuto1,deriEo2ByOuto2,deriNeto2ByOuth1,deriEo2ByNeto2;

    deriEo1ByOuto1 = -(targeto1-outo1);
    deriEo2ByOuto2 = -(targeto2-outo2);
    deriEo1ByNeto1 = deriEo1ByOuto1 * deriOuto1ByNeto1;
    deriNeto1ByOuth1 = w5;
    deriNeto2ByOuth1 = w7;

    deriEo2ByNeto2 = deriEo2ByOuto2 * deriOuto2ByNeto2;

    deriEo1ByOuth1 = deriEo1ByNeto1 * deriNeto1ByOuth1;
    deriEo2ByOuth1 = deriEo2ByNeto2 * deriNeto2ByOuth1;

    deriEtByOuth1 = deriEo1ByOuth1 + deriEo2ByOuth1;

    long double deriOuth1ByNeth1,deriNeth1ByW1;

    deriOuth1ByNeth1 = outh1*(1-outh1);
    deriNeth1ByW1 = i1;

    deriEtByW1 = deriEtByOuth1*deriOuth1ByNeth1*deriNeth1ByW1;
    w1New = w1 - eta*deriEtByW1;
    //now for w2

    long double deriNeth1ByW2 = i2;

    deriEtByW2 = deriEtByOuth1 * deriOuth1ByNeth1 * deriNeth1ByW2;
    w2New = w2 - eta*deriEtByW2;
    //for w3
    long double deriEtByOuth2,deriOuth2ByNeth2,deriEo2ByOuth2,deriEo1ByOuth2,deriNeto2ByOuth2 = w8,deriNeth2ByW3 = i1,deriNeto1ByOuth2 = w6;

    deriOuth2ByNeth2 = outh2*(1-outh2);
    deriEo1ByOuth2 = deriEo1ByNeto1 * deriNeto1ByOuth2;
    deriEo2ByOuth2 = deriEo2ByNeto2 * deriNeto2ByOuth2;
    deriEtByOuth2 = deriEo1ByOuth2 + deriEo2ByOuth2;
    deriEtByW3 = deriEtByOuth2 * deriOuth2ByNeth2 * deriNeth2ByW3;
    w3New = w3 - eta*deriEtByW3;
    //for w4
    long double deriNeth2ByW4 = i2;
    deriEtByW4 = deriEtByOuth2 * deriOuth2ByNeth2 * deriNeth2ByW4;
    w4New = w4 - eta*deriEtByW4;

    cout<<"W1+ = "<<w1New<<endl<<"W2+ = "<<w2New<<endl<<"W3+ = "<<w3New<<endl<<"W4+ = "<<w4New<<endl;
    cout<<"W5+ = "<<w5New<<endl<<"W6+ = "<<w6New<<endl<<"W7+ = "<<w7New<<endl<<"W8+ = "<<w8New<<
            endl<<endl<<"Total Error: "<<etotal<<endl<<endl;

    w1 = w1New;
    w2 = w2New;
    w3 = w3New;
    w4 = w4New;
    w5 = w5New;
    w6 = w6New;
    w7 = w7New;
    w8 = w8New;

    }
    return 0;
}

