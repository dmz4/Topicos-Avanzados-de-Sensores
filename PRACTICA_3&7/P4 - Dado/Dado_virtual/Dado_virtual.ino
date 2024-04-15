#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

int pitch=0;
int roll=0;

void setup() {
  Serial.begin(9600);
  Wire.begin();

  // Inicializar el sensor MPU6050
  mpu.initialize();
 
  // Configurar el rango de escala del giroscopio y acelerómetro
  mpu.setFullScaleGyroRange(MPU6050_GYRO_FS_250);
  mpu.setFullScaleAccelRange(MPU6050_ACCEL_FS_2);
}

void loop() {
  // Leer los datos del sensor
  int16_t ax, ay, az, gx, gy, gz;
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
 
  // Convertir los datos en unidades de medida
  float accelX = ax / 16384.0; // Sensibilidad del acelerómetro para el rango de ±2g
  float accelY = ay / 16384.0;
  float accelZ = az / 16384.0;
 
  float gyroX = gx / 131.0; // Sensibilidad del giroscopio para el rango de ±250°/s
  float gyroY = gy / 131.0;
  float gyroZ = gz / 131.0;
 
  /*----- Angulos pich and roll a partir de un acelerometro*/
  pitch = -(atan2(accelX, sqrt(accelY*accelY + accelZ*accelZ))*180.0)/M_PI;
  roll = ((atan2(accelY, accelZ)*180.0)/M_PI);
  /* Pasamos los grados a valores de 0 a 1023 con la finalidad de no tener negativos*/
  roll=map(roll,-180,180,0,1023);
  pitch=map(pitch,-180,180,0,1023);
  /*---- agregamos ceros para que las cadenas tengan la misma longitud -----*/
  
  imprimir(pitch,roll);
  
  delay(200); // Esperar un poco antes de la próxima lectura
}

void imprimir(int g1, int g2) {
  if(((g1 > 450)&&(g1 < 560))&&((g2 > 450)&&(g2 < 560))){
    Serial.println(" 6");
  }
  else if(((g1 > 450)&&(g1 < 560))&&((g2 > 620)&&(g2 < 820))){
    Serial.println(" 3");
  }
  else if(((g1 > 450)&&(g1 < 560))&&((g2 > 180)&&(g2 < 400))){
    Serial.println(" 5");
  }
  else if(((g1 > 200)&&(g1 < 340))&&((g2 > 20)&&(g2 < 560))){
    Serial.println(" 4");
  }
  else if(((g1 > 370)&&(g1 < 550))&&((g2 > 0)&&(g2 < 100))){
    Serial.println(" 2");
  }
  else if(((g1 > 670)&&(g1 < 800))&&((g2 > 450)&&(g2 < 1100))){
    Serial.println(" 1");
  }
  else{
    Serial.println(" ");
  }
}
