
#include <iostream>
#include <iterator>
#include <vector>
#include <cstddef>

class Integers {
public:
    struct Iterator {
        using iterator_category = std::forward_iterator_tag;
        using difference_type   = std::ptrdiff_t;
        using value_type        = int;
        using pointer           = int*;
        using reference         = int&;

        Iterator(pointer ptr) : m_ptr(ptr) {}

        reference operator*() const { return *m_ptr; }
        pointer operator->() { return m_ptr; }
        
        Iterator& operator++() { m_ptr++; return *this; }  
        Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }
        
        friend bool operator== (const Iterator& a, const Iterator& b) { return a.m_ptr == b.m_ptr; };
        friend bool operator!= (const Iterator& a, const Iterator& b) { return a.m_ptr != b.m_ptr; };  

    private:
        pointer m_ptr;
    };

    Iterator begin() { return Iterator(&m_data[0]); }
    Iterator end()   { return Iterator(&m_data[size]); }

    Integers(int size) : size{size}
    {
        std::cout << "Size: " << this->size << std::endl;
        m_data = new int[size];
    }

private:
    int size = 0;
    int *m_data;
};

void integersTest()
{
    Integers integers(5);
    for (auto& value : integers)
    {
        value = 1;
    }

    for (auto& value : integers)
    {
        std::cout << value << std::endl;
    }
}
