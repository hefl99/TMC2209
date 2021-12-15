#include <Arduino.h>
#include <Streaming.h>
#include <TMC2209.h>

HardwareSerial & serial_stream = Serial1;

const long BAUD = 115200;

const int LOOP_DELAY = 2000;

// Instantiate TMC2209
TMC2209 stepper_driver;


void setup()
{
  // Setup serial communications
  Serial.begin(BAUD);

  // stepper_driver.setDebugOn(Serial);

  stepper_driver.setOperationModeToUart(serial_stream,TMC2209::UART_ADDRESS_0);
}

void loop()
{
  // stepper_driver.test();
  // Serial << "\n";
  // uint8_t version = stepper_driver.getVersion();
  // Serial << "stepper driver version: " << _HEX(version) << "\n";
  // Serial << "\n";

  if (stepper_driver.communicating())
  {
    Serial << "UART communicating with stepper driver!\n";
  }
  else
  {
    Serial << "UART not communicating with stepper driver!\n";
    return;
  }

  // stepper_driver.initialize();

  TMC2209::Status status = stepper_driver.getStatus();
  Serial << "status.over_temperature_warning = " << status.over_temperature_warning << "\n";
  Serial << "status.over_temperature_shutdown = " << status.over_temperature_shutdown << "\n";
  Serial << "status.short_to_ground_a = " << status.short_to_ground_a << "\n";
  Serial << "status.short_to_ground_b = " << status.short_to_ground_b << "\n";
  Serial << "status.low_side_short_a = " << status.low_side_short_a << "\n";
  Serial << "status.low_side_short_b = " << status.low_side_short_b << "\n";
  Serial << "status.open_load_a = " << status.open_load_a << "\n";
  Serial << "status.open_load_b = " << status.open_load_b << "\n";
  Serial << "status.over_temperature_120c = " << status.over_temperature_120c << "\n";
  Serial << "status.over_temperature_143c = " << status.over_temperature_143c << "\n";
  Serial << "status.over_temperature_150c = " << status.over_temperature_150c << "\n";
  Serial << "status.over_temperature_157c = " << status.over_temperature_157c << "\n";
  Serial << "status.current_scaling = " << status.current_scaling << "\n";
  Serial << "status.stealth_mode = " << status.stealth_mode << "\n";
  Serial << "status.standstill = " << status.standstill << "\n";

  // stepper_driver.setRunCurrent(100);
  // Serial << "\n";
  // stepper_driver.setHoldCurrent(50);
  // Serial << "\n";
  // stepper_driver.setHoldDelay(50);
  // Serial << "\n";

  // stepper_driver.setAllCurrentValues(100,50,50);
  // Serial << "\n";

  Serial << "\n";
  delay(LOOP_DELAY);
}
