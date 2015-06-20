#include <LiquidCrystal.h>

// Receiver Output Pins
#define receiver_1 A0
#define receiver_2 A1
#define receiver_3 A2
#define receiver_4 A3

// Extra Analog Pins
#define ap1 A4
#define ap2 A5
#define ap3 A6
#define ap4 A7

// Onboard LEDs
#define led_5 A8
#define led_4 A9
#define led_3 A11
#define led_2 A14
#define led_1 A15

// Board Status Display
#define bsd_1 40 // Board Status Display
#define bsd_2 42
#define bsd_3 38
#define bsd_4 28
#define bsd_5 36
#define bsd_6 32
#define bsd_7 30
#define bsd_8 26
#define bsd_g 34

// Main Display
#define md1_1 53 // Main Display 1    Main Display 2
#define md1_2 52 // Main Display 1    Main Display 2
#define md1_3 37 // Main Display 1    Main Display 2
#define md1_4 51 // Main Display 1    Main Display 2
#define md1_5 35 // Main Display 1    Main Display 2
#define md1_6 33 // Main Display 1    Main Display 2
#define md1_7 31 // Main Display 1    Main Display 2
#define md1_8 49 // Main Display 1    Main Display 2
#define md2_1 45 // Main Display 1    Main Display 2
#define md2_2 47 // Main Display 1    Main Display 2
#define md2_3 29 // Main Display 1    Main Display 2
#define md2_4 41 // Main Display 1    Main Display 2
#define md2_5 27 // Main Display 1    Main Display 2
#define md2_6 25 // Main Display 1    Main Display 2
#define md2_7 23 // Main Display 1    Main Display 2
#define md2_8 39 // Main Display 1    Main Display 2
#define mdg 43 // Main Display Ground

// Motor Driver
#define mot_driver_ip_1 22 // Motor Driver Input 1
#define mot_driver_ip_2 24 // Motor Driver Input 2
#define mot_driver_ip_3 21 // Motor Driver Input 3
#define mot_driver_ip_4 20 // Motor Driver Input 4

// RELAYS
#define refrigerator_relay mot_driver_ip_2
#define powerplug_relay mot_driver_ip_3

// LCD
#define lcd_rs 12
#define lcd_enable 11
#define lcd_d4 5
#define lcd_d5 4
#define lcd_d6 3
#define lcd_d7 2
#define lcd_contrast ap1
#define lcd_led_anode 14
#define lcd_led_cathode 15

// Sensors
#define bottle_detect ap3
#define temperature ap2
#define led_strip mot_driver_ip_1
#define buzzer 16

// Buttons
#define buttons_activator A7
#define button_1 8
#define button_2 7
#define button_3 44
#define button_4 46
#define button_5 48
#define button_6 50



LiquidCrystal lcd( lcd_rs , lcd_enable , lcd_d4 , lcd_d5 , lcd_d6 , lcd_d7 );

/*
  0 0 0 0 0 0 0 0 0 0 1 1 1 1 1 1
 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5
 0             K T B                     
 1                                    
 */

boolean ref_rel = false;
boolean pow_rel = false;

int temp_defined = 22;
int temp_current = 23;
boolean override = false;
boolean disp = true;
boolean developers_mode = false;


void setup()
{
  initialise_pins();
  Serial.begin(9600);
  lcd.begin(16,2);

  ebag_intro();
  //  welcome(); 
  all_led_off();
  ebag_disp();


}

int n = 0;
void loop ()
{
  delay(650);
  bsd(n);
  n++;
  display_funct();
  button_detect();
  refrigerator_temperature_control();
  detect();
  //  state_disp();
}










