# Memo

```cmd
# Configure
# In some case you need `-G"Visual Studio 16 2019"` flag.
# Also take a look into `cmake --help` to indentify supportted generators.
cmake -S "." -B "_builds"

# Build
cmake --build _builds --parallel 4
```
