#include <iostream>

// https://www.youtube.com/watch?v=fbYknr-HPYE&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=85

int getRvalue(){
    return 10; // 10 -> r-value as literal
}

int& getLValue(){
    static int name = 20;
    return name; // name is a l-value, and int& decl ensures function returns the reference to that l-value.
}

void setValue(int value){ // value -> has identifier/location -> l-value

}

void setValueUsingReference(int& value){ // l-value reference function
    //? Utility: l-value as param -> know that its not temp -> cannot steal l-value as resource (copy constructor)
}

void constAcceptRValuesToo(const int& value){ // with const -> both l/r values are acceptable

}

void setValueUsingRReference(int&& value){ // r-value reference (which itself is an l-value)
    //? Utility: r-value as param -> know its temp (expression scope) -> can steal r-value as resource. (move constructor)
}

int main(){
    int a = 10; // a -> l-value as it has location, 10 -> r-value as it is literal (no location)
    int b = 7;
    int a = b; // a,b are both l-values

    // int& c = 10; cannot store r-value inside l-value reference
    int&& c = 10; // can store r-value inside l-value reference (reference itself is l-value);

    getLValue() = 10; // can assign to modifiable l-values!
    // getRvalue() = 10; // cannot assign to r-value (methods by default without & returns r-value copy of e.g. 10)

    setValue(a); // l-value of a is copied into l-value of "value" in param
    setValue(10); // r-value of 10 is copied into l-value of "value" in param

    setValueUsingReference(a); // l-value of a's reference (address) is copied into l-value reference of "value"
    // setValueUsingReference(10); // r-value of 10 has no location and so when l-value of "value" tries to get 10's location it fails

    constAcceptRValuesToo(a);
    constAcceptRValuesToo(10);    
    
    // setValueUsingRReference(a); // a->l-value, but int&& requires r-value as param
    setValueUsingRReference(10); // 10->r-value so int&& can accept it

    const int& c = 10; // Having l-value reference for r-value is possible if l-value reference is const.

    std::string firstName = "tim";
    std::string lastName = "yang";
    std::string fullName = firstName + lastName; // firstName+lastName is an r-value as it is a temporary value 
}