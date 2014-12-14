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


/* Equation Clean up Functions Custom Functions by Alim Ul Karim */

void clean_up_equation(char s[]) {
    int i = 0;
    for_
    char remove_char = remove_chars[i];
    if(remove_char == '\0' ) {
        break;
    }
    removeChar_method(s, remove_char);
    loop


}

void clean_up_whole_array(char s[]){
    char c; int i = 0;
    while(s[i++]){
        s[i - 1] = '\0';
    }
}

void removeChar_method( char s[], char x ) {
    int i, j;
    for( i=0; s[i]!=0; ++i ) {
        while(s[i]== x) {
            j=i;
            while(s[j]!=0) {
                s[j]=s[j+1];
                j++;
            }
            if(s[i]== '\0') {
                return;
            }
        }
    }
}



void removeChar_method( char s[], int pos ) {
    //tested , works fine
    int  i;
    for( i = pos; s[i]!=0; ++i ) {
        s[i] = s[i+1];
    }
}


void print_equation_in_a_decent_format(char s[] , int pos = 0 , int indent_equal_ = 1 , int space = 1) {
    int  i , res_;
    bool previous_one_is_operator;
    char chr;
    if(indent_equal_) {
        indent_equal //already contains the semi colon
    } else {
        indent
    }
    //int res_ = search_is_operator(s[0]);
    forx_(pos)
    //put a gap bettwen every operator
    chr = s[i];
    if (chr == '\0') {
        return;
    }
    res_ = search_is_operator(chr);
    //printf("char:%c , res:%d\n" , chr, res_);
    //oprator/token found
    if (res_>-1) {
        //printf("\n test : %c \n" , s[i] );
        if(i==0) {
            //if first element contains the token
            printf(space ? "%c " : "%c" , chr); //first time
        } else {
            printf(space ? " %c " : "%c" , chr); //middle token
        }
    } else {
        printf("%c" , chr) ; //normal number
    }
    loop
}

void clean_up_plus_minus(char s[]){
    int i , r = 0, count = getLen(s);
    char p = '+' , m = '-';

    for (i = 0; i <  count ; i++ )
    {
        char c = s[i];
        if( c == p ){ //+- = - will be only minus
            char c2 = s[i+1]; //next one is minus
            if(c2 == m){
                s[i] = ' ';
            }
        }

        if( c == m ){ //-+ = -
            char c2 = s[i+1]; //next one is minus
            if(c2 == p){
                s[i+1] = ' ';
            }
        }

        if( c == p ){ //++ = +
            char c2 = s[i+1]; //next one is minus
            if(c2 == p){
                s[i+1] = ' ';
            }
        }

        if( c == m ){ //++ = +
            char c2 = s[i+1]; //next one is minus
            if(c2 == m){
                s[i] = ' ';
                s[i+1] = '+';
            }
        }

    }
    removeChar_method(s, ' ');
    //if any exist at last
    int Count = getLen(s) - 1;
    char c = s[Count];
    int result = search_is_operator_in_duplicateNA(c);
    if(result > -1 && c!= '!') removeChar_method(s, Count);

}

void clean_up_duplicate_opts(char s[]) {
    //remove white spaces before move on
    removeChar_method(s, ' ');
//    int cxs = getLen(s);
//    printf("count:%d\n" , cxs);
//    puts(s);
    // remove the factor from the operators list then at the end add the factor
    //first index is the factor
    removeChar_method(operators_duplicate_not_allowed,0);

    char  c , c2 ;
    int   gotNumber = 0;
    int   remove_positions_[N] = {end_int_array};
    int   i = 0 , r = 0 , result, Row , Row2 , Count = getLen(s);

    for (Row = 0; Row < Count ; Row++ ) {
        i = 0;
        c = s[Row];
        result = search_is_operator_in_duplicateNA(c);
        //printf("result:%d , token:%c\n" , result , c);
        //at the last index
        if (result > -1 && Row == (Count-1)) {
            if(insert_unique_item(remove_positions_ ,Row, r++) == false) {
                //if already exist
                --r;
            }
            goto remove_garbage;
        }

        if(result > -1) {

            int search_previous_token = search(remove_positions_, (Row-1) , 0 , -1 ) > -1;
            //printf("row:%d con1:%d gotNumber:%d row-1:%d\n" ,Row, search_previous_token , gotNumber, (Row-1));
            //error below if
            if( Row == 0 || (search_previous_token && !gotNumber )  ) {
                //if first element contain any token (+,-,*)
                //only minus will be accepted
                char token = operators_duplicate_not_allowed[result];
                //printf("\n token first:%c\n" , token);
                if(token != '-') {
                    //works fine , tested
                    remove_positions_[r++] = Row;// we would like to delete the token from the array
                    //printf("\ntoken : remove for fist:%d\n" , remove_positions_[r-1]);
                }
                continue; // don't need to go any more , first step has been taken care of.

            }
            //if found any operators before
            //printf("\nToken: %c\n" , c);

            for (Row2 = Row + 1; Row2 < Count ; Row2++ ) {
                c2 = s[Row2];
                //printf("%c" , c2);
                result = search_is_operator_in_duplicateNA(c2);
                int execptions_1 = (operators_duplicate_not_allowed[result] != '-');
                int execptions_2 = (operators_duplicate_not_allowed[result] != '!');
                int execptions   =  execptions_1 && execptions_2;

                if(result > -1 && execptions ) {
                    //if no number exist, in between two tokens
                    if( i == 0 ) {
                        if(insert_unique_item(remove_positions_ ,Row2, r++) == false) {
                            //if alrady exist
                            --r;
                        }
                        break; // break from the second loop ,if one removable token is found
                    }

                    i = 0; //after found one token
                } else {
                    //it means we have numbers after the token
                    if (c2 != '.') {
                        gotNumber = 1;
                        i++;
                    }
                }
            }
        }
    }
remove_garbage:
    //remove_positions_[r++] = end_int_array; //putting the end element
    remove_positions_[r] = end_int_array; //putting the end element , becuse r is already incremented
    r = 0;
    for_
        r = remove_positions_[i];  //every single remove element
        if(r == end_int_array) break;
        //printf(":%d , element : %c\n" , r , s[r]);
        //removeChar_method(s, r);
        s[r] = ' ';
    loop
    removeChar_method(s, ' ');
    //after remove all , if still the last index is a token then delete it.
    Count = getLen(s) - 1;
    c = s[Count];
    result = search_is_operator_in_duplicateNA(c);
    if(result > -1) removeChar_method(s, Count);

    //add the factor at the first position because it was deleted at the first index
    insert_space(operators_duplicate_not_allowed,0,1);
    operators_duplicate_not_allowed[0] = '!';

    //print_array(remove_positions_);
    //puts(s);

}
