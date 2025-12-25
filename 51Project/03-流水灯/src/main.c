/**
 * CPU: 89C52
 * Freq: 12MHz
*/
#include <STC89C5xRC.H>
#include <INTRINS.H>

typedef unsigned char u8;
typedef unsigned int u16;

void Delay100ms(void)	//@11.0592MHz
{
	unsigned char data i, j;

	i = 180;
	j = 73;
	do
	{
		while (--j);
	} while (--i);
}

void main(void)
{
    u8 temp=1;
    while (1)
    {
        while (1)
        {
            P0=~temp;
        temp<<=1;
        Delay100ms();
        if(temp==0){
            temp=128;
            break;
        }
        }
        while (1)
        {
            P0=~temp;
        temp>>=1;
        Delay100ms();
        if (temp==0)
        {
            temp=1;
            break;
        }
        }
    }
}
