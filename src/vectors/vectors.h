#ifndef _VECTORS_H_
#define _VECTORS_H_

#include <iostream>
#include <string>
#include <functional>

namespace mm {
namespace vectors {

/**
 * This class represents a mathematical vector.
 * 
 * Notes:
 * 1. First element of the vector is index 0
 * 2. Last element of the vector is size - 1
 **/
template <typename T>
class Vector {

public:
    // Returns an n-element vector whose elements are choosen at random
    // from a gaussian-distribution with a mean of 0.0 and standard deviation
    // of 100.00
    static Vector<T>* randn(int n);

    // Returns an n-element vector whose elements are choosen at random
    static Vector<T>* randn(int n, double stdDeviation);

    ~Vector();

    // Scales the current vector by the given scalar
    //
    // This does not mutate the current vector but returns
    // a new vector instead
    Vector<T>* scale(double scalar);

    // Performs an element-wise vector addition
    //
    // This does not mutate the current vector but returns
    // a new vector instead
    Vector<T>* add(const Vector<T> *other);

    // Performs an element-wise vector multiplication
    //
    // This does not mutate the current vector but returns
    // a new vector instead
    Vector<T>* multiply(const Vector<T> *other);

    // Performs an element-wise vector division
    //
    // This does not mutate the current vector but returns
    // a new vector instead
    Vector<T>* divide(const Vector<T> *other);

    // Performs an element-wise vector subtraction
    //
    // This does not mutate the current vector but returns
    // a new vector instead
    Vector<T>* subtract(const Vector<T> *other);

    // Performs a dot product operation
    //
    // This does not mutate the current vector but returns
    // a new vector instead
    Vector<T>* dot(const Vector<T> *other);

    // Sets a value at the specified location
    // 
    // Note: This mutates the vector
    //
    // @params row The row location of the value to set
    // @params value The value to set at the specified row location
    // 
    // @throws IndexOutOfBoundsException When either the row exceeds the 
    //  size of the vector
    void set(int row, T value);

    // Returns a value at the specified location
    //
    // @params row The row location of the value to get
    // 
    // @throws IndexOutOfBoundsException When either the row exceeds the 
    //  size of the vector
    T get(int row) const;

    // Prints the elements of the vector
    void pretty_print(std::string *buff);

    /**
     * Returns the size of the vector
     **/
    int size() const;
private:
    unsigned int m_size;
    T* elems;

    Vector();

    Vector(int size, T* t);

};

} // namespace vectors
} // namespace mm

// see Method 3 of https://www.codeproject.com/Articles/48575/How-to-Define-a-Template-Class-in-a-h-File-and-Imp 
#include "vectors.cpp"
#endif