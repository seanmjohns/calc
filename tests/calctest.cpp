//Standard


//libs
#include "gtest/gtest.h"

//Project
#include "../src/calc.h"

//Needed functions

bool disableSyntaxChecks = true; //We wont need this here because I know the syntax is correct

int testSize = 20;

//We shouldnt need more than 20 parts
void parseCheck(int values[testSize], int size) {

	struct node *current = list->root;

	EXPECT_EQ(list->length, size); //The things should be the same size

	int i = 0;
	while(current != NULL && i <= size+1) {
		EXPECT_EQ(values[i], current->value);
		current = current->next;
		i++;
	}


}

/* Test Suite: Parse
 *
 *	Test to ensure that the parser is
 *	correctly parsing each character to the correct symbol.
*/

TEST(Parse, addition) {

	//Setup
	char *equation = (char*)("4+5");
	int listValues[] = {4, 0, 5};

	parse(equation); //The equation is stored in the linked list

	//Testing
	parseCheck(listValues, sizeof(listValues)/sizeof(int));

	//Teardown
	list->clean();
}

TEST(Parse, subtraction) {

	//Setup
	char *equation = (char*)("4-5");
	int listValues[] = {4, 1, 5};
	
	parse(equation); //The equation is stored in the linked list

	//Testing
	parseCheck(listValues, sizeof(listValues)/sizeof(int));

	//Teardown
	list->clean();
}

TEST(Parse, multiplication) {

	//Setup
	char *equation = (char*)("4*5");
	int listValues[] = {4, 2, 5};

	parse(equation); //The equation is stored in the linked list

	//Testing
	parseCheck(listValues, sizeof(listValues)/sizeof(int));

	//Teardown
	list->clean();
}

TEST(Parse, division) {

	//Setup
	char *equation = (char*)("4/5");
	int listValues[] = {4, 3, 5};
	
	parse(equation); //The equation is stored in the linked list

	//Testing
	parseCheck(listValues, sizeof(listValues)/sizeof(int));

	//Teardown
	list->clean();
}

TEST(Parse, doubleNegative) {

	//Setup
	char *equation = (char*)("4--5");
	int listValues[] = {4, 1, -5};

	parse(equation); //The equation is stored in the linked list

	//Testing
	parseCheck(listValues, sizeof(listValues)/sizeof(int));

	//Teardown
	list->clean();
}

/* Test Suite: Calculate
 *
 *	Test to ensure each of the following
 * 	operations are working correctly:
 *	 - Addition
 *	 - Subtraction
 *	 - Multiplication
 *	 - Division
 *   - Exponents
 *   - list->roots
 *   - Absolute value
 *   - Parenthesis
*/

TEST(Calculate, addition) {

	//Setup
	char *equation = (char*)("4+5+6");
	int equationSize = 6; //Note that this needs to the be size when it is in the linked list
	long double expected = 15;
	
	parse(equation); //The equation is stored in the linked list

	//Testing
	calculate(NULL, 0, equationSize, false);
	ASSERT_EQ(expected, list->root->value);

	//Teardown
	list->clean();
	
}

TEST(Calculate, subtraction) {

	//Setup
	char *equation = (char*)("4-5-6");
	int equationSize = 6; //Note that this needs to the be size when it is in the linked list
	long double expected = -7;
	
	parse(equation); //The equation is stored in the linked list

	//Testing
	calculate(NULL, 0, equationSize, false);
	ASSERT_EQ(expected, list->root->value);

	//Teardown
	list->clean();
	
}

TEST(Calculate, subtractNegative) {

	//Setup
	char *equation = (char*)("4--5");
	int equationSize = 3; //Note that this needs to the be size when it is in the linked list
	long double expected = 9;
	
	parse(equation); //The equation is stored in the linked list

	//Testing
	calculate(NULL, 0, equationSize, false);
	ASSERT_EQ(expected, list->root->value);

	//Teardown
	list->clean();
	
}

TEST(Calculate, multiplication) {

	//Setup
	char *equation = (char*)("4*5*6");
	int equationSize = 6; //Note that this needs to the be size when it is in the linked list
	long double expected = 120;

	parse(equation); //The equation is stored in the linked list

	//Testing
	calculate(NULL, 0, equationSize, false);
	ASSERT_EQ(expected, list->root->value);

	//Teardown
	list->clean();

}

TEST(Calculate, division) {

	//Setup
	char *equation = (char*)("10/5");
	int equationSize = 6; //Note that this needs to the be size when it is in the linked list
	long double expected = 2; //note the rounding

	parse(equation); //The equation is stored in the linked list

	//Testing
	calculate(NULL, 0, equationSize, false);
	ASSERT_EQ(expected, list->root->value);

	//Teardown
	list->clean();

}

TEST(Calculate, exponent) {

	//Setup
	char *equation = (char*)("4^3");
	int equationSize = 3; //Note that this needs to the be size when it is in the linked list
	long double expected = 64; //note the rounding

	parse(equation); //The equation is stored in the linked list

	//Testing
	calculate(NULL, 0, equationSize, false);
	ASSERT_EQ(expected, list->root->value);

	//Teardown
	list->clean();

}

TEST(Calculate, root) {

	//Setup
	char *equation = (char*)("4*(3V8)");
	int equationSize = 7; //Note that this needs to the be size when it is in the linked list
	long double expected = 8; //note the rounding

	parse(equation); //The equation is stored in the linked list

	//Testing
	calculate(NULL, 0, equationSize, false);
	ASSERT_EQ(expected, list->root->value);

	//Teardown
	list->clean();

}

TEST(Calculate, parenthesis) {

	//Setup
	char *equation = (char*)("4*(4+4)");
	int equationSize = 8; //Note that this needs to the be size when it is in the linked list
	long double expected = 32;

	parse(equation); //The equation is stored in the linked list

	//Testing
	calculate(NULL, 0, equationSize, false);
	ASSERT_EQ(expected, list->root->value);

	//Teardown
	list->clean();

}

TEST(Calculate, nestedParenthesis) {

	//Setup
	char *equation = (char*)("4*(4+4*(4+4))");
	int equationSize = 13; //Note that this needs to the be size when it is in the linked list
	long double expected = 144;

	parse(equation); //The equation is stored in the linked list

	//Testing
	calculate(NULL, 0, equationSize, false);
	ASSERT_EQ(expected, list->root->value);

	//Teardown
	list->clean();

}
