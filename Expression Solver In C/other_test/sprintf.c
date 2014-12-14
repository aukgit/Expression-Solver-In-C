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

#include <stdio.h> // for common library files - printf,scanf etc...
#include <conio.h> // for getch library files
#include <math.h>  // for math library functions , for instances : pow, sqrt etc...

void main(){
    char c[10]; //becuase double is 10 bytes in GCC compiler
    double d = -234.2341;

	sprintf(c , "%lf" , d);
    printf("output :: |%s|\nn" , c);
    getch();

}
