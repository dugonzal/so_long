

# flood fill pseudocodigo

```c
fn fill(x, y):
    if not Inside(x, y) then return
    let s = new empty stack or queue
    Add (x, y) to s
    while s is not empty:
        Remove an (x, y) from s
        let lx = x
        while Inside(lx - 1, y):
            Set(lx - 1, y)
            lx = lx - 1
        while Inside(x, y):
            Set(x, y)
            x = x + 1
      scan(lx, x - 1, y + 1, s)
      scan(lx, x - 1, y - 1, s)

fn scan(lx, rx, y, s):
    let span_added = false
    for x in lx .. rx:
        if not Inside(x, y):
            span_added = false
        else if not span_added:
            Add (x, y) to s
            span_added = true
```
<coment>
main funcion : -> scanner
second funcion : -> floo_fill

- recorrer en y y x todo el mapa
<coment>
