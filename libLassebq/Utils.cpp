#include "Utils.h"
#include <time.h>
#include <stdlib.h>

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
	if (FillConsoleOutputCharacterW(hConsole, // Handle to console screen buffer
		L' ',                                 // Character to write to the buffer
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
	BOOL bResult;

	bResult = AllocConsole();

	if (bResult == TRUE)
	{
		FILE* oldstdin = stdin;
		FILE* oldstderr = stderr;
		FILE* oldstdout = stdout;
		_wfreopen_s(&oldstdin, L"CONIN$", L"r", stdin);
		_wfreopen_s(&oldstderr, L"CONOUT$", L"w", stderr);
		_wfreopen_s(&oldstdout, L"CONOUT$", L"w", stdout);
		//SetConsoleCP(CP_UTF8);
		SetConsoleOutputCP(CP_UTF8);
		SetConsoleTitle(TEXT("libLassebq Console Window"));
	}
}

const char* GetRandomQuote()
{
	// initialize the rng
	unsigned int rndSeed = static_cast<unsigned int>(time(nullptr) & UINT_MAX);
	srand(rndSeed);

	// lel.
	int rndValue = rand() % 21;
	switch (rndValue)
	{
		case  0: return   "Never fear, the pug is here.";
		case  1: return   "Let's hope Lassebq got his tea.";
		case  2: return   "Stay home and wear a mask.";
		case  3: return   "I am bad at coming up with random quotes, am I?";
		case  4: return   "[unknown] likes cats, even though he says he doesn't.";
		case  5: return   "#FreeAlexeiNavalny"; // let's hope our school teachers won't see this :p
		case  6: return   "Here comes the videogame";
		case  7: return   "Now with 90% more metamethods";
		case  8: return   "The feeling of a 2.0 release, it's rewarding, isn't it?";
		case  9: return u8"о, это что, русский текст?"; // console output encoding is utf8.

		// akhchiptune
		case 10: return u8"жду релиза akhchiptune как результатов ќ√Ё ^^'";
		case 11: return   "akhchiptune - the best sound library in the world that is yet to be released!";

		// hugs
		case 12: return   "I wouldn't mind a hug, if you think about it, who wouldn't? They're vewy wawm.";
		case 13: return u8"обнимашки спасут мир!";

		// cats
		case 14: return u8"котики классные, они хот€ бы искренне люб€т теб€. =^-^=";
		case 15: return   "cats are cool, at least they truly love you for who you are. =^-^=";

		// what?
		case 16: return   "Now you're not limited by obj_libLassebq!";
		case 17: return   "what a great person nik is. he made such a great update to libLassebq!";
			//				... and it doesn't matter how much time it took him to make it!
		case 18: return   "Stay funky, stay wholesome, stay cool.";
		case 19: return   "Cherry jam is pretty tasty, everyone should try it";
		case 20: return   "ngl nik is very PogChamp.";
		default: return   "Wtf? You're not supposed to see this quote.";
	}
}

bool CheckFileOk(const std::string& filePath)
{
#ifdef USE_WINAPI_FILE_WAIT_FIX
	HANDLE hFile = nullptr;
	DWORD dwErr = 0;
	bool ret = false;

	int siz = MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS, filePath.c_str(), -1, nullptr, 0);
	if (siz <= 0)
	{
		std::cout << "UNABLE TO CONVERT YOUR FILENAME TO UTF-16: " << filePath << std::endl;
		return false;
	}

	LPWSTR wFilename = new WCHAR[siz];
	MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS, filePath.c_str(), -1, wFilename, siz);

	for (int i = 0, j = 0;;)
	{
		hFile = CreateFileW(wFilename, GENERIC_READ, 0, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
		dwErr = GetLastError();
		CloseHandle(hFile);

		if (dwErr == ERROR_SHARING_VIOLATION) // file is being used by something?
		{
			std::cout << "File " << filePath << " is busy, waiting..." << std::endl;
			Sleep(20);
			i++;
			if (i > 20) // waited for 20*20 milisecs, that's a lot.
			{
				std::cout << "Waited too much, bailing..." << std::endl;
				break;
			}
		}
		else if (dwErr == ERROR_FILE_NOT_FOUND) // just break, ignore non-existent files.
		{
			break;
		}
		else if (hFile == INVALID_HANDLE_VALUE || hFile == nullptr) // what? that is never supposed to happen.
		{
			j++;
			if (j > 20)
			{
				std::cout << "PLEASE CLOSE THE GAME NOW AND REMOVE `" << filePath << "` FROM THE LOADLIST!" << std::endl;
			}
			else
			{
				std::cout << "Failed to open file, bailing..." << std::endl;
			}
			break;
		}
		else
		{
			ret = true;
			break;
		}
	}

	delete[] wFilename;
	//std::cout << "File is no longer busy or the loop was stopped." << std::endl;
	return ret;
#else
	return true;
#endif
}
