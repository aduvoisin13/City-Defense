# Game Design Document

## 'Things'
  1. City
    * Nonmoving.
    * Function: The city, located (and spanning) the bottom of the screen, is what the player is defending. If any enemy gets past the player's ship and the city takes damage, then the player will lose a life.
    * Visual: The city will look like a metropolitan city (high rise buildings and such), and will be very easily identifiable. It will span the bottom of the playing field.
  1. Fast Enemy
    * Moving.
    * Function: The fast enemy will start at the top of the screen and quickly make its way down to the city, in a straight line. In order to defeat this enemy, the player must react quickly before he reaches the city. The fast enemy is fragile; he dies in one shot.
    * Visual: The fast enemy will look like a small and dextrious alien. The enemy will look the part (in that it will be very obvious that he can move fast and die easily).
  1. Slow Enemy
    * Moving.
    * Function: The slow enemy will start at the top of the screen and slowly make its way down to the city, in a straight line. The slow enemy dies in 3-5 shots. In order to defeat this enemy, the player must spend valuable time to shoot him multiple times in order to kill him before he reaches the city.
    * Visual: The slow enemy will look like a fat and hunkering alien. The enemy will look the part (in that it will be very obvious that he moves slow and requires multiple shots to kill).
  1. Bouncing Enemy
    * Moving.
    * Function: The bouncing enemy will start at the top of the screen and make its way down to the city at a moderate speed while bouncing from side to side off of the edges of the screen. In order to defeat this enemy, the player must correctly time his shots to collide with the enemy at the right moment. The bouncing enemy dies in 1 shot.
    * Visual: The bouncing enemy will look like a moderately sized alien, likely with longer legs to indicate his bouncing ability. In addition, he will look the way he is moving, since he will be moving in a zigzag-like pattern to the bottom of the screen. The enemy will look the part (in that it will be very obvious that he moves in a bouncing pattern and requires one shot to kill).
  1. Blimp
    * Moving.
    * Function: The blimp offers the player a chance to score bonus points. The blimp simply flies across the top of the screen at random times, and if the player shoots the blimp, he will score a large amount of bonus points. If the player does not shoot the blimp, however, no penalty will be inflicted.
    * Visual: The blimp will look like a cartoony blimp. It will look its part (in that it's obvious that the blimp offers extra points, but does not damage the player if it's missed).

## Controls
  + Keyboard
    * Left and Right Arrows: Move your ship.
    * Space Bar: Shoot.

## Score
  + The score will increase upon hitting enemies. Sample Values:
    * Fast Enemy: 500 points
    * Bouncing Enemy: 500 points
    * Slow Enemy: 100 points (per shot)
  + The score will increase upon hitting the blimp. Sample Value:
    * Blimp: 1000 points
  + Combos: In order to more greatly increase the skill cap on the game, a combo system will be created. It works very simply:
    * The number of 'combos' you have acts as a multiplier for your score.
    * For each consecutive enemy or blimp hit, the combo multiplier will increase by 1.
    * The combo multiplier will reset when a life is lost or when a shot is fired that doesn't hit to an enemy/blimp (misses completely).
    * Example:
      - Your combo multiplier starts out at 0.
      - You shoot a fast enemy. Your combo multiplier becomes 1, and you gain 500 points.
      - You shoot a bouncing enemy. Your combo multiplier becomes 2, and you gain 1000 (500 * 2) points.
      - You shoot a blimp. Your combo multiplier becomes 3, and you gain 3000 (1000 * 3) points.
      - You shoot toward a slow enemy, but miss completely. Your combo multiplier resets to 0.
  + The score can never go down.

## Lives
  + The player will start out with 3 lives.
  + Whenever any kind of enemy gets past the player's ship and hits the city, the player will lose one life.
  + The game ends when the player's lives hit 0.
  + Note: Time permitting, the player will gain an extra life at specified intervals in scoring. For example:
    * Extra life at 100,000 points.
    * Extra life at 250,000 points.
    * Extra life at 500,000 points.
    * Extra life at 1,000,000 points.
    * etc.

## User Interface
![game_duvoisin](userinterface.JPG "User Interface")
The UI is simple and intuitive:
  + On the title screen, there will be three buttons: Start, Controls, and Quit.
    * Start: Starts the game.
    * Controls: Goes to the Controls Screen.
    * Quit: Quits the game.
  + The Controls Screen contains a description of the controls, along with a Back button that returns you to the Main Menu.
  + When the Start button is pressed, the user is prompted to enter his/her name. The game begins when the Start Game button is pressed.
  + Once the game has started, the user interface consists of two buttons: Pause (P) and Quit.
    * Pause (P): Pauses the game. Can also press P to pause.
    * Quit: Quits the game.
  + In addition, in the HUD for the game, vital information is displayed: User, Score, Combo, Level, and Lives.
    * Self-explainatory.
  + Once the user loses the game (as it will eventually speed up to the point where it is humanly impossible to continue playing), the Game Over screen will appear, and will display the player's name and final score along with two buttons: Main Menu and Quit.
    * Main Menu: Returns the user to the Main Menu.
    * Quit: Quits the game.
