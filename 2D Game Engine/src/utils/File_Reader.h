/**
*	@file		File_Reader.h
*	@Author		BouwnLaw
*	@date		07/07/2017
*	@brief		Reads a text file and store it in a string.
*
*	Reads a text file and copy it in a std::string.
*/

#pragma once

// Include STL
#include <string>
#include <fstream>

/**
*	@brief	Reads a text file and copy it into a std::string.
*
*	Reads a text file and copy it into a std::string.
*
*	@param	filepath, location of the file to be read
*
*	@return	std::string
*/
inline std::string File_Reader( const std::string& filepath )
{
	std::ifstream file( filepath );
	std::string str;

	file.seekg( 0, std::ios::end );
	str.reserve( ( unsigned int ) file.tellg() );
	file.seekg( 0, std::ios::beg );

	char c;
	while( file.get( c ) )
	{
		str.push_back( c );
	}

	return str;
}