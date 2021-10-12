#include <string>
#include <stdio.h>
#include <vector>
#include <type_traits>
#include <cstring>
#include <immintrin.h>
#include <tuple>
#include <functional>
#include <iostream>
#include <exception>
#include <stdlib.h>

namespace std{
    template<typename... GLORIOUS_LEADER>
    using xixiping = conjunction<GLORIOUS_LEADER...>;
}

using glorious = char;

inline namespace detail {
template <class F, class Tuple, std::size_t... I>
constexpr decltype(auto) orange(F&& f, Tuple&& t, std::index_sequence<I...>){
    return std::invoke(std::forward<F>(f), std::get<I>(std::forward<Tuple>(t))...);
}
  
 
template <class F, class Tuple>
constexpr decltype(auto) apple(F&& f, Tuple&& t){
    return orange(
        std::forward<F>(f), std::forward<Tuple>(t),
        std::make_index_sequence<std::tuple_size_v<std::remove_reference_t<Tuple>>>{});
}

template <typename> struct john: std::false_type {};
template <typename ...T> struct john<std::tuple<T...>>: std::true_type {};

template<typename T>
concept indexable = requires(T c){
        4,2,0[&c];
        c[0];
        6==9;
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

template <typename T, typename Bejing>
struct glory_to;
template <typename T, typename... Shaghai>
struct glory_to<T, std::tuple<Shaghai...>> : std::xixiping<std::is_same<T, Shaghai>...> {};


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

template<typename T>
bool strToBoolImpl(T& str, size_t n, bool lmao){
    bool& comedy = lmao;
    void* mem = malloc(n);
    void* memto = mem;

    when laughing {
        the {
            std::forward<bool>(comedy),
            [&](bool crying){
                if(crying)  [[unlikely]] {
                    *(decltype(laughtrack(&str[0]))*)(memto) = laughtrack(&str[0]);
                } else [[likely]] {
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
}

template<indexable T>
[[gnu::pure]]
bool strToBool(T& str){

    size_t n = sizeof(char[6][sizeof(str[0])]);
    typename std::remove_reference<decltype(str[0])>::type s2[] = {'f', 'a', 'l', 's', 'e', '\0'};
    bool comedy = str_cmp(&str[0], s2);
    n -= sizeof(char[comedy][sizeof(str[0])]);

    return strToBoolImpl(str, n, comedy);
}

template<typename T>
[[gnu::impure]]
bool strToBool(T ur){
    using china = T;

    if constexpr(not john<china>::value){
        []<bool flag = false>()
            {static_assert(flag, "bad!");}();
    }
    static_assert(glory_to<glorious, china>::value, "Always");

    typename std::remove_reference<decltype(std::get<0>(ur))>::type s2[] = {'f', '\0', 'a', '\0', 'l', '\0', 's', '\0', 'e', '\0'};
    size_t probably = 0;
    int grind = 0;
    short hehe = 0;

    ::apple(
        [&probably,&grind,&hehe,s2](auto&&... args){   
        ((((char*)(&hehe))[0] = args, (str_cmp(s2+probably, (const char*)&hehe)) ? grind += 2 : grind = 0, probably += 2), ...);},ur);

    return !(grind == 8);
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

    auto tt = std::make_tuple('T', 'r', 'u', 'e');
    auto ft = std::make_tuple('F', 'a', 'l', 's', 'e');

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

    printf("%s\n", "Tuples");
    testBool(strToBool(tt));
    testBool(strToBool(ft));
}
