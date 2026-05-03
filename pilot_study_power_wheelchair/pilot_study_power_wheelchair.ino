const int x_axis = A0;
const int y_axis = A1;
const int in1 = 7;
const int in2 = 6;
const int in3 = 5;
const int in4 = 4;
const int e1 = 3; //ENB
const int e2 = 9; //ENA


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
  analogWrite(e1, 255);
  analogWrite(e2, 255);
  digitalWrite(in1 , LOW);
  digitalWrite(in2 , HIGH);
  digitalWrite(in3 , HIGH);
  digitalWrite(in4 , LOW);

  x_status = analogRead(x_axis);
  y_status = analogRead(y_axis);
  delay(100);

  Serial.println(x_status);
  Serial.println(y_status); 
}