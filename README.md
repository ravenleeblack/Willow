# willow_ide
# **How the code in willow works**

    -Willow.c is the main file, it is the file that has the main function in it. It opens the source file, and calls parse();, then closes the file.
    -The parse(); function calls lexer();, it then inserts the returned new_token into a linked list, and then we search the link list to try and 
    start matching. Not sure if that is the proper workflow but it only gets a couple tokens from the linked linked when searched.(needs fixing)
    and probably a match() function to work with it.

    -The lexer(); calls retrieve_token, which sends its data to create_token, and create_token sends returned data to lexer, which sends to the parse();

    -retrieve_token takes all chars that are not letters or an underscore, ties the enum token_represent to it, and then sends it to create_token. 
    create_token makes the char a string and ties the token_represent into our struct named token. This gives a token that has two traits the string value 
    and the token representation value. The retrieve_token takes all the letters and builds them up in a buffer making a word, these words are then
    checked against a few reserved word functions in check_word.c, if it a reserved word then it is sent to create_token, if it is not then it is an 
    identifier and the identifier is sent to create_token. create_token returns all tokens to lexer(); The reason I did so many different functions 
    for reserved words to break them apart so that later I can handle type checking and syntax coloring in a different way.

My goals for willow is to have an oriented language at some point. The scope in willow: anything outside of the files is universal scope, anything
inside the file or manager(willows class) is global scope, and anything inside of functions is local scope, and nested thereafter. Willows main goal 
is to bring a lamens term approach to coding.

## **willow reserved words translated**

    manager                                     class
    private                                     private
    public                                      public

    place_holder/holder                         variable
    const                                       const
    function                                    procedure

    hollow                                      void
    num                                         int
    deci                                        float
    decii                                       double
    deciv                                       double double
    mark                                        char
    strand                                      string

    check                                       if
    else                                        else

    table                                       array

    act                                         do
    loop                                        while
    set                                         for
    pare                                        bool
    compare                                     switch
    line                                        case
    break                                       break
    continue                                    continue
    fault                                       default

    log                                         enum
    construct                                   struct
    bridge                                      union

    yield                                       return

    read                                        scanf
    write                                       printf
    return                                      ~~~~~             //maybe an actual function that will allow a return to other certain functions, especially in a loop



## **Willow has a slightly different grammer style**

    expressions:  will have a colon for the beginning of the expression, with two space for readablity, the expression, and a \n for the end

    check: 5 * 5
    {

    }

    functions: will have a colon for the beginning of the parameter, with two space for readablity, the arguments,  and a \n for the end

    hollow main:  int x, int y
    {

    }

    strand_literals: will have a colon at the beginnin, two spaces for readability, then the strand, arguments, and a semicolon for the end

    write:  "Hello World";


