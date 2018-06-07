   #include <Servo.h> 

Servo horizontal; // yatay servo 
int servoh = 90; 
Servo vertical; // dikey servo
int servov = 90; 

// LDR Pinlerinin girişleri

int ldrlt = 0; //LDR sol üst
int ldrrt = 1; //LDR sağ üst
int ldrld = 2; //LDR sol alt
int ldrrd = 3; //LDR sağ alt

void setup()
{
  Serial.begin(9600);
// Servo Motor Bağlantı pinleri
  horizontal.attach(10); 
  vertical.attach(9);

}

void loop() 
{

  int lt = analogRead(ldrlt); // Sol üst
  int rt = analogRead(ldrrt); // Sağ üst
  int ld = analogRead(ldrld); // Sol aşağı
  int rd = analogRead(ldrrd); // Sağ aşağıı

  
  int tol =  1  ; // Tolerans değerimiz

  int avt = (lt + rt)  /2; // Ortalama üst değeri
  int avd = (ld + rd) / 2; // Ortalama alt değeri
  int avl = (lt + ld) / 2; // Ortalama sol değeri
  int avr = (rt + rd) / 2; // Ortalama sağ değeri

  int dvert = avt - avd; // Üst ve alt değerlerinin farkı
  int dhoriz = avl - avr;// Sol ve sağ değerlerinin farkı

  if (-1*tol > dvert || dvert > tol) // Dikey eksendeki tolerans farkının kontrol edilmesi
  {
    if (avt > avd){
      servov = ++servov;

      if (servov > 180){
        servov = 180;
       }
    }
    else if (avt < avd)
{

      servov= --servov;
      if (servov < 0){
        servov = 0;
      }
    }
  vertical.write(servov);
}

  if (-1*tol > dhoriz || dhoriz > tol)// Yatay eksendeki tolerans farkının kontrol edilmesi
  {
          if (avl > avr){

                servoh = --servoh;
                
                if (servoh < 0){
                  servoh = 0;
                }
          }
          else if (avl < avr){

                  servoh = ++servoh;
                  
                  if (servoh > 180){
                    servoh = 180;
                  }
              }
          else if (avl == avr){
                 
           }
           horizontal.write(servoh);
           
  }
   delay(50);

   Serial.print("leftdown :");
   Serial.print(ld);
   Serial.print("\t");
   Serial.print("rightdown:");
   Serial.print(rd);
   Serial.print("\t");
   Serial.print("lefttop  :");
   Serial.print(lt);
   Serial.print("\t");
   Serial.print("righttop :");
   Serial.print(rt);
   Serial.print("\t");
   Serial.println();
 
}
