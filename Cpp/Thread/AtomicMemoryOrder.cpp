#include <iostream>
#include <atomic>

int main(int argc, char const *argv[])
{
    /**
     * memory_order_relaxed     没有同步或顺序制约，仅对此操作要求原子性
     * memory_order_consume     当前线程中依赖于当前加载的该值的读或写不能被重排到此加载前
     * memory_order_acquire     当前线程中的读或写不能被重排到此加载前
     * memory_order_release     当前线程中的读或写不能被重排到此存储后
     * memory_order_acq_rel     同时包含memory_order_acquire和memory_order_release
     * memory_order_seq_cst     全部读写都按代码顺序执行
     */

    return 0;
}
