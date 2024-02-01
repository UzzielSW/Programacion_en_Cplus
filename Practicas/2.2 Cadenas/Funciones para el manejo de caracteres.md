# Resumen de funciones para manejo de caracteres

*libreria: `ctype.h`*

* **int isdigit (char c)**
> retorna true si **<u>c</u>** es un digito y false de lo contrario

* **int isalpha (char c)**
> retorna true si **<u>c</u>** es una letra y false de lo contrario

* **int isalnum (char c)**
> retorna true si **<u>c</u>** es un digito o letra y false de lo contrario

* **int isxdigit (char c)**
> retorna true si **<u>c</u>** es un digito hexadecimal y false de lo contrario

* **int islower (char c)**
> retorna true si **<u>c</u>** es una letra minuscula y false de lo contrario

* **int isupper (char c)**
> retorna true si **<u>c</u>** es una letra mayuscula y false de lo contrario

* **int tolower (char c)**
> retorna el caracter en minuscula

* **int toupper (char c)**
> retorna el caracter en mayuscula

* **int isspace (char c)**
> retorna true si **<u>c</u>** es (' ','\n', '\f', '\r', '\t', '\v', '\b')

* **int iscntrl (char c)**
> retorna true si **<u>c</u>** es ('\n', '\f', '\r', '\t', '\v', '\b')

* **int ispunct (char c)**
> retorna true si **<u>c</u>** es un caracter distinto de un espacio, digito o letra

* **int isprint (char c)**
> retorna true si **<u>c</u>** es un caracter de impresion, incluyendo el espacio

* **int isgraph (char c)**
> retorna true si **<u>c</u>** es un caracter de impresion distinto de espacio