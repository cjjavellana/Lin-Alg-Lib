#include <iostream>
#include "vectors/vectors.h"
#include <string>
#include <random>

using namespace mm::vectors;

int main(int argc, char ** argv) {
    Vector<double> *v = Vector<double>::randn(5);
    std::cout << "vector elements: ";
    string vector_elements;
    v->pretty_print(&vector_elements);
    cout << vector_elements << endl;
    std::cout << "vector size: " << v->size() << endl;
    std::cout << "Value at index 3: " << v->get(3) << endl;

    Vector<double>* scaled = v->scale(2.0);
    scaled->pretty_print(&vector_elements);
    std::cout << "scaled: " << vector_elements << endl;
    
    Vector<double>* sum = v->add(scaled);
    sum->pretty_print(&vector_elements);
    std::cout << "sum: " << vector_elements << endl;

    Vector<double>* product = v->multiply(sum);
    product->pretty_print(&vector_elements);
    std::cout << "Product: " << vector_elements << endl;

    delete v;
    delete scaled;
    delete sum;
    delete product;

    return 0;
}