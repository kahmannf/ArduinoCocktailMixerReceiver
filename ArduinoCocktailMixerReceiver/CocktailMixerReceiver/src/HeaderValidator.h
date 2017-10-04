/* 
* HeaderValidator.h
*
* Created: 19.09.2017 15:33:27
* Author: Felix
*/


#ifndef __HEADERVALIDATOR_H__
#define __HEADERVALIDATOR_H__


class HeaderValidator
{
//variables
public:
protected:
private:

//functions
public:
	int ReadHeader(int*);
	HeaderValidator();
	~HeaderValidator();
protected:
private:
	HeaderValidator( const HeaderValidator &c );
	HeaderValidator& operator=( const HeaderValidator &c );

}; //HeaderValidator

#endif //__HEADERVALIDATOR_H__
