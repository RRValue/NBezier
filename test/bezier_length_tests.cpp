#include "NBezier/bezier_length.h"
#include "NBezier/bezier_points.h"

#include "bezier_test_types.h"

#include <gtest/gtest.h>

UseNameSpace(NBezier);

#if !defined(MSVC)
TEST(Bezier, LengthConstexpr)
{
    constexpr auto p0 = Point<float, 2>{-1, 1};
    constexpr auto p1 = Point<float, 2>{0, -1};
    constexpr auto p2 = Point<float, 2>{1, 1};

    constexpr auto bezier = BezierPoints<float, 2, 2>{p0, p1, p2};
    constexpr auto exp_length = float(2.957885715);
    constexpr auto result_compile_time = BezierLength::get(bezier);
    const auto result_run_time = BezierLength::get(bezier);
    
    constexpr auto length_compile_time = result_compile_time.m_length;
    const auto& length_run_time = result_run_time.m_length;

    constexpr auto cache_compile_time = result_compile_time.m_cache;
    const auto& cache_run_time = result_run_time.m_cache;

    EXPECT_TRUE(std::equal(std::cbegin(cache_compile_time), std::cend(cache_compile_time),  //
                           std::cbegin(cache_run_time), std::cend(cache_run_time),          //
                           [](const auto& lhs, const auto& rhs) { return std::abs(lhs - rhs) < 1e-05f; }));
    EXPECT_EQ(length_compile_time, length_run_time);
    EXPECT_TRUE(std::abs(exp_length - length_compile_time) < float(1e-05));
    EXPECT_TRUE(std::abs(exp_length - length_run_time) < float(1e-05));
}
#endif  //! defined(MSVC)

TEST(Bezier, CacheSize)
{
    constexpr auto c0 = LengthResult<float, 1>();
    constexpr auto c1 = LengthResult<float, 2>();
    constexpr auto c2 = LengthResult<float, 3>();
    constexpr auto c3 = LengthResult<float, 4>();

    EXPECT_EQ(c0.m_cache.size(), 2);
    EXPECT_EQ(c1.m_cache.size(), 6);
    EXPECT_EQ(c2.m_cache.size(), 14);
    EXPECT_EQ(c3.m_cache.size(), 30);
}

TEST(Bezier, LengthRunTime)
{
    constexpr auto p0 = Point<float, 2>{-1, 1};
    constexpr auto p1 = Point<float, 2>{0, -1};
    constexpr auto p2 = Point<float, 2>{1, 1};

    constexpr auto bezier = BezierPoints<float, 2, 2>{p0, p1, p2};
    constexpr auto exp_length = float(2.957885715);
    const auto result = BezierLength::get<3>(bezier);
    const auto length = result.m_length;
    
    EXPECT_TRUE(std::abs(exp_length - length) < float(1e-05));
}

TEST(Bezier, LengthCache)
{
    constexpr auto p0 = Point<float, 2>{-1, 1};
    constexpr auto p1 = Point<float, 2>{0, -1};
    constexpr auto p2 = Point<float, 2>{1, 1};

    constexpr auto bezier = BezierPoints<float, 2, 2>{p0, p1, p2};
    const auto result = BezierLength::get<3>(bezier);
    const auto length = result.m_length;
    const auto cache = result.m_cache;

    EXPECT_TRUE(std::abs(cache[1] - (cache[2] + cache[3])) < float(1e-05));
    EXPECT_TRUE(std::abs(cache[4] - (cache[5] + cache[6])) < float(1e-05));
    EXPECT_TRUE(std::abs(cache[8] - (cache[9] + cache[10])) < float(1e-05));
    EXPECT_TRUE(std::abs(cache[11] - (cache[12] + cache[13])) < float(1e-05));

    EXPECT_TRUE(std::abs(cache[0] - (cache[1] + cache[4])) < float(1e-05));
    EXPECT_TRUE(std::abs(cache[7] - (cache[8] + cache[11])) < float(1e-05));

    EXPECT_TRUE(std::abs(length - (cache[0] + cache[7])) < float(1e-05));
}