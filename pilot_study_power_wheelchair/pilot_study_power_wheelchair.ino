const int x_axis = A0;
const int y_axis = A1;


int x_status;
int y_status;

void setup() {
  Serial.begin(9600);
}

void loop() {
  x_status = analogRead(x_axis);
  y_status = analogRead(y_axis);
  delay(100);

  Serial.println(x_status);
  Serial.println(y_status); 
}