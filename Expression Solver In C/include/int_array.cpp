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


/* Integer Custom Fucntions by Alim Ul Karim */

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
    found = search(s,item , 0 , -1);
    if(found == -1) {
        //not found
        s[index] = item;
        return true;
    } else {
        s[index] = temp;
        return false;
    }

}

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


