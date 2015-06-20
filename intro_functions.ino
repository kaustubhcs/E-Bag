void ebag_intro()
{
  lcd.clear();

  lcd.setCursor(6,0);
  lcd.print("THE");
  lcd.setCursor(5,1);
  lcd.print("E-BAG");
  delay(200);
  digitalWrite(md1_6,HIGH);
  delay(200);
  digitalWrite(md1_7,HIGH);
  delay(200);
  digitalWrite(md1_3,HIGH);
  delay(200);
  digitalWrite(md1_2,HIGH);
  delay(200);
  digitalWrite(md1_1,HIGH);
  delay(200);

  digitalWrite(md1_8,HIGH);
  delay(200);

  digitalWrite(md2_1,HIGH);
  delay(200);
  digitalWrite(md2_2,HIGH);
  delay(200);
  digitalWrite(md2_5,HIGH);
  delay(200);
  digitalWrite(md2_6,HIGH);
  delay(200);
  digitalWrite(md2_7,HIGH);
  delay(200);
  digitalWrite(md2_4,HIGH);
  delay(1000);

}


void welcome()
{
  int scroller=0;
  led_num(1000);

  lcd.clear();
  lcd.setCursor(6,0);
  lcd.print("KTB");
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

  ebag_disp();
  delay(2500);

  /*
  for (scroller=0;scroller<17;scroller++)
   {
   lcd.scrollDisplayLeft();
   delay(150); 
   }
   
   lcd.clear();
   */


}

void loading()
{
  all_led_off();
  for(int i=0;i<100;i++)
  {
    if (i>10)
    {
      digitalWrite(led_1,HIGH);
    }
    if (i>20)
    {
      digitalWrite(led_2,HIGH);      
    }
    if (i>40)
    {
      digitalWrite(led_3,HIGH);
    }
    if (i>60)
    {
      digitalWrite(led_4,HIGH);
    }
    if (i>80)
    {
      digitalWrite(led_5,HIGH);
    }

    lcd.clear();
    lcd.setCursor(4,0);
    lcd.print("LOADING");
    lcd.setCursor(6,1);
    lcd.print(i);
    lcd.print("%");
    led_num(i);
    delay(random(10,150));



  }
  led_all_pin_low();

  digitalWrite(md1_3,HIGH);
  digitalWrite(md2_3,HIGH);

  lcd.clear();
  lcd.setCursor(4,0);
  lcd.print("LOADING");
  lcd.setCursor(6,1);
  lcd.print("100");
  lcd.print("%");

  delay(1000);
  digitalWrite(md1_3,LOW);
  digitalWrite(md2_3,LOW);

}

