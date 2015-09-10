/********************** MAIN MODULE ***********************

Company .: Danish Technological Institute,
           Department of Computer Technology (Copyright).

Project .: C++ - advanced course.

Name ....: Implementation Module containind solution
		   for excersize 9

Type ....: Class module

Function : -

Id ......: main.cpp

Version ! Date   ! Init ! Status ! Version includes
---------------------------------------------------------------------
1.00    ! 960412 ! OFS  ! closed !
********************************************************************/

#include "figpch.h"
#include "menu.h"
#include "figure.h"

#define CIRCLE_FILE		"circle.fig"
#define RECTANGLE_FILE	"rectang.fig"
#define TRIANGLE_FILE	"triang.fig"


int main()
{
	cout << "Hello \n";

	Menu MyMenu; 

	MyMenu.AddItem( ' ', "", MenuSeparator );
	MyMenu.AddItem( 'x', "Exit", MenuExit );
	MyMenu.AddItem( '?', "Help", MenuPrintHelp );

	MyMenu.Run();

	return 0;
}