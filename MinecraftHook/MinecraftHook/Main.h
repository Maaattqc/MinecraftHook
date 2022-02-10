//****************************************//
//This code is a property of Body Alhoha  //
//It's open source, but if you use any of //
//this code, you need to write my name on //
//credits. Please, don't juste copy paste //
//like a skid,I'm sure you don't even know//
//What "ave" is... If you have, anything, //
//any question, feel free to open an issue//
//****************************************//
#ifndef AAA_HEADER
#define AAA_HEADER
#include <windows.h>
#include "jni.h"
class Main{
public:
	JavaVM* vm;
	JNIEnv* env;
	JavaVMInitArgs vm_args;
} mc;

void run();

#endif