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


#define N 1000
#define forx_(x) for (i = x ; i < N ; i++){
#define loop }

#include <stdio.h> // for common library files - printf,scanf etc...
#include <conio.h> // for getch library files
#include <math.h>  // for math library functions , for instances : pow, sqrt etc...

//constants , const before and after works same.
int const int_max           = 2147483647;
int const end_int_array     = -2147483647;

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

int getLen(char chr[]) {
    char c;
    int i = 0;
    while(c = chr[i++]);
    return --i;
}

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

int search(int s[], int find ,  int start  , int end) {
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


void print_array(int A[]) {
    int r;

    for (r =0 ;  r < N; r++ ) {
        if (A[r] == end_int_array || A[r] == int_max) {
            return ;
        }
        printf("%d ", A[r]);

        printf("\n");
    }
}

void print_array(char A[]) {
    int r;
    for (r =0 ;  r < N; r++ ) {
       if (A[r] == '\0') { return;}
       printf("%c\n", A[r]);
    }
}


int bubble_sort(int array[]) {
    int i = 0 ;
    int after,cur;
    int any_change = 0;
    int count = getLen(array);

    for (i = 0; i < count ; i++ ) {
        cur = array[i];
        after = array[i+1];

        if(i == (count-1) && any_change > 0) {
            bubble_sort(array);
            return 0;
        } else if (i == (count-1) && any_change == 0) {
            return 0;
        }

        if(cur > after && after != end_int_array) {
            /*never put a equal in the condition ,
              if we then if we have similar item in the
              list , it will be a infinite loop
            */
            array[i]   = after;
            array[i+1] = cur;
            any_change++;
        }


    }
    return 0;
}


/*insert unique item to a int array */
//returns 1 or 0 , if success thn 1
int insert_unique_item(int s[], int item, int index ) {
    /*assume index is the free option where the element will
      be set. So I will put the end of the array and search for the
      item if exist if exist then put item again to that index
      */
    int temp = s[index];
    int found;
    s[index] = end_int_array;
    //print_array(s);

    found = search(s , item , 0 , -1);
    //printf("item:%d , search : %d" , item , found);
    //return;
    if(found == -1) {
        //not found
        s[index] = item;
        return 1;
    } else {
        s[index] = temp;
        return 0;
    }

}

int insert_unique_item(char s[] , char item , int index) {
    /*assume index is the free option where the element will
      be set. So I will put the end of the array and search for the
      item if exist if exist then put item again to that index
      */
    int found;
    char temp = s[index];
    s[index] = '\0'; // end of that array assisment

    found = search(s,item);
    //printf("item:%c , search : %d" , item , found);
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
            //addint unique items
            //printf("ase\n");
            if (!insert_unique_item(firstArray, item , r++)) {
                printf("not:%c\n" , item);
                --r;
            }
        }
    }
    insert_unique_item(firstArray, '\0', r++);
//    printf("first array: %d\n" , getLen(firstArray));
//    printf("%s\n" , firstArray);
    //print_array(firstArray);
}


