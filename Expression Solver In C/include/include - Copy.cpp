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
         "|  Project Name : Equation Solver\n"
         "|-----------------------------------------\n"
         "|-----------------------------------------\n"
         <<endl;
}

//struct equation_propertise {
//    int right_index;
//    int left_index;
//    char number_right_side[];
//    char number_left_side[];
//    char token;
//    char value_object ;
//};

void recursive_simplifier_token(char s[] ,char token){
//    int i = 0;
    recursive:
    int r = process_simple_token(s,token);
    if(r == 1){

        //for testing only
//        i++;
//        if(i > 10) return;
        //so maybe still same token exist
        goto recursive;


    }

}


int process_simple_token(char s[], char token) {
    int i= 0 , count = getLen(s);
    int left_index , right_index; // contain the index only
    char right_number[N] , left_number[N] ; //contain the numbers
    int number_len = 0 ;
    //struct equation_propertise ep[EquationPropertiseN] , epx;
    int routing = 0; // for generating left and right number
    int is_number = 1 , result;
    char temp , tempToken;


    for (i = 0 ; i < count ; i++ ) {
        /* we are moving from  left to right, if we find the token which matches the requirements
           then we will find the right and left number and the verify it and then send it to process
           to its respective function and then replace it in the middle of the equation.
         */
        //consequently a equation of 1+ 3 + 42 + 133 will be
        //if(i == (count)) return;
        char c = s[i];
        if(token == '-' && i == 0) continue;
        //printf("%c" , c);
        if(c == token) {
            //we have found the token , now we need to find the left and the right number
            int token_pos = i;

            //Left Number Getting Operation
            left_index = token_pos - 1;
            routing = left_index;
            //printf("::routing:%d\n" , routing );
            is_number = 1;
            int minus_found_left = 0 , minus_found_right = 0;
            while(is_number) {
                /* checking, if we ran into any token other than minus */
                temp   = s[routing];
                result = search_is_operator_in_duplicateNA(temp);

                int condition_1 = (result > -1 && operators_duplicate_not_allowed[result] != '-');
                int condition_2 = (result > -1 && operators_duplicate_not_allowed[result] == '-' && minus_found_left >= 1);
                if( temp == '-' ) minus_found_left = 1; //if minus found in any place that means count +1
                if(condition_1 || condition_2) {
                    //break
                    break;
                }
                //Now getting the substring to the left number
                substring(s , routing-- , left_index , left_number);
                //printf("LeftN:%s,routing:%d\n" , left_number , routing + 1);
                //printf("routing:%d\n" , routing + 1);
                number_len = getLen(left_number);
                int first_char_minus_condition = (number_len==1 && right_number[0] != '-');
                if(number_len > 0 && first_char_minus_condition) {
                    is_number = verify_number(left_number);
                }
                if (routing <= -1 || minus_found_left >= 1) break;
            }
            left_index = routing + 1;

            is_number = verify_number(left_number);
            //printf("is number:%d,number:|%s|\n" , is_number , left_number);
            if (!is_number) {
                removeChar_method(left_number , 0); //if not valid then the first index contains garbage
                left_index++;
            }
           // printf("Left:%s\n" , left_number);

            //printf("routing: %d , routing char:%c , token:%d\n" , routing , s[i] , token_pos);

            //Right Number Getting Operation
            is_number = 1;
            right_index = token_pos + 1;
            routing = right_index;
            //getting right number , becase we are moving from left to right
            while(is_number) {
                /* checking, if we ran into any token other than minus */
                temp   = s[routing];
                result = search_is_operator_in_duplicateNA(temp);
                if(temp== '-' && routing == right_index){
                    routing++;
                    continue;
                }
                int condition_1 = (result > -1 && operators_duplicate_not_allowed[result] != '-');
                int condition_2 = (result > -1 && operators_duplicate_not_allowed[result] == '-' && minus_found_right >= 1);
                if( temp == '-' ) minus_found_right += 1;
                if(condition_1 || condition_2) {
                    break;
                }
                //Now getting the substring to the left number
                substring(s , right_index , routing++ , right_number);
                //printf("rightN:%s\n" , right_number);
                number_len = getLen(right_number);
                int first_char_minus_condition = (number_len==1 && right_number[0] != '-');
                if(number_len > 0 && first_char_minus_condition) {
                    is_number = verify_number(right_number);
                }
                if(minus_found_right >= 1) break;
                if(temp == '\0'){
                    --routing;
                    break;
                }
            }
            //            // //if not valid then the last index contains garbage
            //printf("Right:%s , count:%d\n" , right_number , getLen(right_number));
            right_index = routing - 1;
            printf("Input Value For:%c\n" , right_number[right_index-1]);
            if(right_number[right_index] == '-'){
                right_number[right_index] = '\0';
                right_index--;
            }
            is_number = verify_number(right_number);
            if (!is_number) {
                right_number[right_index-1] = '\0';
                right_index--;
            }

            process_small_equation(s , left_number,right_number ,left_index ,right_index, token);
            return 1;

        }
        //if(i < count && change > 0) process_simple_token(s, token , i);

    }

    return 0;
}

