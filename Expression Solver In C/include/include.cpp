/*------------------------------------------------
 *------------------------------------------------
 * |id     		:   112 0821 042
 * |name   		:   Alim Ul Karim
 * |email  		:   alim.karim.nsu@gmail.com
 * |course 		:   CSE 115.2
 * |blog   		:   http://bit.ly/auk-blog
 * |linkedin   	:   http://linkd.in/alim-ul-karim
 * |cell   		:   +880-1673-175222
 * |cell   		:   +880-1913-500863
 *------------------------------------------------
 *------------------------------------------------
 */


using namespace std;

/* Libraries like stdio.h , math.h etc.. */
#include "include_libraries.cpp"
/* Method scopes declaration */
#include "scopes.cpp"
/* Macros */
#include "macros.cpp"
/* Variable and Constants */
#include "const_variables.cpp"

/* Other Tested Functions and Methods for this project */
#include "search.cpp"
#include "int_array.cpp"
#include "char_array.cpp"
#include "string_more.cpp"
#include "maths.cpp"
#include "equation_clean_up_functions.cpp"
#include "expression_solve.cpp"


void intialize() {
    len_opts                = getLen(operators_ar);
    len_remove_opts         = getLen(remove_chars);
    len_opts_duplicate_NA   = getLen(operators_duplicate_not_allowed);
    array_merge(operators_ar , operators_duplicate_not_allowed , 1);
//    printf("1:%s\n" , operators_ar);
//    printf("2:%s\n" , operators_duplicate_not_allowed);
//    printf("3:%s\n" , remove_chars);
}

void print_project_outlet() {

    cout <<  "|-----------------------------------------\n"
         "|-----------------------------------------\n"
         "|  \n"
         "|  CSE 115.2 Project By \n"
         "|  Alim Ul Karim and \n"
         "|  Alvee Ibne Rahman\n"
         "|  \n"
         "|-----------------------------------------\n"
         "|  Project Name : Expression Solver\n"
         "|-----------------------------------------\n"
         "|-----------------------------------------\n"
         <<endl;
}

void find_function_arguments(char s[] , char func_name[]){

}

