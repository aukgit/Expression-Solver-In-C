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


// hello world
// 012345678910
// st =4 , end =7 print "o wo" , tested works fine. Written by Alim Ul Karim
void substring(char s[] , int start , int end , char return_substr[] ){
    int i , r=0 , count = getLen(s) - 1;
    if (end < count) {
        count = end;
    }
    if(start >= end) {
        return_substr[r] = '\0';
    }
    for (i = start; i <=  count ; i++ )
    {
        return_substr[r++] = s[i];
    }
    return_substr[r] = '\0';
}

void show_index_of_chars(char s[]){

    int i , count = getLen(s) ;
    //int derive = 0 , count_print  = 0;

    start:
    printf("output :: |%s|\n" , s);
    for (i = 0; i <  count ; i++ )
    {
        printf("|%c = %d|\n" , s[i] , i);
    }
//    printf("\n");
//    for (i = derive; i <  count ; i++ )
//    {
//        printf("%d " , i);
//        if(count_print++ > 9){
//            count_print = 0;
//            break;
//        }
//    }

}


void copy_from_array(char from[] , char to[]){
    char c;
    int i = 0;
    while(c = from[i++]){
        to[i-1] = c;
    }
    to[i] = '\0';

}

int string_compare(char c1[] , char c2[]){

    int a1 = getLen(c1);
    int a2 = getLen(c2);
    if(a1 == a2){
        char c;
        int i =0;
        while(c=c1[i++]){
            if(c != c2[i-1]){
                return 0;
            }
        }
    } else {
        return 0;
    }
    return 1;
}

// char des[N] = "MyName(some)";
//    //first b:6
//    //last bracket:11
//    char src[N] = "(source)";
//                 //01234567
//    //source start index : =1 , it means it will start from index 1: s
//    //source start index : =7  and it will get the output before 7 index means : e
//    string_copy(des,src, 1, 7,  7 , 13);
//    printf("output :: |%s|n" , des);
//    //output: MyName(source

void string_copy(char destination[] , char source[] ,  int souce_start = 0 , int source_end = -1 , int dest_start =  0 , int dest_end = -1){
    char temp[N];
    int i , count ;

    //getting count
    if(source_end == -1){
        count = getLen(source);
    } else {
        count = source_end ;
    }
    int r = 0;
    for (i = souce_start; i <  count ; i++ )
    {
        temp[r++] = source[i];
    }
    //ending temp;
    temp[r] = '\0';

     //getting count
    if(dest_end == -1){
        count = (r) + dest_start; // becuase count gets from : i < count
    } else {
        count = dest_end ;
    }
    r = 0;
    for (i = dest_start; i <  count ; i++ )
    {
        destination[i] = temp[r++];
    }
    //end the destination;
    destination[i] = '\0';
}


/* Suppouse we have a input on s = "Hello World"
                                    012345678910
   Now we want to put 'C Programming' in middle of the 'o w' so the return of s would be
   "Hello C Programming World". To do above , input s ="Hello World" ,
   replace = " C Programming " , start = 5 , end = 5;
   output = "Hello C Programming World". If end = -1 then it means replace
   from the index 5 and then the output would be "Hello C Programming ".
   For input start = 5 , end =6; output = "Hello C Programming orld"
*/
void substring_replace(char s[] , char replace[] , int start , int end = -1) {
    int replace_count = getLen(replace), i=0;
    int whiteSpace_enough = 0;
    //if start = end , no remove
    //if end =-1 , replace the whole thing from the start index
    //if start < end remove chars from those position and insert space for the replace and then put the replace
    //printf("\nase\n");
    if (replace_count <= 0 || start < 0) return;
    replace_count--;

    int distance = (end - start);

    int con1 = (start == end);
    int con2 = (start > 0 && end == -1);
    int con3 = (start < end );
    int con4 = (distance <  replace_count);
    int con5 = (distance >= replace_count);
    if(testing_substring_rep) printf("\ncon1:%d , con2:%d , con3:%d con4:%d con5:%d\n" , con1, con2 , con3 , con4 , con5);
    if( con1 ){
        //do not remove any .
        insert_space(s , start , replace_count + 1);
    } else if( con2 ){
        //replace the whole replace char from the start index
    } else if( con3 && con4 ) {
        //remove between char and insert white spaces
        for (i = start; i <= end ; i++ )
        {
            s[i] = ' ';
        }
        //insert white spaces which are not covert in the top
        int whiteSpace_count = replace_count - (end-start) ;
        if(whiteSpace_count < 0) whiteSpace_count = whiteSpace_count * -1;
        insert_space(s , start , whiteSpace_count);
    } else if( con3 && con5 ){
        for (i = start; i <= end ; i++ )
        {
            s[i] = ' ';
        }
        int whiteSpace_count = replace_count;
        if(whiteSpace_count < 0) whiteSpace_count = whiteSpace_count * -1;
        insert_space(s , start , whiteSpace_count);
    }

    int r = 0;
    replace_count = getLen(replace) + start;
    int end_the_expression = 0;
//    if(replace_count>= getLen(s)){
//        end_the_expression = 1;
//    }

    if(testing_substring_rep) printf("s:%d e:%d rcount:%d\n",start , end , replace_count );
    for (i = start; i < replace_count ; i++ )
    {
       s[i] = replace[r++];
       if(testing_substring_rep) printf("s:%c r:%c , i:%d r:%d\n" , s[i] , replace[r-1] , i , r-1);
    }
//    if(end_the_expression) s[i] = '\0';
    if(testing_substring_rep) printf("output :: |%s| r|%s|\n" , s , replace);
    removeChar_method(s, ' ');
    return;

}

void insert_space(char s[] , int pos , int count_space = 1) {
    int  i , r = 0 , r2 = 0 , r3 = 0, count = getLen(s);

    //for instance.
    /* If we want to put 3 spaces between "Hello World"
                                           012345678910
        and if the index starts from 5 then first we will put
        extra boundary with the last index. like "H e l l o               W o r l d"
                                                  0 1 2 3 4 5 6 7 8 9 10 11 12 13 14

    */
    char a[N] , c;
    int con1 = pos > count;
    int con2 = pos < 0;
    //printf("con1:%d , con2:%d , con3:%d , loop:%d\n" , con1,con2 ,con3 , loopCon);
    if( con1 || con2 ) return ;
    while(c = s[r++]) {
        i  = r-1;
        if(i==pos) {
            for (r2  = 1 ; r2  <=  count_space ; r2++ ) {
                a[r3++] = ' ';
            }
        }
        a[r3++] = s[i];
    }

    a[r3] = '\0';
    //printf("output :: |%s|\n" , a);
    clean_up_whole_array(s);
    copy_from_array(a,s);
    return ;

}

