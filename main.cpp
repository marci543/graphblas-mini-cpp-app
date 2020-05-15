extern "C" {
#include <GraphBLAS.h>
}

#include <iostream>

int main() {
    // based on https://github.com/DrTimothyAldenDavis/GraphBLAS/blob/5e569f2fcb0597b4ad3c60fca1a4ff8e938fd111/Doc/GraphBLAS_UserGuide.tex#L8173-L8191
    GrB_init(GrB_NONBLOCKING);

    char *library_date;
    GxB_Global_Option_get(GxB_LIBRARY_DATE, &library_date);
    std::cout << "SuiteSparse:GraphBLAS " << library_date << std::endl;

    GrB_Vector x, y;
    GrB_Vector_new(&x, GrB_INT32, 1);
    GrB_Vector_new(&y, GrB_INT32, 2);

    GrB_Index I[2] = {0, 0};

    GrB_Vector_setElement_INT32(y, 5, 0);
    GrB_Vector_setElement_INT32(y, 7, 1);

    GrB_wait();

    GxB_Vector_fprint(x, "x", GxB_COMPLETE, stdout);
    GxB_Vector_fprint(y, "y", GxB_COMPLETE, stdout);

    GrB_Vector_assign(x, nullptr, GrB_MIN_INT32, y, I, 2, nullptr);

    GrB_wait();

    GxB_Vector_fprint(x, "x", GxB_COMPLETE, stdout);

    GrB_finalize();

    return 0;
}
