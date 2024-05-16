# Cubical-Script
Cubical-Script este un instrument conceput pentru a simula, pe calculatorul local, comportamentul văzut în ["perfect-tower"](https://github.com/d0sboots/PerfectTower?tab=readme-ov-file#improved-code-editor), un parser realizat de David Walker (poreclit d0sboots) pentru jocul "The Perfect Tower II”.

Acest program este structurat pentru a sprijini evidențierea sintaxei, sugerarea simbolurilor, fragmentele de cod implementate și, cel mai important, compatibilitatea încrucișată între joc și editorul lui David Walker.

În starea sa actuală, Cubical-Script este un prototip cu capacitatea de a citi codul sursă exportat din "perfect-tower" și de a-l extinde într-un text formatat care este mai ușor de citit.

# Cum se utilizează
Cubical-Script este conținut într-un folder intitulat "Cubical-Script", puteți accesa documentul README.MD pentru a vedea această documentație într-un mediu care vă permite să accesați linkurile utilizate.

Programul citeste continutul fișierul „Test.in” și va afisa codul formatat în interiorul lui „Test.out”.


# Demonstratie

Pentru a obtine un cod sursa, trebuie exportat un "program" din joc
![Obtain Export Code](https://github.com/Codrineye/Cubical-Script/assets/87333825/42213326-8b88-4105-9921-b4ac52a24025)

Odata ce obtinut, accesati editorul lui "d0sboots"
![Access External Editor](https://github.com/Codrineye/Cubical-Script/assets/87333825/c53ca976-245a-4c1f-8415-96ca50529cc8)

Este recoamdat sa se creeze un spatiu nou de lucru
![Create New Workspace](https://github.com/Codrineye/Cubical-Script/assets/87333825/31e621a9-a513-40b5-bf19-067df63a9446)

Codul trebuie importat
![Import New Code](https://github.com/Codrineye/Cubical-Script/assets/87333825/99141857-3613-478c-a2b6-489cc7104486)

Codul sursa se copiaza
![Export Source](https://github.com/Codrineye/Cubical-Script/assets/87333825/15da7dcc-e01e-4acf-9d2e-daaf83e27670)

Codul sursa este aplasat in fisierul "Test.in"
![Input Source Code](https://github.com/Codrineye/Cubical-Script/assets/87333825/811d25c6-b28b-44ca-9bcc-f3e963ac266e)

Este necesara editarea continutului astfel:
Stergerea inceputului `{"workspace":` si schimbarea a 3 secvente:
1. fiecare instanta `"]` schimbata in `\}`
2. fiecare instanta `","` schimbata in `":{`
3. fiecare schimbare de "pachet" demonstrata prin `"], ["` in `; "`
Finalul documentului contine secventa `\};]}`, aceasta poate fi stearsa astfel incat sa ramana decat `\}`

![Change So It Can Be Read](https://github.com/Codrineye/Cubical-Script/assets/87333825/ad177afc-f107-4f67-a62a-eb939e3341ff)

Cu documentul formatat corect, se poate executa aplicatia
![Run Cubical Script](https://github.com/Codrineye/Cubical-Script/assets/87333825/ce491778-c90f-44e8-afcd-3fdf77cd6036)

Acesta este documentul anticipat
![Final Result](https://github.com/Codrineye/Cubical-Script/assets/87333825/a852dc3b-3e3f-4b30-b7f7-681977ed73a4)
