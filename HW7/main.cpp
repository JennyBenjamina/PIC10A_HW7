#include<iostream>
#include<vector>
#include<string>

#include "Numbers.h"

int main() {

	/* 1. Try getting this to work first: just uncomment the 3 lines below */

	//std::string s("tod");
	//reverseString(s);
	//std::cout << s << '\n';
	//std::cout << twoPower(3);
	/* 2. Trying getting this add function to work and make sure the 2 lines below work. */

	 //std::cout << add("3", "18", 10) << '\n';
	 //std::cout << add("10101010", "11001100", 2) << '\n';

	/* 3. If the above work, write binaryToDecimal and try the block of code below up to but not including item 4.  */

	//std::string b("1111000011");
	//binaryToDecimal(b);
	//std::string a("1111");
	//std::string res = decimalToBinary(a);
	//std::cout << res;

	
	// obtain two binary numbers to add and convert
	std::cout << "Please enter two nonnegative binary integers: ";
	std::string bin1, bin2;
	std::cin >> bin1 >> bin2;

	// convert each to decimal
	std::string bin1AsDecimal = binaryToDecimal(bin1);
	std::string bin2AsDecimal = binaryToDecimal(bin2);

	// compute sum in binary and decimal
	std::string binarySum = add(bin1, bin2, 2);
	std::string decimalSum = add(bin1AsDecimal, bin2AsDecimal, 10);

	// give the results
	std::cout << "Your first number in decimal is: " << bin1AsDecimal  << '\n';
	std::cout << "Your second number in decimal is: " << bin2AsDecimal  << '\n';
	std::cout << "Their sum in binary is: " << binarySum  << '\n';
	std::cout << "Their sum in decimal is: " << decimalSum << "\n\n";

	
	/* 4. Now write decimalToBinary and include the rest of the code */
	
	// obtain two decimal numbers to add and convert
	std::cout << "Now enter two nonnegative decimal integers: ";
	std::string dec1, dec2;
	std::cin >> dec1 >> dec2;

	// convert each to binary
	std::string dec1AsBinary = decimalToBinary(dec1);
	std::string dec2AsBinary = decimalToBinary(dec2);

	// compute sum in binary and decimal
	decimalSum = add(dec1, dec2, 10);
	binarySum = add(dec1AsBinary, dec2AsBinary, 2);

	// give the results
	std::cout << "Your first number in binary is: " << dec1AsBinary  << '\n';
	std::cout << "Your second number in binary is: " << dec2AsBinary  << '\n';
	std::cout << "Their sum in decimal is: " << decimalSum  << '\n';
	std::cout << "Their sum in binary is: " << binarySum  << '\n';

	
	
	return 0;
}