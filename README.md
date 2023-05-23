# Tema: LAN Party

Acest program are rol de a automatiza procesul de manevrare a datelor în contextul unui LAN party.
Tema constă în 5 cerințe care trebuie îndeplinite.

## Cerința 1:
Programul citește într-o funcție datele (numărul de echipe, numărul de jucători dintr-o echipă, numele echipei, numele și punctajele jucătorilor) dintr-un fișier și creează o listă cu echipele și una cu jucătorii. După crearea listelor, se vor afișa numele echipelor participante din lista de echipe (în cazul în care se cere numai cerința 1 să fie rezolvată).
Nodul listei de echipe (NodeTeam*) conține pointerul către numele echipei (char*), numărul de jucători din echipa (int), numărul de puncte al echipei (float), pointerul către nodul primului jucător al echipei respective (NodePlayer*, nod care se află în lista de jucători) și pointerul către nodul următoarei echipe (NodeTeam*). Nodul listei de jucători (NodePlayer*) conține o structură de tip player (Player*, așa cum este dată în cerință, care are pointer către prenume (char*), pointer către nume (char*) și numărul de puncte (int)) și un pointer către nodul următorului jucător (NodePlayer*).

## Cerința 2: 
Dacă numărul total de echipe nu este o putere a lui 2, programul calculează cea mai mare putere a lui 2 mai mică decât numărul inițial de echipe. Apoi caută și elimină din lista echipele cu cel mai mic punctaj, în timp ce numărul de echipe nu este egal cu numărul calculat. La fiecare ștergere a unei echipe, se decrementează valoarea numărului de echipe cu 1. Acest proces continuă până numărul de echipe ajunge la numărul calculat (putere a lui 2). Ca să găsească echipa cu cel mai mic punctaj, întâi programul folosește o funcție care parcurge lista de echipe și returnează punctajul cel mai mic. Apoi într-o altă funcție parcurge întreagă lista de echipe până găsește prima echipa cu cel mai mic punctaj. Când găsește echipa căutată, o șterge din lista și apelează o funcție care ia ca parametru pointerul către nodul primului jucător din echipa, vârful listei de jucători și numărul de jucători din echipa, cu scopul de a căuta și a elimina din lista jucătorilor membrii echipei eliminate. Apoi se afișează numele echipelor rămase în listă.


## Cerința 3: 
Se iau echipele din lista de echipe două câte două și se formează meciuri folosind o coadă (QueueMatches). Structura cozii constă în nodul primei echipe, nodul celei de a două echipe și pointerul către următorul element din coadă. Se afișează conținutul cozii (meciurile). Se parcurge coada și la fiecare pereche de echipe, nodul echipei câștigătoare este adăugat într-o stivă de câștigători (topWinners), iar nodul echipei pierzătoare într-o stivă de pierzători (topLosers). La finalul rundei, se afișează stivă de câștigători, iar stivă de pierzători și coadă se șterg. La următoarea rundă, din stivă de învingători se iau nodurile echipelor două câte două, se introduc în coadă și se reiau pașii anteriori. Programul se oprește când găsește echipa câștigătoare.

## Cerința 4:
Înainte să se ajungă la echipa câștigătoare, când programul ajunge la o rundă la care au rămas 8 echipe, nodurile celor 8 echipe le va copia într-o stivă (top8). Apoi, parcurge stivă și folosind o funcție, mută nodurile echipelor într-un arbore binar de căutare (rootBST). Parcurge arborele în inordine invers și afișează numele și punctajele echipelor descrescător.

## Cerința 5: 
Programul parcurge arborele binar de căutare (rootBST) în inordine și mută nodurile echipelor în stivă top8 (golită anterior când s-a creat arborele binar de căutare). Astfel echipele se află în stivă în ordine descrescătoare. Apoi, ia din stivă top8 și mută fiecare nod de echipă într-un nou arbore (rootAVL), care va fi echilibrat la fiecare înserare prin rotații. La final, afișează echipele care se află pe nivelul 2 al arborelui echilibrat.

