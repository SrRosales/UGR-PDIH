# Práctica 3: Experimentación con Arduino

## 1. Objetivos de la práctica

* Instalar las herramientas de trabajo con Arduino
* Configurar el dispositivo Arduino para hacer programas básicos
* Hacer programas sencillos de entrada/salida con Arduino

------

## 2. Introducción

### En esta práctica se propone crear y verificar el funcionamiento de diversos sistemas de control basados en Arduino. La mayoría de los proyectos están implementados de forma equivalente o similar en múltiples recursos en Internet, por lo que se aconseja analizar esas implementaciones y adaptarlas a los requisitos que se piden.

-----------------------

## 3. Requisitos Mínimos

1. Implementar el programa de parpadeo de LED, ampliándolo para que encienda 
y apague alternativamente tres LEDs (uno rojo, otro amarillo y otro verde), 
conectados a las salidas digitales 11, 12 y 13 del Arduino, a un intervalo de 1.5 
segundos. Crear el esquema con Fritzing y cargar el programa en Arduino para 
comprobar que funciona correctamente.

2. Partir del programa de parpadeo de LEDs anterior y ampliarlo con las 
modificaciones necesarias para que se encienda el LED rojo solo cuando se 
pulse un interruptor conectado a la entrada digital 7, y en ese momento se 
apaguen los LEDs amarillo y verde.

-------

## 4. Requisitos Ampliados

1. Secuencia de LEDs, encendiendo y apagando 4 LEDs secuencialmente, de 
forma similar a las lucecitas de "El coche fantástico".
2. Detector de la distancia a un objeto (usar el buzzer para hacer sonar un pitido 
en función de la distancia detectada por el sensor de ultrasonidos).
3. Detector de la cantidad de luz que haya en ese momento (usar un LED que se 
ilumine más o menos en función de la cantidad de luz detectada con el 
fotosensor).

-------

## Requisitos Mínimos

### - El primer ejercicio consiste en crear un circuito en el cual haya 3 Leds parpadenado de forma alternativa.

### ***Lista de componenetes:***

| Nombre  | Cantidad | Componente |
| ------------- | ------------- |------------- |
| U1 | 1 | Arduino 1 R3 |
| R1 | 1 | 220 Ω Resistencia |
| R2 | 1 | 220 Ω Resistencia |
| R3 | 1 | 220 Ω Resistencia |
| D1 | 1 | Rojo LED |
| D2 | 1 | Amarillo LED |
| D3 | 1 | Verde LED |

### ***Código:***

```
// C++ code
//
void setup()
{
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
}

void loop()
{
  digitalWrite(11, HIGH);
  delay(1500); // Wait for 1000 millisecond(s)
  digitalWrite(11, LOW);
  delay(1500); // Wait for 1000 millisecond(s)
  digitalWrite(12, HIGH);
  delay(1500); // Wait for 1000 millisecond(s)
  digitalWrite(12, LOW);
  delay(1500); // Wait for 1000 millisecond(s)
  digitalWrite(13, HIGH);
  delay(1500); // Wait for 1000 millisecond(s)
  digitalWrite(13, LOW);
  delay(1500); // Wait for 1000 millisecond(s)
}
```
### ***Circuito:***

![Ejer1](P3%20Ejer%201.png)

### - El segundo ejercicio consiste en crear un circuito a partir del ejercicio anterior en el cual hay un pulsador, cuando lo pulsamos se apagan el led verde y amarillo y se enciende el led rojo, en caso de no pulsarlo el led rojo esta apagado y los leds verde y amarillo encendido.

### ***Lista de componenetes:***

| Nombre  | Cantidad | Componente |
| ------------- | ------------- |------------- |
| U1 | 1 | Arduino 1 R3 |
| R1 | 1 | 220 Ω Resistencia |
| R2 | 1 | 220 Ω Resistencia |
| R3 | 1 | 220 Ω Resistencia |
| R4 | 1 | 220 Ω Resistencia |
| D1 | 1 | Rojo LED |
| D2 | 1 | Amarillo LED |
| D3 | 1 | Verde LED |
| S1 | 1 | Pulsador |

### ***Código:***

```
// C++ code
//

int pulsador = 0;
void setup()
{
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(7,INPUT);
}

void loop()
{
 pulsador = digitalRead(7);
  if(pulsador == LOW){
    digitalWrite(11, LOW);
    digitalWrite(12, HIGH);
    digitalWrite(13, HIGH);
  }else{
    digitalWrite(11, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
  }
}
```

### ***Circuito:***

![Ejer2](P3%20Ejer%202.png)

-------

## Requisitos Ampliados

### - El primer ejercicio consiste en crear un circuito en el cual teniendo 4 Leds de color rojo encenderlos y apagarlos de forma secuencial simulando las luces de "El coche fatástico".

### ***Lista de componenetes:***

| Nombre  | Cantidad | Componente |
| ------------- | ------------- |------------- |
| U1 | 1 | Arduino 1 R3 |
| R1 | 1 | 1 KΩ Resistencia |
| R2 | 1 | 1 KΩ Resistencia |
| R3 | 1 | 1 KΩ Resistencia |
| R4 | 1 | 1 KΩ Resistencia |
| D1 | 1 | Rojo LED |
| D2 | 1 | Rojo LED |
| D3 | 1 | Rojo LED |
| D4 | 1 | Rojo LED |

### ***Código:***

```
// C++ code
//
void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop()
{
  for(int i = 13; i > 10; i--){
    delay(220);
    digitalWrite(i, HIGH);
    delay(220);
	digitalWrite(i, LOW);
	}
  
  for(int i = 10; i < 13; i++){
    delay(220);
    digitalWrite(i, HIGH);
    delay(220);
	digitalWrite(i, LOW);
	}
}
```

### ***Circuito:***

![Ejer3](P3%20Ejer%203.png)

### - El segundo ejercicio consiste en crear un circuito en el cual tenemos que usar un buzzer que sonará dependiendo de lo que capte el sensor.

### ***Lista de componenetes:***

| Nombre  | Cantidad | Componente |
| ------------- | ------------- |------------- |
| U1 | 1 | Arduino 1 R3 |
| R1 | 1 | 1 KΩ Resistencia |
| PIR1 | 1 | -6.882850021331572 , -207.25779974063357 , -161.08871167396302 Sensor PIR |
| PIEZO1 | 1 | Piezo |

### ***Código:***

```
// C++ code
//

unsigned int sensor = 0;

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(11, INPUT);
}

void loop()
{
  sensor = digitalRead(11);
  digitalWrite(13, sensor);
}
```

### ***Circuito:***

![Ejer4](P3%20Ejer%204.png)

### - El tercer ejercicio consiste en crear un circuito en el cual tenemos crear un detector de luz, es decir, el fotosensor detecta cuanta luz recibe y dependiendo de ello el Led se iluminará con más intensidad o menos.

### ***Lista de componenetes:***

| Nombre  | Cantidad | Componente |
| ------------- | ------------- |------------- |
| U1 | 1 | Arduino 1 R3 |
| R1 | 1 | Fotorresistencia |
| R2 | 1 | 330 KΩ Resistencia |
| R3 | 1 | 1 KΩ Resistencia |
| D1 | 1 | Rojo LED |

### ***Código:***

```
int sensorluz = 0;
int umbral = 400;

void setup()
{
 Serial.begin(9600);
  
  pinMode(13, OUTPUT);
}

void loop()
{
  sensorluz = analogRead(A0);
  Serial.println(sensorluz);
  
 if (sensorluz < umbral){
    digitalWrite(13, HIGH);
  } else{
    digitalWrite(13, LOW);
  }
   
   delay(100);
}
```

### ***Circuito:***

![Ejer5](P3%20Ejer%205.png)
