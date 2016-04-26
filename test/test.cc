#include <string>
#include <iostream>

#if 0               // {0,1} - vyzkoušejte si obě varianty

# include <map>

int main() {
    using namespace std;
    map<string,int> m;  // asociativní pole - indexem je slovo
    string word;

    while (cin >> word) // čtení slova
        m[word]++;      // počítání výskytů slova

    for (auto &mi: m)   // pro všechny prvky kontejneru m
        cout << mi.first << "\t" << mi.second << "\n";
    // tisk     slovo (klíč)        počet (data)
}

#else

#include <unordered_map>

int main() {
    using namespace std;
    unordered_map<string,int> m;  // asociativní pole
    string word;

    while (cin >> word) // čtení slova
        m[word]++;      // počítání výskytů slova

    for (auto &mi: m)   // pro všechny prvky kontejneru m
        cout << mi.first << "\t" << mi.second << "\n";
    // tisk     slovo (klíč)        počet (data)
}

#endif