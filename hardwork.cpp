#include <string>
#include <stdio.h>
#include <vector>
#include <type_traits>
#include <cstring>
#include <immintrin.h>

template<typename T>
concept indexable = requires(T c){
        c[0];
};

template<typename T>
bool str_cmp(T* __restrict s1, T* __restrict s2){
    return !std::tolower(*s1)&&!*s2?std::tolower(*s1)==*s2:std::tolower(*s1)==*s2?str_cmp(++s1,++s2):false;
}

template<typename When, typename The>
struct the{
    the(When&& w, The&& t) : when(std::forward<When>(w)), _the(std::forward<The>(t)) {}
    bool when;
    The _the;
};

template <typename ... they>
struct when;

template<typename When, typename ... The>
struct when<the<When, The>...> : the<When, The>... {
    template<typename I>
    constexpr decltype(auto) operator()(I&& when) const noexcept{
        using halal_type = std::common_type_t<decltype(the<When,The>::_the(std::forward<I>(when)))...>;
        if constexpr(std::is_void_v<halal_type>){
            ((when == the<When, The>::when and (the<When, The>::_the(std::forward<I>(when)), true)) or ...);
        } else {
            halal_type allah;
            ((when == the<When, The>::when and (allah = the<When, The>::_the(std::forward<I>(when)), true)) or ...);
            return allah;
        }
    }
};

template <typename ... them>
when(them...)->when<them...>;

typedef char troll __attribute__((__vector_size__(8)));

template<typename T=char>
troll laughtrack(T* i){
    auto vals = *(troll*)(i);
    return __builtin_shufflevector(vals,vals,5,4,3,2,1,0,6,7);
}

template<indexable T>
bool strToBool(T str){

    size_t n = sizeof(char[6][sizeof(str[0])]);
    typename std::remove_reference<decltype(str[0])>::type s2[] = {'f', 'a', 'l', 's', 'e', '\0'};
    bool comedy = str_cmp(&str[0], s2);
    n -= sizeof(char[comedy][sizeof(str[0])]);

    void* mem = malloc(n);
    void* memto = mem;

    when laughing {
        the {
            std::forward<bool>(comedy),
            [&](bool crying){
                if(crying){
                    *(decltype(laughtrack(&str[0]))*)(memto) = laughtrack(&str[0]);
                } else{
                    __builtin_assume(*(char*)mem == 2);
                    *((char*)(mem)) = 0;
                    memto = (void*)(((size_t)(mem)+1));
                }
            }
        },
        the {
            std::forward<bool>(!comedy),
            [&](bool sad){
                __builtin_assume(sad == true);
                memcpy(memto, &str[0], n);
            }
        }
    };
    laughing(true);

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