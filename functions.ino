void initialise_pins()
{
 // Receiver Output Pins
pinMode(receiver_1,INPUT);
pinMode(receiver_2,INPUT);
pinMode(receiver_3,INPUT);
pinMode(receiver_4,INPUT);

analogWrite(receiver_1,0);
analogWrite(receiver_2,0);
analogWrite(receiver_3,0);
analogWrite(receiver_4,0);


// Extra Analog Pins
pinMode(ap1,OUTPUT);
pinMode(ap2,INPUT);
pinMode(ap3,OUTPUT);
pinMode(ap4,OUTPUT);

analogWrite(ap1,0);
analogWrite(ap2,0);
analogWrite(ap3,0);
analogWrite(ap4,0);

// Onboard LEDs
pinMode(led_1,OUTPUT);
pinMode(led_2,OUTPUT);
pinMode(led_3,OUTPUT);
pinMode(led_4,OUTPUT);
pinMode(led_5,OUTPUT);

analogWrite(led_1,0);
analogWrite(led_2,0);
analogWrite(led_3,0);
analogWrite(led_4,0);
analogWrite(led_5,0);

// Board Status Display
pinMode(bsd_1,OUTPUT);
pinMode(bsd_2,OUTPUT);
pinMode(bsd_3,OUTPUT);
pinMode(bsd_4,OUTPUT);
pinMode(bsd_5,OUTPUT);
pinMode(bsd_6,OUTPUT);
pinMode(bsd_7,OUTPUT);
pinMode(bsd_8,OUTPUT);
pinMode(bsd_g,OUTPUT);

digitalWrite(bsd_1,LOW);
digitalWrite(bsd_2,LOW);
digitalWrite(bsd_3,LOW);
digitalWrite(bsd_4,LOW);
digitalWrite(bsd_5,LOW);
digitalWrite(bsd_6,LOW);
digitalWrite(bsd_7,LOW);
digitalWrite(bsd_8,LOW);
digitalWrite(bsd_g,LOW);


// Main Display
pinMode(md1_1,OUTPUT);
pinMode(md1_2,OUTPUT);
pinMode(md1_3,OUTPUT);
pinMode(md1_4,OUTPUT);
pinMode(md1_5,OUTPUT);
pinMode(md1_6,OUTPUT);
pinMode(md1_7,OUTPUT);
pinMode(md1_8,OUTPUT);

pinMode(md2_1,OUTPUT);
pinMode(md2_2,OUTPUT);
pinMode(md2_3,OUTPUT);
pinMode(md2_4,OUTPUT);
pinMode(md2_5,OUTPUT);
pinMode(md2_6,OUTPUT);
pinMode(md2_7,OUTPUT);
pinMode(md2_8,OUTPUT);
pinMode(mdg,OUTPUT);

digitalWrite(md1_1,LOW);
digitalWrite(md1_2,LOW);
digitalWrite(md1_3,LOW);
digitalWrite(md1_4,LOW);
digitalWrite(md1_5,LOW);
digitalWrite(md1_6,LOW);
digitalWrite(md1_7,LOW);
digitalWrite(md1_8,LOW);

digitalWrite(md2_1,LOW);
digitalWrite(md2_2,LOW);
digitalWrite(md2_3,LOW);
digitalWrite(md2_4,LOW);
digitalWrite(md2_5,LOW);
digitalWrite(md2_6,LOW);
digitalWrite(md2_7,LOW);
digitalWrite(md2_8,LOW);
digitalWrite(mdg,LOW);

// Motor Driver
pinMode(mot_driver_ip_1,OUTPUT);
pinMode(mot_driver_ip_2,OUTPUT);
pinMode(mot_driver_ip_3,OUTPUT);
pinMode(mot_driver_ip_4,OUTPUT);

digitalWrite(mot_driver_ip_1,LOW);
digitalWrite(mot_driver_ip_2,LOW);
digitalWrite(mot_driver_ip_3,LOW);
digitalWrite(mot_driver_ip_4,LOW);

// RELAYS
//pinMode(refrigerator_relay,OUTPUT);
//pinMode(powerplug_relay,OUTPUT);

//digitalWrite(refrigerator_relay,LOW);
//digitalWrite(powerplug_relay,LOW);

//LCD
pinMode(lcd_contrast,OUTPUT);
pinMode(lcd_led_anode,OUTPUT);
pinMode(lcd_led_cathode,OUTPUT);

analogWrite(lcd_contrast,0);
digitalWrite(lcd_led_anode,HIGH);
digitalWrite(lcd_led_cathode,LOW);

//Sensors
analogWrite(bottle_detect,1023);
pinMode(buzzer,OUTPUT);
digitalWrite(buzzer,LOW);

// Buttons
pinMode(buttons_activator, OUTPUT);
pinMode(button_1,INPUT);
pinMode(button_2,INPUT);
pinMode(button_3,INPUT);
pinMode(button_4,INPUT);
pinMode(button_5,INPUT);
pinMode(button_6,INPUT);

analogWrite(buttons_activator,0);
digitalWrite(button_1,HIGH);
digitalWrite(button_2,HIGH);
digitalWrite(button_3,HIGH);
digitalWrite(button_4,HIGH);
digitalWrite(button_5,HIGH);
digitalWrite(button_6,HIGH);

}
