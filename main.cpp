//Проект создания движка для игры
//Файл main.cpp
//Дата создания 13.12.2021г.
//Дата последней редакции 13.12.2021г.
//Автор Таранов Павел Анатольевич
//-------------------------------------------------------------------
#include <stdio.h>
#include <windows.h>

//---- START ---- установка значений для настройки параметров игры/
//Установка размеров карты игрового поля по X и Y
const int iMapSizeX(50);
const int iMapSizeY(30);

//Установка значений графических псевдосимволов для отображения объектов на карте
const char cEmpty('.'); //Свободное место для передвижения и размещения объекта
const char cWall(219); //Непроходимая стена
//----  END  ---- ------------------------------------------------/


// Карта игрового поля имеет фиксированный размер
char caMap[iMapSizeY][iMapSizeX + 1];

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
  for(int posY = 0; posY < iMapSizeY; posY++) {
    for(int posX = 0; posX < iMapSizeX; posX++)
      if (posY == 0 || posY == iMapSizeY - 1 || posX == 0 || posX == iMapSizeX - 1)
	caMap[posY][posX] = cWall;
      else
	caMap[posY][posX] = cEmpty;
    caMap[posY][iMapSizeX] = '\0';
  }

  //Вывести карту игрового поля на экран
    for(char *str : caMap)
      printf("%s\n", str);

  //Перед выходом в консоль вернуть курсору начальные настройки
  SetConsoleCursorInfo(handle, &structCursorInfoTemp);

  return 0;
}
