#include <STC89C5xRC.H>
#include <INTRINS.H>
typedef unsigned char u8;
typedef unsigned int u16;
unsigned int i,j;

void Delay100ms(void)	//@11.0592MHz
{
	unsigned char data i, j, k;

	_nop_();
	i = 8;
	j = 1;
	k = 243;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);

}

void main(){
    u8 temp=1;
    u8 temp1=0;
    while (1)
    {
         for ( i = 0; i < 8; i++)
         {
            for ( j = 0; j < 8-i; j++)
            {
                P0=~temp;
                temp<<=1;
                P0=~((~P0)|temp1);
                Delay100ms();
            }
            temp1=temp1|temp;
            temp=1;
         }
         temp1=0;
    }
    
    
}