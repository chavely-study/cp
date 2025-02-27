# Trip to the Olympiad

## Pseudocódigo

```cpp

ll l, r;
cin >> l >> r;
auto k = 31 - __builtin_clz(r ^ l);
ll a = l | ((1 << k) - 1), b = a + 1, c = (a == l) ? r : l;
print(a << " " << b << " " << c);
```

## Explicación

1. Le puse el shif al revés a todo salvo al código porque me dio error. (-_-;)
2. Si el k-ésimo bit de todos los números en el rango posee el mismo valor, entonces el k-ésimo bit aportará 0 a la suma, o sea, nada. Demostración:

   * Sean a, b, c cualesquiera números del rango y a1, a2, ...; b1, b2, ...; c1, c2, ..; sus respectivas representaciones en binaro.
   * ai ^ bi = 0 y ai ^ ci = 0 y bi ^ ci = 0 luego aportan 0*(1 >> i) = 0 a la suma.
3. Como hay al menos 3 elementos en el rango, al menos habrá un índice k tal que un bit será distinto en alguno de los números (el último bit cambia de acuerdo a la paridad).
4. El k-ésimo bit aportará 2*(1 >> k) a la suma pues: ak ^ bk = 0 y bk ^ ck = 1 y ak ^ ck = 1 luego aportan: (1 >> k) + (1 >> k).
5. Como se tiene (1 >> k) > sumatoria(i, 0, k)(1 >> i) es óptimo tomar k lo más grande posible y como tal se asumirá en lo adelante.
6. Además se puede poner 2 * sumatoria(i, 0, k)(1 >> i) como cota superior a la suma. Demostración:

   * Para todo r tal que: r > k: ar = br = cr; de lo contrario contradeciría la maximidad de k. Luego, todo bit r-ésimo con r > k aporta 0 a la suma.
   * Por otra parte, para todo r < k, el r-ésimo bit aportará a la suma a lo mucho 2 * (1 >> r) por lo explicado en 1 y 3.
   * Luego a lo sumo, cada bit hasta el k-ésimo aportará 2 * (1 >> i).
7. Como se asume que k es el mayor bit tal que existen números del intervalo para los cuales es diferente, entornces debe haber un único multiplo de (1 >> k) en el intervalo y debe estar el antecesor del número en el intervalo. Demostración:

   * Para todo multiplo de la i-ésima potencia de dos, todos los bits a la derecha del i-ésimo bit son cero, de no ser así representarían el módulo de 0 con respecto a esa potencia.
   * Luego los bits que cambian entre una potencia de dos y otra son los de la izquierda. Pero se asumío que todos los bits a la izquierda del k-ésimo son iguales para todos los números en el rango. Luego hay un único multiplo de (1 >> k) en el intervalo.
   * Como hay almenos un número en el intervalo tal que el k-ésimo bit es uno, y otro tal que el k-ésimo bit es 0, y hay un multiplo de (1 >> k), entonces:
     * está el multiplo de (1 >> k) que sería de la forma: xxxx10...0.
     * Como no hay otro multiplo de dicha potencia de dos y el próximo multiplo de dicha potencia es de la forma: xxx100...0. Entonces este número excede el tope del intervalo, de lo contrario se contradeciría la maximidad de k.
     * Y para todo número entre dicha multiplo y el siguiente el k-ésimo bit es 1, para hayar alguno para el cual fuese 0 habría que ver a partir de su antecesor, el cual es: xxxx01..1. Como es un rango continuo en los enteros, y por la definición de k tiene que haber al menos un número en el rango tal que se haga 0 el k-ésimo bit, entonces el antecesor del multiplo de (1 >> k) es el máximo número que cumple tal condición.
8. Suponiendo se toman: a = x...x10..0 (el único multiplo de (1 >> k) en el intervalo) y b = x...x01..1(su antecesor) y c = x...xy...y(con ´y´ cualesquiera). Entonces:

   * a ^ b = 0..011..1 = sumatoria(i, 0, k)(1 >> i).
   * a ^ c = 0..0~(y)y...y
   * b ^ c = 0...0y~(y...y)
   * (a ^ c) + (b ^ c) = 0..01...1 (pues en cada bit de cada sumando si hay un 0 en uno habrá un 1 en el otro, luego en la suma todos son 1s).
   * Finalmente: (a ^ b) + ((a ^ c) + (b ^ c)) = 0..01..1 + 0..01...1 = 2 * sumatoria(i, 0, k)(1 >> i) que es el máximo valor posible para la función.
9. Para hallar k se utilizó el siguiente análisis: si todos los bits son iguales de k en aadelante, entones al hacer xor r y l se volverán 0. Y como el k-ésimo es 1 en r y 0 el l, se volverá 1 en el xor. Como la función __builtin_clz(x) devuelve la cantidad de ceros a la izquierda en la representación en binario de un número, y los int tiene 32 bits para hallar k basta hacer 31-__builtin_clz(x).
10. En el or todo lo que está a la izquierda del k-ésimo bit se queda como en todos los números del intervalo, el k-ésimo se queda como 0 pues es cero en el antecesor de dos a la k y es cero en el menor elemento del intervalo y del k-ésimo en adelante se vuelven 1 pues son 1 en el antecesor de dos a la k. Luego queda el antecesor del primer multiplo de dos a la k del intervalo en a, basta sumarle uno para obtener dicho multiplo en b y como c puede ser cualquier número del intervalo, se toma el menor, y si a es el menor, b no puede ser el mayor por tanto se toma c como el mayor elemento del intervalo. Y problema resuelto.

## Complejidad

O(1): Todos los trabajos con bits en el código no son más de O(32) = O(1) y la suma y la comparación también es O(1). Finalmente la solución es O(1).

## Link

[Trip to the Olympiad](https://codeforces.com/contest/2057/problem/C)
