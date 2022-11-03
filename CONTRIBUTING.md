# Style Guide
## Code Style
### Header Files
* Each `.c` source file **MUST** have an associated `.h` header file with the same file name
* Code **MUST** use 4 spaces per indent, and not tabs
* There **MUST** be 1 space between keyword and opening bracket
```c
// RIGHT
if (condition)
while (condition)
for (init; condition; step)
do {} while (condition)

// WRONG
if(condition)
while(condition)
for(init;condition;step)
do {} while(condition)
```
* Comments **MUST** be on a separate line above the code it is referring to using the `//` style
```c
// RIGHT
// This is the main entry point
int main(void) {
    return 0;
}

// WRONG
int main(void) /* This is the main entry point */ {
    return 0;
}
```
* Comments **MUST** be formatted with a space after the slashes
```c
// RIGHT
// This is a comment

// WRONG
//This is a comment
```
* Multi-line comments **MUST** use multiple lines with `//`

* There **MUST** not be a space between function name and opening bracket
```c
// RIGHT
int main(void) {
    return 0;
}

// WRONG
int main (void) {
    return 0;
}
```
* A function which takes no parameters **MUST** be specified with void in the function declaration
```c
// RIGHT
int main(void) {
    return 0;
}

// WRONG
int main() {
    return 0;
}
```
* There **MUST** be a single space before and after comparison and assignment operators (`*, +, /, =, ==, =*, ...`)
```c
// RIGHT
int a = 3 + 4;
// RIGHT
for (a = 0; a < 5; ++a)
    
// WRONG
a=3+4;
// WRONG
a = 3+4;
// WRONG
for (a=0;a<5;++a)
```

* Every comma **MUST** be followed by a space
```c
// RIGHT
func_name(5, 4);

// WRONG
func_name(4,3);
```

* Opening curly bracket **MUST** be placed on the same line as the keyword (`for`, `while`, `do`, `switch`, `if`, ...)
* The opening curly bracket **MUST** be separated from the ending parenthesis by a space
```c
size_t i;
// RIGHT
for (i = 0; i < 5; ++i) {
}
// WRONG
for (i = 0; i < 5; ++i){
}
// WRONG
for (i = 0; i < 5; ++i)
{
}
```

* `static` and `global` variables **MUST** be initialized to some value such as `0` (or `NULL`)
```c
// RIGHT
static int32_t a = 0;
// RIGHT
static int32_t b = 4;

// WRONG
static int32_t a;
void my_func(void) {
    // RIGHT
    static int32_t* ptr = NULL;
    // RIGHT
    static char abc = 0;
    
    // WRONG
    static int32_t* ptr;
}
```

* Local variables **SHOULD** be declared separately
```c
void my_func(void) {
    // RIGHT
    char a = 0;
    // RIGHT
    char b = 'a';
    
    // WRONG
    char a, b;
}
```

* Local variables **SHOULD** be sorted by type, and then alphabetically
  1. Structs, enums, and pointers thereto, then finally other pointers.
     1. Pointers **SHOULD** follow directly after the types that they are pointing to
     2. Const pointers **SHOULD** come before any regular pointers 
```c
typedef struct {
    int32_t a;
    int32_t b;
} S;

typedef enum {
   A,
   B,
   C,
} E;

S s = S { .a = 1, .b = 2 };
S* s_ptr = &s;
E e = A;
E* e_ptr = &e;
const int8_t* str = "Hello";
int64_t* int_ptr = NULL;
```
  2. Integers
     1. Unsigned before any signed integers
     2. Wider/bigger integers first
        1. int32_t
        2. int16_t
        3. ...
  3. Floating-point numbers
     1. Single precision floats first (float)
     2. Followed by double precision floats (double)
     
* Local variables **MUST** be declared and initialized with a value at the beginning of the block, before first executable statement

- Counter variables in `for` loops **SHOULD** be declared in the loop constructor
```c
// RIGHT
for (size_t i = 0; i < 10; ++i)

// RIGHT because it is used after the loop
// But **MUST** have a descriptive name, rather than i,j...
size_t some_counter;
for (some_counter = 0; i < 10; ++i) {
    if (...) {
        break;
    }
}
if (some_counter == 10) {
}

// WRONG
size_t i;
for (i = 0; i < 10; ++i) ...
```

* Integers **MUST** use the types in the `stdint.h` library, int8_t, uint16_t, etc.
* Boolean values **MUST** use the types in the `stdbool.h` library, the `bool` type, and `true` and `false` constants`
```c
// RIGHT
uint8_t status = 11;

// RIGHT
#include <stdbool.h>
bool status = true;

int is_set = 1;
```

* Boolean variables **MUST** not be compared against `true` or `false`, but instead use `var` or  `!var`  respectively
```c
// RIGHT
bool a = true;
bool b = false;
if (a && !b) {}

// WRONG
if (a == true && b == false) {}
```

* Pointers **MUST** be compared against `NULL`


* Increment and decrement operators **MUST** not be used outside of `for` loops, instead use `num += 1`
* Increment **MUST** be used in `for` loops


* `size_t` **MUST** be used for length, loop counter or size variables
```c
// RIGHT
size_t len = strlen(str);
for (size_t = 0; i < 100; i++) {}
size_t size = sizeof(S) * 10;

// WRONG
int32_t len = strlen(str);
for (int32_t = 0; i < 100; i++) {}
int32_t size = sizeof(S) * 10;
``` 
 
* `const` for pointer parameters **MUST** be used if function will not modify memory pointed to by `pointer`
```c
// When data pointed to by d will not be modified
void my_func(const void* d) {}
// When the data pointed to by d will be modified
void my_func(void* d) {}
```

* The `sizeof` operator **MUST** be used with parenthesis
```c
// RIGHT
sizeof(T)

// WRONG
sizeof T
```

* Functions returning multiple values **SHOULD** return a struct with the appropriate fields, over accepting multiple pointers, unless the pointers would already be defined


* Arrays **MUST** have a fixed length `int8_t arr[8]`
* Variable length arrays **MUST** be defined with `malloc()`


* `void *` **SHOULD** never be manually casted to other pointer types, eg. `uint8_t* ptr = (uint8_t *)func_returning_void_ptr();` as `void *` is safely promoted to any other pointer type


* Libraries **MUST** be included with `"` for local header files, and `<>` for system header files, eg. `#include <stdlib.h>`


* Pointers **MUST** be defined with the asterisk `*` next to the type, not the name


* All functions which can be accessed from another source file **MUST** only have the prototype defined in the header file

* Function declarations and definition **MUST** include return type and parameters on the same line
* In case function defintion is longer than 110 characters, each parameter **MUST** be placed on separate lines
```c
int8_t long_function_name_with_many_parameters(
        int8_t a,
        int8_t b,
        int16_t c,
) {
    ...
}
```

* All structs **MUST** have a `new_<name>` function which **MUST** take as parameters the fields as the struct and return the struct

* All structs and enums **MUST** be declared with `typedef`
```c
typedef struct {
    char a,
    char b,
} Struct;

typedef enum {
    A,
    B,
} Enum;
```

* Constructing of structs **MUST** use the dot notation `(Struct){.field = value;};`

## Naming and Casing

* File names **MUST** be in `kebab-case`
* Types, such as structs or enums **MUST** be in `camelCase`
* Enum variants **MUST** be in `SCREAMING_SNAKE_CASE`
* `static` and `const` variables **MUST** be in `PascalCase`
* functions, parameters and variables **MUST** be in `snake_case`
* `#define` macros **MUST** be in `SCREAMING_SNAKE_CASE`

* functions **MUST** be in `verb_object()`, eg. `get_name()`

## Commit Messages

Commit messages use the [conventional commit format](https://gist.github.com/qoomon/5dfcdf8eec66a051ecd85625518cfd13#scopes)
```
<type>(<optional scope>): <subject>
empty line
<optional body>
```

### Types
* `feat` Commits, that adds a new feature
* `fix` Commits, that fixes a bug
* `refactor` Commits, that rewrite/restructure your code, however does not change any behaviour
    * `perf` Commits are special `refactor` commits, that improve performance
* `style` Commits, that do not affect the meaning (white-space, formatting, missing semi-colons, etc)
* `test` Commits, that add missing tests or correcting existing tests
* `docs` Commits, that affect documentation only
* `build` Commits, that affect build components, like CMake 
* `chore` Miscellaneous commits e.g. modifying `.gitignore`

### Scopes
The `scope` provides additional contextual information about what parts the commit affect.
* Is an **optional** part of the format

The scope **CAN** be eg. the file of where a function name was changed, as the diff would include multiple files, but the main change is contained to the single file


### Subject
The `subject` contains a short description of the change.
* Is a **mandatory** part of the format
* Use the imperative, present tense: "change" not "changed" nor "changes"
    * Think of `This commit will <subject>`
* The first letter **MUST** be capitalized
* No dot (.) at the end


### Body
The `body` should include the additional information about the change.
* Is an **optional** part of the format
* Use the imperative, present tense: "change" not "changed" nor "changes"
* Write in regular English sentences using proper commas and periods
* This is the p lace to mention issue identifiers and their relations eg. `FIXES: #1234`

### Examples
* ```
  feat(shopping cart): add the amazing button
  ```
* ```
  feat: remove ticket list endpoint
  
  refers to JIRA-1337
  BREAKING CHANGES: ticket enpoints no longer supports list all entites.
  ```
* ```
  fix: add missing parameter to service call
  
  The error occurred because of <reasons>.
  ```
* ```
  build(release): bump version to 1.0.0
  ```
* ```
  build: update dependencies
  ```
* ```
  refactor: implement calculation method as recursion
  ```
* ```
  style: remove empty line
  ```

## PR Etiquette

* Branches **MUST** be named `<name>-<one-or-two-word-description>` or `<name>-<issue-id>`

* PRs **MUST** be reviewed by at least 1 other person

* PR feedback **MUST** be prefixed with `style: ` in case the code doesn't follow this style guide

## File Structure

* Source and header files **MUST** be kept in `src/` and can optionally be grouped in subdirectories eg. `src/menu/menu.h`
  * If subdirectories are used, there **MUST** be a header file without a source file, that only includes the needed headers from the directory
```
src/
  menu/
    options.c
    options.h
    system.c
    system.h
  menu.h
  main.c
```

* Third-party libraries **MUST** be included in its entirety in `vendor/` unless it is a header-only library, in which case it **MUST** be placed in `headers/`
* CMake **MUST** be instructed to build into a directory containing `build` in its name
  * CLion does this by default, `cmake-build-*`
  * VSCode does this by default with the `Microsoft C/C++ extension`, `build`
  