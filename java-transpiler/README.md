# C++ to Java Transpiler

This repo wants to bridge as well as to emerge the differences, from a language view, regarding the way of programming the Java instructions language into the C++ one. 

It showcases a tiny version of the **JDK**, properly following the hierarchy among the interfaces and the implenting classes, such as **ArrayList**.

## Hierarchy disposition

The Java hierarchy is disposed of in the following way:

![Java to C++](C:\Users\Andrea\Desktop\uni\2nd Year\Coding and Laboratory\Exams\Value-Oriented-Programming\java-transpiler\Java to C++.png)

## Workflow

From the C++ side, the repo covers a source file, with the ArrayList class implementation, besided the two interfaces of List and Collection, in this instance marked as header files.

Though the Interface entity in C++ doesn't exist, it's possibile to create pure abstract classes, anyway, marking all the methods of a class as **virtual**. In this way, the classes that partecipate in the inheritance process are able to properly override them.

