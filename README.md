# Falling Shapes

This is an interactive game built with SFML in C++. In this game, various colored shapes fall from the top of the window, and the player earns points by clicking on them before they reach the bottom.

# Game Concept

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


# Features

 - Basic Game Engine wrapper with a modular structure.

 - Mouse Input Handling to click and destroy enemies.

 - Dynamic Enemy Spawning with randomized size, color, and position.

 - UI Rendering with live updates for points and health.

 - Fixed Framerate for consistent performance.

# Requirements

- C++17 or higher

- SFML 2.5+


