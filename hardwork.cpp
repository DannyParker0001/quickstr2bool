#include <string>
#include <stdio.h>
#include <vector>
#include <type_traits>
#include <cstring>

template<typename T>
concept indexable = requires(T c){
        c[0];
};

template<typename T>
bool str_cmp(T* __restrict s1, T* __restrict s2){
    return !std::tolower(*s1)&&!*s2?std::tolower(*s1)==*s2:std::tolower(*s1)==*s2?str_cmp(++s1,++s2):false;
}

template<indexable T>
bool strToBool(T str){

    size_t n = 6 * sizeof(str[0]);
    typename std::remove_reference<decltype(str[0])>::type s2[] = {'f', 'a', 'l', 's', 'e', '\0'};
    bool comedy = str_cmp(&str[0], s2);
    n -= comedy * sizeof(str[0]);

    void* mem = malloc(n);
    void* memto = mem;

    if(comedy){
        *((char*)(mem)) = 0;
        memto = (void*)(((size_t)(mem)+1));
    }
    memcpy(memto, &str[0], n);

    return *(char*)(mem);
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

    std::u32string tus(U"True");
    std::u32string fus(U"False");

    std::vector<char> tv = { 'T', 'r', 'u', 'e'};
    std::vector<char> fv = { 'F', 'a', 'l', 's', 'e'};

    std::string_view tsv(ts);
    std::string_view fsv(fs);

    const char* tcs = "True";
    const char* fcs = "False";

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

    printf("%s\n", "C String:");
    testBool(strToBool(tcs));
    testBool(strToBool(fcs));

    printf("%s\n", "Unicode String:");
    testBool(strToBool(tus));
    testBool(strToBool(fus));
}