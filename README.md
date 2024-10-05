
# Monopoly Game in C++

## Overview

This project is a C++ implementation of the classic board game Monopoly, designed to run on a console and utilize the Qt framework for a graphical user interface (GUI). It supports 2 to 8 players and includes functionalities such as rolling dice, buying properties, and handling player interactions.
Final Project in System Programming 2 course in Ariel University.

## Features

- **Multiple Players:** Supports 2 to 8 players.
- **Dice Rolling:** Players can roll two dice to determine their movement on the board.
- **Property Management:** Players can buy, sell, and build houses on properties.
- **Bankruptcy Management:** Handles player bankruptcy and game over conditions.
- **Graphical Interface:** Uses Qt for a visually appealing interface.
- **Game Logic:** Implements Monopoly rules for property ownership, rent payments, and player movement.

## Project Structure

```
/Monopoly_Game 
│
├── /hppFiles               # Header files for the classes
│   ├── GameBoard.hpp       # Defines the GameBoard class and its functionalities
│   ├── GameManager.hpp     # Defines the GameManager class, handling the game flow
│   ├── Player.hpp          # Defines the Player class, including properties and methods
│   ├── Slot.hpp            # Abstract class for game slots (properties)
│   ├── SpecialSlot.hpp     # Defines special slots (like taxes)
│   ├── Street.hpp          # Defines street properties
│   ├── Train.hpp           # Defines train properties
│   └── Utility.hpp         # Defines utility properties
│
├── /src                    # Source files for the implementation
│   ├── GameBoard.cpp       # Implementation of GameBoard methods
│   ├── GameManager.cpp     # Implementation of GameManager methods
│   ├── Player.cpp          # Implementation of Player methods
│   ├── SpecialSlot.cpp     # Implementation of special slot actions
│   ├── Street.cpp          # Implementation of street actions
│   ├── Train.cpp           # Implementation of train actions
│   └── Utility.cpp         # Implementation of utility actions
│
├── /resources              # Resource files (images, icons, etc.)
│   └── Monopolyboardimg.jpg # Image file for the Monopoly board
│
├── main.cpp                # Main entry point of the application
├── mainwindow.cpp          # Implementation of the MainWindow class
├── mainwindow.h            # Header for the MainWindow class
├── MonopolyGame.pro        # Qt project file for building the application
└── README.md               # This README file
```

## Class Descriptions

### GameBoard

- **Responsibilities:**
  - Manages the board layout, including a collection of slots.
  - Initializes the game board with predefined properties.
  - Handles player movements across the board and manages interactions with slots.

### GameManager

- **Responsibilities:**
  - Controls the flow of the game, managing player turns and the overall game state.
  - Adds players to the game and tracks their statuses.
  - Checks for game over conditions and handles bankruptcy.
  - Delegates actions like rolling dice and moving players to the appropriate classes.

### Player

- **Responsibilities:**
  - Represents each player in the game, including their name, money, position, and owned properties.
  - Handles player actions, such as rolling dice, moving, buying properties, paying rent, and managing bankruptcy.
  - Provides methods for interacting with the game state, such as checking if the player is bankrupt or owns both utilities.

### Slot (Abstract Class)

- **Responsibilities:**
  - Serves as a base class for different types of properties on the board (e.g., streets, utilities, trains).
  - Contains common attributes like name, price, and owner.
  - Declares a pure virtual method for the action that occurs when a player lands on the slot, to be implemented by derived classes.

### SpecialSlot

- **Responsibilities:**
  - Inherits from the Slot class and represents special slots, such as taxes or chance cards.
  - Implements the action method to handle the specific interactions when a player lands on a special slot.

### Street

- **Responsibilities:**
  - Inherits from the Slot class and represents street properties on the board.
  - Contains details about the street, such as rent, house prices, and the color group.
  - Implements the action method for buying, renting, and building houses on the street.

### Train

- **Responsibilities:**
  - Inherits from the Slot class and represents train properties.
  - Manages the rent calculations based on the number of trains owned by the player.
  - Implements the action method for handling interactions when a player lands on a train.

### Utility

- **Responsibilities:**
  - Inherits from the Slot class and represents utility properties (e.g., electric company, water company).
  - Implements the action method for handling utility interactions, including rent payments based on dice rolls.

## Installation

### Prerequisites

- **C++ Compiler:** Ensure you have a C++ compiler installed (e.g., g++, clang).
- **Qt Framework:** Download and install Qt (version 5 or later). Make sure to include Qt Creator for an easy development experience.

### Building the Project

1. **Clone the Repository:**
   ```bash
   git clone https://github.com/MaorBer/Monopoly_Game
   cd Monopoly_Game
   ```

2. **Open the Project:** Open the MonopolyGame.pro file in Qt Creator.

3. **Build the Project:** Click on the build button in Qt Creator or run the following command:
   ```bash
   qmake && make
   ```

4. **Run the Application:** After building, run the executable produced in the bin directory.

## Gameplay Instructions

1. **Start the Game:** Launch the application and add players by entering their names.
2. **Roll the Dice:** Click the "Roll Dice" button to roll the dice and move your player accordingly.
3. **Buy Properties:** If you land on a property, you can choose to buy it if it's available.
4. **End Your Turn:** Click the "End Turn" button to pass the turn to the next player.
5. **Game Over:** The game continues until only one player remains or a predefined condition is met.


