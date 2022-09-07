/*  version: 22.08.26.001

   You running this script/function means you will not blame the author(s) 
   if this breaks your game. This script/function is provided AS IS without 
   warranty of any kind. Author(s) disclaim all implied warranties including, 
   without limitation, any implied warranties of merchantability or of fitness 
   for a particular purpose. The entire risk arising out of the use or performance 
   of the sample scripts and documentation remains with you. 
   
   In no event shall author(s) be held liable for any damages whatsoever (including, 
   without limitation, damages for loss of business profits, business interruption, 
   loss of business information, or other pecuniary loss) arising out of the use of 
   or inability to use the script or documentation. Neither this script/function, 
   nor any part of it other than those parts that are explicitly copied from others, 
   may be republished without author(s) express written permission. 
   
   Author(s) retain the right to alter this disclaimer at any time. 
   
*/

void main()
{
	//INIT ECONOMY--------------------------------------
	Hive ce = CreateHive();
	if ( ce )
		ce.InitOffline();

	//DATE RESET AFTER ECONOMY INIT-------------------------
	int year, month, day, hour, minute;
	int reset_month = 9, reset_day = 20;
	GetGame().GetWorld().GetDate(year, month, day, hour, minute);

	if ((month == reset_month) && (day < reset_day))
	{
		GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
	}
	else
	{
		if ((month == reset_month + 1) && (day > reset_day))
		{
			GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
		}
		else
		{
			if ((month < reset_month) || (month > reset_month + 1))
			{
				GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
			}
		}
	}
}

class CustomMission: MissionServer
{
	
	/* Set global variables to use in the following functions */
	
	bool rndHealthClothing = true; // set this to false if you want your spawned clothing items to be pristine instead of random between low end badly damaged and high end of worn
	
	
	/* Define the chosen career and Generate the starting gear */
	
	/*******************************************************/
	/* EDITING OF ITEMS IS PERFORMED IN THIS FUNCTION ONLY */
	/*******************************************************/
	
	void SetCareerPath(PlayerBase player) {
		
		/* grab a random career on spawn */
		int rndCareer = Math.RandomInt( 0, 99 ); // comment out if you are testing a specific character role **be sure to comment out next line or you will get an error on load**
		//int rndCareer = 90; // comment out if you are running all available character roles, set number and uncomment if testing for a specific role **be sure to comment out previous line if testing or you will get an error on load**
		
		/* set gloabal variables for strict processing requirements */
		autoptr TStringArray playerGear; 
		autoptr TStringArray allItems;
		autoptr TStringArray beltAttachments;
		string itemWeapon;
		autoptr TStringArray itemWeaponAttachments;
		
		/* check rndCareer value and set appropriate loadout */
		if (rndCareer < 5) { 	
		
			/* prisoner */
			
			/* Build Loadout */
			/* this list should include ALL items you want your spawned characters to wear */
			playerGear = {"PrisonUniformJacket","PrisonUniformPants","PrisonerCap","JoggingShoes_White"};
			allItems = {"Chemlight_White","Apple","BandageDressing"};
			beltAttachments = {};
			itemWeapon = "StoneKnife";
			itemWeaponAttachments = {};
			
			/* send items to build loadout */
			attachLoadout(player,playerGear,allItems,beltAttachments);
			attachWeapon(player,itemWeapon,itemWeaponAttachments);
		
		} else if ( 5 <= rndCareer && rndCareer < 15 ) { 
		
			/* businessman */
			
			/* Build Loadout */
			/* this list should include ALL items you want your spawned characters to wear */
			playerGear = {"ManSuit_Black","SlacksPants_Black","DressShoes_Black","CivilianBelt"};
			allItems = {"Paper","PetrolLighter","Pen_Blue","Pajka"};
			beltAttachments = {};
			itemWeapon = "SharpWoodenStick";
			itemWeaponAttachments = {};
			
			/* send items to build loadout */
			attachLoadout(player,playerGear,allItems,beltAttachments);
			attachWeapon(player,itemWeapon,itemWeaponAttachments);
		
			
		} else if ( 15 <= rndCareer && rndCareer < 25 ) { 
		
			/* civilian */
			
			/* Build Loadout */
			/* this list should include ALL items you want your spawned characters to wear */
			playerGear = {"Hoodie_Blue","Jeans_BlueDark","JoggingShoes_White"};
			allItems = {"Rag","SaltySticks","SodaCan_Cola","DisinfectantSpray"};
			beltAttachments = {};
			itemWeapon = "KitchenKnife";
			itemWeaponAttachments = {};
			
			/* send items to build loadout */
			attachLoadout(player,playerGear,allItems,beltAttachments);
			attachWeapon(player,itemWeapon,itemWeaponAttachments);
			
		} else if ( 25 <= rndCareer && rndCareer < 35 ) { 
		
			/* industrial */
			
			/* Build Loadout */
			/* this list should include ALL items you want your spawned characters to wear */
			playerGear = {"Shirt_BlueCheckBright","CargoPants_Beige","WorkingBoots_Brown","WorkingGloves_Brown","ConstructionHelmet_Orange"};
			allItems = {"DuctTape","EpoxyPutty","Hammer","NailBox","Flashlight","Battery9V"};
			beltAttachments = {};
			itemWeapon = "Crowbar";
			itemWeaponAttachments = {};
			
			/* send items to build loadout */
			attachLoadout(player,playerGear,allItems,beltAttachments);
			attachWeapon(player,itemWeapon,itemWeaponAttachments);
			
		} else if ( 35 <= rndCareer && rndCareer < 45 ) { 
		
			/* athlete */
			
			/* Build Loadout */
			/* this list should include ALL items you want your spawned characters to wear */
			playerGear = {"TrackSuitJacket_Red","TrackSuitPants_Red","AthleticShoes_Grey","BaseballCap_Red"};
			allItems = {"WaterBottle","Apple","VitaminBottle"};
			beltAttachments = {};
			itemWeapon = "Baseballbat";
			itemWeaponAttachments = {};
			
			/* send items to build loadout */
			attachLoadout(player,playerGear,allItems,beltAttachments);
			attachWeapon(player,itemWeapon,itemWeaponAttachments);
				
		} else if ( 45 <= rndCareer && rndCareer < 55 ) { 
		
			/* farmer */
			
			/* Build Loadout */
			/* this list should include ALL items you want your spawned characters to wear */
			playerGear = {"Shirt_GreenCheck","Jeans_Blue","WorkingBoots_Brown","WorkingGloves_Brown"};
			allItems = {"WaterBottle","TomatoSeeds","Tomato"};
			beltAttachments = {};
			itemWeapon = "FarmingHoe";
			itemWeaponAttachments = {};
			
			/* send items to build loadout */
			attachLoadout(player,playerGear,allItems,beltAttachments);
			attachWeapon(player,itemWeapon,itemWeaponAttachments);
					
		} else if ( 55 <= rndCareer && rndCareer < 65 ) { 
		
			/* medic */
			
			/* Build Loadout */
			/* this list should include ALL items you want your spawned characters to wear */
			playerGear = {"ParamedicJacket_Blue","ParamedicPants_Blue","SurgicalGloves_Blue","WorkingBoots_Beige","FirstAidKit"};
			allItems = {"BandageDressing","BloodTestKit","StartKitIV","TetracyclineAntibiotics","WaterBottle","Epinephrine"};
			beltAttachments = {};
			itemWeapon = "BoneKnife";
			itemWeaponAttachments = {};
		
			/* send items to build loadout */
			attachLoadout(player,playerGear,allItems,beltAttachments);
			attachWeapon(player,itemWeapon,itemWeaponAttachments);
					
		} else if ( 65 <= rndCareer && rndCareer < 75 ) { 
		
			/* hunter */
			
			/* Build Loadout */
			/* this list should include ALL items you want your spawned characters to wear */
			playerGear = {"HuntingJacket_Brown","HunterPants_Brown","HikingBoots_Brown","LeatherBelt_Brown"};
			allItems = {"Compass","Ammo_762x39","ZagorkyPeanuts","PurificationTablets","HuntingKnife"};
			beltAttachments = {"LeatherKnifeSheath"}
			itemWeapon = "Izh18";
			itemWeaponAttachments = {};
			
			/* send items to build loadout */
			attachLoadout(player,playerGear,allItems,beltAttachments);
			attachWeapon(player,itemWeapon,itemWeaponAttachments);
					
		} else if ( 75 <= rndCareer && rndCareer < 85 ) { 
		
			/* firefighter */
			
			/* Build Loadout */
			/* this list should include ALL items you want your spawned characters to wear */
			playerGear = {"FirefighterJacket_Black","FirefightersPants_Black","WorkingBoots_Grey","FirefightersHelmet_Red"};
			allItems = {"WaterBottle","Roadflare"};
			beltAttachments = {};
			itemWeapon = "FirefighterAxe";
			itemWeaponAttachments = {};
			
			/* send items to build loadout */
			attachLoadout(player,playerGear,allItems,beltAttachments);
			attachWeapon(player,itemWeapon,itemWeaponAttachments);
			
		} else if ( 85 <= rndCareer && rndCareer < 95 ) { 
		
			/* police */
			
			/* Build Loadout */
			/* this list should include ALL items you want your spawned characters to wear */
			playerGear = {"PoliceCap","PoliceJacket","PolicePants","DressShoes_Black","CivilianBelt"};
			allItems = {"Handcuffs","HandcuffKeys","PetrolLighter"};
			beltAttachments = {"PlateCarrierHolster"}
			itemWeapon = "MakarovIJ70";
			itemWeaponAttachments = {"Mag_IJ70_8Rnd"};
			
			/* send items to build loadout */
			attachLoadout(player,playerGear,allItems,beltAttachments);
			attachWeapon(player,itemWeapon,itemWeaponAttachments);
					
		} else if ( 95 <= rndCareer ) { 
		
			/* military */
			
			/* Build Loadout */
			/* this list should include ALL items you want your spawned characters to wear */
			playerGear = {"TacticalShirt_Olive","BDUPants","JungleBoots_Olive","TacticalGloves_Beige","MilitaryBelt"};
			allItems = {"WeaponCleaningKit","Morphine","BandageDressing"};
			beltAttachments = {"Canteen","PlateCarrierHolster"}
			itemWeapon = "FNX45";
			itemWeaponAttachments = {"Mag_FNX45_15Rnd"};
			
			/* send items to build loadout */
			attachLoadout(player,playerGear,allItems,beltAttachments);
			attachWeapon(player,itemWeapon,itemWeaponAttachments);
					
		}
	}
	
	
	/************************************************************/
	/* THERE SHOULD BE NO NEED TO EDIT ANYTHING BELOW THIS LINE */
	/************************************************************/
	
	/* function to loop array and attach items to player */
	void attachLoadout (PlayerBase player, TStringArray playerGear, TStringArray playerItems, TStringArray beltItems) {
		
		/* Loops through the array and puts last item in your hands - typically the weapon */
		// define our total number of items to attach
		int gearCount = playerGear.Count();
		int weaponSlot = (gearCount - 1);
			
		// loop through the array and attach items
		foreach(string j: playerGear) {
			player.GetInventory().CreateInInventory(j);
		}
		
		/* set up items for each possible inventory slot/clothing slot */
		EntityAI itemsArray[11];
		itemsArray[0] = player.FindAttachmentBySlotName("Armband");
		itemsArray[1] = player.FindAttachmentBySlotName("Backpack");
		itemsArray[2] = player.FindAttachmentBySlotName("Body");
		itemsArray[3] = player.FindAttachmentBySlotName("Eyewear");
		itemsArray[4] = player.FindAttachmentBySlotName("Feet");
		itemsArray[5] = player.FindAttachmentBySlotName("Gloves");
		itemsArray[6] = player.FindAttachmentBySlotName("Headgear");
		itemsArray[7] = player.FindAttachmentBySlotName("Hips");
		itemsArray[8] = player.FindAttachmentBySlotName("Legs");
		itemsArray[9] = player.FindAttachmentBySlotName("Mask");
		itemsArray[10] = player.FindAttachmentBySlotName("Vest");
			
		/* set random health on starting items if configured */
		if (rndHealthClothing == true) {
			if (itemsArray) {
				foreach(int z, EntityAI ia: itemsArray) {
					if(itemsArray[z]) {
						SetRandomHealth(ia);
					}
				}
			}
		}
		
		/* drop provided items into the inventory slots */
		if(playerItems) {
			foreach(string pi: playerItems) {
				player.GetInventory().CreateInInventory(pi);
			}
		}
		
		/* attach belt items if provided */
		if(beltItems) {
			foreach(string bi: beltItems) {
				itemsArray[7].GetInventory().CreateAttachment(bi);
			}
		}
	}
	
	/* attach gun and provided ammo */
	void attachWeapon(PlayerBase player, string playerWeapon, TStringArray weaponAttachments) {
		int weaponAttachmentCount = weaponAttachments.Count();
		bool magAdded = false;
		
		/* put first inventory in hands - assumed to be the gun */
		EntityAI weapon = player.GetHumanInventory().CreateInHands(playerWeapon)
		
		/* verify weaponAttachments has items before looping through */
		if (weaponAttachmentCount > 0) {
			
			/* create attachments as the rest of the items */
			foreach(int wa, string was: weaponAttachments) {
				
				string weaponStart = weaponAttachments[wa].Substring(0,3);
				//string weaponLower = weaponStart.ToLower();
			
				/* verify if the string starts with "mag" and drop in inventory if adding more than 1 */
				if (weaponStart == "Mag" && magAdded == false) {
					magAdded = true;
					weapon.GetInventory().CreateAttachment(was);
				} else if (weaponStart == "Mag" && magAdded == true) {
					player.GetInventory().CreateInInventory(was);
				} else {
					weapon.GetInventory().CreateAttachment(was);
				}
			}
		}
	}
	
	void SetRandomHealth(EntityAI itemEnt)
	{
		if ( itemEnt )
		{
			float rndHlt = Math.RandomFloat( 0.45, 0.65 );
			itemEnt.SetHealth01( "", "", rndHlt );
		}
	}

	override PlayerBase CreateCharacter(PlayerIdentity identity, vector pos, ParamsReadContext ctx, string characterName)
	{
		Entity playerEnt;
		playerEnt = GetGame().CreatePlayer( identity, characterName, pos, 0, "NONE" );
		Class.CastTo( m_player, playerEnt );

		GetGame().SelectPlayer( identity, m_player );

		return m_player;
	}

	override void StartingEquipSetup(PlayerBase player, bool clothesChosen)
	{
		
		/* remove all items attached by default to be able to assign new loadouts */
		player.RemoveAllItems();
		
		/* call our career function and start the game */
		SetCareerPath(player);
		
	}
};

Mission CreateCustomMission(string path)
{
	return new CustomMission();
}