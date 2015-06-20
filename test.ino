void bsd_receiver ()
{


}

void receiver_serial_test()
{
  Serial.print("Receiver 1: ");
  Serial.println(analogRead(receiver_1));
  Serial.print("Receiver 2: ");
  Serial.println(analogRead(receiver_2));
  Serial.print("Receiver 3: ");
  Serial.println(analogRead(receiver_3));
  Serial.print("Receiver 4: ");
  Serial.println(analogRead(receiver_4));
  delay(300);
}

void receiver_led_test()
{
  if (disp == true)
  {
    if (analogRead(receiver_1) > 2)
    {
      digitalWrite(led_1,HIGH);
    } 
    else
    {
      digitalWrite(led_1,LOW);   
    }

    if (analogRead(receiver_2) > 2)
    {
      digitalWrite(led_2,HIGH);
    } 
    else
    {
      digitalWrite(led_2,LOW);   
    }
  }
  else
  {
    digitalWrite(led_1,LOW);   
    digitalWrite(led_2,LOW);   
    digitalWrite(led_3,LOW);   
    digitalWrite(led_4,LOW);   
    digitalWrite(led_5,LOW);   

  }
  // delay(300);
}

void receiver_lcd_test()
{
  lcd.setCursor(0,0);
  lcd.print(analogRead(receiver_1));
  lcd.setCursor(8,0);
  lcd.print(analogRead(receiver_2));
  lcd.setCursor(0,1);
  lcd.print(analogRead(receiver_3));
  lcd.setCursor(8,1);
  lcd.print(analogRead(receiver_4));
  delay(300);
}


void sensor_serial_test()
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("LDR:");
  lcd.setCursor(4,0);
  lcd.print(analogRead(bottle_detect));
  lcd.setCursor(0,1);
  lcd.print("Temp: ");
  lcd.setCursor(5,1);
  lcd.print(analogRead(temperature));
  delay(100);
}


void button_test()
{
  Serial.print("Button 1: ");
  Serial.println(digitalRead(button_1)); 
  Serial.print("Button 2: ");
  Serial.println(digitalRead(button_2)); 
  Serial.print("Button 3: ");
  Serial.println(digitalRead(button_3)); 
  Serial.print("Button 4: ");
  Serial.println(digitalRead(button_4)); 
  Serial.print("Button 5: ");
  Serial.println(digitalRead(button_5)); 
  Serial.print("Button 6: ");
  Serial.println(digitalRead(button_6)); 
  Serial.println("\n\n");
  delay(500);
}


void state_disp()
{
  if (developers_mode)
  {
    Serial.print("ref_rel: ");
    Serial.println(ref_rel);
    Serial.print("pow_rel: ");
    Serial.println(pow_rel);
    Serial.print("temp_defined: ");
    Serial.println(temp_defined);
    Serial.print("override: ");
    Serial.println(override);
    Serial.print("disp: ");
    Serial.println(disp);
    Serial.print("developers_mode: ");
    Serial.println(developers_mode);
    delay(500);
  } 
}


