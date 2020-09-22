# CPSC350Assignment1
Computes basic statistics for a list of DNA strings

Patrick Polcuch
2348668
polcuch@chapman.edu

This project did not use any data structures. The assignment prompt is at the end of this file. I referenced stack overflow for using rand() because the documentation wasnt very helpful. I used the documentation for the string methods because this is my first time coding in c++.


-----------Prompt-------------------------------------
For this assignment, you will build a simple analysis program that will compute basic statistics
for a list of DNA strings. Your program should work as follows:
-The program will accept as a command line argument the name of a text file that will contain an
arbitrary list of DNA strings. (ie. ~/assign1/filename.txt) DNA strings consist of a sequence of
nucleotides (A,C,T, or G). There will be 1 string per line of the file. No guarantees on
capitalization.
-The program will then compute the sum, mean, variance, and standard deviation of the length of
the DNA strings in the list. It will also compute the relative probability of each nucleotide
(A,C,T, or G), as well as the probability of each nucleotide bigram (AA, AC, AT, AG, CA, CC,
CT, CG, etc) across the entire collection.
-The program will output the labeled results to a file called yourname.out. At the top of the file,
output your name, student id, etc.
-After printing the summary statistics to yourname.out, you will generate 1000 DNA strings
whose lengths follow a Gaussian distribution with the same mean and variance as calculated
above. The relative frequency of nucleotides will also follow the statistics calculated above.
Append the 1000 strings to the end of yourname.out.
-The program will then ask the user if they want to process another list.
-If not, the program will exit. If so, the program will prompt for the name of the next file, process
it, and append the results to the output file.
