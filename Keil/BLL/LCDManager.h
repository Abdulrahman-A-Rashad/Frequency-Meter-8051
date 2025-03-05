

#ifndef _LCDMANAGER_H_
#define _LCDMANAGER_H_

void init();
void lcd_print(char *str);
unsigned long return_7aga(int num_digits) ;
void print_result(unsigned long res);

void clearLCD();

#endif