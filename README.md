# Sensor de temperatura DS18B20 con Arduino
El sensor de temperatura cuenta con un alto grado de precisión, más que el LM35. En este tutorial veremos cómo configurarlo con un Arduino.

### Requisitos
- Tener el IDE de [Arduino](https://www.arduino.cc/en/Main/Software) (o el de tu preferencia) con la versión más actual
- Contar con las librerías [OneWire](https://github.com/PaulStoffregen/OneWire) y [DallasTemperature](https://github.com/milesburton/Arduino-Temperature-Control-Library)
- Tener el material para hacer el proyecto

### Código
**[Aqui](https://github.com/proyectoTEOS/Sensor-de-temperatura-DS18B20-con-Arduino/blob/master/Sensor-de-temperatura-DS18B20-con-Arduino.ino)** podrás obtener el link del código, también dejaremos
una vista previa aquí abajo.

```c++
/*
  Created by TEOS
  Domotic with Arduino https://goo.gl/btZpjs
  YouTube https://goo.gl/k7TUSZ
  Instagram https://goo.gl/zEIjia
  Facebook https://goo.gl/eivraR
  Twitter https://goo.gl/du5Wgn
  Github https://goo.gl/Xl5IiS
  WEB https://www.proyecto-teos.com
*/

#include <OneWire.h> //https://github.com/PaulStoffregen/OneWire
#include <DallasTemperature.h> //https://github.com/milesburton/Arduino-Temperature-Control-Library

const uint8_t dsPinT = 2;

OneWire wireT(dsPinT);
DallasTemperature dallasT(&wireT);

void setup() {
  dallasT.begin();
  Serial.begin(9600);
}

void loop() {
  dallasT.requestTemperatures();
  String resultSerialT = "Temperatura actual: " + String(dallasT.getTempCByIndex(0)) + " °C";
  Serial.print(resultSerialT);
  delay(200);
}
```

### Diagrama
El siguiente esquemático muestra como se debe conectar todos los componentes con la placa.
![](https://github.com/proyectoTEOS/Sensor-de-temperatura-DS18B20-con-Arduino/blob/master/sensor-de-temperatura-ds18b20-con-arduino-5.jpg)
