#include "Utils.h"

BOOL ClearConsole()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coordScreen = { 0, 0 };    // home for the cursor
	DWORD cCharsWritten = 0;
	DWORD dwConSize = 0;
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	// Error checking...
	if (hConsole == INVALID_HANDLE_VALUE || hConsole == NULL) return FALSE;

	// Get the number of character cells in the current buffer.
	if (GetConsoleScreenBufferInfo(hConsole, &csbi) != TRUE) return FALSE;

	// Calculate the console size.
	dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

	// Fill the entire screen with blanks.
	if (FillConsoleOutputCharacterA(hConsole, // Handle to console screen buffer
		' ',                                  // Character to write to the buffer
		dwConSize,                            // Number of cells to write
		coordScreen,                          // Coordinates of first cell
		&cCharsWritten) != TRUE)              // Receive number of characters written
		return FALSE;

	// Get the current text attribute.
	if (!GetConsoleScreenBufferInfo(hConsole, &csbi) != TRUE) return FALSE;

	// Set the buffer's attributes accordingly.
	if (!FillConsoleOutputAttribute(hConsole, // Handle to console screen buffer
		csbi.wAttributes,                     // Character attributes to use
		dwConSize,                            // Number of cells to set attribute
		coordScreen,                          // Coordinates of first cell
		&cCharsWritten) != TRUE)              // Receive number of characters written
		return FALSE;

	// Put the cursor at its home coordinates.
	return SetConsoleCursorPosition(hConsole, coordScreen);
}

void WaitForDebugger()
{
	while (IsDebuggerPresent() == FALSE)
	{
		Sleep(100);
	}
}

void AllocConsoleQuick()
{
	FILE *__fDummy;
	BOOL bResult;

	bResult = AllocConsole();

	if (bResult == TRUE)
	{
		_wfreopen_s(&__fDummy, L"CONIN$", L"r", stdin);
		_wfreopen_s(&__fDummy, L"CONOUT$", L"w", stderr);
		_wfreopen_s(&__fDummy, L"CONOUT$", L"w", stdout);
		//SetConsoleCP(CP_UTF8);
		SetConsoleOutputCP(CP_UTF8);
		SetConsoleTitle(TEXT("a cat in need is a cat indeed."));
	}
}