// Analog Inputs

int bottle_sensor = 0;
int heater_sensor = 1;
int cooler_sensor = 2;

// Outputs

int refri_output = 13;
int lcd_backlight = 8;
int lcd_contrast = 9;
int bt_tx = 6;
int bt_rx = 7;
int development_mode_pin = 3; 


int developers_option = 0;
int error_codes = 0; 

int lcd_status = -1;


int g_oner = -1;
int g_offer = -1;
int g_all_off = -1;
int g_cooler_on = -1;
int g_heater_on = -1;
int g_unwanted_reading = -1;


//***********************************************************************

#include <SoftwareSerial.h>
SoftwareSerial ktb(bt_tx,bt_rx);



#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);



void setup()
{
 Serial.begin(9600);
 
  pinMode(22,OUTPUT);
 pinMode(24,OUTPUT);
 pinMode(26,OUTPUT);
 pinMode(28,OUTPUT);
 pinMode(50,OUTPUT);
 pinMode(52,OUTPUT);
 pinMode(46,OUTPUT);
 pinMode(44,OUTPUT);
 pinMode(32,OUTPUT);
 pinMode(34,OUTPUT);
 pinMode(30,OUTPUT);
 pinMode(53,OUTPUT);
 pinMode(40,OUTPUT);
 pinMode(42,OUTPUT);
 pinMode(38,OUTPUT);
 pinMode(36,OUTPUT);
 pinMode(48,OUTPUT);
 pinMode(9,OUTPUT);
 pinMode(6,OUTPUT);
 digitalWrite(48,LOW);

  digitalWrite(22,LOW);
 digitalWrite(24,LOW);
 digitalWrite(26,LOW);
 digitalWrite(28,LOW);
 digitalWrite(50,LOW);
 digitalWrite(52,LOW);
 digitalWrite(46,LOW);
 digitalWrite(44,LOW);
 digitalWrite(32,LOW);
 digitalWrite(34,LOW);
 digitalWrite(30,LOW);
 digitalWrite(53,LOW);
 digitalWrite(40,LOW);
 digitalWrite(42,LOW);
 digitalWrite(38,LOW);
 digitalWrite(36,LOW);

 
 
 
 
 
 
 
 
 
 
 pinMode(refri_output,OUTPUT);
 pinMode(lcd_backlight,OUTPUT);
 pinMode(lcd_contrast,OUTPUT);
 digitalWrite(lcd_backlight,HIGH);
 analogWrite(lcd_contrast,25);

int development_mode=0;

//development_mode = analogRead(development_mode_pin);
Serial.print(development_mode);
Serial.print("\n");
if (development_mode > 127)
   {
    developers_option = 1;
    error_codes = 1; 
   }
 
 lcd.begin(16, 2);
 Serial.print("Setup DONE\n");
 if (developers_option == 0) 
    {
     welcome();
    }
if (error_codes)
   {
    delay(2000);
    Serial.print("\nSETUP DONE\n");
   
    lcd.clear();
    lcd.print("SETUP");
    lcd.setCursor(0,1);
    lcd.print("COMPLETED");
    delay(2000);
   }
}


//***********************************************************************






int bottle_check()
{
 int value;
 int oner;
 int offer;
 oner=0;
 offer=0;
  
 
 for (int a=0;a<1000;a++)
     {
      value=analogRead(bottle_sensor);
      if (value>100)
         {
          oner++; 
         }
      else
          {
           offer++; 
          }
     }
 
 /*
  If bottle removed
  oner = 100
  offer = 900
  Required OFF
  
  If bottle inserted
  oner = 500
  offer = 500
  Required ON
  
 */
 g_oner = oner;
 g_offer = offer;
 
 if (developers_option)
 {
 
 Serial.print("\n");
 Serial.print("Oner = ");
 Serial.print(oner);
 Serial.print("\n");
 Serial.print("Offer = ");
 Serial.print(offer);
 Serial.print("\n");
 
 
 ktb.print("\n");
 ktb.print("Oner = ");
 ktb.print(oner);
 ktb.print("\n");
 ktb.print("Offer = ");
 ktb.print(offer);
 ktb.print("\n");
 
 }
 
 
 if (offer>900)
 {
//  digitalWrite(pin_no,LOW);
  return(0);
 }
 
 int h_offer;
 h_offer = offer/5;
 
 if (oner>100)
 {
//  digitalWrite(pin_no,HIGH);
  return(1);
 }
  
}






//***********************************************************************




int refri_status()
{
  int cool_sens_no = cooler_sensor;
  int heat_sens_no = heater_sensor;
 
 /*
 Return 0 for both OFF
 
 
 
 Return 1 for Cooler ON
 
 
 
 Rerturn 2 for Heater ON
 
 
 
 */
 
 
 int cool_sens_val;
 int heat_sens_val;
 
 int all_off;
 int cooler_on;
 int heater_on;
 int unwanted_reading;
 
 all_off = 0;
 cooler_on = 0;
 heater_on = 0; 
 unwanted_reading=0;
 
 
 for (int time=0;time<1000;time++)
     {
      cool_sens_val = analogRead(cool_sens_no);
      heat_sens_val = analogRead(heat_sens_no);
      
      if (cool_sens_val == 0 && heat_sens_val == 0)
         {
          all_off++; 
         }
         
       else if (cool_sens_val < 100 && heat_sens_val < 100)
               {
                cooler_on++; 
               }
       else if (cool_sens_val > 100 && heat_sens_val > 100)
               {
                heater_on++; 
               }
       else 
           {
            unwanted_reading++; 
           }
     }
 
 g_all_off = all_off;
 g_cooler_on = cooler_on;
 g_heater_on = heater_on; 
 g_unwanted_reading = unwanted_reading;
  
 
 
 if (developers_option)
 {
 
 Serial.print("\n");
 Serial.print("All OFF = ");
 Serial.print(all_off);
 Serial.print("\n");
 Serial.print("Cooler ON = ");
 Serial.print(cooler_on);
 Serial.print("\n");
 Serial.print("Heater ON = ");
 Serial.print(heater_on);
 Serial.print("\n");
 Serial.print("Unwanted Reading = ");
 Serial.print(unwanted_reading);
 Serial.print("\n");

 ktb.print("\n");
 ktb.print("All OFF = ");
 ktb.print(all_off);
 ktb.print("\n");
 ktb.print("Cooler ON = ");
 ktb.print(cooler_on);
 ktb.print("\n");
 ktb.print("Heater ON = ");
 ktb.print(heater_on);
 ktb.print("\n");
 ktb.print("Unwanted Reading = ");
 ktb.print(unwanted_reading);
 ktb.print("\n");
 
 }
 
 
 if (all_off > 500)
    {
     return (0); 
    }
    
 if (cooler_on > 800)
    {
     return (1);
    }
    
 if (heater_on > 800)
    {
     return (2); 
    }
}





//***********************************************************************

/*
    0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5
    0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5


    K T B   &   V E N S - T E C H 5
    0 1 2 I N D U S T R I E S 3 4 5

    P R O U D L Y 8 9 9 0 1 2 3 4 5
    0 1 2 3 4 5 6 7 8 P R E S E N T

    0 1 2 3 4 5 T H E 9 0 1 2 3 4 5
    0 1 2 3 4 E - B A G 0 1 2 3 4 5



*/




void welcome()
{
 int scroller=0;
 loading();
  lcd.clear();

 lcd.print("KTB & VENS-TECH");
 lcd.setCursor(3,1);
 lcd.print("INDUSTRIES");
 delay(2000);
 
 for (scroller=0;scroller<17;scroller++)
      {
       lcd.scrollDisplayLeft();
       delay(150); 
      }

 lcd.clear();

 lcd.print("PROUDLY");
 lcd.setCursor(9,1);
 lcd.print("PRESENT");
 delay(1500);

for (scroller=0;scroller<17;scroller++)
      {
       lcd.scrollDisplayLeft();
       delay(150); 
      }

 lcd.clear();
 
 lcd.setCursor(6,0);
 lcd.print("THE");
 lcd.setCursor(5,1);
 lcd.print("E-BAG");
 delay(2500);
 
 
for (scroller=0;scroller<17;scroller++)
      {
       lcd.scrollDisplayLeft();
       delay(150); 
      }

 lcd.clear();
   

 
}

//****************************************************************************


int lcd_disp()
{
 loading();
 
 if (bottle_check() == 0 )
    {
/*
    0 1 2 3 4 B O T T L E 1 2 3 4 5
    0 1 2 N O T   D E T E C T E D 5




    0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5
    0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5



    0 1 2 3 4 5 I N S E R T 2 3 4 5
    0 1 2 3 4 5 B O T T L E 2 3 4 5
*/
 
 if (lcd_status != 1)
    {
      lcd.clear();
      lcd.setCursor(5,0);
     lcd.print("BOTTLE");
     lcd.setCursor(3,1);
     lcd.print("NOT DETECTED");
     delay(1500);
     lcd.clear();


     lcd.setCursor(6,0);
     lcd.print("INSERT");
     lcd.setCursor(6,1);
     lcd.print("BOTTLE");
//     delay(1500);
    
   lcd_status = 1;
    }
      
     if (developers_option)
        {
         delay(1000);

         Serial.print("\n");
         Serial.print("G_ONER = ");
         Serial.print(g_oner);
         Serial.print("\n");
         Serial.print("G_OFFER = ");
         Serial.print(g_offer);
         Serial.print("\n\n");


         lcd.clear();
         lcd.print("ONER = ");
         lcd.print(g_oner);
         lcd.setCursor(0,1);
         lcd.print("OFFER = ");
         lcd.print(g_offer);
         delay(3000);
         
      
if (error_codes)
   {
    delay(2000);
    Serial.print("\nNo Bottle Error\n");
   
    lcd.clear();
    lcd.print("NO BOTTLE");
    lcd.setCursor(0,1);
    lcd.print("ERROR");
    delay(2000);
   }
    
        }
     
     return(0);
    } 
 
 
 
 if (refri_status()==0)
    {
     if (lcd_status != 2)
     {
      lcd.clear();
     lcd.print("     E-BAG");
     lcd.setCursor(0,1);
//     lcd.print("Switch on Mains");
     lcd_status = 2;  
     }
     
     
     if (developers_option)
        {
         delay(1000);

         Serial.print("\n");
         Serial.print("Main Switch OFF Detected");
         Serial.print("\n");



/*
    0 1 2 3 A L L   O F F 1 2 3 4 5
    0 1 2 3 4 5 * * * * 0 1 2 3 4 5
    
    0 1 2 C O O L E R   O N 2 3 4 5
    0 1 2 3 4 5 * * * * 0 1 2 3 4 5
     
    0 1 2 H E A T E R   O N 2 3 4 5
    0 1 2 3 4 5 * * * * 0 1 2 3 4 5




    0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5
    0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5

*/

         lcd.clear();
         lcd.setCursor(4,0);
         lcd.print("ALL OFF");
         lcd.setCursor(6,1);
         lcd.print(g_all_off);
         delay(2000);
         lcd.clear();
         lcd.setCursor(3,0);
         lcd.print("COOLER ON");
         lcd.setCursor(6,1);
         lcd.print(g_cooler_on);
         delay(2000);
         lcd.clear();
         lcd.setCursor(3,0);
         lcd.print("HEATER ON");
         lcd.setCursor(6,1);
         lcd.print(g_heater_on);
         delay(2000);
        
        }
        
        if (error_codes)
   {
    delay(2000);
    Serial.print("\nMains OFF\n");
   
    lcd.clear();
    lcd.setCursor(5,0);
    lcd.print("MAINS");
    lcd.setCursor(6,1);
    lcd.print("OFF");
    
    delay(2000);
   }



     return(1);
    }
    
/*    
    1 2 3 4 C O O L I N G 2 3 4 5 6
    1 2 3 A C T I V A T E D 3 4 5 6
    
*/    

if (refri_status()==1)
   {
     if (lcd_status != 3)
     {
      lcd.clear();
     lcd.setCursor(4,0);
     lcd.print("COOLING");
     lcd.setCursor(3,1);
     lcd.print("ACTIVATED");
     delay(1000);
     lcd.clear();
     delay(1000);     
     lcd.setCursor(4,0);
     lcd.print("COOLING");
     lcd.setCursor(3,1);
     lcd.print("ACTIVATED");
     delay(1000);
     lcd.clear();
     delay(1000);
     lcd.setCursor(4,0);
     lcd.print("COOLING");
     lcd.setCursor(3,1);
     lcd.print("ACTIVATED");
     delay(1000);
     lcd.clear();
     delay(1000);
     lcd.setCursor(4,0);
     lcd.print("COOLING");
     lcd.setCursor(3,1);
     lcd.print("ACTIVATED");
     lcd_status = 3;
     }
     
     if (developers_option)
        {
         delay(1000);

         Serial.print("\n");
         Serial.print("COOLING ACTIVATED");
         Serial.print("\n");



/*
    0 1 2 3 A L L   O F F 1 2 3 4 5
    0 1 2 3 4 5 * * * * 0 1 2 3 4 5
    
    0 1 2 C O O L E R   O N 2 3 4 5
    0 1 2 3 4 5 * * * * 0 1 2 3 4 5
     
    0 1 2 H E A T E R   O N 2 3 4 5
    0 1 2 3 4 5 * * * * 0 1 2 3 4 5




    0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5
    0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5

*/

         lcd.clear();
         lcd.setCursor(4,0);
         lcd.print("ALL OFF");
         lcd.setCursor(6,1);
         lcd.print(g_all_off);
         delay(2000);
         lcd.clear();
         lcd.setCursor(3,0);
         lcd.print("COOLER ON");
         lcd.setCursor(6,1);
         lcd.print(g_cooler_on);
         delay(2000);
         lcd.clear();
         lcd.setCursor(3,0);
         lcd.print("HEATER ON");
         lcd.setCursor(6,1);
         lcd.print(g_heater_on);
         delay(2000);
        
        }

if (error_codes)
   {
    delay(2000);
    Serial.print("\nCooling Activated\n");
   
    lcd.clear();
    lcd.setCursor(4,0);
    lcd.print("COOLING");
    lcd.setCursor(4,1);
    lcd.print("STARTED");
    delay(2000);
   }


     return(2);
     }
/*
    1 2 3 4 H E A T I N G 2 3 4 5 6
    1 2 3 A C T I V A T E D 3 4 5 6
*/



if (refri_status()==2)
   {
     if (lcd_status != 4)
     {
     lcd.clear();
     lcd.setCursor(4,0);
     lcd.print("HEATING");
     lcd.setCursor(3,1);
     lcd.print("ACTIVATED");
     delay(1000);
     lcd.clear();
     delay(1000);     
     lcd.setCursor(4,0);
     lcd.print("HEATING");
     lcd.setCursor(3,1);
     lcd.print("ACTIVATED");
     delay(1000);
     lcd.clear();
     delay(1000);
     lcd.setCursor(4,0);
     lcd.print("HEATING");
     lcd.setCursor(3,1);
     lcd.print("ACTIVATED");
     delay(1000);
     lcd.clear();
     delay(1000);
     lcd.setCursor(4,0);
     lcd.print("HEATING");
     lcd.setCursor(3,1);
     lcd.print("ACTIVATED"); 
     lcd_status = 4;
     }


     
     if (developers_option)
        {
         delay(1000);

         Serial.print("\n");
         Serial.print("HEATING ACTIVATED");
         Serial.print("\n");



/*
    0 1 2 3 A L L   O F F 1 2 3 4 5
    0 1 2 3 4 5 * * * * 0 1 2 3 4 5
    
    0 1 2 C O O L E R   O N 2 3 4 5
    0 1 2 3 4 5 * * * * 0 1 2 3 4 5
     
    0 1 2 H E A T E R   O N 2 3 4 5
    0 1 2 3 4 5 * * * * 0 1 2 3 4 5




    0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5
    0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5

*/

         lcd.clear();
         lcd.setCursor(4,0);
         lcd.print("ALL OFF");
         lcd.setCursor(6,1);
         lcd.print(g_all_off);
         delay(2000);
         lcd.clear();
         lcd.setCursor(3,0);
         lcd.print("COOLER ON");
         lcd.setCursor(6,1);
         lcd.print(g_cooler_on);
         delay(2000);
         lcd.clear();
         lcd.setCursor(3,1);
         lcd.print("HEATER ON");
         lcd.setCursor(6,1);
         lcd.print(g_heater_on);
         delay(2000);
        
        }

if (error_codes)
   {
    delay(2000);
    Serial.print("\nHeating Started\n");
   
   
    lcd.clear();
    lcd.setCursor(4,0);
    lcd.print("COOLING");
    lcd.setCursor(4,1);
    lcd.print("STARTED");
    delay(2000);
   }


     return(3);  

}

}



//***********************************************************************

void loop()
{
 int initial_status=0;
 int final_status=0;

 
  
 if (bottle_check())
    {
     digitalWrite(refri_output,HIGH); 
    }
 else
     {
      digitalWrite(refri_output,LOW);
     }
     
 lcd_disp();
 //++
 delay(4000);

if (developers_option)
   {
    Serial.print("LCD STATUS = ");
    Serial.print(lcd_status); 
   }

/*
while(initial_status ==  final_status)
{
initial_status = bottle_check() + refri_status();
delay(500);
final_status = bottle_check() + refri_status();

int flag=0;

if (developers_option)
   {
    
    Serial.print("No Activity Detected");
    flag=1;
   }

if (flag==1)
   {
    Serial.print("\n"); 
   }

if (error_codes)
   {
    delay(2000);
    lcd.clear();
    lcd.print("DOING NOTHING");
    delay(2000);
   }

}

*/

 
}



//***********************************************************************


void loading()
{
  for(int i=0;i<100;i++)
 {
 lcd.clear();
 lcd.setCursor(4,0);
 lcd.print("LOADING");
 lcd.setCursor(6,1);
 lcd.print(i);
 lcd.print("%");
 led_num(i);
 delay(25);



 }
 led_all_pin_low();
 
 digitalWrite(22,HIGH);
 digitalWrite(30,HIGH);

 lcd.clear();
 lcd.setCursor(4,0);
 lcd.print("LOADING");
 lcd.setCursor(6,1);
 lcd.print("100");
 lcd.print("%");

 delay(1000);
 digitalWrite(22,LOW);
 digitalWrite(30,LOW);
 
}

void led_num(int numb)
{
 if (numb<100)
 {
  int n1;
  int n2;
 
  n2 = numb%10; 
  numb = numb - n2;
  n1 = numb/10;
 
  led_num_1(n1);
  led_num_2(n2);
 }
 
 else
 {
 digitalWrite(22,LOW);
 digitalWrite(24,LOW);
 digitalWrite(26,LOW);
 digitalWrite(28,LOW);
 digitalWrite(50,LOW);
 digitalWrite(52,LOW);
 digitalWrite(46,LOW);
 digitalWrite(44,LOW);
 digitalWrite(32,LOW);
 digitalWrite(34,LOW);
 digitalWrite(30,LOW);
 digitalWrite(23,LOW);
 digitalWrite(40,LOW);
 digitalWrite(42,LOW);
 digitalWrite(38,LOW);
 digitalWrite(36,LOW);

  digitalWrite(26,HIGH);   
  digitalWrite(24,HIGH);   
  digitalWrite(22,HIGH);   
  digitalWrite(50,HIGH);   
  digitalWrite(52,HIGH);   
  digitalWrite(42,HIGH);   
  digitalWrite(30,HIGH);   
 }
}


void led_num_1(int num)
{
 digitalWrite(22,LOW);
 digitalWrite(24,LOW);
 digitalWrite(26,LOW);
 digitalWrite(28,LOW);
 digitalWrite(50,LOW);
 digitalWrite(52,LOW);
 digitalWrite(46,LOW);
 digitalWrite(44,LOW);
 switch(num)
 {
 case 1:
        digitalWrite(28,HIGH);
        digitalWrite(46,HIGH);
        break;
 case 2:
        digitalWrite(26,HIGH);
        digitalWrite(28,HIGH);
        digitalWrite(22,HIGH);
        digitalWrite(50,HIGH);
        digitalWrite(52,HIGH);
        break;

 case 3:
        digitalWrite(26,HIGH);
        digitalWrite(28,HIGH);
        digitalWrite(22,HIGH);
        digitalWrite(46,HIGH);
        digitalWrite(52,HIGH);
        break;

 case 4:
        digitalWrite(24,HIGH);
        digitalWrite(22,HIGH);
        digitalWrite(28,HIGH);
        digitalWrite(46,HIGH);
        break;

 case 5:
        digitalWrite(26,HIGH);
        digitalWrite(24,HIGH);
        digitalWrite(22,HIGH);
        digitalWrite(46,HIGH);
        digitalWrite(52,HIGH);
        break;

 case 6:
        digitalWrite(26,HIGH);
        digitalWrite(24,HIGH);
        digitalWrite(22,HIGH);
        digitalWrite(46,HIGH);
        digitalWrite(52,HIGH);
        digitalWrite(50,HIGH);
        break;

 case 7:
        digitalWrite(26,HIGH);
        digitalWrite(28,HIGH);
        digitalWrite(46,HIGH);
        break;

 case 8:
        digitalWrite(26,HIGH);
        digitalWrite(24,HIGH);
        digitalWrite(22,HIGH);
        digitalWrite(28,HIGH);
        digitalWrite(50,HIGH);
        digitalWrite(52,HIGH);
        digitalWrite(46,HIGH);
        break;

 case 9:
        digitalWrite(22,HIGH);
        digitalWrite(24,HIGH);
        digitalWrite(26,HIGH);
        digitalWrite(28,HIGH);
        digitalWrite(46,HIGH);
        digitalWrite(52,HIGH);
        break;

 case 0:
        digitalWrite(24,HIGH);
        digitalWrite(26,HIGH);
        digitalWrite(28,HIGH);
        digitalWrite(46,HIGH);
        digitalWrite(50,HIGH);
        digitalWrite(52,HIGH);
        break;
 }
}






void led_num_2(int num)
{
 digitalWrite(32,LOW);
 digitalWrite(34,LOW);
 digitalWrite(30,LOW);
 digitalWrite(53,LOW);
 digitalWrite(40,LOW);
 digitalWrite(42,LOW);
 digitalWrite(38,LOW);
 digitalWrite(36,LOW);
 switch(num)
 {
 case 1:
        digitalWrite(53,HIGH);
        digitalWrite(38,HIGH);
        break;
 case 2:
        digitalWrite(34,HIGH);
        digitalWrite(53,HIGH);
        digitalWrite(30,HIGH);
        digitalWrite(42,HIGH);
        digitalWrite(40,HIGH);
        break;

 case 3:
        digitalWrite(34,HIGH);
        digitalWrite(53,HIGH);
        digitalWrite(30,HIGH);
        digitalWrite(38,HIGH);
        digitalWrite(40,HIGH);
        break;

 case 4:
        digitalWrite(32,HIGH);
        digitalWrite(30,HIGH);
        digitalWrite(53,HIGH);
        digitalWrite(38,HIGH);
        break;

 case 5:
        digitalWrite(34,HIGH);
        digitalWrite(32,HIGH);
        digitalWrite(30,HIGH);
        digitalWrite(38,HIGH);
        digitalWrite(40,HIGH);
        break;

 case 6:
        digitalWrite(34,HIGH);
        digitalWrite(32,HIGH);
        digitalWrite(30,HIGH);
        digitalWrite(42,HIGH);
        digitalWrite(40,HIGH);
        digitalWrite(38,HIGH);
        break;

 case 7:
        digitalWrite(34,HIGH);
        digitalWrite(53,HIGH);
        digitalWrite(38,HIGH);
        break;

 case 8:
        digitalWrite(32,HIGH);
        digitalWrite(34,HIGH);
        digitalWrite(53,HIGH);
        digitalWrite(30,HIGH);
        digitalWrite(38,HIGH);
        digitalWrite(40,HIGH);
        digitalWrite(42,HIGH);
        break;

 case 9:
        digitalWrite(30,HIGH);
        digitalWrite(32,HIGH);
        digitalWrite(34,HIGH);
        digitalWrite(53,HIGH);
        digitalWrite(38,HIGH);
        digitalWrite(40,HIGH);
        break;

 case 0:
        digitalWrite(53,HIGH);
        digitalWrite(34,HIGH);
        digitalWrite(32,HIGH);
        digitalWrite(38,HIGH);
        digitalWrite(40,HIGH);
        digitalWrite(42,HIGH);
        break;
 }

}




void led_all_pin_low()
{
 digitalWrite(22,LOW);
 digitalWrite(24,LOW);
 digitalWrite(26,LOW);
 digitalWrite(28,LOW);
 digitalWrite(50,LOW);
 digitalWrite(52,LOW);
 digitalWrite(46,LOW);
 digitalWrite(44,LOW);
 digitalWrite(32,LOW);
 digitalWrite(34,LOW);
 digitalWrite(30,LOW);
 digitalWrite(53,LOW);
 digitalWrite(40,LOW);
 digitalWrite(42,LOW);
 digitalWrite(38,LOW);
 digitalWrite(36,LOW);
 
}


