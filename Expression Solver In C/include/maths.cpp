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


/* Mathametics Custom Functions, All below Functions are written by Alim Ul Karim */


double factor(double a) {
    int i , count = (int)a;

    if(count == 0) return 1;
    if(count == 1 || count == 2 || count == -2 || count == -1) return (double)count;

    int r = 1 , minus_exist = 0;

    if(count < 0) {
        count = count * -1;
        minus_exist = 1;
    }

    for (i = count; i >= 2 ; i-- ) {
        r *= i ;
    }

    if(minus_exist) r *= -1;
    return r;

}

void math_token_process(char left[] , char right[], char return_[] , char token) {
    double a                    = strtod (left, NULL);
    double b                    = strtod (right, NULL);
    int    rightLen             = getLen(right);
    int    leftLen              = getLen(left);


    if( rightLen == 0 && (token == '*' || token == '/' || token == '^' ) ) {
        b = 1;
    }

    if( leftLen == 0 && (token == '*' || token == '/' || token == '^' ) ) {
        a = 1;
    }

    double c ; // contain the result

    int con_plus                = (token == '+');
    int con_minus               = (token == '-');
    int con_div                 = (token == '/');
    int con_mul                 = (token == '*');
    int con_power               = (token == '^');
    int con_negative_power      = (token == '~');
    int con_percentage          = (token == '%');
    int con_factor              = (token == '!');
    if(testing) {
        indent;
        printf("left: |%s| right: |%s|\n" , left , right , token);
    }
    if( con_div ) {
        c = a / b;
    } else if(con_mul) {
        c = a * b;
    } else if(con_plus) {
        c = a + b;
    } else if(con_minus) {
        c = a - b;
    } else if(con_power) {
        c = pow(a , b);
    } else if(con_negative_power) {
        c = pow(a , (1/b));
    } else if(con_percentage) {
        c = (a/b) * 100;
    } else if(con_factor) {
        c = factor(a);
    }
    if(testing){
        indent;
        printf("result(%c):%lf\n" , token, c);
    }


    convert_double_to_char(c , return_);
    if(number_triming) trim_zeros_from_a_real_number(return_);
}


void process_small_equation(char stringx[] , char left[] , char right[] , int leftI , int rightI , char token) {
    if(testing){
        printf("left: |%s| Right: |%s| token:%c\n" , left ,right , token);
        printf("s: |%s|\n\n" , stringx);
    }
    //char replace[N] ="XHelloX";
    char replace[N];
    //printf("s: |%s|\n" , s );
    math_token_process(left , right, replace, token);
//    printf("output: |%s|\n", replace);
    /* solve the - or + problem when the return result doesn't have any token
     * -3 -3 always minus -
     * -3 +7 could have minus or plus : have to solve
     * -1 * 2  minus
     * -1 * -1 plus : have to solve
     *  1 / -1 minus
     * -1 / 1  minus
     * -1 / -1 plus : have to solve
     */
    double left_double     = strtod (left, NULL);
    //double right_double    = strtod (right, NULL);
    double result_double   = strtod (replace, NULL);

    //(minus plus) return problem solved
    if(left_double < 0 && leftI!=0) {
        if(result_double>0) {
            insert_space(replace,0,1);
            replace[0] = '+';
//            printf("ase");
        }
    }

//    printf("\nreplace count:%d\n" , getLen(replace) );
    //printf("s: |%s|(before repalced) lIndex:%d ,rIndex:%d\n\n" , stringx , leftI ,rightI);
    substring_replace(stringx,replace ,leftI, rightI);
    if(testing){
        printf("repalce objs :: |%s|\n" , replace);
        printf("s: |%s|(repalced) lIndex:%d ,rIndex:%d\n\n" ,stringx, leftI ,rightI);
    }
}


int verify_number(char s[]) {
    char c;
    int  i = 0 ,convert;
    int  pure_number = 0;
    int  dotExist = 0 ;
    int  minus_found_at_first = 0;
    /* int 48 = '0'
           49 = '1' and so on to 57 = '9'
           46 = '.' and 45 = '-'
       those are only valid numbers
    */

    //real number can have minus in them at the first place


    while( c = s[i++]) {
        convert = (int) c;
        int condition1 = ( convert >= 48 ) && ( convert <= 57 ); // pure number
        int condition2 = ( convert == 46 ) ;
        int condition4 = ( c == '-' && (i-1) == 0 ) ; // minus at first
        //real number can have minus in them at the first place
        if( condition4 ) {
            continue;
        }

        //one number real number must have a pure number and there could be one dot exist or maybe not
        if( condition1 ) {
            pure_number = 1;
        }

        if( condition2 ) {
            dotExist += 1;
        }

        int condition3 = (dotExist <= 1);
        //printf("C1:%d , C2:%d , C3:%d , pure: %d , c:%c , v:%i\n" , condition1 ,condition2 , condition3 ,pure_number , c , convert );


        if( (condition1 || condition2) && condition3 ) {
            //a absolute real number but pure number hasn't been checked.
            if(!pure_number && i > 1) {
                //becuase a pure number must exist after one dot or before one dot.
                //assuming the first is the dot then this char must be the pure number
                return 0; // not a real number
                goto finalize;
            }
        } else {
            return 0;
        }
    }


finalize:
    // checked all , it means it must be a real number , now
    // there is a posibility the the last index could be only dot
    // which is not good for a number format
    i = i-2;
    c = s[i];
    //printf("\n%c\n" , c);
    if ( c == '.' ) {
        //remove the last char,if the last char has the dot(.)
        removeChar_method(s, i);
    }

    return 1;
}

void convert_double_to_char(double d, char return_[]) {
    //char buffer[10]; // or: buffer[sizeof(a)];
    clean_up_whole_array(return_);
    sprintf(return_ , "%lf" , d);
}

void trim_zeros_from_a_real_number(char s[]) {
    // we can only trim zero if the number has any dot.
    // first find if the number is a real number

    if(verify_number(s)) {
        //it is a real number
        int dotFound = search(s,'.');
        //printf("ase:%d\n" , dotFound);
        if(dotFound > -1) {
            int i , count = getLen(s)-1;
            //printf("ase:%d\n" , count);
            for (i = count; i >= dotFound ; i--) {
                char c = s[i];
                if(c=='.') s[i] = ' ';
                if(c!='0') goto finalize;
                if(c=='0') s[i] = ' ';
            }
        }
    }
finalize:
    removeChar_method(s, ' ');
}
