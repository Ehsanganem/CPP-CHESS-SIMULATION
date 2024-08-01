# chess-simulation-c-
ChessApp is a fully-featured console-based chess game implemented in C++. This project demonstrates core concepts of object-oriented programming, including inheritance, polymorphism, and encapsulation. The application supports standard chess rules, including move validation, check, checkmate detection, and castling.

Key Features
Basic Game Setup:

Initialization of the chessboard with pieces placed in their standard starting positions.
ASCII art representation of the chessboard for a simple, text-based graphical interface.
Game Flow Management:

Implementation of turn-based mechanics, allowing two players to alternate moves.
Input handling for players to enter their moves using standard chess notation (e.g., e2e4).
Piece Movement:

Basic movement logic for all pieces, ensuring they move according to standard chess rules.
Prevention of illegal moves such as moving through other pieces (except for the knight), moving into check, and other invalid actions.
Validation and Feedback:

Display messages indicating invalid moves and the reasons for them (e.g., moving a piece that doesn't belong to the player, trying to move to an occupied square by their own piece).
Basic error handling and prompts to guide players in case of incorrect inputs.
Simple User Interface:

Text-based UI to display the board, current player's turn, and relevant messages (e.g., check status, illegal moves).
Clear prompts for player input and instructions for quitting the game.
Implementation Details
Classes and Architecture: The codebase consists of key classes such as Chess for managing the game flow and user interface, and ChessBoard for representing the state of the game and executing moves.
Data Structures: Usage of a 2D array to represent the board and store pieces, with additional classes for each piece type to encapsulate movement logic and piece-specific rules.
Constraints and Assumptions: The implementation assumes a standard 8x8 chessboard and does not yet handle advanced rules like castling, en passant, or pawn promotion.
Usage Instructions
Running the Game: Compile and execute the game to start a new chess match. Players input their moves in turn, using chess notation.
Exiting: Players can type exit or quit to end the session at any time.
