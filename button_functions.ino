/*
  0000000000111111
 0123456789012345
 0OVERRIDE WARNING
 1       ON
 */

void temp_disp()
{
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("TEMPERATURE");
  lcd.setCursor(7,1);
  lcd.print(temp_defined);
  delay(1000);
  ebag_disp();

}

void refrigerator_temperature_control()
{
  if (ref_rel == true)
  {
    temp_current = (analogRead(temperature)-10);
    if (temp_defined <= temp_current)
    {
      digitalWrite(refrigerator_relay,HIGH);
    }

    else
    {
      digitalWrite(refrigerator_relay,LOW);  
    }
  }
}

void ref_temp_disp()
{
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("REFRIGERATOR");
  lcd.setCursor(7,1);
  switch(ref_rel)
  {
  case 0:
    lcd.print("OFF");
    break;
  case 1:
    lcd.print("ON");
    break;


  }
  delay(1000);
  ebag_disp();

}

void disp_temp_disp()
{
  lcd.clear();
  lcd.setCursor(5,0);
  lcd.print("DISPLAY");
  lcd.setCursor(7,1);
  switch(disp)
  {
  case 0:
    lcd.print("OFF");
    break;
  case 1:
    lcd.print("ON");
    break;


  }
  delay(1000);
  ebag_disp();


}


void ovr_temp_disp()
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("OVERRIDE WARNING");
  lcd.setCursor(7,1);
  switch(override)
  {
  case 0:
    lcd.print("OFF");
    break;
  case 1:
    lcd.print("ON");
    break;


  }
  delay(1000);
  ebag_disp();


}

