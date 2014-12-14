Floating-Point-Expression-Solver-In-C
=====================================

Expression Solver in C to solve floating point problems.


It was my CSE115 (Introduction to C programming course).

It was a two persons project, the other person never worked on it
because he left the country. As a result , other person never credited
for this project. However name is there as we were assigned.

###Features and Ordering of the Operators
- ()  	: Opening"(" and closing")" brackets , user must have to close the bracket and must put a number between brackets.
- ^   	: Power/Exponential Operator, 2^3 = 8
- ~   	: Roots , like 8~3 = 2, 4~2 = 2 , 36~2=6
- %   	: Percentage Operator , 5%10 will be 50 , 3%10 will 30
- !   	: factor, x! , means x(x-1)!
- /   	: Division Operator
- *  	: Multiplication Operator
- +   	: Addition Operator
- -   	: Minus/Subtraction Operator



###Working Examples
Expression solver can evaluate certain expression as shown below:
- 5((-2) + 2 ( 2 * (10 + 1) /11 +5) ) = 60
- +++-+^////13341 ++    3.14 16 + 3 / 1 * ++- 2 /  4 - 3  * 2 +-+++3++++----****4 + 982 +1233 -112 = -11241.3584 _// complex error example_
- -4 - 3 *-232 -1*-23-2 = 713
- -4 - 3 -232 -1 = **-240**
- -2+2*7+2 = 14
- 5*(-2+2*7 ) = **60**
- 2^3+3+2*2/5 = 11.8
- 72(7(2(1)(2/100))) = **20.16** _// example with brackets_
- 4 - 982 * 1233 / -112 = **10814.76786** _// cal:10814.768278_
- 2 + 1 (-2 *2 +1) /1 0 -20 = 18.3 _// both same in handy cal and program_
- (2.) + 1 (-2 *2 +1)  / 1      .0   1 - 20 = -20.970297 _//simple error example cal : -20.97029703_
- 2 ^ 2+ 1 (1) + 2 (2) -1 * 2 + 10  * 1 + 1  + 5! =**138** _// both same_

##Code Credits

Every function is written by Alim Ul Karim. We were asked not use any standard functions. Only one function is used sprintf to convert from char to decimal , other than that every single piece of code is self written. If concept is retrived from some place then cite is given on top of the function(code).

###Duration	
Project was assigned 20 July, 2011 and completly presented on 21 August, 2011.


