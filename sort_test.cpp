#include "sort.h"
#include "gtest/gtest.h"
#include<vector>

namespace {
  TEST(Sort, CountSort) {
    const std::vector<int> unsorted {6, 3, 1, 3, 2, 4, 3, 1};
    const std::vector<int> expectedSort {1, 1, 2, 3, 3, 3, 4, 6};
    const int biggestIntOnVector = 10;

    const auto actualSort = CountSort(unsorted, biggestIntOnVector);

    EXPECT_EQ(expectedSort, actualSort);
  }
}  // namespace
