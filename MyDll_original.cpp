#include <Windows.h>

extern "C" __declspec(dllexport) int Add(int a, int b)                { return a + b; }
extern "C" __declspec(dllexport) int Sub(int a, int b)                { return a - b; }
extern "C" __declspec(dllexport) int Mul(int a, int b)                { return a * b; }
extern "C" __declspec(dllexport) int Div(int a, int b)                { return a / b; }
extern "C" __declspec(dllexport) void Func5()                         { }
extern "C" __declspec(dllexport) void Func6(const char* s)            { }
extern "C" __declspec(dllexport) int Func7(int x)                     { return x; }
extern "C" __declspec(dllexport) int Func8(int a, int b, int c)       { return 0; }
extern "C" __declspec(dllexport) void Func9()                         { }
extern "C" __declspec(dllexport) int Func10()                         { return 100; }

BOOL APIENTRY DllMain(HMODULE, DWORD, LPVOID) { return TRUE; }
