#include <STC89C5xRC.H>
#include <INTRINS.H>
void Delay500ms(void)	//@11.0592MHz
{
	unsigned char data i, j, k;

	_nop_();
	i = 4;
	j = 129;
	k = 119;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}

void main(){
while (1)
{
	P00=0;
	P01=1;
	Delay500ms();
	P00=1;
	P01=0;
	Delay500ms();
}
}