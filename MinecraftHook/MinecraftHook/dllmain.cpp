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
void init() {
    DWORD id = GetCurrentProcessId();
    if (id == NULL) {
        MessageBox(NULL, "Invalid PID", "HookMc", MB_ICONERROR);
        exit(-1);
    }
    HWND window = FindWindow(NULL, "Minecraft 1.8.9");
    if (!window) {
        MessageBox(NULL, "Minecraft not found.", "HookMc", MB_ICONERROR);
    }
    jsize vmCount;
    if (JNI_GetCreatedJavaVMs(&mc.vm, 1, &vmCount) != JNI_OK || vmCount == 0) {
        MessageBoxA(NULL, "Java VM not found.", "HookMc", MB_ICONERROR | MB_OK);
        return;
    }
    jint res = mc.vm->GetEnv((void**)&mc.env, JNI_VERSION_1_6);
    if (res == JNI_EDETACHED) {
        res = mc.vm->AttachCurrentThread((void**)&mc.env, nullptr);
    }
    if (res != JNI_OK) {
        MessageBoxA(NULL, "Could not create a java environnement.", "HookMc", MB_ICONERROR | MB_OK);
        return;
    }

    if (mc.env != nullptr) {
        run();
    }
    else {
        MessageBoxA(NULL, "Could not create a java environnement.", "HookMc", MB_ICONERROR | MB_OK);
        return;
    }

}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)init, 0, 0,0);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

