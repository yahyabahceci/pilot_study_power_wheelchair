const int x_axis = A0;
const int y_axis = A1;
const int in1 = 7;
const int in2 = 6;
const int in3 = 5;
const int in4 = 4;
const int e1 = 3; //ENB left
const int e2 = 9; //ENA right

int x_status;
int y_status;

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(e1, OUTPUT);
  pinMode(e2, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  x_status = analogRead(x_axis);
  y_status = analogRead(y_axis);

  Serial.println(x_status);
  Serial.println(y_status); 

// moving forward  
  if (y_status < 200){
    digitalWrite(in1 , HIGH);
    digitalWrite(in2 , LOW);
    digitalWrite(in3 , HIGH);
    digitalWrite(in4 , LOW);

    if (x_status < 255){
      analogWrite(e1, x_status);
      analogWrite(e2, 255-x_status);
    }

    else if (x_status > 768){
      analogWrite(e1, x_status-768);
      analogWrite(e2, 255);
    }
    
    else if (x_status > 255 && x_status<768){
      analogWrite(e1, 255);
      analogWrite(e2, 255);
    }
  
  }

// moving back
  else if (y_status > 700){
    digitalWrite(in1 , LOW);
    digitalWrite(in2 , HIGH);
    digitalWrite(in3 , LOW);
    digitalWrite(in4 , HIGH);
    analogWrite(e1, 255);
    analogWrite(e2, 255);
  }

  else{
    analogWrite(e1, 0);
    analogWrite(e2, 0);
  }


  
}