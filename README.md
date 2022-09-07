# DayZ-SA
Code for init.c used in the game DayZ for StandAlone servers


/* Welcome to Project3W Career DayZ Mod */
/* Author: Supernova					*/

1. Copy the careerDayZ.chernarusplus folder and drop it into your \mpmission\ folder on your server
2. Edit your serverDZ.cfg file and change your "template="dayzOffline.chernarusplus";" line to the new folder name eg. template="careerDayZ.chernarusplus";
3. run your server and enjoy Career DayZ!!!

Or if you don't want to change your serverDZ.cfg file:

1. Make a backup of your init.c file located in either \mpmission\dayzOffline.chernarusplus or \mpmission\dayzOffline.enoch
2. Copy the init.c file in the mod to the \mpmission\dayzOffline.chernarusplus or \mpmission\dayzOffline.enoch folder
3. run your server and enjoy Career DayZ!!!

Alternately:

1. Make a copy of your entire dayzOffline.chernarusplus or dayzOffline.enoch folder in the same \mpmission folder
2. Make sure to rename the copied folder to something like careerDayZ.chernarusplus or careerDayZ.enoch
- leaving the .chernarusplus or .enoch I don't think is critical but makes it easier to know the map you are running
3. Edit your serverDZ.cfg file and change your "template="dayzOffline.chernarusplus";" line to the new folder name eg. template="careerDayZ.enoch";
4. run your server and enjoy Career DayZ!!!


Editing Values:
Look for the SetCareerPath function and find all roles listed below this.
Any gear you want on the player, make sure it's in the "playerGear" line
Any items you want them to have will go in the "allItems" line
If you want to attach a canteen or holster, make sure you added a belt to the playerGear and then add these specific items to the beltAttachments line
The itemWeapon line for built for a weapon, but any item you want in your players hands at spawn goes here
The itemWeaponAttachments line is built for gun weapons and if compatible will auto attach the item to the item listed in the itemWeapon line. If you want your players to spawn with a mag, put it here and it will attach automatically to the gun if it fits. Same with adding a suppressor or optics.

If it's in braces {} this is an array and can hold multiple items in quotes "" separated by a comma ,
If it's only in quotes "" it will only hold 1 item (this is only the weapon slot currently)

Example:
playerGear = {"TacticalShirt_Olive","BDUPants","JungleBoots_Olive","TacticalGloves_Beige","MilitaryBelt"};
allItems = {"WeaponCleaningKit","Morphine","BandageDressing"};
beltAttachments = {"Canteen","PlateCarrierHolster"}
itemWeapon = "FNX45";
itemWeaponAttachments = {"Mag_FNX45_15Rnd"};



Want to help support the ongoing efforts of this mod? You can subscribe to my Patreon and get exclusive early access to this project.
Patreon Link: 
https://www.patreon.com/project3w
