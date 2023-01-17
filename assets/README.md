# Hra CHESS ( téma: Šachy )
Autor: Tadeáš Hejnic

## Specifikace zadání CHESS

Hra CHESS je po spuštění ovládána pomocí psaní jednoduchých zkratek do terminálu.
Na výběr je hra pro dva hráče a hra proti počítači se třemi úrovněmi obtížnosti ( "Beginner", "Pro", "Legend" ).
Hlavní menu se ovládá pomocí znaků napsaných přímo v menu, samotná hra se ovládá pomocí zadávání souřadnic políček.
V prvním kroku hráč napíše souřadnice figurky, se kterou chce táhnou.
Následně dostane "nápovědu" možných tahů s touto figurkou a v tuto chvíli již má hráč figurku v ruce,
takže již nemůže táhnout s jinou. Po výběru tahu se vyhodnotí akce a je na řadě druhý hráč.
Ten dostane případně varování o šachu. Případně se provede vyhodnocení. Vyhodnocení hry se zobrazí v terminálu.

Kromě zadávání pozic máme během tahu k dispozici dvě klíčová slova:
- `quit` ukončí program bez uložení
- `save` přeruší hru a uloží ji

### Kde mám polymorfismus?

Polymorfismus využívám u třídy `CChessman`. Ta má dvě abstraktní metody `possibleMoves`, `print` a několik dalších
virtuálních metod pro vyhodnocení pravidel hry nebo vyhodnocení AI počítače.
Tím se mi usnadnilo volání pro generování množiny možných tahů s danou figurkou.
- metoda possibleMoves vrátí množinu možných tahů pro danou figurku
- metoda print je jednoduchá metoda sloužící pro vykreslení figurky - každá figurka má
  charakteristický Unicode znak / písmeno

Druhý polymorfimus bude u jednotlivých tahů hráčů, resp. generování tahů pomocí "AI". Abstraktní třída CPlayer
bude mít abstraktní metodu `makeMove` a `makePromotion`. Díky tomu neřeším, zda je na tahu počítač, hráč č. 1 nebo č. 2. Navíc se
automaticky vygeneruje tah adekvátní k obtížnosti zvolené na začátku v případě hry proti počítači.
- metoda makeMove
    * u CHuman zpracuje výběr tahu hráče
    * u CBeginner, CPro a CLegend vyhodnotí situaci a vybere patříčný tah (pro každou úroveň jinak)
- metoda makePromotion 
    * u CHuman zpracuje výběr proměny hráče
    * u CBeginner vybere náhodnou proměnu
    * u CPro a CLegend vybere vždy dámu


### Možné neočekávané chování

Pokud se nepovede načíst hru ze souboru, vygeneruje se nová hra.