#include <systemc.h>

SC_MODULE(DeltaCycleDemo)
{
    sc_in_clk clk;
    sc_signal<int> sig1, sig2;
    sc_event zero_time_event; // 用于SC_ZERO_TIME通知

    void thread1()
    {
        while (true)
        {
            wait(); // 等待时钟上升沿
            cout << "@ " << sc_time_stamp() << " in Thread1: sig1 = " << sig1.read() << endl;

            // 修改sig2，下一个delta cycle才会生效！
            sig2.write(sig1.read() + 5);
            cout << "@ " << sc_time_stamp() << " in Thread1: sig2 = " << sig2.read() << endl;

            // 使用SC_ZERO_TIME触发事件
            zero_time_event.notify(SC_ZERO_TIME);
            cout << "@ " << sc_time_stamp() << " in Thread1: zero_time_event notified" << endl;
        }
    }

    void thread2()
    {
        while (true)
        {
            wait(); // 等待时钟上升沿
            cout << "@ " << sc_time_stamp() << " in Thread2 (before wait): sig2 = " << sig2.read() << endl;

            // 等待零时间，在下一个delta cycle继续执行
            wait(SC_ZERO_TIME);
            cout << "@ " << sc_time_stamp() << " in Thread2 (after wait): sig2 = " << sig2.read() << "\n"
                 << endl;

            // 修改sig1，触发thread1在下一个时钟周期
            sig1.write(sig2.read() * 2);
        }
    }

    void thread3()
    {
        while (true)
        {
            // 等待事件触发
            wait(zero_time_event);
            cout << "@ " << sc_time_stamp() << " in Thread3: zero_time_event triggered" << endl;
        }
    }

    SC_CTOR(DeltaCycleDemo)
    {
        SC_THREAD(thread1);
        sensitive << clk.pos();

        SC_THREAD(thread2);
        sensitive << clk.pos();

        SC_THREAD(thread3);
        sensitive << zero_time_event;
    }
};

int sc_main(int argc, char *argv[])
{
    sc_clock clk("clk", 1, SC_NS);
    DeltaCycleDemo demo("demo");
    demo.clk(clk);

    // 初始化信号
    demo.sig1.write(10);


    // 创建VCD波形文件
    sc_trace_file *tf = sc_create_vcd_trace_file("wave");

     // 对你关心的信号进行trace
    sc_trace(tf, demo.sig1, "sig1");
    sc_trace(tf, demo.sig2, "sig2");

    // 启动仿真
    sc_start(3, SC_NS);

    sc_close_vcd_trace_file(tf); // 仿真结束关闭文件
    return 0;
}