int EstadoBoton;     //Variable para controlar el estado del botón interior

void setup()
{
  EstadoBoton = 0;

  pinMode(7, INPUT_PULLUP);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, INPUT_PULLUP);
}


void loop()
{
analogWrite(9,map(analogRead(A0), 0, 1024, 255, 0));   //Rutina para el LED de cortesía exterior en una sola línea.

  if (!digitalRead(7)) {          //Rutina para el botón interior. Una pulsación lo enciende,
    delay(25);                    //la siguiente pulsación lo apaga.
    if (digitalRead(7)) {
      if (EstadoBoton == 1) {
        EstadoBoton = 0;

      } else {
        EstadoBoton = 1;

      }

    }

if (EstadoBoton == 0) {
    digitalWrite(10,LOW);

  } else if (EstadoBoton == 1) {
    digitalWrite(10,HIGH);
  }
  
  }
  
  if (!digitalRead(8)) {           //Programación para el botón exterior del timbre.
    tone(6,250,200);
    delay((100));

  }
 
  }
