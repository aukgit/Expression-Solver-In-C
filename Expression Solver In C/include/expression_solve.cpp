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

//Below functions are related to solve expressions , written by Alim Ul Karim

void solve_first_bracket_expressions(char s[]){

    startover:
    int i = 0,r = 0, count = getLen(s) , missing_index = -1;
    char token;
    int con1 = 0,con2 = 0,con3 = 0,con4 = 0 ,con5 = 0 ,con6 = 0;
    char previous_token;
    char part[N] = "";
    int open_braket_index = -1 , close_braket_index = -1;

    con2 = ( search(s,'(') == -1 );
    con3 = ( search(s,')') == -1 );

//    if(con2 && con3 ) goto simple_expression_solve;



    for (i = 0; i <  count ; i++ )
    {
        inside_first_braket:
        token = s[i];
        if(token == ')') { missing_index = i+1 ; goto no_brakets;}

        if(token == '('){
            //first bracket present then look for second braket
            open_braket_index = i;
            missing_index = i + 1;
            for (r = i+1; r <  count ; r++ )
            {

                token = s[r];
                if(token == '('){
                    //if inside a first braket , we found another first braket , it means it has nested expressions inside a braket.
                    i = r;
                    goto inside_first_braket;
                }
                if(token == ')'){
                    close_braket_index = r;
                    goto got_bracktes;
                }


            }
        }

    }

    if(missing_index> -1) goto no_brakets;
    //if(missing_index == -1) goto simple_expression_solve;

    got_bracktes:

    //printf("\nf:%d l:%d\n" , open_braket_index , close_braket_index);
    //index was tested and it was correct:
    //Experiments
    string_copy(part , s , open_braket_index + 1 , close_braket_index);
    //printf("\npart :: |%s|\n" , part);
    con1 = !verify_number(part);
    con2 = ( search(part,'(') == -1 );
    con3 = ( search(part,')') == -1 );
    con4 = verify_number(part);
    previous_token = s[open_braket_index-1];
    con5 = (previous_token == '*' || previous_token == '(' || previous_token == '^' ) || (open_braket_index ==0 );//it means user inputed minus or already a bracket exist before it

    //printf("con1:%d , con2:%d , con3:%d con4:%d con5:%d con6:%d previous token:%c\n" , con1, con2 , con3 , con4 ,con5 , con6 , previous_token);

    //check for brackets and solve it.
    if(con4) {
        //real number inside a bracket
        //then push that number inside the expression without using brackets
        if(!con5) {
            insert_space(part,0,1);
            part[0] = '*';
        }
        substring_replace(s , part , open_braket_index, close_braket_index);
        clean_up_plus_minus(s);
        print_equation_in_a_decent_format(s , 0 , 1 , space_in_expression); printf("\n");

    } else if (con1 && con2 && con3){
        //simplefied version
        //printf("enter part:%s\n" , part);
        //show_index_of_chars(part);
        solve_a_non_bracket_full_expression(part, 0); //solving the bracket portion
        //printf("solved:%s\n" , part);
        if(!con5) {
            insert_space(part,0,1);
            part[0] = '*';
        }
        substring_replace(s , part , open_braket_index, close_braket_index);
        clean_up_plus_minus(s);
        print_equation_in_a_decent_format(s , 0 , 1 , space_in_expression); printf("\n");
    } else {
        goto common_error;
    }

    con2 = ( search(s,'(') > -1 );
    con3 = ( search(s,')') > -1 );
    if(con2 || con3){
        //it means , expression has one or many brackets yet
        solve_first_bracket_expressions(s);
    } else {
        //total simplified version
        goto simple_expression_solve;
    }

    return;
    simple_expression_solve:
    if(!verify_number(s)){
        //the whole expression if  not a number then must be a expression
        solve_a_non_bracket_full_expression(s ,1);
    }


    return;
    common_error:
    printf("\n");
    indent;
    printf("Sorry , your expression has a syntax error, please check and try again." , missing_index);

    return;
    no_brakets:
    printf("\n");
    indent;
    printf("Sorry , your expression has a missing bracket at %d, so we can not solve your expresson." , missing_index);
}


void solve_a_non_bracket_full_expression(char s[] , int pint_expression = 0){

    int i , count = getLen(operators_duplicate_not_allowed);
    for (i = 0; i <  count ; i++ )
    {
        char token = operators_duplicate_not_allowed[i];
        //printf("Input Value For:%c\n" , token);
        if(search(s,token,0,-1) > -1){
            recursive_simplifier_token(s, token);
            int len        = getLen(s);
            //if last char has minus , then solve it
            char last_char = s[len-1];
            int result = search_is_operator_in_duplicateNA(last_char);

            if( result > -1 && last_char !='!' ){
                removeChar_method(s, len-1);
            }

            if(pint_expression) {
                print_equation_in_a_decent_format(s , 0 , 1 , space_in_expression); printf("\n");
            }
        }
    }

}

void recursive_simplifier_token(char s[] ,char token){
    if(!verify_number(s)) {
        recursive:
        int r = process_simple_token(s,token);
        if(r == 1){
            //so maybe still same token exist
            goto recursive;

        }
    }
}


int process_simple_token(char s[], char token) {
    int i= 0 , count = getLen(s);
    int left_index = -1, right_index = -1; // contain the index only
    char right_number[N] = "" , left_number[N] =""; //contain the numbers
    int result = 0;
    char temp = '\0';

    if(verify_number(s)) return 0;
    for (i = 0 ; i < count ; i++ ) {

        //if(i == (count)) return;
        char c = s[i];
        if(token == '-' && i == 0) continue;

        if(c == token) {
            //we have found the token , now we need to find the left and the right number
            int token_pos = i;

            //Left Number Getting Operation
            left_index = token_pos - 1;
            //Left Side Number
            int lx , minus_found_at_left = 0;
            for (lx = left_index; lx >= 0 ; lx-- )
            {
            	temp = s[lx];
                int search_token = search_is_operator(temp);

            	if( (search_token > -1 && temp != '-' )){
            	    //lx++;
                    goto after_left_got;
            	}

            	if(temp =='-'){
            	    substring(s , lx , left_index , left_number);
            	     lx--;
            	    goto after_left_got;
            	}
            	substring(s , lx , left_index , left_number);
            }


            after_left_got:
            left_index = lx + 1;
            //printf("Left Number: |%s| Leftindex:%d\n" , left_number , left_index);
//            if(!verify_number(left_number)){
//                printf("\nError Left Number: %s , please check the syntax.\n" ,left_number);
//                exit(0);
//            }

            //Getting Right Side Number
            right_index = token_pos + 1;
            for (lx = right_index; lx <  count ; lx++ )
            {
                temp = s[lx];
                int search_token = search_is_operator(temp);

            	if( (search_token > -1  && temp != '-') || (temp =='-' && lx != right_index ) ) {
                    goto after_right_got;
            	}

            	substring(s ,  right_index, lx , right_number);
            	//printf("new|%s|\n" ,right_number );
            }

            after_right_got:
            right_index = lx - 1; //becuase from for loop we have +1
            //printf("Right Number: |%s| Rightindex:%d\n" , right_number , right_index );
//            if(!verify_number(right_number)){
//                printf("\nError Right Number: %s , please check the syntax.\n" ,left_number);
//                exit(0);
//            }


            process_small_equation(s , left_number, right_number ,left_index ,right_index, token);
            //printf("final s :: |%s|\n" , s);
            return 1;

        }
        //if(i < count && change > 0) process_simple_token(s, token , i);

    }

    return 0;
}

