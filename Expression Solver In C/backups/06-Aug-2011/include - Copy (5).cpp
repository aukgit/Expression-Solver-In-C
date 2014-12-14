#include <iostream>
#include <conio.h>
#include <string.h>
#include <math.h>
#include <stdio.h>

//Macros
#define N 1000
#define EquationPropertiseN 100
#define for_ for (i = 0 ; i < N ; i++){
#define forx_(x) for (i = x ; i < N ; i++){
#define loop }
#define indent cout << "   ";
#define indent_equal  cout << "  =";

using namespace std;

//method scopes declaration
void removeChar_method( char s[], char x );
void read_before_number(char s[] , int pos);
void clean_up_equation(char s[]);
void print_equation_in_a_decent_format(char s[] , int pos);
int search(char s[], char find ,  int start , int end );
int search(int s[], int find ,  int start, int end);
int search_operators(char s[],  int end , int start);
int search_is_operator(char s);
void intialize();
int getLen(char chr[]);
int getLen(int chr[]);
void clean_up_duplicate_opts(char s[]);
void array_merge(char firstArray[] , char secondArray[] , int uniqueAdd);

void print_array(char A[]);
void print_array(int A[]);

//constants , const before and after works same.
int const int_max           = 2147483647;
int const end_int_array     = -2147483647;



//important operators and remove chars
char operators_ar[] = { '(' , ')' , '\0'} ;
char remove_chars[] = {' ' , '#' , '$' , '%' , '_' , '=' , '!' , '~' , '|' , '"' , '<' , '>' , '?' , ';' , ':' , '\0'} ;
char operators_duplicate_not_allowed[] = { '^' , '/' , '*' , '+' , '-' , '\0'} ;


int len_opts                = 0;
int len_opts_duplicate_NA   = 0;
int len_remove_opts         = 0;

//global varibales
int position = 0 ; /* 1 + 2 +4 , we are reading from position 0 to the end of the str*/


//project name and developers details
void print_project_outlet();



void intialize() {
    len_opts                = getLen(operators_ar);
    len_remove_opts         = getLen(remove_chars);
    len_opts_duplicate_NA   = getLen(operators_duplicate_not_allowed);
    array_merge(operators_ar , operators_duplicate_not_allowed , 1);
    //print_array(operators_ar);
    //printf("ase");
}


int getLen(char chr[]) {
    char c;
    int i = 0;
    while(c = chr[i++]);
    return --i;
}

//input -9999 at the end to learn the last index
int getLen(int chr[]) {
    int c;
    int i = 0;
    //pos:
    while(1) {
        c = chr[i++];
        if(c == end_int_array) {
            break;
        }
        //printf("i:%d :%d\n" , i, c);
    };
    return --i;
}




void print_project_outlet() {

    cout << "|-----------------------------------------\n"
         "|-----------------------------------------\n"
         "|  \n"
         "|  CSE 115.2 Project By \n"
         "|  Alim Ul Karim and \n"
         "|  Alvee Rahman\n"
         "|  \n"
         "|-----------------------------------------\n"
         "|  Project Name : Equation Solver\n"
         "|-----------------------------------------\n"
         "|-----------------------------------------\n"
         <<endl;
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

void print_equation_in_a_decent_format(char s[] , int pos = 0 , int indent_equal_ = 1 , int space = ' ') {
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
    //oprator found
    if (res_>-1) {
        //printf("\n test : %c \n" , s[i] );
        if(i==0) {
            //if first element contains the token
            //printf("%c%c" , chr , space);
            printf(space ? "%c%c" : "%c", chr , space);
        } else {
            if(space)
                printf("%c%c%c" , space , chr , space);
            else
                printf("%c" ,chr);
        }


    } else {
        printf("%c" , chr) ;
    }
    loop
}

int search(char s[], char find ,  int start = 0 , int end = -1) {
    int  i;
    char chr;

    forx_(start)
    chr = s[i];
    //end if matched with end index
    if( i == end  && end != -1) {
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

/*insert unique item to a int array */
//returns 1 or 0 , if success thn 1
bool insert_unique_item(int s[] , int item , int index) {
    /*assume index is the free option where the element will
      be set. So I will put the end of the array and search for the
      item if exist if exist then put item again to that index
      */
    int temp = s[index];
    int found;
    s[index] = end_int_array;
    found = search(s,item);
    if(found == -1) {
        //not found
        s[index] = item;
        return true;
    } else {
        s[index] = temp;
        return false;
    }

}

/*insert unique item to a int array */
//returns 1 or 0 , if success thn 1
bool insert_unique_item(char s[] , char item , int index) {
    /*assume index is the free option where the element will
      be set. So I will put the end of the array and search for the
      item if exist if exist then put item again to that index
      */
    char temp = s[index];
    int found;
    found = search(s,item);
    if(found == -1) {
        //not found
        s[index] = item;
        return true;
    } else {
        s[index] = temp;
        return false;
    }

}


/* search form the last position */
int search_operators(char s[],  int end = -1 , int start = 0) {
    char chr;
    int  i , ix , count = 0;
    //start from the last index
    if( end != -1) {
        count = end;
    } else {
        count = ( getLen(s) );
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

    for (ix = 0; ix < (len_opts); ix++ ) {
        char opt = operators_ar[ix];
        //printf("\n%c:\n" , opt);
        if(opt == s) {
            //operator found in that index
            return ix;
        }
    }
    return -1; // not found
}

/* search for the operations  in duplicate not allowed (NA)*/
int search_is_operator_in_duplicateNA(char s) {
    char chr;
    int  i , ix , count = 0;

    for (ix = 0; ix < (len_opts); ix++ ) {
        char opt = operators_duplicate_not_allowed[ix];
        //printf("\n%c:\n" , opt);
        if(opt == s) {
            //operator found in that index
            return ix;
        }
    }
    return -1; // not found
}



/* second array will merge with first array */
void array_merge(int firstArray[] , int secondArray[] , int uniqueAdd) {
    int i;
    int count = getLen(secondArray);
    int r = getLen(firstArray);
    for (i = 0; i <  count ; i++ ) {
        int item = secondArray[i];
        if(!uniqueAdd) {
            firstArray[r++] = item;
        } else {
            //addint unique items
            if (!insert_unique_item(firstArray,item , r++)) {
                --r;
            }
        }

    }
    insert_unique_item(firstArray, end_int_array, r++);
}

/* second array will merge with first array */
void array_merge(char firstArray[] , char secondArray[] , int uniqueAdd) {
    int i;
    int count = getLen(secondArray);
    int r = getLen(firstArray);
    for (i = 0; i <  count ; i++) {
        char item = secondArray[i];
        if(!uniqueAdd) {
            firstArray[r++] = item;
        } else {
            //addint unique items
            if (!insert_unique_item(firstArray, item , r++)) {
                --r;
            }
        }
    }
    insert_unique_item(firstArray, '\0', r++);
    print_array(firstArray);
}

void print_array(int A[]) {
    int r;

    for (r =0 ;  r < N ; r++ ) {
        if (A[r] == end_int_array || A[r] == int_max) {
            return ;
        }
        printf("%d ", A[r]);

        printf("\n");
    }
}

void print_array(char A[]) {
    int r;

    for (r =0 ;  r < 10; r++ ) {
//        if (A[r] == '\0') {
//            return ;
//        }
        printf("%c\n", A[r]);
    }
}


//
//void sorting(int a[] , int ascending ){
//
//}


void clean_up_duplicate_opts(char s[]) {
    //remove white spaces before move on
    removeChar_method(s, ' ');
//    int cxs = getLen(s);
//    printf("count:%d\n" , cxs);
//    puts(s);
    char  c , c2 ;
    bool  gotNumber;
    int   remove_positions_[N] = {'\0'};
    int   i = 0 , r = 0 ,result, Row , Row2 , Count = getLen(s);

    for (Row = 0; Row < Count ; Row++ ) {
        i = 0;
        c = s[Row];
        result = search_is_operator_in_duplicateNA(c);

        //at the last index
        if (result > -1 && Row == (Count-1)) {
            if(insert_unique_item(remove_positions_ ,Row, r++) == false) {
                //if alrady exist
                --r;
            }
            goto remove_garbage;
        }

        if(result > -1) {
            if(Row == 0) {
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
                if(result > -1) {
                    //if no number exist, in between two tokens
                    if( i == 0 ) {
                        //delete the next token / operator
                        //remove method is tested
                        //cout << "Entered the remove section:\n";
                        //printf("Delete:%c , pure count: %d , Row:%d\n" , c2 , i , Row2);
                        if(insert_unique_item(remove_positions_ ,Row2, r++) == false) {
                            //if alrady exist
                            --r;
                        }
                        //remove_positions_[r++] = Row2;// we would like to delete the token from the array
                        //printf("\n%d" , remove_positions_[r-1]);
                        //Count = getLen(s); //as one item it deleted , Count should be changed too.
                        break; // break from the second loop ,if one removable token is found
                    }

                    i = 0; //after found one token
                } else {
                    //it means we have numbers after the token
                    if (c2 == '.') {
                        //cout << "found .\n";
                        //cout << "not found number\n";
                    } else {
                        //pure number
                        //printf("pure: %c\n" , c2);
                        i++;
                    }
                }
                //printf("%s\n" , &s[Row2]);
            }
        }
    }
remove_garbage:
    remove_positions_[r++] = end_int_array; //putting the end element
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
    //print_array(remove_positions_);
    //puts(s);

}

struct equation_propertise{
    int right_index;
    int left_index;
    char number_right_side[];
    char number_left_side[];
    char token;
    char value_object ;
};

//void process_simple_equation(char s[]){
//    int i= 0 , count = getLen(s) - 1;
//    int left_index , right_index;
//    struct equation_propertise ep[EquationPropertiseN];
//
//    right_index = count;
//    for (i = count; i >= 0 ; i-- )
//    {
//
//    }
//}




