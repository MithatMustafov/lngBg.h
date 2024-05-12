#pragma once
#pragma once
#include <iostream>
#include <windows.h>
#pragma execution_character_set( "utf-8" )
//UTF-8 Cyrillic

const std::string ALPHABET_CYRILLIC_CP65001_TEXTS[] = {
    "а",
    "б",
    "в",
    "г",
    "д",
    "е",
    "ж",
    "з",
    "и",
    "й",
    "к",
    "л",
    "м",
    "н",
    "о",
    "п",
    "р",
    "с",
    "т",
    "у",
    "ф",
    "х",
    "ц",
    "ч",
    "ш",
    "щ",
    "ъ",
    "ь",
    "ю",
    "я",
    "А",
    "Б",
    "В",
    "Г",
    "Д",
    "Е",
    "Ж",
    "З",
    "И",
    "Й",
    "К",
    "Л",
    "М",
    "Н",
    "О",
    "П",
    "Р",
    "С",
    "Т",
    "У",
    "Ф",
    "Х",
    "Ц",
    "Ч",
    "Ш",
    "Щ",
    "Ъ",
    "Ь",
    "Ю",
    "Я"
};

const short ALPHABET_CYRILLIC_CP65001_UTF8_CODES[][2] = {
    {-48, -80},
    {-48, -79},
    {-48, -78},
    {-48, -77},
    {-48, -76},
    {-48, -75},
    {-48, -74},
    {-48, -73},
    {-48, -72},
    {-48, -71},
    {-48, -70},
    {-48, -69},
    {-48, -68},
    {-48, -67},
    {-48, -66},
    {-48, -65},
    {-47, -128},
    {-47, -127},
    {-47, -126},
    {-47, -125},
    {-47, -124},
    {-47, -123},
    {-47, -122},
    {-47, -121},
    {-47, -120},
    {-47, -119},
    {-47, -118},
    {-47, -116},
    {-47, -114},
    {-47, -113},
    {-47, -112},
    {-48, -111},
    {-48, -110},
    {-48, -109},
    {-48, -108},
    {-48, -107},
    {-48, -106},
    {-48, -105},
    {-48, -104},
    {-48, -103},
    {-48, -102},
    {-48, -101},
    {-48, -100},
    {-48, -99},
    {-48, -98},
    {-48, -97},
    {-48, -96},
    {-48, -95},
    {-48, -94},
    {-48, -93},
    {-48, -92},
    {-48, -91},
    {-48, -90},
    {-48, -89},
    {-48, -88},
    {-48, -87},
    {-48, -86},
    {-48, -85},
    {-48, -84},
    {-48, -83},
    {-48, -82},
    {-48, -81}
};

const short ALPHABET_CYRILLIC_CP1251_WINDOWS_CODES[] = {
    -32,
    -31,
    -30,
    -29,
    -28,
    -27,
    -26,
    -25,
    -24,
    -23,
    -22,
    -21,
    -20,
    -19,
    -18,
    -17,
    -16,
    -15,
    -14,
    -13,
    -12,
    -11,
    -10,
    -9,
    -8,
    -7,
    -6,
    -4,
    -2,
    -1,
    -64,
    -63,
    -62,
    -61,
    -60,
    -59,
    -58,
    -57,
    -56,
    -55,
    -54,
    -53,
    -52,
    -51,
    -50,
    -49,
    -48,
    -47,
    -46,
    -45,
    -44,
    -43,
    -42,
    -41,
    -40,
    -39,
    -38,
    -36,
    -34,
    -33
};

//Setting the console's output code page to Windows-1251
void cinBGvariable()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
}

//Setting the console's output code page to Windows-1251
void coutBGvariable()
{
    cinBGvariable();
}


//Setting the console's output code page to UTF-8
void coutBGconsole()
{
    SetConsoleOutputCP(65001);
}

//Setting the console's output code page to Default
void endBG()
{
    SetConsoleCP(437);
    SetConsoleOutputCP(437);
}

//Get the right length Of Cyrillic string
int lngBG_getLengthOfCyrillicString(std::string cyrillicString)
{
    int size = 0;
    char searchingSymbol = ' ';
    cyrillicString += searchingSymbol;
    int lastIndex = cyrillicString.find_last_of(searchingSymbol);


    for (int letterIndex = 0; letterIndex < lastIndex; letterIndex++)
        if (cyrillicString[letterIndex] >= 0)
            size++;

    size += (cyrillicString.length() - size) / 2;

    return size;
};

int lngBG_getSetWCyrillicStringAdjustment(const std::string& cyrillicString)
{
    // cyrillicString = " ";

    // actual size = 11
    int cyrillicStringActualSize = lngBG_getLengthOfCyrillicString(cyrillicString);

    // system .length()  = 21
    int cyrillicStringLength = cyrillicString.length();

    // Get how many are the none cyrillic chars
    // It is the  2 x actual size - system length of the string
    // => none cyrillic chars = 2 * 11 - 21 = 1
    int adjustmentNoneCyrillicChars = 2 * cyrillicStringActualSize - cyrillicStringLength;

    // Adjustment the SetW
    // The string is cyrillic and it is made of two codes/char 
    // While printing them they add up and there are extra ghost chars
    // so to correct it, it has to be the setW + the adjustment:
    // + once the size of the string
    // - adjustmentNoneCyrillicChars

    int adjustment = cyrillicStringActualSize - adjustmentNoneCyrillicChars;

    return adjustment;
}


// It just converts letter by letter searching in the different type arrays
// NB! when have time make it to worki like ASCII code 
// to be able to find it by +/- a number becuse it is slow this way with the loops
std::string lngBG_convertCyrillicWindowsToUTF8(std::string cyrillicString)
{
    int cyrillicStringWindowsLength = cyrillicString.length();
    std::string newCyrillicString;

    for (int letterIndex = 0; letterIndex < cyrillicStringWindowsLength; letterIndex++)
    {
        int currentLetterCodeIndex = cyrillicString[letterIndex];

        // Hard codded these letter becuase it returns something wrong for them
        if (currentLetterCodeIndex == -64) { newCyrillicString += "А"; }
        else if (currentLetterCodeIndex == -36) { newCyrillicString += "Ь"; }
        else if (currentLetterCodeIndex == -34) { newCyrillicString += "Ю"; }
        else if (currentLetterCodeIndex == -33) { newCyrillicString += "Я"; }
        else
        {
            bool foundChar = false;
            for (int codeIndex = 0; codeIndex < 60; codeIndex++)
            {
                if (currentLetterCodeIndex == ALPHABET_CYRILLIC_CP1251_WINDOWS_CODES[codeIndex])
                {
                    currentLetterCodeIndex = codeIndex;
                    foundChar = true;
                    break;
                }
            }
            if (foundChar)
                newCyrillicString += {
                static_cast<char>(ALPHABET_CYRILLIC_CP65001_UTF8_CODES[currentLetterCodeIndex][0]),
                    static_cast<char>(ALPHABET_CYRILLIC_CP65001_UTF8_CODES[currentLetterCodeIndex][1])
            };
            else
                newCyrillicString += static_cast<char>(currentLetterCodeIndex);
        }
    }

    return newCyrillicString;
}