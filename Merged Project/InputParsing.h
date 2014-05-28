#pragma once
#include <vector>
#include <string>

using namespace std;

/*
ParseInput
Input: string to be parsed
Output: vector containing the first word and the rest of the input string
Usage: Call this function to split a string into two parts. The first is a single word, the second is the rest of the string (if there is anything left).
The function does not split the rest of the string into words as this game only allows for 1 or 2-word input.
Example: ParseInput("kill evil ogre")
		-returns a vector containing two strings: "kill" and "evil ogre"
Example: ParseInput("north")
		-returns a vector containing one string: "north"
*/
vector<string> ParseInput(string p_input);