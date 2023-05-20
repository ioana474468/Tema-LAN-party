Tema: LAN Party

Acest program are rol de a automatiza procesul de manevrare a datelor in contextul unui LAN party.
Tema consta in 5 cerinte care trebuie indeplinite.

Cerinta 1:
Programul citeste intr-o functie datele (numarul de echipe, numarul de jucatori dintr-o echipa, numele echipei, numele si punctajele jucatorilor) dintr-un fisier si creeaza o lista cu echipele si una cu jucatorii. Dupa crearea listelor, se vor afisa numele echipelor participante din lista de echipe (in cazul in care se cere numai cerinta 1 sa fie rezolvata).
Nodul listei de echipe (NodeTeam*) contine pointerul catre numele echipei (char*), numarul de jucatori din echipa (int), numarul de puncte al echipei (float), pointerul catre nodul primului jucator al echipei respective (NodePlayer*, nod care se afla in lista de jucatori) si pointerul catre nodul urmatoarei echipe (NodeTeam*). Nodul listei de jucatori (NodePlayer*) contine o structura de tip player (Player*, asa cum este data in cerinta, care are pointer catre prenume (char*), pointer catre nume (char*) si numarul de puncte (int)) si un pointer catre nodul urmatorului jucator (NodePlayer*).

Cerinta 2: 
Daca numarul total de echipe nu este o putere a lui 2, programul calculeaza cea mai mare putere a lui 2 mai mica decat numarul initial de echipe. Apoi cauta si elimina din lista echipele cu cel mai mic punctaj, in timp ce numarul de echipe nu este egal cu numarul calculat. La fiecare stergere a unei echipe, se decrementeaza valoarea numarului de echipe cu 1. Acest proces continua pana numarul de echipe ajunge la numarul calculat (putere a lui 2). Ca sa gaseasca echipa cu cel mai mic punctaj, intai programul foloseste o functie care parcurge lista de echipe si returneaza punctajul cel mai mic. Apoi intr-o alta functie parcurge intreaga lista de echipe pana gaseste prima echipa cu cel mai mic punctaj. Cand gaseste echipa cautata, o sterge din lista si apeleaza o functie care ia ca parametru pointerul catre nodul primului jucator din echipa, varful listei de jucatori si numarul de jucatori din echipa, cu scopul de a cauta si a elimina din lista jucatorilor membrii echipei eliminate. Apoi se afiseaza numele echipelor ramase in lista.


Cerinta 3: 
Se iau echipele din lista de echipe doua cate doua si se formeaza meciuri folosind o coada (QueueMatches). Structura cozii consta in nodul primei echipe, nodul celei de a doua echipe si pointerul catre urmatorul element din coada. Se afiseaza continutul cozii (meciurile). Se parcurge coada si la fiecare pereche de echipe, nodul echipei castigatoare este adaugat intr-o stiva de castigatori (topWinners), iar nodul echipei pierzatoare intr-o stiva de pierzatori (topLosers). La finalul rundei, se afiseaza stiva de castigatori, iar stiva de pierzatori si coada se sterg. La urmatoarea runda, din stiva de invingatori se iau nodurile echipelor doua cate doua, se introduc in coada si se reiau pasii anteriori. Programul se opreste cand gaseste echipa castigatoare.

Cerinta 4:
Inainte sa se ajunga la echipa castigatoare, cand programul ajunge la o runda la care au ramas 8 echipe, nodurile celor 8 echipe le va copia intr-o stiva (top8). Apoi, parcurge stiva si folosind o functie, muta nodurile echipelor intr-un arbore binar de cautare (rootBST). Parcurge arborele in inordine invers si afiseaza numele si punctajele echipelor descrescator.

Cerinta 5: 
Programul parcurge arborele binar de cautare (rootBST) in inordine si muta nodurile echipelor in stiva top8 (golita anterior cand s-a creat arborele binar de cautare). Astfel echipele se afla in stiva in ordine descrescatoare. Apoi, ia din stiva top8 si muta fiecare nod de echipa intr-un nou arbore (rootAVL), care va fi echilibrat la fiecare inserare prin rotatii. La final, afiseaza echipele care se afla pe nivelul 2 al arborelui echilibrat.


