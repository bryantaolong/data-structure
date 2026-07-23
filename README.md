# Data Structure

Common data structures implemented in C, built as a shared library (DLL / SO).

## Data Structures

| Structure | Header | Source |
|-----------|--------|--------|
| Linked List | `include/list.h` | `src/list.c` |
| Stack | `include/stack.h` | `src/stack.c` |
| Queue | `include/queue.h` | `src/queue.c` |
| Custom String | `include/custom_string.h` | `src/custom_string.c` |

## Project Structure

```
.
├── include/                  # Public headers with DLL export macros
├── src/                      # Library sources + demo (data-structure-demo)
├── data-structure-consumer/  # Standalone project that consumes the DLL
│   ├── include/              # Header imports (dllimport)
│   ├── lib/                  # Pre-built DLL and import library
│   ├── src/main.c            # Consumer demo
│   └── CMakeLists.txt
├── build/                    # Build output (git-ignored)
├── CMakeLists.txt
└── README.md
```

## Build

### Prerequisites

- CMake >= 3.10
- C11 compiler (MSVC, GCC, Clang)

### Library + Demo

```bash
cd build
cmake ..
cmake --build .
```

Outputs in `build/`:
- `libdata-structure.dll` (or `.so` / `.dylib`) — the shared library
- `data-structure-demo.exe` — demo executable that links against the library

### Consumer

`data-structure-consumer/` is a standalone CMake project demonstrating how to consume the DLL:

```bash
cd data-structure-consumer/build
cmake ..
cmake --build .
```

The build automatically copies the DLL next to the consumer executable.

## Using the Library in Your Project

1. Link against the import library (`libdata-structure.dll.a` or `.lib`)
2. Include headers from `include/`
3. Ship the DLL alongside your executable or add it to `PATH`

See `data-structure-consumer/CMakeLists.txt` for a working reference.
