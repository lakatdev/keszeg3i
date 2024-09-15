# Keszeg language version 3i

## About Keszeg
Keszeg is a minimalist programming language designed with simplicity and clarity at its core. It focuses on a clean, easy-to-learn syntax and structure. While intentionally limited in scope, these constraints encourage creative problem-solving and can serve as the foundation for more intricate solutions. Keszeg is as much a playful challenge for programmers as it is a functional tool, offering an environment that emphasizes fundamental coding principles.

## The software
This repository contains an interpreter for the Keszeg language, specifically for version 3i.

## Contents
- [Keszeg language version 3i](#keszeg-language-version-3i)
  - [About Keszeg](#about-keszeg)
  - [The software](#the-software)
  - [Contents](#contents)
  - [How to build](#how-to-build)
  - [Running the code](#running-the-code)
  - [Writing code](#writing-code)
    - [Subroutines](#subroutines)
    - [Comments](#comments)
    - [Escaped characters](#escaped-characters)
    - [Variables, arrays and strings](#variables-arrays-and-strings)
    - [Scopes](#scopes)
  - [Instructions](#instructions)
    - [Arithmetic operations](#arithmetic-operations)
      - [Setting variables](#setting-variables)
      - [Addition](#addition)
      - [Subtraction](#subtraction)
      - [Multiplication](#multiplication)
      - [Division](#division)
      - [Modulo](#modulo)
      - [Increment](#increment)
      - [Decrement](#decrement)
    - [Control flow instructions](#control-flow-instructions)
      - [if conditions](#if-conditions)
      - [end](#end)
      - [Executing system commands](#executing-system-commands)
      - [while loops](#while-loops)
      - [Calling and returning from a subroutine](#calling-and-returning-from-a-subroutine)
      - [Sleep](#sleep)
    - [Input/Output operations](#inputoutput-operations)
      - [Printing to the console](#printing-to-the-console)
      - [Receiving input from the console](#receiving-input-from-the-console)
      - [File I/O](#file-io)
    - [Array and string operations](#array-and-string-operations)
      - [Setting values of arrays and strings](#setting-values-of-arrays-and-strings)
    - [Utility functions](#utility-functions)
      - [Random numbers](#random-numbers)
  - [Example program](#example-program)


## How to build
Keszeg code can be run using the following software:
- *keszegi* is the interpreter, which runs the code

This can be built with gcc using the following command:

`g++ src/*.cpp src/instructions/*.cpp -o keszegi -I include -std=c++11`

The provided build.sh script contains exactly this line.

The resulting bytecode can be placed in `/bin/keszegi` or `/usr/bin/keszegi` so the interpreter is available globally across the OS.

## Running the code
When the source file is ready, it can be run using *keszegi*:

`./keszegi source.k`.

To enable some debug functions one can use:

`./keszegi -d source.k`.

## Writing code
Code is written by giving the interpreter instructions line by line. It is important to note that the instructions in the language are case insensitive while subroutine and variable names are not.

### Subroutines

The program enters in the "MAIN" subroutine and runs until it is returned. If MAIN is not present, the program will start from the first line and from there be executed line by line without executing the defined subroutines, that can be called separately. Please note that the "MAIN" subroutine must be written in all uppercase letters. This is a requirement of the language and not following this convention will result in the program malfunctioning. From there can other subroutines be called. These are not functions, they do not return any value. For example:

```
(rt MAIN
    call other
return)

(rt other
    print const Hello World\n
return)
```

this prints "Hello World".

*OR*

```
print const Hel

(rt second_part
    print const World\n
rt)

print const lo\s

call second_part
```

this also prints "Hello World".

### Comments
In a line after the # character all text is ignored during compilation. These are comments.

```
(rt MAIN
    i = 0
    # initialize loop
    while i < 100
        print $ i        # print the number
        print const \n   # print new line character
        i +=             # increase the iterator variable
    end
rt)
```

### Escaped characters
In strings there are 3 escaped characters, one is the new line character and the other two are the number sign (#) and the space.

- new line: "\n"
- number sign: "\h"
- space: "\s"

### Variables, arrays and strings
These are the three data types that can be used. They are not scope specific, unless scopes are explicitly defined! Keep that in mind while coding. Variables are 32bit signed integers, arrays are an array of these, while strings are arrays of 8bit signed integers.

### Scopes
Scopes in Keszeg are used to manage data flow and control structures, and they provide a way to organize and isolate logic within your code. Scopes are explicitly defined using the `scope` keyword, and everything inside the scope is isolated from the rest of the code. When a scope is declared, it creates a local environment where variables can be manipulated without affecting the global state. If a subroutine is called from within a scope all of its data can be accessed in the subroutine that is called.

```
(rt example
    A = 12
    scope
        B = 32
        print $ A
        print $ B
    end
    scope
        print $ A
        C = 23
        call rt_call
    end
rt)

(rt rt_call 
    [...]
rt)
```

In this example, within the second scope the value of B is not defined in contrast to A which is defined outside of the scopes, therefore can be accessed. In rt_call the value of C can be accessed and modified.

## Instructions
There are four main groups of instructions

- Arithmetic
- Control flow
- I/O
- Arrays and strings

**It is *very* important to type spaces between each symbol described below, otherwise the code will not compile correctly.**

This will work:
`n = m + 4`

this will not:
`n=m+4`.

As a positive side effect, this makes the code readable.

### Arithmetic operations

#### Setting variables

`X = Y`

Sets value of Y to X variable, Y can be either a constant or a variable.

#### Addition

`X = Y + Z`

Stores the sum of Y and Z in the X variable.

#### Subtraction

`X = Y - Z`

Stores the difference of Y and Z in the X variable.

#### Multiplication

`X = Y * Z`

Stores the product of Y and Z in the X variable.

#### Division

`X = Y / Z`

Stores the ratio of Y and Z in the X variable.

#### Modulo

`X = Y % Z`

Stores Y mod Z value in the X variable.

#### Increment

`X += Y` or `X +=`

Increases the X variable by Y if Y is specified, if not then by 1.

#### Decrement

`X -= Y` or `X -=`

Decreases the X variable by Y if Y is specified, if not then by 1.

### Control flow instructions

#### if conditions

`if X condition Y`

The if instruction has 6 possible conditions:
- =
- <
- \>
- !=
- <=
- \>=

The value of X is compared to the value of Y the way the condition describes.

If the result is true the code between this *if* instruction and the corresponding *end* instruction will be executed.

#### end
Indicates the end of *if* conditions and *while* loops.

#### Executing system commands
`exec X` executes X command in the default shell of the operating system.

#### while loops
`while X condition Y`

While loops work the same as *if* conditions, except they repeat execution until the condition is false.

#### Calling and returning from a subroutine

`(rt example` declares a subroutine called "example". The instructions between this, and the corresponding `rt)` are the body of the subroutine.

When using `call example` the program execution continues at the specified subroutine (in this case "example") until that finishes, and then returns to where it was originally called from.

`rt)` describes the end of a subroutine, after that the execution returns to where it was called from. If *MAIN* is returned the program finishes.

#### Sleep

The `sleep X` instruction makes the thread sleep for X milliseconds. X can be a variable or a constant.

### Input/Output operations

Keszeg is capable of communicating with the outer world in mainly two ways. It can read and write standard console input and output and it can write and read strings and arrays to and from the file system. It is done using the following instructions:

#### Printing to the console

`print mode X`

The print instruction has 4 different modes:
- $
- ascii
- string
- const

The *$* (numerical) option prints the numerical value of the constant or the variable to the console. The *ascii* option does something similar, except it doesn't print it as number, but its corresponding ascii character.

The *string* option prints the data stored in the referenced string, while the *const* option prints everything written after the instruction's parameter.

#### Receiving input from the console

Similarly to printing, the `input mode X` instruction also has different modes.

- $
- ascii
- string

These work the same. *$* receives a number input to a variable, *ascii* a single character input to a variable, while *string* takes an entire string of text and places it in a string.

#### File I/O

Strings and arrays can be written to and read from files. The `save mode X Y` and `load mode X Y` instructions take care of that. The modes can be *array* and *string* depending on the type of the data.

When using `save array X Y` X is the array to be saved and Y is the path to the file which it should be saved to. Similarly with strings.

`load array X Y` works the same way, X is the destination array or string while Y is a path.

Files are in a raw binary format, if the string is 5 characters long, the file will be a 5 byte long file with the said characters. Same goes with arrays, each integer is 4 bytes long.

This implies that these operations can be used for binary file manipulation.

### Array and string operations

#### Setting values of arrays and strings
One can set the Y - 1th value of an X array to Z by using the following operators:

`X : Y <= Z`.

This loads Z to the array. If the array is not at least Y + 1 long, it will be resized.

With strings the operator is `<-`:

`X : Y <- Z`.

To get a previously set value back from arrays or strings, the following should be done:

`Z <= X : Y` when working with arrays and `Z <- X : Y` when working with strings.

To get the size of these types, there are two functions to be used.

`X sizeof Y` loads the length of the Y array or string to X.

To reset the sizes and empty the values, the `free X` instruction is to be used with variables, strings and arrays.

The `cat X Y` instruction concatenates a constant Y string to theee string X. Y is everything written after the space character after the X value, just like previously with paths and constant string prints.

### Utility functions

#### Random numbers

The `random X Y` instruction generates a random integer value less than Y, where Y is either a variable or a constant number. The result is placed in the X integer variable. The seed of the random generator is set at the beginning of runtime.

## Example program
Below is an example program to determine the maximum value of an array provided by the user using the console.

```
(rt MAIN
    call receive_input
    call determine_max
    call output_result
rt)

(rt receive_input
    print const n:
    input $ length

    i = 0
    while i < length
        disp = i
        disp +=
        print $ disp
        print const .:
        input $ tmp
        numbers : i <= tmp
        i +=
    end
rt)

(rt determine_max
	max <= numbers : 0
	i = 1
	while i < length
		tmp <= numbers : i
		if tmp > max
			max = tmp
		end
		i +=
	end
rt)

(rt output_result
    print const max:
    print $ max
    print const \n
rt)
```

The console will look like this (including the user input):
```
n:5
1.:45
2.:-23
3.:163
4.:-89
5.:0
max:163
```

*15th September 2024*
