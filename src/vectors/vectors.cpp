#include <cstdlib>
#include <chrono>
#include <random>
#include <type_traits>

#include "../common/complex.h"
#include "vectors.h"

using namespace std;

#define CHECK_ROW(row, vector_size) \
    if(row >= vector_size) { \
        throw "Row: " + std::to_string(row) + " exceeds the size of the vector: " + std::to_string(vector_size); \
    }

#define CHECK_NOT_NULL(ptr) \
    if(ptr == nullptr) { \
        throw "Unable to allocate memory"; \
    }

#define CHECK_SIZE_ARE_SAME(curr_vector_size, other_vector_size) \
    if(curr_vector_size != other_vector_size) { \
        throw "Vector size mismatch"; \
    }

namespace mm {
namespace vectors {

template<typename T>
Vector<T>::Vector(){
};

template<typename T>  
Vector<T>::Vector(int size, T* t){
    this->m_size = size;
    this->elems = t;
};

template<typename T>  
int Vector<T>::size() const {
    return m_size;
}

template<typename T>  
T Vector<T>::get(int row) const {
    CHECK_ROW(row, this->m_size)

    return this->elems[row];
}

template<typename T>  
void Vector<T>::set(int row, T value) {
    CHECK_ROW(row, this->m_size)

    this->elems[row] = value;
}

template<typename T>  
void Vector<T>::pretty_print(string *buff) {
    if(this->elems == nullptr) {
        cout << "Vector is empty";
        return;
    }

    *buff = "[";
    for(int i = 0; i < this->m_size; i++) {
        *buff = *buff + std::to_string(this->elems[i]);
        if(i < this->m_size - 1) {
            //append separator
            *buff = *buff + ", ";    
        }
    }
    *buff = *buff + "]";
}

template<typename T>  
Vector<T>* Vector<T>::scale(double scalar) {
    int vector_size = this->m_size;
    T *elements = new T[vector_size];

    CHECK_NOT_NULL(elements);

    for(int i = 0; i < vector_size; i++) {
        elements[i] = this->get(i) * scalar;
    }

    return new Vector<T>(vector_size, elements);
}

template<typename T>  
Vector<T>* Vector<T>::add(const Vector<T> *other) {
    int vector_size = this->m_size;
    int other_vector_size = other->size();

    CHECK_SIZE_ARE_SAME(vector_size, other_vector_size);

    T *elements = new T[vector_size];
    
    CHECK_NOT_NULL(elements);

    for(int i = 0; i < vector_size; i++) {
        elements[i] = this->get(i) + other->get(i);
    }

    return new Vector<T>(vector_size, elements);
}

template<typename T>  
Vector<T>* Vector<T>::multiply(const Vector<T> *other) {
    int vector_size = this->m_size;
    int other_vector_size = other->size();

    CHECK_SIZE_ARE_SAME(vector_size, other_vector_size);

    T *elements = new T[vector_size];
    
    CHECK_NOT_NULL(elements);

    for(int i = 0; i < vector_size; i++) {
        elements[i] = this->get(i) * other->get(i);
    }

    return new Vector<T>(vector_size, elements);
}

template<typename T>  
Vector<T>* Vector<T>::randn(int n) {
    return randn(n, 100.0);
}

template<typename T>  
Vector<T>* Vector<T>::randn(int n, double std_deviation) {
    default_random_engine generator;
    generator.seed(std::chrono::system_clock::now().time_since_epoch().count());

    normal_distribution<double> distribution(0.0, std_deviation);

    T *elements  = new T[n];
    
    if (std::is_same<T, mm::common::ComplexNumber>::value) {
        cout << "T is a double";
    }

    CHECK_NOT_NULL(elements);
    
    for(int i = 0; i < n; i++) {
        elements[i] = distribution(generator);
        cout << "-> " << elements[i] << endl;
    }

    return new Vector<T>(n, elements);
}

template<typename T>  
Vector<T>::~Vector(){
    delete[] this->elems;
}

} // namespace vectors
} // namespace mm

