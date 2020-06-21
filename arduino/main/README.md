# swemu plus plus

This is a controller emulator anchored on [FluffyMadness' Fight Stick project](https://github.com/fluffymadness/ATMega32U4-Switch-Fightstick) and [Palatis' Arduino LUFA](https://github.com/Palatis/Arduino-Lufa). This particular repository is home to scripts that deal with Pokemon Sword and Shield. This is only compatible with ATMega32U4 based boards and compatibility is not planned.  

The benefits of this project over the other sword/shield projects you can find online

1. Programmed in C++
1. Programmed in the Arduino IDE (easier compatibility with arduino peripherals)
1. Better memory management (all scripts can fit onto a single board vs one script per program)
1. Better/more sensible looping - scripts are easier to understand, write, and loop since switch statements are not used


| Script  | Status |
| ------------- | ------------- |
| 2560 egg Step hatching  | Complete  | 
| 3840 egg Step hatching  | Complete  | 
| 5120 egg Step hatching  | Complete  | 
| 6400 egg Step hatching  | Complete  |
| 7680 egg Step hatching  | Complete  |
| 8960 egg Step hatching  | Complete  |
| 10240 egg step hatching  | Complete  |
| Egg collecting | Planned |
| Box hatching | Planned |
| Box release | Complete |
| Digger brothers | Complete |
| Watt farming | Complete |
| Fossil revive  | Complete |
| Berry farming | Complete |
| Stow on side bargain farming | Complete |
| Lotto farming | Complete |
| EV training | Complete |
| Poke job farming | Complete/untested |
| Champions cup farming | Complete/not fully tested |

## Flashing instructions

If you're just looking to use the code, it's all available in the form of hex files. Flashing those is probably a bit easier and less painful than installing Arduino LUFA. 

You can download the hex files [here](https://github.com/ironandstee1/pkmn-hexes/tree/master/swemu-plus-plus). You'll probably need to clone the repository to get them, but the one's you want are located in the swemu-plus-plus folder. 

[Here](https://www.youtube.com/watch?v=TzfHGD3JPSo) is a video on how to flash these hex files to your device. 

[Here](https://www.youtube.com/watch?v=ymstv13uoAo) is a video on how to set up in game. 

## Building Instructions

This is for people who are looking to develop further or use this code themselves. 

- Download Arduino IDE (I used 1.8.2, other versions should work)
- Download Arduino LUFA from https://github.com/Palatis/Arduino-Lufa and follow the instructions on its repository to set it up. Note: these are not easy and it'll take some time to get this ready to go
- Upload this program to the Arduino. Every time you want to change the program you'll have to flash the original firmware first. [Here's a video on it](https://www.youtube.com/watch?v=JZtzIyXm98Q). 

## Scripting instructions

If you want to create your own scripts, I've included a function called ```simpleScript``` in the main.ino file. Simply make the ```simpleScript();``` the only function call in main and write a script such as

```  
Left(1000);
Nothing(1000);
Right(1000);
Nothing(1000);
Up(1000);
Nothing(1000);
X(1000);
Nothing(1000);
Y(1000);
Nothing(1000);
A(1000);
Nothing(1000);
B(1000);
Nothing(1000);
```

to execute it! This example is aleady provided in the source code. 

If you would like to see the available functions or configure the wait time after every function, check out the SimpleScripting.h header. You can also create classes and functions as I did if that's your preference. 

## In-game setup instructions

### Egg Hatching

1. Make sure you have the oval charm and a pokemon with magma body in the sixth slot of your party
1. Fly to route 5 where the nursery is
1. Make sure the nursery lady has the pokemon you want and an egg ready
1. Get on our bike and go slightly to the left of the daycare lady (about where the fence is) but still facing upward
1. Unplug your controller and plug in your board

The egg hatching script is robust enough that it will not fail if the nursery lady does not have an egg. It will have some different behaviors to cover for the situations where this doesn't happen that may look weird, but it will get back on track. 

### Watt farming

1. Set your date to a a few days before 1/1/2000 (which day doesn't matter)
1. Find a wishing well with no pokemon near it and put a wishing piece into it
1. Turn on online and go to Link Battles
1. As soon as you've found a partner, press the home button and turn your device on airplane mode (un dock if necessary)
1. Turn airplane mode back off and go into your game and return to being in front of the well
1. Change your date forward a day and ensure that watts appear in the fountain 
1. Change your date to 1/1/2000 and collect the watts
1. Close the raid menu and stand directly in front of it
1. Unplug your controller and plug in your board

### Box release

1. Fill up the number of boxes you've specified in the code with the pokemon you want released
1. Put the cursor over the first pokemon in the first box you've released
1. Unplug your controller and plug in your board

### Digger brothers

1. Stand in front of the digger brothers
1. Unplug your controller and plug in your board

### Fossil revive

1. Go to the fossil lady with enough fossils in your bag for the number you specified in the program
1. Save before you plug in assuming you are shiny hunting
1. Plug in your board

### Berry farming

1. Perform date/time exploit listed in watt farming steps 3-6
1. Stand in front of a berry tree
1. Plug in your board

### Lotto farming

1. Perform date/time exploit listed in watt farming steps 3-6
1. Stand in front of a PC
1. Plug in your board

### EV training

1. Perform date/time exploit listed in watt farming steps 3-6
1. Put the pokemon you want to be trained in the first box of the PC in a 2x5 grid from the top left
1. Stand in front of a PC
1. Change the date forward once and return to the game
1. Plug in your board

### Poke job exp training

1. Perform date/time exploit listed in watt farming steps 3-6
1. Put the pokemon you want to be trained in the first box of the PC in a 2x4 grid from the top left
1. Stand in front of a PC
1. Change the date forward once and return to the game
1. Plug in your board

### Champions cup farming

1. Get a team of 3 or so pokemon that will mostly one hit your champions cup opponents. I use a maxed out ev dracovish, eternatus, etc. The first move on every pokemon must be a really strong one (fishous rend, etc)
1. Stand in front of the champions cup desk but just a little bit away
1. Plug in your board

## Progress

All desired features complete. I'm just adding extra scripts whenever I feel like it at this point. 

## Future work (in order)

- Figure out battle tower scripting if possible
- Hammer out training via pokemon jobs
- Automate raiding 

## How can you help?

- Fork this for yourself and do something cool with it
- Hit me up with ideas on twitter @ironandstee1
- Send me the IDs of some broken battle tower teams (attack heavy/no setup required please)

If you have a suggested feature it'd be best to open an issue or dm me on twitter. 

### Credits

fluffymadness, this is a fork of his repo after all

fluffymadness also thanked:

Special thanks to shinyquagsire's and progmem's reverseengineering work for the pokken tournament controller. (https://github.com/progmem/Switch-Fightstick)

Dean Camera for the LUFA Library

zlittell, msf-xinput was very helpful for starting.


