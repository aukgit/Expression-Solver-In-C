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


/* Char Custom Fucntions by Alim Ul Karim */

int getLen(char chr[]) {
    char c;
    int i = 0;
    while(c = chr[i++]);
    return --i;
}

int insert_unique_item(char s[] , char item , int index) {
    int found;
    char temp = s[index];

    s[index] = '\0'; // end of that array assisment
    found = search(s,item , 0 , -1);
    //printf("\nitem:%c , search : %d , %s\n" , item , found , s);
    //printf("\n%s\n" ,  s);
    if(found == -1) {
        //not found
        s[index] = item;
        return 1;
    } else {
        s[index] = temp;
        return 0;
    }
}

/* second array will merge with first array */
void array_merge(char firstArray[] , char secondArray[] , int uniqueAdd) {
    int i;
    int count = getLen(secondArray);
    int r = getLen(firstArray);
//    printf("first array: %d\n" , r);
//    print_array(firstArray);
//    printf("2nd array:%d\n" , count);
//    print_array(secondArray);

    for (i = 0; i <  count ; i++) {
        char item = secondArray[i];

        if(!uniqueAdd) {
            firstArray[r++] = item;
        } else {
            //printf("\n2nd: %s\n" , secondArray);
            if (!insert_unique_item(firstArray, item , r++)) {
                --r;
            }
            //printf("\n--2nd: %s\n" , secondArray);
        }
    }

    insert_unique_item(firstArray, '\0', r++);
//    printf("first array: %d\n" , r);
//    print_array(firstArray);
//    printf("2nd array:%d\n" , count);
//    print_array(secondArray);

}


void print_array(char A[]) {
    int r;
    for (r =0 ;  r < N; r++ ) {
       if (A[r] == '\0') { return;}
       printf("%c\n", A[r]);
    }
}

