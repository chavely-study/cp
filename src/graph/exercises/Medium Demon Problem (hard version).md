# Medium Demon Problem (hard version)

## Pseudocódigo

```cpp
vivi adj = read_from_input()
vivi scc = get_scc(adj)
vivi graph = compress_graph(scc)
vivi transposed = get_transposed(graph)
deque<ll> topological_sort = get_topological_sort(transposed)

ll solution = 0, m = graph.size();
vi dp(m, 0);
per(0, m)
{
    for (auto v : transposed[topological_sort[i]])
	if (graph[topological_sort[i]].size())
	    dp[topological_sort[i]] += dp[v] + 1;
	else dp[topological_sort[i]] = max(dp[topological_sort[i]], dp[v] + 1);
    solution = max(solution, dp[topological_sort[i]]);
}

print(solution + 2);
```

## Explicación

Inicialmente se modelan las arañas como nodos y la relación entre una araña y la araña a la cual envia un punto como una arista dirigida.

Suponiendo todas las arañas se encuentran en un ciclo simple, sin importar la cantidad de puntos que tenga cada araña, al transcurrir un año se mantendrá todas con la misma cantidad, pues cada araña tendrá esactamente una arista entrante(a++) y una arista saliente(a--), luego: a = a + 1 - 1 = a; para toda araña. Por esto solo interesa el grafo que queda tras reducir las componentes fuertemente conexas a nodos. (se puede demostrar que todos los ciclos en el grafo del problema son simples, pues de cada nodo sale a lo máximo una arista, también se puede demostrar que existe al menos un ciclo, pues hay igual cantidad de aristas que de nodos).

Luego se pueden reducir los ciclos simples a nodos, pues no influyen en la solución.

Tras reducir todos los ciclos simples a nodos queda un dag.

Se computa el transpuesto del dag para facilitar las operaciones siguientes. (EL transpuesto de un dag sigue siendo un dag).

Dado un nodo, este tiene esactamente una arista saliendo del mismo, a menos que sea un ciclo reducido a nodo, por definición del problema. Si el nodo posee una arista saliente y ninguna entrante, entonces al transcurrir el primer año, el nodo tendrá 0 puntos y nunca cambiará su cantidad de puntos, luego, el nodo se habrá estabilizado.

Si el nodo tuviese una o más aristas entrantes(k), entonces a este le tomaría estabilisarse tantos años como tarden en estabilisarse cada uno de los nodos dirigidos a el más k años, más un año. Pues al nodo entrarían en total tantos puntos como entran a sus precedentes, mas un punto por cada uno de sus presedentes, que era el que tenía cada uno de sus presedentes inicialmente, más el punto que tenía el propio nodo inicialmente. Se sabe que si el tiempo que tarda un nodo en estabilizarse para todos los nodos presedentes al actual está correctamente calculado se puede calcular el actual pues depende únicamente de sus aristas entrantes. Se calcula realmente uno menos dicha cantidad para los nodos que no representan cíclos. Se sabe que todos los ancestros de un nodo dado en el grafo original esán después del mismo en el orden topológico del dag transpuesto.

Y suponiendo tuviese una arista saliente, este no podría llegar a cero antes de pasarle a su siguiente todos los puntos que llegan a él mismo, y como solo puede pasar un punto por año tardará en estabilizarse tantos años como puntos llegarán a él en total, más uno, su punto inicial, pero para facilitar el cómputo de la dp no se cuenta este punto en el mismo nodo, si no en el siguiente, como se explicó anteriormente (líneas 12 y 13 del código).

Suponiendo que el nodo no tuviese ningún siguiente, entonces este sería un ciclo y un nodo del ciclo estaría aumentando puntos mientras estos estuviesen llegando desde algún nodo exterior al ciclo, mientras alguno de los nodos entrantes tuviese aún puntos, o sea, no se hubiese estabilizado. Pero dado el caso de que en un mismo año llegasen puntos desde varios nodos a la vez estos se estabilizarían al momento, luego simplemente interesa saber en que momento llega el último punto al nodo, por lo cual se computa el máximo entre lo que se tarda en estabilizarse cada uno de sus anteriores, es decir la cantidad de puntos que entra a cada uno de los anteriores más uno, el punto originalmente en el anterior (línea 13 del código).

Como todo nodo tiene una arista saliente esactamente, a menos que sea un ciclo reducido, el final, las hojas de los árboles que componen el dag siempre serán las últimas en estabilizarse. Luego basta saber cuando el ciclo que se estabilice de último se estabiliza, pues esta es la solución (línea 15 del código).

## Complejidad

Leer adj y computar: scc, graph, transposed y topological sort, tienen cada uno una complegidad temporal de O(v+e).

El bucle per es en total O(v+e) también.

Finalmente la complejidad temporal del algoritmo es O(v+e).

## Link

https://codeforces.com/contest/2044/problem/G2
