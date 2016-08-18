/*  Test Sketch.
 *  Owen Ling
 *  August 2016
 *  
 *  This sketch is the first attempt at using the IR proximity sensor
 *  along side the dc motor with the motor driving forward and slowing
 *  down and coming to a stop as it approaches an object.
 *  
 *  The entire sketch is based on rough readings and is by no means fine
 *  tuned.
 */



void setup() {

}

void loop() {
  //  Pin Outs
  int motor_pin_one = 3;
  int motor_pin_two = 2;
  int sensor_pin = A0;
  
  //  Working Variables
  int sensor_value = 0;   //  Holds the latest average sensor reading.
  int max_speed = 250;    // This is the absolute maximum signal that may be sent to the motor.



  
  sensor_value = get_sensor_value(sensor_pin);
  car_speed = set_speed(sensor_value, max_speed);
  analogWrite(motor_pin_one, car_speed);
  analogWrite(motor_pin_two, car_speed);
}


/*
 *  Takes the analoge pin address as the input and returns
 *  the average of the 5 most recent values.  This prevents
 *  random spikes from a single signal effecting the speed
 *  too drastically.
 */
int get_sensor_value(int pin)
{
  int count = 0;
  int sum = 0;
  while (count <= 5)
  {
    sum += analogRead(pin);
    count++;
  }
  return sum / count;
}


/*
 *  Function is called after each cycle, and takes the average sensor value
 *  and returns the motor signal based on this.
 */
int set_speed(int sensor_val, int max_speed)
{
  if (max_speed - (sensor_val / 9) < 0)
  {
    return 0;
  }
  else if (sensor_val > 950)
  {
    return 0;
  }
  else
  {
    return max_speed - (sensor_val / 9);  // Playing around with default speed and the value division
  
}
