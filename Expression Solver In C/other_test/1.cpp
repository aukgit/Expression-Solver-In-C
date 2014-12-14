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
int insert_unique_item(int s[], int item, int index );
int insert_unique_item(char s[] , char item , int index);
void array_merge(char firstArray[] , char secondArray[] , int uniqueAdd);

int getLen(char chr[]);

char operators_ar[] = { '(' , ')' , '\0'} ;
char remove_chars[] = {' ' , '#' , '$' , '%' , '_' , '=' , '!' , '~' , '|' , '"' , '<' , '>' , '?' , ';' , ':' , '\0'} ;
char operators_duplicate_not_allowed[] = { '^' , '/' , '*' , '+' , '-' , '\0'} ;

#include "codes_tested.cpp"

/* search for the operations  in duplicate not allowed (NA)*/
int search_is_operator_in_duplicateNA(char s) {
    char chr;
    int  i , ix ,  count;
    count = getLen(operators_duplicate_not_allowed);

    for (ix = 0; ix < (count); ix++ ) {
        char opt = operators_duplicate_not_allowed[ix];
        printf("\n%c:\n" , opt);

        if(opt == s) {
            //operator found in that index
            return ix;
        }
    }
    return -1; // not found
}


int main() {
    int a[N] = {0 , 1, 3, 4, 5 , 6 , 10 , 10, end_int_array};
    int b[N] = {55 , 99, 11, 3, 33 , 0 , 34 , 43 , end_int_array};



    int count   = getLen(a);

    printf("count : %d\n" , count);
    int r = search(a, 10 , 0 , -1);
    printf("\n\nfound index : %d\n" , r);
    int r2 = insert_unique_item(a , 11 , count);
    if( !r2 ) {
        printf("\nCan't insert 3. Becuase already exist.\n");
    } else {
        printf("\nSuccessfully inputed.\n");
        a[count + 1] = end_int_array;
    }

    //print_array(a);

    array_merge(a , b ,1 );
    print_array(a);
    printf("\n-------sorting--------\n");
    bubble_sort(a);
    print_array(a);
    printf("\n-------Merging Chars--------\n");
    array_merge(operators_ar,operators_duplicate_not_allowed , 1);
    printf("First Array(merged): %s\n" , operators_ar);
    printf("2nd Array(from merged): %s\n" , operators_duplicate_not_allowed);

    int rx = search_is_operator_in_duplicateNA('^');
    printf("Found : %d" , rx) ;

    //insert_unique_item(operators_ar, '^' , getLen(operators_ar) );
    getch();
    return 0;

}
