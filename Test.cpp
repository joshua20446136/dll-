#include <Windows.h>
#include <stdio.h>

int main() {
    printf("测试开始\n");
    HMODULE hDll = LoadLibraryA("MyDll.dll");  // 用 A 版本

    typedef int(*Func)(int, int);
    ((Func)GetProcAddress(hDll, "Add"))(10, 20);
    ((Func)GetProcAddress(hDll, "Sub"))(50, 20);
    ((Func)GetProcAddress(hDll, "Mul"))(9, 8);
    ((Func)GetProcAddress(hDll, "Div"))(100, 2);
    ((void(*)())GetProcAddress(hDll, "Func5"))();
    ((void(*)(const char*))GetProcAddress(hDll, "Func6"))("test");
    ((int(*)(int))GetProcAddress(hDll, "Func7"))(123);
    ((int(*)(int,int,int))GetProcAddress(hDll, "Func8"))(1,2,3);
    ((void(*)())GetProcAddress(hDll, "Func9"))();
    ((int(*)())GetProcAddress(hDll, "Func10"))();

    printf("完成！生成了 dll_log.txt\n");
    return 0;
}
