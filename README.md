# graphblas-mini-cpp-app

## Grab and compile dependencies

Install [SuiteSparse:GraphBLAS](https://github.com/DrTimothyAldenDavis/SuiteSparse).

```bash
export JOBS=$(nproc)

git clone --depth 1 --branch master https://github.com/DrTimothyAldenDavis/GraphBLAS/
cd GraphBLAS/build
# GBCOMPACT=1 for faster SuiteSparse compilation, but the code will be slower
cmake .. -DGBCOMPACT=1 && make && sudo make install && sudo ldconfig
```

## Run and build

```bash
mkdir -p cmake-build-debug && cd cmake-build-debug && cmake .. && cmake --build . --parallel; cd ..; cmake-build-debug/graphblas_mini_cpp_app
```
