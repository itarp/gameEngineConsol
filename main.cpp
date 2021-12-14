//Проект создания движка для игры
//Файл main.cpp
//Дата создания 13.12.2021г.
//Дата последней редакции 14.12.2021г.
//Автор Таранов Павел Анатольевич
//-------------------------------------------------------------------
#include <stdio.h>
#include <windows.h>

//---- START ---- установка значений для настройки параметров игры/
//Установка размеров карты игрового поля по X и Y
const int iMapSizeX(80);
const int iMapSizeY(24);

//Установка значений графических псевдосимволов для отображения объектов на карте
const char cEmpty(' '); //Свободное место для передвижения и размещения объекта
const char cWall(219); //Непроходимая стена
const char cMainObj('O'); //Главный объeкт игры
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

  //Карта инициализируется бордюром - cWall и свободным полем для размещения и передвижения объектов - cEmpty
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

  //Вычислить координаты размещения главного объекта в центр карты по X и по Y.
  //Проверить можно ли размещать объект в данное место на карте
  COORD mainObjPos;
  mainObjPos.X = iMapSizeX / 2;
  mainObjPos.Y = iMapSizeY / 2;

  //Проверить можно ли размещать объект в вычисленное место на карте.
  //Если объект разместить можно записать его координаты на карту.
  if (caMap[mainObjPos.Y][mainObjPos.X] == cEmpty)
    caMap[mainObjPos.Y][mainObjPos.X] = cMainObj;
  else
    ;//Пересчитать новые координаты размещения главного объекта
  
  //Отобразить главный объект.
  SetConsoleCursorPosition(handle, mainObjPos);
  putchar(cMainObj);

  bool bMoove = false; //Задать движение объекта постоянное или при нажатии клавиши
  int iRapidity = 50; // Задать скорость движения 
  bool bExit = false; // Управляющая переменная выхода из программы
    
  //Основной цикл управления программой
  do {
    caMap[mainObjPos.Y][mainObjPos.X] = cEmpty;

    if(GetAsyncKeyState('Q'))
      bExit = true;
    else if(GetAsyncKeyState('M'))
      bMoove = !bMoove;
    else {
        if(GetAsyncKeyState('W') || GetAsyncKeyState(VK_UP))
	  if (caMap[mainObjPos.Y - 1][mainObjPos.X] == cEmpty)
	    mainObjPos.Y = mainObjPos.Y - 1;
	if(GetAsyncKeyState('S') || GetAsyncKeyState(VK_DOWN))
	  if (caMap[mainObjPos.Y + 1][mainObjPos.X] == cEmpty)
	    mainObjPos.Y = mainObjPos.Y + 1;
	if(GetAsyncKeyState('A') || GetAsyncKeyState(VK_LEFT))
	  if (caMap[mainObjPos.Y][mainObjPos.X - 1] == cEmpty)
	    mainObjPos.X = mainObjPos.X - 1;
	if(GetAsyncKeyState('D')|| GetAsyncKeyState(VK_RIGHT))
	  if (caMap[mainObjPos.Y][mainObjPos.X + 1] == cEmpty)
	    mainObjPos.X = mainObjPos.X + 1;
    }
    
    if (bMoove == false) 
      caMap[mainObjPos.Y][mainObjPos.X] = cMainObj;
    
    //Установить курсор в левый верхний угол экрана
    cursorPos.X = 0;
    cursorPos.Y = 0;
    SetConsoleCursorPosition(handle, cursorPos);

    //Перерисовать карту игрового поля на экране
    for(char *str : caMap)
      printf("%s\n", str);
    
    Sleep(iRapidity);
  } while (!bExit);
  Sleep(300);
  //Перед выходом в консоль вернуть курсору начальные настройки
  SetConsoleCursorInfo(handle, &structCursorInfoTemp);

  return 0;
}
