# Tree Jumps

## Pseudocódigo

```cpp

deque<ll> q;
ll sol;
ll depth[300001];
ll father[300001];
ll solution[300001];
vivi adj;

ll get_solution(ll d, ll previous_solution)
{
    ll new_solution = 0;
    if (!d)
        return 1;
    if (d == 1)
        for (auto n : adj[0])
            solution[n] = 1, new_solution++;
    else
        for (auto n : q)
        {
            solution[n] = mod(previous_solution - solution[father[n]]);
            solution[n] = mod(big_number + solution[n]);
            new_solution = mod(new_solution + solution[n]);
        }
    return new_solution;
}

void bfs()
{
    ll u = 0, d = 0, d_solution = 0;
    sol = 0;
    depth[u] = 0;
    q.clear();
    q.push_back(u);
    sol += get_solution(d, d_solution);
    while (!q.empty())
    {
        u = q.front();
        if (depth[u] != d)
        {
            d = depth[u];
            d_solution = get_solution(d, d_solution);
            sol = mod(sol + d_solution);
        }
        for (auto v : adj[u])
        {
            q.push_back(v);
            father[v] = u;
            depth[v] = depth[u] + 1;
        }
        q.pop_front();
    }
}

void read(ll n)
{
    adj = vivi(n, vi());
    ll curr;
    rep(1, n)
    {
        cin >> curr;
        adj[curr - 1].push_back(i);
    }
}

void solve()
{
    ll n;
    cin >> n;
    read(n);
    bfs();
    print(sol);
}
```

## Explicación

1. Se crearon varios arreiglos para almacenar las informaciones necesaria, en el solution se almacena la cantidad de soluciones que terminan en el nodo i-ésimo, todas las soluciones comienzan en el nodo 0, en depth se almacena la profundidad y en father el padre. La variable sol almacena el total de caminos posibles en total o sea la solución y previous?solution almacena el total de soluciones en el nivel anterior al que se está evaluando actualmente.
2. Dado un árbol cualquiera, la cantidad de soluciones para el nodo raíz es 1: [1]. Para cada uno de los nodos de profundidad 1 la cantidad de soluciones es 1: [1, v]. Para el resto de los nodos la cantidad de soluciones será la cantidad total de soluciones en el nivel anterior menos la cantidad de soluciones para su padre, pues los únicos nodos que pueden añadir a un nodo cualquiera a un camino son los que se encuentran en el nivel anterior que no lo tienen como vecino por definición del problema, y el único nodo del nivel anterior que lo tiene como vecino es su padre pues se está trabajando con un árbol.
3. Finalmente para poder trabajar por niveles se utilizó un bfs, como característica del bfs los nodos se agregan por niveles y se eliminan igualmente. Luego, cuando el nivel del primer nodo cambia, quiere decir que solo hay nodos del nivel de este, y que están todos los nodos de este nivel en la cola actualmente. No es objetivo de este texto demostrar las propiedades del bfs por lo tanto solo se asumirán.
4. Como el módulo puede resultar negativo, se le suma al valor dado y luego se halla el módulo de nuevo para que quede positivo:
   * (x)mod(99...) = -y
   * |-y| < 99...
   * y < 99...
   * 0 < 99... - y
   * 99... - y < 99...
   * (-y + 99...)mod(99...) = (-y)mod(99...)
5. De resultar positivo no cambiaría nada.

## Complejidad

Por cada nodo se realizan un número finito de operaciones. Por tanto la complejidad del algoritmo es O(n).

Por nodo se hace: leerlo, agregarlo como hijo de su padre, agregar su profindidad, agregar su padre, agregarlo a la cola, sacarlo de la cola, sumarlo a la variable sol, sumarlo a la solución para su nivel. Todos son O(1).

(^_^)

## Link

[Trre Jumps](https://codeforces.com/contest/2070/problem/D)
