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


int search(int s[], int find ,  int start , int end);
int  insert_unique_item(int s[], int item, int index );


int getLen(int chr[]){
    int c;
    int i = 0;
    //pos:
    while(1){
        c = chr[i++];
        if(c == end_int_array){
            break;
        }
        //printf("i:%d :%d\n" , i, c);
    };
    return --i;
}

int search(int s[], int find ,  int start  , int end){
    int  i;
    int  chr;
    forx_(start)
        chr = s[i];
        //end if matched with end index
        if (chr == end_int_array || chr == int_max) { return -1;}
        if( i == end  && end != -1) {return -1;}
        if(chr == find){
            return i;
        }
    loop
    return -1;
}


/*insert unique item to a int array */
//returns 1 or 0 , if success thn 1
int insert_unique_item(int s[], int item, int index ){
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
    if(found == -1){
        //not found
        s[index] = item;
        return 1;
    } else {
        s[index] = temp;
        return 0;
    }

}

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


/* second array will merge with first array */
void array_merge(int firstArray[] , int secondArray[] , int uniqueAdd){
    int i;
    int count = getLen(secondArray);
    int r = getLen(firstArray);
    for (i = 0; i <  count ; i++ )
    {
        int item = secondArray[i];
        if(!uniqueAdd){
            firstArray[r++] = item;
        } else {
            //addint unique items
            if (!insert_unique_item(firstArray,item , r++)){
                --r;
            }
        }

    }
    insert_unique_item(firstArray, end_int_array, r++);


}


void print_array(int A[]){
    int r;

    for (r =0 ;  r < N; r++ ){
        if (A[r] == end_int_array || A[r] == int_max) { return ;}
        printf("%d ", A[r]);

        printf("\n");
    }
}

int bubble_sort(int array[]){
    int i = 0 ;
    int after,cur;
    int any_change = 0;
    int count = getLen(array);

    for ( i = 0; i < count ; i++ )
    {
        if( i >= 1 ){

            cur = array[i];
            after = array[i+1];
            printf("cur: %d , aft:%d" , cur , after);
            if(i = (count-1) && any_change > 0){
                return bubble_sort(array);
            }else {
                return array;
            }

            if(cur >= after){
               array[i]   = after;
               array[i+1] = cur;
               any_change++;
            }

        }

    }
    return array;
}

void main(){
	int a[N] = {0 , 1, 3, 4, 5 , 6 , 10 , 10, end_int_array};
	int b[N] = {55 , 99, 11, 3, 33 , 0 , 34 , 43 , end_int_array};

	char operators_ar[] = { '(' , ')' , '\0'} ;
    char remove_chars[] = {' ' , '#' , '$' , '%' , '_' , '=' , '!' , '~' , '|' , '"' , '<' , '>' , '?' , ';' , ':' , '\0'} ;
char operators_duplicate_not_allowed[] = { '^' , '/' , '*' , '+' , '-' , '\0'} ;
    int count   = getLen(a);

    printf("count : %d\n" , count);
    int r = search(a, 10 , 0 , -1);
    printf("\n\nfound index : %d\n" , r);
    int r2 = insert_unique_item(a , 11 , count);
    if( !r2 ){
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
    getch();

}
