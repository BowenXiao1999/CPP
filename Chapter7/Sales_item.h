#include <iostream>

// explict

class Sales_item {
    public:
    // 默认初始化
    Sales_item() = default;
    
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
    
    std::string isbn() const;
    friend std::istream& operator>>(std::istream&, Sales_item&);
    friend std::ostream& operator<<(std::ostream&, Sales_item&);
    Sales_item& operator+=(Sales_item&);
    Sales_item& operator=(Sales_item&);
};

// 常量成员函数 参数列表后面加const
std::string Sales_item::isbn() const {
    return bookNo;
}

std::istream& operator>>(std::istream& io, Sales_item& a) {
    io >> a.bookNo >> a.units_sold >> a.revenue;
    return io;
}

std::ostream& operator<<(std::ostream& os, Sales_item& a) {
    os << a.bookNo << a.units_sold << a.revenue;
    return os;
}

Sales_item& Sales_item::operator+=(Sales_item& a){
    this->units_sold++;
    this->revenue += a.revenue;
    return *this;
}

Sales_item& Sales_item::operator=(Sales_item& a){
    this->bookNo = a.bookNo;
    this->units_sold = a.units_sold;
    this->revenue = a.revenue;
    return *this;
}












