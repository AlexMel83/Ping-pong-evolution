# Ping-pong-evolution

Developed with SFML library by Alexander Meleshko, fierst individual project for INTITA

PING-PONG
EVOLUTION
v. 1.0

done by Alexander Meleshko
(Group B22.Red, Vinnytsia IT Academy)

Task obtained: 22.12.2022
Pre-defense: 15.01.2023, Teacher1 Yaroslav Plaksiy
Defense: 11.02.2023, Teacher2 Alexander Panchenko

1. System requirements.

Operating system: DOS or Windows.
Hardware requirements: user (programmer) requires
- processor: Pentium Processor or higher;
- RAM: 14 Mb (min);
- Hard Disc: 491 Kb (min).

And for version PingPongEvolutionAL (openal32.dll required)
- RAM: 25.6 Mb (min);
- Hard Disc: 1530 Kb (min);
- openal32.dll

2. About the game Ping-pong Evolution (typical rules).

2.1. Typical rules of game Ping-pong and basic information.
Ping-pong is an Olympic sport, a ball sport that uses special paddles and a game table delimited by a net in half.
The game can be played between two opponents. The task of the players is to keep the ball in play with the help of paddles - each player, after one bounce of the ball in his half of the table, must send the ball to the opponent's half of the table. 
A point is awarded to a player when an opponent fails to recover the ball in accordance with the rules. 
Each game continues up to 11 points, the match consists of an odd number of games, and is played for the most wins in the games.

2.2. Problem statement.
It is required to develop a computer game ping-pong. The playing field consists of two movable rectangles (platforms, rackets), one of which is controlled by the player, the other by the opponent, the ball, the game menu, and the field markings. A ball moving along the playing field can bounce off the boundaries of the field and off the paddles.
The game lasts until one of the players gets 3 points by default, or up to 11 points if set accordingly in the game settings.

2.3. Definition of the main functions of the task.
The main functions of the task of game "ping-pong" are not only to make the user's leisure time entertaining but also to develop a reaction and the ability to think quickly.
You also need to implement the pause and exit options in the task. Thanks to it, the user will be able to stop or exit the game. When you first start the game, it will be useful to have information about the control of the game and the ability to turn off these tips in the future. Color design, animation, and sound will give the game additional value and attractiveness for users.

2.4. Requirements for the initial data.
The initial data for this program are the number of points in the match entered at the beginning of the game up to eleven points or three points by default.
The control is carried out with the following keys:

1 – yellow player:
"W" – move platform up
"S" – move platform down
"ESC" – (paused) platform stop

2 – blue player:
"UP" – moving platform up
"DOWN" – move platform down
"ESC" – (paused) platform stop
The game lasts until one of the players receives the number of points for missing the balls set in the settings or by default three points.

3. User guide.

3.1. Main program functions and their implementation.
The main functions of the program are:
1)	implementation of the user interface, in particular, the program menu description of the subject area in the key of object-oriented programming;
2)	implementation of the procedure for quickly drawing an object (ball);
3)	implementation of the adversary platform control algorithm;
4)	implementation of the mechanism of the ball's behavior when colliding with obstacles.

3.2. Interface Features.
The user interface is the first thing a user encounters when starting a program. The user's first impression of any program is formed in the first moments of working with it. And here, user interface friendliness is extremely important. The concept of a friendly user interface includes the whole set of convenience, informativeness, and intuitiveness uses of the program. A user-friendly interface indicates a good level of the develops. The presence of a user-friendly interface speeds up the work with the program and reduces the time for training staff to work with it.
Informative presentation of information is vital in many applications such as process control in critical manufacturing areas. Depending on how quickly the operator sees the output of any value outside the specified limits, the faster he reacts to this exceptional situation, the less the consequences will have cost. In addition, his reaction to such a situation, again, should use some of the process controls that are in front of him.
Even if we do not take such important areas of application of computer technology, the role of the user interface cannot be underestimated. Imagine a program that millions of people around the world use every day, such as the Word text editor. Take, for example, a search operation. If we imagine that such an operation in the new version will save one-tenth of a second when working, and one person will resort to such an operation at least once an hour, then for a working day (8 hours), a million people will save 222 hours of working time! And because of what the difference in 0.1 seconds can turn out? Yes, almost because of not what - a different position of the buttons, for example.
Thus, the importance of the user interface should by no means be underestimated. 

3.3. instructions for the application.

a.	Find and run the file PingPongEvolution.exe in the folder PingPongEvolution.

b.	Read information about the program`s name and author and press «start game» to begin or «setting» for a set number of points in the match, or «exit» to close the program.

c.	If you press the «start game» button, the game control information will be displayed and you will need to press the «back» button to return to the previous menu, or «start game» to begin the game in a default three-point match. Each button press is accompanied by a sound effect.

d.	If you press «start game», the game will begin with two paddles controlled by the «W» and «S» keys for the yellow player and the «up» and «down» keys for the blue player. When one of the players misses the ball, one point is awarded to his opponent.

e.	If the «ESC» key is pressed, the game will be paused with an appropriate message and a prompt to press three buttons, «continue» to return to the current match, «start again» to restart the game, and «return to menu» to back to the main screen. Each hit of the ball into the wall or racket, as well as the loss of the ball, is accompanied by a sound effect.

f.	If one of the players reaches three (default) points, the match will end and the winner will be displayed on the screen: «yellow wins» or «blue wins» in message-appropriate color. And it will prompt two buttons to «start again» to repeat the match and «return to menu» to back to the main screen. An executable with openal32.dll dependencies will play the corresponding sound.

g.	When you press «return to menu» and back to the main screen and press «settings», the screen will display information about the number of points in the match, which can be changed by pressing the «+» or «-» button in the range from 3 to 11 points.

h.	Interactive objects for «disable hints» will also be offered, when you click on an empty or filled checkbox, the status will be changed to show instructions before starting the game or not, and you will be prompted to press the button «back» to return to the main screen.

i.	If you fill in the checkbox «disable hints» then after pressing the «start game» button on the main screen, the game will begin immediately without displaying information about the game control.

4. Programmer instruction.

4.1. Description of the problem solution algorithm.
To solve the problem, it is necessary to develop several objects and implement their methods.
An ancestor base object is a static object. A static object is characterized by the x, and y coordinates of the object's location in the window. A dynamic object inherits from a static one. Additional characteristics of a dynamic object are the screen coordinates to which it was last drawn, as well as a pointer to the bitmap of the object's screen image (pixels).
The main objects of the program are: a field with borders, a ball, and knockout rectangles (paddles).
A rectangle is an object that inherits all the properties of a static object. Additional characteristics of this object are the width and height of the rectangle.
A ball is an object that inherits all the properties of a dynamic object. Additional parameters are the displacement values along both coordinate axes for one game cycle and the radius of the ball.
All objects contain a Draw procedure that draws an image of the object on the screen. In this case, dynamic objects are drawn by first erasing the objects with the window clearing function, and then copying their image to a new position on the screen in the usual way.
In the loop interrogates the keyboard and if any control button is pressed, the speed and direction of movement of the player's platform are updated. Also, the hit of the ball into all obstacles is analyzed. When hit, a new direction of ball movement is calculated along both coordinate axes. If necessary, the direction of movement along each of the axes is changed by changing the sign of the value kx or ky of the ball to the opposite one. After one step of the game, the current state of objects is checked. If the ball flew out of the playing field, then the number of missed balls of the player in whose direction the ball flew away increases. The fact that the game is over is also checked. The game is considered over if one of the players has the maximum number of goals conceded, or the user has abandoned the game and pressed the key ESC.

4.2. Testing the main task functions.
Testing of the program was carried out by the method of practical enumeration of game situations. The main task of testing is to identify deviations from the reference values.
Main tasks of testing:
Detection of errors in the program;
Diagnosis and localization of the causes of the error;
Control check.

4.3. rationale for the choice of programming language.
The project was written in C++.
Advantages of C++: 
1)	Portability – C++ is one of the most used and portable to different platforms, almost any type of computer and operating system;
2)	Brevity – code written in C++ is very short in comparison with other languages.
3)	Modular programming – applications written in C++ can be made up of several source code files which are compiled separately and then linked together. This characteristic allows the linking of C++ code with the one written in other languages (for example, Assembler).
4)	Speed – the resulting code from a C++ compilation is very efficient due to the reduced size of the language itself.
5)	The project is a single CPP unit that contains all necessary algorithms and functions as well as files connected to it with the necessary resources for textures, sounds, and icons.
Find and open the file main.cpp in the folder PingPongEvolution. For editing, debugging, and compiling program code you may use C++ compilers such as MS Visual Studio, Visual C++, C++ Builder, Borland C++, Dev C++, and similar After setting up the necessary dependencies with the SFML libraries https://www.sfml-dev.org/.

4.4. Used procedures, functions and variables.
Main global arrays:
Textures bit file In texture1.h: unsigned char ball[], player[], nazva[], butplay[],  nastroy[], exitb[], KO[], cifr[], bsc[], gal[], npok[], back[], UI[], nazvapause[], uprav[], nac[], win[], winbut[], pau[], cont[], iconicon[].
Sound bit file in sound1.h: unsigned char ballsound[], ballwallsound[], buttonsound[], goalsound[], winsound[].
Main global variables in recource.h:
IDI_ICON1 – main icon executable, IDR_WAVE1, IDR_WAVE2, IDR_WAVE3 – sound for play without openal32.dll dependencies.
Main variables:
Color Dark_Green, Light_Green – define basic color field;
Int screen_width, screen_height – define dimensions window;
Int kx, ky - ball speed coefficients;
Int c – number of points in match;
Bool menu, setting, pok, game, animation, play, stop, pause – bool status menus and game;
RenderWindow window – object window;
Rectagleshape line – line that separated field on two halves;
Circleshape circle – circle in center field;
Image icon – small icon in up-left cutter executable and taskbar;
Texture t1-20 – texture buffers;
Soundbuffer balbuf, wallbuf, buttonbuf, goalbuf, winbuf – soundbuffer for load sound files;
Sound soundball, soundbutton, soundwall, soundgoal, soundwin – sound for plays after determined events;
Sprite player, ball, naz, butplay, nastroy, exit, KO, cifr, bsc, gal, npok, back, UI, nazpause, uprav, nac, score, win, winbut, pau, con, pbut – objects that included figures and textures in determined positions;
Event event – object determined events and conditions;
Vector2i pos – positions click mouse;
Vector2f b – positions movements of ball;
Vector2f p[2] – positions movements of paddles of players;
Main functions:
sf::VideoMode::VideoMode() – determined dimension window;
sf::Vector2f() – start position of line;
sf::Transformable::setPosition() – set properties object position;
void sf::Shape::setFillColor() – fill color of object;
bool sf::Image::loadFromMemory() – load file from bit array in header file;
void sf::Window::setIcon() – change the window`s icon;
void sf::Sprite::setTexture() – determined textures in sprite;
void sf::Transformable::setScale() – specifies scale of sprite;
void sf::Sprite::setTextureRect – read part of textures;
bool sf::Window::isOpen() – return true is window open;
bool sf::Window::polEvent() – return true if conditions performed;
void sf::Window::close() – close the window and destroy all attached resources;
static sf::Vector2i sf::Mouse::getPosition() – get current position of the mouse;
virtual void sf::Sound::play() – start or resume playing the sound;
void sf::Transformable::move() – move of the object;
sf::FloatRect::sf Sprite::getGlobalBounds() – get the global bounding rectangle of the entity;
static bool sf::Keyboard::isKeyPressed() – check if a key is pressed;
void sf::RenderTarget::clear() – clear the entire target with a single color;
void sf::RenderTarget::drav() – draw a drawable object to the render target;
virtual sf::SoundSource::Status sf::Sound::getStatus() – get current status sound;
void sf::Window::display() – display on screen what has been rendered to the window so far.

5. About author
This project was done by Alexander Meleshko – Vinnytsia IT-Academy student (group B22.Red, January 2023).
