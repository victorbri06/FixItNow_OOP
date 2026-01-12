# Teste – format fișiere + erori așteptate

Acest folder conține fișiere CSV folosite ca input pentru aplicație.
Fiecare fișier are câte **o înregistrare pe linie**, câmpurile sunt separate prin **virgulă ( , )**.
Liniile pot fi valide sau invalide (intenționat), ca să testez validările din cod.

## 1) angajati_in.csv

### Format general (toate tipurile)

- `tip` = `receptioner` / `tehnician` / `supervizor` (alte valori trebuie să dea eroare)
- `nume`, `prenume` = trebuie să respecte condițiile din cod (lungime minimă/maximă etc.)
- `cnp` = trebuie să fie valid conform validatorului tău
- `zi,luna,an` = data angajării
- `oras` = text
- `extra`:
  - pentru `tehnician` este o listă de competențe în forma:
    ```
    TipAparat:Marca|TipAparat:Marca|...
    ```
    exemplu: `TV:Samsung|Frigider:LG`
  - pentru `receptioner` și `supervizor` poate fi `-` (sau ce acceptă codul tău)

### Linii invalide (în fișierul curent) și erori așteptate
- **Linia 16**: `receptioner,Li,Bo,...` → nume/prenume prea scurte (ar trebui mesaj de tip „numele sau prenumele sunt prea lungi sau prea scurte”)
- **Linia 17**: CNP evident invalid (`1234567890123`) → „CNP invalid”
- **Linia 18**: `tip=manager` (necunoscut) → „tip angajat necunoscut”

Restul liniilor sunt intenționat valide.

---

## 2) electrocasnice_in.csv

### Format general

- `tip` = unul dintre tipurile acceptate în codul tău (ex: `TV`, `Frigider`, `MasinaSpalat` etc.)
- `marca`, `model` = texte (ne-gol, în limite)
- `an` = numeric
- `pret` = numeric
- `extra` = depinde de tip (ex. diagonală la TV, capacitate/volum la frigider etc. – exact cum ai în cod)

### Linii invalide și erori așteptate
- **Linia 16**: `TV,Samsung,,2020,4000,50` → `model` gol → eroare câmp invalid / lipsă
- **Linia 17**: `Toaster,...` → tip aparat necunoscut
- **Linia 18**: `an=20XX` → an nenumeric / format greșit
- **Linia 19**: `pret=abc` → preț nenumeric / format greșit
- **Linia 20**: lipsesc câmpuri (are doar 5 coloane) → „linie incompletă / număr greșit de câmpuri”

Restul liniilor sunt intenționat valide.

---

## 3) cereri_in.csv

### Format general

- `timestamp` = format așteptat de cod (în fișier: `YYYY-MM-DD HH:MM:SS`)
- `tip,marca,model` = identifică electrocasnicul pentru care se face cererea
- `complexitate` = conform regulilor tale (de obicei 1..5; dacă accepți 0 doar în anumite condiții, vezi liniile de mai jos)

### Linii invalide și erori așteptate
- **Linia 13**: complexitate `0` → dacă regula ta este 1..5, atunci „complexitate invalidă”
- **Linia 15**: complexitate `6` → „complexitate invalidă (prea mare)”
- **Linia 16**: lipsește `complexitate` → linie incompletă / câmp lipsă
- **Linia 17**: lună `13` în dată → timestamp invalid
- **Linia 18**: oră `25` → timestamp invalid
- **Linia 19**: format dată cu `/` (`2026/01/10`) → timestamp invalid / format greșit
- **Linia 20**: `model` gol → câmp invalid / lipsă
- **Linia 21**: marcă posibil inexistentă (`MarcaInexistenta`) → dacă validezi existența în lista încărcată, trebuie eroare „aparat inexistent”
- **Linia 22**: câmp în plus (`...,2,EXTRA`) → număr greșit de câmpuri / format invalid

Restul liniilor sunt intenționat valide.

---