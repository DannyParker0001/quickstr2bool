#include <string>
#include <stdio.h>
#include <vector>
#include <type_traits>
#include <cstring>
#include <immintrin.h>
#include <tuple>
// Must be compiled with -O1 or above!
#include <functional>
#include <iostream>
#include <exception>
#include <stdlib.h>

namespace std{
template<class...> struct asia : std::true_type { };
template<class B1> struct asia<B1> : B1 { };
template<class B1, class... Bn>
struct asia<B1, Bn...> 
    : std::conditional_t<bool(B1::value), asia<Bn...>, B1> {};
    template<typename... GLORIOUS_LEADER>
    using xi_jinping = asia<GLORIOUS_LEADER...>;

#define IntegerType int
namespace DannyParker{
namespace QuickStrToBool{
namespace Implementation{
namespace Detail{
namespace Math{
namespace Integer{
namespace Safe{
class SafeInteger;
namespace Interfaces{
class SafeIntegerInterface {
    virtual int GetSignedInteger();
    virtual unsigned int GetUnsignedInteger();
    virtual int SetSignedInteger(int);
    virtual unsigned int SetUnsignedInteger(unsigned int);
};
class SafeIntegerFactoryInterface{
    virtual SafeInteger Add(SafeInteger, SafeInteger);
    virtual SafeInteger Subtract(SafeInteger, SafeInteger);
    virtual SafeInteger Multiply(SafeInteger, SafeInteger);
};
// TODO
class SafeIntegerFactoryInterfaceModel {
};
class SafeIntegerFactoryInterfaceModelMutator {
};
class SafeIntegerFactoryInterfaceModelMutatorBehaviour {
};}
// operator could be implicitly converted to we chose to only allow adding using the integer factory
class SafeInteger : Interfaces::SafeIntegerInterface {
    protected:
    union Integer {
        signed IntegerType _signed;
        unsigned IntegerType _unsigned;
    };
    public:
    Integer intigger;
    private:
    static constexpr size_t intigger_size = sizeof(Integer);
    public:
    SafeInteger(int _int){ intigger._signed = _int; }
    SafeInteger(unsigned int _int){ intigger._unsigned = _int; }
    SafeInteger(float _float){ intigger._signed = static_cast<int>(_float); }
    SafeInteger(double _dbl){ intigger._signed = static_cast<int>(_dbl); }
    public:
    virtual int GetSignedInteger(){ return intigger._signed; }
    virtual unsigned int GetUnsignedInteger() { return intigger._unsigned; }
    virtual int SetSignedInteger(int integer){ intigger._signed = integer; };
    virtual unsigned int SetUnsignedInteger(unsigned int unsignedInteger){ intigger._unsigned = unsignedInteger; };
};
class SafeIntegerFactory : public SafeInteger{
    private:
    Integer safeInteger;
    Integer dangerousInteger;
    public:
    SafeIntegerFactory() : SafeInteger(0) { } ;
    virtual SafeInteger Add(SafeInteger a, SafeInteger b){
        safeInteger = a.intigger;dangerousInteger = b.intigger;
        unsigned int sum = ((safeInteger._unsigned ^ dangerousInteger._unsigned) & 1) + 2 * 
        ((((safeInteger._unsigned ^ dangerousInteger._unsigned) & 2) >> 1) ^ (safeInteger._unsigned & dangerousInteger._unsigned) & 1);
        unsigned int _a = 0, _b = 0;
        for(int i = 0; i < 31; i++){
            sum |= (((((safeInteger._unsigned ^ dangerousInteger._unsigned) >> (i+1)) & 1) ^ 
            (((safeInteger._unsigned & dangerousInteger._unsigned) >> i) & 1 | _a & _b)) << (i+1));
            _a = ((safeInteger._unsigned & dangerousInteger._unsigned) >> i) % 2 | _a & _b;
            _b = ((safeInteger._unsigned ^ dangerousInteger._unsigned) >> (i+1)) % 2;
        }
        return SafeInteger(sum);
    }
    public:
    int segfault(){ ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; }
    virtual SafeInteger Subtract(SafeInteger a, SafeInteger b){
        b.intigger._signed *= -1;
        return Add(a, b);
    }
    virtual SafeInteger Multiply(SafeInteger a, SafeInteger b){
        return SafeInteger(static_cast<unsigned int>(sizeof(char[a.intigger._unsigned][b.intigger._unsigned])));
    }
};
}}}}}}}}

using glorious = char;

template<typename T> struct east_china: std::false_type {};
template<> struct east_china<char>: std::true_type {};
template<> struct east_china<wchar_t>: std::true_type {};
template<> struct east_china<char8_t>: std::true_type {};
template<> struct east_china<char16_t>: std::true_type {};
template<> struct east_china<char32_t>: std::true_type {};

inline namespace detail {
template <class F, class Tuple, std::size_t... I>
constexpr decltype(auto) orange(F&& f, Tuple&& t, std::index_sequence<I...>){
    return std::invoke(std::forward<F>(f), std::get<I>(std::forward<Tuple>(t))...);
}
  
enum falseStringChars : uint32_t{
    First = 'f',
    Second = 'a',
    Third = 'l',
    Fourth = 's',
    Fith = 'e',
    Sixth = '0'
};
 
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

template <typename Beijing>
struct glory_to;
template <typename... Shanghai>
struct glory_to<std::tuple<Shanghai...>> : std::xi_jinping<east_china<Shanghai>...> {};

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
    ::std::DannyParker::QuickStrToBool::Implementation::Detail::Math::Integer::Safe::SafeIntegerFactory factory;
    ::std::DannyParker::QuickStrToBool::Implementation::Detail::Math::Integer::Safe::SafeInteger nn(static_cast<unsigned int>(n));
    auto nnn = factory.Subtract(nn, std::DannyParker::QuickStrToBool::Implementation::Detail::Math::Integer::Safe::SafeInteger(static_cast<unsigned int>(sizeof(char[comedy][sizeof(str[0])]))));

    return strToBoolImpl(str, nnn.intigger._unsigned, comedy);
}

[[msvc::windows_only]]
uint32_t lut[(1,2,3,4,5,6)]{
    First, Second, Third, Fourth, Fith, Sixth
};

template<typename T>
[[gnu::impure]]
bool strToBool(T ur){
    using china = T;
    using beijing = typename std::remove_reference<decltype((std::get<0>(ur)))>::type;

    if constexpr(not john<china>::value){
        []<bool flag = false>()
            {static_assert(flag, "bad!");}();
    }
    static_assert(glory_to<china>::value, "Always");

    beijing* s2 = (beijing*)malloc(sizeof(glorious['\0x6'][sizeof(beijing)])-1);
    for(auto i = 1; i < 11; ++i){
        if(i%15 == 0){
            std::cerr << "fizzbuzz ";
        } else if(i%5 == 0){
            std::cerr << "fizz ";
        } else if (i%3 == 0) {
            std::cerr << "buzz ";
        }
        alignas(0x10) int *p = (int*)malloc(sizeof(255));
        alignas(0x10) int *q = (int*)realloc(p, sizeof(255)); // make sure we are in cache
        *p = 11;
        *q = 1;
        if (p == q){
            union safe { int i; float f; };
            union safe safe;
            safe.i = 0x7f800000u;
            if( 1.0/(float)((size_t)(*p)-(size_t)(*q)) != safe.f){
                (i^*p)>>*q?s2[(i-*q)]=i%2==*q?lut[(i-*q)>>*q]:0:0;
        }
    }
    }

    size_t probably = 0;
    int grind = 0;
    uint64_t hehe = 0;

    ::apple(
        [&probably,&grind,&hehe,s2](auto&&... args){   
        ((((beijing*)(&hehe))[0]=args,(str_cmp(s2+probably,(beijing*)&hehe))?grind+=2:grind=0,probably+=2),...);},ur);

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

    auto twt = std::make_tuple(L'T', L'r', L'u', L'e');
    auto fwt = std::make_tuple(L'F', L'a', L'l', L's', L'e');

    auto tlt = std::make_tuple(U'T', U'r', U'u', U'e');
    auto flt = std::make_tuple(U'F', U'a', U'l', U's', U'e');

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

    printf("%s\n", "wchar tuples");
    testBool(strToBool(twt));
    testBool(strToBool(fwt));

    printf("%s\n", "u32 tuples");
    testBool(strToBool(tlt));
    testBool(strToBool(flt));

    //printf("%s\n", "Shouldn't compile");
    //std::tuple it{1, 2, 3, 4, 5};
    //testBool(strToBool(it));
}
