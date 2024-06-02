#include <string>
#include <windows.h>
#pragma execution_character_set("utf-8")

// Setting the console's output code page to UTF-8
void setConsoleCyrillic()
{
	SetConsoleOutputCP(65001);
}

// Setting the console's output code page to Default
void setConsoleDefault()
{
	SetConsoleCP(437);
	SetConsoleOutputCP(437);
}

class stringCyrillic
{

	struct letter
	{
		char charPartA = '\0';
		char charPartB = '\0';
	};

	struct stringCyrillicVariables
	{
		letter* letters = nullptr;
		int length = 0;
	};

private:
	stringCyrillicVariables theString;

	int getCStringActualLength(const char* theString)
	{
		int letterCounterCyrillic = 0;
		int letterCounterNoneCyrillic = 0;
		while (theString[letterCounterCyrillic] != '\0')
		{
			if (theString[letterCounterCyrillic] > -1)
			{
				letterCounterNoneCyrillic++;
			}
			letterCounterCyrillic++;
		}
		return ((letterCounterCyrillic + letterCounterNoneCyrillic) / 2);
	}

public:

	stringCyrillic(const char* inputString)
	{
		theString.length = getCStringActualLength(inputString);
		theString.letters = new letter[theString.length];

		int index_inputString = 0, index_theString = 0;
		while (inputString[index_inputString] != '\0')
		{
			theString.letters[index_theString].charPartA = inputString[index_inputString];
			index_inputString++;

			if ((unsigned char)inputString[index_inputString - 1] >= 128)
			{
				theString.letters[index_theString].charPartB = inputString[index_inputString];
				index_inputString++;
			}
			else 
			{
				theString.letters[index_theString].charPartB = '\0'; 
			}

			index_theString++;
		}
	}

	int length()
	{
		return theString.length;
	}

	int capacity()
	{
		return  theString.length * sizeof(letter) + sizeof(int);
	}
	
	void print()
	{
		std::cout << "L: " << theString.length << std::endl;
		for (int i = 0; i < theString.length; ++i) 
		{
			int a = static_cast<int>(theString.letters[i].charPartA);
			std::cout << i << "[" << a;

			if (theString.letters[i].charPartB != '\0') {
				int b = static_cast<int>(theString.letters[i].charPartB);
				std::cout << "," << b << "|" << theString.letters[i].charPartA << theString.letters[i].charPartB << "]";
			}
			else {
				std::cout << "| " << theString.letters[i].charPartA << "]";
			}

			std::cout << std::endl;
		}
	}

	~stringCyrillic()
	{
		delete[] theString.letters;
	}

	stringCyrillic& operator=(const stringCyrillic& newData)
	{
		if (this != &newData)
		{
			delete[] theString.letters;

			theString.length = newData.theString.length;
			theString.letters = new letter[theString.length];

			for (int i = 0; i < theString.length; i++)
			{
				theString.letters[i].charPartA = newData.theString.letters[i].charPartA;
				theString.letters[i].charPartB = newData.theString.letters[i].charPartB;
			}
		}
		return *this;
	}

	friend std::ostream& operator<<(std::ostream& os, const stringCyrillic& myString)
    {
        for (int i = 0; i < myString.theString.length; ++i)
        {
            os << myString.theString.letters[i].charPartA;

            if (myString.theString.letters[i].charPartB != '\0')
            {
                os << myString.theString.letters[i].charPartB;
            }
        }

        return os;
    }

};
