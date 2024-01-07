# 1 strategija (Dvigubas Konteinerių Naudojimas)

## `std::vector`:
- Didėjant duomenų kiekiui, skaitymo, rikiavimo, grupių atskyrimo ir įrašymo į failus laikas ženkliai auga.
- Grupių atskyrimo laikas yra santykinai mažesnis už skaitymo ir rikiavimo laikus, bet auga su duomenų kiekiu.

## `std::list`:
- Skaitymo laikas panašus į `std::vector`, tačiau rikiavimo laikas yra ženkliai trumpesnis.
- Grupių atskyrimo laikas yra minimalus, o įrašymo į failus laikas panašus į `std::vector`.

## `std::deque`:
- Skaitymo laikas yra panašus į `std::list` ir `std::vector`.
- Rikiavimo laikas ilgesnis nei `std::list`, bet panašus į `std::vector`.
- Grupių atskyrimo laikas yra trumpesnis nei `std::vector`, bet ilgesnis nei `std::list`.

# 2 strategija (Vieno Konteinerio Naudojimas ir Elementų Trynimas)

## `std::vector`:
- Skaitymo laikas yra panašus į 1 strategiją.
- Rikiavimo laikas taip pat panašus į 1 strategiją.
- Grupių atskyrimo laikas ženkliai trumpesnis nei 1 strategijoje, ypač didesniuose duomenų rinkiniuose.

## `std::list`:
- Skaitymo, rikiavimo ir grupių atskyrimo laikai yra panašūs į 1 strategiją, tačiau grupių atskyrimo laikas šiek tiek trumpesnis.
- Įrašymo į failus laikas panašus į 1 strategiją.

# Bendros Išvados

- **Atminties Efektyvumas**: 2 strategija yra efektyvesnė atminties naudojimo požiūriu, nes nekuria studentų kopijų.
- **Našumas**: `std::list` pasirodo esąs labai efektyvus rikiavimo ir grupių atskyrimo operacijose, tai yra dėl jo privalumų trinant elementus.


# Laiko palyginimas naudojant 1 strategija.

## naudojant vector:

Iveskite failo pavadinima: C:\...\1000_studentu.txt
- Laikas, praleistas skaitymui is failo: 49 ms
- Laikas, praleistas rikiavimui: 7 ms
- Laikas, praleistas grupiu atskyrimui: 6 ms
- Laikas, praleistas rasant i failus: 13 ms

Iveskite failo pavadinima: C:\...\10000_studentu.txt
- Laikas, praleistas skaitymui is failo: 362 ms
- Laikas, praleistas rikiavimui: 127 ms
- Laikas, praleistas grupiu atskyrimui: 70 ms
- Laikas, praleistas rasant i failus: 90 ms

Iveskite failo pavadinima: C:\...\100000_studentu.txt
- Laikas, praleistas skaitymui is failo: 3396 ms
- Laikas, praleistas rikiavimui: 1560 ms
- Laikas, praleistas grupiu atskyrimui: 593 ms
- Laikas, praleistas rasant i failus: 909 ms

Iveskite failo pavadinima: C:\...\1000000_studentu.txt
- Laikas, praleistas skaitymui is failo: 63176 ms
- Laikas, praleistas rikiavimui: 59522 ms
- Laikas, praleistas grupiu atskyrimui: 17234 ms
- Laikas, praleistas rasant i failus: 28282 ms

## naudojant list:

Iveskite failo pavadinima: C:\...\1000_studentu.txt
- Laikas, praleistas skaitymui is failo: 36 ms
- Laikas, praleistas rikiavimui: 0 ms
- Laikas, praleistas grupiu atskyrimui: 1 ms
- Laikas, praleistas rasant i failus: 11 ms

Iveskite failo pavadinima: C:\...\10000_studentu.txt
- Laikas, praleistas skaitymui is failo: 292 ms
- Laikas, praleistas rikiavimui: 4 ms
- Laikas, praleistas grupiu atskyrimui: 14 ms
- Laikas, praleistas rasant i failus: 101 ms

Iveskite failo pavadinima: C:\...\100000_studentu.txt
- Laikas, praleistas skaitymui is failo: 2774 ms
- Laikas, praleistas rikiavimui: 59 ms
- Laikas, praleistas grupiu atskyrimui: 169 ms
- Laikas, praleistas rasant i failus: 834 ms

Iveskite failo pavadinima: C:\...\1000000_studentu.txt
- Laikas, praleistas skaitymui is failo: 27297 ms
- Laikas, praleistas rikiavimui: 659 ms
- Laikas, praleistas grupiu atskyrimui: 2369 ms
- Laikas, praleistas rasant i failus: 8760 ms

## naudojant deque:

Iveskite failo pavadinima: C:\...\1000_studentu.txt
- Laikas, praleistas skaitymui is failo: 60 ms
- Laikas, praleistas rikiavimui: 17 ms
- Laikas, praleistas grupiu atskyrimui: 3 ms
- Laikas, praleistas rasant i failus: 25 ms

Iveskite failo pavadinima: C:\...\10000_studentu.txt
- Laikas, praleistas skaitymui is failo: 299 ms
- Laikas, praleistas rikiavimui: 125 ms
- Laikas, praleistas grupiu atskyrimui: 15 ms
- Laikas, praleistas rasant i failus: 89 ms

Iveskite failo pavadinima: C:\...\100000_studentu.txt
- Laikas, praleistas skaitymui is failo: 2773 ms
- Laikas, praleistas rikiavimui: 1598 ms
- Laikas, praleistas grupiu atskyrimui: 161 ms
- Laikas, praleistas rasant i failus: 874 ms

Iveskite failo pavadinima: C:\...\1000000_studentu.txt
- Laikas, praleistas skaitymui is failo: 27387 ms
- Laikas, praleistas rikiavimui: 19745 ms
- Laikas, praleistas grupiu atskyrimui: 1891 ms
- Laikas, praleistas rasant i failus: 8944 ms

# Laiko palyginimas naudojant 2 strategija.

## naudojant vector:

Iveskite failo pavadinima: C:\...\1000_studentu.txt
- Laikas, praleistas skaitymui is failo: 44 ms
- Laikas, praleistas rikiavimui: 7 ms
- Laikas, praleistas grupiu atskyrimui: 1 ms
- Laikas, praleistas rasant i failus: 8 ms

Iveskite failo pavadinima: C:\...\10000_studentu.txt
- Laikas, praleistas skaitymui is failo: 333 ms
- Laikas, praleistas rikiavimui: 118 ms
- Laikas, praleistas grupiu atskyrimui: 25 ms
- Laikas, praleistas rasant i failus: 86 ms

Iveskite failo pavadinima: C:\...\100000_studentu.txt
- Laikas, praleistas skaitymui is failo: 3243 ms
- Laikas, praleistas rikiavimui: 1649 ms
- Laikas, praleistas grupiu atskyrimui: 210 ms
- Laikas, praleistas rasant i failus: 2131 ms

Iveskite failo pavadinima: C:\...\1000000_studentu.txt
- Laikas, praleistas skaitymui is failo: 31008 ms
- Laikas, praleistas rikiavimui: 18729 ms
- Laikas, praleistas grupiu atskyrimui: 1886 ms
- Laikas, praleistas rasant i failus: 8774 ms

## naudojant list:

Iveskite failo pavadinima: C:\...\1000_studentu.txt
- Laikas, praleistas skaitymui is failo: 29 ms
- Laikas, praleistas rikiavimui: 0 ms
- Laikas, praleistas grupiu atskyrimui: 1 ms
- Laikas, praleistas rasant i failus: 10 ms

Iveskite failo pavadinima: C:\...\10000_studentu.txt
- Laikas, praleistas skaitymui is failo: 276 ms
- Laikas, praleistas rikiavimui: 3 ms
- Laikas, praleistas grupiu atskyrimui: 12 ms
- Laikas, praleistas rasant i failus: 86 ms

Iveskite failo pavadinima: C:\...\100000_studentu.txt
- Laikas, praleistas skaitymui is failo: 2889 ms
- Laikas, praleistas rikiavimui: 53 ms
- Laikas, praleistas grupiu atskyrimui: 139 ms
- Laikas, praleistas rasant i failus: 905 ms

Iveskite failo pavadinima: C:\...\1000000_studentu.txt
- Laikas, praleistas skaitymui is failo: 29243 ms
- Laikas, praleistas rikiavimui: 664 ms
- Laikas, praleistas grupiu atskyrimui: 1374 ms
- Laikas, praleistas rasant i failus: 9158 ms

## naudojant deque:

Iveskite failo pavadinima: C:\...\1000_studentu.txt
- Laikas, praleistas skaitymui is failo: 35 ms
- Laikas, praleistas rikiavimui: 9 ms
- Laikas, praleistas grupiu atskyrimui: 2 ms
- Laikas, praleistas rasant i failus: 16 ms

Iveskite failo pavadinima: C:\...\10000_studentu.txt
- Laikas, praleistas skaitymui is failo: 270 ms
- Laikas, praleistas rikiavimui: 126 ms
- Laikas, praleistas grupiu atskyrimui: 19 ms
- Laikas, praleistas rasant i failus: 89 ms

Iveskite failo pavadinima: C:\...\100000_studentu.txt
- Laikas, praleistas skaitymui is failo: 2748 ms
- Laikas, praleistas rikiavimui: 1569 ms
- Laikas, praleistas grupiu atskyrimui: 212 ms
- Laikas, praleistas rasant i failus: 833 ms

Iveskite failo pavadinima: C:\...\1000000_studentu.txt
- Laikas, praleistas skaitymui is failo: 28957 ms
- Laikas, praleistas rikiavimui: 20170 ms
- Laikas, praleistas grupiu atskyrimui: 2441 ms
- Laikas, praleistas rasant i failus: 9266 ms
