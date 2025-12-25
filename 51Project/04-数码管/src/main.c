#include <STC89C5xRC.H>
#include <INTRINS.H>
#define SMG_EN P36
typedef unsigned char u8;
typedef unsigned int u16;

u8 arr[]={0X3F,0X06,0X5B,0X4F,0X66,0X6D,0X7D,0X07,0X7F,0X6F};
u8 dig[]={0,1,2,3,4,5,6,7};

void digital(u8 dig,u8 num){
    P1&=0XC7;//使P13，P14，P15为0
    dig<<=3;
    P1|=dig;
    P0=num;
}

void Delay100us(void)	//@11.0592MHz
{
	unsigned char data i;

	_nop_();
	i = 43;
	while (--i);
}

void Delay(u16 n){
    u8 i;
    for ( i = 0; i < n; i++)
    {
        Delay100us();
    }
}

void main(){
    u8 i;
    SMG_EN=0;
    while (1){
        
        for ( i = 4; i < 8; i++)
        {
            P0=0;
            digital(i,arr[i-3]);
            Delay(10);
        }
        
    }
}