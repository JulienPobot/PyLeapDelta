// Programme de démonstration du Leap Motion
// utilisant le Deltabot pour reproduire les mouvements

#include <Servo.h> 

// trois variables pour chacun des servos (sens horaire, A étant en haut.
Servo servoA, servoB, servoC;

// la position courante demandée
int posX = 90;
int posY = 90;
int posZ = 90;


void setup() 
{ 
  Serial.begin(115200);

  // initialisation des servomoteurs
  servoA.attach(8);
  servoB.attach(9);
  servoC.attach(10);
} 


void loop() 
{ 

  while (Serial.available()) {

    switch (Serial.read()) {
    case 'X':
      posX = Serial.parseInt();
      servoB.write(map(posX, -200,200,90,20));
      break;
    case 'Y':
      posY = Serial.parseInt();
      servoA.write(map(posY, 40,450,90,20));
      break;
    case 'Z':
      posZ = Serial.parseInt(); 
      servoC.write(map(posZ, -200,200,90,20));     
      
      break;
    default:
      Serial.print("Inconnu");   
    }

  }


}


