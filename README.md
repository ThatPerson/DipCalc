# DipCalc

Calculate dipolar coupling constants

## Compilation

`gcc main.c -lm -o dc`

## Usage

`./dc ATOM1 ATOM2 VALUE <MODE>`

ATOM1 and ATOM2 should be the isotopes in the format `13C`, `15N`, see `isotopes.c` for labels. VALUE can be either the bond length (in Angstroms) or the dipolar coupling constant; by default, if no mode is set then for `VALUE > 100` it will assume dipolar coupling and for `VALUE <= 100` it will assume bond length. 

If you don't want this, pass `<MODE>`. Passing `d` will treat `VALUE` as a dipolar coupling, anything else will treat it as a bond length. For example

```
$ ./dc 13C 1H 400
Bond Length: 4.23 A
$ ./dc 13C 1H 1.3
Dipolar Coupling: 13750.73 Hz
$ ./dc 13C 1H 1.3 d
Bond Length: 28.54 A
$ ./dc 13C 1H 400 c
Dipolar Coupling: 0.00 Hz
$ 
```
