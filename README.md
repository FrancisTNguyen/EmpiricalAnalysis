# CPSC 335 Fall 2018 - Project 1 - Empirical Analysis

## Group members
Ian Alvarez ian_alvarez23@csu.fullerton.edu

Francis Nguyen lqtruongnguyen@csu.fullerton.edu

Antonio Lopez antonio_lopez@csu.fullerton.edu


## Empirical Analysis

In this project we will implement and analyaze three algorithms. For each algorithm we will:

* Analyze it mathematically to derive a big-O complexity class 

* Implement the algorithm in C++; 

* Analyze the algorithm empirically, by running it for various input sizes and plotting the timing data

* Conclude whether the two analyses agree with each other.

## Implementation 

* words.txt

ASCII text file containing thousands of English words, courtesy of Ubuntu Linux. We will use this file as a source of words in the problem instances we use to gather experimental data.
* project1.hh 

C++ header that defines functions for the three algorithms character_mode, longest_mirrored_string, and longest_substring_trio. In addition, it includes the helper functions load_words, is_mirrored, and is_substring
* project1_test.cc 

C++ program with a main() function that performs unit tests on the functions defined in project1.hh to see whether they work, prints out the outcome, and calculates a score for the code. 
* rubrictest.hh 

Unit test library used for the test program.
* timer.hh 

contains a small Timer class that implements a precise timer using the std::chrono library in C++11.
* experiment.cc 

C++ program with main() function that measures an experimental data point. 
* README.md 

contains a brief description of the project, and a place to write the names and CSUF email addresses of the group members
