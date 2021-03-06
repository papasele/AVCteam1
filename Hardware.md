#Hardware Information Log

###Part Sizes:
|Part        | Length *(mm)*| Width *(mm)*| Heigth *(mm)*|
|------------| ------------| -------------| -------------|
|Power Board |118          |64            |
|RPi         |85           |56            |17            |
|Camera      |25           |25            |
|I.R         |20           |45            |
|**Wheel Size**    | **Diameter _(mm)_**  |
|Small       |30          |
|Medium      |60          |
|Large       |90          |


#####Week 1. Plan 
The plan for hardware is get the bot to be set up to be functional to be able to access all ports without having to remove parts. Also to be small enough to be able to move through the maze with ease. 


#####Week 2. Decisions 
We have assembled the bot in to a basic small frame that fits everything above the two motor wheels, with a free moving back wheel. The power board and raspberry pi are mounted above one another in a two tier layout. We believe this to best functional layout with access to all inputs, as well as space for the battery. The Camera is mounted to the chassis with a two hinge arm that holds it out at any required angle. We have used the medium size wheels (60mm) which we believe to be the best size for the bot.


#####Week 3. Testing
While testing the bot we discovered that the bot was a little unstable, the battery was not holding its place and the camera mount was moving around. This caused us to switch down to the smaller wheels bringing the centre of gravity down. We took the arm off the camera mount and then creating a new mount with the parts from the old one. Then attaching the camera directly to the chassis point directly towards the ground to read the line. Using one of the hinges from the camera mount and some other supports we managed to get a battery support/brace. 


#####Week 4. First quadrant. 
First time using the alterations from week 3, we found out that the camera needed to be on a slight angle or elevated higher *(was unable to see the line and enough area on both sides)*. Using parts that we had we got the camera on to a single hinge mount and got it into a stable position. The bot successfully went through the first quadrant! 
We are now looking at getting mounts for the three I.R sensors that will get the bot through the maze. 

######I.R Sensor Placement
* Two sensors will be angled with brackets either attached to the supports for the board or built into the supports for the board
* A third will be mounted facing forward on the front centre
  * This creates slight issues with the camera mount, *current thought is to put a bracket bellow the camera*
 
######Other Possible 3D Printing _not yet required_
- [x] Block for motor mount to make the robot flat
- [x] Bracket to raise camera height that is fixed *(not hinged)*

*In the end all parts being 3D printed. This included the braces for the Rpi and power board to be mounted on. The front braces also had mounts for two of the angeled front I.R sensors. Also printed off a Camera holder with a I.R front mount below it facing forward. We ended up also printing out a base cassis that had the correct thinkness for the motors to be mounted flat. As well as space for the wires to be hidden. 
###3D printed Part Sizes:
|Part        | Width *(mm)*| Height *(mm)*| Length*(mm)*
|------------| ------------| -------------| -------------|  *IR mounts attached to the front bracing and Camera mount. 
|Bracing     |2            |70            |10
|Base        |55           |10            |135
|I.R mount*  |2            |50            |10
|Camera Mount|25           |2             |32

!! Also see photo with visual measurements. 
![Visual Measurements](https://github.com/papasele/AVCteam1/blob/master/Bot.Sizing.Image..jpg)


All Parts attached using a mix of 2mm screws and nuts varing in length from 4mm - 16mm. (maybe some hot glue aswell)  
- Motors and bracing attached to the Chassis using 2mm by 16mm screw and nut. 
- Raspberry Pi, Camera and IR sensors attached to bracing using 2mm by 4mm screw. 
- Power board and Camera mount attached to bracing uing 2mm by 8mm screw and nut.
- There were two pieces of plastic hot glued to the bottom to hold wires in place. 

