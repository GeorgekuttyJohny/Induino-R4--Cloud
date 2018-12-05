/*   Remote Controlled Binary Counter using the IR remote library
 
 This sketch transmits 0 to 1023 in increments
 
 */
 
 void setup()  
 {  
  pinMode(15,OUTPUT);  
 }  
 void loop()  
 {  
  for(int count=0; count<1023; count++)  
  {  
   for( int j=0;j<3;j++)  
   {  
   dec_to_bin_transmit(count);  
   delay(50);  
   }  
   delay(500);  
  }  
 }  
 void dec_to_bin_transmit(int val)  
 {  
  int cnt = 0;  
  pulseData(96); // Sending the Startbit  
  while(cnt<12) // Execute this 12 times to send 12 bits of data  
  {  
  if(val>0) // Checking if the decimal value is non-zero  
  {  
   if(val%2 == 0) // Binary reminder check, if reminder is 1 then we need to send a logical '1'  
   {  
    pulseData(24);  
   }  
   else// Binary reminder check, if reminder is not 1 then we need to send a logical '0'  
   {  
    pulseData(48);  
   }  
   val = val / 2;  
  }  
  else // when the decimal value becomes zero, start sending zeroes for the remaining bits  
  {  
   pulseData(24);  
  }  
  cnt++;  
  }  
 }  
 void pulseData(int no_of_cycles)  
 {  
  for(int i=0;i<no_of_cycles;i++)      
  {  
   digitalWrite(15,HIGH);  
   delayMicroseconds(13);  
   digitalWrite(15,LOW);  
   delayMicroseconds(12);  
  }  
  digitalWrite(15,LOW);  
  delayMicroseconds(600);// This delay is for the space between the signals 0.6 millseconds  
 }  
