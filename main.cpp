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

	copy( istream_iterator<CRectangle>( r_file ),
				  istream_iterator<CRectangle>(),
					  back_inserter( Rect_List ) );

	ifstream t_file( TRIANGLE_FILE );

	copy( istream_iterator<CTriangle>( t_file ),
			      istream_iterator<CTriangle>(),
					  back_inserter( Tria_List ) );

	ifstream c_file( CIRCLE_FILE );

	copy( istream_iterator<CCircle>( c_file ),
			      istream_iterator<CCircle>(),
					  back_inserter( Circ_List ) );

		cout << "Files read.\n";
}

void FileWrite()
{
	ofstream r_file( RECTANGLE_FILE, ios::trunc );
	copy( Rect_List.begin(), Rect_List.end(),
			ostream_iterator<CRectangle>( r_file, "\n" ) );

	ofstream t_file( TRIANGLE_FILE, ios::trunc );
	copy( Tria_List.begin(), Tria_List.end(),
			ostream_iterator<CTriangle>( t_file, "\n" ) );

	ofstream c_file( CIRCLE_FILE, ios::trunc );
	copy( Circ_List.begin(), Circ_List.end(),
			ostream_iterator<CCircle>( c_file, "\n" ) );

	cout << "Files written.\n";
}

class AreaComp
{
public:
	AreaComp( double l ) : limit( l ) { }
	bool operator() ( const CFigure& fig ) const {  return fig.Area() < limit; }

private:
	double limit;
};

void ShowBig()
{
	remove_copy_if( Rect_List.begin(), Rect_List.end(),
		ostream_iterator<CRectangle>( cout, "\n" ),
			    AreaComp( 5.0 ) );
	remove_copy_if( Tria_List.begin(), Tria_List.end(),
		ostream_iterator<CTriangle>( cout, "\n" ),
			    AreaComp( 5.0 ) );
	remove_copy_if( Circ_List.begin(), Circ_List.end(),
		ostream_iterator<CCircle>( cout, "\n" ),
			    AreaComp( 5.0 ) );
}



void ListAll()
{
	copy( Rect_List.begin(), Rect_List.end(), ostream_iterator<CRectangle>( cout, "\n" ) );
	copy( Tria_List.begin(), Tria_List.end(), ostream_iterator<CTriangle>( cout, "\n" ) );
	copy( Circ_List.begin(), Circ_List.end(), ostream_iterator<CCircle>( cout, "\n" ) );
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
	MyMenu.AddItem( 'w', "Write to files", FileWrite );

	MyMenu.AddItem( ' ', "", MenuSeparator );
	MyMenu.AddItem( 'x', "Exit", MenuExit );
	MyMenu.AddItem( '?', "Help", MenuPrintHelp );

	MyMenu.Run();

	return 0;
}
