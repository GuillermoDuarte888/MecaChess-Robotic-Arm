
<p align="center">
  <img src="https://github.com/GuillermoDuarte888/MecaChess-Robotic-Arm/raw/main/Logo%20de%20la%20Facultad%20de%20Ingenieria.png" alt="Brazo Robótico" width="800"/>
</p>



<h1 align="center" style="font-size: 3em;">♟️ MecaChess Robotic Arm ♟️</h1>

<p align="center">
  <img src="https://github.com/GuillermoDuarte888/MecaChess-Robotic-Arm/raw/main/brazo%20robot.jpg" width="400"/>
</p>

# Integrantes
<p>👤 Guillermo Daniel Duarte</p>
<p>👤 Gaston Alejandro Díaz</p>
</section>

# Introduccion

El presente proyecto denominado **"MecaChess Robotic Arm"** tiene como finalidad la creación de un brazo robótico antropomórfico de 4 grados de libertad, diseñado para jugar al ajedrez de manera autónoma. Además, se le incorporaron funciones adicionales que permiten acomodar las piezas al inicio de una partida, jugar a través de la aplicación Chess.com, moverse por comandos de voz e identificar jugadas ilegales, entre otras. Para hacerlo más accesible, se emplearon materiales económicos y reciclados, logrando un balance óptimo entre costo y precisión sin comprometer la funcionalidad del brazo. Por último, se continúa trabajando en la incorporación de nuevas funcionalidades, como la implementación de inteligencia artificial y mejoras en el diseño, entre otros aspectos.

<h1 align="center">Recursos y Tecnologias Integradas</h1> 

# Software Empleados

| Software                  | Descripción                                                                                        |
|--------------------------|-----------------------------------------------------------------------------------------------------|
| SolidWorks 2023          |  Se empleó SolidWorks 2023 para el diseño del conjunto elemental, la modelación de diversos componentes y la utilización de su biblioteca de herramientas para tornillos, tuercas y otros elementos de fijación. |
| Proteus 8 Professional    | Se usó Proteus 8 Professional para el diseño del esquema electrónico y su correspondiente simulacion |
| Python                  | Se utilizó Python para el desarrollo de la lógica del juego, incluyendo la detección de piezas, el manejo del tablero y el mapeo de las jugadas.   |
| Arduino IDE              |  Se utilizó Arduino IDE para programar la lógica de las cinemáticas y las funciones necesarias para controlar los movimientos del brazo robótico. |
|  Stockfish                | Se utilizó Stockfish como motor de ajedrez para la evaluación de posiciones y la generación de movimientos óptimos durante las partidas.         |
| Iriun Webcam | Se implementó Iriun Webcam para establecer una conexión entre el teléfono móvil, utilizado como cámara, y el entorno de programación Python, facilitando así su control y gestión de manera eficiente. |

# Bibliotecas de Phyton Utilizadas

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


<h1 align="center">Diseño Mecanico y Cinematicas</h1> 

# Cinematica Directa

La cinemática directa permite calcular la posición y orientación del efector final del robot ajedrecista a partir de los valores de las articulaciones. Para ello, se utilizan transformaciones homogéneas aplicadas de manera sistemática, empleando el método de Denavit-Hartenberg. Este enfoque proporciona un marco estándar para representar las configuraciones articulares y facilita la obtención de las coordenadas del efector final en el espacio tridimensional. Comprender este proceso es fundamental para analizar el movimiento del robot en el tablero de ajedrez y es esencial para el diseño de algoritmos de control de trayectorias que optimicen su desempeño en el juego.

<p align="center">
  <img src="https://github.com/GuillermoDuarte888/MecaChess-Robotic-Arm/blob/main/Cinematica%20Directa%20Robot%204%20GDL.png" alt="Brazo Robótico" width="800"/>
</p>

El siguiente programa, desarrollado en Python, permite simular diversas configuraciones de articulaciones que alcanzan una misma posición del extremo del manipulador robótico, mostrando así las diferentes alternativas disponibles. En la imagen de la derecha, se puede observar que q3 tiene la configuración "codo arriba", lo que hace que q2 deba quedar hacia abajo, ya que su cálculo depende de q3. Por otro lado, en la imagen de la izquierda, q3 presenta la configuración "codo abajo", lo que implica que q2 debe posicionarse hacia arriba, de acuerdo con la relación mencionada entre ambos ángulos. De este modo, se puede observar cómo ambas configuraciones logran alcanzar la misma posición y orientación del extremo del manipulador.

<p align="center">
  <img src="https://github.com/GuillermoDuarte888/MecaChess-Robotic-Arm/raw/main/Cinematica%20Directa%20simulacion.png" alt="Brazo Robótico" width="1100"/>
</p>


# Cinematica Inversa

En el contexto del robot ajedrecista, la cinemática inversa se utiliza para determinar los ángulos de las articulaciones necesarios para alcanzar una posición y orientación específicas, como posicionar el efector final en una casilla del tablero. Se implementan tanto el método geométrico como el analítico para verificar los resultados, considerando diferentes configuraciones, como codo arriba y codo abajo. Esta capacidad de ajuste es fundamental para garantizar un movimiento preciso y efectivo del robot al realizar sus jugadas. A modo de corroboración, se puede observar que la posición y orientación proporcionadas por la cinemática directa, al ser ingresadas en la cinemática inversa, generan los mismos ángulos de las articulaciones utilizados en la cinemática directa. Esto valida la precisión de ambos métodos y asegura que el robot puede reproducir efectivamente las posiciones deseadas en el tablero.

<p align="center">
  <img src="https://github.com/GuillermoDuarte888/MecaChess-Robotic-Arm/raw/main/Cinematica%20Directa%20e%20Inversa.png" alt="Brazo Robótico" width="1100"/>
</p>

# Diseño Mecanico del Brazo Robot

En esta sección se presenta el diseño mecánico del robot ajedrecista, desglosando sus diferentes componentes. Cada parte del robot está identificada con un número en la imagen, lo que facilitará su explicación. A continuación, se incluye una tabla que detalla las funciones y características de cada pieza.

<p align="center">
  <img src="https://github.com/GuillermoDuarte888/MecaChess-Robotic-Arm/raw/main/Piezas%20del%20Brazo%20Robot.png" alt="Brazo Robótico" width="1100"/>
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


# Representación del Brazo Robótico en SolidWorks
<p align="center">
  <img src="https://github.com/GuillermoDuarte888/MecaChess-Robotic-Arm/raw/main/Brazo%20Robot%20dise%C3%B1o%20completo.png" alt="Brazo Robótico" width="500"/>
</p>


# Diseño de las Piezas y la Caja

<h1 align="center">Diseño Electronico del Proyecto</h1> 


En esta sección, se describe la electrónica utilizada en el proyecto. Se utilizó Wokwi para presentar el esquema en un formato más legible y comprensible para cualquiera. Wokwi es una herramienta en línea que permite simular circuitos electrónicos, lo que facilita la visualización y comprensión del diseño.

# Diagrama del Circuito Electronico



## Componentes del Circuito Electrónico

- **Microcontrolador:** Arduino Mega
  - Controla todos los componentes del circuito y gestiona la lógica del proyecto.

- **Servomotores:**
  - **5 Servos MG996R:** Utilizados en las articulaciones Qn; 2 de ellos están en la articulación Q2 para mayor control.
  - **1 Servo SG90:** Utilizado para el gripper, permitiendo abrir y cerrar.

- **Resistencias:**
  - **6 Resistencias de 10 kΩ:** Utilizadas para limitar la corriente en el circuito y proteger los componentes.

- **LEDs:**
  - **4 LEDs Rojos:** Indicadores de estado o señales visuales.
  - **1 LED Verde:** Indicador de funcionamiento.

- **Pulsador:**
  - **1 Pulsador de 4 patas:** Permite la interacción del usuario y el control manual del circuito.

- **Fuente de Laboratorio:**
  - **Fuente regulable de 5.5 V CC:** Proporciona la alimentación necesaria para el circuito.


<h2 align="center">Pruebas de Precision</h2>
<p align="center">
  <img src="https://github.com/GuillermoDuarte888/MecaChess-Robotic-Arm/raw/main/brazo%20robot.gif" alt="Demostración" width="300"/>
</p>


# Reconocimientos

Quisiera expresar mi más sincero agradecimiento a varias personas y organizaciones que hicieron posible este proyecto:

**Gaston Alejandro Díaz**: Quiero expresar mi sincero agradecimiento a mi colega por su apoyo incondicional y valiosa colaboración a lo largo de toda la carrera. Nuestro crecimiento y evolución conjunta han sido esenciales para el éxito de este proyecto, y su dedicación ha sido una fuente constante de inspiración.


**Profesor Ingeniero Cristian Leandro Lukasiewicz**: Estoy profundamente agradecido con el profesor Lukasiewicz por supervisar nuestra Práctica Profesional Supervisada (PPS) y por su valiosa orientación y apoyo durante todo el proceso en la carrera de Ingeniería Mecatrónica. Su compromiso y profesionalismo han sido una fuente de inspiración, estableciendo un ejemplo a seguir en el campo de la ingeniería y motivándome a alcanzar mis metas académicas y profesionales.

**Universidad Nacional de Lomas de Zamora**, Facultad de Ingeniería: Agradezco sinceramente a la universidad por brindarme acceso a un entorno académico enriquecedor que ha facilitado mi desarrollo y me ha permitido adquirir valiosos conocimientos en mi formación como ingeniero.

**A mis profesores y familiares**: Quiero expresar mi agradecimiento a todos mis profesores y a mi familia por su apoyo incondicional a lo largo de este proceso. Su aliento y orientación han sido fundamentales en mi formación y crecimiento personal.

**A todos los lectores**: Espero que este proyecto les resulte interesante y útil.

