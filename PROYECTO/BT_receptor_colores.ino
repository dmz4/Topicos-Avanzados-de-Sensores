#include <Adafruit_NeoPixel.h>

#include <SoftwareSerial.h>   // Incluimos la librería  SoftwareSerial  

#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

#define RXin 10
#define TXin 11
#define BTBauds 9600
#define PIN        5 // On Trinket or Gemma, suggest changing this to 1

#define NUMPIXELS 30 // Popular NeoPixel ring size

SoftwareSerial BT(RXin,TXin);    // Definimos los pines RX y TX del Arduino conectados al Bluetooth

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

char mensaje;

uint32_t magenta = pixels.Color(255,0,255);
uint32_t rojo = pixels.Color(255,0,0);
uint32_t verde = pixels.Color(0,255,0);
uint32_t azul = pixels.Color(0,0,255);
uint32_t amarillo = pixels.Color(0,255,255);
uint32_t cyan = pixels.Color(255,255,0);
uint32_t blanco = pixels.Color(255,255,255);
uint32_t anterior;

void setup(){
  BT.begin(BTBauds);       // Inicializamos el puerto serie BT (Para Modo AT 2)
  Serial.begin(BTBauds);   // Inicializamos  el puerto serie
  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
    clock_prescale_set(clock_div_1);
  #endif

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels.clear(); // Set all pixel colors to 'off'  
}
 
void loop(){
  if(BT.available()){
    mensaje = BT.read();
    Serial.println(mensaje);
  }
  switch (mensaje) {
  case '1':
    anterior = magenta;
    pixels.setPixelColor(0, magenta);
    pixels.setPixelColor(1, magenta);
    pixels.setPixelColor(2, magenta);
    pixels.setPixelColor(3, magenta);
    pixels.setPixelColor(4, magenta);
    pixels.setPixelColor(5, magenta);
    pixels.setPixelColor(6, magenta);
    pixels.setPixelColor(7, magenta);
    pixels.setPixelColor(8, magenta);
    pixels.setPixelColor(9, magenta);
    pixels.setPixelColor(10, magenta);
    pixels.setPixelColor(11, magenta);
    pixels.setPixelColor(12, magenta);
    pixels.setPixelColor(13, magenta);
    pixels.setPixelColor(14, magenta);
    pixels.setPixelColor(15, magenta);
    pixels.setPixelColor(16, magenta);
    pixels.setPixelColor(17, magenta);
    pixels.setPixelColor(18, magenta);
    pixels.setPixelColor(19, magenta);
    pixels.setPixelColor(20, magenta);
    pixels.setPixelColor(21, magenta);
    pixels.setPixelColor(22, magenta);
    pixels.setPixelColor(23, magenta);
    pixels.setPixelColor(24, magenta);
    pixels.setPixelColor(25, magenta);
    pixels.setPixelColor(26, magenta);
    pixels.setPixelColor(27, magenta);
    pixels.setPixelColor(28, magenta);
    pixels.setPixelColor(29, magenta);
    pixels.show();   // Send the updated pixel colors to the hardware.
    break;
  case '2':
    anterior = rojo;
    pixels.setPixelColor(0, rojo);
    pixels.setPixelColor(1, rojo);
    pixels.setPixelColor(2, rojo);
    pixels.setPixelColor(3, rojo);
    pixels.setPixelColor(4, rojo);
    pixels.setPixelColor(5, rojo);
    pixels.setPixelColor(6, rojo);
    pixels.setPixelColor(7, rojo);
    pixels.setPixelColor(8, rojo);
    pixels.setPixelColor(9, rojo);
    pixels.setPixelColor(10, rojo);
    pixels.setPixelColor(11, rojo);
    pixels.setPixelColor(12, rojo);
    pixels.setPixelColor(13, rojo);
    pixels.setPixelColor(14, rojo);
    pixels.setPixelColor(15, rojo);
    pixels.setPixelColor(16, rojo);
    pixels.setPixelColor(17, rojo);
    pixels.setPixelColor(18, rojo);
    pixels.setPixelColor(19, rojo);
    pixels.setPixelColor(20, rojo);
    pixels.setPixelColor(21, rojo);
    pixels.setPixelColor(22, rojo);
    pixels.setPixelColor(23, rojo);
    pixels.setPixelColor(24, rojo);
    pixels.setPixelColor(25, rojo);
    pixels.setPixelColor(26, rojo);
    pixels.setPixelColor(27, rojo);
    pixels.setPixelColor(28, rojo);
    pixels.setPixelColor(29, rojo);
    pixels.show();   // Send the updated pixel colors to the hardware.
    break;
  case '3':
    anterior = verde;
    pixels.setPixelColor(0, verde);
    pixels.setPixelColor(1, verde);
    pixels.setPixelColor(2, verde);
    pixels.setPixelColor(3, verde);
    pixels.setPixelColor(4, verde);
    pixels.setPixelColor(5, verde);
    pixels.setPixelColor(6, verde);
    pixels.setPixelColor(7, verde);
    pixels.setPixelColor(8, verde);
    pixels.setPixelColor(9, verde);
    pixels.setPixelColor(10, verde);
    pixels.setPixelColor(11, verde);
    pixels.setPixelColor(12, verde);
    pixels.setPixelColor(13, verde);
    pixels.setPixelColor(14, verde);
    pixels.setPixelColor(15, verde);
    pixels.setPixelColor(16, verde);
    pixels.setPixelColor(17, verde);
    pixels.setPixelColor(18, verde);
    pixels.setPixelColor(19, verde);
    pixels.setPixelColor(20, verde);
    pixels.setPixelColor(21, verde);
    pixels.setPixelColor(22, verde);
    pixels.setPixelColor(23, verde);
    pixels.setPixelColor(24, verde);
    pixels.setPixelColor(25, verde);
    pixels.setPixelColor(26, verde);
    pixels.setPixelColor(27, verde);
    pixels.setPixelColor(28, verde);
    pixels.setPixelColor(29, verde);    
    pixels.show();   // Send the updated pixel colors to the hardware.
    break;
  case '4':
    anterior = azul;
    pixels.setPixelColor(0, azul);
    pixels.setPixelColor(1, azul);
    pixels.setPixelColor(2, azul);
    pixels.setPixelColor(3, azul);
    pixels.setPixelColor(4, azul);
    pixels.setPixelColor(5, azul);
    pixels.setPixelColor(6, azul);
    pixels.setPixelColor(7, azul);
    pixels.setPixelColor(8, azul);
    pixels.setPixelColor(9, azul);
    pixels.setPixelColor(10, azul);
    pixels.setPixelColor(11, azul);
    pixels.setPixelColor(12, azul);
    pixels.setPixelColor(13, azul);
    pixels.setPixelColor(14, azul);
    pixels.setPixelColor(15, azul);
    pixels.setPixelColor(16, azul);
    pixels.setPixelColor(17, azul);
    pixels.setPixelColor(18, azul);
    pixels.setPixelColor(19, azul);
    pixels.setPixelColor(20, azul);
    pixels.setPixelColor(21, azul);
    pixels.setPixelColor(22, azul);
    pixels.setPixelColor(23, azul);
    pixels.setPixelColor(24, azul);
    pixels.setPixelColor(25, azul);
    pixels.setPixelColor(26, azul);
    pixels.setPixelColor(27, azul);
    pixels.setPixelColor(28, azul);
    pixels.setPixelColor(29, azul);
    pixels.show();   // Send the updated pixel colors to the hardware.
    break;
  case '5':
    anterior = amarillo;
    pixels.setPixelColor(0, amarillo);
    pixels.setPixelColor(1, amarillo);
    pixels.setPixelColor(2, amarillo);
    pixels.setPixelColor(3, amarillo);
    pixels.setPixelColor(4, amarillo);
    pixels.setPixelColor(5, amarillo);
    pixels.setPixelColor(6, amarillo);
    pixels.setPixelColor(7, amarillo);
    pixels.setPixelColor(8, amarillo);
    pixels.setPixelColor(9, amarillo);
    pixels.setPixelColor(10, amarillo);
    pixels.setPixelColor(11, amarillo);
    pixels.setPixelColor(12, amarillo);
    pixels.setPixelColor(13, amarillo);
    pixels.setPixelColor(14, amarillo);
    pixels.setPixelColor(15, amarillo);
    pixels.setPixelColor(16, amarillo);
    pixels.setPixelColor(17, amarillo);
    pixels.setPixelColor(18, amarillo);
    pixels.setPixelColor(19, amarillo);
    pixels.setPixelColor(20, amarillo);
    pixels.setPixelColor(21, amarillo);
    pixels.setPixelColor(22, amarillo);
    pixels.setPixelColor(23, amarillo);
    pixels.setPixelColor(24, amarillo);
    pixels.setPixelColor(25, amarillo);
    pixels.setPixelColor(26, amarillo);
    pixels.setPixelColor(27, amarillo);
    pixels.setPixelColor(28, amarillo);
    pixels.setPixelColor(29, amarillo);
    pixels.show();   // Send the updated pixel colors to the hardware.
    break;
  case '6':
    anterior = cyan;
    pixels.setPixelColor(0, cyan);
    pixels.setPixelColor(1, cyan);
    pixels.setPixelColor(2, cyan);
    pixels.setPixelColor(3, cyan);
    pixels.setPixelColor(4, cyan);
    pixels.setPixelColor(5, cyan);
    pixels.setPixelColor(6, cyan);
    pixels.setPixelColor(7, cyan);
    pixels.setPixelColor(8, cyan);
    pixels.setPixelColor(9, cyan);
    pixels.setPixelColor(10, cyan);
    pixels.setPixelColor(11, cyan);
    pixels.setPixelColor(12, cyan);
    pixels.setPixelColor(13, cyan);
    pixels.setPixelColor(14, cyan);
    pixels.setPixelColor(15, cyan);
    pixels.setPixelColor(16, cyan);
    pixels.setPixelColor(17, cyan);
    pixels.setPixelColor(18, cyan);
    pixels.setPixelColor(19, cyan);
    pixels.setPixelColor(20, cyan);
    pixels.setPixelColor(21, cyan);
    pixels.setPixelColor(22, cyan);
    pixels.setPixelColor(23, cyan);
    pixels.setPixelColor(24, cyan);
    pixels.setPixelColor(25, cyan);
    pixels.setPixelColor(26, cyan);
    pixels.setPixelColor(27, cyan);
    pixels.setPixelColor(28, cyan);
    pixels.setPixelColor(29, cyan);
    pixels.show();   // Send the updated pixel colors to the hardware.
    break;
  default:
    pixels.setPixelColor(0, anterior);
    pixels.setPixelColor(1, anterior);
    pixels.setPixelColor(2, anterior);
    pixels.setPixelColor(3, anterior);
    pixels.setPixelColor(4, anterior);
    pixels.setPixelColor(5, anterior);
    pixels.setPixelColor(6, anterior);
    pixels.setPixelColor(7, anterior);
    pixels.setPixelColor(8, anterior);
    pixels.setPixelColor(9, anterior);
    pixels.setPixelColor(10, anterior);
    pixels.setPixelColor(11, anterior);
    pixels.setPixelColor(12, anterior);
    pixels.setPixelColor(13, anterior);
    pixels.setPixelColor(14, anterior);
    pixels.setPixelColor(15, anterior);
    pixels.setPixelColor(16, anterior);
    pixels.setPixelColor(17, anterior);
    pixels.setPixelColor(18, anterior);
    pixels.setPixelColor(19, anterior);
    pixels.setPixelColor(20, anterior);
    pixels.setPixelColor(21, anterior);
    pixels.setPixelColor(22, anterior);
    pixels.setPixelColor(23, anterior);
    pixels.setPixelColor(24, anterior);
    pixels.setPixelColor(25, anterior);
    pixels.setPixelColor(26, anterior);
    pixels.setPixelColor(27, anterior);
    pixels.setPixelColor(28, anterior);
    pixels.setPixelColor(29, anterior);
    pixels.show();   // Send the updated pixel colors to the hardware.
}
}
