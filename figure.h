/********************** MODULE-SPECIFICATION ************************

Company .: Danish Technological Institute,
           Department of Computer Technology (Copyright).

Project .: C++ - advanced course.

Name ....: Figure Module for excersize 9, 10 & 10a

Type ....: Class module

Function : Declares class CFigure and its three descendants
		   CRectangle, CTriangle and CCircle. All classes are 
		   streamable, and is able to compute the area of the corresponding 
		   figure. Each class has a Scale function, which performs a linear 
		   inflate on the figure.

Design criterion: Simple inheritance hierarchy designed for use by STL templates

Id ......: figure.h

Version ! Date   ! Init ! Status ! Version includes
---------------------------------------------------------------------
1.00    ! 960412 ! OFS  ! closed !
---------------------------------------------------------------------
1.01    ! 990224 ! KVE  ! closed ! Adapted to VC++ 6.0
		!		 !      !        ! Problem descriped in Micro$oft 
		!		 !      !        ! kb article Q192539
---------------------------------------------------------------------
1.02    ! 990928 ! RMA  ! closed ! Adapted to using standard 
        !        !      !        ! libraries
********************************************************************/


#include <iostream>

using namespace std;

#define WORKAROUND // Micro$oft kb Q192539 
#ifdef WORKAROUND
	class CFigure;
	ostream& operator<< ( ostream& o, const CFigure& fig );
	
	class CRectangle;
	istream& operator>> ( istream& i, CRectangle& r );

	class CTriangle;
	istream& operator>> ( istream& i, CTriangle& t );

	class CCircle;
	istream& operator>> ( istream& i, CCircle& c );
#endif


class CFigure
{
public:
	/* Area
	input ...: -
	function : virtual function for area computation
	output ..: double - area of figure
	*/
	virtual double Area() const = 0;

	/* Scale
	input ...: double 
	function : virtual scaling function multiplying the linear
			   dimensions of the figure by scalingfactor	
	output ..: -
	*/
	virtual void Scale( double scalingfactor ) = 0;
	
	/* Format
	input ...: -
	function : virtual function for text format of figure 
			   dimension
	output ..: String representation of figure
	*/
	virtual string Format() const = 0;
	
	/* clone
	input ...: -
	function : virtual function for cloning of figure
			   i.e. creating a copy og identical type	 
	output ..: CFigure-derivation of samme type as this
	*/
	virtual CFigure* clone() const = 0;
	
	/* operator<<
	input ...: ostream and figure
	function : friend function to perform output streaming of
			   CFigure. Invokes Format.	
	output ..: ostream
	*/
	friend ostream& operator<< ( ostream& o, const CFigure& fig );
	bool operator< ( const CFigure& )  const { return true;}
	bool operator== ( const CFigure& )  const { return true;}
};


class CRectangle : public CFigure
{
public:
	/* CRectangle
	input ...: double Height and double Width.
	function : Constructs a CRectangle instance of the given dimensions
	output ..: -
	*/
	CRectangle( double h, double w ) : m_Height( h ), m_Width( w )  { } 
	CRectangle() { }

	CFigure* clone() const;  
	/* Area
	input ...: -
	function : Area computation. Area = Width*Height
	output ..: double - area of Rectangle
	*/
	double Area()	 const;
	void Scale( double s );
	/* Format
	input ...: -
	function : virtual function for text format of figure 
			   dimension
	output ..: String representation of Rectangle. Format
			   R 12.3 14.4
	*/
	string Format() const;
	bool operator< ( const CRectangle& )  const { return true; }
	
	friend istream& operator>> ( istream& i, CRectangle& r );

private:
	double m_Height, m_Width;
};

class CTriangle : public CFigure
{
public:
	/* CRectangle
	input ...: double Height and double Width.
	function : Constructs a CTriangle instance of the given dimensions
	output ..: -
	*/
	CTriangle( double h, double w ) : m_Height( h ), m_Width( w )  { } 
	CTriangle() { }

	CFigure* clone() const;
	/* Area
	input ...: -
	function : Area computation. Area = Width*Height/2
	output ..: double - area of Rectangle
	*/
	double Area()	const;
	void Scale( double s );
	/* Format
	input ...: -
	function : virtual function for text format of figure 
			   dimension
	output ..: String representation of Triangle. Format
			   T 12.3 14.4
	*/
	string Format() const;
	
	bool operator< ( const CTriangle& ) const { return true;}
	bool operator== ( const CTriangle& ) const { return true;}
	friend istream& operator>> ( istream& i, CTriangle& t );
private:
	double m_Height, m_Width;
};

class CCircle : public CFigure
{
public:
	/* CCircle
	input ...: double Radius.
	function : Constructs a CRadius instance of the given radius
	output ..: -
	*/
	CCircle( double r ) : m_Radius( r )  { } 
	CCircle() { }

	CFigure* clone() const;
	double Area()	const;
	void Scale( double s );
	/* Format
	input ...: -
	function : virtual function for text format of figure 
			   dimension
	output ..: String representation of Triangle. Format
			   C 12.3 
	*/
	string Format() const;

	bool operator< ( const CCircle& )  const { return true;}
	bool operator== ( const CCircle& )  const { return true;}
	friend istream& operator>> ( istream& i, CCircle& c );

private:
	double m_Radius;
};
