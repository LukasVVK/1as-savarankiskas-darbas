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


# Laiko Palyginimas

## 1 Strategija (Dvigubas Konteinerių Naudojimas)

### Naudojant `std::vector`:
#### 1000 studentų:
- Skaitymui iš failo: 49 ms
- Rikiavimui: 7 ms
- Grupių atskyrimui: 6 ms
- Rašant į failus: 13 ms

#### 10000 studentų:
- Skaitymui iš failo: 362 ms
- Rikiavimui: 127 ms
- Grupių atskyrimui: 70 ms
- Rašant į failus: 90 ms

#### 100000 studentų:
- Skaitymui iš failo: 3396 ms
- Rikiavimui: 1560 ms
- Grupių atskyrimui: 593 ms
- Rašant į failus: 909 ms

#### 1000000 studentų:
- Skaitymui iš failo: 63176 ms
- Rikiavimui: 59522 ms
- Grupių atskyrimui: 17234 ms
- Rašant į failus: 28282 ms

### Naudojant `std::list`:
#### 1000 studentų:
- Skaitymui iš failo: 36 ms
- Rikiavimui: 0 ms
- Grupių atskyrimui: 1 ms
- Rašant į failus: 11 ms

#### 10000 studentų:
- Skaitymui iš failo: 292 ms
- Rikiavimui: 4 ms
- Grupių atskyrimui: 14 ms
- Rašant į failus: 101 ms

#### 100000 studentų:
- Skaitymui iš failo: 2774 ms
- Rikiavimui: 59 ms
- Grupių atskyrimui: 169 ms
- Rašant į failus: 834 ms

#### 1000000 studentų:
- Skaitymui iš failo: 27297 ms
- Rikiavimui: 659 ms
- Grupių atskyrimui: 2369 ms
- Rašant į failus: 8760 ms

### Naudojant `std::deque`:
#### 1000 studentų:
- Skaitymui iš failo: 60 ms
- Rikiavimui: 17 ms
- Grupių atskyrimui: 3 ms
- Rašant į failus: 25 ms

#### 10000 studentų:
- Skaitymui iš failo: 299 ms
- Rikiavimui: 125 ms
- Grupių atskyrimui: 15 ms
- Rašant į failus: 89 ms

#### 100000 studentų:
- Skaitymui iš failo: 2773 ms
- Rikiavimui: 1598 ms
- Grupių atskyrimui: 161 ms
- Rašant į failus: 874 ms

#### 1000000 studentų:
- Skaitymui iš failo: 27387 ms
- Rikiavimui: 19745 ms
- Grupių atskyrimui: 1891 ms
- Rašant į failus: 8944 ms

## 2 Strategija (Vieno Konteinerio Naudojimas ir Elementų Trynimas)

### Naudojant `std::vector`:
#### 1000 studentų:
- Skaitymui iš failo: 44 ms
- Rikiavimui: 7 ms
- Grupių atskyrimui: 1 ms
- Rašant į failus: 8 ms

#### 10000 studentų:
- Skaitymui iš failo: 333 ms
- Rikiavimui: 118 ms
- Grupių atskyrimui: 25 ms
- Rašant į failus: 86 ms

#### 100000 studentų:
- Skaitymui iš failo: 3243 ms
- Rikiavimui: 1649 ms
- Grupių atskyrimui: 210 ms
- Rašant į failus: 2131 ms

#### 1000000 studentų:
- Skaitymui iš failo: 31008 ms
- Rikiavimui: 18729 ms
- Grupių atskyrimui: 1886 ms
- Rašant į failus: 8774 ms

### Naudojant `std::list`:
#### 1000 studentų:
- Skaitymui iš failo: 29 ms
- Rikiavimui: 0 ms
- Grupių atskyrimui: 1 ms
- Rašant į failus: 10 ms

#### 10000 studentų:
- Skaitymui iš failo: 276 ms
- Rikiavimui: 3 ms
- Grupių atskyrimui: 12 ms
- Rašant į failus: 86 ms

#### 100000 studentų:
- Skaitymui iš failo: 2889 ms
- Rikiavimui: 53 ms
- Grupių atskyrimui: 139 ms
- Rašant į failus: 905 ms

#### 1000000 studentų:
- Skaitymui iš failo: 29243 ms
- Rikiavimui: 664 ms
- Grupių atskyrimui: 1374 ms
- Rašant į failus: 9158 ms

### Naudojant `std::deque`:
#### 1000 studentų:
- Skaitymui iš failo: 35 ms
- Rikiavimui: 9 ms
- Grupių atskyrimui: 2 ms
- Rašant į failus: 16 ms

#### 10000 studentų:
- Skaitymui iš failo: 270 ms
- Rikiavimui: 126 ms
- Grupių atskyrimui: 19 ms
- Rašant į failus: 89 ms

#### 100000 studentų:
- Skaitymui iš failo: 2748 ms
- Rikiavimui: 1569 ms
- Grupių atskyrimui: 212 ms
- Rašant į failus: 833 ms

#### 1000000 studentų:
- Skaitymui iš failo: 28957 ms
- Rikiavimui: 20170 ms
- Grupių atskyrimui: 2441 ms
- Rašant į failus: 9266 ms
