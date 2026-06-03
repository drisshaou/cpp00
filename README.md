*This project has been created as part of the 42 curriculum by drhaouha.*

# C++ - Module 00

## Description

Introduction to Object-Oriented Programming in C++98. Covers namespaces, classes, member functions, `std::cout`, initialization lists, `static`, and `const`.

## Exercises

| # | Name | Description |
|---|------|-------------|
| 00 | Megaphone | Uppercase all CLI arguments using C++ streams |
| 01 | My Awesome PhoneBook | Interactive phonebook with `PhoneBook` and `Contact` classes, max 8 entries, formatted table display |
| 02 | The Job Of Your Dreams | Reconstruct `Account.cpp` from a header and a log file (optional) |

## Compilation

```bash
c++ -Wall -Wextra -Werror -std=c++98 *.cpp -o <binary>
```

Each exercise has its own `Makefile`.

## Rules

- C++98 standard only — no C++11, no Boost
- No `printf`, `*alloc`, `free`
- No `using namespace` or `friend`
- No STL containers or `<algorithm>` (allowed only from module 08)
- No function implementations in header files
- Include guards required on all headers
- No memory leaks when using `new`

## Resources

- [cplusplus.com — std::string](http://www.cplusplus.com/reference/string/string/)
- [cplusplus.com — iomanip](http://www.cplusplus.com/reference/iomanip/)

## command to compare logs in ex02 :
paste <(cut -c18- 1234.log) <(cut -c18- 19920104_091532.log) | awk -F'\t' '($1 != $2) { print "Diff: \nF1: " $1 "\nF2: " $2 }'
