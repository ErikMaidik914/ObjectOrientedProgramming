#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "ui.h"
#include <crtdbg.h>

int main()
{
    setbuf(stdout, NULL);
    startApplication();
    _CrtDumpMemoryLeaks();
    return 0;
}

