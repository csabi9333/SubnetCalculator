#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    char ip_class;
    char subnet_mask[]="Subnet Mask: ";
    unsigned int number_of_subnetwork, resulted_octet;
    unsigned int temp_value=100;
    unsigned int bit=0;

    printf("Please enter the address class(A,B,C) and number of subnetwork!(1,2,4,16,32,64) \n");
    scanf("%c %d", &ip_class, &number_of_subnetwork);

    if(number_of_subnetwork==1)
    {
        resulted_octet=0;
    }
    else
    {
        do
        {
            if(bit==0)
                temp_value=number_of_subnetwork/2;
            else
                temp_value=temp_value/2;
            bit++;

        }
        while(temp_value!=1);
    }
    resulted_octet=256-(pow(2,8-(bit)));

    switch(ip_class)
    {
        case 'A': printf("%s %d.%d.%d.%d",subnet_mask, 255,resulted_octet,0,0); break;
        case 'B': printf("%s %d.%d.%d.%d",subnet_mask, 255,255,resulted_octet,0); break;
        case 'C': printf("%s %d.%d.%d.%d",subnet_mask, 255,255,255,resulted_octet); break;
        default: printf("error");
    }
    return 0;
}
