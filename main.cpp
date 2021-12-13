//Проект создания движка для игры
//Файл main.cpp
//Дата создания 13.12.2021г.
//Дата последней редакции 13.12.2021г.
//Автор Таранов Павел Анатольевич
//-------------------------------------------------------------------
#include <stdio.h>
#include <windows.h>

// Карта игрового поля имеет фиксированный размер
char caMap[30][120+1];

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

  //Карта инициализируется бордюром - '#' и свободным полем для размещения объектов - символом пробел ' '
  for(int posY = 0; posY < 30; posY++) {
    for(int posX = 0; posX < 120; posX++)
      if (posY == 0 || posY == 29 || posX == 0 || posX == 119)
	caMap[posY][posX] = '#';
      else
	caMap[posY][posX] = ' ';
    caMap[posY][120] = '\0';
  }

  //Вывести карту игрового поля на экран
    for(char *str : caMap)
      printf("%s\n", str);

  //Перед выходом в консоль вернуть курсору начальные настройки
  SetConsoleCursorInfo(handle, &structCursorInfoTemp);

  return 0;
}
