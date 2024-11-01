

<h1 align="center" style="font-size: 3em;">♘ MecaChess Robotic Arm ♘</h1>


<p align="center">
  <img src="https://github.com/GuillermoDuarte888/MecaChess-Robotic-Arm/blob/main/Imagenes/Demostracion%20Brazo%20Robot.gif" alt="Demostración" width="300"/>
  <br>
  <em>MecaChess in Action</em>
</p>

# Team Members
<p>👤 <a href="https://github.com/GuillermoDuarte888">Guillermo Daniel Duarte</a></p>
<p>👤 <a href="https://github.com/GastonADiaz">Gastón Alejandro Díaz</a></p>


# Index
- **1.0** [🔗 Introduction 🔗](#-introduction-)
- **2.0** [📲 Project Features 📲](#-project-features-)
    - **2.1** [Voice Command Control](#voice-command-control)
    - **2.2** [Integration with Chess.com](#integration-with-chess)
    - **2.3** [Kinematic Simulation](#kinematic-simulation)
    - **2.4** [Graphical User Interface and Autonomous Play](#graphical-user-interface-and-autonomous-play)
 - **3.0** [💻 Integrated Resources and Technologies 💻](#-integrated-resources-and-technologies-)
    - **3.1** [Software Used](#software-used-)
    - **3.2** [Python Libraries Used](#python-libraries-used-)
- **4.0** [🔩 Mechanical Design and Kinematics 🔩](#-mechanical-design-and-kinematics-)
    - **4.1** [Direct Kinematics](#direct-kinematics-)
    - **4.2** [Inverse Kinematics](#inverse-kinematics-)
    - **4.3** [Mechanical Design of the Robotic Arm](#mechanical-design-of-the-robotic-arm-)
    - **4.4** [Representation of the Robotic Arm in SolidWorks](#representation-of-the-robotic-arm-in-solidworks-)
    - **4.5** [Design of the Pieces and the Box](#design-of-the-pieces-and-the-box-)
    - **4.6** [Chessboard](#chessboard-)
    - **4.7** [Recycled Materials Used](#recycled-materials-used-)
- **5.0** [💡 Electronic Design of the Project 💡](#-electronic-design-of-the-project-)
    - **5.1** [Electronic Circuit Diagram](#electronic-circuit-diagram-)
    - **5.2** [Components of the Electronic Circuit](#components-of-the-electronic-circuit-)
- **6.0** [📲 Setting Up and Running the Main Code 📲](#Setting-Up-and-Running-the-Main-Code)
    - **6.1** [Connect the Phone to the Computer with Iriun Webcam](#connect-the-phone-to-the-computer-with-iriun-webcam)
    - **6.2** [Execute the Color Extraction Calibration Cell](#execute-the-color-extraction-calibration-cell)
    - **6.3** [Load the Values into the Functions Cell](#load-the-values-into-the-functions-cell)
    - **6.4** [Run the SERIAL PORT Cell](#run-the-serial-port-cell)
    - **6.5** [Upload the Code to the Arduino Board](#upload-the-code-to-the-arduino-board)
- **7.0** [🎮 Start the Game 🎮](#-start-the-game-)
    - **7.1** [Considerations](#considerations-)
- **8.0** [🤖 Project in Operation 🤖](#-project-in-operation-)
- **9.0** [♛ Future Proposals and Improvements ♛](#-future-proposals-and-improvements-)
- **10.0** [📝 Acknowledgments 📝](#-acknowledgments-)

  
<h1 align="center">🔗 Introduction 🔗</h1>

This project, titled **"MecaChess Robotic Arm,"** aims to create an anthropomorphic robotic arm with 4 degrees of freedom, designed to play chess autonomously. Additionally, it includes extra features that allow it to set up pieces at the start of a game, play through the Chess.com application, move via voice commands, and identify illegal moves, among others. To make it more accessible, affordable and recycled materials were used, achieving an optimal balance between cost and precision without compromising the arm's functionality. Finally, work continues on incorporating new features, such as implementing artificial intelligence and design improvements, among other aspects.

<p align="center">
  <img src="https://github.com/GuillermoDuarte888/MecaChess-Robotic-Arm/blob/main/Imagenes/Renderizado%20del%20Brazo%20Robot%20con%20las%20Piezas.JPG" alt="Brazo Robótico" width="800"/>
  <br>
  <em>Rendering of the robotic arm with the parts</em>
</p>

<h1 align="center">📲 Project Features 📲</h1>
This project presents an innovative chess-playing experience, incorporating multiple functionalities that enhance interactivity and control. Below are the main features:

## Voice Command Control
The system allows users to move pieces and capture opponents using voice commands. Simply indicate the squares to which you want to move the pieces or the ones you wish to capture, and the robotic arm will execute the corresponding action.

## Integration with Chess
Users can play online against other players on the [Chess.com](https://www.chess.com/home) platform. The robotic arm replicates the moves made by opponents in real-time, providing a smooth and dynamic gaming experience.

<p align="center">
  <img src="https://github.com/user-attachments/assets/c86f5850-0269-4ffa-8e88-f5735e09054a" alt="Colores de chess.com" width="500"/>
  <br>
  <em>Board setup and colors on chess.com</em>
</p>

Below is a sequence of movements, and we see what Python actually sees when executing each movement. In this way, the location of the pieces can be obtained anywhere on the board and chess can be played remotely online using the robotic arm.

<p align="center">
  <img src="https://github.com/user-attachments/assets/294ad7f8-78fa-451c-a1b5-81eba574587d" alt="Colores de chess.com" width="500"/>
  <br>
  <em>Sequence of moves read on chess.com</em>
</p>

## Kinematic Simulation
A Python program has been developed to simulate both direct and inverse kinematics of the robotic arm. This simulation is conducted in a three-dimensional plane, allowing for visualization and planning of movements before execution. Once calculated, commands are sent to the microcontroller for precise replication by the arm.

## Graphical User Interface and Autonomous Play
The project's graphical user interface displays key information during the game, such as the validity of each move, the moves made, and the player's turn. Additionally, the system has the capability to play chess autonomously, evaluating possible moves and making strategic decisions. This allows users to enjoy a game without manual intervention, making the experience more immersive.

<p align="center">
  <img src="https://github.com/GuillermoDuarte888/MecaChess-Robotic-Arm/blob/main/Imagenes/Jugada%20del%20Pastor.gif" alt="Colores de chess.com" width="600"/>
  <br>
  <em>Fool's Mate</em>
</p>


This project combines advanced technology and fun, offering a unique and engaging chess-playing experience.


<p align="center">
  <img src="https://github.com/GuillermoDuarte888/MecaChess-Robotic-Arm/blob/main/Imagenes/Untitled8.JPG" alt="Brazo Robótico" width="800"/>
  <br>
  <em>High-Resolution Render of Robotic Arm Parts</em>
</p>

<h1 align="center">💻 Integrated Resources and Technologies 💻</h1>

## Software Used ♕

| Software                 | Description                                                                                         |
|--------------------------|-----------------------------------------------------------------------------------------------------|
| SolidWorks 2023          | SolidWorks 2023 was used for designing the elemental assembly, modeling various components, and utilizing its library of tools for screws, nuts, and other fastening elements. |
| Python                   | Python was used for developing the game logic, including piece detection, board management, and move mapping.   |
| Arduino IDE              | Arduino IDE was used to program the kinematics logic and the necessary functions to control the movements of the robotic arm. |
| Stockfish                | [Stockfish](https://stockfishchess.org/download/) was used as a chess engine for evaluating positions and generating optimal moves during games.         |
| Iriun Webcam             | Iriun Webcam was implemented to establish a connection between the mobile phone, used as a camera, and the Python programming environment, facilitating efficient control and management. |
| Wokwi                    | [Wokwi](https://wokwi.com/) is an online tool used to design and simulate electronic circuits. It allows the creation of interactive diagrams, making it easier to visualize the circuit and test the code before implementing it in hardware. |

## Python Libraries Used 📚

| Library                  | Description                                                                                         |
|--------------------------|-----------------------------------------------------------------------------------------------------|
| OpenCV                   | A library for computer vision tasks, used for image processing and object detection.               |
| NumPy                    | A library for numerical calculations, which facilitates array manipulation and complex mathematical operations. |
| Matplotlib               | A library for data visualization and graphics, allowing the creation of graphical representations of information. |
| Chess                    | A library that manages the rules of chess, including moves, validations, and game analysis.       |
| IPython.display          | A tool for displaying graphics and SVG in Jupyter notebooks, facilitating data visualization.      |
| Serial                   | A library that allows serial communication with external devices, useful for interacting with hardware. |
| Time                     | A module that provides functions for measuring and controlling time, used for event synchronization. |
| Copy                     | A module that allows the creation of shallow and deep copies of objects in Python.                 |
| PyQt                     | The PyQt library was used to develop the graphical interface for the kinematics, facilitating user interaction with the system. |

>[!NOTE]
> These libraries are used only in the main code.

<h1 align="center">🔩 Mechanical Design and Kinematics 🔩</h1>

## Direct Kinematics

Direct kinematics allows for the calculation of the position and orientation of the end effector of the chess robot based on the joint values. To achieve this, homogeneous transformations are systematically applied using the Denavit-Hartenberg method. This approach provides a standard framework for representing joint configurations and facilitates the obtaining of the end effector's coordinates in three-dimensional space. 

<p align="center">
  <img src="https://github.com/GuillermoDuarte888/MecaChess-Robotic-Arm/raw/main/Imagenes/Cinematica%20Directa%20Robot%204%20GDL.png" alt="Direct Kinematics" width="800"/>
  <br>
  <em>Direct Kinematics Diagram by Denavit-Hartenberg method</em>
</p>

## Inverse Kinematics
Inverse kinematics (IK) is a crucial concept in robotics , allowing us to determine the joint configurations needed to achieve a desired position and orientation of an end effector. One of the aspects of IK is that there are often multiple possible solutions to reach the same target position. 

In the case of a robotic arm, the elbow joints can be oriented in different ways: "elbow up" and "elbow down." This duality provides flexibility in motion but also adds complexity to the calculations.

To compute the joint angles (q1, q2, q3, and q4) needed to reach a specified position (px, py, pz) and orientation (represented by Euler angles, focusing primarily on the pitch angle), we can apply various mathematical techniques. We utilize two different methods for obtaining the inverse kinematics:

1. **Geometric Method**
2. **Analytical Method**

In the following image, the robotic arm is illustrated for working with the geometric method.

<p align="center">
  <img src="https://github.com/user-attachments/assets/f6cc374f-69de-45bd-9fd1-19a5f92bc60c" alt="Inverse Kinematics" width="800"/>
  <br>
  <em>Inverse kinematics by geometric method</em>
</p>

### Simulation of Direct and Inverse Kinematics

A simulation was conducted in Python, utilizing several libraries, most notably Matplotlib for visualizing the 3D Cartesian axes, and PyQT for developing the kinematics interface. On the left side of the interface, you can observe the direct kinematics, while the right side displays the inverse kinematics.

When inputting values, the simulation visualizes the links of the robotic arm and its joints, updating in real-time when the "Calculate" button is pressed. Additionally, the program can send commands to an Arduino to replicate the movements of the robotic arm in real life. This application also provides outputs for both direct and inverse kinematics, allowing users to verify results against one another.

<p align="center">
  <img src="https://github.com/user-attachments/assets/84c889c3-6aad-4fdd-87c6-5bcd99d83bc2" alt="Forward and inverse kinematics" width="1100"/>
  <br>
  <em>Forward and inverse kinematics with interface made in PyQt</em>
</p>

## Mechanical Design of the Robotic Arm 

In this section, the mechanical design of the chess robot is presented, breaking down its various components. Each part of the robot is identified with a number in the image, which will facilitate its explanation. Below is a table detailing the functions and features of each piece.

<p align="center">
  <img src="https://github.com/GuillermoDuarte888/MecaChess-Robotic-Arm/raw/main/Imagenes/Piezas%20del%20Brazo%20Robot%20.png" alt="Brazo Robótico" width="1100"/>
  <br>
  <em>Mechanical parts that compose the robotic arm</em>
</p>


| Number | Component                       | Description                                       | Quantity             |
|--------|---------------------------------|---------------------------------------------------|----------------------|
| 1      | Base                            | A stable support that holds the entire system.    | 1                    |
| 2      | Shoulder                        | Allows the arm to move at different angles.       | 1                    |
| 3      | Arm                             | Connects the shoulder with the forearm, facilitating movement. | 1       |
| 4      | Forearm                         | The part that connects the arm with the wrist.     | 1                    |
| 5      | Wrist                           | Provides flexibility and movement for the gripper. | 1                    |
| 6      | Hand                            | The end effector that interacts with the board.    | 1                    |
| 7      | Gripper Joint Part 1           | The first part of the gripper that allows for grasping. | 1                |
| 8      | Gripper Joint Part 2           | The second part that complements the grasping mechanism. | 1               |
| 9      | Gripper Joint Part 3           | The third part that complements the grasping mechanism. | 4               |
| 10     | Fingers                         | Elements that allow for precise and controlled grasping of pieces. | 2  |


## Representation of the Robotic Arm in SolidWorks 
<p align="center">
  <img src="https://github.com/GuillermoDuarte888/MecaChess-Robotic-Arm/blob/main/Imagenes/Renderizacion%20del%20Brazo%20Robot.JPG" alt="Brazo Robótico" width="500"/>
  <br>
  <em>Robot arm in SolidWorks</em>
</p>

## Design of the Pieces and the Box 

The chess pieces and the box were designed and redesigned multiple times to achieve optimal shapes. This iterative process allowed the pieces to adapt not only more effectively to the board but also to the robot's gripper, ensuring a secure and functional grasp.


<p align="center">
  <img src="https://github.com/GuillermoDuarte888/MecaChess-Robotic-Arm/blob/main/Imagenes/Untitled11.JPG" alt="Brazo Robótico" width="500"/>
  <br>
  <em>Rendering of the box with its parts</em>
</p>

The box was designed in SolidWorks, which facilitated the creation of a precise design tailored to the necessary dimensions. To increase the stability of the pieces, a nut was incorporated into the bottom of each one. This addition not only provides greater weight but also helps lower the center of gravity, which in turn improves the stability of the pieces during play.

<p align="center">
  <img src="https://github.com/GuillermoDuarte888/MecaChess-Robotic-Arm/blob/main/Imagenes/Untitled14.JPG" alt="Brazo Robótico" width="500"/>
  <br>
  <em>3D Render of the Box and Its Components</em>
</p>


This focus on design and stability reflects a commitment to the functionality and aesthetics of the project, ensuring that each component works in harmony.


<p align="center">
  <img src="https://github.com/GuillermoDuarte888/MecaChess-Robotic-Arm/blob/main/Imagenes/Piezas%20Verdes.JPG" alt="Brazo Robótico" width="500"/>
  <br>
  <em>Rendering of the parts</em>
</p>

## Chessboard 

The chessboard measures 18 x 18 cm and was handmade, painted on recycled wood. The classic black and white design was chosen, as this contrast allows for better piece detection during play. Additionally, a yellow circle was painted in each corner of the board to aid in board detection. This approach not only highlights the pieces but also provides a traditional aesthetic that is appreciated by players. The choice of recycled materials reflects a commitment to sustainability and creativity in design.


<p align="center">
  <img src="https://github.com/GuillermoDuarte888/MecaChess-Robotic-Arm/raw/main/Imagenes/Tablero.png" alt="Brazo Robótico" width="500"/>
  <br>
  <em>Chessboard</em>
</p>


## Recycled Materials Used  

In this project, a conscious effort was made to use recycled materials, contributing to sustainability and waste reduction. This approach not only saves resources but also demonstrates that it is not necessary to spend a lot of money when ingenuity and creativity prevail. Using recycled materials is not only a sustainable option but also opens the door to unique innovations in the design and construction of the project. Below are the materials used:

- **Recycled Wood:** Used to build the chessboard as well as the base that supports the entire system, offering a unique and rustic aesthetic.

- **Recycled Electronic Components:** Components from previous projects were incorporated, including wires and a perforated board that belonged to another project, among others.

- **Recycled Tripod:** The tripod holding the phone was made with various parts from different components, demonstrating the versatility of recycled materials.

- **Storage Box:** The box where all the electronic parts are stored was also made from recycled materials.

- **Button Structure:** The structure that houses the button was also made from parts of recycled elements.

- **Reuse of Components:** More components from previous projects were reused.


<h1 align="center">💡 Electronic Design of the Project 💡</h1>

In this section, the electronics used in the project are described. Wokwi was used to present the schematic in a more readable and understandable format for everyone. Wokwi is an online tool that allows for the simulation of electronic circuits, making it easier to visualize and understand the design.

## Electronic Circuit Diagram 

<p align="center">
  <img src="https://github.com/GuillermoDuarte888/MecaChess-Robotic-Arm/blob/main/Imagenes/Circuito%20Electronico%20con%20Wokwi.png" alt="Brazo Robótico" width="800"/>
  <br>
  <em>Wiring of the electronic circuit</em>
</p>

## Components of the Electronic Circuit 

- **Microcontroller:** Arduino Mega
  - Controls all the components of the circuit and manages the project's logic.

- **Servomotors:**
  - **5 MG996R Servos:** Used in the joints Qn; the pin outputs are 7, 8, 9, 10, and 11.
  - **1 SG90 Servo:** Used for the gripper, allowing it to open and close, output on pin 13.

- **Resistors:**
  - **6 Resistors of 220 Ω:** Used to limit current in the circuit and protect the components.

- **LEDs:**
  - **4 RGB LEDs:** Status indicators or visual signals, with pin outputs of 22, 26, and 30.
  - **1 Green LED:** Functionality indicator, output on pin 3.

- **Button:**
  - **1 4-Pin Button:** Allows user interaction and manual control of the circuit, output on pin 2.

- **Buzzer:**
  - **1 Buzzer:** Emits sounds for alerts or signals, controlled via pin 34.

- **Laboratory Power Supply:**
  - **Adjustable 5.5 V DC Power Supply:** Provides the necessary power for the circuit.

The circuit was implemented on a perforated copper board, as the circuit design is quite simple. This type of board allows for efficient and quick connections without the need for software design or a more complex printed circuit board (PCB). The simplicity of the wiring facilitates the construction and modification of the circuit as updates are made.

<h1 align="center">📲Setting Up and Running the Main Code📲</h1>

In this section, we will explain how to compile the project's source code and load the necessary values in Python. The steps for using the appropriate development environment will be covered, ensuring that the code runs correctly. Additionally, details about parameter configuration and connection verification before starting the upload process will be included.

## Connect the Phone to the Computer with Iriun Webcam

1. **Installation:**
   - **Phone:** Download Iriun Webcam from the [Play Store](https://play.google.com/store/apps/details?id=com.jacksoftw.webcam&hl=es_AR).
   - **Computer:** Download and install Iriun from [its website](https://iriun.com).

2. **Connection:**
   - **Wi-Fi:** Make sure both devices are on the same network.
   - **USB:** Connect the phone via USB and enable "USB Debugging" in the phone's settings.

3. **Verification:** Check that the software on the computer displays the video feed from the phone.


## Execute the Color Extraction Calibration Cell

1. Go to the Python code and execute the first cell titled **🔷Color Extraction Calibration🔷**.
2. The camera will open. Position the camera so that it captures the board and pieces.
3. Click on the **yellow** color in the corners of the board; another window will open showing only the detected areas. Adjust both windows to your convenience and press **"v"** to confirm the color selection.
4. Repeat the process for the **blue** and **green** colors in that order.
5. After defining the three colors, press **"Esc"** to close the window. It will open again.
6. Select the **green** color; you will notice that it now detects both green and blue pieces. Press **"v"** to confirm and then **"Esc"**.
7. The values will be displayed below the code in the mentioned order.
8. Clarification: Adjust the colors as many times as necessary by clicking on each of them, keeping in mind that it will only take the values when you press "v".

## Load the Values into the Functions Cell

1. Go to the cell titled **🔶FUNCTION CODES USED🔶**.
2. Load the values obtained from the calibration in the following format, following the order:

```python
# LOAD THE OBTAINED VALUES BY DROPPING HERE:
Am1, Am2, Am3, Am4, Am5, Am6 = [12, 66, 169, 32, 255, 255]    # Yellow
Az1, Az2, Az3, Az4, Az5, Az6 = [100, 116, 130, 120, 255, 255] # Blue
Ve1, Ve2, Ve3, Ve4, Ve5, Ve6 = [79, 86, 81, 99, 255, 255]     # Green
AV1, AV2, AV3, AV4, AV5, AV6 = [79, 90, 76, 180, 255, 255]    # Green and Blue
```
3. Make sure to load the values into the corresponding vectors within the brackets [].
4. Once loaded, execute the cell to continue.

## Run the SERIAL PORT Cell

1. Execute the cell titled **🌸SERIAL PORT🌸**.
2. Load the port corresponding to which the Arduino is connected in the following format:

```python
# Configure the Serial Port
arduino_port = 'COM5'  # Change this to the correct port on your system
baud_rate = 9600       # Communication speed with Arduino
```
3. To verify the port, access the Arduino IDE and go to **Tools** > **Port**.

## Upload the Code to the Arduino Board

1. Select the corresponding port and board in the Arduino IDE.
2. Compile the code to check for any errors.
3. Upload the code to the microcontroller by clicking the upload button.

<h1 align="center">🎮 Start the Game 🎮</h1> 

1. Execute the last cell titled **"Main Loop"**.
2. When executed, a window with the camera view will open.
3. Press the physical red button of the game:
   - On the first activation, the image of the board will be captured.
   - On the second activation, the initial positions of the pieces will be recorded.
4. After the second activation, the game interface will open, displaying:
   - The board with the current positions of the pieces
   - The moves made by Stockfish
   - The validation of each move
   - The current turn of the player
5. For each move of the green pieces, press the red button after completing the move. This will allow the robot to capture the current positions and continue the game development.

<p align="center">
  <img src="https://github.com/GuillermoDuarte888/MecaChess-Robotic-Arm/blob/main/Imagenes/Tablero%20Interfaz.gif" alt="Interfaz" width="600"/>
  <br>
  <em>Graphical interface</em>
</p>

## Considerations 

It is essential that no actions are taken on the board unless it is the player's turn, along with other recommendations detailed below:

1. **Prevention of Mis-detection:** Avoid having the camera register unwanted movements that may interfere with the detection of the pieces and the board.
   
2. **Safety:** Minimize the risk of collisions between the robotic arm and players, which could cause damage to both the equipment and the individuals involved.

3. **Game Integrity:** Ensure that the flow of the game remains uninterrupted and that there is no confusion in the moves.

4. **Controlled Lighting:** It is crucial that the game takes place in an environment with controlled lighting. Avoid exposure to significant variations in light to ensure detection accuracy.

5. **Device Positioning:** The mobile device must be positioned above the robot's work area, adjusting the tripod height appropriately to ensure optimal viewing of the board and pieces.

<h1 align="center">🤖 Project in Operation 🤖</h1>

In this section, you can observe the robotic chess arm in action. The arm moves in real life, showcasing its capabilities in handling chess pieces.

[Click here to watch the robotic arm in action on YouTube!](https://www.youtube.com/watch?v=mJXuzqAW_us)

Below are a couple of GIFs demonstrating the functionality of the robotic arm:

1. **Initial Setup**  
   The first GIF shows the robotic arm arranging chess pieces from the white box into their starting positions on the board. This is particularly useful for setting up the game, as the arm places both green and blue pieces in their correct spots.
   
<p align="center">
  <img src="https://github.com/GuillermoDuarte888/MecaChess-Robotic-Arm/raw/main/Imagenes/brazo%20robot.gif" alt="Demostración" width="300"/>
  <br>
  <em>Robot arm placing pieces on the board</em>
</p>

2.**Capturing a Piece**  
   The second GIF illustrates how the arm captures a chess piece. When a piece is taken, it is moved to a designated box for captured pieces, ensuring proper handling of the game.

<p align="center">
  <img src="https://github.com/GuillermoDuarte888/MecaChess-Robotic-Arm/raw/main/Imagenes/Robot%20Jugada.gif" alt="Demostración" width="300"/>
  <br>
  <em>Capturing the piece</em>
</p>

<h1 align="center">♛ Future Proposals and Improvements ♛</h1> 

1. **Enhanced User Interface:** Develop a more intuitive and visually appealing interface that facilitates user interaction during the game.

2. **Statistics Logging:** Implement a logging system that captures game statistics, such as moves made and playtime, for later analysis.

3. **Firmware Updates:** Provide periodic updates for the Arduino firmware to improve performance and fix bugs.

4. **AI Integration:** Integrate artificial intelligence so the system can interact verbally with players, offering feedback and suggestions during the game.

<p align="center">
  <img src="https://github.com/GuillermoDuarte888/MecaChess-Robotic-Arm/blob/main/Imagenes/Untitled6.JPG" alt="Interfaz" width="800"/>
  <br>
  <em>Detailed Render of the Robot Arm</em>
</p>

<h1 align="center">📝 Acknowledgments 📝</h1> 

I would like to express my sincere gratitude to several people and organizations that made this project possible:

**Gaston Alejandro Díaz:** I want to express my heartfelt thanks to my colleague for his unwavering support and valuable collaboration throughout our studies. Our joint growth and evolution have been essential to the success of this project, and his dedication has been a constant source of inspiration 🌟.

**Professor Engineer Cristian Leandro Lukaszewicz:** I am deeply grateful to Professor Lukasiewicz for supervising our Supervised Professional Practice (PPS) and for his valuable guidance and support throughout the process in the Mechatronics Engineering program. His commitment and professionalism have been an inspiration, setting an example to follow in the field of engineering and motivating me to achieve my academic and professional goals.

**Ezequiel Blanca and Juan Ignacio Szombach:** I extend my gratitude to both professors who also served as project supervisors, providing their recommendations, knowledge, and guidance for its completion.

**National University of Lomas de Zamora, Faculty of Engineering:** I sincerely thank the university for providing me access to a rich academic environment that has facilitated my development and allowed me to acquire valuable knowledge in my training as an engineer.

**To my professors and family:** I want to express my gratitude to all my professors and my family for their unconditional support throughout this process. Their encouragement and guidance have been fundamental to my personal growth and development.

**To all readers:** I hope you find this project interesting and useful.

<p align="center">
  <img src="https://github.com/GuillermoDuarte888/MecaChess-Robotic-Arm/blob/main/Imagenes/Epic%20Nikola%20Tesla.gif" width="300"/>
  <br>
  <em>Nikola Tesla</em>
</p>


<p align="center">
  <img src="https://github.com/GuillermoDuarte888/MecaChess-Robotic-Arm/raw/main/Imagenes/Logo%20de%20la%20Facultad%20de%20Ingenieria.png" alt="Brazo Robótico" width="800"/>
</p>




