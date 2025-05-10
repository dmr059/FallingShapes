# Falling Shapes

An interactive game built with SFML in C++. Various colored shapes fall from the top of the window, and the player earns points by clicking on them before they reach the bottom.

## Game Concept

Shapes of different sizes and colors fall from the top of the screen.

Each color represents a different point value:

🔴 Red — 50 pts

🔵 Blue — 25 pts

🟣 Magenta — 15 pts

🟡 Yellow — 10 pts

🟢 Green — 5 pts

- Click on shapes to destroy them and gain points.

- Missed shapes reduce the player's health.

- The game ends when health reaches zero.

  ![FallingShapes](https://github.com/user-attachments/assets/51dfa2d7-e285-4f2d-afe4-6decad101855)


## Features

 - Basic Game Engine wrapper with a modular structure.

 - Mouse Input Handling to click and destroy enemies.

 - Dynamic Enemy Spawning with randomized size, color, and position.

 - UI Rendering with live updates for points and health.

 - Fixed Framerate for consistent performance.

## Requirements

- C++17 or higher

- SFML 2.5+

## Development Notes and Goals

This project really challenged me to think modularly while designing the Game class and structuring the event-handling system. I enjoyed experimenting with fonts for the UI and randomizing shape attributes like size and color.

One clear improvement I see is creating a separate Enemy class instead of handling all the shape logic inside Game.cpp. This would allow for greater flexibility, easier future expansion, and improved readability.

Next Steps: 

- Work with sound effects
- Introduce hit animation
- Incorpoate textures and more polished UI design

Feel free to fork, explore, and build on it! Happy coding!


