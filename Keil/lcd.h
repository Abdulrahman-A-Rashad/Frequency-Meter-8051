// Sends different commands to LCD
void command(unsigned char cmd)
{
 RW = 0;
 RS = 0;
 LCD_PORT = cmd;
 EN = 1;
 delay(20);
 EN = 0;
}

// Used to write data in char on LCD
void write_data(unsigned char ch)
{
  RW = 0;
  RS = 1;
  LCD_PORT = ch;
  EN = 1;
  delay(20);
  EN = 0;
}

// LCD initilaizer function
void init()
{
		command(0x38);  // for using 2 lines and 5X7 matrix of LCD
    delay(20);
    command(0x0F);  // turn display ON, cursor blinking
    delay(20);
    command(0x01);  //clear screen
    delay(20);
 
}
// Print string on LCD
void lcd_print(char *str) {
    while (*str) {
        write_data(*str++);
    }
}

