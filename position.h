
  #include <windows.h>

  inline void gotoxy( int x, int y ){
    COORD p = { x, y };
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), p );
    }
