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

vector<CTriangle>  Tria_List;
vector<CCircle>    Circ_List;
vector<CRectangle> Rect_List;

void FileRead()
{
	ifstream r_file( RECTANGLE_FILE );
	while( !r_file.eof() )
	{
		CRectangle rect;
		r_file >> rect;
		if( r_file ) Rect_List.push_back( rect );
	}
	cout << "Rectangles read.\n";

	ifstream t_file( TRIANGLE_FILE );
	while( !t_file.eof() )
	{
		CTriangle tri;
		t_file >> tri;
		if( t_file ) Tria_List.push_back( tri );
	}
	cout << "Triangles read.\n";

	ifstream c_file( CIRCLE_FILE );
	while( !c_file.eof() )
	{
		CCircle cir;
		c_file >> cir;
		if( c_file ) Circ_List.push_back( cir );
	}
	cout << "Circles read.\n";
}

void ListAll()
{
	for( vector<CRectangle>::iterator r_iter = Rect_List.begin();
	         r_iter < Rect_List.end(); ++r_iter )
		cout << *r_iter << endl;

	for( vector<CTriangle>::iterator t_iter = Tria_List.begin();
			t_iter < Tria_List.end(); ++t_iter )
		cout << *t_iter << endl;

	for( vector<CCircle>::iterator c_iter = Circ_List.begin();
			c_iter < Circ_List.end(); ++c_iter )
			cout << *c_iter << endl;
}

void ShowBig()
{
	for( vector<CRectangle>::iterator r_iter = Rect_List.begin(); r_iter < Rect_List.end(); ++r_iter )
		if( r_iter->Area() > 5.0 )
			cout << *r_iter << endl;

	for( vector<CTriangle>::iterator t_iter = Tria_List.begin(); t_iter < Tria_List.end(); ++t_iter )
		if( t_iter->Area() > 5.0 )
			cout << *t_iter << endl;

	for( vector<CCircle>::iterator c_iter = Circ_List.begin(); c_iter < Circ_List.end(); ++c_iter )
		if( c_iter->Area() > 5.0 )
			cout << *c_iter << endl;
}

void AddCircle()
{
	cout << "Enter Data for new circle in following format: 'C radius'" << "\n";
	CCircle newCirc;
	cin >> newCirc;
	Circ_List.push_back( newCirc );
}

void AddRectangle()
{
	cout << "Enter Data for new rectangle in following format: 'R height width'" << "\n";
	CRectangle newRect;
	cin >> newRect;
	Rect_List.push_back( newRect );
}

void AddTriangle()
{
	cout << "Enter Data for new triangle in following format: 'T height width'" << "\n";
	CTriangle newTria;
	cin >> newTria;
	Tria_List.push_back( newTria );
}

void AddMenu()
{
    Menu AddMenu;
	AddMenu.AddItem( 'c', "Add new circle", AddCircle );
	AddMenu.AddItem( 'r', "Add new rectangle", AddRectangle );
	AddMenu.AddItem( 't', "Add new triangle", AddTriangle );
	AddMenu.AddItem( ' ', "", MenuSeparator );
	AddMenu.AddItem( 'x', "Exit", MenuExit );
	AddMenu.AddItem( '?', "Help", MenuPrintHelp );

	AddMenu.Run();
}

static vector<CRectangle>::iterator iter;

void FigurePrint()
{
	if( iter == Rect_List.end() )
		cout << "end" << endl;
	else
		cout << *iter << endl;
}

void FigureFirst()
{
	iter = Rect_List.begin();
	FigurePrint();
}

void FigureNext()
{
	iter++;
	if( iter == Rect_List.end() )
		--iter;
	FigurePrint();
}

void FigurePrevious()
{
	if( iter != Rect_List.begin() )
		--iter;
	FigurePrint();
}

void FigureDelete()
{
	if( iter != Rect_List.end() )
		Rect_List.erase( iter );
	FigurePrint();
}

void MaintainRect()
{
    Menu MaintainMenu;
	FigureFirst();
	MaintainMenu.AddItem( 'f', "First", FigureFirst );
	MaintainMenu.AddItem( 'n', "Next", FigureNext );
	MaintainMenu.AddItem( 'p', "Previous", FigurePrevious );
	MaintainMenu.AddItem( 'd', "Delete", FigureDelete );
	MaintainMenu.AddItem( 'q', "Print current", FigurePrint );
	MaintainMenu.AddItem( ' ', "", MenuSeparator );
	MaintainMenu.AddItem( 'x', "Exit", MenuExit );
	MaintainMenu.AddItem( '?', "Help", MenuPrintHelp );

	MaintainMenu.Run();
}


int main()
{
	cout << "Hello \n";

	Menu MyMenu; 

	MyMenu.AddItem( 'r', "Read from files", FileRead );
	MyMenu.AddItem( 'l', "List all", ListAll );
	MyMenu.AddItem( 's', "Show big", ShowBig );
	MyMenu.AddItem( 'a', "Add new item",AddMenu );
	MyMenu.AddItem( 'm', "Maintain Rects",MaintainRect );

	MyMenu.AddItem( ' ', "", MenuSeparator );
	MyMenu.AddItem( 'x', "Exit", MenuExit );
	MyMenu.AddItem( '?', "Help", MenuPrintHelp );

	MyMenu.Run();

	return 0;
}
