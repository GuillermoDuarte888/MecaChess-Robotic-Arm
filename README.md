
<p align="center">
  <img src="https://github.com/GuillermoDuarte888/MecaChess-Robotic-Arm/raw/main/Imagenes/Logo%20de%20la%20Facultad%20de%20Ingenieria.png" alt="Brazo Robótico" width="800"/>
</p>



<h1 align="center" style="font-size: 3em;">♟️ MecaChess Robotic Arm ♟️</h1>

<p align="center">
  <img src="https://github.com/GuillermoDuarte888/MecaChess-Robotic-Arm/raw/main/Imagenes/brazo%20robot.jpg" width="400"/>
</p>

# Integrantes
<p>👤 Guillermo Daniel Duarte</p>
<p>👤 Gaston Alejandro Díaz</p>
</section>

## Índice
- [Introduccion](#introduccion)
 - [💻Recursos y Tecnologías Integradas💻](#-recursos-y-tecnologias-integradas-)
    - [Software Empleados♕](#software-empleados-)
    - [Bibliotecas de Phyton Utilizadas📚](#bibliotecas-de-phyton-utilizadas-)
- [⚙️Diseño Mecanico y Cinematicas⚙️](#-diseño-mecanico-y-cinematicas-)
    - [Cinemática Directa♖](#cinematica-directa-)
    - [Cinemática Inversa♗](#cinematica-inversa-)
    - [Diseño Mecánico del Brazo Robot🛠️](#diseño-mecanico-del-brazo-robot)
    - [Representación del Brazo Robótico en SolidWorks🔧](#representación-del-brazo-robótico-en-solidworks-)
    - [Diseño de las Piezas y la Caja📦](#diseño-de-las-piezas-y-la-caja-)
    - [Tablero de Ajedrez♘](#tablero-de-ajedrez-)
    - [Materiales Reciclados Utilizados🔄](#materiales-reciclados-utilizados-)


# Introduccion

El presente proyecto denominado **"MecaChess Robotic Arm"** tiene como finalidad la creación de un brazo robótico antropomórfico de 4 grados de libertad, diseñado para jugar al ajedrez de manera autónoma. Además, se le incorporaron funciones adicionales que permiten acomodar las piezas al inicio de una partida, jugar a través de la aplicación Chess.com, moverse por comandos de voz e identificar jugadas ilegales, entre otras. Para hacerlo más accesible, se emplearon materiales económicos y reciclados, logrando un balance óptimo entre costo y precisión sin comprometer la funcionalidad del brazo. Por último, se continúa trabajando en la incorporación de nuevas funcionalidades, como la implementación de inteligencia artificial y mejoras en el diseño, entre otros aspectos.

<h1 align="center">💻 Recursos y Tecnologias Integradas 💻</h1> 

# Software Empleados ♕

| Software                  | Descripción                                                                                        |
|--------------------------|-----------------------------------------------------------------------------------------------------|
| SolidWorks 2023          |  Se empleó SolidWorks 2023 para el diseño del conjunto elemental, la modelación de diversos componentes y la utilización de su biblioteca de herramientas para tornillos, tuercas y otros elementos de fijación. |
| Proteus 8 Professional    | Se usó Proteus 8 Professional para el diseño del esquema electrónico y su correspondiente simulacion |
| Python                  | Se utilizó Python para el desarrollo de la lógica del juego, incluyendo la detección de piezas, el manejo del tablero y el mapeo de las jugadas.   |
| Arduino IDE              |  Se utilizó Arduino IDE para programar la lógica de las cinemáticas y las funciones necesarias para controlar los movimientos del brazo robótico. |
|  Stockfish                | Se utilizó Stockfish como motor de ajedrez para la evaluación de posiciones y la generación de movimientos óptimos durante las partidas.         |
| Iriun Webcam | Se implementó Iriun Webcam para establecer una conexión entre el teléfono móvil, utilizado como cámara, y el entorno de programación Python, facilitando así su control y gestión de manera eficiente. |
| Wokwi                    | Wokwi es una herramienta en línea utilizada para diseñar y simular circuitos electrónicos. Permite crear diagramas interactivos, facilitando la visualización del circuito y la prueba del código antes de implementarlo en el hardware. |

# Bibliotecas de Phyton Utilizadas 📚

| Biblioteca               | Descripción                                                                                         |
|--------------------------|-----------------------------------------------------------------------------------------------------|
| OpenCV                   | Biblioteca para tareas de visión por computadora, utilizada para procesamiento de imágenes y detección de objetos. |
| NumPy                    | Biblioteca para cálculos numéricos, que facilita la manipulación de arreglos y operaciones matemáticas complejas. |
| Matplotlib               | Biblioteca para la visualización de datos y gráficos, que permite crear representaciones gráficas de información. |
| Chess                    | Biblioteca que gestiona las reglas del ajedrez, incluyendo movimientos, validaciones y análisis de partidas. |
| IPython.display          | Herramienta para mostrar gráficos y SVG en notebooks de Jupyter, facilitando la visualización de datos. |
| Serial                   | Biblioteca que permite la comunicación serie con dispositivos externos, útil para interactuar con hardware. |
| Time                     | Módulo que proporciona funciones para medir y controlar el tiempo, utilizado para la sincronización de eventos. |
| Copy                     | Módulo que permite la creación de copias superficiales y profundas de objetos en Python. |
| PyQt                     | Se utilizó la biblioteca PyQt para desarrollar la interfaz gráfica de las cinemáticas, facilitando la interacción del usuario con el sistema. |


<h1 align="center">⚙️ Diseño Mecanico y Cinematicas ⚙️</h1> 

# Cinematica Directa ♖

La cinemática directa permite calcular la posición y orientación del efector final del robot ajedrecista a partir de los valores de las articulaciones. Para ello, se utilizan transformaciones homogéneas aplicadas de manera sistemática, empleando el método de Denavit-Hartenberg. Este enfoque proporciona un marco estándar para representar las configuraciones articulares y facilita la obtención de las coordenadas del efector final en el espacio tridimensional. Comprender este proceso es fundamental para analizar el movimiento del robot en el tablero de ajedrez y es esencial para el diseño de algoritmos de control de trayectorias que optimicen su desempeño en el juego.

<p align="center">
  <img src="https://github.com/GuillermoDuarte888/MecaChess-Robotic-Arm/raw/main/Imagenes/Cinematica%20Directa%20Robot%204%20GDL.png" alt="Brazo Robótico" width="800"/>
</p>

El siguiente programa, desarrollado en Python, permite simular diversas configuraciones de articulaciones que alcanzan una misma posición del extremo del manipulador robótico, mostrando así las diferentes alternativas disponibles. En la imagen de la derecha, se puede observar que q3 tiene la configuración "codo arriba", lo que hace que q2 deba quedar hacia abajo, ya que su cálculo depende de q3. Por otro lado, en la imagen de la izquierda, q3 presenta la configuración "codo abajo", lo que implica que q2 debe posicionarse hacia arriba, de acuerdo con la relación mencionada entre ambos ángulos. De este modo, se puede observar cómo ambas configuraciones logran alcanzar la misma posición y orientación del extremo del manipulador.

<p align="center">
  <img src="https://github.com/GuillermoDuarte888/MecaChess-Robotic-Arm/raw/main/Imagenes/Cinematica%20Directa%20simulacion.png" alt="Brazo Robótico" width="1100"/>
</p>


# Cinematica Inversa ♗

En el contexto del robot ajedrecista, la cinemática inversa se utiliza para determinar los ángulos de las articulaciones necesarios para alcanzar una posición y orientación específicas, como posicionar el efector final en una casilla del tablero. Se implementan tanto el método geométrico como el analítico para verificar los resultados, considerando diferentes configuraciones, como codo arriba y codo abajo. Esta capacidad de ajuste es fundamental para garantizar un movimiento preciso y efectivo del robot al realizar sus jugadas. A modo de corroboración, se puede observar que la posición y orientación proporcionadas por la cinemática directa, al ser ingresadas en la cinemática inversa, generan los mismos ángulos de las articulaciones utilizados en la cinemática directa. Esto valida la precisión de ambos métodos y asegura que el robot puede reproducir efectivamente las posiciones deseadas en el tablero.

<p align="center">
  <img src="https://github.com/GuillermoDuarte888/MecaChess-Robotic-Arm/raw/main/Imagenes/Cinematica%20Directa%20e%20Inversa.png" alt="Brazo Robótico" width="1100"/>
</p>

# Diseño Mecanico del Brazo Robot🗜️

En esta sección se presenta el diseño mecánico del robot ajedrecista, desglosando sus diferentes componentes. Cada parte del robot está identificada con un número en la imagen, lo que facilitará su explicación. A continuación, se incluye una tabla que detalla las funciones y características de cada pieza.

<p align="center">
  <img src="https://github.com/GuillermoDuarte888/MecaChess-Robotic-Arm/raw/main/Imagenes/Piezas%20del%20Brazo%20Robot%20.png" alt="Brazo Robótico" width="1100"/>
</p>

| Número | Componente                      | Descripción                                       | Cantidad              |
|--------|----------------------------------|---------------------------------------------------|----------------------|
| 1      | Base                             | Soporte estable que sostiene todo el sistema.     | 1                    |
| 2      | Hombro                           | Permite el movimiento del brazo en diferentes ángulos. | 1               |
| 3      | Brazo                            | Conecta el hombro con el antebrazo, facilitando el movimiento. | 1       |
| 4      | Antebrazo                       | Parte que conecta el brazo con la muñeca.         | 1                     |
| 5      | Muñeca                          | Proporciona flexibilidad y movimiento del gripper.  | 1                   |
| 6      | Mano                             | El efector final que interactúa con el tablero.    | 1                   |
| 7      | Unión de Pinza parte 1         | Primera parte de la pinza que permite el agarre.   | 1                     |
| 8      | Unión de Pinza parte 2         | Segunda parte que complementa el mecanismo de agarre. | 1                  |
| 9      | Unión de Pinza parte 3         | Tercera parte que complementa el mecanismo de agarre. | 4                  |
| 10     | Dedos                            | Elemento que permiten un agarre preciso y controlado de las piezas. | 2  |


# Representación del Brazo Robótico en SolidWorks 🔧
<p align="center">
  <img src="https://github.com/GuillermoDuarte888/MecaChess-Robotic-Arm/raw/main/Imagenes/Brazo%20Robot%20dise%C3%B1o%20completo.png" alt="Brazo Robótico" width="500"/>
</p>


# Diseño de las Piezas y la Caja 📦

Las piezas del juego de ajedrez y la caja fueron diseñadas y rediseñadas varias veces hasta alcanzar las formas óptimas. Este proceso de iteración permitió que las piezas se adaptaran no solo de manera más efectiva al tablero, sino también al gripper del robot, garantizando un agarre seguro y funcional.

La caja fue diseñada en SolidWorks, lo que facilitó la creación de un diseño preciso y ajustado a las dimensiones necesarias. Para aumentar la estabilidad de las piezas, se incorporó una tuerca en la parte inferior de cada una. Este agregado no solo proporciona un mayor peso, sino que también ayuda a bajar el centro de gravedad, lo que a su vez mejora la estabilidad de las piezas durante el juego.

Este enfoque en el diseño y la estabilidad refleja un compromiso con la funcionalidad y la estética del proyecto, asegurando que cada componente trabaje en armonía.

# Tablero de Ajedrez ♘

El tablero de ajedrez tiene un tamaño de 18 x 18 cm y fue realizado de manera manual, pintado sobre madera reciclada. Se optó por el diseño clásico en blanco y negro, ya que este contraste permite una mejor detección de las piezas durante el juego. Además, en cada esquina del tablero se pintó un círculo de color amarillo, lo cual permite la deteccion del tablero. Este enfoque no solo resalta las piezas, sino que también proporciona una estética tradicional que es apreciada por los jugadores. La elección de materiales reciclados refleja un compromiso con la sostenibilidad y la creatividad en el diseño.

<p align="center">
  <img src="https://github.com/GuillermoDuarte888/MecaChess-Robotic-Arm/raw/main/Imagenes/Tablero.png" alt="Brazo Robótico" width="500"/>
</p>


# Materiales Reciclados Utilizados 🔄 

En este proyecto se hizo un esfuerzo consciente por utilizar materiales reciclados, contribuyendo así a la sostenibilidad y reducción de residuos. Este enfoque no solo permite ahorrar recursos, sino que también demuestra que no es necesario gastar mucho dinero cuando el ingenio y la creatividad predominan. Utilizar materiales reciclados no solo es una opción sostenible, sino que también abre la puerta a innovaciones únicas en el diseño y la construcción del proyecto. A continuación, se describen los materiales empleados:

- **Madera Reciclada:** Utilizada para construir el tablero de ajedrez asi como la base que sostiene todo el sistema, ofreciendo una estética única y rústica.

- **Componentes Electrónicos Reciclados:** Se incorporaron componentes de proyectos anteriores, incluyendo cables y una placa perforada que pertenecía a otro proyecto entre otros.

- **Trípode Reciclado:** El trípode que sostiene el celular fue hecho con varias partes de diferentes componentes, demostrando la versatilidad de los materiales reciclados.

- **Caja para Almacenamiento:** La caja donde se almacena toda la parte electrónica también fue fabricada con materiales reciclados.

- **Estructura del Pulsador:** La propia estructura que almacena el pulsador fue hecha de partes de elementos reciclados tambien.

- **Reutilización de Componentes:** Se reutilizaron más componentes de proyectos previos.


<h1 align="center">💡 Diseño Electronico del Proyecto 💡</h1> 


En esta sección, se describe la electrónica utilizada en el proyecto. Se utilizó Wokwi para presentar el esquema en un formato más legible y comprensible para cualquiera. Wokwi es una herramienta en línea que permite simular circuitos electrónicos, lo que facilita la visualización y comprensión del diseño.

# Diagrama del Circuito Electronico 🔌

<p align="center">
  <img src="https://github.com/GuillermoDuarte888/MecaChess-Robotic-Arm/raw/main/Imagenes/Circuito%20en%20wokwi.png" alt="Brazo Robótico" width="800"/>
</p>

# Componentes del Circuito Electrónico 🧩

- **Microcontrolador:** Arduino Mega
  - 💻 Controla todos los componentes del circuito y gestiona la lógica del proyecto.

- **Servomotores:**
  - ⚙️ **5 Servos MG996R:** Utilizados en las articulaciones Qn; las salidas de los pines son 7, 8, 9, 10 y 11.
  - ⚙️ **1 Servo SG90:** Utilizado para el gripper, permitiendo abrir y cerrar, salida en pin 13.

- **Resistencias:**
  - ⚡ **6 Resistencias de 10 kΩ:** Utilizadas para limitar la corriente en el circuito y proteger los componentes.

- **LEDs:**
  - 🔴 **4 LEDs Rojos:** Indicadores de estado o señales visuales, las salidas de los pines son 22, 26, 30, y 34.
  - 🟢 **1 LED Verde:** Indicador de funcionamiento, salida en el pin 3.

- **Pulsador:**
  - ⚪ **1 Pulsador de 4 patas:** Permite la interacción del usuario y el control manual del circuito, salida en el pin 2.

- **Fuente de Laboratorio:**
  - 🔋 **Fuente regulable de 5.5 V CC:** Proporciona la alimentación necesaria para el circuito.

El circuito se llevó a cabo en una plaqueta de cobre perforada, debido a que el diseño del circuito es bastante simple. Este tipo de plaqueta permite realizar conexiones de manera eficiente y rápida, sin la necesidad de recurrir a un diseño en software o a una placa de circuito impreso (PCB) más compleja. La simplicidad del conexionado facilita la construcción y modificación del circuito según se vaya actualizando.

<h1 align="center">🔑 Configuración y Ejecución del Código 🔑</h1> 

En esta sección, se explicará cómo compilar el código fuente del proyecto y cargar los valores necesarios en Python. Se abordarán los pasos para utilizar el entorno de desarrollo adecuado, asegurando que el código se ejecute correctamente. Además, se incluirán detalles sobre la configuración de parámetros y la verificación de conexiones antes de iniciar el proceso de carga.


# Paso 1: Conectar el celular a la computadora con Iriun Webcam

1. **Instalación:**
   - **Celular:** Descarga Iriun Webcam desde la [Play Store](https://play.google.com/store/apps/details?id=com.iriun.wifi.cam).
   - **Computadora:** Descarga e instala Iriun desde [su sitio web](https://iriun.com).

2. **Conexión:**
   - **Wi-Fi:** Asegúrate de que ambos dispositivos estén en la misma red.
   - **USB:** Conecta el celular por USB y habilita la "Depuración USB" en la configuración del celular.

3. **Verificación:** Comprueba que el software en la computadora muestre la transmisión de video del celular.


# Paso 2: Ejecución de la celda de calibración de extracción de color

1. Dirígete al código de Python y ejecuta la primera celda titulada **🔷Color Extraction Calibration🔷**.
2. Se abrirá la cámara. Coloca la cámara de modo que capte el tablero y las piezas.
3. Haz clic en el color **amarillo** en las esquinas del tablero, se abrira otra ventana donde mostrara solo las zonas detectadas, desliza ambas ventanas a su comodidad y presiona **"v"** para confirmar la seleccion del color.
4. Repite el proceso para los colores **azul** y **verde** en ese orden.
5. Después de definir los tres colores, presiona **"Esc"** para cerrar la ventana. Esta se abrirá nuevamente.
6. Selecciona el color **verde**; notarás que ahora detecta tanto las piezas verdes como las azules. Presiona **"v"** para confirmar y luego **"Esc"**.
7. Los valores se mostrarán debajo del código en el orden mencionado.
8. Aclaracion: Ajusta los colores tantas veces como haga falta dando clic en cada uno de ellos, teniendo en cuenta que solo tomara los valores al presionar "v"

# Paso 3: Cargar los valores en la celda de funciones

1. Dirígete a la celda titulada **🔶CODIGOS DE LAS FUNCIONES UTILIZADAS🔶**.
2. Carga los valores obtenidos de la calibración en el siguiente formato siguiendo el orden:

```python
# CARGAR LOS VALORES OBTENIDOS POR GOTEO AQUI:
Am1, Am2, Am3, Am4, Am5, Am6 = [12, 66, 169, 32, 255, 255]    # Amarillo
Az1, Az2, Az3, Az4, Az5, Az6 = [100, 116, 130, 120, 255, 255] # Azul
Ve1, Ve2, Ve3, Ve4, Ve5, Ve6 = [79, 86, 81, 99, 255, 255]     # Verde
AV1, AV2, AV3, AV4, AV5, AV6 = [79, 90, 76, 180, 255, 255]    # Verde y Azul
```
3. Asegúrate de cargar los valores en los vectores correspondientes dentro de los corchetes [].
4. Una vez cargados, ejecuta la celda para continuar.

# Paso 4: Ejecutar la celda "PUERTO SERIE"

1. Ejecuta la celda denominada **🌸PUERTO SERIE🌸**.
2. Carga el puerto correspondiente al que está conectado el Arduino en el siguiente formato:

```python
# Configura el puerto serie
arduino_port = 'COM5'  # Cambia esto al puerto correcto en tu sistema
baud_rate = 9600       # Velocidad de comunicación con Arduino
```
3. Para verificar el puerto, accede a la IDE de Arduino y dirígete a **Herramientas** > **Puerto**.

# Paso 5: Cargar el Código a la Placa Arduino

1. Selecciona el puerto y la placa correspondientes en el IDE de Arduino.
2. Compila el código para verificar que no haya errores.
3. Sube el código al microcontrolador haciendo clic en el botón de carga.

<h1 align="center">🎮 Inicio del Juego 🎮</h1> 

1. Ejecuta la última celda titulada **"Bucle principal"**.
2. Al ejecutarla, se abrirá una ventana con la vista de la cámara.
3. Presiona el botón rojo físico del juego:
   - En la primera activación, se capturará la imagen del tablero.
   - En la segunda activación, se registrarán las posiciones iniciales de las piezas.
4. Tras la segunda activación, se abrirá la interfaz del juego, donde se mostrará:
   - El tablero con las posiciones actuales de las piezas
   - Las jugadas realizadas por Stockfish
   - La validación de cada jugada
   - El turno actual del jugador
5. Para cada jugada de las piezas verdes, presiona el botón rojo al finalizar la jugada. Esto permitirá que el robot capture las posiciones actuales y continúe con el desarrollo del juego.

<p align="center">
  <img src="https://github.com/GuillermoDuarte888/MecaChess-Robotic-Arm/raw/main/Imagenes/Interfaz.png" alt="Interfaz" width="800"/>
</p>

# Consideraciones 📋

Es fundamental que no se realice ninguna acción sobre el tablero a menos que sea el turno del jugador ademas de otras recomendaciones que se detallaran a continuacion:

1. **Prevención de Detección Errónea:** Evitar que la cámara registre movimientos no deseados que puedan interferir con la detección de las piezas y el tablero.
   
2. **Seguridad:** Minimizar el riesgo de colisiones entre el brazo robótico y los jugadores, lo cual podría ocasionar daños tanto al equipo como a las personas involucradas.

3. **Integridad del Juego:** Asegurar que el flujo del juego se mantenga sin interrupciones ni confusiones en las jugadas.

4. **Iluminación Controlada:** Es crucial que el juego se desarrolle en un entorno con iluminación controlada. Evitar exposiciones a variaciones significativas de luz es esencial para asegurar la precisión en la detección.

5. **Posicionamiento del Dispositivo:** El dispositivo móvil debe estar posicionado por encima de la zona de trabajo del robot, ajustando adecuadamente la altura del trípode para garantizar una visualización óptima del tablero y las piezas.

<h1 align="center">🤖 Proyecto en Funcionamiento 🤖</h1>
<p align="center">
  <img src="https://github.com/GuillermoDuarte888/MecaChess-Robotic-Arm/raw/main/Imagenes/brazo%20robot.gif" alt="Demostración" width="300"/>
</p>

<h1 align="center">♛ Futuras Propuestas y Mejoras ♛</h1> 


1. **Interfaz de Usuario Mejorada:** Desarrollar una interfaz más intuitiva y visualmente atractiva que facilite la interacción del usuario durante el juego.

2. **Registro de Estadísticas:** Implementar un sistema de registro que capture estadísticas del juego, como movimientos realizados y tiempo de juego, para análisis posterior.

3. **Actualizaciones de Firmware:** Proporcionar actualizaciones periódicas del firmware del Arduino para mejorar el rendimiento y corregir errores.

4. **Incorporación de IA:** Integrar inteligencia artificial para que el sistema pueda interactuar verbalmente con los jugadores, brindando comentarios y sugerencias durante el juego.

5. **Integración de LEDs RGB:** Incorporar LEDs RGB que se adapten al juego, proporcionando efectos visuales que reflejen el estado del juego y las acciones de los jugadores.


# Reconocimientos 📝

Quisiera expresar mi más sincero agradecimiento a varias personas y organizaciones que hicieron posible este proyecto:

**Gaston Alejandro Díaz**: Quiero expresar mi sincero agradecimiento a mi colega por su apoyo incondicional y valiosa colaboración a lo largo de toda la carrera. Nuestro crecimiento y evolución conjunta han sido esenciales para el éxito de este proyecto, y su dedicación ha sido una fuente constante de inspiración 🌟.


**Profesor Ingeniero Cristian Leandro Lukaszewicz**: Estoy profundamente agradecido con el profesor Lukasiewicz por supervisar nuestra Práctica Profesional Supervisada (PPS) y por su valiosa orientación y apoyo durante todo el proceso en la carrera de Ingeniería Mecatrónica. Su compromiso y profesionalismo han sido una fuente de inspiración, estableciendo un ejemplo a seguir en el campo de la ingeniería y motivándome a alcanzar mis metas académicas y profesionales.

**Ezequiel Blanca y Juan Ignacio Szombach**: Un agradecimiento a ambos profesores quienes tambien formaron parte como supervisores del proyecto, aportando sus recomendaciones, conocimientos y orientandonos para su concrecion.

**Universidad Nacional de Lomas de Zamora**, Facultad de Ingeniería: Agradezco sinceramente a la universidad por brindarme acceso a un entorno académico enriquecedor que ha facilitado mi desarrollo y me ha permitido adquirir valiosos conocimientos en mi formación como ingeniero.

**A mis profesores y familiares**: Quiero expresar mi agradecimiento a todos mis profesores y a mi familia por su apoyo incondicional a lo largo de este proceso. Su aliento y orientación han sido fundamentales en mi formación y crecimiento personal.

**A todos los lectores**: Espero que este proyecto les resulte interesante y útil.

