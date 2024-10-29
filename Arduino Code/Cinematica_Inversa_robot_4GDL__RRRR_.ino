
#include <math.h>             // Incluyo la librería 'math.h' que me proporciona funciones matemáticas estándar.
#include <VarSpeedServo.h>    // Incluyo la librería 'VarSpeedServo' que me permite controlar servos con velocidad variable.

VarSpeedServo servo1;         // Crea un objeto servo para el primer servo
VarSpeedServo servo2_1;       // Crea un objeto servo para el segundo servo
VarSpeedServo servo2_2;       // Crea un objeto servo para el segundo servo agregado (opcional)
VarSpeedServo servo3;         // Crea un objeto servo para el tercer servo
VarSpeedServo servo4;         // Crea un objeto servo para el cuarto servo
VarSpeedServo servo5;         // Crea un objeto servo para el quinto servo

// -------------------- VARIABLES DE LONGITUD ---------------------

float l1 = 96;                // Unidades en mm 
float l2 = 13.9;              // Unidades en mm
float l3 = 150;               // Unidades en mm
float l4 = 143.24;            // Unidades en mm 
float l5 = 127.42;            // Unidades en mm 

// -------------------- VARIABLES DE ORDENAMIENTO DE COORDENADAS ---------------------

struct CoordenadasGlobales {                                  // Defino una estructura llamada 'CoordenadasGlobales' que contiene las variables para las coordenadas globales.
    int Px4;                                                  // Declaro la variable 'Px4' para la coordenada X.
    int Py4;                                                  // Declaro la variable 'Py4' para la coordenada Y.                                               
    int Pz4;                                                  // Declaro la variable 'Pz4' para la coordenada Z.
    int Q;                                                    // Declaro la variable 'Q' para el ángulo de Pitch
};

// -------------------- MATRIZ DE COORDENADAS --------------------- 

CoordenadasGlobales coordenada_de_referencia_global[1]= {     // Creo una instancia de 'CoordenadasGlobales' llamada 'coordenada_de_referencia_global' con un tamaño de 1 y la inicializo.
    {0, 140, 140, 90}                                         // Inicializo la coordenada de referencia global al centro del tablero aproximadamente.
};

CoordenadasGlobales coordenada_de_muerte[1]= {                // Creo una instancia de 'CoordenadasGlobales' llamada 'coordenada_de_muerte' con un tamaño de 1 y la inicializo.
    {-190, 90, 40, 90}                                        // Inicializo la coordenada de muerte con los valores de las coordenadas de la cajita de muerte.
};

CoordenadasGlobales coordenadas_del_tablero[64]= {            // Creo una instancia de 'CoordenadasGlobales' llamada 'coordenadas_del_tablero' con un tamaño de 64 casillas y la inicializo.
    {75, 245, 12, 90}, {47, 238, 12, 90}, {15, 240, 13, 90}, {5, 240, 12, 90}, {-16, 240, 12, 90}, {-40, 238, 12, 90}, {-64, 238, 13, 90}, {-93, 238, 13, 90},     // A1 - H1 
    {80, 210, 7, 90}, {48, 210, 7, 90}, {16, 210, 9, 90},    {5, 210, 9, 90}, {-13, 210, 9, 90}, {-37, 210, 9, 90},    {-63, 210, 8, 90}, {-95, 210, 10, 90},      // A2 - H2
    {78, 180, 7, 90}, {50, 180, 7, 90}, {18, 186, 9, 90},    {5, 180, 7, 90},  {-18, 185, 6, 90},  {-42, 184, 10, 90}, {-66, 180, 8, 90}, {-95, 180, 8, 90},      // A3 - H3
    {72, 160, 7, 90}, {52, 158, 8, 90}, {24, 160, 7, 90},    {5, 158, 7, 90},  {-19, 163, 7, 90},  {-44, 156, 7, 90}, {-67, 156, 8, 90}, {-96, 156, 7, 90},      // A4 - H4
    {77, 130, 7, 90},   {54, 135, 8, 90}, {30, 136, 10, 90}, {4, 137, 10, 90}, {-18, 137, 9, 90},  {-42, 135, 10, 90}, {-66, 127, 10, 90}, {-95, 136, 10, 90},      // A5 - H5
    {77, 108, 8, 90}, {54, 112, 10, 90},  {33, 112, 15, 90}, {4, 114, 13, 90},   {-17, 114, 13, 90}, {-44, 116, 10, 90}, {-65, 110, 10, 90}, {-92, 110, 11, 90},               // A6 - H6
    {82, 87, 13, 90}, {58, 95, 16, 90},   {33, 96, 20, 90},   {10, 92, 19, 90},   {-17, 95, 19, 90}, {-40, 92, 17, 90},   {-63, 90, 16, 90},   {-87, 86, 8, 90},       // A7 - H7
    {87, 70, 32, 90},  {65, 75, 30, 90},  {43, 79, 35, 90},  {15, 82, 36, 90},  {-15, 82, 32, 90},  {-43, 78, 32, 90},  {-65, 77, 34, 90},  {-92, 70, 30, 90}        // A8 - H8  // Solo funciona bien con q2 de caida en 0
};

CoordenadasGlobales coordenadas_de_la_cajita[34] = {          // Creo una instancia de 'CoordenadasGlobales' llamada 'coordenadas_de_la_cajita' con un tamaño de 34 celdas y la inicializo.
    {124, 20, 2, 90}, {140, 45, 30, 90}, {110, 55, 28, 90},{115, 78, 20, 90}, {115, 97, 30, 90}, {115, 119, 32, 90},{114, 138, 30, 90}, {114, 165, 25, 90},                                // Fila 1
    {149, 15, 20, 90}, {153, 37, 20, 90}, {153, 54, 20, 90},{160, 70, 20, 90}, {160, 94, 20, 90}, {154, 120, 20, 90},{168, 138, 18, 90}, {168, 152, 20, 90}, {167, 186, 22, 90},            // Fila 2
    {177, 25, 25, 90}, {177, 47, 25, 90}, {177, 69, 25, 90},{177, 91, 25, 90}, {177, 113, 25, 90}, {177, 135, 25, 90},{177, 157, 25, 90}, {177, 179, 25, 90}, {177, 201, 25, 90},           // Fila 3
    {199, 25, 25, 90}, {199, 47, 25, 90}, {199, 69, 25, 90},{199, 91, 25, 90}, {199, 113, 25, 90}, {199, 135, 25, 90},{199, 157, 25, 90}, {199, 179, 25, 90}                                // Fila 4
};

// -------------------- VARIABLES PARA LOS CALCULOS ---------------------

double Qrad;                                        // Declaro una variable de tipo double para almacenar el ángulo en radianes.
double ht;                                          // Declaro una variable de tipo double para ht
double l5x;                                         // Declaro una variable de tipo double para una longitud 5 específica en el eje X.
double l5z;                                         // Declaro una variable de tipo double para una longitud 5 específica en el eje Z.
double h;                                           // Declaro una variable de tipo double para h
double a1;                                          // Declaro una variable de tipo double para el primer ángulo
double a2;                                          // Declaro una variable de tipo double para el segundo ángulo.
double a3;                                          // Declaro una variable de tipo double para el tercer ángulo.
double Q1;                                          // Declaro una variable de tipo double para el ángulo Q1 pero por defecto esta en radianes.
double Q2;                                          // Declaro una variable de tipo double para el ángulo Q2 pero por defecto esta en radianes.
double Q3;                                          // Declaro una variable de tipo double para el ángulo Q3 pero por defecto esta en radianes.
double Q4;                                          // Declaro una variable de tipo double para el ángulo Q4 pero por defecto esta en radianes.
double Q1_grados;                                   // Declaro una variable de tipo double para el ángulo Q1 pero ahora en grados.
double Q2_grados;                                   // Declaro una variable de tipo double para el ángulo Q2 pero ahora en grados.
double Q3_grados;                                   // Declaro una variable de tipo double para el ángulo Q3 pero ahora en grados.
double Q4_grados;                                   // Declaro una variable de tipo double para el ángulo Q4 pero ahora en grados.
double q3_argument;                                 // Para los errores de maquina
double q3_root;                                     // Para los errores de maquina
int Gripper_open = 55 ;                             // Declaro una variable de tipo int para el ángulo de apertura del gripper. Pongo 27 para una apertura moderada.     
int Gripper_closed = 28;                            // Declaro una variable de tipo int para el ángulo de cierre del gripper. Pongo 4 para asegurar un cierre firme. Para mayor seguridad usar 5 (100% seguro que no falla)
int Tiempo_para_velocidad_servo_lenta = 20 ;         // Declaro una variable de tipo int para el tiempo de movimiento lento del servo. Pongo 3 para movimientos lentos.
int Tiempo_para_velocidad_servo_rapida = 60 ;       // Declaro una variable de tipo int para el tiempo de movimiento rápido del servo. Poner 40 para movimientos rápidos.(con 10 funciona perfecto, aunque no tan rapido)
int Tiempo_para_velocidad_home = 60 ;               // Declaro una variable de tipo int para el tiempo de movimiento del servo a la posición home. Pongo 20 para movimientos moderados.
int tiempo_de_linealidad = 14;                       // Este es un +3 para que el servo se mueva un poquito mas rapido y permita una linealidad entre dos puntos, pero para las casillas finales, este valor debe ser <3
// -------------------- VARIABLES PARA AJUSTES ---------------------

int Angulo_ajuste_Gripper = 3;                      // Este valor se debe a que el brazo se cae un poquito, mayor valor,se orientara hacia el brazo, menor valor se orientara para el lado del jugador humano (general  en 3) , para la fila 1 , usar un numero negativo
int Angulo_de_ajuste_servo2_2 = 10;                 // Para alinearlo con el servo 2.1 (opcional cuando se usa)
int Angulo_ajuste_q2_caida = 11;                    // Declaro una variable de tipo int para ajustar y compensar el ángulo Q2 en caso de caída. 11 para casillas finales
int Angulo_ajuste_q3_caida = 1;                    // Declaro una variable de tipo int para ajustar y compensar el ángulo Q2 en caso de caída. 11 para casillas finales
int Angulo_ajuste_q1_linea = 3;                     // Declaro una variable de tipo int para ajustar el ángulo Q1 y que se alinee con el eje Y global. Pongo 3 para un ajuste general.

// -------------------- VARIABLES PARA POSICION DE HOME ---------------------

int qh1 = 0;                                        // Coloco el valor 0 para centrar la línea del eje del tablero de ajedrez en la posición home.
int qh2 = 90;                                       // Coloco el valor 90 para el segundo ángulo en la posición home.
int qh3 = 30;                                       // Coloco el valor 30 para el tercer ángulo en la posición home.
int qh4 = 160;                                      // Coloco el valor 160 para el cuarto ángulo en la posición home.

// -------------------- VARIABLES PARA LOS VALORES DE ENTRADA ---------------------

float Px4 ;                                         // Declaro una variable de tipo float para la coordenada X de entrada.
float Py4 ;                                         // Declaro una variable de tipo float para la coordenada Y de entrada. 
float Pz4 ;                                         // Declaro una variable de tipo float para la coordenada Z de entrada.
float Q ;                                           // Declaro una variable de tipo float para el ángulo de pitch de entrada.


const int buttonPin = 2;  // Pin donde está conectado el pulsador
const int buttonPinn = 3;  // Pin donde está conectado el LED verde
int buttonState = 0;      // Variable para leer el estado del pulsador
const int redPin = 22;
const int greenPin = 26;
const int bluePin = 30;

void setup() {

  pinMode(buttonPin, INPUT);
  pinMode(buttonPinn, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  
  Asignacion_de_pines_a_servos(8, 9, 10, 11, 12, 7);  // Pines donde conecto los servos. (serv1,serv2_1,serv3,serv4,serv5,serv2_2)    // El ultimo parametro es para el servo adicional en la articulacion 2, es opcional
  Serial.begin(9600);                                 // Iniciar la comunicación serie
  Posicion_de_home1(qh1,qh2,qh3,qh4);                 // Apenas ejecuto el programa, me hire primero a la posicion de home.
  Abrir_el_gripper(Gripper_open);                     // Apenas ejecuto el programa comenzare con el gripper abierto.
  
  //Secuencia_acomodar_piezas_de_robot();
  digitalWrite(buttonPinn, HIGH);

 
  //Mover_pieza("A2","A1");
  //Mover_pieza("A1","A2");
  //Mover_pieza("B2","B1");
  //Mover_pieza("B1","B2");
  //Mover_pieza("C2","C1");
  //Mover_pieza("C1","C2");
  //Mover_pieza("D2","D1");
  //Mover_pieza("D1","D2");
  //Mover_pieza("E2","E1");
  //Mover_pieza("E1","E2");
  //Mover_pieza("F2","F1");
  //Mover_pieza("F1","F2");
  //Mover_pieza("G2","G1");
  //Mover_pieza("G1","G2");
  //Mover_pieza("H2","H1");
  //Mover_pieza("H1","H2");
  
  //Mover_pieza("A8","A7");
  //Comer_pieza("D5","D3");
  //Ejecutar_movimiento(0, 350, 40, 10);              // Recordar descomentar para usar esta funcion. (Que basicamente es la cinematica inversa)
}


void loop() {

  
  //checkButtonAndSendSignal2();  // Para simular jugadas al presionar el boton
  checkButtonAndSendSignal();
  //Abrir_el_gripper(Gripper_open);
  //Cerrar_el_gripper(Gripper_closed);

  coordenadas_del_tablero_recibidas_desde_py(); // Funcion que se usa con el vector de coordenadas por ejemplo:['A1','A2','0']
  //Punto_a_punto_py();
}



void checkButtonAndSendSignal2() {
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    Mover_pieza("E7","E5");
    Mover_pieza("E2","E4");
    Mover_pieza("F8","C5");
    Mover_pieza("B1","C3");
    Mover_pieza("D8","H4");
    Mover_pieza("G1","F3");
    
    Comer_pieza("H4","F2");
    delay(500);  // Evita múltiples lecturas por un solo clic
  }
}

void checkButtonAndSendSignal() {
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    Serial.println("CAPTURE");  // Envía una señal para capturar la imagen
    delay(500);  // Evita múltiples lecturas por un solo clic
  }
}

void Secuencia_acomodar_piezas_de_robot(){      // Esta es una secuencia solamente para colocar las piezas desde la cajita blanca hasta las posicion inicial en el tablero de ajedrez.
  
  Mover_pieza("1", "A8");
  Mover_pieza("2", "B8");
  //Mover_pieza("3", "C8");
  //Mover_pieza("4", "D8");
  //Mover_pieza("5", "E8");
  //Mover_pieza("6", "F8");
  //Mover_pieza("7", "G8");
  //Mover_pieza("8", "H8");
  //Mover_pieza("9", "A7");
  //Mover_pieza("10", "B7");
  //Mover_pieza("11", "C7");
  //Mover_pieza("12", "D7");
  //Mover_pieza("13", "E7");
  //Mover_pieza("14", "F7");
  //Mover_pieza("15", "G7");
  //Mover_pieza("16", "H7");                      // Valores permitidos de la cajita "1" hasta "34" , valores permitidos del tablero desde filas "1" hasta "8" , columnas "A" , hasta "H" 
    
  }

void Punto_a_punto_py() {
    if (Serial.available() > 0) {
        String data = Serial.readStringUntil('\n'); // Leer hasta el salto de línea

        // Verificar que la longitud de los datos sea correcta
        int expectedLength = 33; // Longitud esperada incluyendo comas y letras
        if (data.length() == expectedLength) {
            // Leer la letra (primer carácter)
            char letter = data.charAt(0);

            // Leer los valores numéricos
            float num1 = data.substring(2, 9).toFloat(); // Lee del carácter 2 al 8
            float num2 = data.substring(10, 17).toFloat(); // Lee del carácter 9 al 16
            float num3 = data.substring(18, 25).toFloat(); // Lee del carácter 17 al 24
            float num4 = data.substring(26, 33).toFloat(); // Lee del carácter 25 al 32

            // Procesar los datos según la letra
            if (letter == 'D') {
                Serial.println("Cinemática Directa:");
                Serial.print("Q1: "); Serial.println(num1);
                Serial.print("Q2: "); Serial.println(num2);
                Serial.print("Q3: "); Serial.println(num3);
                Serial.print("Q4: "); Serial.println(num4);
                Movimiento_directo(num1, num2, num3, num4);
            } else if (letter == 'I') {
                Serial.println("Cinemática Inversa:");
                Serial.print("Px: "); Serial.println(num1);
                Serial.print("Py: "); Serial.println(num2);
                Serial.print("Pz: "); Serial.println(num3);
                Serial.print("Pitch: "); Serial.println(num4);
                Movimiento_inverso(num1, num2, num3, num4);
            } else {
                Serial.println("Letra desconocida.");
            }
        } else {
            Serial.println("Formato de datos incorrecto.");
        }
    }
}
  
void Movimiento_directo(double Q1_grados, double Q2_grados, double Q3_grados, double Q4_grados) {  // Lo mismo que la funcion "Ejecutar movimiento"              
  
  servo1.write(abs(Q1_grados)-Angulo_ajuste_q1_linea,Tiempo_para_velocidad_servo_rapida,false);                                              
  servo2_1.write(abs(Q2_grados)+Angulo_ajuste_q2_caida,Tiempo_para_velocidad_servo_rapida,false);
  servo3.write(abs(Q3_grados)+ qh3-Angulo_ajuste_q3_caida,Tiempo_para_velocidad_servo_rapida,false);
  servo4.write(qh4 - abs(Q4_grados) -Angulo_ajuste_Gripper,Tiempo_para_velocidad_servo_rapida,true);
}

void Movimiento_inverso(double Px, double Py, double Pz, double Q) {                    // Esta es la funcion para mover el brazo, recibe como entrada los valores de Px,Py,Pz,Q.
    Valores_de_posicion_e_Imprimir_entradas(Px, Py, Pz, Q);                             // Imprimo los valores para verlos en la terminal serie (solo funciona cuando no uso python debido a problemas con el puerto COM)
    Calculos_cinematica_inversa();                                                      // Utilizo los valores de Px,Py,Pz,Q para que se realize el calculo de la cinematica inversa y me devuelva los valores de los angulos Q de cada articulacion
    Imprimir_salidas();                                                                 // Print de los angulos Q, para ver en la terminal serie. (Solo funciona cuando no se usa Py, debido a conflictos con el puerto COM).
    Mover_brazo_a_la_velocidad_rapida(Q1_grados, Q2_grados, Q3_grados, Q4_grados);      // Descomentar en caso de querer usar solo esta funcion, para cargar una ubicacion en especifica manualmente, y comentarlo si deseo usarlo con la funcion de py().
}

void Ejecutar_movimiento(int Px, int Py, int Pz, int Q) {                               // Esta es la funcion para mover el brazo, recibe como entrada los valores de Px,Py,Pz,Q.
    Valores_de_posicion_e_Imprimir_entradas(Px, Py, Pz, Q);                             // Imprimo los valores para verlos en la terminal serie (solo funciona cuando no uso python debido a problemas con el puerto COM)
    Calculos_cinematica_inversa();                                                      // Utilizo los valores de Px,Py,Pz,Q para que se realize el calculo de la cinematica inversa y me devuelva los valores de los angulos Q de cada articulacion
    Imprimir_salidas();                                                                 // Print de los angulos Q, para ver en la terminal serie. (Solo funciona cuando no se usa Py, debido a conflictos con el puerto COM).
    //Mover_brazo_a_la_velocidad_rapida(Q1_grados, Q2_grados, Q3_grados, Q4_grados);    // Descomentar en caso de querer usar solo esta funcion, para cargar una ubicacion en especifica manualmente, y comentarlo si deseo usarlo con la funcion de py().
}

void Comer_pieza(const char* posicion_inicial, const char* posicion_final) {            // Lo mismo que la funcion de 'mover pieza' pero agregando una secuencia mas, para cuando come una pieza, es decir llevarla a la coordenada de muerte a la pieza comida.
    int tiempo = 1000;
    int Elevacion_Z = 55;
    CoordenadasGlobales ref_global = coordenada_de_referencia_global[0];
    CoordenadasGlobales coordenada_muerte = coordenada_de_muerte[0];

    CoordenadasGlobales inicial = Obtener_coordenadas_de_casilla(posicion_inicial);
    CoordenadasGlobales final = Obtener_coordenadas_de_casilla(posicion_final);
    
    if ((posicion_final[1] == '8')) {
        Angulo_ajuste_q2_caida = 0;
        Serial.println("Angulo de caida de q2 NO incluido");
    } 
    
    Ejecutar_movimiento(ref_global.Px4, ref_global.Py4, ref_global.Pz4 , ref_global.Q);  
    Mover_brazo_a_la_velocidad_rapida(Q1_grados, Q2_grados, Q3_grados, Q4_grados);
    delay(tiempo);
    
    Ejecutar_movimiento(final.Px4, final.Py4, final.Pz4 + Elevacion_Z, final.Q);    // Voy a a la casilla a capturar
    Mover_brazo_a_la_velocidad_rapida(Q1_grados, Q2_grados, Q3_grados, Q4_grados);
    delay(tiempo);
    Ejecutar_movimiento(final.Px4, final.Py4, final.Pz4, final.Q);
    Mover_brazo_a_la_velocidad_lenta(Q1_grados, Q2_grados, Q3_grados, Q4_grados,tiempo_de_linealidad);
    Cerrar_el_gripper(Gripper_closed);
    delay(tiempo);
    
     if ((posicion_inicial[1] == '1')) {
        tiempo_de_linealidad = 0;
        Serial.println("Mover mas lento la articulacion q4");
    } 
    
    Ejecutar_movimiento(final.Px4, final.Py4, final.Pz4 + Elevacion_Z, final.Q);
    Mover_brazo_a_la_velocidad_lenta(Q1_grados, Q2_grados, Q3_grados, Q4_grados,tiempo_de_linealidad);

    Ejecutar_movimiento(ref_global.Px4, ref_global.Py4, ref_global.Pz4 , ref_global.Q);  
    Mover_brazo_a_la_velocidad_rapida(Q1_grados, Q2_grados, Q3_grados, Q4_grados);
    delay(tiempo);

    tiempo_de_linealidad = 14;    
    Angulo_ajuste_q2_caida = 11;

    Ejecutar_movimiento(coordenada_muerte.Px4, coordenada_muerte.Py4, coordenada_muerte.Pz4 + Elevacion_Z, final.Q);  //Coloco la pieza en la coordenada de muerte
    Mover_brazo_a_la_velocidad_rapida(Q1_grados, Q2_grados, Q3_grados, Q4_grados);
    delay(tiempo);
    Ejecutar_movimiento(coordenada_muerte.Px4, coordenada_muerte.Py4, coordenada_muerte.Pz4, final.Q);
    Mover_brazo_a_la_velocidad_lenta(Q1_grados, Q2_grados, Q3_grados, Q4_grados,tiempo_de_linealidad);
    Abrir_el_gripper(Gripper_open);
    delay(tiempo);
    Ejecutar_movimiento(coordenada_muerte.Px4, coordenada_muerte.Py4, coordenada_muerte.Pz4 + Elevacion_Z, final.Q);
    Mover_brazo_a_la_velocidad_rapida(Q1_grados, Q2_grados, Q3_grados, Q4_grados);
    delay(tiempo);
    
    Ejecutar_movimiento(ref_global.Px4, ref_global.Py4, ref_global.Pz4 , ref_global.Q);  
    Mover_brazo_a_la_velocidad_rapida(Q1_grados, Q2_grados, Q3_grados, Q4_grados);
    delay(tiempo);
    
    if ((posicion_inicial[1] == '8')) {
        Angulo_ajuste_q2_caida = 0;
        Serial.println("Angulo de caida de q2 NO incluido");
    } 
    Ejecutar_movimiento(inicial.Px4, inicial.Py4, inicial.Pz4 + Elevacion_Z, inicial.Q);      // busco mi pieza que comio
    Mover_brazo_a_la_velocidad_rapida(Q1_grados, Q2_grados, Q3_grados, Q4_grados);
    delay(tiempo);
    Ejecutar_movimiento(inicial.Px4, inicial.Py4, inicial.Pz4, inicial.Q);
    Mover_brazo_a_la_velocidad_lenta(Q1_grados, Q2_grados, Q3_grados, Q4_grados,tiempo_de_linealidad);
    Cerrar_el_gripper(Gripper_closed);
    delay(tiempo);
    Ejecutar_movimiento(inicial.Px4, inicial.Py4, inicial.Pz4 + Elevacion_Z, inicial.Q);
    Mover_brazo_a_la_velocidad_lenta(Q1_grados, Q2_grados, Q3_grados, Q4_grados,tiempo_de_linealidad);
    delay(tiempo);

    Ejecutar_movimiento(ref_global.Px4, ref_global.Py4, ref_global.Pz4 , ref_global.Q);  
    Mover_brazo_a_la_velocidad_rapida(Q1_grados, Q2_grados, Q3_grados, Q4_grados);
    delay(tiempo);

    Angulo_ajuste_q2_caida = 11;
    
    if ((posicion_final[1] == '8')) {
        Angulo_ajuste_q2_caida = 0;
        Serial.println("Angulo de caida de q2 NO incluido");
    } 
    
    Ejecutar_movimiento(final.Px4, final.Py4, final.Pz4 + Elevacion_Z, inicial.Q);            // coloco la pieza donde comio
    Mover_brazo_a_la_velocidad_rapida(Q1_grados, Q2_grados, Q3_grados, Q4_grados);
    delay(tiempo);
    Ejecutar_movimiento(final.Px4, final.Py4, final.Pz4, final.Q);
    Mover_brazo_a_la_velocidad_lenta(Q1_grados, Q2_grados, Q3_grados, Q4_grados,tiempo_de_linealidad);
    Abrir_el_gripper(Gripper_open);
    delay(tiempo);
    Ejecutar_movimiento(final.Px4, final.Py4, final.Pz4 + Elevacion_Z, inicial.Q);
    Mover_brazo_a_la_velocidad_lenta(Q1_grados, Q2_grados, Q3_grados, Q4_grados,tiempo_de_linealidad);
    delay(tiempo);
    Posicion_de_home1(qh1,qh2,qh3,qh4);
}

void Mover_pieza(const char* posicion_inicial, const char* posicion_final) {        // Esta funcion recibe como entrada dos coordenadas del tablero como 'A2' 'A5', y hara una secuencia de movimientos para mover la pieza desde la posicion inicial hasta la posicion final
    int tiempo = 1000;                                                              // El tiempo de todos los delay
    int Elevacion_Z =55;                                                            // Las mismas coordenadas establecidas en las 'coordenadas globales' pero con una altura para que se posicione justo por encima de la pieza

    CoordenadasGlobales ref_global = coordenada_de_referencia_global[0];

    CoordenadasGlobales inicial;
    CoordenadasGlobales final;
    
    if (EsNumero(posicion_inicial)){                                                  // Esto arrojara True o False , True si es un numero ,False si es una coordenada del tablero
        inicial = Obtener_coordenadas_de_cajita(atoi(posicion_inicial));              //La función atoi se usa para convertir una cadena de caracteres que representa un número (como "12") en un entero (12)
    }else{
        inicial = Obtener_coordenadas_de_casilla(posicion_inicial);
       }
       
    if (EsNumero(posicion_final)) {
        final = Obtener_coordenadas_de_cajita(atoi(posicion_final));                  // Lo mismo que arriba pero ahora para el segundo parametro, por si la posicion final es de la cajiita
    } else {
        final = Obtener_coordenadas_de_casilla(posicion_final);
    }
   // Imprime las posiciones para depuración
   
    Serial.print("Posicion inicial: ");
    Serial.println(posicion_inicial);
    
    Serial.print("Posicion final: ");
    Serial.println(posicion_final);
    
    if ((posicion_inicial[1] == '8')) {
        Angulo_ajuste_q2_caida = 0;
        Serial.println("Angulo de caida de q2 NO incluido");
    } 
    
    Ejecutar_movimiento(ref_global.Px4, ref_global.Py4, ref_global.Pz4 , ref_global.Q);  
    Mover_brazo_a_la_velocidad_rapida(Q1_grados, Q2_grados, Q3_grados, Q4_grados);
    delay(tiempo);
    
    Ejecutar_movimiento(inicial.Px4, inicial.Py4, inicial.Pz4 + Elevacion_Z, inicial.Q);
    Mover_brazo_a_la_velocidad_rapida(Q1_grados, Q2_grados, Q3_grados, Q4_grados);
    delay(tiempo);
    Ejecutar_movimiento(inicial.Px4, inicial.Py4, inicial.Pz4, inicial.Q);
    Mover_brazo_a_la_velocidad_lenta(Q1_grados, Q2_grados, Q3_grados, Q4_grados,tiempo_de_linealidad);
    Cerrar_el_gripper(Gripper_closed);
    delay(tiempo);

    if ((posicion_inicial[1] == '1')) {
        tiempo_de_linealidad = -1;
        Serial.println("Mover mas lento la articulacion q4");
    } 
    
    Ejecutar_movimiento(inicial.Px4, inicial.Py4, inicial.Pz4 + Elevacion_Z, inicial.Q);
    Mover_brazo_a_la_velocidad_lenta(Q1_grados, Q2_grados, Q3_grados, Q4_grados,tiempo_de_linealidad);

    Ejecutar_movimiento(ref_global.Px4, ref_global.Py4,ref_global.Pz4 , ref_global.Q);  
    Mover_brazo_a_la_velocidad_rapida(Q1_grados, Q2_grados, Q3_grados, Q4_grados);
    delay(tiempo);
    
    tiempo_de_linealidad = 14;
    Angulo_ajuste_q2_caida = 11;
    
    if ((posicion_final[1] == '8')) {
        Angulo_ajuste_q2_caida = 0;
        Serial.println("Angulo de caida de q2 NO incluido");
    } 
    
    Ejecutar_movimiento(final.Px4, final.Py4, final.Pz4 + Elevacion_Z, inicial.Q);
    Mover_brazo_a_la_velocidad_rapida(Q1_grados, Q2_grados, Q3_grados, Q4_grados);
    delay(tiempo);
    Ejecutar_movimiento(final.Px4, final.Py4, final.Pz4, final.Q);
    Mover_brazo_a_la_velocidad_lenta(Q1_grados, Q2_grados, Q3_grados, Q4_grados,tiempo_de_linealidad);
    Abrir_el_gripper(Gripper_open);
    delay(tiempo);
    
    Ejecutar_movimiento(final.Px4, final.Py4, final.Pz4 + Elevacion_Z, inicial.Q);
    Mover_brazo_a_la_velocidad_lenta(Q1_grados, Q2_grados, Q3_grados, Q4_grados,tiempo_de_linealidad);

    Posicion_de_home1(qh1,qh2,qh3,qh4);
}

void coordenadas_del_tablero_recibidas_desde_py(){                                          // Para mover o comer la pieza... Funciona para codigo general (el que presentamos en la ultima clase), codigo de voz y codigo de chess.com.
    if (Serial.available() > 0) {                                                           // Esta línea comprueba si hay datos disponibles para leer en el puerto serie. La función Serial.available() devuelve el número de bytes disponibles para leer. Si es mayor que 0, significa que hay datos disponibles.
      String coordenadas_tablero = Serial.readStringUntil('\n');                            // se lee una cadena de caracteres desde el puerto serie hasta encontrar un salto de línea ('\n'). La cadena leída se almacena en la variable coordenadas
      coordenadas_tablero.trim();                                                           // Elimina cualquier espacio en blanco al principio y al final de la cadena
      String inicial = coordenadas_tablero.substring(0, 2);                                 // .substring Este método se utiliza para extraer una subcadena de una cadena.Primer indice se incluye, el segundo indice se excluye
      String final = coordenadas_tablero.substring(3, 5);
                                                                                            // Formato del mensaje:
                                                                                            // Índices:  0 1 2 3 4 5      6
                                                                                            // Cadena:   A 1   B 2   0/1/2/3/4/5
      char ultimoDigito = coordenadas_tablero.charAt(coordenadas_tablero.length() - 1);     // Obtiene el último dígito.

        if (ultimoDigito == '0') {
            Mover_pieza(inicial.c_str(), final.c_str());                                    // Muevo una pieza.
        } 
        else if (ultimoDigito == '1') {
            Comer_pieza(inicial.c_str(), final.c_str());                                    // Como una pieza.
        } 
        else if (ultimoDigito == '2') {                                                     // Enroque corto de las negras.
            Mover_pieza(inicial.c_str(), final.c_str());                                    // Movimiento del rey negro.
            Mover_pieza("H8", "F8");                                                        // Movimiento de la torre.
        } 
        else if (ultimoDigito == '3') {                                                     // Enroque largo de las negras.
            Mover_pieza(inicial.c_str(), final.c_str());                                    // Movimiento del rey negro.
            Mover_pieza("A8", "D8");                                                        // Movimiento de la torre.
        } 
        else if (ultimoDigito == '4') {                                                     // Enroque corto de las blancas.
            Mover_pieza(inicial.c_str(), final.c_str());                                    // Movimiento del rey blanco.
            Mover_pieza("H1", "F1");                                                        // Movimiento de la torre.
        } 
        else if (ultimoDigito == '5') {                                                     // Enroque largo de las blancas.
            Mover_pieza(inicial.c_str(), final.c_str());                                    // Movimiento del rey blanco.
            Mover_pieza("A1", "D1");                                                        // Movimiento de la torre.
        }
      }
    }

bool Coordenadas_Validas(String coord) {                              // En un tablero de ajedrez, una coordenada válida (como "A1" o "H8") siempre tiene dos caracteres. Si la longitud no es 2, la coordenada no puede ser válida, por lo que la función devuelve false inmediatamente.
  if (coord.length() != 2) return false;
  char col = coord.charAt(0);                                         // Aquí, se extrae el primer carácter de la cadena coord y se guarda en la variable col. Este carácter representa la columna del tablero de ajedrez.
  char row = coord.charAt(1);                                         // Esta línea extrae el segundo carácter de la cadena coord y lo guarda en la variable row. Este carácter representa la fila del tablero de ajedrez.
  return (col >= 'A' && col <= 'H') && (row >= '1' && row <= '8');    // Si ambas condiciones se cumplen, la función devuelve true, indicando que coord es una coordenada válida del tablero de ajedrez. Si alguna de las condiciones no se cumple, la función devuelve false.
}

void Mover_brazo_a_la_velocidad_deseada_desde_home(double Q1_grados, double Q2_grados, double Q3_grados, double Q4_grados) {
  
  servo1.write(abs(Q1_grados)+ qh1-Angulo_ajuste_q1_linea,Tiempo_para_velocidad_home+0,false);                            
  servo4.write(qh4 - abs(Q4_grados) -Angulo_ajuste_Gripper,Tiempo_para_velocidad_home+3,false);                           
  servo2_1.write(abs(Q2_grados),Tiempo_para_velocidad_home,false);                              
  servo2_2.write(180 - abs(Q2_grados)-Angulo_de_ajuste_servo2_2,Tiempo_para_velocidad_home,false);
  servo3.write(abs(Q3_grados)+ qh3-Angulo_ajuste_q3_caida,Tiempo_para_velocidad_home,true);
}

void Mover_brazo_a_la_velocidad_lenta(double Q1_grados, double Q2_grados, double Q3_grados, double Q4_grados,int tiempo_de_linealidad) {
  
  servo1.write(abs(Q1_grados)+ qh1-Angulo_ajuste_q1_linea,Tiempo_para_velocidad_servo_lenta,false);                             // Mando al 'servo1' que se mueva al ángulo calculado, con el tiempo definido para la velocidad lenta y sin esperar a que termine antes de iniciar el siguiente movimiento.                                             
  servo2_1.write(abs(Q2_grados)+Angulo_ajuste_q2_caida,Tiempo_para_velocidad_servo_lenta,false);                                // Mando al 'servo2_1' que se mueva al ángulo calculado, con el tiempo definido para la velocidad lenta y sin esperar a que termine antes de iniciar el siguiente movimiento.
  servo2_2.write(180 - abs(Q2_grados)-Angulo_de_ajuste_servo2_2-Angulo_ajuste_q2_caida,Tiempo_para_velocidad_servo_lenta,false);// Mando al 'servo2_2' que se mueva al ángulo calculado, con el tiempo definido para la velocidad lenta y sin esperar a que termine antes de iniciar el siguiente movimiento.
  servo3.write(abs(Q3_grados)+ qh3-Angulo_ajuste_q3_caida,Tiempo_para_velocidad_servo_lenta,false);                             // Mando al 'servo3' que se mueva al ángulo calculado, con el tiempo definido para la velocidad lenta y sin esperar a que termine antes de iniciar el siguiente movimiento.
  servo4.write(qh4 - abs(Q4_grados) -Angulo_ajuste_Gripper,Tiempo_para_velocidad_servo_lenta+tiempo_de_linealidad,true);        // Mando al servo 4 que se mueva , con velocidad lenta , pero con +3 la velocidad gripper...para movimiento lineal y esperando a que termine antes de iniciar el siguiente movimiento.

}

void Mover_brazo_a_la_velocidad_rapida(double Q1_grados, double Q2_grados, double Q3_grados, double Q4_grados) {                // Lo mismo que la funcion de arriba, pero con velocidad rapida.
  
  servo1.write(abs(Q1_grados)+ qh1-Angulo_ajuste_q1_linea,Tiempo_para_velocidad_servo_rapida,false);                                              
  servo2_1.write(abs(Q2_grados)+Angulo_ajuste_q2_caida,Tiempo_para_velocidad_servo_rapida,false);
  servo2_2.write(180 - abs(Q2_grados)-Angulo_de_ajuste_servo2_2-Angulo_ajuste_q2_caida,Tiempo_para_velocidad_servo_rapida,false);
  servo3.write(abs(Q3_grados)+ qh3-Angulo_ajuste_q3_caida,Tiempo_para_velocidad_servo_rapida,false);
  servo4.write(qh4 - abs(Q4_grados) -Angulo_ajuste_Gripper,Tiempo_para_velocidad_servo_rapida,true);

}

void Abrir_el_gripper(int Gripper_open){                                              // Defino una función para abrir el gripper utilizando el valor proporcionado.
  delay(1000);                                                                        // Hago una pausa de 2 segundos antes de abrir el gripper.
  servo5.write(Gripper_open);                                                         // Mando al 'servo5' que se mueva al ángulo especificado por 'Gripper_open'
}

void Cerrar_el_gripper(int Gripper_closed){                                           // Defino una función para cerrar el gripper utilizando el valor proporcionado.
  delay(1000);                                                                        // Hago una pausa de 2 segundos antes de cerrar el gripper.
  servo5.write(Gripper_closed);                                                       // Mando al 'servo5' que se mueva al ángulo especificado por 'Gripper_closed'.
}
  
void Posicion_de_home1 (int qh1,int qh2,int qh3,int qh4){                             // Defino una función para mover los servos a la posición de home con los ángulos proporcionados.
  servo1.write(qh1,Tiempo_para_velocidad_home,false);                                 // Mando al 'servo1' que se mueva al ángulo 'qh1' con la velocidad de home y sin esperar a que termine antes de iniciar el siguiente movimiento.
  servo2_1.write(qh2,Tiempo_para_velocidad_home,false);                               // Mando al 'servo2_1' que se mueva al ángulo 'qh2' con la velocidad de home y sin esperar a que termine antes de iniciar el siguiente movimiento
  servo2_2.write(180-qh2-Angulo_de_ajuste_servo2_2,Tiempo_para_velocidad_home,false); // Mando al 'servo2_2' que se mueva al ángulo calculado (180 - qh2 - ajuste) con la velocidad de home y sin esperar a que termine antes de iniciar el siguiente movimiento
  servo3.write(qh3,Tiempo_para_velocidad_home,true);                                  // Mando al 'servo3' que se mueva al ángulo 'qh3'con la velocidad de home y esperando a que termine antes de iniciar el siguiente movimiento.
  servo4.write(qh4,Tiempo_para_velocidad_home,true);                                  // Mando al 'servo4' que se mueva al ángulo 'qh4'con la velocidad de home y esperando a que termine antes de iniciar el siguiente movimiento.
  Serial.println("CAPTURE");  // Envía una señal para capturar la imagen al momento de volver a home en la jugada
}

void Asignacion_de_pines_a_servos (int serv1,int serv2_1,int serv3,int serv4,int serv5,int serv2_2){  // Defino una función para asignar pines a los servos y establecer sus límites de pulso.

  servo1.attach(serv1,500,2380);                                                      // Asigno el pin proporcionado a 'servo1' y configuro el rango de pulso (500 a 2380 microsegundos).
  servo2_1.attach(serv2_1,500,2440);                                                  // Asigno el pin proporcionado a 'servo2_1' y configuro el rango de pulso (500 a 2440 microsegundos).     
  servo2_2.attach(serv2_2,500,2440);                                                  // Asigno el pin proporcionado a 'servo2_2' y configuro el rango de pulso (500 a 2440 microsegundos) (Opcional usar) 
  servo3.attach(serv3,500,2425);                                                      // Asigno el pin proporcionado a 'servo3' y configuro el rango de pulso (500 a 2425 microsegundos).
  servo4.attach(serv4,500,2450);                                                      // Asigno el pin proporcionado a 'servo4' y configuro el rango de pulso (500 a 2450 microsegundos)
  servo5.attach(serv5,500,2460);                                                      // Asigno el pin proporcionado a 'servo5' y configuro el rango de pulso (500 a 2460 microsegundos).
}

int Casilla_a_indice(const char* Casilla_referenciada){     // Primero, defino la función Casilla_a_indice que toma una referencia a una casilla en formato de texto (por ejemplo, "A1") y devuelve un índice que usare en otra funcion
   int columna = Casilla_referenciada[0] - 'A';             // Obtengo el valor de la columna, restando el carácter 'A' del primer carácter de la cadena. Esto convierte 'A' en 0, 'B' en 1, etc.
   int fila = Casilla_referenciada[1] - '1';                // Obtengo el valor de la fila, restando el carácter '1' del segundo carácter de la cadena. Esto convierte '1' en 0, '2' en 1, etc.
   return fila*8+columna;                                   // Calcula el índice en el tablero combinando la fila y la columna. La fila se multiplica por 8 y se le suma la columna.
  }
  
CoordenadasGlobales Obtener_coordenadas_de_casilla(const char* Casilla_referenciada){
  int indice = Casilla_a_indice(Casilla_referenciada);              // Llamo a la función Casilla_a_indice para obtener el índice basado en la casilla referenciada.
  return coordenadas_del_tablero[indice];                           // Devuelvo las coordenadas globales correspondientes al índice en el tablero.
  }

CoordenadasGlobales Obtener_coordenadas_de_cajita(int indice) {
  return coordenadas_de_la_cajita[indice - 1];                      // Devuelvo las coordenadas globales correspondientes al índice menos 1 de la cajita blanca.
  }

bool EsNumero(const char* str) {     // Defino la función EsNumero que determina si la cadena de caracteres es un número.  (Para diferenciar laas coordeenadas de la cajita con las de las del tablero)
    while (*str) {
        if (!isdigit(*str)) {
            return false;
        }
        str++;
    }
    return true;
}
void Coordenadas_recibidas(const char* Casilla_referenciada){
  CoordenadasGlobales Valores = Obtener_coordenadas_de_casilla(Casilla_referenciada);
  Serial.print("Coordenadas de:");Serial.println(Casilla_referenciada);
  Px4 = Valores.Px4;Serial.print("Px4:");Serial.println(Px4);
  Py4 = Valores.Py4;Serial.print("Py4:");Serial.println(Py4);
  Pz4 = Valores.Pz4;Serial.print("Pz4:");Serial.println(Pz4);  
  Q = Valores.Q;Serial.print("Q:");Serial.println(Q); 
  }

double convertirGradosARadianes(double Ang_grados) {                                        // Defino una función que convierte ángulos de grados a radianes.
  return Ang_grados * PI / 180.0;                                                           // Convierto el ángulo de grados a radianes usando la fórmula (grados * PI / 180).
}

double convertirRadianesAGrados(double Ang_radianes) {                                      // Defino una función que convierte ángulos de radianes a grados.
  return Ang_radianes * 180.0 / PI;                                                         // Convierto el ángulo de radianes a grados usando la fórmula (radianes * 180 / PI).
}

void Valores_de_posicion_e_Imprimir_entradas(float nPx4,float nPy4,float nPz4 ,float nQ ){
  Px4 = nPx4;
  Serial.print("Numero recibido para X: ");Serial.println(Px4);Serial.println(" ");
  Py4 = nPy4;
  Serial.print("Numero recibido para Y: ");Serial.println(Py4);Serial.println(" ");
  Pz4 = nPz4;
  Serial.print("Numero recibido para Z: ");Serial.println(Pz4);Serial.println(" ");
  Q = nQ;
  Serial.print("Numero recibido para Q: ");Serial.println(Q);Serial.println(" ");
}

void Ingresar_valores_de_posicion_e_Imprimir_entradas(){

  Serial.println("Ingrese la posicion en X en mm:");
  while (!Serial.available()) {}
  Px4 = Serial.parseFloat();
  Serial.print("Numero recibido para X: ");
  Serial.println(Px4);
  Serial.println(" ");
  
  Serial.println("Ingrese la posicion en Y en mm:");
  while (!Serial.available()) {}
  Py4 = Serial.parseFloat();
  Serial.print("Numero recibido para Y: ");
  Serial.println(Py4);
  Serial.println(" ");
  
  Serial.println("Ingrese la posicion en Z en mm:");
  while (!Serial.available()) {}
  Pz4 = Serial.parseFloat();
  Serial.print("Numero recibido para Z: ");
  Serial.println(Pz4);
  Serial.println(" ");
  
  Serial.println("Ingrese el angulo ° de Q:");
  while (!Serial.available()) {}
  Q = Serial.parseFloat();
  Serial.print("Numero recibido para Q: ");
  Serial.println(Q);
  Serial.println(" ");
  
}

void Imprimir_salidas(){
  Serial.println("\nSegun los calculos, los Angulos de las articulaciones en grados:");
  Serial.print("Q1: ");Serial.println(Q1_grados);
  Serial.print("Q2: ");Serial.println(Q2_grados);
  Serial.print("Q3: ");Serial.println(Q3_grados);
  Serial.print("Q4: ");Serial.println(Q4_grados);
  Serial.println(" ");
}

void Imprimir_datos_para_ver_en_caso_de_errores(){
  Serial.print("ht:");Serial.println(ht);
  Serial.print("l5x:");Serial.println(l5x);
  Serial.print("l5z:");Serial.println(l5z);
  Serial.print("h:");Serial.println(h);
  Serial.print("argumento a1:");Serial.println((Pz4 + l5z - l1) / (ht - l5x - l2));
  Serial.print("a1 en radianes:");Serial.println(a1);
  Serial.print("argumento a2:");Serial.println((l4 * sin(Q3)) / (l3 + l4 * cos(Q3)));
  Serial.print("a2 en radianes:");Serial.println(a2);
}

void Calculos_cinematica_inversa(){

  Qrad = convertirGradosARadianes(Q);
  
// Cálculo de ht,l5x,l5z,h
  
  ht = sqrt(pow(Px4, 2) + pow(Py4, 2));
  l5x = l5 * cos(Qrad);
  l5z = l5 * sin(Qrad);
  h = sqrt(pow(ht - l5x - l2, 2) + pow(Pz4 + l5z - l1, 2));
  
// Cálculo de los ángulos a1, a2, a3 , Q1,Q2,Q3,Q4

  a1 = abs(atan2((Pz4 + l5z - l1) , (ht - l5x - l2)));
  Q1 = abs(atan2(Py4, Px4));
  q3_argument = (pow(h, 2) - pow(l3, 2) - pow(l4, 2)) / (2 * l3 * l4);

  if (abs(q3_argument) < 1) {                                   // Por el posible error de maquina , enves de 0 , podria dar un valor muy pequeño
  q3_root = sqrt(1 - pow(q3_argument, 2));
} else {
  q3_root = 0;  // Manejo de errores numéricos
}
  Q3 = -abs(atan2(q3_root, q3_argument));
  a2 = atan2((l4 * sin(Q3)), (l3 + l4 * cos(Q3)));
  Q2 = abs(a1) + abs(a2);
  Q4 = -abs(Q2) + abs(Q3) - abs(Qrad);
   
  Q1_grados = convertirRadianesAGrados(Q1);
  Q2_grados = convertirRadianesAGrados(Q2);
  Q3_grados = convertirRadianesAGrados(Q3);
  Q4_grados = convertirRadianesAGrados(Q4);
}
