///////////////////////////////////////////////////////////////////////////////
// project1.hh
//
// The three algorithms specified in the project 1 requirements
// document, plus helper functions.
//
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <algorithm>
#include <cassert>
#include <fstream>
#include <string>
#include <vector>

// Convenient typedef for a vector of strings.
typedef std::vector<std::string> string_vector;

// Load words from the file at the given path. The words vector is
// cleared, and then each word from the file is added to the
// vector. Returns true on success or fale on I/O error.
bool load_words(string_vector& words, const std::string& path) {
	std::string line;
	words.clear();
	std::ifstream myfile(path);

	if (myfile.is_open()) {
		
		while (std::getline(myfile, line)) {
			
			words.push_back(line);
		}
		
		return true;

		myfile.close();
	} else{ 
		std::cerr << "Error opening file, returning false" << std::endl;
		return false;
	}
}

// Return true if string2 is a mirrored copy of string1, or false
// otherwise. In other words, return true if string1 is the reverse of
// string2. Return false when both strings are equal; by this rule,
// "aaa" is not a mirror of "aaa" even though they are technically the
// reverse of each other. Likewise "" is not a mirror of "". This
// function should be in-place, meaning that it only examines string1
// and string2 and never creates another string object.
bool is_mirrored(const std::string& string1, const std::string& string2) {
	std::string string_copy1 = string1;
	std::string string_copy2 = string2;

	if (string_copy1 == string_copy2 || (string_copy1.length() == 0 && string_copy2.length() == 0)) {
		return false;
	}
	std::reverse(string_copy1.begin(), string_copy1.end());
	if (string_copy2.compare(string_copy1) == 0) {
		return true;
	}
	return false;
}

// Return true if alleged_substring can be found as a substring of
// alleged_superstring. For example, "cat" is a substring of
// "catamaran"; "tama" is also a substring of "catamaran". This
// function should be in-place, meaning that it only examines string1
// and string2 and never creates another string object.
bool is_substring(const std::string& alleged_substring,
		  const std::string& alleged_superstring) {
	std::string superstring = alleged_superstring;
	std::string substring = alleged_substring;
	size_t found = superstring.find(substring);
	if (found != std::string::npos) {
		//shows where the first occurance starts, can be commented out or removed
		//std::cout << "First occurance found at " << found << std::endl;
		return true;
	}
  return false;
}

// Return the character that occurs the most times in the given vector
// of strings. The vector must contain at least one character, so that
// the mode is defined. In the event of a tie (i.e. two characters
// have the same count), this function returns the tied character with
// the lesser ASCII code (i.e. the tied character that comes first in
// conventional alphabetical order).
char character_mode(const string_vector& strings) {
	// Create array to keep the count of individual 
	// characters and initialize the array as 0 
	int count[256] = { 0 };
	int max_count = 0;
	char max_char = 0;

	for (auto v : strings) {
		for (int i = 0; i < v.size(); i++) {
			if (++count[v[i]] > max_count) {	//if the current character count is higher
				max_count = count[v[i]];		//than max count of previous character
				max_char = v[i];				//set current character as max
			}
		}
	}
	//visually see the most occurring character and its count
	//std::cout << "MaxChar is: " << maxChar << ", Count: " << max_count << std::endl;
	return max_char;
}

// Return a longest string in the strings vector whose mirror is also
// in the vector. Strings are mirrors of each other in the same sense
// as described above for the is_mirrored(...) function. Either of the
// two mirrored strings may be returned; for example, if the vector
// contains both "cat" and "tac", this function is allowed to return
// either "cat" or "tac". If the vector contains no mirrored strings,
// returns an empty string.
std::string longest_mirrored_string(const string_vector& strings) {
	std::string longest_holding_string = "";

	for (int i = 0; i < strings.size() - 1; i++) {
		for (int j = i++; j < strings.size(); j++) {
			std::string s1 = strings[i];
			std::string s2 = strings[j];
			if (is_mirrored(s1, s2)) {
				if (s1.length() > longest_holding_string.length()) {
					longest_holding_string = s1;
				}
			}
		}
	}

	return longest_holding_string;
}

//Return a vector of length exactly three, containing the longest
//substring trio from the string vector. A substring trio is three
//non-empty, distinct, strings a, b, and c such that a is a substring
//of b, b is a substring of c. This function returns the substring
//trio with the longest total length of a, b, and c. If the input
//vector does not contain a substring trio, return a vector
//containing exactly three empty strings.
string_vector longest_substring_trio(const string_vector& strings) {
	string_vector string_vect{ "", "", "" };
	size_t max_vector_length = 0;
	size_t vector_length = 0;

	for (auto itr_i = strings.begin(); itr_i != strings.end(); itr_i++) {
		for (auto itr_j = strings.begin(); itr_j != strings.end(); itr_j++) {
			for (auto itr_k = strings.begin(); itr_k != strings.end(); itr_k++) {

				vector_length = itr_i->length() + itr_j->length() + itr_k->length();

				//check to see if the indexes are not the same
				if (itr_i->compare(*itr_j) != 0 && itr_i->compare(*itr_k) != 0 && itr_j->compare(*itr_k) != 0) {

					//check to see if the first index is a substring of the next and if the current vector length
					//is greater than the set maximum vector length
					if (is_substring(*itr_i, *itr_j) && is_substring(*itr_j, *itr_k) && vector_length > max_vector_length) {
						for (int i = 0; i < 3; i++) {
							string_vect.pop_back();
						}
						string_vect.push_back(*itr_i);
						string_vect.push_back(*itr_j);
						string_vect.push_back(*itr_k);
					}
				}
			}
		}
	}
return string_vect;
}