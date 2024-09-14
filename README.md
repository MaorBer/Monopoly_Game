# Monopoly_Game



Explanation of Each Class in the Monopoly Project

Here’s an overview of each class and its role in the Monopoly project:

    Player
        Purpose: Represents a player in the game.
        Why We Need It: To store and manage each player's name, balance, properties, and game status (e.g., whether they are bankrupt or in jail). This class tracks the player's actions and manages their assets.

    Slot
        Purpose: Represents a square or slot on the Monopoly board.
        Why We Need It: The board consists of multiple slots, and each slot has its own rules (e.g., properties, taxes, utilities). The Slot class provides a base that other more specific slot types can inherit from.

    Property (inherits from Slot)
        Purpose: Represents a street or property on the board.
        Why We Need It: Properties can be bought, sold, and developed (houses, hotels). Players pay rent when they land on other players' properties. This class handles property-related actions like rent calculations and ownership changes.

    Utility (inherits from Slot)
        Purpose: Represents utility slots like the water and electric companies.
        Why We Need It: Utilities work differently from properties in terms of charging rent. This class is specifically for handling the rules related to utilities.

    TrainStation (inherits from Slot)
        Purpose: Represents train stations on the board.
        Why We Need It: Train stations have unique rules for calculating rent based on how many stations the owner possesses. This class manages those specific rules.

    Board
        Purpose: Represents the Monopoly board with all its slots.
        Why We Need It: The game requires a dynamic board that holds and manages all the slots, determines where players are located, and processes actions when players land on different slots. It also keeps track of available properties and other game-related actions that take place on the board.

    GameManager
        Purpose: Coordinates the entire game, handling turns, managing players, rolling dice, and checking game-over conditions.
        Why We Need It: It acts as the controller, ensuring the game runs smoothly, enforcing rules, and managing the interaction between players, the board, and the game mechanics.

    Dice
        Purpose: Simulates rolling two dice.
        Why We Need It: The game revolves around dice rolls to determine how far players move on the board. This class abstracts the dice logic, providing randomized rolls.

    Bank
        Purpose: Manages the overall money flow and property management not owned by players.
        Why We Need It: The bank holds unsold properties and handles the initial transactions when players buy properties. It also deals with bankrupt players and any properties that revert to the bank.

Each of these classes serves a distinct purpose in managing different aspects of the Monopoly game, following object-oriented principles to keep the code modular and manageable.