#include <OneWire.h>
#include <DallasTemperature.h>
#define SensorPin A0
#define ONE_WIRE_BUS 8

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

double celsius = 0;
unsigned long int avgValue;
double b;
int buf[10],temp;

void setup()
{
  Serial.begin(9600);
}
void loop(){

  for(int i = 0; i < 10 ; i++)
  {
    buf[i]=analogRead(SensorPin);
    delay(10); 
  }
   for(int i = 0 ; i < 9 ;i++)
  {
      for(int j = i+1 ; j < 10 ;j++)
      {
        if(buf[i]>buf[j])
      {
        temp=buf[i];
        buf[i]=buf[j];
        buf[j]=temp;
      }
        avgValue=0;
   }
        
}

  for(int i=2 ; i<8; i++)
    avgValue+=buf[i];
  double phValue=(double)avgValue*5.0/1024/6;
  phValue = 3.5 * phValue;
//  Serial.print("  ph : ");
  
//  Serial.println(" ");
  delay(400);
  
  if(celsius > -127){
//   Serial.print("  Temperature = c :");
  Serial.print(phValue,2);
  Serial.print("-");
  Serial.println(celsius);
  }
  double ph=69.0;
  double suhu=27.0;
    
  sensors.requestTemperatures();
  celsius = sensors.getTempCByIndex(0);;
}
    
