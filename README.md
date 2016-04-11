A laborfeladat célja a heterogén kollekció bemutatása.

A heterogén kollekció alapötlete: az ősosztályra mutató pointereket tárolunk,
amiken keresztül elérjük a leszármazott osztályokat. Ezeket a pointereket egy
tárolóban (itt std::vector) tároljuk.

1. Feladat: Készíts egy osztályt, ami képes a heterogén kollekció tárolására!

2. A tároló osztálynak legyen egy rajzol metódusa, ami kirajzolja a benne 
tárolt alakzatokat sorrendben! Legyen hozzaad(Alakzat*) függvénye is,
amivel új alakzatot adhatunk hozzá a kollekcióhoz! Ez a függvény dinamikusan
foglalt objektumot várjon, amit a destruktorában szabadítson is fel!

3. A kirajzoláshoz használd a kirajzol.h függvényeit!

3. Valósítsd meg a Teglalap és Kor osztályokat!

4. Valósítsd meg a LekerekitettTeglalap osztályt, ami egyfajta Teglalap!

5. Valósítsd meg a szakasz osztályt!

6. Bónusz: Rajzolj ki valami felismerhető ábrát az alakzatok segítségével!

7. Bónusz: Valósítsd meg a sokszög osztályt!
