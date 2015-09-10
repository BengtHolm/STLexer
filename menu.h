/********************** MODULE-SPECIFICATION ************************

Company .: Danish Technological Institute,
	       Department of Computer Technology (Copyright).

Project .: C++ - advanced course.

Name ....: Class for a simple menu-system

Type ....: Class module

Function : The class Menu implements a simple menusystem. Each
		   item in the menu is associated with a procedure which
		   is call when ever the item is selected.

Design criterion:
		   The Menu is based on the STL for handling multiple menuitems and
		   mapping between menu access key and functions.

Id ......: menu.h

Version ! Date   ! Init ! Status ! Version includes
---------------------------------------------------------------------
1.00    ! 960410 ! tso  ! closed ! Menu and menuitem classes
---------------------------------------------------------------------
1.01    ! 990224 ! KVE  ! closed ! Adapted to VC++ 6.0
		!		 !      !        ! Problem descriped in Micro$oft 
		!		 !      !        ! kb article Q192539
---------------------------------------------------------------------
1.02    ! 990928 ! RMA  ! closed ! Adapted to using standard 
        !        !      !        ! libraries
********************************************************************/

#ifndef _MENU_H_
#define _MENU_H_


using namespace std;

#define WORKAROUND // Micro$oft kb Q192539 
#ifdef WORKAROUND
	class MenuItem;
	ostream& operator<< ( ostream& o, const MenuItem& p );	   
#endif

class Menu;

// Class to handle a menu item

class MenuItem
{
public:
	MenuItem( const char key, const string& HelpText, void(*pFunction)(), Menu* menu )
		: m_cKey( key ), m_pHelpText( HelpText ), m_pMenu( menu ), m_pFunction( pFunction ), m_pmFunction( 0 ) { };

	MenuItem( const char key, const string& HelpText, void (Menu::*pmFunction)() const, Menu* menu)
		: m_cKey( key ), m_pHelpText( HelpText ), m_pMenu( menu ), m_pmFunction( pmFunction ), m_pFunction( 0 ) { };
	MenuItem()	{ };
	// Default copy constructor is OK
	// Default assignment operator is OK
	bool operator< ( const MenuItem& mi ) const { return mi.m_cKey < m_cKey; }
	bool operator== ( const MenuItem& mi ) const { return mi.m_cKey == m_cKey; }
	char Key()	const { return m_cKey; }
	void DoIt()	const ;
	friend ostream& operator<< ( ostream& o, const MenuItem& p );

private:
	string  m_pHelpText;					// The menu help text
	char    m_cKey;							// The key to access the function
	void	(*m_pFunction)();				// The function to be performed
	void	(Menu::*m_pmFunction)() const ;	// The function to be performed
	Menu*   m_pMenu;						// Poiner to menu containing the item
};


class Menu
{
public:
	/* AddItem
	input ...: key to activate menuitem
			   helptext for the menuitem
			   pointer to function
	function : Add menuitem to menu
	output ..: -
	*/
	void AddItem( char key, const string& helptext, void (*Function)() );

	/* AddItem
	input ...: key to activate menuitem
			   helptext for the menuitem
			   Special Command
	function : Add menuitem to menu
	output ..: -
	*/

	void AddItem( char key, const string& helptext, void (Menu::*mFunction)() const );

	/* Run
	input ...: -
	function : Activate menu
	output ..: -
	*/
	void Run();

	/* PrintHelp
	input ...: -
	function : Print a list of commands in the menu
	output ..: -
	*/
	void PrintHelp() const
	{	
		copy( m_Items.begin(), m_Items.end(), ostream_iterator<MenuItem>( cout, "\n" ) );
		
	}
		
	/* Done
	input ...: -
	function : Deactivate menu
	output ..: -
	*/
    void Exit() const
	{
		m_Running=0;
	}

	void Separator() const
	{
	}

private:
	typedef map<char , int> MenuMap;
	vector<MenuItem> m_Items;		// Vector of menu items
	MenuMap m_KeyMap;				// Map for access keys
	mutable int m_Running;			// Flag idicating menu active

};

#define MenuExit &Menu::Exit
#define MenuSeparator &Menu::Separator
#define MenuPrintHelp &Menu::PrintHelp

#endif
