#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
    int x1[4] = {0,0,1,1}, x2[4] = {0,1,0,1};
    int t[4]={0,0,0,1},y[4];
    float w0 = 0.3, w1 = 0.5, w2 = -0.4;
    float ita = 0.25, F;
    int i, iteration = 1;
    printf("Iteration : %d\n\n", iteration);
    for(i=0; i<4; i++)
    {
        F =(-1 * w0) + (x1[i] * w1) + (x2[i] * w2);
        if(F>0)
        {
            y[i] = 1;
        }
        else
        {
            y[i] = 0;
        }
        printf("Target Output : %d\t Actual Output : %d\n", t[i], y[i]);
        if (t[i] !=y[i])
        {
            w0 = w0 + (ita * (t[i] - y[i]) * (-1));
            w1 = w1 + (ita * (t[i] - y[i]) * x1[i]);
            w2 = w2 + (ita * (t[i] - y[i]) * x2[i]);
            i = -1;
            iteration++;
            printf("\n\nIteration : %d\n", iteration);
            printf("Updated Weights : \n");
            printf("w0 = %.2f\t w1 = %.2f\t w2 = %.2f\n ", w0,w1,w2);
        }
    }
}
