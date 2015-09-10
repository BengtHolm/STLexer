/********************** MODULE-IMPLEMENTATION ***********************

Company..: Danish Technological Institute,
           Department of Computer Technology (Copyright).

Project .: C++ - advanced course

Name ....: Class for a simple menu-system

Type ....: Module implementation

Function : The class Menu implements a simple menusystem. Each
		   item in the menu is associated with a procedure which
		   is call when ever the item is selected.

Design criterion:
		   The Menu is based on the STL for handling multiple menuitems and
		   mapping between menu access key and functions.

Id ......: menu.cpp

Version ! Date   ! Init ! Status ! Version includes
---------------------------------------------------------------------
1.00    ! 960410 ! tso  ! closed ! Menu and menuitem classes
********************************************************************/

#include "figpch.h"
#include "menu.h"


// Implementation on operations on MenuItem

ostream& operator<< ( ostream& o, const MenuItem& p )
{ 
	o<< p.m_cKey << ((p.m_cKey!=' ') ? " - ": "   ") << p.m_pHelpText.c_str();
	return o;
}


void MenuItem::DoIt() const 
{ 
	if( m_pFunction )
		m_pFunction();
	else
		(m_pMenu->*m_pmFunction)();
}
	

// Implementation of operation on Menu

void Menu::AddItem( char key, const string& helptext, void (*Function)() )
{
	MenuItem item( key, helptext, Function, this );
	m_KeyMap[ key ] = m_Items.size();
	m_Items.push_back( item );
}

void Menu::AddItem( char key, const string& helptext, void (Menu::*mFunction)() const )
{
	MenuItem item( key, helptext, mFunction, this );
	
	if( mFunction != &Menu::Separator )
		m_KeyMap[ key ] = m_Items.size();

	m_Items.push_back( item );
}

void Menu::Run()
{
	for( m_Running=1; m_Running; ) 
	{
		cout << ">>";

		char input;
		cin >> input;

		if( m_KeyMap.find( input ) != m_KeyMap.end() )
			m_Items[ m_KeyMap[input] ].DoIt();
		else
			cout << "Unknown Command - type '?' for help\n";
	} 
}
