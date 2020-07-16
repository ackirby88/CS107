## Hello World Lab
[Interactive Lab](https://lab.cs50.io/ackirby88/CS107/master/labs/helloworld/)  
You can follow along with these instructions and build this C++ source code within the CS50 Lab, which requires you to be logged into your github account.

### Compiling Programs
Before we can execute the program must *compile* it with a *compiler* (e.g., `g++`), translating it from *source code* into *machine code* (i.e., zeroes and ones). Execute the command below to do just that:

```
g++ hello.cpp
```  
And then execute  
```
ls
```  
You should see not only `hello.cpp` but `a.out` listed as well. That's because `g++` has translated the source code in `hello.cpp` into machine code in `a.out`, which happens to stand for "assembler output".

Now run the program by executing the below.

```
./a.out
```

You should get the output `Hello CS107!`.

{% next %}

## Naming Programs

Now, `a.out` isn't the most informative name for a program. Let's compile `hello.cpp` again, this time saving the machine code in a file called `hello`. Execute the below.

```
g++ -o hello hello.cpp
```

Don't overlook those spaces therein! Then execute this one again:

```
ls
```

You should now see not only `hello.cpp` (and `a.out` from before) but also `hello` listed. That's because `-o` is a *command-line argument* known as a *flag*, that tells `g++` to output (hence the `o`) a file called `hello`. Execute the below to try out the newly named program.

```
./hello
```

{% next %}

## Making Things Easier

We can let `make` build the exucutable for us. Execute the below to compile this program.

```
make hello
```

You should see that `make` executes `g++`.

Now execute the program itself one last time by executing the below.

```
./hello
```
