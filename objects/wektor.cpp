#include <iostream>

template <typename T>
class Wektor{
    private:
        T* array;
        size_t capacity;
        size_t size;

    public:
        Wektor() : array(nullptr), capacity(0), size(0) {}
        ~Wektor() {
            delete[] array;
        }

    void push_back(const T& element) {
        if (size >= capacity) {
            capacity = (capacity == 0) ? 1 : capacity * 2;
            T* new_array = new T[capacity];
            for (size_t i = 0; i < size; ++i) {
                new_array[i] = array[i];
            }
            delete[] array;
            array = new_array;
        }
        array[size++] = element;
    }

    T& operator[](size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return array[index];
    }

    size_t getSize() const {
        return size;
    }
};