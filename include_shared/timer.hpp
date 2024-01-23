#pragma once

#include <iostream>
#include <chrono>

namespace MyTimer
{
    static std::chrono::high_resolution_clock::time_point start_time;
    static std::chrono::high_resolution_clock::time_point end_time;

    void start()
    {
        if (start_time != std::chrono::high_resolution_clock::time_point{})
        {
            // 如果已经开始计时，则输出错误信息
            std::cerr << "Error: Timer already started." << std::endl;
            return;
        }

        // 获取程序开始执行时的时间点
        start_time = std::chrono::high_resolution_clock::now();
    }

    void end()
    {
        if (start_time == std::chrono::high_resolution_clock::time_point{})
        {
            // 如果还未开始计时，则输出错误信息
            std::cerr << "Error: Timer not started." << std::endl;
            return;
        }

        // 获取程序结束执行时的时间点
        end_time = std::chrono::high_resolution_clock::now();

        // 计算程序执行时间，单位为毫秒
        auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);

        // 输出执行时间，精确到毫秒
        std::cout << "程序执行时间: " << elapsed_time.count() << " 毫秒" << std::endl;

        // 重置计时器状态
        start_time = std::chrono::high_resolution_clock::time_point{};
        end_time = std::chrono::high_resolution_clock::time_point{};
    }
}
