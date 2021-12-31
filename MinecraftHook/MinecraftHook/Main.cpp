//****************************************//
//This code is a property of Body Alhoha  //
//It's open source, but if you use any of //
//this code, you need to write my name on //
//credits. Please, don't juste copy paste //
//like a skid,I'm sure you don't even know//
//What "ave" is... If you have, anything, //
//any question, feel free to open an issue//
//****************************************//
#include "Main.h"
#include <exception>
#include <iostream>
#include "functions.h"


FILE* pFile = nullptr;



void run() {
	AllocConsole();
	freopen_s(&pFile, "CONOUT$", "w", stdout);
	try {
		if (getMinecraft() == NULL) {
			MessageBoxA(NULL, "Minecraft object not found!", "HookMc", MB_ICONERROR | MB_OK);
			return;
		}
	}
	catch (const std::exception&) {
		MessageBoxA(NULL, "Minecraft object not found!", "HookMc", MB_ICONERROR | MB_OK);
		return;
	}
	bool activated = false;
	while (true) {
		if (activated) {
			try {
				if (!getMinecraft())continue;
				if (!getPlayer())continue;
				setSprinting(true); //set Sprinting to true. WARNING : It does not check in what direction you go. You can sprint backwars which can make you flag.
				playerJump(false); //false make that it jump without checking if on ground.
			}
			catch (std::exception&) {
				std::cout << "exception..." << std::endl;
			}
			Sleep(30);
		}
		if (GetAsyncKeyState(VK_NUMPAD0) && 0x8000) {
			while (GetAsyncKeyState(VK_NUMPAD0) && 0x8000){}
			activated = !activated;

		}
		

		
	}


}