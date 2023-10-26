# Mobile Robot
- Repository where the source code and documentation of the operation of the Mobile Robot developed at IFSC Campus Araranguá are located.

## Project Details
- Developed at the Federal Institute of Santa Catarina (IFSC) Campus Araranguá;
- Integrated Technical Course in Electromechanics;
- Integrative Project III discipline;
- Team: Emanuel Cardoso Tavecia ([@emanueltavecia](https://github.com/emanueltavecia)), Bernardo Fernandes Spillere and Gabriel Dutra dos Santos;
- Advisor: Werther Alexandre de Oliveira Serralheiro.

## Documentation

- This project uses the Arduino platform.

- You must enter a code on the serial monitor starting with a letter, which will be the function to be performed, followed by a number, which will correspond to the robot's wheels or its rotation angle. The function letter is case-insensitive.

- The letter corresponds to the function that will be performed by the robot. You have the following options:

  - v - velocity;
    - The number that makes up the code represents the robot's speed, with the minimum value being 1 and the maximum value being 5. Example:
      ```
      v3
      ```
    - In this example, the robot will be configured to rotate at speed 3.
    - Note: this code only defines the speed at which the robot will work. To make it move you must use one of the following options.

  - f - forward
    - The number that makes up the code represents the number of revolutions that the engine will move forward, example:
      ```
      f4
      ```
    - In this example the robot goes forward. The wheels rotate 4 revolutions.

  - b - backward
    - The number that makes up the code represents the number of revolutions that the motor will move backwards, example:
      ```
      b7
      ```
    - In this example the robot goes backwards. The wheels rotate 7 revolutions.

  - Not yet available:

    - r - rotate
      - The number that makes up the code represents the angle that the robot will rotate, example:
        ```
        r-50
        ```
      - In this example, the robot will rotate -50°, that is, 50° clockwise. If the number is positive, the robot will rotate counterclockwise.
      