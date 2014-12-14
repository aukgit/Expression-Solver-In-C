/*------------------------------------------------
 *------------------------------------------------
 * |id     		:   112 0821 042
 * |name   		:   Alim Ul Karim
 * |email  		:   alim.karim.nsu@gmail.com
 * |course 		:   CSE 115.2
 * |blog   		:   http://bit.ly/auk-blog
 * |linkedin   	:   http://linkd.in/alim-ul-karim
 * |cell   		:   +880-1673-175222
 *------------------------------------------------
 *------------------------------------------------
 *---------------------And------------------------
 *------------------------------------------------
 *------------------------------------------------
 * |id     		:   112 0350 042
 * |name   		:   Alvee Ibne Rahman
 * |email  		:   alveeibnerahman@yahoo.com
 * |course 		:   CSE 115.2
 * |cell   		:   +8801824513578
 *------------------------------------------------
 *------------------------------------------------
 */

#include "include/include.cpp"

void do_the_job(){

    int  i;
    char str[N] = "" ;


    //input print

taking_input:
    cout << "\ninput your expression:\n";
    indent;

    gets(str);
    //temp puts the existed one
    //puts(&str[0]);

compress_input:
    /* Clean up user inputed equation */
    clean_up_equation(str);
    clean_up_duplicate_opts(str);
    clean_up_duplicate_opts(str);
    clean_up_plus_minus(str); // resolves the plus * minus problem = minus



    printf("\n   Standard Format of Your Expression:\n");

    print_equation_in_a_decent_format (str , 0 , 0 , space_in_expression);
    printf("\n");

    solve_first_bracket_expressions(str);

    getch();
}

int main() {

    intialize();
    print_project_outlet();
    for (; ; ){
        do_the_job();
    }



    return 0;

}





