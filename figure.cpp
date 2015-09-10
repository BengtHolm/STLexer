/********************** MODULE-IMPLEMENTATION ************************

Company .: Danish Technological Institute,
           Department of Computer Technology (Copyright).

Project .: C++ - advanced course.

Name ....: Figure Module for excersize 9, 10 & 10a

Type ....: Module Implementation

Function : Implements class CFigure and its three descendants
		   CRectangle, CTriangle and CCircle. All classes are 
		   streamable, and is able to compute the area of the corresponding 
		   figure. Each class has a Scale function, which performs a linear 
		   inflate on the figure.

Design criterion: Simple inheritance hierarchy designed for use by STL templates

Id ......: figure.cpp

Version ! Date   ! Init ! Status ! Version includes
---------------------------------------------------------------------
1.00    ! 960412 ! OFS  ! closed !
********************************************************************/

#include "figpch.h"
#include "figure.h"


const double PI=3.1415927;

ostream& operator<< ( ostream& o, const CFigure& fig )
{ 
	return o << fig.Format().c_str(); 
}

CFigure* CRectangle::clone() const  
{ 
	return new CRectangle( *this ); 
}

double CRectangle::Area()	 const	
{ 
	return m_Height*m_Width; 
}

void CRectangle::Scale( double s )
{
	m_Height *= s; m_Width *= s; 
}

string CRectangle::Format() const	
{
	ostringstream str;
	str << "R " << m_Height << " " << m_Width;
	return str.str();
}

istream& operator>> ( istream& i, CRectangle& r )
{
	char dummy;
    return i >> dummy >> r.m_Height >> r.m_Width;
}

void CTriangle::Scale( double s )
{ 
	m_Height *= s; 
	m_Width *= s; 
}

CFigure* CTriangle::clone() const 
{ 
	return new CTriangle( *this ); 
}

double CTriangle::Area()	const   
{ 
	return m_Height*m_Width/2; 
}

string CTriangle::Format() const	
{
	ostringstream str;
	str << "T " << m_Height << " " << m_Width;
	return str.str();
}

istream& operator>> ( istream& i, CTriangle& t )
{
	char dummy;
	return i >> dummy >> t.m_Height >> t.m_Width;
}

void CCircle::Scale( double s )
{
	m_Radius *= s; 
}

CFigure *CCircle::clone() const 
{ 
	return new CCircle( *this ); 
}

double CCircle::Area()	const	
{ 
	return PI * m_Radius * m_Radius; 
}

string CCircle::Format() const	
{
	ostringstream str;
	str << "C " << m_Radius;
	return str.str();
}

istream& operator>> ( istream& i, CCircle& c )
{
	char dummy;
	return i >> dummy >> c.m_Radius;
}
