# Pimpl Pattern

According to the **VOP** paradigm of the C++ language, when we've tasked to create a class, the hinted idea is to break down its creation in two different branches:

* **class_name.hpp**: The file containing the public interface of the class.

* **class_name.cpp**: The file containing the implementation of all its methods.

  One of the best practices also when it comes to the **Object Oriented Programming** pattern is to maximize both the **information hiding** of a class and the implementation of a method from the user.

  This is achieved, In this way, by adopting a **Pointer to Implementation** system which allows to do so.  

  In addition, this improves the compilation time of the overall file as well.

  