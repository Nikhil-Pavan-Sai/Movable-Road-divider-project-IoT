#define MP 9
#define MN 10
#define buz 13
#define red 5
#define yel 4
#define grn 3

#define trigPin 12
#define echoPin 11

int duration, distance;

void setup() 
{
  Serial.begin(9600);
  pinMode (trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(MP, OUTPUT);
  pinMode(MN, OUTPUT);
  pinMode(red,OUTPUT);
  pinMode(yel,OUTPUT);
  pinMode(grn,OUTPUT);
  pinMode(buz,OUTPUT);
  Serial.println("Setup Completed");
}

void loop() 
{
   int l;
   digitalWrite(red,1);
   delay(1000);
   digitalWrite(red,0);
   digitalWrite(yel,1);
   delay(500);
   digitalWrite(yel,0);
   digitalWrite(grn,1);
   l = density();
   Serial.println("Sensor Value = " + String(l));
   if(l<10)
   {
      Serial.println("Traffic is High");
      digitalWrite(buz,1);
      delay(3000);
      digitalWrite(buz,0);
      divider_front();
      delay(8000);  
      divider_back();
      delay(3000);
      digitalWrite(grn,0);
   }
   else
   {
    Serial.println("Traffic is Normal");
    delay(2000);
    digitalWrite(grn,0);
   }
   
  Serial.println();
  delay(500);
}

void divider_front()
{
  Serial.println("MOVING DIVIDER");
  analogWrite(MP,80);
  //digitalWrite(MP,1);
  analogWrite(MN,0);
  delay(800);
  analogWrite(MP,0);
  analogWrite(MN,0);
}

void divider_back()
{
  Serial.println("Moving Divider Back");
  analogWrite(MP,0);
  analogWrite(MN,80);
  //digitalWrite(MN,1);
  delay(800);
  digitalWrite(MP,0);
  digitalWrite(MN,0);
}

int density()
{
  digitalWrite (trigPin, HIGH);
  delay(50);
  digitalWrite (trigPin, LOW);
  duration=pulseIn(echoPin,HIGH);
  distance=(duration*0.034)/2;
  return distance; 
}

