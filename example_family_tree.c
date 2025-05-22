#include <stdio.h>

// Struktur für eine Person
struct Person {
    char* name;
    int alter;
    struct Person* vater;
    struct Person* mutter;
};

int main() {
    // Großeltern väterlicherseits
    struct Person opa_vater = { "Klaus", 80, NULL, NULL };
    struct Person oma_vater = { "Irma", 78, NULL, NULL };

    // Großeltern mütterlicherseits
    struct Person opa_mutter = { "Heinz", 82, NULL, NULL };
    struct Person oma_mutter = { "Lena", 79, NULL, NULL };

    // Eltern
    struct Person vater = { "Martin", 52, &opa_vater, &oma_vater };
    struct Person mutter = { "Eva", 50, &opa_mutter, &oma_mutter };

    // Geschwister des Kindes
    struct Person schwester = { "Anna", 19, &vater, &mutter };
    struct Person bruder = { "Jonas", 17, &vater, &mutter };

    // Tante väterlicherseits (Schwester des Vaters)
    struct Person tante = { "Monika", 49, &opa_vater, &oma_vater };

    // Kind
    struct Person kind = { "Lukas", 21, &vater, &mutter };

    // Ausgabe Stammbaum
    printf("Kind: %s (%d Jahre)\n", kind.name, kind.alter);
    printf("  Vater: %s (%d Jahre)\n", kind.vater->name, kind.vater->alter);
    printf("    Opa väterlicherseits: %s (%d Jahre)\n", kind.vater->vater->name, kind.vater->vater->alter);
    printf("    Oma väterlicherseits: %s (%d Jahre)\n", kind.vater->mutter->name, kind.vater->mutter->alter);
    printf("  Mutter: %s (%d Jahre)\n", kind.mutter->name, kind.mutter->alter);
    printf("    Opa mütterlicherseits: %s (%d Jahre)\n", kind.mutter->vater->name, kind.mutter->vater->alter);
    printf("    Oma mütterlicherseits: %s (%d Jahre)\n", kind.mutter->mutter->name, kind.mutter->mutter->alter);
    printf("  Geschwister:\n");
    printf("    Schwester: %s (%d Jahre)\n", schwester.name, schwester.alter);
    printf("    Bruder: %s (%d Jahre)\n", bruder.name, bruder.alter);
    printf("  Tante väterlicherseits: %s (%d Jahre)\n", tante.name, tante.alter);

    return 0;
}
