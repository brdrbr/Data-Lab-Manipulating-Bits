/* 
 * CS:APP Data Lab 
 * 
 * <Berke Derin Berktay 72968>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2020 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */
/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
  /*Our end product should have nonzero bits at only the locations where for both the inputs the bits at that specific location is nonzero. The remaining lcoations should only have 0 as bits.
    To make this happen what I did was that I first inverted both the ints and then used the bitwise or to add them and the result should give me 0s at only the locations where for both inputs in the beginning
	both of the inputs were 1 at that specific location and this is because once the inputs are inverted, only in this specific case both numbers will have 0s at the locations and once we use or for
	the newest versions we will end up with only those specified locations having 0 bits. But we want the exact revers of this so at the end we simply invert the bits again by using ~*/
  int result = ~x | ~y;
  result = ~result;
  return result;
}
/* 
 * isEqual - return 1 if x == y, and 0 otherwise 
 *   Examples: isEqual(5,5) = 1, isEqual(4,5) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int isEqual(int x, int y) {
  /* By taking the exclusive or of the two numbers we will end up with a 0 if all of the bits are the same since if the bits are the same the operator returns 0 and if they are different the operator returns 1
	And since the ! sign returns a 1 if the number is 0 and returns a 0 if the number is nonzero, we will end up with a 1 if and only if all of the bits are the same*/
  int result = x ^ y;
  return !result;
}
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
	/* Normally I wanted to write this as ((!((x-0x30) >> 31)) & ((x-0x3A) >> 31)) but couldnt since the - operator apparently is illegal. The idea here is that this function that I just wrote checks
	the signs of the results by first substracting the minimum from the given number and then substracting the max + 1 from the given number. This idea allows us to determine whether or not the number is
	indeed in the interval and if this is the case the first part should give us a 0 and the second part should give us a 1 and we will end up with !0 & 1 which ultimately will be only 1 and 0 combination
	possibility that will give us this result of. Below I used this idea but had to come up with different numbers that will give the same result when added as the ones that we substracted above or in
	another words, I added the negative versions of the numbers above. In the beginning I also tried a brute force algorithm that checks if the number is equal to any of the 10 cases and 
	then for the results of 10 cases I put an or statement to each of them to see if any of them is indeed equal to one. But when I ran it it said I used too much operators so I switched to this idea.
	But for some reason that i did not understand 0xD0 and 0xC6, which are the exact negative versions of 0x30 and 0x3a did not work, so I tried the negated versions where once you negate the number you
	end up getting the numbers 0xD0 and 0xC6. These numbers correspond to 0x2F and 0x39*/
   return ((!((x+~0x2F) >> 31)) & ((x+~0x39) >> 31));
}
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
  /* Only in the case that all the bits are zero that the or statment of a number's sign by its negative version's sign should give us a 0 for the sign digit since if the number is positive,
	 its negative will have a 1 and vice 
	versa. But if this number is 0 its negative version will also have a 0 for the sign digit so we will end up with 0xFFFFFFE and therefore once you 0xFFFFFFFE | 0xFFFFFFFE you will get a 0xFFFFFE. 
	For all the other cases at least one of the sign digits will be
	a 0xFFFFFFFF and therefore we can distinguish and in all the nonzero cases we will end up with 0xFFFFFFFF due to the or statement. However we want to get the reverse of this where 
	the all zero value sohuld output a 1 and vice versa. And therefore we increment the final value by 1, which will
	give us a 0xfffffffe + 1 = 0xfffffff for the allzero value (which returns 1) and 0xfffffff + 1 = 0 for the nonzero values.*/
  int normalsign = x>>31;
  int negation = ~x + 1;
  int negationsign = negation >> 31;
  return ((normalsign | negationsign) + 1);
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  /* The minimum 32-bit signed integer is 0x80000000 which ca be written as 00000000000000000000000000000001 << 31 and I have to write it like this because writing too big of a constant is not allowed*/
  return 1 << 31;
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  /* During the class we learned this rule of thumb where the negative of a number is simply it being inverted + 1 and this is what I used below.*/
  x = ~x + 1;
  return x;
}
/* 
 * isGreater - if x > y  then return 1, else return 0 
 *   Example: isGreater(4,5) = 0, isGreater(5,4) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isGreater(int x, int y) {
  /* If the signs were only restricted to +s this question wouldve been so easy but we can have 4 different combinations of signs and the combinations need different sets of actions and hence we need to 
	seperate the cases and therefore we separate them to same sign and different sign cases but in order to do that first we obtain their signs. Then the first part of the samesign makes sure that
	the signs are the same and hence gives a 1 if they are indeed the same. Then the second part of the and returns a 0 sign bit if the x is larger and a 1 sign biy if the y sign bit is larger due
	to the program substracting y from x. If both conditions are met this means we get a 1 for the same sign and that y is larger and a 0 if x is larger. The different sign case is easier since 
	we can simply compare the signs we will get a 1 if x is the positive one and a 0 if the x is the negative one. Then we get the (samesign | differentsign) command which gives us (0|0) when they 
	have the same sign and and x is larger
	, (1|0) when they have the same sign and y is larger,(0|0) when different signs and x is larger and (0|1) when different signs and y is larger. 
	These outputs need to be reversed since we are asked for 1 when x is greater and hence we add a ! to the beginning.*/ 
  int signx = x >> 31;
  int signy = y >> 31;
  int samesign = ((~signx ^ signy) & ((~y + x)>>31));
  int differentsign = signx & !signy;
  return !( samesign | differentsign);
}
/* 
 * float_abs - Return bit-level equivalent of absolute value of f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument..
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_abs(unsigned uf) {
  /* Because of the format of the single-precision floating point values, we know that the leftmost digit will give us the value of the sign and hence if we can change that to 0, we will obtain the absolute
	value. However as it is noted above, we also need to consider the NaN. By the powerpoint slides I know that the value of the minimum NaN is 0x7F800001 and any value above it we will have a NaN and
	then we need to simply return the entering argument The reason why all the numbers that are bigger than 0x7F80001 is NaN is because by the definition we know that all the values that are bigger than
	this number will have their exponent bits as all 1s and will for sure have at least 1 nonzero bit on the fraction bits and hence this makes sense. Since we got rid of the sign in the beginning we also
	know that this classification also considers all of the negative NaNs as well which are very very small but since their signs became positive we know that they are bigger than the minimum NaN.We could
	also use abs > 0x7F800000 and abs <= 0x7F800000 for the if statements as well.*/
  int abs = uf & 0x7FFFFFFF;
  if (abs >= 0x7F800001)
    return uf;
  else if (abs < 0x7F800001)
    return abs;
  else
    return 0;
}
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
  /* Here what I tried to do was that I tried to separate the 3 components which are the sign, exponent and the fraction. However I couldn't figure out the proper ways to multipy the exponent and fraction.
     But after my attempt of multiplying them I put thm back into their locations and gathered them together to form the new number called twice using th eor statement. I also knew that I could detect the 
	NaN cases by checking the exponent to see whether or not it is all 1s and if this is the case it is indeed a NaN case. I know that the function does not work but I did this all for partial marks.*/
  /*int sign = uf >> 31;
  sign = uf << 31;
  int exponent = ((uf << 1) >> 24);
  int fraction = ((uf << 10) >> 10);
  exponent = exponent + exponent;
  fraction = fraction + fraction;
  exponent = exponent << 23;
  int twice = exponent | fraction | sign;
  if (exponent = 0xFF000000)
    return uf;
  else
    return twice;*/
  return 2;
}
