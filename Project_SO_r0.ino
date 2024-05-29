//IR LED control for Project SO
// By Henry Chan
// Date: Dec2023
// Rev: 0 - 1st release
#include <Wire.h>
#include <MCP23017.h>
#include <SoftwareSerial.h>

#define MCP23017_ADDR 0x20  //always = 0x2_
#define MCP23017_ADDR1 0x27  //always = 0x2_
#define INT_PIN 3

MCP23017 mcp = MCP23017(MCP23017_ADDR);
MCP23017 mcp1 = MCP23017(MCP23017_ADDR1);

SoftwareSerial mySerial(11, 12); // RX, TX
String rec_data = "00";

bool interrupted = false;
int out_PortA = 0x00;
int out_PortB = 0x00;
int out_PortA1 = 0x00;

void led_output()
{
  Serial.print(out_PortA);
  Serial.print(";");
  Serial.print(out_PortB);
  Serial.print(";");
  Serial.println(out_PortA1);
  //mcp.writeRegister(MCP23017Register::GPIO_A, out_PortA);  
  //mcp.writeRegister(MCP23017Register::GPIO_B, out_PortB);  
  //mcp1.writeRegister(MCP23017Register::GPIO_A, out_PortA1);  
  mcp.writeRegister(MCP23017Register::GPIO_A, 255-out_PortA);   //invert 1 & 0
  mcp.writeRegister(MCP23017Register::GPIO_B, 255-out_PortB);   //invert 1 & 0 
  mcp1.writeRegister(MCP23017Register::GPIO_A, 255-out_PortA1);  //invert 1 & 0
}

void setup() {
  Wire.begin();
  Serial.begin(115200);
  mySerial.begin(115200);

  mcp.init();
  mcp1.init();
  mcp.portMode(MCP23017Port::A, 0);  //Port A as output
  mcp.portMode(MCP23017Port::B, 0);  //Port B as output
  mcp1.portMode(MCP23017Port::A, 0);  //Port A as output
  mcp1.portMode(MCP23017Port::B, 0);  //Port B as output
  
  led_output(); //initial value all high
  mcp1.writeRegister(MCP23017Register::GPIO_B, 255);  //initial value = 0b1111111
}

void loop() {
  Serial.println("restart again!!");
  while (mySerial.available()==0) {} //wait for data available
  rec_data = mySerial.readString();  //read until timeout
  rec_data.trim();                        // remove any \r \n whitespace at the end of the String
  if (rec_data == "00") { // all off
    out_PortA = 0x00;
    out_PortB = 0x00; 
    out_PortA1 = 0x00;
    Serial.println(out_PortA);
    Serial.println(out_PortB);
    Serial.println(out_PortA1);
  }
  else if (rec_data == "01") { // LED1
    out_PortA = 0b00000001;
    out_PortB = 0x00; 
    out_PortA1 = 0x00;
    Serial.println(out_PortA);
    Serial.println(out_PortB);
    Serial.println(out_PortA1);
  }
  else if (rec_data == "02") { // LED2
    out_PortA = 0b00000010;
    out_PortB = 0x00; 
    out_PortA1 = 0x00;
    Serial.println(out_PortA);
    Serial.println(out_PortB);
    Serial.println(out_PortA1);
  }
  else if (rec_data == "03") { // LED3
    out_PortA = 0b00000100;
    out_PortB = 0x00; 
    out_PortA1 = 0x00;
    Serial.println(out_PortA);
    Serial.println(out_PortB);
    Serial.println(out_PortA1);
  }
  else if (rec_data == "04") { // LED4
    out_PortA = 0b00001000;
    out_PortB = 0x00; 
    out_PortA1 = 0x00;
    Serial.println(out_PortA);
    Serial.println(out_PortB);
    Serial.println(out_PortA1);
  }
  else if (rec_data == "05") { // LED5
    out_PortA = 0x00; 
    out_PortB = 0b10000000;
    out_PortA1 = 0x00;
    Serial.println(out_PortA);
    Serial.println(out_PortB);
    Serial.println(out_PortA1);
  }
  else if (rec_data == "06") { // LED6
    out_PortA = 0x00; 
    out_PortB = 0b01000000;
    out_PortA1 = 0x00;
    Serial.println(out_PortA);
    Serial.println(out_PortB);
    Serial.println(out_PortA1);
  }
  else if (rec_data == "07") { // LED7
    out_PortA = 0x00; 
    out_PortB = 0b00100000;
    out_PortA1 = 0x00;
    Serial.println(out_PortA);
    Serial.println(out_PortB);
    Serial.println(out_PortA1);
  }
  else if (rec_data == "08") { // LED8
    out_PortA = 0x00; 
    out_PortB = 0b00010000;
    out_PortA1 = 0x00;
    Serial.println(out_PortA);
    Serial.println(out_PortB);
    Serial.println(out_PortA1);
  }
  else if (rec_data == "09") { // LED9
    out_PortA = 0b00010000;
    out_PortB = 0x00; 
    out_PortA1 = 0x00;
    Serial.println(out_PortA);
    Serial.println(out_PortB);
    Serial.println(out_PortA1);
  }
  else if (rec_data == "10") { // LED10
    out_PortA = 0b00100000;
    out_PortB = 0x00; 
    out_PortA1 = 0x00;
    Serial.println(out_PortA);
    Serial.println(out_PortB);
    Serial.println(out_PortA1);
  }
  else if (rec_data == "11") { // LED11
    out_PortA = 0b01000000;
    out_PortB = 0x00; 
    out_PortA1 = 0x00;
    Serial.println(out_PortA);
    Serial.println(out_PortB);
    Serial.println(out_PortA1);
  }
  else if (rec_data == "12") { // LED12
    out_PortA = 0b10000000;
    out_PortB = 0x00; 
    out_PortA1 = 0x00;
    Serial.println(out_PortA);
    Serial.println(out_PortB);
    Serial.println(out_PortA1);
  }
  else if (rec_data == "13") { // LED13
    out_PortA = 0x00;
    out_PortB = 0x00;
    out_PortA1 = 0b00001000; 
    Serial.println(out_PortA);
    Serial.println(out_PortB);
    Serial.println(out_PortA1);
  }
  else if (rec_data == "14") { // LED14
    out_PortA = 0x00;
    out_PortB = 0x00;
    out_PortA1 = 0b00000100; 
    Serial.println(out_PortA);
    Serial.println(out_PortB);
    Serial.println(out_PortA1);
  }
  else if (rec_data == "15") { // LED15
    out_PortA = 0x00;
    out_PortB = 0x00;
    out_PortA1 = 0b00000010; 
    Serial.println(out_PortA);
    Serial.println(out_PortB);
    Serial.println(out_PortA1);
  }
  else if (rec_data == "16") { // LED16
    out_PortA = 0x00;
    out_PortB = 0x00;
    out_PortA1 = 0b00000001; 
    Serial.println(out_PortA);
    Serial.println(out_PortB);
    Serial.println(out_PortA1);
  }
  else if (rec_data == "17") { // LED17
    out_PortA = 0x00;
    out_PortB = 0b00000001;
    out_PortA1 = 0x00; 
    Serial.println(out_PortA);
    Serial.println(out_PortB);
    Serial.println(out_PortA1);
  }
  else if (rec_data == "18") { // LED18
    out_PortA = 0x00;
    out_PortB = 0b00000010;
    out_PortA1 = 0x00; 
    Serial.println(out_PortA);
    Serial.println(out_PortB);
    Serial.println(out_PortA1);
  }
  else if (rec_data == "19") { // LED19
    out_PortA = 0x00;
    out_PortB = 0b00000100;
    out_PortA1 = 0x00; 
    Serial.println(out_PortA);
    Serial.println(out_PortB);
    Serial.println(out_PortA1);
  }
  else if (rec_data == "20") { // LED20
    out_PortA = 0x00;
    out_PortB = 0b00001000;
    out_PortA1 = 0x00; 
    Serial.println(out_PortA);
    Serial.println(out_PortB);
    Serial.println(out_PortA1);
  }
  else if (rec_data == "21") { // LED21
    out_PortA = 0x00;
    out_PortB = 0x00;
    out_PortA1 = 0b10000000; 
    Serial.println(out_PortA);
    Serial.println(out_PortB);
    Serial.println(out_PortA1);
  }
  else if (rec_data == "22") { // LED22
    out_PortA = 0x00;
    out_PortB = 0x00;
    out_PortA1 = 0b01000000; 
    Serial.println(out_PortA);
    Serial.println(out_PortB);
    Serial.println(out_PortA1);
  }
  else if (rec_data == "23") { // LED23
    out_PortA = 0x00;
    out_PortB = 0x00;
    out_PortA1 = 0b00100000; 
    Serial.println(out_PortA);
    Serial.println(out_PortB);
    Serial.println(out_PortA1);
  }
  else if (rec_data == "24") { // LED24
    out_PortA = 0x00;
    out_PortB = 0x00;
    out_PortA1 = 0b00010000; 
    Serial.println(out_PortA);
    Serial.println(out_PortB);
    Serial.println(out_PortA1);
  }
  led_output(); //initial value all high
}