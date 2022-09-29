#ifndef _NUMBERS_
#define _NUMBERS_

#include<string>
#include<cstddef>

#include<vector>

/**
This function takes a single character and returns an unsigned char for its value from 0-9

@param c the character to convert
@return its value from 0-9
*/
unsigned char charToDigit(char c);

/**
This function converts an unsigned char from 0-9 and returns a char '0' to '9'

@param u the unsigned char to convert
@return its digit representation as a char
*/
char digitToChar(unsigned char u);

/**
This function computes 2 to a given nonnegative integer power with the output as an std::string, in base 10

@param pow the power
@return 2 to that power
*/
std::string twoPower(size_t pow);

/**
This function reverses the given string

For example: "string" would turn into "gnirts"

@param str the string to be reversed
*/
void reverseString(std::string& str);

/**
This function adds two unsigned integer types, represented as strings, given a base to work in.
The return format will be a sum, computed in whatever base is specified, where 2 <= base <= 10.

For example,
std::string sum1 = add("116", "14", 10); // sum1 == "130"
std::string sum2 = add("11", "10", 2); // sum == "101"

@param first the first addend
@param second the second addend
@param base the base being used: from 2-10

@return the sum, num1+num2 in the base
*/
std::string add(const std::string& first, const std::string& second, unsigned char base);


/**
This function subtracts two unsigned integer types, represented as strings, given a base to work in.
The return format will be a difference, computed in whatever base is specified, with as few digits as possible,
i.e., "0010" would be returned as "10", etc. We require 2 <= base <= 10.

The result is not defined if the minuend is less than the subtrahend!

For example,
std::string diff1 = subtract("130", "14", 10); // diff1 == "116"
std::string diff2 = subtract("101", "10", 2); // diff == "11"
subtract("30", "108", 10); // Do not do this!

@param minuend the term being subtracted from
@param subtrahend the value being subtracted
@param base the base being used

@return the difference, minuend-subtrahend in the base given
*/
std::string subtract(const std::string& minuend, std::string subtrahend, unsigned char base);


/**
This function determines whether two string representations of unsigned integers satisfy <= numerically

For example,
lessThanOrEqual("12", "108"); // true
lessThanOrEqual("100", "100"); // true
lessThanOrEqual("19", "6"); // false

@param first the first number
@param second the second number

@return whether first <= second as unsigned integer types
*/
bool lessThanOrEqual(const std::string& first, const std::string& second);


/**
This function determines if string sizes are equal or unequal. If not equal, change prepend '0's to the shorter string

@param first_num the first number to compare
@param sec_num the second number to compare
@param vec vector that holds the strings
*/
void isSmallerThan(std::string first, std::string second, std::vector<std::string>& vec);

/**
This function accepts a string representation of a nonnegative integer in binary and outputs its decimal representation.

@param binaryNum is the binary number that converts to its decimal representation
*/
std::string binaryToDecimal(const std::string& binaryNum);

/**
This function accepts a string representation of a nonnegative integer in decimal and outputs its binary representation

@param decimal is the decimal number that converts to a binary representation
*/
std::string decimalToBinary(const std::string& decimal);

std::string changeToStr(size_t pow);

#endif
