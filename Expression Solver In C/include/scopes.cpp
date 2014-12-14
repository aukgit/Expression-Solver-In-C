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


/* Method & Functions Scopes */
void intialize();
void removeChar_method( char s[], char x );
void removeChar_method( char s[], int pos );

void read_before_number(char s[] , int pos);
void clean_up_equation(char s[]);
void print_equation_in_a_decent_format(char s[] , int pos);
int search(char s[], char find ,  int start  , int end);
int search(int s[], int find ,  int start, int end);
int search_operators(char s[],  int end , int start);
int search_is_operator(char s);
int getLen(char chr[]);
int getLen(int chr[]);
void clean_up_duplicate_opts(char s[]);
void array_merge(char firstArray[] , char secondArray[] , int uniqueAdd);
bool insert_unique_item(int s[] , int item , int index);
void substring(char s[] , int start , int end , char return_substr[]);
int verify_number(char s[]);
void clean_up_whole_array(char s[]);
void copy_from_array(char from[] , char to[]);

void convert_double_to_char(double d, char return_[]);
void trim_zeros_from_a_real_number(char s[]);

void insert_space(char s[] , int pos , int count_space);
void substring_replace(char s[] , char replace[] , int start , int end);

//project name and developers details
void print_project_outlet();

void print_array(char A[]);
void print_array(int A[]);
void clean_up_duplicate_opts(char s[]);

void process_small_equation(char s[] , char left[] , char right[] , int leftI , int rightI , char token);
void math_token_process(char left[] , char right[], char return_[] , char token);
int process_simple_token(char s[], char token);

int string_compare(char c1[] , char c2[]);
void recursive_simplifier_token(char s[] ,char token);
double factor(double a);
void string_copy(char destination[] , char source[] ,  int souce_start , int source_end, int dest_start, int dest_end);
void solve_first_bracket_expressions(char s[] , int pint_expression);
void solve_a_non_bracket_full_expression(char s[] , int pint_expression);
