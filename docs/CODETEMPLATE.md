This is the template for how you should write your algorithm code.

```c++

    #ifndef ALGORITHMNAME_H
    #define ALGORITHMNAME_H

    // Your includes, if any
    #include <your_include.h>
    // Suggested includes
    #include "../../core/types.h" // This is the file with all the simplified types (ex: uint16_t = unsigned long = int16)
    
    namespace Sequency // This is the namespace for the whole project
    {
        class YourAlgorithmName
        {
            private:
                // Your private variables, if any
                int32 private_variable;
                
            public:
                // Your constructor
                // Here you will usually ask the user for the seed
                // and then set the private variables (for example the state)
                // as the seed or key or nonce.
                YourAlgorithmName(int32 private_variable_2) : private_variable(private_variable_2) {}
                
                // Your functions
                // Here you can - if you need - add functions that will be used
                // in the algorithm.
                int32 my_function() 
                {
                    return 0;
                }  
                
                // Obligatory functions
                // This function is the one used for generating the random numbers
                // you must name it as "generate"
                int32 generate()
                {
                    return private_variable;
                }
        };
    }
    
#endif // ALGORITHMNAME_H

```