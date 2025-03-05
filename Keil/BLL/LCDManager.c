#include "LCD.h"
#include "LCDManager.h"

void init()
{
		command(0x38);  // for using 2 lines and 5X7 matrix of LCD
    delayUsingInstruction(20);
    command(0x0F);  // turn display ON, cursor blinking
    delayUsingInstruction(20);
    command(0x01);  //clear screen
    delayUsingInstruction(20);
 
}

void lcd_print(char *str) {
    while (*str) {
        write_data(*str++);
    }
}


unsigned long return_7aga(int num_digits)   
{
		unsigned long result = 1;
		int i;
		for(i = 0;i<num_digits-1;i++)
		{
				result = result*10;
		}
		return result;
}


void print_result(unsigned long res)
{
		if(res)
		{
				
				int num_digits = 0;
				unsigned long temp = res;
				while (temp > 0) 
				{
						num_digits++;
						temp /= 10;
				}
				while (num_digits >0) 
				{
						unsigned long y = return_7aga(num_digits);
						char z = ((res / y) + '0');
						write_data(z);
						res %= y;
						num_digits--;		
				}
		}
		else{
				write_data('0');
		}
}

void clearLCD(){
	command(0x01);
}