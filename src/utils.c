#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

void initialize_grid(int grid[L][L]) {
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < L; j++) {
            grid[i][j] = rand() % 16;
        }
    }
}

void print_grid(int grid[L][L]) {
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < L; j++) {
            int val = grid[i][j];
            // Boven: bit 0
            if (val & (1 << 0)) printf("↑ ");
            else printf("  ");

            // Beneden: bit 1
            if (val & (1 << 1)) printf("↓ ");
            else printf("  ");

            // Links: bit 2
            if (val & (1 << 2)) printf("← ");
            else printf("  ");

            // Rechts: bit 3
            if (val & (1 << 3)) printf("→ ");
            else printf("  ");
        }
        printf("\n");
    }
}


int check_ice_rules(int grid[L][L], int i, int j) {
    int val = grid[i][j];

    // Controleer de verbindingen in de vier richtingen
    int up = (val & (1 << 0)) > 0;    // 1 als er een verbinding naar boven is
    int down = (val & (1 << 1)) > 0;  // 1 als er een verbinding naar beneden is
    int left = (val & (1 << 2)) > 0;  // 1 als er een verbinding naar links is
    int right = (val & (1 << 3)) > 0; // 1 als er een verbinding naar rechts is

    // Controleer of er 2 inkomende en 2 uitgaande verbindingen zijn
    int incoming = (up + down);  // Hoeveel verbindingen komen er naar de cel?
    int outgoing = (left + right); // Hoeveel verbindingen gaan er van de cel weg?

    if (incoming == 2 && outgoing == 2) {
        return 1;  // De configuratie voldoet aan de ice rules
    }

    return 0;  // De configuratie is ongeldig
}

