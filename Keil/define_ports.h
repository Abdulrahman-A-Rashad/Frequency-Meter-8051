sbit EN = P2^1; // Enable LCD
sbit RW = P2^2; // Read Write 
sbit RS = P2^0; // Register Select
sbit signal_pin = P3^5;  // External signal input

#define LCD_PORT P1
int i, j;
unsigned char x,y;
