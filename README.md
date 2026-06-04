# Yang & Object Rain Metin2

In this repo yang rain is an example but you can easily extend it to objects if you feel like it 

I am unsure if I took the best approach or not but I am open to feedback!

![Preview](./test_yang_rain.gif)

## How it works

What I did is just basically modify serverside lua so that accepts a custom range for our quest, our quest is just spawning the vnum 2 yang around us.
Client side the vnum 2 item has modified height that it falls from and speed from UserInterface/PythonItem.cpp  

## Adjustments

I left comments where what you can adjust, either the speed of the objects spawned, for how long and amount in the lua quest
And for the height and speed of the fall in client UserInterface/PythonItem.Cpp

## Additional Info

I did hardcode the vnum for this example and ofc for multiple items I could hardcode an item range but I feel like the best approach would be to create an item_type for it and then do not have hardcoded values.
For objects it might be better but I havent tested, in my head instead of just dupping every item perhaps just make a vnum that points at it.
Theres with blessing marbles for example if you /i 39004 you will get an item with the vnum 70024 in your inventory, so perhaps we can make the 39004 blessing marble fall out of sky and the 70024 can drop nicely.
I havent tested it but I am just imagining, I might be wrong. 

Needless to say you can adjust it for objects but unsure of the best approach.

## Contact

discord: shadowofthelove

## Licence (no one cares)

[![MIT License](https://img.shields.io/badge/License-MIT-green.svg)](https://choosealicense.com/licenses/mit/)
