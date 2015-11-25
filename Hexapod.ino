#include <Servo.h>

#define MID_LEG_MID 95
#define MID_LEG_MAX 115
#define MID_LEG_MIN 75

#define LEFT_LEG_MID 90
#define LEFT_LEG_MAX 125
#define LEFT_LEG_MIN 45

#define RIGHT_LEG_MID 90
#define RIGHT_LEG_MAX 125
#define RIGHT_LEG_MIN 45

#define MID_LEG_LIFT_RIGHT MID_LEG_MAX
#define MID_LEG_LIFT_LEFT MID_LEG_MIN

#define LEFT_LEG_FWD LEFT_LEG_MIN
#define LEFT_LEG_REV LEFT_LEG_MAX

#define RIGHT_LEG_FWD RIGHT_LEG_MAX
#define RIGHT_LEG_REV RIGHT_LEG_MIN

Servo midLeg;
Servo leftLeg;
Servo rightLeg;

void setup() {
  // put your setup code here, to run once:
  midLeg.attach(3);
  leftLeg.attach(5);  
  rightLeg.attach(6);
}
bool first = 1;
void loop() {
  // put your main code here, to run repeatedly:
  if (first) {
    first = 0;
    //setMidLeg(MID_LEG_LIFT_LEFT);
    walkFwd();
    walkFwd();
    walkFwd();

    delay(5000);
    zeroLegs();
  }
  
}

void zeroLegs() {
  setMidLeg(MID_LEG_LIFT_LEFT);
  delay(500);
  setLeftLeg(LEFT_LEG_MID);
  delay(200);
  
  setMidLeg(MID_LEG_LIFT_RIGHT);
  delay(500);
  setRightLeg(RIGHT_LEG_MID);
  delay(200);
  
  setMidLeg(MID_LEG_MID);  
}

void walkFwd() {
  setMidLeg(MID_LEG_LIFT_RIGHT);
  delay(500);
  setRightLeg(RIGHT_LEG_FWD);
  setLeftLeg(LEFT_LEG_REV);  
  delay(500);
  setMidLeg(MID_LEG_LIFT_LEFT);
  delay(500);
  setRightLeg(RIGHT_LEG_REV);
  setLeftLeg(LEFT_LEG_FWD);
  delay(500);
}

void walkRev() {
  setMidLeg(MID_LEG_LIFT_LEFT);
  delay(500);
  setRightLeg(RIGHT_LEG_FWD);
  setLeftLeg(LEFT_LEG_REV);  
  delay(500);
  setMidLeg(MID_LEG_LIFT_RIGHT);
  delay(500);
  setRightLeg(RIGHT_LEG_REV);
  setLeftLeg(LEFT_LEG_FWD);
  delay(500);
  //TODO: Implement
}

void walkLeft() {
  setMidLeg(MID_LEG_LIFT_RIGHT);
  delay(500);
  setRightLeg(RIGHT_LEG_FWD);
  setLeftLeg(LEFT_LEG_FWD);  
  delay(500);
  setMidLeg(MID_LEG_LIFT_RIGHT);
  delay(500);
  setRightLeg(RIGHT_LEG_REV);
  setLeftLeg(LEFT_LEG_REV);
  delay(500);
}

void walkRight() {
  setMidLeg(MID_LEG_LIFT_RIGHT);
  delay(500);
  setRightLeg(RIGHT_LEG_REV);
  setLeftLeg(LEFT_LEG_REV); 
  delay(500);
  setMidLeg(MID_LEG_LIFT_LEFT);
  delay(500);
  setRightLeg(RIGHT_LEG_FWD);
  setLeftLeg(LEFT_LEG_FWD);
  delay(500);
  //TODO: Implement
}

void setMidLeg(int val) {
  midLeg.write(constrain(val, MID_LEG_MIN, MID_LEG_MAX));
}

void setLeftLeg(int val) {
  leftLeg.write(constrain(val, LEFT_LEG_MIN, LEFT_LEG_MAX));
}

void setRightLeg(int val) {
  rightLeg.write(constrain(val, RIGHT_LEG_MIN, RIGHT_LEG_MAX));
}
