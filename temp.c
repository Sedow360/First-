#include<stdio.h>

int main()
{
    printf("Enter the prices:\n");
    float p[3]; float total=0;
    for (int i=0; i<=2; i++)
    {
        scanf("%f", &p[i]);
        total+=(p[i]);
    }
    printf("The total price with 18 percent gst is: %f", total*0.18);
    


     return 0;

}