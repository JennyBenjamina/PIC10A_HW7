#include "Numbers.h"

#include<stdexcept>
#include<string>
#include<vector>
#include<iostream>



//this function changes a character to unsigned char
unsigned char charToDigit(char c) {
	return c - '0'; //return the digit value of char
}

//this function changes a digit to a character
char digitToChar(unsigned char u) {
	return u + '0'; //return the char value of digit
}


//This function computes 2 to a given nonnegative integer power with the output as an std::string, in base 10
std::string twoPower(size_t pow) {

	std::string result = "1"; //declare the starting point
	for (size_t i = 0; i < pow; ++i) {//loop through to get 2 to the pow
		result = add(result, result, 10);//add result by result and update result
	}


	return result;//return the result
}


//this function returns a reversed string
void reverseString(std::string& str) {
	size_t len = str.size() - 1; //get string length
	char temp; //declare temp to hold a character
	
	for (size_t i = 0; i < len; ++i) {
		temp = str[i]; //store the i index of str to temp
		str[i] = str[len]; //store the len index of str to i index of str
		str[len] = temp; //assign the temp to the len index of str
		--len; //decrement len
	}
	
}


//This function adds two unsigned integer types, represented as strings, given a base to work in
std::string add(const std::string& first, const std::string& second, unsigned char base) {
	size_t carry = 0; //declare carry 
	size_t some_num = 0; //declare some_num to hold total % base value
	std::string result = ""; //declare result to return the summed result
	size_t total = 0; //declare total of the two integers and the carry
	char some_num_char; //declare the variable that will append to the result string 

	std::vector <std::string> vec; //declare a vector that will hold the two number strings
	isSmallerThan(first, second, vec); //call isSmallerThan function to find out if the differences in strings' lengths

	for (size_t index = vec[0].size() - 1; index != -1; --index) {//loop through to do addition

		int nu1 = charToDigit(vec[0][index]);//declare a digit of the first number. (starting from the end)
		int nu2 = charToDigit(vec[1][index]);//declare a digit of the second number. (starting from the end)

		total = carry + nu1 + nu2; //add the digits and carry to get the total
		some_num = total % base; //use modolus operator to get the remainder of the specific base(2 or 10).
		some_num_char = digitToChar(some_num); //change number to char

		result += some_num_char; //append the char to string
		carry = total / base; //divide the base by the total to get the carry

		if ((index == 0) && (carry == 1)) {//add the carry of the last part of the addition
			result += "1"; //append '1' to the result
		}
	}

	reverseString(result);//reverse the string so the output is correct
	return result; //return the string


}

//This function takes in a binary number and displays its decimal number
std::string binaryToDecimal(const std::string& binaryNum) {
	size_t numLen = binaryNum.size() - 1; //declare the size of binary number
	std::string decimal = ""; //declare decimal
	const int base = 10; //initialize base to 10 because we are converting binary to decimal
	const char one = '1'; //declare the 1 that is computed
	const int val_one = 1; //declare and define val_one to indicate 1
	std::vector<std::string> digits = {}; //vector to store the numbers to add up

	for (size_t i = 0; i <= numLen; ++i) { //loop through to make digits vector
		if (binaryNum[i] == one) { //if binaryNum has '1', calculate the power of two and push into digits vector
			digits.push_back(twoPower(numLen - i)); //pushing into digits vector
		}
	}

	if (digits.size() == val_one) {//if the digits vector has one element
		return digits[0];// return the only element in digit vector
	}

	const int zero = 0; //declare and define zero value
	std::vector<std::string> holder = {}; //declare an empty vector to use as a holder
	while (digits.size() != val_one && holder.size() != val_one) { //loop through while the digits vector and the holder vector's size is not 1.
		if (digits.size() == zero) { //if the digits vector did not hold any elements
			return "0"; //return "0".
		}

		size_t j = digits.size() - val_one; //declare a variable to iterate through a vector
		const int two = 2; //declare a variable for the value two
		if (digits.size() % two == zero) {//if there is an even number of elements

			for (size_t i = 0; i < j; ++i) {//loop through the digits vector
				holder.push_back(add(digits[i], digits[j], base)); //push the sum of the digits' elements to the holder vector
				--j;//decrement j
			}
			digits.clear();//clear the digits vector
		}
		else {//odd number of elements
			for (size_t i = 0; i < j; ++i) {//loop through the digits vector
				holder.push_back(add(digits[i], digits[j], base));//push the sum of the digits' elements to the holder vector
				--j;//decrement j
			}
			holder.push_back(digits[j]);//push the remaining digits' element into the holder vector
			digits.clear();//clear the digits vector
		}

		if (holder.size() % two == zero) { //if the size of the holder vector is an even number
			size_t k = holder.size() - val_one; //declare and instantiate the variable k to iterate through holder

			for (size_t i = 0; i < k; ++i) {//loop through holder
				digits.push_back(add(holder[i], holder[k], base));//push the sum of the holders' elements
				--k;//decrement k
			}
			holder.clear();//clear the holder vector
		}
		else {//if the holder vector is an odd size
			size_t k = holder.size() - val_one;//declare and instantiate the variable that will iterate through holder

			for (size_t i = 0; i < k; ++i) {//loop through holder
				digits.push_back(add(holder[i], holder[k], base)); //push in the sum of the holder elements
				--k;//decrement k
			}
			digits.push_back(holder[k]);//push in the remaining holder element
			holder.clear();//clear holder vector
		}

		if (holder.size() == val_one) {//if the size of holder vector is 1
				return holder[0]; //return the holder element
		}
		else if(digits.size() == 1){//if the size of the digits vector is 1
				return digits[0]; //return the digits element
		}
	}
}

//this function displays the binary value of the decimal input
std::string decimalToBinary(const std::string& decimal) {

	size_t maxPower = 0; //declare counter variable
	while (lessThanOrEqual(twoPower(maxPower), decimal)) {//loop to find the highest power of two that is less than the decimal value
		++maxPower;//increment per loop
	}

	size_t pow = maxPower - 1; //declare and define pow value
	std::string binary = ""; //declare binary string
	const char one = '1'; //declare and define the char one 
	const char zero = '0'; //declare and define the char two


	std::string number = decimal; //copy decimal value to a string variable called number
	while (pow != -1) {//loop through until pow reaches the value 0

		const int base = 10; //declare the base 
		if (lessThanOrEqual(twoPower(pow), number)) {//condition if 2 to the power of pow is less than the current number
			std::string res = subtract(number, twoPower(pow), base); //subtract two to the power of pow from number of base 10
			binary += one; //append a '1' to binary variable 
			number = res;  //assign number variable to the difference of number and two to the power of pow
		}
		else {
			binary += zero; //if the if condition is not met, append a '0'
		}
		--pow;//decrement pow

	}

	return binary; //return the string
}



/**
If you are reading this, you may be puzzled as to why subtrahend is not passed as reference to const.
This is one of those few exceptions: we will need to make a copy of subtrahend anyway in order to modify
it in this function. It would actually be less efficient to pass by reference to const and then make a copy
inside the function. We just make a copy straightaway. Unless you really understand this deeply, do not
pass an object by value.
*/
std::string subtract(const std::string& minuend, std::string subtrahend, unsigned char base) {

	// ensure subtrahend has as many digits as minuend
	if (subtrahend.size() < minuend.size()) {
		subtrahend = std::string(minuend.size() - subtrahend.size(), '0') + subtrahend;
	}

	/* We first wish to modify each digit of subtrahend by turning it into its complement.
	The digit d should be converted into (base-1-d).
	*/
	for (auto& c : subtrahend) { // for each char in the subtrahend string
		// need to convert the char to digits, do the arithmetic, and go back to char!
		c = digitToChar((base - 1) - charToDigit(c));
	}

	//Subtraction can be done by addition, now. We first add 1 to the subtrahend.
	subtrahend = add(subtrahend, "1", base);

	// now, add the minuend and updated subtrahend
	std::string difference = add(minuend, subtrahend, base);

	/*
	The resulting number will always have a superfluous digit at index 0 that we do not want.
	In addition, we wish to move past all the zeros at the start.
	*/
	size_t zeroEnd = 1; // index to track where zeros end

	// size of the difference  
	const size_t diff_sz = difference.size();

	// while index still within bounds (checked first) and there are still zeros
	while ((zeroEnd < diff_sz) && (difference[zeroEnd] == '0')) {
		++zeroEnd; // increase the index
	}

	if (zeroEnd == diff_sz) { // if zeroEnd is out of range then it was all 0's
		return "0";
	}

	return difference.substr(zeroEnd); // return the truncated number going from first nonzero to end of string
}


//this function checks if the two strings are less than or equal to each other
bool lessThanOrEqual(const std::string& first, const std::string& second) {
	if (first == second) { // if the two strings are equal, then they are equal!
		return true;
	}

	/* We need to look at their lengths: a longer number in proper format (no 0's at beginning)
	will always be larger than a number that is shorter */

	if (first.size() < second.size()) { // second longer
		return true; // so first < second
	}
	else if (second.size() < first.size()) { // first longer
		return false; // so first > second
	}
	else { // If the numbers have the same length, we can compare digit by digit because the chars 0-9 are ordered
		return first < second;
	}
}



//this function checks to see if the two strings are the same size or not. If not, prepend '0's to make them equal size
void isSmallerThan(std::string first, std::string second, std::vector<std::string>& vec) {
	if (first.size() <= second.size()) { //check to see if the first string is smaller than the second or equal to each other
		size_t diff = second.size() - first.size(); //get the difference in size

		for (size_t i = 0; i < diff; ++i) { //if there is a difference, prepend '0's to the first string
			first.insert(0, 1, '0'); //prepend '0's
		}

		vec.insert(vec.begin(), first); //insert string to vector
		vec.insert(vec.end(), second); //insert string to vector
	}
	else if (second.size() < first.size()) { //check to see if second string size is smaller than the first
		size_t diff = first.size() - second.size(); //check to see if there is a difference

		for (size_t i = 0; i < diff; ++i) { //loop through to prepend '0's
			second.insert(0, 1, '0'); //prepend '0's
		}

		vec.insert(vec.begin(), second); //insert string to vector
		vec.insert(vec.end(), first); //insert string to vector
	}

}

//this function returns a string version of the inputted size_t
std::string changeToStr(size_t pow) {
	std::string power = "";//declare string to hold the return variable

	while (pow > 0) {
		const int base = 10; //declare the base
		int first_digit = pow % base; //this looks at the first digit in the ones place

		pow /= base; //this truncates the pow variable
		power += digitToChar(first_digit); //appending the first_digit to the returning variable
	}
	reverseString(power); //reverse the string

	return power;
}