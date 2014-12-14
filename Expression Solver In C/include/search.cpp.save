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

//All Search Related Custom Functions are written in here by Alim Ul Karim

int search(char s[], char find ,  int start = 0 , int end = -1) {
    int  i;
    char chr;

    forx_(start)
    chr = s[i];

    //end if matched with end index
    if( (i == end  && end != -1) || chr == '\0') {
        return -1;
    }
    if(chr == find) {
        return i;
    }
    loop
    return -1;
}

int search(int s[], int find ,  int start = 0 , int end = -1) {
    int  i;
    int  chr;
    forx_(start)
    chr = s[i];
    //end if matched with end index
    if (chr == end_int_array || chr == int_max) {
        return -1;
    }
    if( i == end  && end != -1) {
        return -1;
    }
    if(chr == find) {
        return i;
    }
    loop
    return -1;
}

int search(char )

/* search form the last position */
int search_operators(char s[],  int end = -1 , int start = 0) {
    char chr;
    int  i , ix , count = 0;
    //start from the last index
    if( end != -1) {
        count = end;
    } else {
        count = ( getLen(s) - 1 );
    }

    for (i = count; i >= start ; i-- ) {
        chr = s[i];
        // found operator
        if (search_is_operator(chr) > -1) return i;
    }
    // not found
    return -1;
}

/* search for the operations */
int search_is_operator(char s) {
    char chr;
    int  i , ix , count = 0;
    count = getLen(operators_ar);
    for (ix = 0; ix < (count); ix++ ) {
        char opt = operators_ar[ix];
        //printf("\n%c:\n" , opt);
        if(opt == s) {
            //operator found in that index
            return ix;
        }
    }
    return -1; // not found
}

int search_is_operator_in_duplicateNA(char s) {
    char chr;
    int  i , ix ,  count;
    count = getLen(operators_duplicate_not_allowed) ;
    for (ix = 0; ix < (count); ix++ ) {
        char opt = operators_duplicate_not_allowed[ix];
        //printf("\n%c:\n" , opt);
        if(opt == s) {
            //operator found in that index
            return ix;
        }
    }
    return -1; // not found
}
