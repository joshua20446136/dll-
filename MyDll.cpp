#include <Windows.h>
#include <stdio.h>
#include <stdarg.h>

#define REAL_DLL L"MyDll_original.dll"
HMODULE g_hRealDll = NULL;

void Log(const char* fmt, ...) {
    FILE* f = fopen("dll_log.txt", "a+");
    if (!f) return;
    va_list args;
    va_start(args, fmt);
    vfprintf(f, fmt, args);
    va_end(args);
    fprintf(f, "\n");
    fclose(f);
}

void LoadRealDll() {
    g_hRealDll = LoadLibrary(REAL_DLL);
    if (g_hRealDll) Log("[+] 加载原DLL成功");
    else Log("[-] 加载原DLL失败");
}

extern "C" __declspec(dllexport) int Add(int a, int b) {
    Log("[监控] Add a=%d b=%d", a, b);
    typedef int(*Func)(int, int);
    Func real = (Func)GetProcAddress(g_hRealDll, "Add");
    int ret = real(a, b);
    Log("[监控] Add 返回=%d", ret);
    return ret;
}

extern "C" __declspec(dllexport) int Sub(int a, int b) {
    Log("[监控] Sub a=%d b=%d", a, b);
    typedef int(*Func)(int, int);
    Func real = (Func)GetProcAddress(g_hRealDll, "Sub");
    int ret = real(a, b);
    Log("[监控] Sub 返回=%d", ret);
    return ret;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD reason, LPVOID res) {
    if (reason == DLL_PROCESS_ATTACH) LoadRealDll();
    return TRUE;
}
