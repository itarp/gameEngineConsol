//Проект создания движка для игры
//Файл main.cpp
//Дата создания 13.12.2021г.
//Дата последней редакции 13.12.2021г.
//Автор Таранов Павел Анатольевич
//-------------------------------------------------------------------
#include <stdio.h>
#include <windows.h>

// Карта игрового поля имеет фиксированный размер, инициализируется бордюром - '#' и свободным полем - символом пробел ' '
char caMap[30][120+1] = {
  "########################################################################################################################",
  "#                                                                                                                      #",
  "#                                                                                                                      #",
  "#                                                                                                                      #",
  "#                                                                                                                      #",
  "#                                                                                                                      #",
  "#                                                                                                                      #",
  "#                                                                                                                      #",
  "#                                                                                                                      #",
  "#                                                                                                                      #",
  "#                                                                                                                      #",
  "#                                                                                                                      #",
  "#                                                                                                                      #",
  "#                                                                                                                      #",
  "#                                                                                                                      #",
  "#                                                                                                                      #",
  "#                                                                                                                      #",
  "#                                                                                                                      #",
  "#                                                                                                                      #",
  "#                                                                                                                      #",
  "#                                                                                                                      #",
  "#                                                                                                                      #",
  "#                                                                                                                      #",
  "#                                                                                                                      #",
  "#                                                                                                                      #",
  "#                                                                                                                      #",
  "#                                                                                                                      #",
  "#                                                                                                                      #",
  "#                                                                                                                      #",
  "########################################################################################################################"
};

int main(int argc, char *argv[]) {
  //Получить дескриптор стандартного вывода
  HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

  //Отключить курсор и сохранить начальные настройки.
  CONSOLE_CURSOR_INFO structCursorInfo, structCursorInfoTemp;
  GetConsoleCursorInfo(handle, &structCursorInfo);
  structCursorInfoTemp = structCursorInfo;
  structCursorInfo.bVisible = false;
  SetConsoleCursorInfo(handle, &structCursorInfo);

  //Установить курсор в левый верхний угол экрана
  COORD cursorPos;
  cursorPos.X = 0;
  cursorPos.Y = 0;
  SetConsoleCursorPosition(handle, cursorPos);

  //Вывести карту игрового поля на экран
  printf("%s\n",caMap[0]);
  printf("%s\n",caMap[1]);
  printf("%s\n",caMap[2]);
  printf("%s\n",caMap[3]);
  printf("%s\n",caMap[4]);
  printf("%s\n",caMap[5]);
  printf("%s\n",caMap[6]);
  printf("%s\n",caMap[7]);
  printf("%s\n",caMap[8]);
  printf("%s\n",caMap[9]);
  printf("%s\n",caMap[10]);
  printf("%s\n",caMap[11]);
  printf("%s\n",caMap[12]);
  printf("%s\n",caMap[13]);
  printf("%s\n",caMap[14]);
  printf("%s\n",caMap[15]);
  printf("%s\n",caMap[16]);
  printf("%s\n",caMap[17]);
  printf("%s\n",caMap[18]);
  printf("%s\n",caMap[19]);
  printf("%s\n",caMap[20]);
  printf("%s\n",caMap[21]);
  printf("%s\n",caMap[22]);
  printf("%s\n",caMap[23]);
  printf("%s\n",caMap[24]);
  printf("%s\n",caMap[25]);
  printf("%s\n",caMap[26]);
  printf("%s\n",caMap[27]);
  printf("%s\n",caMap[28]);
  printf("%s\n",caMap[29]);

  //Перед выходом в консоль вернуть курсору начальные настройки
  SetConsoleCursorInfo(handle, &structCursorInfoTemp);

  return 0;
}
