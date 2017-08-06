#pragma once

#include <string>
#include <fstream>
#include <stdexcept>

inline std::string File_Reader( const std::string& filepath )
{
	std::ifstream file( filepath );
	std::string str;

	if( file.tellg( ) < 0 )
	{
		throw std::runtime_error{ "Unable to read the file. Check filepath." };
	}

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