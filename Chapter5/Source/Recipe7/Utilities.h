#pragma once

#if !defined(__Utilities_H__)
#define __Utilities_H__

// Library Includes
#include <strstream>

// Local Includes

// Types

// Constants

// Prototypes

#define VALIDATE(a) if (!a) return (false)

template<typename T>
std::string ToString(const T& _value)
{
	std::strstream theStream;
	theStream << _value << std::ends;
	return (theStream.str());
}

#endif    // __Utilities_H__
