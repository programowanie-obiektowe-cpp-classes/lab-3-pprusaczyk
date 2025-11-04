#pragma once
#include "Statki.hpp"
#include "Stocznia.hpp"
#include <iostream>

unsigned int transportujFlota(unsigned int towar)
{
    // Jeżeli towar == 0 nie tworzymy żadnego statku
    if (towar == 0) {
        return 0;
    }

    Stocznia stocznia{};
    unsigned int przetransportowano = 0;
    unsigned int licznik_zaglowcow = 0;

    // Pętla kontynuuje, dopóki nie przetransportujemy co najmniej wymaganej ilości towaru.
    while (przetransportowano < towar) {
        Statek* nowy_statek = stocznia();
        unsigned int transport_statku = nowy_statek->transportuj();
        przetransportowano += transport_statku;
        Zaglowiec* zaglowiec = dynamic_cast<Zaglowiec*>(nowy_statek);
        if (zaglowiec != nullptr) {
            licznik_zaglowcow++;
        }
        delete nowy_statek;
    }
    return licznik_zaglowcow;
}
