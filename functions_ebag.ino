







int anti_theft()
{
  int waiting=5000;

  for (int t=0;t<waiting;t++)
  {
    repeat_functions();
    receiver_led_test();
    delay(1);       
    if (analogRead(receiver_1)>2)
    {
      for (int u=0;u<waiting;u++)
      {
        repeat_functions();
        receiver_led_test();
        delay(1);       
        if (analogRead(receiver_2)>2)
        {
          receiver_led_test();
          return(0);
        }
      }
      return(1);

    }
  }



  for (int t=0;t<waiting;t++)
  {
    repeat_functions();
    receiver_led_test();
    delay(1);       
    if (analogRead(receiver_2)>2)
    {
      for (int u=0;u<waiting;u++)
      {
        repeat_functions();
        receiver_led_test();
        delay(1);       
        if (analogRead(receiver_1)>2)
        {
          receiver_led_test();
          return(0);
        }
        return(2);

      }
    }
  }
}

void alarm (int t)
{
  if (override == false)
  {
    for(int i=0;i<20;i++)
    {
      digitalWrite(led_strip,HIGH);
      digitalWrite(buzzer,HIGH);  
      delay(t);
      digitalWrite(led_strip,LOW);
      digitalWrite(buzzer,LOW);  
      delay(t);
    }
  }
}



void detect()
{
  if (anti_theft() == 0)
  {
    ebag_disp();
  }


  if (anti_theft() == 1)
  {
    lcd.clear();
    lcd.setCursor(5,0);
    lcd.print("WALLET");
    lcd.setCursor(6,1);
    lcd.print("LOST");
    alarm(100);

  }
  if (anti_theft() == 2)
  {
    lcd.clear();
    lcd.setCursor(5,0);
    lcd.print("MOBILE");
    lcd.setCursor(6,1);
    lcd.print("LOST");
    alarm(100);

  }
}










void repeat_functions()
{
  button_detect();  
  refrigerator_temperature_control();
  //  state_disp();
}











