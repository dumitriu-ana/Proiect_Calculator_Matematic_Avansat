## Calculator Avansat Expresii Matematice
Utilizatorul poate introduce expresii matematice ce pot include paranteze imbricate, numere, operații de adunare, scădere, înmulțire, împărțire, puteri și radicali. <br>
Aplicația respectă regulile specifice ordinii operatiilor matematice și gestionează expresii cu paranteze imbricate. <br>
Utilizatorul introduce expresia matematică la tastatură si aplicația procesează expresia conform regulilor ordinei operațiilor și returnează rezultatul. <br>

- Aplicația identifică și evaluează mai întâi conținutul parantezelor, înlocuind parantezele cu rezultatul expresiei din interior.
- Respectă ordinea operațiilor matematice, calculând mai întâi puteri și radicali, apoi înmulțiri și împărțiri, și în final adunări și scăderi.
Utilizarea unui vector pentru salvarea operațiilor:
- Operațiile dintre numere sunt gestionate printr-un vector separat, în care fiecare element conține o operație (aferenta pentru operandul 1 și operandul 2).
- Dacă expresia conține paranteze imbricate, se rezolva fiecare paranteza pe rand, înlocuind parantezele cu rezultatul și continuând până când nu mai există paranteze.
- Rezultatul operatiilor anterioare sunt salvate si pot fi utilizate ulterior

## Clasa Operatie
![image](https://github.com/dumitriu-ana/Proiect_Calculator_structurat/assets/72306782/883704aa-3fb7-4a43-a987-645c63e2a914)

## Clasa Expresie
![image](https://github.com/dumitriu-ana/Proiect_Calculator_structurat/assets/72306782/010cab2d-43ed-4e74-a6b4-858588f99a62)

## Clasa Ecuatie
![image](https://github.com/dumitriu-ana/Proiect_Calculator_structurat/assets/72306782/b4ec4e79-23ee-49f1-89bb-ab357ec2f81e)

## Expresie - creare vector operatii
![image](https://github.com/dumitriu-ana/Proiect_Calculator_structurat/assets/72306782/97756965-1e4f-4520-abd2-b244fffb51b1)

## Expreise - calculare prioritate (ordinea operatiilor)
![image](https://github.com/dumitriu-ana/Proiect_Calculator_structurat/assets/72306782/422298de-4a0e-4379-aa1b-23b1a5d2623f)

## Expresie - calcul din interiorul parantezelor
![image](https://github.com/dumitriu-ana/Proiect_Calculator_structurat/assets/72306782/52ab0972-420b-4b01-8d2f-38d73af5173d)

## Validare ecuatie - numar paranteze
![image](https://github.com/dumitriu-ana/Proiect_Calculator_structurat/assets/72306782/c8d4c480-e5f3-4c6f-b58c-04b840c5eebb)

## Functia de calculare
![image](https://github.com/dumitriu-ana/Proiect_Calculator_structurat/assets/72306782/958529eb-cc20-4b9b-a6b9-c9a889795c33)

## Exemple 
![image](https://github.com/dumitriu-ana/Proiect_Calculator_structurat/assets/72306782/d99a4640-89d1-45de-969e-0d6aaba616f1)
![image](https://github.com/dumitriu-ana/Proiect_Calculator_structurat/assets/72306782/66e4d592-b6d4-4d1a-a51b-e452c841680c)



