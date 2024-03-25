// 201779612 (Student ID Daulet Rashidov)
#include <stdio.h>
#include <stdlib.h>
int main(void) {
	char numNum[] = "How many numbers: "; //strings that will be outputed as per the assignments request
	char numValue[] = "Enter a number: ";
	int positive = 0; //declaring variable of type integer to store the n times positive numbers have ben imputted, start value is 0 like other 2 variables below
	int negative = 0; // sets the number of zeros to be 0
	int zero = 0; // sets the number of zeros to be 0
	int intValue; 	// will store the counter to track the number of iterations left (for recursion)
	char Positive[] = "Positive: %2d \n"; 	//strings that will be outputted in the end on console, with %2d meaning that there will be a variable passed in, printed in position of the 2nd number in 2 digit value in "positive"
	char Negative[] = "Negative: %2d \n";
	char Zero[] = "Zero:     %2d \n";
	char inpt[] = "%d"; //for properly storing inputs of type intger for loops, in variable inputtedNum below
	int inputtedNum; 
	char dashes[] = "------------ \n"; //will be used to print out required by canvas example dashes 

	_asm {
		mainCode:
			lea eax, numNum 
			push eax
			call printf //outputs stack contents(How many nums text)
			add esp, 4 //clearing the stack
			lea eax, intValue //before waiting for input with scanf, i will pass in a variable of type integer as a parameter into it, so that the user input that is meant to be an int, will be stored with appropriate type signature
			push eax
			lea eax, inpt
			push eax
			call scanf 
			add esp, 8
			
			cmp intValue, 0 // if user inputs 0, or if counter gets down to 0, jump to the output part!
			je output_part
			jmp recursive_part //else, go ahead with the recursive part

		recursive_part:
			mov eax, intValue //preparing to launch recursive loop
			cmp eax, 0 //intValue will be decremented by one with every iteration, thus if there are no more numbers left to ask, just jump straight to output part
			jg while_loop
			je output_part
			
		while_loop: //this is where "Enter a number" str will be outputted and store value
			lea eax, numValue
			push eax
			call printf // same process, printing string, waiting for input, and storing that in inputtedNum variable with inpt[], then clearing the stack
			add esp, 4
			lea eax, inputtedNum //doing same thing as in the beginning so that string value wouldnt be asked to be stored in a variable of type integer
			push eax
			lea eax, inpt
			push eax
			call scanf 
			add esp, 8

			cmp inputtedNum, 0 // comparing inputed num with 0 (to see if pos, neg, or zero), then jumping to corresponding parts of code
			jg isPositive
			jl isNegative
			je isZero

		isPositive: //main code jumps to this to increment variable positive by 1
			inc positive //incrementing value stored in the variable, which is initially 0
			jmp decrement_intValue

		isNegative: //same as above, increment varibable negative by 1, which is initially 0
			inc negative 
			jmp decrement_intValue

		isZero: // does same thing as above, but now with variable zero 
			inc zero
			jmp decrement_intValue

		decrement_intValue: // seperate piece of code to increase efficiency, as i can just unconditionally jump to it to decrement the counter variable needed for recursive_part
			dec intValue
			jmp recursive_part

		output_part: //once the recursive part is done, we can output the 3 variables!
			lea eax, dashes//printing the dashes first to match the given example from canvas
			push eax
			call printf
			add esp, 4

			push positive //outputting the [stirng] + variable, first positive 
			lea eax, Positive 
			push eax
			call printf
			add esp, 8 

			push negative //then negative
			lea eax, Negative 
			push eax
			call printf
			add esp, 8

			push zero //then zero
			lea eax, Zero 
			push eax
			call printf
			add esp, 8
	}
	return 0;
}