int switch_state = 0; 

void setup( ){ 
  pinMode(2, INPUT); 
  pinMode(13, OUTPUT); 
} 

void loop(){ 
  switch_state = digitalRead(2);   
  if (switch_state == HIGH){
    digitalWrite(13, HIGH);   
  }else{ 
    digitalWrite(13, LOW);   
  } 
  delay(10);
}