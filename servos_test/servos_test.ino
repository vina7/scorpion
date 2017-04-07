/* This example shows how to smoothly control a single servo on a
Maestro servo controller using the PololuMaestro library. It
assumes you have an RC hobby servo connected on channel 0 of your
Maestro, and that you have already used the Maestro Control
Center software to verify that the servo is powered correctly and
moves when you command it to from the Maestro Control Center
software.
Before using this example, you should go to the Serial Settings
tab in the Maestro Control Center and apply these settings:
* Serial mode: UART, fixed baud rate
* Baud rate: 9600
* CRC disabled
Be sure to click "Apply Settings" after making any changes.
This example also assumes you have connected your Arduino to your
Maestro appropriately. If you have not done so, please see
https://github.com/pololu/maestro-arduino for more details on how
to make the connection between your Arduino and your Maestro. */

#include <PololuMaestro.h>

/* On boards with a hardware serial port available for use, use
that port to communicate with the Maestro. For other boards,
create a SoftwareSerial object using pin 10 to receive (RX) and
pin 11 to transmit (TX). */
#ifdef SERIAL_PORT_HARDWARE_OPEN
  #define maestroSerial SERIAL_PORT_HARDWARE_OPEN
#else
  #include <SoftwareSerial.h>
  SoftwareSerial maestroSerial(10, 11);
#endif

/* Next, create a Maestro object using the serial port.
Uncomment one of MicroMaestro or MiniMaestro below depending
on which one you have. */
//MicroMaestro maestro(maestroSerial);
MiniMaestro maestro(maestroSerial);

void setup()
{
  // Set the serial baud rate.
  maestroSerial.begin(9600);

  maestro.setSpeed(0, 5);
  maestro.setAcceleration(0,127);
  maestro.setSpeed(1, 5);
  maestro.setAcceleration(1,127);
}

void loop()
{
  int i;

  maestro.reset();
  
  /* setSpeed takes channel number you want to limit and the
  speed limit in units of (1/4 microseconds)/(10 milliseconds).
  A speed of 0 makes the speed unlimited, so that setting the
  target will immediately affect the position. Note that the
  actual speed at which your servo moves is also limited by the
  design of the servo itself, the supply voltage, and mechanical
  loads. */
  //maestro.setSpeed(i, 0);
  /* setAcceleration takes channel number you want to limit and
  the acceleration limit value from 0 to 255 in units of (1/4
  microseconds)/(10 milliseconds) / (80 milliseconds).
  A value of 0 corresponds to no acceleration limit. An
  acceleration limit causes the speed of a servo to slowly ramp
  up until it reaches the maximum speed, then to ramp down again
  as the position approaches the target, resulting in relatively
  smooth motion from one point to another. */
  //maestro.setAcceleration(i, 0);

  maestro.setSpeed(0, 10);
  maestro.setAcceleration(0,127);
  maestro.setSpeed(1, 10);
  maestro.setAcceleration(1,127);

  // Initial position
  maestro.setTarget(0, 2000);
  maestro.setTarget(1, 2000);
  delay(8000);

  maestro.setSpeed(0, 10);
  maestro.setAcceleration(0,127);
  maestro.setSpeed(1, 10);
  maestro.setAcceleration(1,127);

  // Move 90 degrees
  maestro.setTarget(0, 10000);
  maestro.setTarget(1, 10000);
  delay(8000);
  
  
  

  
  
}
