# Pong Game

A classic Pong game implementation using C++ and the Raylib library.

## Description

This is a simple implementation of the classic arcade game Pong. The player controls the left paddle and competes against a CPU-controlled right paddle. The objective is to hit the ball with your paddle and prevent it from passing your side, while trying to make the ball pass the CPU's paddle.

## Features

- Player vs CPU gameplay
- Score tracking
- Paddle collision detection
- Ball physics with speed and direction changes
- Clean, responsive controls
- Visually distinct game elements

## Controls

- **W key**: Move the left paddle up
- **S key**: Move the left paddle down
- **ESC key**: Exit the game

## Implementation Details

The game is structured using object-oriented programming principles with the following main classes:
- `Ball`: Handles the ball's movement, collision detection, and rendering
- `Paddle`: Base class for paddles with position, movement, and rendering functionality
- `CPUPaddle`: Derived from Paddle, implements AI behavior to follow the ball

## Areas for Improvement 

### AI Enhancements
- Implement varying difficulty levels for the CPU opponent
- Create more sophisticated AI that can predict ball trajectory
- Add slight reaction delay to CPU movements for more balanced gameplay
- Implement adaptive AI that adjusts to player skill level

### Game Features
- Add a proper menu system (main menu, options, pause screen)
- Implement a win condition (first to reach a certain score)
- Create game reset functionality without needing to restart the program
- Add round transitions and match structures (best of 3/5/7)

### Gameplay Improvements
- Add sound effects for ball hits, scoring, and background music
- Implement visual polish (animations, particles, dynamic lighting)
- Add power-ups that modify ball speed, paddle size, or other game elements
- Include visual countdown before each round starts

### Technical Enhancements
- Add multiplayer functionality for local or network play
- Create a settings menu to adjust game parameters (ball speed, paddle size, etc.)
- Add a high score system with persistent storage

## Dependencies

This game uses the [Raylib library](https://www.raylib.com/index.html), a simple and easy-to-use library to enjoy videogames programming.

## Building and Running

1. Ensure you have Raylib installed on your system
2. Compile the main.cpp file with your C++ compiler
3. Run the executable

Example (using g++):
```
g++ -o pong main.cpp -lraylib
./pong
```

## Acknowledgments

This project was created with reference to the tutorial video by [VeryHotShark](https://www.youtube.com/watch?v=VLJlTaFvHo4&list=PLwR6ZGPvjVOTIMqUXnqyWaIfQg0xdHNZn), which provided valuable insights into game development with Raylib.
