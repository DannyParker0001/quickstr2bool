#include <string>
#include <stdio.h>
#include <vector>
#include <type_traits>
#include <cstring>

template<typename T>
concept whitelist = requires(T c){
    std::is_same<typename T::value_type, char>::value
        || std::is_same<typename T::value_type, wchar_t>::value
        || std::is_same<typename T::value_type, unsigned char>::value
        || std::is_same<typename T::value_type, char8_t>::value
        || std::is_same<typename T::value_type, char16_t>::value
        || std::is_same<typename T::value_type, char32_t>::value;

    std::is_same<T, std::vector<typename T::value_type>>::value
        || std::is_same<T, std::basic_string<typename T::value_type>>::value;
};

template<whitelist T>
bool strToBool(T str){
    bool comedy = false;
    size_t n = str.size() * sizeof(decltype(((str[0]))));

    if( std::tolower(str[0]) == 'f' && 
        std::tolower(str[1]) == 'a' && 
        std::tolower(str[2]) == 'l' && 
        std::tolower(str[3]) == 's' && 
        std::tolower(str[4]) == 'e'){
        n++;
        comedy=true;
    }

    void* mem = malloc(n);
    void* memto = mem;

    if(comedy){
        *((char*)(mem)) = 0;
        memto = (void*)(((size_t)(mem)+1));
    }
    memcpy(memto, str.data(), n);

    bool* ret = (bool*)(mem);

    return *ret;
}

void testBool(bool b){
    if(b){
        printf("%s\n", "true");
    } else{
        printf("%s\n", "false");
    }
}

int main(){
    std::string ts("True");
    std::string fs("False");

    std::wstring tws(L"True");
    std::wstring fws(L"False");

    std::vector<char> tv = { 'T', 'r', 'u', 'e'};
    std::vector<char> fv = { 'F', 'a', 'l', 's', 'e'};

    std::string_view tsv(ts);
    std::string_view fsv(fs);

    printf("%s\n", "Strings:");
    testBool(strToBool(ts));
    testBool(strToBool(fs));

    printf("%s\n", "WStrings:");
    testBool(strToBool(tws));
    testBool(strToBool(fws));

    printf("%s\n", "Vectors:");
    testBool(strToBool(tv));
    testBool(strToBool(fv));

    printf("%s\n", "String view:");
    testBool(strToBool(tsv));
    testBool(strToBool(fsv));
}
