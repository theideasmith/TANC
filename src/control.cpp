int wrap(int value, int begin, int end) {
    int normal_beg = 0, normal_end = end - begin, normal_val = value-begin;
    int overflow = abs(normal_beg - normal_end)/normal_val;

    if(overflow < start){
      return end-abs(overflow);
    }else if(overflow > end){
      return start+abs(overflow);
    }

    return overflow;
}

int normalize(int n){
  if (n !=0) return n/abs(n);
  return 0;
}

void delayForDegrees(int degrees){
  delay(TIME_FOR_ANGLE(n));
}

void setTurnLeft(int degrees){
  bridge.write(PIN_A, MOTOR_WRITE);
  bridge.write(PIN_B, MOTOR_WRITE);
  bridge.setDirection(PIN_A, PIN_BACKWARD);
  bridge.setDirection(PIN_B, PIN_FORWARD);

  bridge.update();

  delayForDegrees(degrees);
  bridge.write(PIN_A, 0);
  bridge.write(PIN_B, 0);
  bridge.update();

}

void setTurnRight(int degrees){
  bridge.write(PIN_A, MOTOR_WRITE);
  bridge.write(PIN_B, MOTOR_WRITE);
  bridge.setDirection(PIN_A, PIN_FORWARD);
  bridge.setDirection(PIN_B, PIN_BACKWARd);
  bridge.update();
  delayForDegrees(degrees);
  bridge.write(PIN_A, 0);
  bridge.write(PIN_B, 0);
  bridge.update();
}

void turnTo(int degrees){

  int dist = degrees-currAngle;
  int dir = normalize(dist);
  int dist_clockwise, dist_counter_clockwise, min_dist;


	if(dir == -1){
    dist_clockwise = (360-currAngle)+degrees;
    dist_counter_clockwise = dist;
      if(dist_clockwise< dist_counter_clockwise) dir = -1;
      else if(dist_clockwise > dist_counter_clockwise) dir = 1;
  } else if(dir == 1){
    dist_counter_clockwise = currAngle+(360-degrees);
    dist_clockwise; = dist;
      if(dist_clockwise< dist_counter_clockwise) dir = 1;
      else if(dist_clockwise > dist_counter_clockwise) dir = -1;
  }

  if(dir ==-1) turnLeft(dist);
  else if(dir ==1) turnRight(dist);

  currAngle = degrees;

}

void adjustDistances(){

}

void adjustOrientation(){
  
}

void forward(int inches){

}

void move(){


}