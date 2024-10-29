
<p align="center">
  <img src="https://github.com/GuillermoDuarte888/MecaChess-Robotic-Arm/raw/main/Imagenes/Logo%20de%20la%20Facultad%20de%20Ingenieria.png" alt="Brazo Robótico" width="800"/>
</p>

<h1 align="center" style="font-size: 3em;">♘ MecaChess Robotic Arm ♘</h1>

<p align="center">
  <img src="https://github.com/GuillermoDuarte888/MecaChess-Robotic-Arm/blob/main/Imagenes/Demostracion%20Brazo%20Robot.gif" alt="Demostración" width="300"/>
</p>

# Team Members
<p>👤 <a href="https://github.com/GuillermoDuarte888">Guillermo Daniel Duarte</a></p>
<p>👤 <a href="https://github.com/GastonADiaz">Gaston Alejandro Díaz</a></p>


# Index
- [Introduction 🔗](#introduction-)
 - [💻 Integrated Resources and Technologies 💻](#-integrated-resources-and-technologies-)
    - [Software Used ♕](#software-used-)
    - [Python Libraries Used 📚](#python-libraries-used-)
- [🔩 Mechanical Design and Kinematics 🔩](#-mechanical-design-and-kinematics-)
    - [Direct Kinematics ♖](#direct-kinematics-)
    - [Inverse Kinematics ♗](#inverse-kinematics-)
    - [Mechanical Design of the Robotic Arm 🎨](#mechanical-design-of-the-robotic-arm-)
    - [Representation of the Robotic Arm in SolidWorks 🔧](#representation-of-the-robotic-arm-in-solidworks-)
    - [Design of the Pieces and the Box 📦](#design-of-the-pieces-and-the-box-)
    - [Chessboard ♘](#chessboard-)
    - [Recycled Materials Used 🔄](#recycled-materials-used-)
- [💡 Electronic Design of the Project 💡](#-electronic-design-of-the-project-)
    - [Electronic Circuit Diagram 🔌](#electronic-circuit-diagram-)
    - [Components of the Electronic Circuit 🧩](#components-of-the-electronic-circuit-)
- [📲 Configuration and Execution of the Code 📲](#-configuration-and-execution-of-the-code-)
    - [Connect the Phone to the Computer with Iriun Webcam](#connect-the-phone-to-the-computer-with-iriun-webcam)
    - [Execute the Color Extraction Calibration Cell](#execute-the-color-extraction-calibration-cell)
    - [Load the Values into the Functions Cell](#load-the-values-into-the-functions-cell)
    - [Run the SERIAL PORT Cell](#run-the-serial-port-cell)
    - [Upload the Code to the Arduino Board](#upload-the-code-to-the-arduino-board)
- [🎮 Start the Game 🎮](#-start-the-game-)
    - [Considerations 📋](#considerations-)
- [🤖 Project in Operation 🤖](#-project-in-operation-)
- [♛ Future Proposals and Improvements ♛](#-future-proposals-and-improvements-)
- [📝 Acknowledgments 📝](#-acknowledgments-)
  
# Introduction 🔗

This project, titled **"MecaChess Robotic Arm,"** aims to create an anthropomorphic robotic arm with 4 degrees of freedom, designed to play chess autonomously. Additionally, it includes extra features that allow it to set up pieces at the start of a game, play through the Chess.com application, move via voice commands, and identify illegal moves, among others. To make it more accessible, affordable and recycled materials were used, achieving an optimal balance between cost and precision without compromising the arm's functionality. Finally, work continues on incorporating new features, such as implementing artificial intelligence and design improvements, among other aspects.

<h1 align="center">💻 Integrated Resources and Technologies 💻</h1>

# Software Used ♕

| Software                 | Description                                                                                         |
|--------------------------|-----------------------------------------------------------------------------------------------------|
| SolidWorks 2023          | SolidWorks 2023 was used for designing the elemental assembly, modeling various components, and utilizing its library of tools for screws, nuts, and other fastening elements. |
| Python                   | Python was used for developing the game logic, including piece detection, board management, and move mapping.   |
| Arduino IDE              | Arduino IDE was used to program the kinematics logic and the necessary functions to control the movements of the robotic arm. |
| Stockfish                | Stockfish was used as a chess engine for evaluating positions and generating optimal moves during games.         |
| Iriun Webcam             | Iriun Webcam was implemented to establish a connection between the mobile phone, used as a camera, and the Python programming environment, facilitating efficient control and management. |
| Wokwi                    | Wokwi is an online tool used to design and simulate electronic circuits. It allows the creation of interactive diagrams, making it easier to visualize the circuit and test the code before implementing it in hardware. |

# Python Libraries Used 📚

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


<h1 align="center">🔩 Mechanical Design and Kinematics 🔩</h1>

# Direct Kinematics ♖

Direct kinematics allows for the calculation of the position and orientation of the end effector of the chess robot based on the joint values. To achieve this, homogeneous transformations are systematically applied using the Denavit-Hartenberg method. This approach provides a standard framework for representing joint configurations and facilitates the obtaining of the end effector's coordinates in three-dimensional space. Understanding this process is fundamental for analyzing the robot's movement on the chessboard and is essential for designing trajectory control algorithms that optimize its performance in the game.

<p align="center">
  <img src="https://github.com/GuillermoDuarte888/MecaChess-Robotic-Arm/raw/main/Imagenes/Cinematica%20Directa%20Robot%204%20GDL.png" alt="Brazo Robótico" width="800"/>
</p>

The following program, developed in Python, allows for simulating various joint configurations that reach the same position of the robotic manipulator's end effector, thus showcasing the different available alternatives. In the image on the right, it can be observed that q3 has the "elbow up" configuration, which requires q2 to be positioned downwards, as its calculation depends on q3. On the other hand, in the image on the left, q3 presents the "elbow down" configuration, which means that q2 must be positioned upwards, according to the relationship mentioned between both angles. In this way, it can be seen how both configurations achieve the same position and orientation of the manipulator's end effector.


<p align="center">
  <img src="https://github.com/GuillermoDuarte888/MecaChess-Robotic-Arm/raw/main/Imagenes/Cinematica%20Directa%20simulacion.png" alt="Brazo Robótico" width="1100"/>
</p>


# Inverse Kinematics ♗

In the context of the chess robot, inverse kinematics is used to determine the joint angles required to reach a specific position and orientation, such as placing the end effector on a square of the board. Both geometric and analytical methods are implemented to verify the results, considering different configurations, such as elbow up and elbow down. This adjustment capability is essential to ensure precise and effective movement of the robot when making its moves. As a form of validation, it can be observed that the position and orientation provided by direct kinematics, when input into inverse kinematics, generate the same joint angles used in direct kinematics. This validates the accuracy of both methods and ensures that the robot can effectively reproduce the desired positions on the board.


<p align="center">
  <img src="https://github.com/GuillermoDuarte888/MecaChess-Robotic-Arm/raw/main/Imagenes/Cinematica%20Directa%20e%20Inversa.png" alt="Brazo Robótico" width="1100"/>
</p>

# Mechanical Design of the Robotic Arm 🎨

In this section, the mechanical design of the chess robot is presented, breaking down its various components. Each part of the robot is identified with a number in the image, which will facilitate its explanation. Below is a table detailing the functions and features of each piece.

<p align="center">
  <img src="https://github.com/GuillermoDuarte888/MecaChess-Robotic-Arm/raw/main/Imagenes/Piezas%20del%20Brazo%20Robot%20.png" alt="Brazo Robótico" width="1100"/>
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


# Representation of the Robotic Arm in SolidWorks 🔧
<p align="center">
  <img src="https://github.com/GuillermoDuarte888/MecaChess-Robotic-Arm/raw/main/Imagenes/Brazo%20Robot%20dise%C3%B1o%20completo.png" alt="Brazo Robótico" width="500"/>
</p>


# Design of the Pieces and the Box 📦

The chess pieces and the box were designed and redesigned multiple times to achieve optimal shapes. This iterative process allowed the pieces to adapt not only more effectively to the board but also to the robot's gripper, ensuring a secure and functional grasp.

The box was designed in SolidWorks, which facilitated the creation of a precise design tailored to the necessary dimensions. To increase the stability of the pieces, a nut was incorporated into the bottom of each one. This addition not only provides greater weight but also helps lower the center of gravity, which in turn improves the stability of the pieces during play.

This focus on design and stability reflects a commitment to the functionality and aesthetics of the project, ensuring that each component works in harmony.


# Chessboard ♘

The chessboard measures 18 x 18 cm and was handmade, painted on recycled wood. The classic black and white design was chosen, as this contrast allows for better piece detection during play. Additionally, a yellow circle was painted in each corner of the board to aid in board detection. This approach not only highlights the pieces but also provides a traditional aesthetic that is appreciated by players. The choice of recycled materials reflects a commitment to sustainability and creativity in design.


<p align="center">
  <img src="https://github.com/GuillermoDuarte888/MecaChess-Robotic-Arm/raw/main/Imagenes/Tablero.png" alt="Brazo Robótico" width="500"/>
</p>


# Recycled Materials Used 🔄 

In this project, a conscious effort was made to use recycled materials, contributing to sustainability and waste reduction. This approach not only saves resources but also demonstrates that it is not necessary to spend a lot of money when ingenuity and creativity prevail. Using recycled materials is not only a sustainable option but also opens the door to unique innovations in the design and construction of the project. Below are the materials used:

- **Recycled Wood:** Used to build the chessboard as well as the base that supports the entire system, offering a unique and rustic aesthetic.

- **Recycled Electronic Components:** Components from previous projects were incorporated, including wires and a perforated board that belonged to another project, among others.

- **Recycled Tripod:** The tripod holding the phone was made with various parts from different components, demonstrating the versatility of recycled materials.

- **Storage Box:** The box where all the electronic parts are stored was also made from recycled materials.

- **Button Structure:** The structure that houses the button was also made from parts of recycled elements.

- **Reuse of Components:** More components from previous projects were reused.


<h1 align="center">💡 Electronic Design of the Project 💡</h1>

In this section, the electronics used in the project are described. Wokwi was used to present the schematic in a more readable and understandable format for everyone. Wokwi is an online tool that allows for the simulation of electronic circuits, making it easier to visualize and understand the design.

# Electronic Circuit Diagram 🔌

<p align="center">
  <img src="https://github.com/GuillermoDuarte888/MecaChess-Robotic-Arm/raw/main/Imagenes/Circuito%20en%20wokwi.png" alt="Brazo Robótico" width="800"/>
</p>

# Components of the Electronic Circuit 🧩

- **Microcontroller:** Arduino Mega
  - 💻 Controls all the components of the circuit and manages the project's logic.

- **Servomotors:**
  - ⚙️ **5 MG996R Servos:** Used in the joints Qn; the pin outputs are 7, 8, 9, 10, and 11.
  - ⚙️ **1 SG90 Servo:** Used for the gripper, allowing it to open and close, output on pin 13.

- **Resistors:**
  - ⚡ **6 Resistors of 220 Ω:** Used to limit current in the circuit and protect the components.

- **LEDs:**
  - 🔴 **4 RGB LEDs:** Status indicators or visual signals, with pin outputs of 22, 26, and 30.
  - 🟢 **1 Green LED:** Functionality indicator, output on pin 3.

- **Button:**
  - ⚪ **1 4-Pin Button:** Allows user interaction and manual control of the circuit, output on pin 2.

- **Buzzer:**
  - 🔔 **1 Buzzer:** Emits sounds for alerts or signals, controlled via pin 34.

- **Laboratory Power Supply:**
  - 🔋 **Adjustable 5.5 V DC Power Supply:** Provides the necessary power for the circuit.

The circuit was implemented on a perforated copper board, as the circuit design is quite simple. This type of board allows for efficient and quick connections without the need for software design or a more complex printed circuit board (PCB). The simplicity of the wiring facilitates the construction and modification of the circuit as updates are made.

<h1 align="center">📲 Configuration and Execution of the Code 📲</h1>

In this section, we will explain how to compile the project's source code and load the necessary values in Python. The steps for using the appropriate development environment will be covered, ensuring that the code runs correctly. Additionally, details about parameter configuration and connection verification before starting the upload process will be included.

# Connect the Phone to the Computer with Iriun Webcam

1. **Installation:**
   - **Phone:** Download Iriun Webcam from the [Play Store](https://play.google.com/store/apps/details?id=com.iriun.wifi.cam).
   - **Computer:** Download and install Iriun from [its website](https://iriun.com).

2. **Connection:**
   - **Wi-Fi:** Make sure both devices are on the same network.
   - **USB:** Connect the phone via USB and enable "USB Debugging" in the phone's settings.

3. **Verification:** Check that the software on the computer displays the video feed from the phone.


# Execute the Color Extraction Calibration Cell

1. Go to the Python code and execute the first cell titled **🔷Color Extraction Calibration🔷**.
2. The camera will open. Position the camera so that it captures the board and pieces.
3. Click on the **yellow** color in the corners of the board; another window will open showing only the detected areas. Adjust both windows to your convenience and press **"v"** to confirm the color selection.
4. Repeat the process for the **blue** and **green** colors in that order.
5. After defining the three colors, press **"Esc"** to close the window. It will open again.
6. Select the **green** color; you will notice that it now detects both green and blue pieces. Press **"v"** to confirm and then **"Esc"**.
7. The values will be displayed below the code in the mentioned order.
8. Clarification: Adjust the colors as many times as necessary by clicking on each of them, keeping in mind that it will only take the values when you press "v".

# Load the Values into the Functions Cell

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

# Run the SERIAL PORT Cell

1. Execute the cell titled **🌸SERIAL PORT🌸**.
2. Load the port corresponding to which the Arduino is connected in the following format:

```python
# Configure the Serial Port
arduino_port = 'COM5'  # Change this to the correct port on your system
baud_rate = 9600       # Communication speed with Arduino
```
3. To verify the port, access the Arduino IDE and go to **Tools** > **Port**.

# Upload the Code to the Arduino Board

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
  <img src="https://github.com/GuillermoDuarte888/MecaChess-Robotic-Arm/raw/main/Imagenes/Interfaz.png" alt="Interfaz" width="800"/>
</p>

# Considerations 📋

It is essential that no actions are taken on the board unless it is the player's turn, along with other recommendations detailed below:

1. **Prevention of Mis-detection:** Avoid having the camera register unwanted movements that may interfere with the detection of the pieces and the board.
   
2. **Safety:** Minimize the risk of collisions between the robotic arm and players, which could cause damage to both the equipment and the individuals involved.

3. **Game Integrity:** Ensure that the flow of the game remains uninterrupted and that there is no confusion in the moves.

4. **Controlled Lighting:** It is crucial that the game takes place in an environment with controlled lighting. Avoid exposure to significant variations in light to ensure detection accuracy.

5. **Device Positioning:** The mobile device must be positioned above the robot's work area, adjusting the tripod height appropriately to ensure optimal viewing of the board and pieces.

<h1 align="center">🤖 Project in Operation 🤖</h1>

[Video link, demonstration of the robotic arm](https://www.youtube.com/watch?v=mJXuzqAW_us)

<p align="center">
  <img src="https://github.com/GuillermoDuarte888/MecaChess-Robotic-Arm/raw/main/Imagenes/brazo%20robot.gif" alt="Demostración" width="300"/>
</p>

<p align="center">
  <img src="https://github.com/GuillermoDuarte888/MecaChess-Robotic-Arm/raw/main/Imagenes/Robot%20Jugada.gif" alt="Demostración" width="300"/>
</p>

<h1 align="center">♛ Future Proposals and Improvements ♛</h1> 

1. **Enhanced User Interface:** Develop a more intuitive and visually appealing interface that facilitates user interaction during the game.

2. **Statistics Logging:** Implement a logging system that captures game statistics, such as moves made and playtime, for later analysis.

3. **Firmware Updates:** Provide periodic updates for the Arduino firmware to improve performance and fix bugs.

4. **AI Integration:** Integrate artificial intelligence so the system can interact verbally with players, offering feedback and suggestions during the game.


<h1 align="center">📝 Acknowledgments 📝</h1> 

I would like to express my sincere gratitude to several people and organizations that made this project possible:

**Gaston Alejandro Díaz:** I want to express my heartfelt thanks to my colleague for his unwavering support and valuable collaboration throughout our studies. Our joint growth and evolution have been essential to the success of this project, and his dedication has been a constant source of inspiration 🌟.

**Professor Engineer Cristian Leandro Lukaszewicz:** I am deeply grateful to Professor Lukasiewicz for supervising our Supervised Professional Practice (PPS) and for his valuable guidance and support throughout the process in the Mechatronics Engineering program. His commitment and professionalism have been an inspiration, setting an example to follow in the field of engineering and motivating me to achieve my academic and professional goals.

**Ezequiel Blanca and Juan Ignacio Szombach:** I extend my gratitude to both professors who also served as project supervisors, providing their recommendations, knowledge, and guidance for its completion.

**National University of Lomas de Zamora, Faculty of Engineering:** I sincerely thank the university for providing me access to a rich academic environment that has facilitated my development and allowed me to acquire valuable knowledge in my training as an engineer.

**To my professors and family:** I want to express my gratitude to all my professors and my family for their unconditional support throughout this process. Their encouragement and guidance have been fundamental to my personal growth and development.

**To all readers:** I hope you find this project interesting and useful.

