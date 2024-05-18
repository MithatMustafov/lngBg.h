#include <string>
#include <windows.h>
#pragma execution_character_set("utf-8")

// Setting the console's output code page to UTF-8
void setConsoleCyrillic() { SetConsoleOutputCP(65001); }

// Setting the console's output code page to Default
void setConsoleDefault() {
  SetConsoleCP(437);
  SetConsoleOutputCP(437);
}

class stringCyrillic {
  struct stringCyrillicVariables {
    std::string stringNoneCyrillic = "";
    std::string stringCyrillic = "";
  };

private:
  stringCyrillicVariables theString;

public:
  // Constructor
  stringCyrillic() {
    // theString.noneCyrillic = str;
  }

  void setText(const std::string &str)
  {
    theString.stringNoneCyrillic = str;
  }

  std::string getText()
  {
    return theString.stringNoneCyrillic;
  }

  int getLength()
  {
    /*
    int size = 0;
    char searchingSymbol = ' ';
    //std::string cyrillicString += searchingSymbol;
    //int lastIndex = cyrillicString.find_last_of(searchingSymbol);

    for (int letterIndex = 0; letterIndex < lastIndex; letterIndex++)
      if (cyrillicString[letterIndex] >= 0)
        size++;

    size += (cyrillicString.length() - size) / 2;

    return size;
    */
  }
};
