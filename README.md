# cpp00

✅ CPP Module 00 — Bases du C++
📚 Source : fr.subject.pdf

Manipulation de chaînes (std::string)

Fonctions membres, attributs, classes simples

Références, pointeurs

static, const, initialisation de membres

Organisation des fichiers (.hpp, .cpp)

Manipulation de iostream (std::cin, std::cout)

Pas d’allocation dynamique dans PhoneBook

Pas de STL, pas de printf(), pas de free()

Pas de new/delete avant le module 01

Makefile obligatoire


commande pour comparer les log dans ex02 :
paste <(cut -c18- 1234.log) <(cut -c18- 19920104_091532.log) | awk -F'\t' '($1 != $2) { print "Diff: \nF1: " $1 "\nF2: " $2 }'