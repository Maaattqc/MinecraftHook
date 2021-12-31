//****************************************//
//This code is a property of Body Alhoha  //
//It's open source, but if you use any of //
//this code, you need to write my name on //
//credits. Please, don't juste copy paste //
//like a skid,I'm sure you don't even know//
//What "ave" is... If you have, anything, //
//any question, feel free to open an issue//
//****************************************//
#include "functions.h"


jobject getMinecraft() {
	jclass minecraftClass = mc.env->FindClass("ave");
	if (minecraftClass == NULL) {
		return NULL;
	}
	jmethodID minecraftField = mc.env->GetStaticMethodID(minecraftClass, "A", "()Lave;");
	if (minecraftField == NULL) {
		return NULL;
	}
	return mc.env->CallStaticObjectMethod(minecraftClass, minecraftField);
}
jobject getPlayer() {
	jfieldID playerField = mc.env->GetFieldID(mc.env->GetObjectClass(getMinecraft()), "h", "Lbew;");
	return mc.env->GetObjectField(getMinecraft(), playerField);
}
void setSprinting(jboolean sprinting) {
	jmethodID setSprinting = mc.env->GetMethodID(mc.env->GetObjectClass(getPlayer()), "d", "(Z)V");
	mc.env->CallBooleanMethod(getPlayer(), setSprinting, sprinting);
}
bool isOnGround() {
	jfieldID onGroundField = mc.env->GetFieldID(mc.env->GetObjectClass(getPlayer()), "C", "Z");
	jboolean onGround = mc.env->GetBooleanField(getPlayer(), onGroundField);


	if (onGround == false) {
		return false;
	}
	return true;
}
void playerJump(bool checkGround) {
	jmethodID jumpMethod = mc.env->GetMethodID(mc.env->GetObjectClass(getPlayer()), "bF", "()V");
	if (checkGround && !isOnGround())
		return;
	mc.env->CallVoidMethod(getPlayer(), jumpMethod);
}