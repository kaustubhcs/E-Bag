


int button_detect()
{
  /*
  
   1 Refrigerator
   2 Power Plug
   3 Temperature ++
   4 Temperature --
   5 Display
   6 Override
   
   */


  switch(button_read()) 
  {

  case 1:
    if (ref_rel == false)
    {
      ref_rel = true;
      refrigerator_temperature_control();
      ref_temp_disp();

      return(0);

    }


    if (ref_rel == true)
    {  
      ref_rel = false;
      digitalWrite(refrigerator_relay,LOW);
      ref_temp_disp();
      return(0);
    } 

    break;

  case 2:
    if (pow_rel == false)
    {
      digitalWrite(powerplug_relay,HIGH);
      pow_rel = true;
      delay(500);
      return(0);

    }


    if (pow_rel == true)
    {  
      digitalWrite(powerplug_relay,LOW);
      pow_rel = false;
      delay(500);
      return(0);
    } 

    break;


  case 3:
    temp_defined = temp_defined + 1;
    temp_disp();


    break;

  case 4:
    temp_defined = temp_defined - 1;
    temp_disp();

    break;



  case 5:
    if (disp == true)
    {
      disp = false; 
      disp_temp_disp();
      display_funct();
      return(0);
    }
    if (disp == false)
    {
      disp = true; 
      disp_temp_disp();
      display_funct();
      return(0);
    }

    break;

  case 6:
    if (override == false)
    {
      override=true;
      ovr_temp_disp();
      return(0);
    }
    if (override == true)
    {
      override=false;
      ovr_temp_disp();
      return(0);
    }


    break;


  }
}

int button_read_2()
{
  if (digitalRead(button_1) == 0)
  {
    return(1); 
  }

  if (digitalRead(button_2) == 0)
  {
    return(2); 
  }

  if (digitalRead(button_3) == 0)
  {
    return(3); 
  }

  if (digitalRead(button_4) == 0)
  {
    return(4); 
  }

  if (digitalRead(button_5) == 0)
  {
    return(5);
  }

  if (digitalRead(button_6) == 0)
  {
    return(6); 
  }


  return(0);
}

int button_read()
{
  int a=-1;
  int b=-1;
  for (int i=0;i<10;i++)
  {
    a=button_read_2();
    delay(1);
    b=button_read_2();

    if (a == b );
    else
    {
      return(0);
    }
    return(b);
  }

}


