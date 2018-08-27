#include "mcc_generated_files/mcc.h"
#include "oled.h"

void OLED_Command( uint8_t temp)
{
  //Issues command to OLED W Click Board over SPI protocol
    
  OLED_CS_LAT = 0;
  OLED_DC_LAT = 0;
  SPI_Write( temp);
  OLED_CS_LAT = 1;
}

void OLED_Data( uint8_t temp)
{
  //Issues the pixel pattern for character to be displayed
    
  OLED_CS_LAT = 0;
  OLED_DC_LAT = 1;
  SPI_Write( temp);
  OLED_CS_LAT = 1;
}

void OLED_Initialize( void)
{
    // Initialize the OLED W Click Board
    
    OLED_RST_LAT = 0;
    __delay_ms(1000);
    OLED_RST_LAT = 1;
    __delay_ms(1000);
    OLED_Command(SSD1306_DISPLAYOFF);             //0xAE  Set OLED Display Off
    OLED_Command(SSD1306_SETDISPLAYCLOCKDIV);     //0xD5  Set Display Clock Divide Ratio/Oscillator Frequency
    OLED_Command(0x80);
    OLED_Command(SSD1306_SETMULTIPLEX);           //0xA8  Set Multiplex Ratio
    OLED_Command(39);
    
    OLED_Command(SSD1306_SETSEGMENTREMAP);        //0xA1  Set Segment Remap Inv
    OLED_Command(SSD1306_COMSCANDEC);             //0xC8  Set COM Output Scan Inv
    OLED_Command(SSD1306_SETSTARTLINE);           //0x40  Set Display Start Line
    
    OLED_Command(SSD1306_SETDISPLAYOFFSET);       //0xD3  Set Display Offset
    OLED_Command(0xA4);
    OLED_Command(SSD1306_CHARGEPUMP);             //0x8D  Set Charge Pump
    OLED_Command(0x14);                           //0x14  Enable Charge Pump
    OLED_Command(SSD1306_SETCOMPINS);             //0xDA  Set COM Pins Hardware Configuration
    OLED_Command(0x12);
    OLED_Command(SSD1306_SETCONTRAST);            //0x81   Set Contrast Control
    OLED_Command(0xAF);
    OLED_Command(SSD1306_SETPRECHARGE);           //0xD9   Set Pre-Charge Period
    OLED_Command(0x25);
    OLED_Command(SSD1306_SETVCOMDETECT);          //0xDB   Set VCOMH Deselect Level
    OLED_Command(0x20);
    OLED_Command(SSD1306_DISPLAYALLON_RESUME);    //0xA4   Set Entire Display On/Off
    OLED_Command(SSD1306_NORMALDISPLAY);          //0xA6   Set Normal/Inverse Display
    OLED_Command(SSD1306_DISPLAYON);              //0xAF   Set OLED Display On
} 

void OLED_SetRow( uint8_t address)
{
    //Sets the row at which a character has to be displayed
    
    address = (uint8_t)(0xB0 | address);
    OLED_Command( address);
}

void OLED_SetColumn( uint8_t address)
{
    //Sets the column at which a character has to be displayed
    
    address += 32;
    OLED_Command(( SSD1306_SETHIGHCOLUMN | (address >> 4))); // SET_HIGH_COLUMN
    OLED_Command(( 0x0f & address));        // SET LOW_COLUMN
}

void OLED_PutPicture( const uint8_t *pic)
{
    //Used to display the complete OLED W Click Board pattern
    
    unsigned int i,j;
    for( i=0; i<5; i++) // 5*8=40 pixel rows (actually 39)
    {
        OLED_SetRow( i);
        OLED_SetColumn( 0);
        for( j=0; j<96; j++)  // 96 pixel columns
        {
            OLED_Data( *pic++);
        }
    }
}

void OLED_Clear( void)
{
    unsigned char i,j;
    for( i=0; i<5; i++) // 5*8=40 pixel rows (actually 39)
    {
        OLED_SetRow( i);
        OLED_SetColumn( 0);
        for( j=0; j<96; j++)  
            OLED_Data( 0x00);
    }
    for(int j = 0; j < 400; j++){
        displayArray[j] = 0x00;
    }
    OLED_PutPicture(emptyArray);
}

void Write_String(char message[]){
    size_t len = strlen(message);
    sprintf(CharacterArray, message);
    Modify_Data(CharacterArray, 0, len);
    OLED_PutPicture(displayArray);
}

void Modify_Data(char c[], unsigned int offset, unsigned int limit)
{
    //Based on the character array sent, the OLED W click board changes the display
    
    unsigned int j;
    for(int p=0;p<=limit;p++)                                                   //Limit to number of characters to be displayed
    {
        for(j=0;j<5;j++)                                                        //Each digit is represented using 5 lines
        {
            int right;
            right=(j+((int)(c[p])-0x20)*5);
            displayArray[offset+j+(p*5)]=lookup[right];
        }
    }
}