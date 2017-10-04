/* 
* HeaderValidator.cpp
*
* Created: 19.09.2017 15:33:27
* Author: Felix
*/
/************************************************************************/
/* HEADER STRUCTURE:                                                    */
/*																		*/
/* 8 Byte:																*/
/*																		*/
/* KAFACMRH	(Kahmann Felix Arduino Cocktail Mixer Header)				*/
/*																		*/
/* Hex:																	*/
/*																		*/
/* 4b 41 46 41 43 4d 52 48												*/
/*																		*/
/* 1 Byte: Following Data Length										*/
/*																		*/
/* undefined in template												*/
/************************************************************************/

// default constructor
HeaderValidator::HeaderValidator()
{
	header_template = int[8];

	header_template[0] = 0x4b;
	header_template[1] = 0x41;
	header_template[2] = 0x46;
	header_template[3] = 0x41;

	header_template[4] = 0x43;
	header_template[5] = 0x4d;
	header_template[6] = 0x52;
	header_template[7] = 0x48;

} //HeaderValidator

// default destructor
HeaderValidator::~HeaderValidator()
{
} //~HeaderValidator

class HeaderValidator
{	
	int header_template[];
	public:
		int ReadHeader(int*);
};

int HeaderValidator::ReadHeader(int header[])
{
	for (int i = 0; i < 8; i++)
	{
		if(header[i] != header_template[i])
			return -1;
	}

	return header[8];
}