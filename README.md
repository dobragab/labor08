# 8. labor

A laborfeladat célja a heterogén kollekció bemutatása.

A heterogén kollekció alapötlete: az ősosztályra mutató pointereket tárolunk,
amiken keresztül elérjük a leszármazott osztályokat. Ezeket a pointereket egy
tárolóban (itt `std::vector`) tároljuk.

1. Készíts egy osztályt, ami képes a heterogén kollekció tárolására!

2. A tároló osztálynak legyen egy rajzol metódusa, ami kirajzolja a benne 
tárolt alakzatokat sorrendben! Legyen `hozzaad(Alakzat*)` függvénye is,
amivel új alakzatot adhatunk hozzá a kollekcióhoz! Ez a függvény dinamikusan
foglalt objektumot várjon, amit a destruktorában szabadítson is fel!

3. A kirajzoláshoz használd a `kirajzol.h` függvényeit!

3. Valósítsd meg a `Teglalap` és `Kor` osztályokat!

3. Legyen másolható a tároló! A másolásakor az alakzatokról **típushelyes**, dinamikusan foglalt másolat kell. Ötlet: ki ismeri az egyes alakzatok pontos típusát, és hogy férünk hozzá?

4. Valósítsd meg a `Sokszog` osztályt! Használj `std::vector`-t!

4. Valósítsd meg a `LekerekitettTeglalap` osztályt, ami egyfajta `Teglalap`!

5. Valósítsd meg azt, hogy az `AlakzatTarolo` is egy kirajzolható `Alakzat` legyen! Figyelj arra is, hogy ha az `AlakzatTarolo`-t mozgatjuk, akkor az összes tárolt alakzatának azzal együtt, csoportban kell mozognia! Mit kell ehhez módosítani az `Alakzat` osztályon?

6. Bónusz: Rajzolj ki valami felismerhető ábrát az alakzatok segítségével!

7. Bónusz: Valósítsd meg a `Sokszog` és `Szakasz` osztályokat! Használj STL tárolókat!
