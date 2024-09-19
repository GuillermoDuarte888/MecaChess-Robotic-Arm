<h1 align="center">MecaChess Robotic Arm</h1>

<p align="center">
  <img src="https://github.com/GuillermoDuarte888/MecaChess-Robotic-Arm/raw/main/brazo%20robot%20.jpg" alt="Brazo Robótico" width="400"/>
</p>


El presente proyecto denominado **"MecaChess Robotic Arm"** tiene como finalidad la creación de un brazo robótico antropomórfico de 4 grados de libertad, diseñado para jugar al ajedrez de manera autónoma. Además, se le incorporaron funciones adicionales que permiten acomodar las piezas al inicio de una partida, jugar a través de la aplicación Chess.com, moverse por comandos de voz e identificar jugadas ilegales, entre otras. Para hacerlo más accesible, se emplearon materiales económicos y reciclados, logrando un balance óptimo entre costo y precisión sin comprometer la funcionalidad del brazo. Por último, se continúa trabajando en la incorporación de nuevas funcionalidades, como la implementación de inteligencia artificial y mejoras en el diseño, entre otros aspectos.

<h1 align="center">Recursos y Tecnologias Integradas</h1> 

# Software Empleado

| Software                  | Descripción                                                                                        |
|--------------------------|-----------------------------------------------------------------------------------------------------|
| SolidWorks 2021          |  Se empleó SolidWorks 2024 para el diseño del conjunto elemental, la modelación de diversos componentes y la utilización de su biblioteca de herramientas para tornillos, tuercas y otros elementos de fijación. |
| Proteus 8 Professional    | Se usó Proteus 8 Professional para el diseño del esquema electrónico y su correspondiente simulacion |
| Python                  | Se utilizó Python para el desarrollo de la lógica del juego, incluyendo la detección de piezas, el manejo del tablero y el mapeo de las jugadas.   |
| Arduino IDE              |  Se utilizó Arduino IDE para programar la lógica de las cinemáticas y las funciones necesarias para controlar los movimientos del brazo robótico. |
|  Stockfish                | Se utilizó Stockfish como motor de ajedrez para la evaluación de posiciones y la generación de movimientos óptimos durante las partidas.         |

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

# Diseño Mecanico

En esta sección se presenta el diseño mecánico del robot ajedrecista, desglosando sus diferentes componentes. Cada parte del robot está identificada con un número en la imagen, lo que facilitará su explicación. A continuación, se incluye una tabla que detalla las funciones y características de cada pieza.

<p align="center">
  <img src="https://github.com/GuillermoDuarte888/MecaChess-Robotic-Arm/raw/main/Piezas%20del%20Brazo%20Robot.png" alt="Brazo Robótico" width="1100"/>
</p>

| Número | Componente                      | Descripción                                       |
|--------|----------------------------------|---------------------------------------------------|
| 1      | Base                             | Soporte estable que sostiene todo el sistema.     |
| 2      | Hombro                           | Permite el movimiento del brazo en diferentes ángulos. |
| 3      | Brazo                            | Conecta el hombro con el antebrazo, facilitando el movimiento. |
| 4      | Antebrazo                       | Parte que conecta el brazo con la muñeca.         |
| 5      | Muñeca                          | Proporciona flexibilidad y movimiento del gripper.  |
| 6      | Mano                             | El efector final que interactúa con el tablero.    |
| 7      | Unión de Pinza parte 1         | Primera parte de la pinza que permite el agarre.   |
| 8      | Unión de Pinza parte 2         | Segunda parte que complementa el mecanismo de agarre. |
| 9      | Unión de Pinza parte 3         | Tercera parte que complementa el mecanismo de agarre. |
| 10     | Dedos                            | Elemento que permiten un agarre preciso y controlado de las piezas. |

<p align="center">
  <img src="https://github.com/GuillermoDuarte888/MecaChess-Robotic-Arm/raw/main/Cinematica%20Directa%20e%20Inversa.png" alt="Brazo Robótico" width="1100"/>
</p>

# Diseño Mecanico



<h2 align="center">Pruebas de Precision</h2>
<p align="center">
  <img src="https://github.com/GuillermoDuarte888/MecaChess-Robotic-Arm/raw/main/brazo%20robot.gif" alt="Demostración" width="300"/>
</p>

