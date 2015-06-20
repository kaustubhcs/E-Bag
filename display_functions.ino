void ebag_disp()
{
  lcd.clear();
  lcd.setCursor(6,0);
  lcd.print("THE");
  lcd.setCursor(5,1);
  lcd.print("E-BAG");
}

void display_funct()
{
  if (disp == true)
  {
    led_num(temp_current);
    digitalWrite(lcd_led_anode,HIGH);  
  }
  else
  {
//    all_led_off(); 
    led_md1_low();
    led_md2_low();
    digitalWrite(lcd_led_anode,LOW);
  }

}

void all_led_off()
{
  digitalWrite(led_1,LOW);
  digitalWrite(led_2,LOW);
  digitalWrite(led_3,LOW);
  digitalWrite(led_4,LOW);
  digitalWrite(led_5,LOW);

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
    led_all_pin_low();
  }
}



void led_all_pin_low()
{
  led_md1_low();
  led_md2_low();
}

void led_md1_low ()
{
  digitalWrite(md1_1,LOW);
  digitalWrite(md1_2,LOW);
  digitalWrite(md1_3,LOW);
  digitalWrite(md1_4,LOW);
  digitalWrite(md1_5,LOW);
  digitalWrite(md1_6,LOW);
  digitalWrite(md1_7,LOW);
  digitalWrite(md1_8,LOW);  
}

void led_md2_low()
{
  digitalWrite(md2_1,LOW);
  digitalWrite(md2_2,LOW);
  digitalWrite(md2_3,LOW);
  digitalWrite(md2_4,LOW);
  digitalWrite(md2_5,LOW);
  digitalWrite(md2_6,LOW);
  digitalWrite(md2_7,LOW);
  digitalWrite(md2_8,LOW);
}



void led_num_1(int num)
{
  led_md1_low();
  switch(num)
  {
  case 1:
    digitalWrite(md1_4,HIGH);
    digitalWrite(md1_7,HIGH);
    break;
  case 2:
    digitalWrite(md1_6,HIGH);
    digitalWrite(md1_7,HIGH);
    digitalWrite(md1_1,HIGH);
    digitalWrite(md1_2,HIGH);
    digitalWrite(md1_3,HIGH);
    break;

  case 3:
    digitalWrite(md1_6,HIGH);
    digitalWrite(md1_7,HIGH);
    digitalWrite(md1_1,HIGH);
    digitalWrite(md1_3,HIGH);
    digitalWrite(md1_4,HIGH);
    break;

  case 4:
    digitalWrite(md1_5,HIGH);
    digitalWrite(md1_7,HIGH);
    digitalWrite(md1_3,HIGH);
    digitalWrite(md1_4,HIGH);
    break;

  case 5:
    digitalWrite(md1_5,HIGH);
    digitalWrite(md1_6,HIGH);
    digitalWrite(md1_1,HIGH);
    digitalWrite(md1_3,HIGH);
    digitalWrite(md1_4,HIGH);
    break;

  case 6:
    digitalWrite(md1_6,HIGH);
    digitalWrite(md1_5,HIGH);
    digitalWrite(md1_1,HIGH);
    digitalWrite(md1_2,HIGH);
    digitalWrite(md1_3,HIGH);
    digitalWrite(md1_4,HIGH);
    break;

  case 7:
    digitalWrite(md1_6,HIGH);
    digitalWrite(md1_7,HIGH);
    digitalWrite(md1_4,HIGH);
    break;

  case 8:
    digitalWrite(md1_1,HIGH);
    digitalWrite(md1_2,HIGH);
    digitalWrite(md1_3,HIGH);
    digitalWrite(md1_4,HIGH);
    digitalWrite(md1_5,HIGH);
    digitalWrite(md1_6,HIGH);
    digitalWrite(md1_7,HIGH);
    break;

  case 9:
    digitalWrite(md1_5,HIGH);
    digitalWrite(md1_6,HIGH);
    digitalWrite(md1_7,HIGH);
    digitalWrite(md1_1,HIGH);
    digitalWrite(md1_3,HIGH);
    digitalWrite(md1_4,HIGH);

    break;

  case 0:
    digitalWrite(md1_5,HIGH);
    digitalWrite(md1_6,HIGH);
    digitalWrite(md1_7,HIGH);
    digitalWrite(md1_1,HIGH);
    digitalWrite(md1_2,HIGH);
    digitalWrite(md1_4,HIGH);
    break;
  }
}



void led_num_2(int num)
{
  led_md2_low();
  switch(num)
  {
  case 1:
    digitalWrite(md2_4,HIGH);
    digitalWrite(md2_7,HIGH);
    break;
  case 2:
    digitalWrite(md2_6,HIGH);
    digitalWrite(md2_7,HIGH);
    digitalWrite(md2_1,HIGH);
    digitalWrite(md2_2,HIGH);
    digitalWrite(md2_3,HIGH);
    break;

  case 3:
    digitalWrite(md2_6,HIGH);
    digitalWrite(md2_7,HIGH);
    digitalWrite(md2_1,HIGH);
    digitalWrite(md2_3,HIGH);
    digitalWrite(md2_4,HIGH);
    break;

  case 4:
    digitalWrite(md2_5,HIGH);
    digitalWrite(md2_7,HIGH);
    digitalWrite(md2_3,HIGH);
    digitalWrite(md2_4,HIGH);
    break;

  case 5:
    digitalWrite(md2_5,HIGH);
    digitalWrite(md2_6,HIGH);
    digitalWrite(md2_1,HIGH);
    digitalWrite(md2_3,HIGH);
    digitalWrite(md2_4,HIGH);
    break;

  case 6:
    digitalWrite(md2_6,HIGH);
    digitalWrite(md2_5,HIGH);
    digitalWrite(md2_1,HIGH);
    digitalWrite(md2_2,HIGH);
    digitalWrite(md2_3,HIGH);
    digitalWrite(md2_4,HIGH);
    break;

  case 7:
    digitalWrite(md2_6,HIGH);
    digitalWrite(md2_7,HIGH);
    digitalWrite(md2_4,HIGH);
    break;

  case 8:
    digitalWrite(md2_1,HIGH);
    digitalWrite(md2_2,HIGH);
    digitalWrite(md2_3,HIGH);
    digitalWrite(md2_4,HIGH);
    digitalWrite(md2_5,HIGH);
    digitalWrite(md2_6,HIGH);
    digitalWrite(md2_7,HIGH);
    break;

  case 9:
    digitalWrite(md2_5,HIGH);
    digitalWrite(md2_6,HIGH);
    digitalWrite(md2_7,HIGH);
    digitalWrite(md2_1,HIGH);
    digitalWrite(md2_3,HIGH);
    digitalWrite(md2_4,HIGH);
    break;

  case 0:
    digitalWrite(md2_5,HIGH);
    digitalWrite(md2_6,HIGH);
    digitalWrite(md2_7,HIGH);
    digitalWrite(md2_1,HIGH);
    digitalWrite(md2_2,HIGH);
    digitalWrite(md2_4,HIGH);
    break;
  }
}




void bsd_low()
{
  digitalWrite(bsd_1,LOW);
  digitalWrite(bsd_2,LOW);
  digitalWrite(bsd_3,LOW);
  digitalWrite(bsd_4,LOW);
  digitalWrite(bsd_5,LOW);
  digitalWrite(bsd_6,LOW);
  digitalWrite(bsd_7,LOW);
  digitalWrite(bsd_8,LOW); 
}





void bsd (int num)
{
  bsd_low();
  switch(num)
  {
  case 1:
    digitalWrite(bsd_4,HIGH);
    digitalWrite(bsd_7,HIGH);
    break;
  case 2:
    digitalWrite(bsd_6,HIGH);
    digitalWrite(bsd_7,HIGH);
    digitalWrite(bsd_1,HIGH);
    digitalWrite(bsd_2,HIGH);
    digitalWrite(bsd_3,HIGH);
    break;

  case 3:
    digitalWrite(bsd_6,HIGH);
    digitalWrite(bsd_7,HIGH);
    digitalWrite(bsd_1,HIGH);
    digitalWrite(bsd_3,HIGH);
    digitalWrite(bsd_4,HIGH);
    break;

  case 4:
    digitalWrite(bsd_5,HIGH);
    digitalWrite(bsd_7,HIGH);
    digitalWrite(bsd_3,HIGH);
    digitalWrite(bsd_4,HIGH);
    break;

  case 5:
    digitalWrite(bsd_5,HIGH);
    digitalWrite(bsd_6,HIGH);
    digitalWrite(bsd_1,HIGH);
    digitalWrite(bsd_3,HIGH);
    digitalWrite(bsd_4,HIGH);
    break;

  case 6:
    digitalWrite(bsd_6,HIGH);
    digitalWrite(bsd_5,HIGH);
    digitalWrite(bsd_1,HIGH);
    digitalWrite(bsd_2,HIGH);
    digitalWrite(bsd_3,HIGH);
    digitalWrite(bsd_4,HIGH);
    break;

  case 7:
    digitalWrite(bsd_6,HIGH);
    digitalWrite(bsd_7,HIGH);
    digitalWrite(bsd_4,HIGH);
    break;

  case 8:
    digitalWrite(bsd_1,HIGH);
    digitalWrite(bsd_2,HIGH);
    digitalWrite(bsd_3,HIGH);
    digitalWrite(bsd_4,HIGH);
    digitalWrite(bsd_5,HIGH);
    digitalWrite(bsd_6,HIGH);
    digitalWrite(bsd_7,HIGH);
    break;

  case 9:
    digitalWrite(bsd_5,HIGH);
    digitalWrite(bsd_6,HIGH);
    digitalWrite(bsd_7,HIGH);
    digitalWrite(bsd_1,HIGH);
    digitalWrite(bsd_3,HIGH);
    digitalWrite(bsd_4,HIGH);
    break;

  case 0:
    digitalWrite(bsd_5,HIGH);
    digitalWrite(bsd_6,HIGH);
    digitalWrite(bsd_7,HIGH);
    digitalWrite(bsd_1,HIGH);
    digitalWrite(bsd_2,HIGH);
    digitalWrite(bsd_4,HIGH);
    break;
  }
}

