/*------------------------------------------------
 * Expression Solver (Readme)
 *------------------------------------------------
 * |id     		  :   112 0821 042
 * |name   		  :   Alim Ul Karim
 * |email  		  :   alim.karim.nsu@gmail.com
 * |course 		  :   CSE 115.2
 * |blog   		  :   http://bit.ly/auk-blog
 * |linkedin   	:   http://linkd.in/alim-ul-karim
 * |Written     :   21 Aug 2011
 *------------------------------------------------
 *------------------------------------------------
 *---------------------And------------------------
 *------------------------------------------------
 *------------------------------------------------
 * |id     		:   112 0350042
 * |name   		:   Alvee Rahman (never worked on  the project)
 * |email  		:   alveeibnerahman@yahoo.com
 * |course 		:   CSE 115.2
 *------------------------------------------------
 *------------------------------------------------
 */
 
Expression solver can evaluate certain expression as shown below:
5((-2) + 2 ( 2 * (10 + 1) /11 +5) ) 
+++-+^////13341 ++    3.14 16 + 3 / 1 * ++- 2 /  4 - 3  * 2 +-+++3++++----**** 4 + 982 +1233 -112 
-4 - 3 *-232 -1*-23-2 
-4 - 3 -232 -1 
-2+2*7+2 
5*(-2+2*7 ) 
2^3+3+2*2/5 
72(7(2(1)(2/100))) 
4 - 982 * 1233 / -112 

Expression Solver has below operators:

()  : Opening"(" and closing")" brackets , user must have to close the bracket 
^   : Power/Exponential Operator, 2^3 = 8
~   : Roots , like 8~3 = 2, 4~2 = 2 , 36~2=6
%   : Percentage Operator , 5%10 will be 50 , 3%10 will 30
!   : factor, x! , means x(x-1)!
/   : Division Operator
*   : Multiplication Operator
+   : Addition Operator
-   : Minus/Subtraction Operator
There is no need to use * before any bracket program will automatic understand it.
Expression Solver follows the BODMAS mechanism to simplify a mathematical expressions sequentially as calculator does.

Limitations:
Input expression must be equal or less than 600 digits,
Only evaluate double data type and displays in a user-friendly format, it does not present the extra zeros of a number.

Running Instruction:
Compiling [main.cpp] file via [Code::Blocks] will convert the source code to object code and now user can test the project.
Other including files are inside the include folder, which is not necessary to open before run or compile the project but 
it is necessary to keep those files in the same folder.
