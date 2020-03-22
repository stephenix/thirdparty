#include <gtest/gtest.h>
int Get(int a) {
    return a;
}

TEST(TestGet, test0){
    EXPECT_EQ(Get(2), 5);
}

int main(int argc,char **argv){
  testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}
