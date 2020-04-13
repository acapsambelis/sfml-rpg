# sfml-rpg
A top-down RPG demo built using SFML

When playing the demo, the player (a red square) moves around a world populated by wooden and iron boxes.
Movement is controlled by the standard WASD keys.  To break a block, the space bar is pressed.
In order to generate a new world, the user presses the backspace button.  To exit the game, press escape.

SFML-RPG was written using SFML and C++

World generation is random (except when loaded from a file).  Here are some example world generations.
![World1](/SFML-RPG/ScreenShots/NewGeneration.png)

![World2](/SFML-RPG/ScreenShots/NewWorld.png)

Blocks are broken when the space bar is pressed while colliding with them.
![BeforeBreak](/SFML-RPG/ScreenShots/ApproachingBox.png)
![AfterBreak](/SFML-RPG/ScreenShots/BoxBroken.png)
